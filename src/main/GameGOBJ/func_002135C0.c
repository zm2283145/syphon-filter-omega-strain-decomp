#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { char d[0x9C]; } LuStr;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LuStr s78;
    LuStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LuSnd;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LuMsg;
struct LuShm { int f0; int f4; };
struct LuSeg { char pad[0x1C]; LuShm* p1C; };
struct LuCtl { int f0; char pad4[0x1C]; int f20; char pad24[4]; int f28; };
struct LuQ { __int128 q; LuQ() {} LuQ(const LuQ& o) { const LuQ* s = &o; LuQ* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); } };
struct LuSub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0x40 - 4];
    LuQ pos;
    unsigned char f50;
};
struct LuIt { void** p; };
struct LuVec;
struct Lift {
    VPAD32(a)
    virtual void Refresh();
    char pad4[8];
    int fC;
    char pad10[0x50 - 0x10];
    LuSub* sub;
    char pad54[0x70 - 0x54];
    int f70;
    char pad74[0xDC - 0x74];
    unsigned char fDC;
    char padDD[3];
    int fE0;
    char padE4[0x128 - 0xE4];
    LuCtl* ctl;
    int floors[5];
    int nFloors;
    char pad144[0x2E0 - 0x144];
    char preset2[0x470 - 0x2E0];
    char preset1[0x790 - 0x470];
    LuShm* shm;
};
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern unsigned char D_005721D0;
extern int D_004F54A0;
extern int D_0048AAE8;
extern char D_004A44D0[];
extern char D_004A44F0[];
extern char D_004F5448[];
extern char D_004DAED0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
int func_0042B1A0(int a);
int func_002EAF28(int* h, int a, int b, int c, int d, int e, int f, void* buf, char* name, int size);
int func_002EB650(LuSeg** o, int h);
void printf(char* s, int h, int n);
void func_002EC460(int h);
void* World_GetActorArray(void);
LuVec* func_001339A0(void* arr);
void PtrVec_End(LuIt* out, LuVec* v);
void func_00133980(LuIt* out, LuIt* in);
void PathObj_Update(Lift* l, float dt);
int func_00213FA0(Lift* l);
int func_00214160(Lift* l);
void Lift_CloseDoors(Lift* l);
void Lift_OpenDoors(Lift* l);
void Lift_FinishArrival(Lift* l);
void Lift_ActivateRecipients(Lift* l);
void Lift_SeekFloor(Lift* l, int floor, int a2, int a3);
void Event_Construct(LuMsg* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void SoundEvent_CtorFromPreset(LuSnd* e, void* preset, Lift* l);
void func_0036E220(LuStr* s, int flag);
}
static inline bool LuIsHost(void) { unsigned char r; if (D_005721C8) r = D_005721C0; else r = true; return r; }
static inline LuShm* LuCreate(void)
{
    int h;
    LuSeg* seg;
    LuShm* r = 0;
    if (!LuIsHost() || !D_005721D0) return 0;
    {
        if (!func_002EAF28(&h, 2, 3, 0, 0, 0, 0, 0, D_004A44D0, D_0048AAE8)) {
            if (!func_002EB650(&seg, h)) {
                r = seg->p1C;
                r->f4 = h;
                printf(D_004A44F0, h, 8);
            }
        }
    }
    return r;
}
static inline void LuGetEnd(LuIt* o, LuVec* v) { LuIt te; PtrVec_End(&te, v); func_00133980(o, &te); }
extern "C" void Lift_Update(Lift* l, float dt)
{
    LuIt it;
    if (D_005721C8 && LuIsHost()) {
        if (!l->shm && D_004F54A0 < func_0042B1A0(1)) {
            l->shm = LuCreate();
            if (l->shm) {
                int id = l->fC;
                l->shm->f0 = id;
                func_002EC460(l->shm->f4);
            }
            D_004F54A0 = func_0042B1A0(1) + 500;
        }
    }
    LuGetEnd(&it, func_001339A0(World_GetActorArray()));
    LuSub* s = l->sub;
    if (s->f50) s->Sync();
    LuQ p = s->pos;
    l->Refresh();
    PathObj_Update(l, dt);
    LuCtl* c = l->ctl;
    switch (c->f28) {
    case 0:
        if (c->f20 != c->f0) c->f28 = 1;
        break;
    case 1:
        if (!l->fDC) break;
        if (c->f20 != c->f0) {
            if (l->f70 > 0 && func_00213FA0(l)) {
                Lift_CloseDoors(l);
                break;
            }
            if (!func_00214160(l) && l->f70 > 0) break;
            {
                LuSnd ev1;
                LuSnd ev2;
                SoundEvent_CtorFromPreset(&ev1, l->preset1, l);
                ev1.flag = 1;
                SoundEvent_CtorFromPreset(&ev2, l->preset2, l);
                ev2.flag = 1;
                Event_Send(&ev1, D_004FFB50, 1);
                Event_Send(&ev2, D_004FFB50, 1);
                l->fDC = 0;
                l->fE0 = 0;
                ev2.vt = D_004DAE30;
                func_0036E220(&ev2.s114, -1);
                func_0036E220(&ev2.s78, -1);
                cMessage_dtor(&ev2, 0);
                ev1.vt = D_004DAE30;
                func_0036E220(&ev1.s114, -1);
                func_0036E220(&ev1.s78, -1);
                cMessage_dtor(&ev1, 0);
            }
            break;
        }
        if (l->f70 <= 0) Lift_FinishArrival(l);
        if (l->f70 > 0 && func_00214160(l)) {
            if (!D_005721C8 || LuIsHost()) {
                LuMsg msg;
                LuMsg* m = &msg;
                Event_Construct(m, D_004F5448);
                m->vtable = D_004DAED0;
                m->kind = 0;
                m->arg = 0;
                Event_Send(m, l, 0);
                msg.vtable = D_004DAED0;
                cMessage_dtor(m, 0);
            }
            Lift_OpenDoors(l);
            break;
        }
        if (!func_00213FA0(l) && l->f70 > 0) break;
        l->ctl->f28 = 0;
        Lift_ActivateRecipients(l);
        {
            int f = -1;
            if (l->nFloors) {
                l->nFloors--;
                f = l->floors[l->nFloors];
            }
            if (f != -1) Lift_SeekFloor(l, f, 1, 0);
        }
        break;
    }
}

