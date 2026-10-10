#include "types.h"
typedef struct { char pad[0x2EC0]; } F8Actor_pad;
typedef struct {
    void* vt;
    char pad4[0x5C];
    char x60[0x2E50 - 0x60];
    char x2E50[4];
    char x2E54[0x14];
    char x2E68[0x2EC0 - 0x2E68];
    char x2EC0[0x10];
    char x2ED0[0xF0];
    char x2FC0[4];
} F8Actor_392;
extern char D_004DF740[];
extern void func_00393690(void* p);
extern void func_003931F0(void* p);
extern void func_00393000(void* p, int f);
extern void func_00392D10(void* p, int f);
extern void func_003960F0(void* p, int f);
extern void func_00396000(void* p, int f);
extern void func_00392260(void* p, int f);
extern void cGOBJ_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void F8L3a(void* p) { if (p) func_003960F0(p, 0); }
static inline void F8L2a(void* p) { if (p) F8L3a(p); }
static inline void F8L1a(void* p) { if (p) F8L2a(p); }
static inline void F8L3b(void* p) { if (p) func_00396000(p, 0); }
static inline void F8L2b(void* p) { if (p) F8L3b(p); }
static inline void F8L1b(void* p) { if (p) F8L2b(p); }
F8Actor_392* Actor_Destroy(F8Actor_392* a, short del)
{
    if (a) {
        a->vt = D_004DF740;
        if (a->x2EC0) {
            func_00393690(a->x2EC0);
            func_003931F0(a->x2EC0);
            func_00393000(a->x2FC0, -1);
            func_00392D10(a->x2ED0, -1);
        }
        if (a->x2E50) {
            F8L1a(a->x2E68);
            F8L1b(a->x2E54);
        }
        func_00392260(a->x60, -1);
        cGOBJ_dtor(a, 0);
        if (del > 0)
            operator_delete(a);
    }
    return a;
}