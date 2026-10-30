// 00264980 cAirTaser_BeginShocking_cHumanP_int_cVector -- cAirTaser::BeginShocking(cHuman*, int, cVector) (taser.cc). l7 match.
// AI noise message and cVector are expression temporaries (prototype has no locals for them); temp dtor weak in .dtors_drop.
#pragma cplusplus on
#include "types.h"

typedef struct HStr { char d[0x9C]; } HStr;
typedef struct HSnd {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    HStr s78;
    HStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) HSnd;
typedef struct HNoiseMsg { void* vt; char pad4[0x4C]; } HNoiseMsg;
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" char D_004D92A0[];
#pragma define_section ALLOC_GUARD_DTOR ".dtors_drop" far_absolute RX
struct AiMsg : HNoiseMsg { __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AiMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); } };
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct HTarget { void* vt; char pad4[8]; int serial; };
typedef struct HActor { char pad0[0xC]; int pos[2]; int* Id() { return pos; } const int& IdR() const { return pos[0]; } } HActor;
typedef struct HDef { char pad0[0xFC]; float fFC; float Get() const { return fFC; } } HDef;
typedef struct HeldItem {
    HDef* def;
    HActor* actor;
    unsigned char state;
    char pad9[0x2C - 9];
    HTarget* hp;
    int hserial;
    char pad34[8];
    void* x3C;
    V pos;
    char pad50[0xB4 - 0x50];
    int xB4;
    float xB8;
    unsigned char bBC;
    unsigned char bBD;
    static bool Same(int a, int b) { return a == b; }
    bool Valid() { return !hp || Same(hp->serial, hserial); }
    HTarget* Get() { return Valid() ? hp : 0; }
    void Set(HTarget* o) { hp = o; int d; hserial = *(o ? &o->serial : (d = -1, &d)); }
} HeldItem;

extern "C" {
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void cHuman_SetParticleEffect(HTarget* a, int kind, int b, float f);
extern void cPlaySoundMsg_ctor_cSndFxR(HSnd* e, void* preset, void* owner);
extern void cFileMan_dtor(HStr* s, int flag);
extern void* cSystemContainer_GetSystem(void* w, void* key);
extern void* cHuman_GetFloorAnchor_void_2(HTarget* a);
extern V* cSkaAnimAnchor_GetPosition(void* r);
extern V* cVector_ctor_cVectorR(V* d, V* s);
extern AiMsg cAISoundSystemGOBJPositionMessage_ctor(const int& id, const V& pos, int kind, float a, float b);
extern char D_004F12D0[];
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004EE5C0[];
extern char D_004D92A0[];
void cAirTaser_BeginShocking_cHumanP_int_cVector(HeldItem* s, HTarget* t, void* a2, V* pos);
}

inline void Queue(const HNoiseMsg& m, void* sys, int imm) { QueueMessage_cMessageR_cSystemP_int((void*)&m, sys, imm); }
struct VC : V { VC(const V& o) { cVector_ctor_cVectorR(this, (V*)&o); } };
void cAirTaser_BeginShocking_cHumanP_int_cVector(HeldItem* s, HTarget* t, void* a2, V* pos)
{
    s->state = 2;
    s->xB4 = 0;
    s->bBD = 0;
    s->bBC = 0;
    s->Set(t);
    s->xB8 = 10000.0f;
    s->x3C = a2;
    s->pos = *pos;
    cHuman_SetParticleEffect(s->Get(), 2, 1, 1.0f);
    {
        HSnd ev;
        cPlaySoundMsg_ctor_cSndFxR(&ev, D_004F12D0, s->Get());
        ev.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
        {
            void* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
            /* the message is a temporary built by its (out-of-line) ctor: returned by value via the hidden a0 pointer */
            Queue(cAISoundSystemGOBJPositionMessage_ctor(*s->actor->Id(), VC(*cSkaAnimAnchor_GetPosition(cHuman_GetFloorAnchor_void_2(t))), 4, 1.0f, s->def->fFC), svc, 0);
        }
        ev.vt = D_004DAE30;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}



