#pragma cplusplus on
#include "types.h"
struct H_239610 { int v; };
struct P_239610 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_239610 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Track_239610 {
    void* vtable;
    float time;
    int kind;
    int pad0C;
    P_239610 snd;
};
struct Reader_239610 { int version; int size; unsigned int base; char* cur; };
struct Owner_239610 { char pad[0xC]; unsigned int flags; };
extern "C" {
extern char D_004DC038[];
extern void * const D_004DC008[];
void func_002395A0();
extern char** D_004F7C70;
extern int D_004F7C78;
extern int D_004F7C80;
extern int D_0048AE28;
void func_0036E5D0(void* m);
void SoundAction_CtorVoice(void* action, int kind, char* name, Owner_239610* owner, int x);
}
static inline float RdF(Reader_239610* r){ float t = *(float*)r->cur; r->cur += 4; return t; }
#pragma push
#pragma opt_propagation off
extern "C" Track_239610* func_00239610(Track_239610* self, Reader_239610* r, Owner_239610* o)
{
    P_239610* p;
    int id;
    char* name;
    self->vtable = D_004DC038;
    self->kind = 2;
    self->time = RdF(r);
    self->vtable = (void*)D_004DC008;
    *(int*)((char*)self + 0x34) = -2;
    *(int*)((char*)self + 0x30) = 0;
    p = &self->snd;
    func_0036E5D0(p->memberA);
    func_0036E5D0(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_239610 h; H_239610* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    id = (int)*(float*)r->cur;
    r->cur += 4;
    if ((o->flags & 0xFF0000) >> 16 != D_0048AE28)
        id += D_004F7C80;
    name = id < D_004F7C78 ? D_004F7C70[id] : 0;
    {
        int k = (int)*(float*)r->cur;
        r->cur += 4;
        SoundAction_CtorVoice(&self->snd, k, name, o, 0);
    }
    return self;
}
#pragma pop
extern "C" void * const D_004DC008[3] = { (void*)0x0, (void*)0x0, (void*)func_002395A0 };
