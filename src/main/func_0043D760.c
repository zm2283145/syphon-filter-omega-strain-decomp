#include "types.h"
typedef struct { char p[0x64]; int page; int pos; int f6C; int total; char p74[8]; void* sb; } L43D760;
extern void func_0043BC70(void* sb, unsigned char b, int v, int lo, int hi);
void func_0043D760(L43D760* l, int big)
{
    int step = l->page;
    if (l->pos < l->total - step) {
        step = big ? step : 1;
        l->pos += step;
        if (!(l->pos < l->total - l->page)) {
            l->pos = l->total - l->page;
            if (l->pos < 0) l->pos = 0;
        }
        if (l->sb) func_0043BC70(l->sb, 0, l->pos, 0, l->total - l->page);
    }
}
