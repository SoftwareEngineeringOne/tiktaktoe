/**
 * @file
 *
 * @author
 *
 * @date
 *
 * @brief
 *
 * @see
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
#include "logic/input.h"

#include "config.h"
#include "hal_high/input_buf.h"
#include "logic/bot.h"
#include "logic/game.h"
#include "logic/time.h"
#include "presentation/cell.h"
#include "presentation/menu.h"
#include "presentation/style.h"
#include "presentation/ui.h"

static void handleEscapeSequence(CellState *cell_state);

static void handleSetMark(GameState *game_state, CellState *cell_state);
static void openControls();
static bool handlePauseResume(CellState *cell_state);


bool input_handleByte(uint8_t *byte, GameState *game_state, CellState *cell_state)
{
    switch(*byte)
    {
        case '\e':
            if(!g_timer.is_running)
                break;
            handleEscapeSequence(cell_state);
            break;
        case '\r':
        case ' ':
            handleSetMark(game_state, cell_state);
            break;
        case '?':
            openControls();
            return true;
        case 'p':
        case 'P':
            return handlePauseResume(cell_state);
        case '+':
            cell_increaseSize();
            return true;
        case '-':
            cell_decreaseSize();
            return true;
        default:;
    }
    return false;
}

void handleEscapeSequence(CellState *cell_state)
{
    uint8_t input = '\0';
    if(!input_getNext(&g_input_buf, &input) || input != '[')
    {
        return;
    }

    if(!input_getNext(&g_input_buf, &input))
    {
        return;
    }

    const int col = cell_state->selected->col;
    const int row = cell_state->selected->row;

    switch(input)
    {
        case 'A':
            if(row - 1 >= 0)
            {
                cell_state->selected = &cell_state->all[row - 1][col];
            }
            break;
        case 'B':
            if(row + 1 < CELLS_PER_COL)
            {
                cell_state->selected = &cell_state->all[row + 1][col];
            }
            break;
        case 'C':
            if(col + 1 < CELLS_PER_ROW)
            {
                cell_state->selected = &cell_state->all[row][col + 1];
            }
            break;
        case 'D':
            if(col - 1 >= 0)
            {
                cell_state->selected = &cell_state->all[row][col - 1];
            }
            break;
        default:;
    }
}

static void handleSetMark(GameState *game_state, CellState *cell_state)
{
    if(cell_state->selected->marked_by != None || !g_timer.is_running)
    {
        return;
    }

    if(game_state->mode == PVE)
    {
        cell_state->selected->marked_by = Cross;
        cell_state->last_cross = bot_markRandomCell(cell_state->all, Circle);
        cell_state->last_circle = cell_state->selected;
        cell_redraw(cell_state->last_cross);
    }
    else
    {
        cell_state->selected->marked_by = game_state->current_player;
        if(game_state->current_player == Circle)
        {
            cell_state->last_circle = cell_state->selected;
            cell_select(cell_state->last_circle);
        }
        else
        {
            cell_state->last_cross = cell_state->selected;
            cell_select(cell_state->last_cross);
        }
    }

    game_endTurn();
    ui_updateTurn(game_state->round, game_state->current_player);
}

static void openControls()
{
    if(g_timer.is_running)
    {
        time_pause();
        menu_showControls("\nPress any key to return to the match...");
        time_resume();
    }
    else
    {
        menu_showControls("\nPress any key to return to the match...");
    }
}

static bool handlePauseResume(CellState *cell_state)
{
    if(g_timer.is_running)
    {
        time_pause();
        cell_redrawAll(cell_state->all, HIDDEN);
        return false;
    }
    time_resume();
    return true;
}
