#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[4]; } O2AD920;
extern void func_00293890();
extern void func_002AD9D0();
extern void func_002AD9E0();
extern void func_002ADA10();
extern void func_002ADAB0();
extern void func_002ADE00();
extern void func_002ADE60();
extern void func_002ADF00();
extern void func_0033CCA0();
extern void func_0033DA00();
extern void func_0033DE00();
extern void func_0033E410();
extern void func_0033E5B0();
extern void func_0033EE40();
extern void func_0033F050();
extern void func_0033F110();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041D8C0();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041E470();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void * const D_004DDC20[];
extern char D_004DE8A0[];
extern void func_00138B70(void* p, int f);
extern void func_0044F970(void* p, int f);
extern void func_0033D430(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2AD920(O2AD920* p)
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
O2AD920* func_002AD920(O2AD920* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDC20);
        Base2AD920(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDC20[32] = { (void*)0x0, (void*)0x0, (void*)func_002AD920, (void*)func_002ADF00, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0033F110, (void*)func_0033F050, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0033DA00, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0033DE00, (void*)func_002ADAB0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002AD9D0, (void*)func_002AD9E0, (void*)func_00293890, (void*)func_0033CCA0, (void*)func_002ADE60, (void*)func_002ADE00, (void*)func_0033EE40, (void*)func_0033E410, (void*)func_0033E5B0, (void*)func_002ADA10, (void*)0x0 };
