#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

typedef struct HStr_263080 { char d[0x9C]; } HStr_263080;

typedef struct HSnd_263080 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    HStr_263080 s78;
    HStr_263080 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) HSnd_263080;

typedef struct HTaserMsg_263080 {
    void* vt;
    char pad4[0x18];
    int i1C;
    char b20;
    char pad21[3];
    char b24;
    char pad25[3];
    int i28;
    char pad2C[0x30];
} HTaserMsg_263080;

typedef struct HStateMsg_263080 {
    void* vt;
    char pad4[0x1C];
    char immediate;
    char pad21[3];
    int state;
    char sub;
    char pad29[3];
    int stamp;
} HStateMsg_263080;

typedef struct HNoiseMsg_263080 {
    void* vt;
    char pad4[0x4C];
} HNoiseMsg_263080;

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
struct HTarget_263080 {
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g)
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4(); virtual void h5();
    virtual void f100(void* actor, int a, int b, int c, int d, int e, float f);
    char pad4[8];
    int serial;
};

struct HIface_263080 {
    V8(a) V8(b)
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual bool f54();
};

typedef struct HActor_263080 {
    char pad0[0xC];
    int pos[2];
    unsigned char f14;
    char pad15[0x58 - 0x15];
    HIface_263080* p58;
} HActor_263080;

struct HOwned_263080 {
    int pad0;
    virtual ~HOwned_263080();
};

typedef struct HNode_263080 {
    struct HNode_263080* prev;
    struct HNode_263080* next;
    char pad8[8];
    void* data;
} HNode_263080;

typedef struct HHead_263080 {
    HNode_263080* prev;
    HNode_263080* next;
} HHead_263080;

typedef struct HIter_263080 {
    HNode_263080* n;
} HIter_263080;

typedef struct HDef_263080 {
    char pad0[0xFC];
    float fFC;
} HDef_263080;

typedef struct HPos_263080 { char d[0x40]; } HPos_263080;

typedef struct HeldItem_263080 {
    HDef_263080* def;
    HActor_263080* actor;
    unsigned char state;
    char pad9[3];
    HOwned_263080* owned;
    int pad10;
    int count;
    HPos_263080* pos;
    int pad1C;
    int list;
    HHead_263080 head;
    HTarget_263080* hp;
    int hserial;
    char pad34[0xBC - 0x34];
    unsigned char bBC;
    unsigned char bBD;
    char padBE[2];
    void* pC0;
    float fC4;
    float fC8;
    float fCC;
} HeldItem_263080;

extern "C" {
extern void cMessage_ctor_cMessageNameR(void* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void cHuman_SetParticleEffect(HTarget_263080* a, int kind, int b, float f);
extern void cStopSoundMsg_ctor_cSndFxR_cGOBJP(HSnd_263080* e, void* preset, void* owner);
extern void cFileMan_dtor(HStr_263080* s, int flag);
extern HHead_263080* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_6(HHead_263080* p);
extern HNode_263080* std_list_deleter_TaserPulse_tail(int* list);
extern void std_list_deleter_TaserPulse_generic_iterator_ctor(HIter_263080* it, HNode_263080* n);
extern void std_list_deleter_TaserPulse_erase_listdeleter(HIter_263080* res, int* list, HIter_263080* pos);
extern void cParticle_dtor(void* p, int flag);
extern void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern void cGameSystem_PopWeaponCam(void* w);
extern int cGameSystem_GetAgentData(void* w, int idx);
extern void cAgentData_AddScore(int agent, int kind, int n);
extern int Libc_Rand(void);
extern void* cSystemContainer_GetSystem(void* w, void* key);
extern void cAISoundSystemGOBJPositionMessage_ctor(HNoiseMsg_263080* m, float a, int* id, HPos_263080* pos, signed char kind, float b);

extern unsigned char g_IsMultiplayer;
extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern char g_ActorActionMsgClass[];
extern char D_004E01E0[];
extern char D_004E0840[];
extern int D_0048B1D8;
extern char D_004F12D0[];
extern char D_004F1470[];
extern char g_Game[];
extern char D_004DADF0[];
extern char D_004A81E8[];
extern float D_0048B150;
extern float D_0048B158;
extern float D_004F8330;
extern float D_0048B148;
extern char D_004EE5C0[];
extern char D_004D92A0[];
}

static inline HTarget_263080* Handle_Get(HeldItem_263080* h) {
    bool isNull;
    bool ok;
    HTarget_263080* t;
    t = h->hp;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->serial != h->hserial) ok = false;
    return ok ? t : 0;
}

static inline HTarget_263080* Handle_Ptr(HeldItem_263080* h) {
    bool isNull;
    HTarget_263080* t;
    t = h->hp;
    isNull = !t;
    return (isNull || t->serial == h->hserial) ? t : 0;
}

static inline void Del_263080(void* p, int line) {
    AllocGuard g;
    cParticle_dtor(p, -1);
    cMemMan_Deallocate(0, p, D_004A81E8, line);
}

