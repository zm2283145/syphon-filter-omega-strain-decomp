/*
 * SFOGame/Source/gameSound_msg: 5 files, 0020F540-0020F990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020F540 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int pad; int b[4]; int c; int d; char e; } Proto_0020F540;
extern char D_004F53C0[];
extern void SoundPosRequest_NetReceive(void);

NETREG_BEGIN(SoundPosRequest_NetRegister, Proto_0020F540)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 0x10, 1)
NETREG_FIELD(c, 4, 1)
NETREG_FIELD(d, 4, 1)
NETREG_FIELD(e, 1, 1)
NETREG_END(D_004F53C0, SoundPosRequest_NetReceive)
static inline void merge_flush_func_0020F540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F540 */

/* merge_units: begin func_0020F620 */
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
extern int D_004F53C0;
#endif /* merge_units */
#define D_004F53C0 (*(int*)&D_004F53C0) /* merge_units */

void Event_PackHeader(Ev_EF50* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
}
extern "C" int SoundPosRequest_Serialize(Ev_EF50* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf) {
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
            *type = D_004F53C0;
        }
    }
    return r;
}
#undef D_004F53C0 /* merge_units */
static inline void merge_flush_func_0020F620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F620 */

/* merge_units: begin func_0020F730 */
#pragma push /* merge_units */
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_F190;
extern char g_PlaySndMsgClass[];
extern char D_004DAE30[];
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
SoundEvent* cPlaySoundMsg_ctor_cSndFxR_cVectorR(SoundEvent* ev, Preset_F060* pr) {
    SoundRequest* p;
    Voice_F190* voice;
    int id;
    cMessage_ctor_cMessageNameR(ev, g_PlaySndMsgClass);
    ev->vtable = D_004DAE30;
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
static inline void merge_flush_func_0020F730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F730 */

/* merge_units: begin func_0020F860 */
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
static inline void Req_InitPos(SoundRequest* p, int type, __int128 name, Voice_F190* voice, const Vec_F2A0& pos, int x180) {
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
static inline unsigned char GetX186(Src_F2A0* s) { return s->x186; }
static inline void SetX186(SoundRequest* p, unsigned char v) { p->x186 = v; }
extern "C" SoundEventP* cPlaySoundMsg_ctor_cSndFxR_cGOBJP(SoundEventP* ev, Src_F2A0* src, Vec_F2A0* pos) {
    SoundRequest* p;
    cMessage_ctor_cMessageNameR(ev, g_PlaySndMsgClass);
    ev->vtable = D_004DAE30;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    Req_InitPos(&ev->req, src->type, src->name, 0, *pos, src->x180);
    SetX186(&ev->req, GetX186(src));
    return ev;
}
static inline void merge_flush_func_0020F860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F860 */

/* merge_units: begin func_0020F990 */
#pragma push /* merge_units */
SoundEvent* cPlaySoundMsg_ctor_cSndFxR(SoundEvent* ev, Src_F190* src, Voice_F190* voice) {
    SoundRequest* p;
    cMessage_ctor_cMessageNameR(ev, g_PlaySndMsgClass);
    ev->vtable = D_004DAE30;
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
static inline void merge_flush_func_0020F990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020F990 */
