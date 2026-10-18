/*
 * main/GameGOBJ: range (2 files, 002156C0-00215700)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_002156C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10C]; int count; int* locks; } Lift56C0;
void Lift_SetFloorLock(Lift56C0* p, int floor, unsigned char lock) {
    if (floor >= 0 && floor < p->count) {
        p->locks[floor] = lock;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002156C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002156C0 */

/* merge_units: begin func_00215700 */
#pragma push /* merge_units */
// Lift_Ctor (cElevatorGOBJ ctor): PathObj base, 4 SoundActions, collision/voice list, name list.
// Siblings: src/main/GameGOBJ/cSoundGOBJ_ctor.c (Act init idiom), func_00211980.c (state alloc/release).
#pragma cplusplus on
#pragma exceptions off
#pragma opt_prelinearize off
#pragma opt_strength_reduction off

struct H_215700 { int v; };
struct HT_215700 { int v; HT_215700() { v = -1; } };
struct Act_215700 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_215700 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
    char pad187[9];
};
struct Vec_215700 { int f0; int count; void** data; unsigned char flag; char pad[3]; };
struct Coll_215700 { char pad[0xE4]; Act_215700* snd; };
struct State_215700 { int f0; int f4; char pad8[4]; unsigned char bC; char padD[0x13]; int f20; int f24; int f28; int f2C; };
struct Reader_215700 { int version; int a, b; char* cur; };
struct Lift_215700 {
    void* vtbl;
    char pad04[0x64];
    int f68;
    char pad6C[0x2C];
    int count;
    char pad9C[0x34];
    State_215700* prev;
    float fD4;
    int fD8;
    unsigned char bDC;
    char padDD[0xB];
    Vec_215700 colls;
    Vec_215700 names;
    Vec_215700 ints;
    Vec_215700 vD;
    State_215700* state;
    char pad12C[0x14];
    int f140;
    char pad144[0xC];
    Act_215700 snd[4];
    int f790;
};
extern "C" char D_004A4550[];
extern "C" {
extern char D_004DB040[];
extern int D_004F54A0;
extern unsigned char D_005721C8;
extern char D_004A45D0[], D_004A45E0[], D_004A45F0[], D_004A4600[], D_004A4610[];
extern char D_004A4620[], D_004A4630[];
extern int D_0048A9C0;
void PathObj_Ctor(Lift_215700* self, int a, Reader_215700* r);
void func_00215F30(void* v);
void func_00146020(void* v);
void func_001C10A0(void* v);
void func_00173910(void* v);
void Resource_Construct(void* m);
void func_00211980(Lift_215700* self);
int func_00211DA0(void);
void func_002EC2A8(int a);
void* Mem_Alloc(int heap, int size, char* file, int line);
void SoundAction_CtorVoice(void* act, int kind, char* name, void* owner, int b);
void PtrVector_Resize(void* v, int n, const void* fill);
Coll_215700* IdMgr_FindCollision(int a, int b);
}
static inline int Read_215700(Reader_215700* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void* New_215700(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004A4550, line);
}

static inline void ActInit_215700(Act_215700* p)
{
    p->h24.v = -2;
    p->w20 = 0;
    Resource_Construct(p->memberA);
    Resource_Construct(p->memberB);
    p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
    p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
}
extern "C" Lift_215700* Lift_Ctor(Lift_215700* self, int a, Reader_215700* r)
{
    Coll_215700* z1;
    char* z2;
    int n, i, j;
    char buf[20];
    PathObj_Ctor(self, a, r);
    self->vtbl = D_004DB040;
    { Vec_215700* v = &self->colls; func_00215F30(v); v->flag = 1; }
    { Vec_215700* v = &self->names; func_00146020(v); v->flag = 1; }
    { Vec_215700* v = &self->ints; func_001C10A0(v); v->flag = 1; }
    { Vec_215700* v = &self->vD; func_00173910(v); v->flag = 1; }
    self->state = 0;
    {
        Act_215700* p = &self->snd[0];
        self->snd[0].h24.v = -2;
        self->snd[0].w20 = 0;
        Resource_Construct(p->memberA);
        Resource_Construct(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    {
        Act_215700* p = &self->snd[1];
        self->snd[1].h24.v = -2;
        self->snd[1].w20 = 0;
        Resource_Construct(p->memberA);
        Resource_Construct(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    {
        Act_215700* p = &self->snd[2];
        self->snd[2].h24.v = -2;
        self->snd[2].w20 = 0;
        Resource_Construct(p->memberA);
        Resource_Construct(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    {
        Act_215700* p = &self->snd[3];
        self->snd[3].h24.v = -2;
        self->snd[3].w20 = 0;
        Resource_Construct(p->memberA);
        Resource_Construct(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    self->f790 = 0;
    D_004F54A0 = 0;
    self->f68 = 3;
    if (D_005721C8) {
        func_00211980(self);
    } else {
        State_215700* p;
        { AllocGuard g; p = (State_215700*)Mem_Alloc(0, 0x30, D_004A4550, 0x5EE); }
        if (p) {
            p->f0 = 0;
            p->f4 = 0;
            p->bC = 0;
            p->f20 = 0;
            p->f24 = 0;
            p->f28 = 0;
            p->f2C = 0;
        }
        self->state = p;
        {
            State_215700* s = self->state;
            if (self->prev && s) {
                s->f4 = self->prev->f4;
                s->f0 = self->prev->f0;
                {
                    State_215700* q = self->prev;
                    if (q) {
                        if (q->bC) {
                            func_002EC2A8(func_00211DA0());
                        } else {
                            AllocGuard g;
                            Mem_Free(0, q, D_004A4550, 0xB83);
                        }
                        self->prev = 0;
                    }
                }
            }
            self->prev = s;
        }
    }
    self->fD4 = self->fD4 / 2.0f;
    self->state->f20 = self->state->f0;
    self->state->f28 = 0;
    self->fD8 = 4;
    self->bDC = 1;
    SoundAction_CtorVoice(&self->snd[0], 0, D_004A45D0, self, 0);
    SoundAction_CtorVoice(&self->snd[1], 0, D_004A45E0, self, 0);
    SoundAction_CtorVoice(&self->snd[2], 0, D_004A45F0, self, 0);
    SoundAction_CtorVoice(&self->snd[3], 0, D_004A4600, self, 0);
    n = Read_215700(r);
    z1 = 0;
    PtrVector_Resize(&self->colls, n, &z1);
    for (i = 0; i < n; i++) {
        Coll_215700* c = IdMgr_FindCollision(Read_215700(r), Read_215700(r));
        Act_215700* p;
        self->colls.data[i] = c;
        p = (Act_215700*)New_215700(0x190, 0x60E);
        if (p) ActInit_215700(p);
        SoundAction_CtorVoice(p, 0, D_004A4610, c, 0);
        c->snd = p;
    }
    PtrVector_Resize(&self->ints, self->count, &D_0048A9C0);
    for (i = 0; i < self->ints.count; i++) self->ints.data[i] = 0;
    z2 = 0;
    PtrVector_Resize(&self->names, self->count, &z2);
    for (j = 0; j < self->names.count; j++) {
        sprintf(buf, D_004A4620, j + 1);
        {
            void* m;
            void** slot = &self->names.data[j];
            int len = strlen(buf) + 1;
            {
                AllocGuard g;
                m = Mem_Alloc(0, len, D_004A4550, 0x61D);
            }
            *slot = m;
        }
        sprintf((char*)self->names.data[j], D_004A4630, buf);
    }
    self->f140 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00215700 */
