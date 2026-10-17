#pragma opt_propagation off
#pragma cplusplus on
#pragma opt_foldconstants off
#include "types.h"
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_F190;
struct Vec_F2A0 {
    int v[4];
    Vec_F2A0(const Vec_F2A0& o) { Vec_F2A0* d = this; const Vec_F2A0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    Vec_F2A0& operator=(const Vec_F2A0& o) { Vec_F2A0* d = this; const Vec_F2A0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
typedef struct {
    int type; int pad[3]; __int128 name; Voice_F190* voice; int voiceId; int pad28[2];
    Vec_F2A0 pos; char pad40[0x140]; int x180; short x184; unsigned char x186;
} Src_F2A0;
extern "C" {
extern char D_004F53C8[];
extern char D_004DAE10[];
extern Voice_F190* ActorRef_Copy(void* ref);
}
static inline void Req_Init(SoundRequest* p, int type, __int128 name, Voice_F190* voice, int x180) {
    int tmp; int* r;
    p->type = type;
    *(__int128*)p->name = name;
    p->voice = voice;
    if (voice) r = &voice->id; else { tmp = -1; r = &tmp; }
    p->voiceId = *r;
    p->x30 = 0; p->x34 = 0; p->x38 = 0;
    p->x184 = -1;
    p->x180 = x180;
}
static inline void Req_InitPos(SoundRequest* p, int type, __int128 name, Voice_F190* voice, Vec_F2A0 pos, int x180) {
    int tmp; int* r;
    p->type = type;
    *(__int128*)p->name = name;
    p->voice = voice;
    if (voice) r = &voice->id; else { tmp = -1; r = &tmp; }
    p->voiceId = *r;
    *(Vec_F2A0*)&p->x30 = pos;
    p->x184 = -1;
    p->x180 = x180;
}
static inline bool IEq(int a, int b) { return a == b; }
static inline bool HValid(Src_F2A0* h) { Voice_F190* t = h->voice; bool ok = true; if (((t != 0) ^ 1) == 0) if (IEq(t->id, h->voiceId) == false) ok = false; return ok; }
static inline Voice_F190* HGet(Src_F2A0* h) { return HValid(h) ? h->voice : 0; }
extern "C" SoundEventP* SoundMsg_WrapAction(SoundEventP* ev, Src_F2A0* src) {
    SoundRequest* p;
    Event_Construct(ev, D_004F53C8);
    ev->vtable = D_004DAE10;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    func_0036E5D0(&p->a);
    func_0036E5D0(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    if (HGet(src))
        Req_Init(&ev->req, src->type, src->name, ActorRef_Copy(&src->voice), src->x180);
    else
        Req_InitPos(&ev->req, src->type, src->name, 0, src->pos, src->x180);
    ev->req.x186 = src->x186;
    return ev;
}






