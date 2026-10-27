/*
 * SFOGame/Source/GameGOBJ: 8 files, 00215310-002156C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00215310 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

typedef struct ElevE6Msg { void* vtbl; char pad[0x74]; char a[0x9C]; char b[0xBC]; } ElevE6Msg;

class ElevE6Child {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    virtual void Fn(void* arg);
};

typedef struct ElevE6 {
    char pad[0x64];
    ElevE6Child* child;
    char pad2[0x2E0 - 0x68];
    char key[4];
} ElevE6;

extern "C" char g_Game[];
extern "C" char D_004DADF0[];
extern "C" char g_TargetVisMgr[];
extern "C" void cStopSoundMsg_ctor_cSndFxR_cGOBJP(ElevE6Msg* msg, void* key, ElevE6* self);
extern "C" void QueueMessage_cMessageR_cSystemP_int(ElevE6Msg*, void*, int);
extern "C" void cFileMan_dtor(void*, int);
extern "C" void cMessage_dtor(ElevE6Msg*, int);
extern "C" void cGOBJ_Deactivate(ElevE6* self, void* arg);
extern "C" void cTargetManager_RemoveGobj(void* list, ElevE6* self);

/* cElevatorGOBJ vtable slot 16: broadcast, forward to the child, then base handling. */
extern "C" void cElevatorGOBJ_Deactivate(ElevE6* self, void* arg)
{
    ElevE6Msg msg;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&msg, self->key, self);
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
    msg.vtbl = D_004DADF0;
    cFileMan_dtor(msg.b, -1);
    cFileMan_dtor(msg.a, -1);
    cMessage_dtor(&msg, 0);
    if (self->child != 0) {
        self->child->Fn(arg);
    }
    cGOBJ_Deactivate(self, arg);
    cTargetManager_RemoveGobj(g_TargetVisMgr, self);
}
static inline void merge_flush_func_00215310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215310 */

/* merge_units: begin func_002153D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Door: only the slots used here are named (vtable offset in comments). */
struct Door {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(); /* +0x5C */
};

/* Virtual-call view of cElevatorGOBJ: only the slots used here are named (vtable offset in comments). */
struct cElevatorGOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E();
    virtual void MethodC4(); /* +0xC4 */
    char pad04[0x64 - 4];
    Door* door; /* +0x64 */
};

extern "C" void cGOBJ_Activate(cElevatorGOBJ* self, void* arg);

/* Lift virtual 0x15: notifies the door (if any), runs the base handler with arg, then virtual +0xC4. */
extern "C" void cElevatorGOBJ_Activate(cElevatorGOBJ* self, void* arg)
{
    if (self->door)
        self->door->Method5C();
    cGOBJ_Activate(self, arg);
    self->MethodC4();
}
static inline void merge_flush_func_002153D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002153D0 */

/* merge_units: begin func_00215430 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
class C4It215 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Fn(int a);
};
struct C4Obj215 { char pad[0x11C]; int count; C4It215** items; };
extern "C" void cElevatorGOBJ_DisableCallboxes(C4Obj215* o) {
    int i;
    for (i = 0; i < o->count; i++) {
        o->items[i]->Fn(-1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00215430 */

