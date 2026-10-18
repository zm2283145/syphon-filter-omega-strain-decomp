#include "types.h"
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_ECB0;
typedef struct { int type; int pad[3]; __int128 name; int ref[2]; } Act_ECB0;
typedef struct {
    CMSG_HEADER;
    char pad24[0xC];
    SoundRequest req;
    unsigned char evflags;
} SoundEv_ECB0;
extern char D_004F53D8[];
extern char D_004DADF0[];
extern Voice_ECB0* ActorRef_Copy(void* ref);
static inline void Req_Init(SoundRequest* p, int type, __int128 name, Voice_ECB0* voice, int x180) {
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
SoundEv_ECB0* SoundEvent_Ctor(SoundEv_ECB0* ev, Act_ECB0* act, unsigned char flags) {
    SoundRequest* p;
    Event_Construct(ev, D_004F53D8);
    ev->vtable = D_004DADF0;
    p = &ev->req;
    p->voiceId = -2;
    p->voice = 0;
    Resource_Construct(&p->a);
    Resource_Construct(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    ev->evflags = flags;
    Req_Init(&ev->req, act->type, act->name, ActorRef_Copy(act->ref), 0);
    return ev;
}
