#pragma cplusplus off

#include "types.h"
typedef struct { union { struct { unsigned int word; unsigned int length; char* data; } l; struct { unsigned char isLong : 1; unsigned char len : 7; char buf[11]; } s; } u; } ShortStr;

/* Forward the character range of src (short or long form) to func_003B9410. */
ShortStr* func_003B9410(ShortStr* self, const char* data, int arg, unsigned int len);

ShortStr* func_003B7100(ShortStr* self, const ShortStr* src, int arg)
{
    const char* data;
    unsigned int len;
    if (!(src->u.l.word & 1)) {
        data = src->u.s.buf;
        len = (unsigned char)src->u.s.len;
    } else {
        data = src->u.l.data;
        len = src->u.l.length;
    }
    return func_003B9410(self, data, arg, len);
}