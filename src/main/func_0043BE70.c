#include "types.h"
typedef struct { char p[0x10]; int f10; int f14; } D43BE70;
typedef struct { char p[0x48]; unsigned char b48; char p49[3]; int f4C; int f50; } W43BE70;
extern void func_0041F150(W43BE70* w);
extern int func_0041E0F0(W43BE70* w, W43BE70* src, int kind, int a, int out);
extern char D_004BFFA8[];
static int D_004976A0 = (int)D_004BFFA8;
void func_0043BE70(W43BE70* w)
{
    D43BE70* d[1];
    func_0041F150(w);
    d[0] = 0;
    if (func_0041E0F0(w, w, 4, D_004976A0, (int)d) && d[0]) {
        w->b48 = 1;
        w->f4C = d[0]->f10;
        w->f50 = d[0]->f14;
    }
}
