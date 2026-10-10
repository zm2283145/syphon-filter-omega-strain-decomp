#include "types.h"
typedef struct { float v[11]; } F296A80_Tab __attribute__((aligned(16)));
typedef struct { char pad[0x88]; int h; } F296A80_Obj;
extern F296A80_Tab D_0048B870;
extern int func_0041E0F0(void* o, int a, int b, int c, int d);
extern int func_004147A0(void);
void func_00296A80(F296A80_Obj* o, float t) {
    F296A80_Tab tab = D_0048B870;
    if (o->h != 0) {
        float cur = 0.0f;
        int i;
        func_0041E0F0(o, o->h, 9, (int)&cur, 0);
        for (i = 0; i < 11; i++) {
            if (cur < tab.v[i] && !(cur + t < tab.v[i])) {
                func_0041E0F0(o, func_004147A0(), 16, 8, 0);
                return;
            }
        }
    }
}