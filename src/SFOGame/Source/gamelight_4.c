/*
 * SFOGame/Source/gamelight: 7 files, 00179B00-00179C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00179B00 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct LightBase { int unk0; }; /* data before the vtable pointer (vptr at +4) */

/* Virtual-call view of Light: only the slots used here are named (vtable offset in comments). */
struct Light : LightBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void Method2C(); /* +0x2C */
};

typedef struct SceneLight {
    char pad[0x2C];
    unsigned char enabled;   /* +0x2C */
    unsigned char active;    /* +0x2D */
    unsigned char paused;    /* +0x2E */
    char pad2F[0x60 - 0x2F];
    Light* light;            /* +0x60 */
    unsigned char triggered; /* +0x64 */
} SceneLight;

static inline bool IsLive(SceneLight* o)
{
    return o->active && o->enabled && !o->paused;
}

/* One-shot: marks the light triggered and, while the object is live, calls the light's virtual +0x2C. */
extern "C" void cGameLight_TurnOn(SceneLight* self)
{
    if (self->triggered)
        return;
    self->triggered = 1;
    if (IsLive(self))
        self->light->Method2C();
}
static inline void merge_flush_func_00179B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179B00 */

/* merge_units: begin func_00179B70 */
#pragma push /* merge_units */
#pragma cplusplus on
class C6Obj_179B70 {
public:
    int m0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
};
struct C6Own_179B70 { char pad[0x60]; C6Obj_179B70* obj; };
extern "C" void cGOBJ_Deactivate(C6Own_179B70*);
extern "C" void cGameLight_Deactivate(C6Own_179B70* self) {
    cGOBJ_Deactivate(self);
    self->obj->v10();
}
static inline void merge_flush_func_00179B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179B70 */

/* merge_units: begin func_00179BB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


typedef struct cGameLight { char pad[0x60]; Light* light; /* +0x60 */ } cGameLight;

extern "C" void cGOBJ_Activate(cGameLight* self, void* arg);

/* cGOBJ_Activate then light object (+0x60) virtual slot +0x2C. */
extern "C" void cGameLight_Activate(cGameLight* self, void* arg)
{
    cGOBJ_Activate(self, arg);
    self->light->Method2C();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179BB0 */

/* merge_units: begin func_00179BF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Empty / constant virtual methods.
 */


void cGameLight_NextFrame(void) {
}

void cGameLight_Load(void) {
}

void cGameLight_Init(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179BF0 */

/* merge_units: begin func_00179C20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E4Del { int pad; virtual ~E4Del(); };
struct E4Inner { int pad; E4Del d; };
typedef struct {
    void* vt;
    char pad[0x5C];
    E4Del* m60;
} E4Light;
extern char D_004DA1D0[];
extern "C" void cGOBJ_dtor(void* p, int flag);
extern "C" void operator_delete(void* p);
extern "C" E4Light* cGameLight_dtor(E4Light* p, short flag)
{
    if (p != 0) {
        p->vt = D_004DA1D0;
        if (p->m60) {
            delete p->m60;
            p->m60 = 0;
        }
        cGOBJ_dtor(p, 0);
        if (flag > 0) {
            operator_delete(p);
        }
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179C20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179C20 */

/* merge_units: begin func_00179CC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Light_e1;
typedef void (*LightFn_e1)(Light_e1*);
class LightV_e1 { public: int pad; virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void Disable(); };
struct Light_e1 { int pad; LightFn_e1* vt; int id; };
extern LightFn_e1 D_004DA070[];
extern LightFn_e1 D_004D9240[];
extern LightFn_e1 D_004D9280[];
extern char g_LevelLightsDirty;
extern char g_LightMgr[];
extern "C" void cLightMan_RemoveLight(void*, Light_e1*);
extern "C" Light_e1* cParallelLight_dtor(Light_e1* self, short reg)
{
    if (self != 0) {
        self->vt = D_004DA070;
        if (self != 0) {
            self->vt = D_004D9240;
            self->id = -1;
            ((LightV_e1*)self)->Disable();
            g_LevelLightsDirty = 1;
            if (self != 0) {
                self->vt = D_004D9280;
            }
        }
        if (reg > 0) {
            cLightMan_RemoveLight(g_LightMgr, self);
        }
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179CC0 */

/* merge_units: begin func_00179D70 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" void cGOBJ_dtor(void* self, int flag);

class VDel { public: int a; virtual ~VDel(); };
extern "C" char D_004DA0B0[];
extern "C" char D_004DA1D0[];

typedef struct { void* vt; char pad[0x5C]; VDel* x60; } S_00179D70;
extern "C" S_00179D70* cGameDirectionalLight_dtor(S_00179D70* self, short flag)
{
    if (self) {
        self->vt = D_004DA0B0;
        if (self) {
            self->vt = D_004DA1D0;
            if (self->x60) {
                delete self->x60;
                self->x60 = 0;
            }
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179D70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179D70 */
