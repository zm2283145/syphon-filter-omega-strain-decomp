#include "types.h"
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_BA10;
typedef struct {
    void* vtbl;
    char pad4[0x48 - 4];
    int x48;
    char pad4c[0x78 - 0x4C];
    int x78;
    char pad7c[0xB4 - 0x7C];
    int xB4;
    char cfg[0x28];
    SoundRequest r1;
    SoundRequest r2;
} G_BA10;
extern char D_004E1220[];
extern char D_004DD580[];
void GuiWidget_ctor(void*);
void func_0045A7A0(void*);
static inline void Req_Init(SoundRequest* p, int type, __int128 name, Voice_BA10* voice, int x180) {
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
G_BA10* func_0029BA10(G_BA10* self) {
    SoundRequest* p;
    GuiWidget_ctor(self);
    self->vtbl = D_004E1220;
    self->x48 = -2;
    self->vtbl = D_004DD580;
    func_0045A7A0(self->cfg);
    p = &self->r1;
    p->voiceId = -2;
    p->voice = 0;
    func_0036E5D0(&p->a);
    func_0036E5D0(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    p = &self->r2;
    p->voiceId = -2;
    p->voice = 0;
    func_0036E5D0(&p->a);
    func_0036E5D0(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    self->xB4 = 0;
    self->x78 = 0;
    ((unsigned char*)self)[0x400] = 0;
    return self;
}