#include "types.h"
typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS41A100;
typedef struct { union { SS41A100 s; unsigned int w; } h; unsigned int size; } Str41A100;
typedef struct { char p[0x48]; Str41A100 text; char p50[0x3C]; int cursor; } W41A100;
static inline unsigned int Size41A100(Str41A100* s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }
int func_0041A100(W41A100* w, int pos)
{
    int len = Size41A100(&w->text);
    if (pos == -1) pos = len;
    if (len < pos) { w->cursor = len; return 0; }
    if (pos < 0) { w->cursor = 0; return 0; }
    w->cursor = pos;
    return 1;
}
