/**
 * @file ascii_art.h
 *
 * @brief Contains ASCII art constants for the TikTakToe game.
 *
 * @details
 * This file defines macros for ASCII art used in the TikTakToe game, including
 * headings, win messages, and start messages. The ASCII art adapts based on
 * whether Unicode or plain text is enabled.
 *
 * @ingroup Presentation
 *
 * @note
 * Ensure that ENABLE_ASCII_ART and ENABLE_UNICODE are defined appropriately
 * to use the desired ASCII art format.
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ASCII_ART_H
#define ASCII_ART_H

#ifdef ENABLE_ASCII_ART

/**
 * @def HEADING_LINES
 * @brief Number of lines in the heading ASCII art.
 */
#define HEADING_LINES 9

#ifdef ENABLE_UNICODE
/**
 * @def HEADING
 * @brief ASCII art for the game heading with Unicode support.
 */
#define HEADING \
    "\
.___________. __   __  ___ .___________.    ___       __  ___ .___________.  ______    _______  \n\
|           ||  | |  |/  / |           |   /   \\     |  |/  / |           | /  __  \\  |   ____| \n\
`---|  |----`|  | |  '  /  `---|  |----`  /  ^  \\    |  '  /  `---|  |----`|  |  |  | |  |__    \n\
    |  |     |  | |    <       |  |      /  /_\\  \\   |    <       |  |     |  |  |  | |   __|   \n\
    |  |     |  | |  .  \\      |  |     /  _____  \\  |  .  \\      |  |     |  `--'  | |  |____  \n\
    |__|     |__| |__|\\__\\     |__|    /__/     \\__\\ |__|\\__\\     |__|      \\______/  |_______| \n\
───────────────────────────────────────────────────────────────────────────────────────────────\n\
"
#else
/**
 * @def HEADING
 * @brief ASCII art for the game heading without Unicode support.
 */
#define HEADING \
    "\
.___________. __   __  ___ .___________.    ___       __  ___ .___________.  ______    _______  \n\
|           ||  | |  |/  / |           |   /   \\     |  |/  / |           | /  __  \\  |   ____| \n\
`---|  |----`|  | |  '  /  `---|  |----`  /  ^  \\    |  '  /  `---|  |----`|  |  |  | |  |__    \n\
    |  |     |  | |    <       |  |      /  /_\\  \\   |    <       |  |     |  |  |  | |   __|   \n\
    |  |     |  | |  .  \\      |  |     /  _____  \\  |  .  \\      |  |     |  `--'  | |  |____  \n\
    |__|     |__| |__|\\__\\     |__|    /__/     \\__\\ |__|\\__\\     |__|      \\______/  |_______| \n\
_______________________________________________________________________________________________\n\
"
#endif

/**
 * @def CROSS_WINS
 * @brief ASCII art displayed when the cross player wins.
 */
#define CROSS_WINS \
    "\
  ____                    __        ___           _ \n\
 / ___|_ __ ___  ___ ___  \\ \\      / (_)_ __  ___| |\n\
| |   | '__/ _ \\/ __/ __|  \\ \\ /\\ / /| | '_ \\/ __| |\n\
| |___| | | (_) \\__ \\__ \\   \\ V  V / | | | | \\__ \\_|\n\
 \\____|_|  \\___/|___/___/    \\_/\\_/  |_|_| |_|___(_)\n\
"

/**
 * @def CIRCLE_WINS
 * @brief ASCII art displayed when the circle player wins.
 */
#define CIRCLE_WINS \
    "\
  ____ _          _       __        ___           _ \n\
 / ___(_)_ __ ___| | ___  \\ \\      / (_)_ __  ___| |\n\
| |   | | '__/ __| |/ _ \\  \\ \\ /\\ / /| | '_ \\/ __| |\n\
| |___| | | | (__| |  __/   \\ V  V / | | | | \\__ \\_|\n\
 \\____|_|_|  \\___|_|\\___|    \\_/\\_/  |_|_| |_|___(_)\n\
"

/**
 * @def ITS_A_TIE
 * @brief ASCII art displayed when the game ends in a tie.
 */
#define ITS_A_TIE \
    "\
 ___ _   _               _____ _      _ \n\
|_ _| |_( )___    __ _  |_   _(_) ___| |\n\
 | || __|// __|  / _` |   | | | |/ _ \\ |\n\
 | || |_  \\__ \\ | (_| |   | | | |  __/_|\n\
|___|\\__| |___/  \\__,_|   |_| |_|\\___(_)\n\
"