static inline bool HasF54(HIface_263080* q) {
    bool r = false;
    if (q) if (q->f54()) r = true;
    return r;
}

static inline bool HasF54b(HActor_263080* a) {
    bool r = false;
    if (a->p58 && a->p58->f54()) r = true;
    return r;
}

static inline float Rand01(void) {
    return (float)Libc_Rand() / 2147483648.0f;
}

/* Wrapper depth matters: MW allocates inline locals breadth-first by inline depth,
   so these iterator slots land below the two AllocGuard slots from Del_263080. */
static inline HNode_263080* EndN263(int* l) { HIter_263080 e; std_list_deleter_TaserPulse_generic_iterator_ctor(&e, std_list_deleter_TaserPulse_tail(l)); return e.n; }
static inline HNode_263080* End2263(int* l) { return EndN263(l); }
static inline HNode_263080* EraseN263(int* l, HNode_263080* it) { HIter_263080 res; HIter_263080 tmp; tmp.n = it; std_list_deleter_TaserPulse_erase_listdeleter(&res, l, &tmp); return res.n; }
static inline HNode_263080* Erase1263(int* l, HNode_263080* it) { return EraseN263(l, it); }
extern "C" void cAirTaser_Release(HeldItem_263080* s)
{
    if (s->state) {
        if (s->actor->f14 && g_IsMultiplayer) {
            HTaserMsg_263080 m;
            cMessage_ctor_cMessageNameR(&m, D_00504050);
            m.i28 = 0;
            m.vt = D_004DCDA0;
            m.b24 = 2;
            m.b20 = 4;
            m.i1C = 0x40;
            QueueMessage_cMessageR_cSystemP_int(&m, s->actor, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
        if (Handle_Get(s)) {
            HStateMsg_263080 sm;
            HSnd_263080 a;
            HSnd_263080 b;
            cHuman_SetParticleEffect(Handle_Ptr(s), 2, 0, 1.0f);
            cHuman_SetParticleEffect(Handle_Get(s), 1, 0, 1.0f);
            cMessage_ctor_cMessageNameR(&sm, g_ActorActionMsgClass);
            sm.state = 7;
            sm.sub = 2;
            sm.vt = D_004E01E0;
            sm.immediate = 1;
            sm.stamp = D_0048B1D8;
            QueueMessage_cMessageR_cSystemP_int(&sm, Handle_Get(s), 0);
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&a, D_004F12D0, Handle_Get(s));
            a.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&a, g_Game, 0);
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&b, D_004F1470, Handle_Get(s));
            b.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&b, g_Game, 0);
            b.vt = D_004DADF0;
            cFileMan_dtor(&b.s114, -1);
            cFileMan_dtor(&b.s78, -1);
            cMessage_dtor(&b, 0);
            a.vt = D_004DADF0;
            cFileMan_dtor(&a.s114, -1);
            cFileMan_dtor(&a.s78, -1);
            cMessage_dtor(&a, 0);
            sm.vt = D_004E0840;
            cMessage_dtor(&sm, 0);
        }
        {
            HNode_263080* it = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_6(&s->head)->next;
            while (it != End2263(&s->list)) {
                void* p = it->data;
                Del_263080(p, 0x295);
                it = Erase1263(&s->list, it);
            }
        }
        if (s->pC0) {
            void* p = s->pC0;
            Del_263080(p, 0x29B);

            s->pC0 = 0;
        }
        if (s->owned) {
            HOwned_263080* o = s->owned;
            delete o;
            s->owned = 0;
        }
        if (s->state == 2) {
            cGameSystem_PopWeaponCam(g_Game);
            if (Handle_Get(s)) {
                if (s->bBC) {
                    Handle_Ptr(s)->f100(s->actor, 1, 4, 0, 0, 0, 10000.0f);
                } else if (s->bBD) {
                    HTarget_263080* t;
                    if (s->actor->f14) {
                        HIface_263080* q = s->actor->p58;
                        bool ok = HasF54b(s->actor);
                        if (ok) cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 6, 1);
                    }
                    t = Handle_Get(s);
                    t->f100(s->actor, 1, 7, 0, 0, 0, 0.0f);
                }
            }
        }
        s->state = 3;
        s->fC4 = D_0048B150 + (D_0048B158 - D_0048B150) * Rand01();
        s->fC8 = D_004F8330 + (D_0048B148 - D_004F8330) * Rand01();
        s->fCC = D_0048B148 - s->fC8;
        if (Libc_Rand() & 1) s->fC8 = -s->fC8;
        if (Libc_Rand() & 1) s->fCC = -s->fCC;
        if (s->count > 1) {
            void* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
            HNoiseMsg_263080 nm;
            cAISoundSystemGOBJPositionMessage_ctor(&nm, 1.0f, s->actor->pos, &s->pos[s->count - 1], 4, s->def->fFC);
            QueueMessage_cMessageR_cSystemP_int(&nm, svc, 0);
            nm.vt = D_004D92A0;
            cMessage_dtor(&nm, 0);
        }
    }
}