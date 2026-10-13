#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern unsigned char D_00489D70[];
extern char D_0049B1D0[];
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






