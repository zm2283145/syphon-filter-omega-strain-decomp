#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[4]; } O2A8A60;
extern char D_004DDA50[];
extern char D_004DE8A0[];
extern void func_00138B70(void* p, int f);
extern void func_0044F970(void* p, int f);
extern void func_0033D430(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2A8A60(O2A8A60* p)
{
    if (p) {
        p->vt = D_004DE8A0;
        if (p->m104)
            func_00138B70(p->m104, 0);
        func_0044F970(p->mE4, -1);
        func_0044F970(p->mC8, -1);
        func_0044F970(p->mAC, -1);
        func_0033D430(p, 0);
    }
}
O2A8A60* func_002A8A60(O2A8A60* self, short del)
{
    if (self) {
        self->vt = D_004DDA50;
        Base2A8A60(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}