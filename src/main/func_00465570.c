#include "types.h"
typedef struct { char p[0x6C]; float f6C; } W465570;
extern void func_00414F00(W465570* w);
extern void* GuiWidget_FindChildByName(void* x, int key);
extern void func_0041E0F0(void* w, void* src, int kind, int a, int b);
extern char D_004C28F8[];
static int D_00497BE0 = (int)D_004C28F8;
void func_00465570(W465570* w, void* x)
{
    func_00414F00(w);
    if (x) {
        void* o = GuiWidget_FindChildByName(x, D_00497BE0);
        if (o) {
            func_0041E0F0(w, o, 10, (int)w->f6C, 0);
            func_0041E0F0(w, o, 0xD, 0, 300);
        }
    }
}
