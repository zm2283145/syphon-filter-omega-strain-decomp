/*
 * main/weapon: range (3 files, 00144BA0-00144DC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00144BA0 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x1C]; unsigned char flag; char pad21[0x57]; char m78[0x9C]; char m114[0xBC]; } Msg_4BA0;
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[0xAC]; } Req_4BA0;
typedef struct { char pad[0x88]; int src; char pad8C[0x38]; int snd[6]; } S_4BA0;
extern char D_004DADF0[];
extern char D_004FFB50[];
void SoundRequest_Ctor(Req_4BA0* r, int a, int id, int b, int c);
void func_0020EBA0(Msg_4BA0* m, Req_4BA0* r, int src);
void Event_Send(Msg_4BA0* m, void* target, int a);
void func_0036E220(void* p, int f);
void cMessage_dtor(Msg_4BA0* m, int f);
void WeaponInv_StopLoopSound(S_4BA0* self, unsigned char slot)
{
    int* p = (int*)((char*)self->snd + (slot << 2));
    if (*p) {
        Req_4BA0 req;
        Msg_4BA0 msg;
        SoundRequest_Ctor(&req, 1, *p, 0, 0);
        func_0020EBA0(&msg, &req, self->src);
        msg.flag = 1;
        Event_Send(&msg, D_004FFB50, 0);
        *p = 0;
        msg.vt = D_004DADF0;
        func_0036E220(msg.m114, -1);
        func_0036E220(msg.m78, -1);
        cMessage_dtor(&msg, 0);
        func_0036E220(req.mE4, -1);
        func_0036E220(req.m48, -1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144BA0 */

/* merge_units: begin func_00144C70 */
#pragma push /* merge_units */
#pragma cplusplus on
class O_4C70 { public: int pad0; virtual void Destroy(int f); };
struct S_4C70 { void* snd; char pad[0xD0]; O_4C70* obj; void* node; };
extern "C" {
extern char D_0049B1D0[];
void func_00266470(void* p, int f);
#if 0 /* merge_units */
void WeaponInv_StopLoopSound(S_4C70* self, int slot);
#endif /* merge_units */
#define WeaponInv_StopLoopSound(a0, a1) (WeaponInv_StopLoopSound((S_4BA0 *)(a0), (unsigned char)(a1))) /* merge_units */

void Object_Unregister(void* n);
void Object_DeleteLater(float t, void* n);
void operator_delete(void* p);
}
extern "C" S_4C70* func_00144C70(S_4C70* self, short del)
{
    if (self) {
        void* s = self->snd;
        O_4C70* o;
        if (s) {
            AllocGuard g;
            func_00266470(s, -1);
            Mem_Free(0, s, D_0049B1D0, 0x4CE);
        }
        WeaponInv_StopLoopSound(self, 0);
        WeaponInv_StopLoopSound(self, 1);
        o = self->obj;
        if (o) {
            if (o)
                o->Destroy(1);
        }
        if (self->node) {
            Object_Unregister(self->node);
            Object_DeleteLater(0.1f, self->node);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef WeaponInv_StopLoopSound /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144C70 */

/* merge_units: begin func_00144DC0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern unsigned char D_00489D70[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void* HeldItem_Construct(void* p, void* actor);
void WeaponInv_Add(void* inv, int item, int a, int b, int c, int d);
}

struct WiObj { char pad[0xC]; int id; };
struct WiHandle {
    void* obj;
    int id;
    WiHandle() { id = -2; obj = 0; }
    void Set(WiObj* o) { int m0; int m1; int* p; obj = (void*)o; if (o) p = &o->id; else if (o) p = &m0; else { m1 = -1; p = &m1; } id = *p; }
};

static inline int NoId() { return -1; }
enum { kNoId = -1 };
static inline void* NewHeld(void* actor) {
    void* p;
    { AllocGuard g; p = Mem_Alloc(0, 0xD0, D_0049B1D0, 0x4B7); }
    if (p) p = HeldItem_Construct(p, actor);
    return p;
}

struct WiSlot {
    unsigned char holsterOk;
    char pad1[3];
    int itemId;
    int clip;
    int spare;
};

struct WiInv {
    void* held;
    WiSlot slots[8];
    unsigned char current;
    unsigned char previous;
    char pad86[2];
    void* actor;
    int unk8C;
    WiHandle burstTarget;
    unsigned char aimView;
    unsigned char infiniteReserve;
    char pad9A[2];
    int subtarget;
    unsigned char reloading;
    char padA1[3];
    int equipMarker;
    unsigned char dontDropWeapons;
    unsigned char activeHand;
    char padAA[2];
    float cooldown[2];
    float unkB4[2];
    int burstLeft[2];
    int loopSoundActive[2];
    float spinUp[2];
    int unkD4;
    int unkD8;
    char padDC[0xC];
    float unkE8;
    unsigned char unkEC;
    unsigned char unkED;
    unsigned char unkEE;
    unsigned char busy;
    unsigned char unkF0;
    char padF1[7];
};

extern "C" WiInv* WeaponInv_Construct(WiInv* self, void* actor, int withHeld) {
    int i;
    self->burstTarget.id = -2;
    self->burstTarget.obj = 0;
    for (i = 0; i < 8; i++) {
        self->slots[i].itemId = -1;
        self->slots[i].clip = 0;
        self->slots[i].spare = 0;
        self->slots[i].holsterOk = D_00489D70[i] < 8;
    }
    self->current = 6;
    self->actor = actor;
    self->previous = 6;
    self->unk8C = 0;
    self->aimView = 0;
    self->burstTarget.Set(0);
    self->infiniteReserve = 0;
    self->reloading = 0;
    self->unkE8 = 180.0f;
    self->unkEC = 0;
    self->unkED = 0;
    self->unkEE = 0;
    self->activeHand = 0;
    self->equipMarker = 0;
    self->held = withHeld ? NewHeld(actor) : 0;
    self->busy = 0;
    self->dontDropWeapons = 0;
    self->unkF0 = 0;
    self->unkD4 = 0;
    self->unkD8 = 0;
    self->burstLeft[0] = 0;
    self->cooldown[0] = 0.0f;
    self->unkB4[0] = 10000.0f;
    self->spinUp[0] = 0.0f;
    self->loopSoundActive[0] = 0;
    self->burstLeft[1] = 0;
    self->cooldown[1] = 0.0f;
    self->unkB4[1] = 10000.0f;
    self->spinUp[1] = 0.0f;
    self->loopSoundActive[1] = 0;
    if (withHeld) {
        WeaponInv_Add(self, 0x67, 0, 0, 0, 1);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144DC0 */
