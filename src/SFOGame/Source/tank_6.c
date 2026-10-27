/*
 * SFOGame/Source/tank: 9 files, 00283020-00283740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00283020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Sub283020 { char p[0x54]; unsigned char b54; };
struct Tank283020 { char p[0x6C]; Sub283020* sub; unsigned char b70; };
struct Msg283020 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth283020(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" int Script_cTank_ResumeAiming(Tank283020** args) {
    Tank283020* self = args[0];
    if (self->sub) self->sub->b54 = 0;
    self->b70 = 1;
    if (g_IsMultiplayer && IsAuth283020()) {
        Msg283020 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f2C = 0;
m.b24 = 2;
m.f28 = 0;
m.b20 = 4;
m.f1C = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
static inline void merge_flush_func_00283020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00283020 */

/* merge_units: begin func_002830F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "tank_types.h"

extern void* cGOBJ_SOBJ_convert(int);
extern int cTank_AimAt(cTank* tank, void* target);

int Script_cTank_AimAt(TankScriptArg* args) {
    cTank* tank = (cTank*)args[0].p;

    cTank_AimAt(tank, cGOBJ_SOBJ_convert(args[1].i));
    return 0;
}
static inline void merge_flush_func_002830F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002830F0 */

/* merge_units: begin func_00283130 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on
#include "alloc_guard.h"
struct Path00283130 { char p[0x144]; float f144; };
struct Tread00283130 { void* f0; Path00283130* f4; char p8[0x1C]; float f24; unsigned char b28; char p29[3]; };
struct Tank00283130 { char p[0x68]; Tread00283130* tread; };
union Arg00283130 { int i; float f; void* p; };
extern "C" {
void* cNIEventOBJ_SOBJ_convert(void* id);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004A93D0[];
}
extern "C" int Script_cTank_SetRightTread(Arg00283130* args) {
    void* obj;
    Path00283130* path;
    Tread00283130* t;
Tank00283130* self;
Tread00283130* old;
    path = (Path00283130*)cNIEventOBJ_SOBJ_convert(args[2].p);
    obj = cNIEventOBJ_SOBJ_convert(args[1].p);
    self = (Tank00283130*)args[0].p;
    old = self->tread;
    if (old) { AllocGuard g; cMemMan_Deallocate(0, old, D_004A93D0, 0x1F9); }
    { AllocGuard g; t = (Tread00283130*)cMemMan_Allocate(0, 0x2C, D_004A93D0, 0x1FB); }
    if (t) {
        t->f4 = path;
        t->f0 = obj;
        t->f24 = t->f4->f144;
        t->b28 = 0;
    }
    self->tread = t;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283130 */

/* merge_units: begin func_002832A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Path002832A0 { char p[0x144]; float f144; };
struct Tread002832A0 { void* f0; Path002832A0* f4; char p8[0x1C]; float f24; unsigned char b28; char p29[3]; };
struct Tank002832A0 { char p[0x64]; Tread002832A0* tread; };
union Arg002832A0 { int i; float f; void* p; };
extern "C" {
}
extern "C" int Script_cTank_SetLeftTread(Arg002832A0* args) {
    void* obj;
    Path002832A0* path;
    Tread002832A0* t;
Tank002832A0* self;
Tread002832A0* old;
    path = (Path002832A0*)cNIEventOBJ_SOBJ_convert(args[2].p);
    obj = cNIEventOBJ_SOBJ_convert(args[1].p);
    self = (Tank002832A0*)args[0].p;
    old = self->tread;
    if (old) { AllocGuard g; cMemMan_Deallocate(0, old, D_004A93D0, 0x1F1); }
    { AllocGuard g; t = (Tread002832A0*)cMemMan_Allocate(0, 0x2C, D_004A93D0, 0x1F3); }
    if (t) {
        t->f4 = path;
        t->f0 = obj;
        t->f24 = t->f4->f144;
        t->b28 = 0;
    }
    self->tread = t;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002832A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002832A0 */

/* merge_units: begin func_00283410 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tank00283410;
struct Tur00283410 { char p[0x70]; };
struct Tank00283410 { char p[0x6C]; Tur00283410* turret; };
union Arg00283410 { int i; float f; void* p; };
extern "C" {
Tur00283410* cTurret_ctor(Tur00283410* t, void* a, void* b, void* c, void* d, Tank00283410* owner);
}
extern "C" int Script_cTank_SetTurret_2(Arg00283410* args) {
    void* a;
    void* b;
    void* c;
    Tur00283410* t;
Tank00283410* self;
Tur00283410* old;
    c = cNIEventOBJ_SOBJ_convert(args[3].p);
    b = cNIEventOBJ_SOBJ_convert(args[2].p);
    a = cNIEventOBJ_SOBJ_convert(args[1].p);
    self = (Tank00283410*)args[0].p;
    old = self->turret;
    if (old) { AllocGuard g; cMemMan_Deallocate(0, old, D_004A93D0, 0x1E8); }
    { AllocGuard g; t = (Tur00283410*)cMemMan_Allocate(0, 0x70, D_004A93D0, 0x1EA); }
    if (t) t = cTurret_ctor(t, a, b, c, 0, self);
    self->turret = t;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283410 */

