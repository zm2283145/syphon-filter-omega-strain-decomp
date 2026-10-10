#include "types.h"
typedef struct { char pad[0x64]; int count; } C5Recv;
typedef struct {
    char pad[0x104E0]; int drawn;
    char pad2[0x1176C - 0x104E4]; C5Recv* recv; int first; int n;
} C5Shadow;
extern int D_005392D0;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern void func_003D2D10(C5Shadow* s, int i);
void func_003D3BC0(C5Shadow* s) {
    if (s->recv) {
        int n = s->recv->count - s->first;
        int i;
        int save;
        s->n = n < 4 ? n : 4;
        s->drawn = s->n;
        save = D_005392D0;
        D_005392D0 = 5;
        D_005392D8 = D_004BC1B0;
        for (i = 0; i < s->n; i++)
            func_003D2D10(s, i);
        D_005392D0 = save;
    }
}