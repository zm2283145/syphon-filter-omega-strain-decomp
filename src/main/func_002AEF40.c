#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[0x70]; char m174[4]; } O2AEF40;
extern char D_004DDD40[];
extern char D_004DE8A0[];
extern void func_00138B70(void* p, int f);
extern void func_0044F970(void* p, int f);
extern void func_0033D430(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2AEF40(O2AEF40* p)
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
O2AEF40* func_002AEF40(O2AEF40* self, short del)
{
    if (self) {
        self->vt = D_004DDD40;
        if (self->m174)
            func_00138B70(self->m174, 0);
        Base2AEF40(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}