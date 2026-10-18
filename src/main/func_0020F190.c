#include "types.h"
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
    Resource_Construct(&p->a);
    Resource_Construct(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
}
SoundEvent* func_0020F190(SoundEvent* ev, Src_F190* src, Voice_F190* voice) {
    SoundRequest* p;
    Event_Construct(ev, D_004F53C8);
    ev->vtable = D_004DAE10;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    Resource_Construct(&p->a);
    Resource_Construct(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    Req_Init(&ev->req, src->type, src->name, voice, src->x180);
    ev->req.x186 = src->x186;
    return ev;
}
