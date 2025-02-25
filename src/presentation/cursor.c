#include "presentation/cursor.h"

#include "util/conversion.h"
#include "presentation/print.h"

void cursor_moveTo(const uint8_t x, const uint8_t y)
{
    // uint8_t has max 3 digits + null terminator
    static char conversion_buf[4];
    const uint8_t size = sizeof(conversion_buf);

    // \e (1) + [ (1) + 000 (3) + ; (1) + 000 (3) + H (1) => 10
    static char escape_seq[10];
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

void writeNumToBuf(const uint8_t num, const char *num_buf, char *buf, uint8_t *buf_pos)
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
