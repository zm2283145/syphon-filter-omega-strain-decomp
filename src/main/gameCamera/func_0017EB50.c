#include "types.h"
extern char D_004DA410[];
extern char D_004DA3B0[];
extern char D_004DA3E0[];
extern char D_004DA380[];
extern void func_0017EC70(void* p, int f);
extern void operator_delete(void* p);
typedef struct { void* vt; } V_EB50;
V_EB50* func_0017EB50(V_EB50* self, short flag)
{
    if (self) {
        V_EB50* m = (V_EB50*)((char*)self + 0x80);
        void* m2;
        if (m) {
            self[0x20].vt = D_004DA410;
            if (m)
                self[0x20].vt = D_004DA3B0;
        }
        m2 = (char*)self + 0x38;
        if (m2)
            func_0017EC70(m2, -1);
        if (self) {
            self->vt = D_004DA3E0;
            if (self)
                self->vt = D_004DA380;
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}