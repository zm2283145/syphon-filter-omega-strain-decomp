#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } SBF70L;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; char buf[11]; } SBF70S;
typedef struct { union { SBF70L l; SBF70S s; } u; } SBF70;
extern int func_003CBFB0(const SBF70* self, const char* s, unsigned int pos, unsigned int n);
static inline unsigned char SBF70_ShortLen(const SBF70* s) { return s->u.s.len; }
int func_003CBF70(const SBF70* self, const SBF70* str, unsigned int pos)
{
    const char* d;
    unsigned int n;
    if (!(str->u.l.word & 1)) {
        d = str->u.s.buf;
        n = SBF70_ShortLen(str);
    } else {
        d = str->u.l.data;
        n = str->u.l.length;
    }
    return func_003CBFB0(self, d, pos, n);
}
