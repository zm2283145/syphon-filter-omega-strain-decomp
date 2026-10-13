#include "types.h"
typedef struct { void* vt; char pad[0xA8]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x20]; char m104[0x70]; char m174[4]; } O2AEF40;
extern void func_00293890();
extern void func_002AF000();
extern void func_002AF010();
extern void func_002AF040();
extern void func_002AF190();
extern void func_002AF2A0();
extern void func_002AF310();
extern void func_002AFA20();
extern void func_002AFA80();
extern void func_002AFDC0();
extern void func_0033DA00();
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
extern void * const D_004DDD40[];
extern char D_004DE8A0[];
extern void String_Dtor(void* p, int f);
extern void func_0044F970(void* p, int f);
extern void func_0033D430(void* p, int f);
extern void operator_delete(void* p);
static inline void Base2AEF40(O2AEF40* p)
{
    if (p) {
        p->vt = D_004DE8A0;
        if (p->m104)
            String_Dtor(p->m104, 0);
        func_0044F970(p->mE4, -1);
        func_0044F970(p->mC8, -1);
        func_0044F970(p->mAC, -1);
        func_0033D430(p, 0);
    }
}
O2AEF40* func_002AEF40(O2AEF40* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDD40);
        if (self->m174)
            String_Dtor(self->m174, 0);
        Base2AEF40(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDD40[32] = { (void*)0x0, (void*)0x0, (void*)func_002AEF40, (void*)func_002AFDC0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0033F110, (void*)func_0033F050, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0033DA00, (void*)func_0041E470, (void*)func_0041E230, (void*)func_002AF2A0, (void*)func_002AF310, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002AF000, (void*)func_002AF010, (void*)func_00293890, (void*)func_002AF040, (void*)func_002AFA80, (void*)func_002AFA20, (void*)func_0033EE40, (void*)func_0033E410, (void*)func_0033E5B0, (void*)func_002AF190, (void*)0x0 };
