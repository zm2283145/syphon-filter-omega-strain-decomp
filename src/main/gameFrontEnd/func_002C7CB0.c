#include "types.h"

extern int D_0051EF78;
extern int D_0048C360;
extern int D_0051EF88;
extern int D_0051EF90;
extern unsigned long long func_003698B0(void);
extern int Gui_GetScreenStack(void);
extern void func_0041E0F0(int, int, int, int, int);

int func_002C7CB0(char* self) {
    float f;
    long long t;
    int h;

    if (*(unsigned char*)(self + 0x2D) == 0) {
        return 1;
    }
    t = D_0051EF78 + D_0048C360;
    if (t < func_003698B0()) {
        return 1;
    }
    h = D_0051EF88;
    if (h != 0 && D_0051EF90 != 0) {
        f = 0.0f;
        func_0041E0F0(Gui_GetScreenStack(), h, 9, (int)&f, 0);
        if (D_0051EF90 == (int)f) {
            return 1;
        }
    }
    return 0;
}
