#include "types.h"
typedef struct { char pad[0x104]; int count; int cur; short ids[1]; } S2BDED0;
extern void func_002BDCF0(S2BDED0* s, short id);
void func_002BDED0(S2BDED0* s, int n)
{
    int base = s->cur - (n >> 1);
    int i;
    for (i = 0; i < n; i++) {
        int k = i + base;
        if (k < 0)
            k += s->count;
        if (k > s->count)
            k -= s->count;
        if (k >= 0 && k < s->count)
            func_002BDCF0(s, s->ids[k]);
    }
}