/* merge_units: begin func_002154B0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C5Item {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Method64(int a); /* +0x64 */
};
struct C5Lift { char pad[0x11C]; int count; C5Item** items; };
#pragma opt_strength_reduction off
extern "C" void cElevatorGOBJ_EnableCallboxes(C5Lift* p) {
    int i;
    for (i = 0; i < p->count; i++) {
        p->items[i]->Method64(-1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002154B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002154B0 */

/* merge_units: begin func_00215530 */
#pragma push /* merge_units */
/* Elevator floor message (vtable, base data, parameters). */
typedef struct FloorMsg {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int floor;
    unsigned char locked;
    char pad2[7];
} FloorMsg;

typedef struct cElevatorGOBJ_00215530 {
    char pad[0x10];
    int handle;
    char pad2[0xF8];
    int floorCount;
    int* floorLocks;
} cElevatorGOBJ_00215530;

extern unsigned char g_IsMultiplayer;
extern char D_004F54C8[];
extern char D_004DAEF0[]; /* floor message vtable */
extern void cMessage_ctor_cMessageNameR(FloorMsg* msg, void* name);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int target, FloorMsg* msg, int a, int b);
#if 0 /* merge_units */
extern void cMessage_dtor(FloorMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((ElevE6Msg *)(a0), (a1))) /* merge_units */


/* Unlocks a floor and, when g_IsMultiplayer is set and not silent, broadcasts the change. */
void cElevatorGOBJ_UnlockFloor(cElevatorGOBJ_00215530* self, int floor, int silent) {
    FloorMsg msg;
    if (floor >= 0 && floor < self->floorCount) {
        self->floorLocks[floor] = 0;
        if (g_IsMultiplayer && !silent) {
            cMessage_ctor_cMessageNameR(&msg, D_004F54C8);
            msg.floor = floor;
            msg.vtable = D_004DAEF0;
            msg.locked = 0;
            msg.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(self->handle, &msg, -1, -1);
            msg.vtable = D_004DAEF0;
            cMessage_dtor(&msg, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215530(void) {}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215530 */

/* merge_units: begin func_002155F0 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int floor;
    unsigned char locked;
    char pad2[7];
} ElevatorMsg;
typedef struct { char pad[0x10]; void* transport; char pad2[0xF8]; int floorCount; int* floorLocked; } cElevatorGOBJ_002155F0;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(ElevatorMsg* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((FloorMsg *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(void* transport, ElevatorMsg* msg, int a, int b);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) (cNetObj_SendMessage_int_cMessageR_int_int((int)(a0), (FloorMsg *)(a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(ElevatorMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((ElevE6Msg *)(a0), (a1))) /* merge_units */



/* Locks the given floor; in network games (unless silent) broadcasts the change. */
void cElevatorGOBJ_LockFloor(cElevatorGOBJ_002155F0* self, int floor, int silent)
{
    if (floor >= 0 && floor < self->floorCount) {
        self->floorLocked[floor] = 1;
        if (g_IsMultiplayer && !silent) {
            ElevatorMsg msg;
            cMessage_ctor_cMessageNameR(&msg, D_004F54C8);
            msg.floor = floor;
            msg.vtable = D_004DAEF0;
            msg.locked = 1;
            msg.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(self->transport, &msg, -1, -1);
            msg.vtable = D_004DAEF0;
            cMessage_dtor(&msg, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002155F0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002155F0 */

/* merge_units: begin func_002156C0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);
int strlen(const char *);

typedef struct { char pad[0x10C]; int count; int* locks; } Lift56C0;
void cElevatorGOBJ_SetLockState(Lift56C0* p, int floor, unsigned char lock) {
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
// cElevatorGOBJ_ctor (cElevatorGOBJ ctor): PathObj base, 4 SoundActions, collision/voice list, name list.
// Siblings: src/main/GameGOBJ/cSoundGOBJ_ctor.c (Act init idiom), cElevatorGOBJ_CreateElevatorInfo.c (state alloc/release).
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
extern char D_004A45D0[], D_004A45E0[], D_004A45F0[], D_004A4600[], D_004A4610[];
extern char D_004A4620[], D_004A4630[];
extern int D_0048A9C0;
void cPathedGOBJ_ctor(Lift_215700* self, int a, Reader_215700* r);
void std_vector_cGameGOBJPtr_ctor(void* v);
void std_vector_charPtr_ctor_void(void* v);
void std_vector_int_ctor_void(void* v);
void std_vector_cHotboxPtr_ctor(void* v);
void cFileMan_ctor_void(void* m);
void cElevatorGOBJ_CreateElevatorInfo(Lift_215700* self);
int func_00211DA0(void);
void NetFreeObject(int a);
void* cMemMan_Allocate(int heap, int size, char* file, int line);
void cSndFx_SetSndFx(void* act, int kind, char* name, void* owner, int b);
void std_vector_pod_int_resize(void* v, int n, const void* fill);
Coll_215700* nGobjManager_LookupGOBJ_int_int(int a, int b);
}
static inline int Read_215700(Reader_215700* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void* New_215700(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004A4550, line);
}

static inline void ActInit_215700(Act_215700* p)
{
    p->h24.v = -2;
    p->w20 = 0;
    cFileMan_ctor_void(p->memberA);
    cFileMan_ctor_void(p->memberB);
    p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
    p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
}
extern "C" Lift_215700* cElevatorGOBJ_ctor(Lift_215700* self, int a, Reader_215700* r)
{
    Coll_215700* z1;
    char* z2;
    int n, i, j;
    char buf[20];
    cPathedGOBJ_ctor(self, a, r);
    self->vtbl = D_004DB040;
    { Vec_215700* v = &self->colls; std_vector_cGameGOBJPtr_ctor(v); v->flag = 1; }
    { Vec_215700* v = &self->names; std_vector_charPtr_ctor_void(v); v->flag = 1; }
    { Vec_215700* v = &self->ints; std_vector_int_ctor_void(v); v->flag = 1; }
    { Vec_215700* v = &self->vD; std_vector_cHotboxPtr_ctor(v); v->flag = 1; }
    self->state = 0;
    {
        Act_215700* p = &self->snd[0];
        self->snd[0].h24.v = -2;
        self->snd[0].w20 = 0;
        cFileMan_ctor_void(p->memberA);
        cFileMan_ctor_void(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    {
        Act_215700* p = &self->snd[1];
        self->snd[1].h24.v = -2;
        self->snd[1].w20 = 0;
        cFileMan_ctor_void(p->memberA);
        cFileMan_ctor_void(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    {
        Act_215700* p = &self->snd[2];
        self->snd[2].h24.v = -2;
        self->snd[2].w20 = 0;
        cFileMan_ctor_void(p->memberA);
        cFileMan_ctor_void(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    {
        Act_215700* p = &self->snd[3];
        self->snd[3].h24.v = -2;
        self->snd[3].w20 = 0;
        cFileMan_ctor_void(p->memberA);
        cFileMan_ctor_void(p->memberB);
        p->id = -1; p->mask = -1; p->w20 = 0; p->h24 = *(H_215700*)&HT_215700();
        p->w30 = 0; p->w34 = 0; p->w38 = 0; p->h184 = -1; p->w180 = 0; p->b186 = 0;
    }
    self->f790 = 0;
    D_004F54A0 = 0;
    self->f68 = 3;
    if (g_IsMultiplayer) {
        cElevatorGOBJ_CreateElevatorInfo(self);
    } else {
        State_215700* p;
        { AllocGuard g; p = (State_215700*)cMemMan_Allocate(0, 0x30, D_004A4550, 0x5EE); }
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
                            NetFreeObject(func_00211DA0());
                        } else {
                            AllocGuard g;
                            cMemMan_Deallocate(0, q, D_004A4550, 0xB83);
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
    cSndFx_SetSndFx(&self->snd[0], 0, D_004A45D0, self, 0);
    cSndFx_SetSndFx(&self->snd[1], 0, D_004A45E0, self, 0);
    cSndFx_SetSndFx(&self->snd[2], 0, D_004A45F0, self, 0);
    cSndFx_SetSndFx(&self->snd[3], 0, D_004A4600, self, 0);
    n = Read_215700(r);
    z1 = 0;
    std_vector_pod_int_resize(&self->colls, n, &z1);
    for (i = 0; i < n; i++) {
        Coll_215700* c = nGobjManager_LookupGOBJ_int_int(Read_215700(r), Read_215700(r));
        Act_215700* p;
        self->colls.data[i] = c;
        p = (Act_215700*)New_215700(0x190, 0x60E);
        if (p) ActInit_215700(p);
        cSndFx_SetSndFx(p, 0, D_004A4610, c, 0);
        c->snd = p;
    }
    std_vector_pod_int_resize(&self->ints, self->count, &D_0048A9C0);
    for (i = 0; i < self->ints.count; i++) self->ints.data[i] = 0;
    z2 = 0;
    std_vector_pod_int_resize(&self->names, self->count, &z2);
    for (j = 0; j < self->names.count; j++) {
        sprintf(buf, D_004A4620, j + 1);
        {
            void* m;
            void** slot = &self->names.data[j];
            int len = strlen(buf) + 1;
            {
                AllocGuard g;
                m = cMemMan_Allocate(0, len, D_004A4550, 0x61D);
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
