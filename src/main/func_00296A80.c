#include "types.h"
typedef struct { char pad[0x88]; int h; } F296A80_Obj;
extern int func_0041E0F0(void* o, int a, int b, int c, int d);
extern int func_004147A0(void);
void func_00296A80(F296A80_Obj* o, float t) {
    float tab[11] = { 34.0f, 159.0f, 280.0f, 397.0f, 509.0f, 621.0f, 723.0f, 824.0f, 928.0f, 1009.0f, 1108.0f };
    if (o->h != 0) {
        float cur = 0.0f;
        int i;
        func_0041E0F0(o, o->h, 9, (int)&cur, 0);
        for (i = 0; i < 11; i++) {
            if (cur < tab[i] && !(cur + t < tab[i])) {
                func_0041E0F0(o, func_004147A0(), 16, 8, 0);
                return;
            }
        }
    }
}