/**
 * @def PLAYER_STARTS
 * @brief ASCII art displayed when the player starts the game.
 */
#define PLAYER_STARTS \
    "\
 ____  _                             _             _       _ \n\
|  _ \\| | __ _ _   _  ___ _ __   ___| |_ __ _ _ __| |_ ___| |\n\
| |_) | |/ _` | | | |/ _ \\ '__| / __| __/ _` | '__| __/ __| |\n\
|  __/| | (_| | |_| |  __/ |    \\__ \\ || (_| | |  | |_\\__ \\_|\n\
|_|   |_|\\__,_|\\__, |\\___|_|    |___/\\__\\__,_|_|   \\__|___(_)\n\
               |___/                                         \n\
"

/**
 * @def COMPUTER_STARTS
 * @brief ASCII art displayed when the computer starts the game.
 */
#define COMPUTER_STARTS \
    "\
  ____                            _                  _             _       _ \n\
 / ___|___  _ __ ___  _ __  _   _| |_ ___ _ __   ___| |_ __ _ _ __| |_ ___| |\n\
| |   / _ \\| '_ ` _ \\| '_ \\| | | | __/ _ \\ '__| / __| __/ _` | '__| __/ __| |\n\
| |__| (_) | | | | | | |_) | |_| | ||  __/ |    \\__ \\ || (_| | |  | |_\\__ \\_|\n\
 \\____\\___/|_| |_| |_| .__/ \\__,_|\\__\\___|_|    |___/\\__\\__,_|_|   \\__|___(_)\n\
                     |_|                                                     \n\
"

/**
 * @def CIRCLE_STARTS
 * @brief ASCII art displayed when the circle player starts the game.
 */
#define CIRCLE_STARTS \
    "\
  ____ _          _            _             _       _ \n\
 / ___(_)_ __ ___| | ___   ___| |_ __ _ _ __| |_ ___| |\n\
| |   | | '__/ __| |/ _ \\ / __| __/ _` | '__| __/ __| |\n\
| |___| | | | (__| |  __/ \\__ \\ || (_| | |  | |_\\__ \\_|\n\
 \\____|_|_|  \\___|_|\\___| |___/\\__\\__,_|_|   \\__|___(_)\n\
"

/**
 * @def CROSS_STARTS
 * @brief ASCII art displayed when the cross player starts the game.
 */
#define CROSS_STARTS \
    "\
  ____                         _             _       _ \n\
 / ___|_ __ ___  ___ ___   ___| |_ __ _ _ __| |_ ___| |\n\
| |   | '__/ _ \\/ __/ __| / __| __/ _` | '__| __/ __| |\n\
| |___| | | (_) \\__ \\__ \\ \\__ \\ || (_| | |  | |_\\__ \\_|\n\
 \\____|_|  \\___/|___/___/ |___/\\__\\__,_|_|   \\__|___(_)\n\
"

#else

/**
 * @def HEADING_LINES
 * @brief Number of lines in the heading ASCII art for plain text mode.
 */
#define HEADING_LINES 3

/**
 * @def HEADING
 * @brief Plain text heading for the game.
 */
#define HEADING "\n TikTakToe \n"

/**
 * @def CROSS_WINS
 * @brief Plain text message displayed when the cross player wins.
 */
#define CROSS_WINS "\n Cross Wins! \n"

/**
 * @def CIRCLE_WINS
 * @brief Plain text message displayed when the circle player wins.
 */
#define CIRCLE_WINS "\n Circle Wins! \n"

/**
 * @def ITS_A_TIE
 * @brief Plain text message displayed when the game ends in a tie.
 */
#define ITS_A_TIE "\n It's a Tie! \n"

/**
 * @def PLAYER_STARTS
 * @brief Plain text message displayed when the player starts the game.
 */
#define PLAYER_STARTS "\n Player starts! \n"

/**
 * @def COMPUTER_STARTS
 * @brief Plain text message displayed when the computer starts the game.
 */
#define COMPUTER_STARTS "\n Computer starts! \n"

/**
 * @def CIRCLE_STARTS
 * @brief Plain text message displayed when the circle player starts the game.
 */
#define CIRCLE_STARTS "\n Circle starts! \n"

/**
 * @def CROSS_STARTS
 * @brief Plain text message displayed when the cross player starts the game.
 */
#define CROSS_STARTS "\n Cross starts! \n"

#endif

#endif// ASCII_ART_H
