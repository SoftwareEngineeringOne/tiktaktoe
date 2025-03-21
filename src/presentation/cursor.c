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
#include "presentation/cursor.h"

#include "presentation/print.h"
#include "util/conversion.h"

/**
 * @brief TODO: ?????
 * @param num
 * @param num_buf
 * @param buf
 * @param buf_pos
 */
static void writeNumToBuf(uint8_t num, const char *num_buf, char *buf, uint8_t *buf_pos);

void cursor_moveTo(const uint8_t x, const uint8_t y)
{
    // uint8_t has max 3 digits + null terminator
    static char conversion_buf[4];
    const uint8_t size = sizeof(conversion_buf);

    // \e (1) + [ (1) + 000 (3) + ; (1) + 000 (3) + H (1) + '\0' => 11
    static char escape_seq[11];
    uint8_t pos = 0;
    escape_seq[pos++] = '\e';
    escape_seq[pos++] = '[';

    int_to_str(y, conversion_buf, size);
    writeNumToBuf(y, conversion_buf, escape_seq, &pos);

    escape_seq[pos++] = ';';

    int_to_str(x, conversion_buf, size);
    writeNumToBuf(x, conversion_buf, escape_seq, &pos);

    escape_seq[pos++] = 'H';
    escape_seq[pos] = '\0';

    print(escape_seq);
}

static void writeNumToBuf(const uint8_t num, const char *num_buf, char *buf, uint8_t *buf_pos)
{
    buf[(*buf_pos)++] = num_buf[0];
    if(num > 9)
    {
        buf[(*buf_pos)++] = num_buf[1];
    }
    if(num > 99)
    {
        buf[(*buf_pos)++] = num_buf[2];
    }
}
