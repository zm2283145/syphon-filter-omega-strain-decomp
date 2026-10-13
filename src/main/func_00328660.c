#include "types.h"
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { int pad[3]; int id; } Voice_328660;
typedef struct {
    char base[0x48];
    char a[0xC];
    unsigned char a0C;
    char pad55[3];
    int x58;
    char pad5C[0x10];
    int x6C;
    int x70;
    int x74;
    int x78;
    int x7C;
    int x80;
    char pad84[0xC];
    SoundRequest req;
} Obj_328660;
extern char D_004DE710[];
extern void GuiWidget_ctor(void* self);
extern void func_00328810(void* p);
extern void func_0032A280(void* p);
static inline void Req_Init_328660(SoundRequest* p, int type, __int128 name, Voice_328660* voice, int x180) {
    int tmp; int* r = &tmp;
    p->type = type;
    *(__int128*)p->name = name;
    p->voice = voice;
    if (voice) r = &voice->id; else tmp = -1;
    p->voiceId = *r;
    p->x30 = 0; p->x34 = 0; p->x38 = 0;
    p->x184 = -1;
    p->x180 = x180;
}
Obj_328660* func_00328660(Obj_328660* o)
{
    SoundRequest* p;
    char* pa;
    GuiWidget_ctor(o);
    *(char**)o = D_004DE710;
    pa = o->a;
    func_00328810(pa);
    pa[0xC] = 1;
    o->x6C = 0;
    o->x70 = 0;
    o->x74 = 0;
    o->x78 = 0;
    o->x7C = 0;
    o->x80 = 0;
    p = &o->req;
    p->voiceId = -2;
    p->voice = 0;
    func_0036E5D0(&p->a);
    func_0036E5D0(&p->b);
    Req_Init_328660(p, -1, -1, 0, 0);
    p->x186 = 0;
    func_0032A280(pa);
    o->x58 = -1;
    return o;
}


