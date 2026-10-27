/*
 * SFOGame/Source/gameSound_msg: 5 files, 0020EE70-0020F2A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020EE70 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; int b; } Desc0020EE70;
typedef struct { int a; int pad[1]; int b[4]; int c; int d; char e; } Proto0020EE70;
extern int NetRegisterMessageStart(void* reg);
extern int cMessage_RegisterFields(void* d);
extern int NetMessageField(void* d, void* field, int size, int count);
extern int NetRegisterMessage(void* type, int version, void* factory);
extern char D_004F53D0[];
extern void cPlaySoundMsg_NetPlaySoundMsgCallback(void);
unsigned char cPlaySoundMsg_InitNet_void(void* reg)
{
    struct { long long file; Proto0020EE70 p; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cMessage_RegisterFields(&L.file) != 0 &&
        NetMessageField(&L.file, &L.p.a, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.p.b, 0x10, 1) == 0 &&
        NetMessageField(&L.file, &L.p.c, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.p.d, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.p.e, 1, 1) == 0 &&
        NetRegisterMessage(D_004F53D0, 2, cPlaySoundMsg_NetPlaySoundMsgCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_0020EE70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020EE70 */

/* merge_units: begin func_0020EF50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Voice_EF50 { char pad[0xC]; int id; };
struct Handle_EF50 {
    Voice_EF50* p; int id;
    inline bool Valid() { return !p || p->id == id; }
    inline Voice_EF50* Get() { return Valid() ? p : 0; }
};
struct Ev_EF50 {
    char hdr[0x30]; int type; int pad34[3]; __int128 name; Handle_EF50 voice;
    char pad58[0x1B0 - 0x58]; int x180; short x184; unsigned char x186;
};
struct Out_EF50 { int pad[2]; int type; int pad0c; __int128 name; int x180; int id; unsigned char x186; };
extern "C" {
#if 0 /* merge_units */
extern int D_004F53D0;
#endif /* merge_units */
#define D_004F53D0 (*(int*)&D_004F53D0) /* merge_units */

void Event_PackHeader(Ev_EF50* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
}
extern "C" int func_0020EF50(Ev_EF50* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf) {
    int r = -1;
    if (size >= 0x30 && buf) {
        Out_EF50* o = (Out_EF50*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        o->type = e->type;
        o->name = e->name;
        o->x180 = e->x180;
        o->x186 = e->x186;
        if (e->voice.Get()) o->id = e->voice.Get()->id; else o->id = 0;
        if (type) {
            r = 0x30;
            *type = D_004F53D0;
        }
    }
    return r;
}
#undef D_004F53D0 /* merge_units */
static inline void merge_flush_func_0020EF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020EF50 */

/* merge_units: begin func_0020F060 */
#pragma push /* merge_units */
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_F190;
extern char D_004F53C8[];
extern char D_004DAE10[];
typedef struct { int type; int pad[3]; __int128 name; int x20; int pad24[0x57]; int x180; short x184; unsigned char x186; } Src_F190;
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
static inline void Req_Default(SoundRequest* p) {
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
}
typedef struct { int pad[2]; int type; int pad0c; __int128 name; int x180; int id; unsigned char x186; } Preset_F060;
extern Voice_F190* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
SoundEvent* func_0020F060(SoundEvent* ev, Preset_F060* pr) {
    SoundRequest* p;
    Voice_F190* voice;
    int id;
    cMessage_ctor_cMessageNameR(ev, D_004F53C8);
    ev->vtable = D_004DAE10;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    voice = 0;
    if (pr->id) { id = pr->id; voice = nGobjManager_LookupGOBJ_cObjectIdR(&id); }
    Req_Init(&ev->req, pr->type, pr->name, voice, pr->x180);
    ev->req.x186 = pr->x186;
    return ev;
}
static inline void merge_flush_func_0020F060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F060 */

/* merge_units: begin func_0020F190 */
#pragma push /* merge_units */
SoundEvent* cPlaySoundMsg_ctor_netPlaySoundMsgR(SoundEvent* ev, Src_F190* src, Voice_F190* voice) {
    SoundRequest* p;
    cMessage_ctor_cMessageNameR(ev, D_004F53C8);
    ev->vtable = D_004DAE10;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    Req_Init(&ev->req, src->type, src->name, voice, src->x180);
    ev->req.x186 = src->x186;
    return ev;
}
static inline void merge_flush_func_0020F190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F190 */

/* merge_units: begin func_0020F2A0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
#pragma opt_foldconstants off

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
extern Voice_F190* cSafePtr_cGOBJ_opCast_cGOBJPtr(void* ref);
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
    cMessage_ctor_cMessageNameR(ev, D_004F53C8);
    ev->vtable = D_004DAE10;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    if (HGet(src))
        Req_Init(&ev->req, src->type, src->name, cSafePtr_cGOBJ_opCast_cGOBJPtr(&src->voice), src->x180);
    else
        Req_InitPos(&ev->req, src->type, src->name, 0, src->pos, src->x180);
    ev->req.x186 = src->x186;
    return ev;
}
static inline void merge_flush_func_0020F2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F2A0 */
