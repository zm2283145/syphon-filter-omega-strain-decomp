/*
 * main/NIEvent: range (2 files, 00239610-00239780)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00239610 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void Resource_Construct(void* m);
void SoundAction_CtorVoice(void* action, int kind, char* name, Owner_239610* owner, int x);
}
static inline float RdF(Reader_239610* r){ float t = *(float*)r->cur; r->cur += 4; return t; }
#pragma push
#pragma opt_propagation off
extern "C" Track_239610* NiEventType4_CtorFromStream(Track_239610* self, Reader_239610* r, Owner_239610* o)
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
    Resource_Construct(p->memberA);
    Resource_Construct(p->memberB);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239610 */

/* merge_units: begin func_00239780 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char pad04[0x1C];
    char b20;
    char pad21[0x57];
    char memberA[0x9C];
    char memberB[0xAC];
} Msg00239780;
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void SoundEvent_CtorFromPreset(Msg00239780* m, void* preset, void* a);
extern void Event_Send(Msg00239780* m, void* target, int a);
extern void FileMan_Release(void* member, int flags);
extern void cMessage_dtor(Msg00239780* m, int flags);
void NiEventSound_Fire(char* self, void* a)
{
    Msg00239780 m;
    SoundEvent_CtorFromPreset(&m, self + 0x10, a);
    m.b20 = 1;
    Event_Send(&m, D_004FFB50, 1);
    m.vtable = D_004DAE30;
    FileMan_Release(m.memberB, -1);
    FileMan_Release(m.memberA, -1);
    cMessage_dtor(&m, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239780(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239780 */
