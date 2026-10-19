#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Phys {
    char pad0[4];
    void* w4;
    void* w8;
    void* wC;
    char pad10;
    unsigned char b11;
    char pad12[2];
    unsigned char b14;
    char pad15[0x9E0 - 0x15];
    char a9E0[0x20];
    char aA00[0x30];
};
struct Sec {
    char pad0[4];
    void* w4;
    unsigned char b8;
    char pad9[3];
    void* wC;
    void* w10;
};
struct Found { char pad[0x164]; void* w164; };
struct Root { char pad[0xB0]; char coll[4]; };
struct Opt { char pad[0xA0]; unsigned char bA0; };
struct Act {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x2E50 - 0x5C];
    char a2E50[0x2EC0 - 0x2E50];
    Root r2EC0;
    char pad2F74[0x2FE0 - 0x2EC0 - sizeof(Root)];
    void* w2FE0;
    char pad2FE4[0x3010 - 0x2FE4];
    void* w3010;
    void* w3014;
    char pad3018[0x3020 - 0x3018];
    void* w3020;
    void* w3024;
    char pad3028[0x32A0 - 0x3028];
    char a32A0[0x3310 - 0x32A0];
    Phys* p3310;
    Sec* p3314;
    char pad3318[0x3524 - 0x3318];
    Opt* p3524;
};
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0[];
extern char D_004A03C8[];
extern char D_004A03D0[];
void Alloc_Lock(int);
void Alloc_Unlock(int);
void* Mem_Alloc(int, int, char*, int);
Phys* ActorPhys_Ctor(void*);
Sec* ActorSecondary_Ctor(void*);
Found* RootCollection_FindByKey(void*, char*);
void Actor_ChooseSecondaryMode(Act*, int);
void ActorPhys_InitFrame(Phys*);
}
static inline Found* FindC(char* c, char* key)
{
    return RootCollection_FindByKey(c, key);
}
static inline Found* Find(Root* r, char* key)
{
    return RootCollection_FindByKey(r->coll, key);
}
static inline void Link(Sec* s, Root* r, Phys* p)
{
    s->wC = r;
    s->w10 = p;
}
static inline void Set3(Act* a, void* x, void* p)
{
    a->w2FE0 = x;
    a->w3014 = p;
    a->w3010 = 0;
}
extern "C" void Npc_CreatePhysical(Act* a)
{
    Phys* p;
    Sec* s;
    {
        AllocGuard g;
        p = (Phys*)Mem_Alloc(0, 0xA30, D_0049D8D0, 0x424);
    }
    if (p) p = ActorPhys_Ctor(p);
    a->p3310 = p;
    {
        AllocGuard g;
        s = (Sec*)Mem_Alloc(0, 0x840, D_0049D8D0, 0x425);
    }
    if (s) s = ActorSecondary_Ctor(s);
    a->p3314 = s;
    {
        Root* r = &a->r2EC0;
        Phys* q = a->p3310;
        char* c;
        q->w4 = a;
        q->w8 = a->a2E50;
        q->wC = r;
        c = r->coll;
        FindC(c, D_004A03C8)->w164 = q->a9E0;
        FindC(c, D_004A03D0)->w164 = q->aA00;
    }
    Set3(a, a->a32A0, a->p3310);
    Link(a->p3314, &a->r2EC0, a->p3310);
    s = a->p3314;
    a->w3024 = s;
    s->w4 = a->w3020;
    Actor_ChooseSecondaryMode(a, 0);
    if (a->p3524) a->p3524->bA0 = 0;
    a->p3310->b11 = 1;
    ActorPhys_InitFrame(a->p3310);
    if (a->b14) {
        bool on = 0;
        if (a->p58 && a->p58->IsOn()) on = 1;
        if (on) {
            a->p3314->b8 = 2;
            a->p3310->b14 = 3;
        }
    }
}





