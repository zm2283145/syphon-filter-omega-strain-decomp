#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0xAC]; char m10C[4]; } O2AAC60;
extern char D_004DDB80[];
extern char D_004E0D20[];
extern void func_002AD780(void* p, int f);
extern void func_0013B2E0(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
static inline void C2AAC60(void* p) { if (p) func_002AD780(p, 0); }
static inline void B2AAC60(void* p) { if (p) C2AAC60(p); }
static inline void A2AAC60(void* p) { if (p) B2AAC60(p); }
static inline void Base2AAC60(O2AAC60* p)
{
    if (p) {
        p->vt = D_004E0D20;
        func_0013B2E0(p->m60, -1);
        func_0041F370(p, 0);
    }
}
O2AAC60* func_002AAC60(O2AAC60* self, short del)
{
    if (self) {
        self->vt = D_004DDB80;
        A2AAC60(self->m10C);
        Base2AAC60(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}