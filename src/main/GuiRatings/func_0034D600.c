#include "types.h"
typedef struct { char pad[0x10]; int f10; } W34D;
typedef struct { char pad[0xC]; int fc; char p[4]; } E34D;
typedef struct { char pad[0x10]; int f10; char pad2[0x58]; int f6c[0x1A]; E34D* fd4; } O34D;
extern int func_004147A0(void);
extern void func_0041E0F0(O34D*, int, int, int, int);
extern void func_00356850(O34D*, int, int);
extern void func_00414B30(int, int);
extern int func_00356B30(O34D*, W34D*, int, int, int);
int func_0034D600(O34D* o, W34D* w, int ev, int x, int y) {
    unsigned short e = ev;
    if (e == 0) {
        func_0041E0F0(o, func_004147A0(), 0x10, 0, 0);
        if (w->f10 != -1) {
            func_00356850(o, w->f10, ((E34D*)((char*)o->fd4 + w->f10 * 20))->fc);
            func_0041E0F0(o, (int)w, 6, (int)"onActivate", 0);
            return 1;
        }
    }
    if (e == 1 && w->f10 != -1) {
        func_0041E0F0(o, (int)w, 6, (int)"onDeactivate", 0);
        return 1;
    }
    if (e == 0x3000) {
        func_00414B30(func_004147A0(), o->f6c[x]);
        o->f10 = x;
        return 1;
    }
    return func_00356B30(o, w, ev, x, y);
}
