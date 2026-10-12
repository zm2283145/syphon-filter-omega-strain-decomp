#include "types.h"
typedef struct { char p[0x64]; int page; int pos; int f6C; int total; char p74[8]; void* sb; } L43D820;
extern void func_0043BC70(void* sb, unsigned char b, int v, int lo, int hi);
void func_0043D820(L43D820* l, int big)
{
    if (l->pos) {
        int step;
        if (big) step = l->page; else step = 1;
        l->pos -= step;
        if (l->pos < 0) l->pos = 0;
        if (l->sb) func_0043BC70(l->sb, 0, l->pos, 0, l->total - l->page);
    }
}
