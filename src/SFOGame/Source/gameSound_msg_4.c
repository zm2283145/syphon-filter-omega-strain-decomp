/*
 * SFOGame/Source/gameSound_msg: 4 files, 0020EA20-0020ECB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020EA20 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x30); *(__int128*)(b + 0x10) = *(__int128*)((char*)e + 0x40); MP_I(b, 0x20) = MP_I(e, 0x1B0); MP_U(b, 0x24) = MP_U(e, 0x1C0);

DEFINE_MESSAGE_PACK(cStopSoundMsg_Pack, 48, D_004F53E0, PACK_BODY)
static inline void merge_flush_func_0020EA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020EA20 */

/* merge_units: begin func_0020EAB0 */
#pragma push /* merge_units */
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_F190;
extern char D_004F53D8[];
extern char D_004DADF0[];
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
typedef struct { int pad0[2]; int type; int pad[1]; __int128 name; int x20; unsigned char x24; } Src_EAB0;
SoundEvent* cStopSoundMsg_ctor_netStopSoundMsgR(SoundEvent* ev, Src_EAB0* src) {
    SoundRequest* p;
    cMessage_ctor_cMessageNameR(ev, D_004F53D8);
    ev->vtable = D_004DADF0;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    ev->pad1C0[0] = src->x24;
    Req_Init(&ev->req, src->type, src->name, 0, src->x20);
    return ev;
}
static inline void merge_flush_func_0020EAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020EAB0 */

/* merge_units: begin func_0020EBA0 */
#pragma push /* merge_units */
typedef struct { int type; int pad[3]; __int128 name; } Src_EBA0;
SoundEvent* cStopSoundMsg_ctor_cSndFxR_cGOBJP(SoundEvent* ev, Src_EBA0* src, Voice_F190* voice) {
    SoundRequest* p;
    cMessage_ctor_cMessageNameR(ev, D_004F53D8);
    ev->vtable = D_004DADF0;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    ev->pad1C0[0] = 0;
    Req_Init(&ev->req, src->type, src->name, voice, 0);
    return ev;
}
static inline void merge_flush_func_0020EBA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020EBA0 */

/* merge_units: begin func_0020ECB0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } Voice_ECB0;
typedef struct { int type; int pad[3]; __int128 name; int ref[2]; } Act_ECB0;
typedef struct {
    CMSG_HEADER;
    char pad24[0xC];
    SoundRequest req;
    unsigned char evflags;
} SoundEv_ECB0;
extern Voice_ECB0* cSafePtr_cGOBJ_opCast_cGOBJPtr(void* ref);
static inline void Req_Init_0020ECB0(SoundRequest* p, int type, __int128 name, Voice_ECB0* voice, int x180) {
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
SoundEv_ECB0* cStopSoundMsg_ctor_cSndFxR_bool(SoundEv_ECB0* ev, Act_ECB0* act, unsigned char flags) {
    SoundRequest* p;
    cMessage_ctor_cMessageNameR(ev, D_004F53D8);
    ev->vtable = D_004DADF0;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init_0020ECB0(p, -1, -1, 0, 0);
    p->x186 = 0;
    ev->evflags = flags;
    Req_Init_0020ECB0(&ev->req, act->type, act->name, cSafePtr_cGOBJ_opCast_cGOBJPtr(act->ref), 0);
    return ev;
}
static inline void merge_flush_func_0020ECB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020ECB0 */
