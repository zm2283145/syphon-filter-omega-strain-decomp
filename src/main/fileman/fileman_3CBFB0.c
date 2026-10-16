#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } SBF70L;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; char buf[11]; } SBF70S;
typedef struct { union { SBF70L l; SBF70S s; } u; } SBF70;
static inline unsigned char SBF70_ShortLen(const SBF70* s) { return s->u.s.len; }
int func_003CBFB0(const SBF70* self, const char* s, unsigned int pos, unsigned int n)
{
    const char* d;
    unsigned int size;
    unsigned int rem;
    const char* end;
    const char* p;
    if (!(self->u.l.word & 1)) {
        d = self->u.s.buf;
        size = SBF70_ShortLen(self);
    } else {
        d = self->u.l.data;
        size = self->u.l.length;
    }
    if (pos <= size) {
        p = d + pos;
        end = s + n;
        rem = size - pos;
        for (; rem >= n; rem--, p++) {
            const char* b = p;
            const char* a = s;
            for (; a < end; a++, b++) {
                if (*a != *b) goto next;
            }
            return p - d;
        next:;
        }
    }
    return -1;
}