/* merge_units: begin func_002835A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tank002835A0;
struct Tur002835A0 { char p[0x70]; };
struct Tank002835A0 { char p[0x6C]; Tur002835A0* turret; };
union Arg002835A0 { int i; float f; void* p; };
extern "C" {
#if 0 /* merge_units */
Tur002835A0* cTurret_ctor(Tur002835A0* t, void* a, void* b, void* c, void* d, Tank002835A0* owner);
#endif /* merge_units */
#define cTurret_ctor(a0, a1, a2, a3, a4, a5) ((Tur002835A0 *)cTurret_ctor((Tur00283410 *)(a0), (a1), (a2), (a3), (a4), (Tank00283410 *)(a5))) /* merge_units */


}
extern "C" int Script_cTank_SetTurret(Arg002835A0* args) {
    void* a;
    void* b;
    void* c;
    void* d;
    Tur002835A0* t;
Tank002835A0* self;
Tur002835A0* old;
    d = cNIEventOBJ_SOBJ_convert(args[4].p);
    c = cNIEventOBJ_SOBJ_convert(args[3].p);
    b = cNIEventOBJ_SOBJ_convert(args[2].p);
    a = cNIEventOBJ_SOBJ_convert(args[1].p);
    self = (Tank002835A0*)args[0].p;
    old = self->turret;
    if (old) { AllocGuard g; cMemMan_Deallocate(0, old, D_004A93D0, 0x1E8); }
    { AllocGuard g; t = (Tur002835A0*)cMemMan_Allocate(0, 0x70, D_004A93D0, 0x1EA); }
    if (t) t = cTurret_ctor(t, a, b, c, d, self);
    self->turret = t;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002835A0(void) {}
#undef cTurret_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002835A0 */

/* merge_units: begin func_00283740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern int D_00506278;   /* cTank class type id */
extern int D_00506280;   /* cTank script type */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cTank script type under its parent type. */
void cTank_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_00506280, *parent);
}

/* Identity casts; volatile mirrors the original stack temporary. */
int cTank_ref_SOBJ_toInt(int obj) {
    volatile int tmp = obj;
    return tmp;
}

int cTank_SOBJ_toInt(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* cTank_ref_SOBJ_convert(void* self) {
    return self;
}

void* cTank_SOBJ_convert(void* self) {
    return self;
}

int* cTank_ref_SOBJ_getClassId(void) {
    return &D_00506278;
}

int* cTank_SOBJ_getClassId(void) {
    return &D_00506278;
}

int cTank_getSOBJClassId(void) {
    return D_00506278;
}

int cTank_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283740 */

/* merge_units: begin func_00283820 */
#pragma push /* merge_units */
typedef struct Obj60 {
    char pad[0xC];
    int id;
    char pad2[0x50];
    void* target;
} Obj60;

/* Small notification message built on the stack. */
typedef struct NotifyMsg {
    void* vtable;
    char pad04[0x18];
    int size;           /* 0x1C */
    unsigned char kind; /* 0x20 */
    char pad21[3];
    Obj60* sender;      /* 0x24 */
    int id;             /* 0x28 */
    int pad2C;
} NotifyMsg;

extern int g_NetCreateTankMsgKey;
extern int cNetCreateTankMsg_vtable;
#if 0 /* merge_units */
extern int D_004DCF10;
#endif /* merge_units */
#define D_004DCF10 (*(int*)&D_004DCF10) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(NotifyMsg*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(NotifyMsg*, void*, int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(NotifyMsg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* Sends a notification message (kind 4) about this object to its target. */
void cTank_NetCreate(Obj60* o) {
    NotifyMsg msg;
    int* idField;
    cMessage_ctor_cMessageNameR(&msg, &g_NetCreateTankMsgKey);
    idField = &msg.id;
    msg.vtable = &cNetCreateTankMsg_vtable;
    *idField = -1;
    msg.sender = o;
    *idField = o->id;
    msg.kind = 4;
    msg.size = 0x40;
    QueueMessage_cMessageR_cSystemP_int(&msg, o->target, 0);
    msg.vtable = &D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283820(void) {}
#undef D_004DCF10 /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00283820 */

/* merge_units: begin func_002838B0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x2C]; } Msg;

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


extern void cNetUpdateTankMsg_UnpackAndProcess(Msg* m, void* target);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* Builds a temporary message, sends it to target, then destroys it. */
void cNetUpdateTankMsg_NetReceive(void* target)
{
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_00506260);
    msg.vtable = D_004DCF50;
    cNetUpdateTankMsg_UnpackAndProcess(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002838B0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002838B0 */
