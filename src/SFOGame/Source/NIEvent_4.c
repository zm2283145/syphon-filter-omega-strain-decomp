/*
 * SFOGame/Source/NIEvent: 14 files, 00237780-00237B90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00237780 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x20]; signed char f24; char pad2[0x30 - 0x25]; } Msg_7780;
int cMessage_ctor_cMessageNameR(Msg_7780 *, char *);
int cNetObj_SendMessage_int_cMessageR_int_int(int, Msg_7780 *, int, int);
int cMessage_dtor(Msg_7780 *, int);
int cGameCamera_PushCurrent(int);
extern char D_004DC2D0;
extern char D_004F7C38;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
int Script_cNIEventOBJ_ActivateCamera(void **arg0) {
    Msg_7780 m;
    char * o = *arg0;
    if (*(int*)(o + 0x60) == 5) {
        int c = *(int*)(o + 0x140);
        if (c != 0) {
            cGameCamera_PushCurrent(c);
            if (g_IsMultiplayer != 0) {
                int v;
                if (g_IsMultiplayer != 0) v = D_005721C0; else v = 1;
                if (v != 0) {
                    cMessage_ctor_cMessageNameR(&m, &D_004F7C38);
                    m.f24 = 0;
                    m.vt = &D_004DC2D0;
                    cNetObj_SendMessage_int_cMessageR_int_int(*(int*)(o + 0xC), &m, -1, -1);
                    m.vt = &D_004DC2D0;
                    cMessage_dtor(&m, 0);
                }
            }
        }
    }
    return 0;
}
static inline void merge_flush_func_00237780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237780 */

/* merge_units: begin func_00237840 */
#pragma push /* merge_units */
#include "NIEvent_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void cNIEventBase_SetSpeed(void* obj, float speed);

/* SetSpeed(object, speed): float argument is passed through a stack slot. */
int Script_cNIEventOBJ_SetSpeed(NIEventScriptArg* args) {
    NIEventScriptArg speed[1];

    speed[0].i = args[1].i;
    cNIEventBase_SetSpeed(args[0].p, speed[0].f);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237840 */

/* merge_units: begin func_00237870 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cNIEventOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void SetEndState(); /* +0x128 */
};

/* Script native: cNIEventOBJ::SetEndState() on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_SetEndState(ScriptArg* args)
{
    cNIEventOBJ* obj = (cNIEventOBJ*)args[0].p;
    obj->SetEndState();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237870 */

/* merge_units: begin func_002378A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_002378A0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_002378A0;

/* Virtual-call view of cNIEventOBJ: only the slots used here are named (vtable offset in comments). */
struct cNIEventOBJ_002378A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int who); /* +0x68 */
};

/* Script native: cNIEventOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Disable(ScriptArg_002378A0* args)
{
    cNIEventOBJ_002378A0* obj = (cNIEventOBJ_002378A0*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002378A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002378A0 */

/* merge_units: begin func_002378D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNIEventOBJ_002378D0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int value); /* +0x64 */
};

/* Script native: cNIEventOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Enable(ScriptArg* args)
{
    cNIEventOBJ_002378D0* obj = (cNIEventOBJ_002378D0*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002378D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002378D0 */

/* merge_units: begin func_00237900 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00237900 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00237900;

/* Virtual-call view of cNIEventOBJ: only the slots used here are named (vtable offset in comments). */
struct cNIEventOBJ_00237900 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44();
    virtual void Reset(); /* +0x11C */
};

/* Script native: cNIEventOBJ::Reset() on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Reset(ScriptArg_00237900* args)
{
    cNIEventOBJ_00237900* obj = (cNIEventOBJ_00237900*)args[0].p;
    obj->Reset();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237900 */

/* merge_units: begin func_00237930 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNIEventOBJ_00237930 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43();
    virtual void Stop(int value); /* +0x118 */
};

/* Script native: cNIEventOBJ::Stop(1) on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Stop(ScriptArg* args)
{
    cNIEventOBJ_00237930* obj = (cNIEventOBJ_00237930*)args[0].p;
    obj->Stop(1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237930 */

/* merge_units: begin func_00237960 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00237960 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00237960;

/* Virtual-call view of cNIEventOBJ: only the slots used here are named (vtable offset in comments). */
struct cNIEventOBJ_00237960 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42();
    virtual void Play(); /* +0x114 */
};

/* Script native: cNIEventOBJ::Play() on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Play(ScriptArg_00237960* args)
{
    cNIEventOBJ_00237960* obj = (cNIEventOBJ_00237960*)args[0].p;
    obj->Play();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237960 */

/* merge_units: begin func_00237990 */
#pragma push /* merge_units */
extern int D_004F7CA0; /* cNIEventOBJ script type key */
extern int D_004F7CA8; /* cNIEventOBJ script type id */
extern int D_004F7D20; /* cNINotice script type key */
extern char D_00555070[]; /* global script filter */
extern int cScriptInterpreter_CallEvent(void* filter, int a1, int a2);
extern int* cGOBJ_SOBJ_getClassId(void); /* address of the cGObj type key */
extern int cScriptBase_declareMsgUse(int type, int acceptedType);
extern void cScriptBase_declareParent(int type, int parentType);

/* cNIEventOBJ derives from cGObj and accepts cNINotice messages. */
int cNIEventOBJ_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7CA8, *parent);
    return cScriptBase_declareMsgUse(D_004F7CA8, D_004F7D20);
}

void* cNIEventOBJ_SOBJ_convert(void* self) {
    return self;
}

int* cNIEventOBJ_SOBJ_getClassId(void) {
    return &D_004F7CA0;
}

int cNIEventOBJ_getSOBJClassId(void) {
    return D_004F7CA0;
}

int cNIEventOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237990 */

/* merge_units: begin func_00237A20 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cNIEventFloatTrack_Update(float, char * );                       
int cNIEventBase_SetEndState(char * );                            

void cNIEventLight_SetEndState(char * arg0) {
    F_(arg0, 0x18C, signed char) = 1;
    if (F_(arg0, 0x184, int) == -1) {
        cNIEventFloatTrack_Update(*(float *)((char *)F_(arg0, 0x17C, int) + ((F_(arg0, 0x178, int) - 1) * 0x10)) - F_(arg0, 0x188, float), arg0 + 0x170);
    }
    F_(arg0, 0x1AC, signed char) = 1;
    if (F_(arg0, 0x1A4, int) == -1) {
        cNIEventFloatTrack_Update(*(float *)((char *)F_(arg0, 0x19C, int) + ((F_(arg0, 0x198, int) - 1) * 0x10)) - F_(arg0, 0x1A8, float), arg0 + 0x190);
    }
    cNIEventBase_SetEndState(arg0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237A20 */

/* merge_units: begin func_00237AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Light00237AD0 {
public:
    int id;
    virtual void dtor(int flag);
    VPAD8(a) VPAD1(b)
    virtual void stop();
};
struct Ev00237AD0 { char pad[0x140]; Light00237AD0* light; };
extern "C" void cGOBJ_Deactivate(Ev00237AD0* self);
extern "C" void cNIEventLight_Deactivate(Ev00237AD0* self)
{
    cGOBJ_Deactivate(self);
    if (self->light) {
        self->light->stop();
        if (self->light)
            self->light->dtor(1);
        self->light = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237AD0 */

/* merge_units: begin func_00237B40 */
#pragma push /* merge_units */
extern void cGOBJ_Activate(int);

void cNIEventLight_Activate(int a0) {
    cGOBJ_Activate(a0);
}
static inline void merge_flush_func_00237B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237B40 */

/* merge_units: begin func_00237B50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nievent_v10.h"

/* Event virtual 10: call slot 66 while inactive. */
DEFINE_NIEVENT_V10(cNIEventLight_NextFrame)
static inline void merge_flush_func_00237B50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237B50 */

/* merge_units: begin func_00237B90 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNIEventLight_ProcessNextFrame (update): runs the light event's animation (time scaled
 * by its speed while playing, or once at 0 when it becomes ready), sends the
 * finished message when playback stopped, steps the inner/outer radius
 * tracks, and keeps a point light from the light manager in sync with the
 * owner while the event is active (released otherwise). Light class as in
 * cNIEventLight_Deactivate (NIEvent_237A20.c); light creation as in
 * cLightBundle_ctor (SpecFxDefs_231F00.c). */
#pragma always_inline on
#pragma inline_depth(8)
typedef struct { float x, y, z, w; } V4_7B90;
class Light_7B90 {
public:
    int id;
    virtual void dtor(int flag);
    VPAD4(a) VPAD2(b) VPAD1(c)
    virtual void Move(void* m);
    virtual void Enable();
    virtual void stop();
    char p8[0x10 - 8];
    float inner;
    float outer;
    char p18[0x1D - 0x18];
    unsigned char flags;
};
class Owner_7B90 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char p4[0x40 - 4];
    char mtx[0x10];
    unsigned char dirty;
};
typedef struct { float value; char pad[0x20 - 4]; } Track_7B90;
class Ev_7B90 {
public:
    VPAD32(a) VPAD32(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual void Play(float t);
    char p4[0x2C - 4];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
    char p2F[0x50 - 0x2F];
    Owner_7B90* owner;
    char p54[0x60 - 0x54];
    int state;
    char p64[0xDC - 0x64];
    unsigned char active;
    char pDD[0x130 - 0xDD];
    unsigned char playing;
    char p131[3];
    float speed;
    char p138[0x140 - 0x138];
    Light_7B90* light;
    float pos[3];
    unsigned char b150;
    unsigned char b151;
    char p152[0x170 - 0x152];
    Track_7B90 a;
    Track_7B90 b;
};
typedef struct { void* vt; char pad[0x20]; int x24; char pad28[0x30 - 0x28]; } Msg_7B90;
extern "C" {
extern char g_LightMgr[];
extern char D_004F7C30[];
extern char D_004DBEB0[];
extern char D_004D9200[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg_7B90* e, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((Msg_7780 *)(a0), (char *)(a1))) /* merge_units */

void QueueMessage_cMessageR_cSystemP_int(Msg_7B90* e, void* target, int a);
#if 0 /* merge_units */
void cMessage_dtor(Msg_7B90* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((Msg_7780 *)(a0), (a1))) /* merge_units */

void cGOBJ_NextFrame(Ev_7B90* self, float dt);
#if 0 /* merge_units */
void cNIEventFloatTrack_Update(float t, Track_7B90* tr);
#endif /* merge_units */
#define cNIEventFloatTrack_Update(a0, a1) ((void)cNIEventFloatTrack_Update((a0), (char *)(a1))) /* merge_units */

Light_7B90* cLightMan_AddLight(void* pool, int n);
V4_7B90* tRGBA_ctor_tRGBR_float(V4_7B90* out, float* in, float w);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(Light_7B90* l, int n, V4_7B90* pos, void* m, int k);
void LightEffect_SetInner(Light_7B90* l, float f);
void LightEffect_SetOuter(Light_7B90* l, float f);
void cNIEventLight_ProcessNextFrame(Ev_7B90* self, float dt);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Ev_7B90* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline Owner_7B90* SyncedOwner(Ev_7B90* self) { Owner_7B90* o = self->owner; if (o->dirty) o->Sync(); return o; }

extern "C" void cNIEventLight_ProcessNextFrame(Ev_7B90* self, float dt)
{
    unsigned char playing = self->playing;
    if (playing || (self->state == 3 && self->active && Ready(self))) {
        float t = dt * self->speed;
        self->Play(playing ? t : 0.0f);
        if (playing && !self->playing) {
            Msg_7B90 e;
            cMessage_ctor_cMessageNameR(&e, D_004F7C30);
            e.vt = D_004DBEB0;
            e.x24 = 0;
            QueueMessage_cMessageR_cSystemP_int(&e, self, 0);
            e.vt = D_004DBEB0;
            cMessage_dtor(&e, 0);
        }
    }
    cGOBJ_NextFrame(self, dt);
    if (self->playing) {
        cNIEventFloatTrack_Update(dt * self->speed, &self->a);
        cNIEventFloatTrack_Update(dt * self->speed, &self->b);
    }
    if (Ready(self) && self->active) {
        if (!self->light) {
            Light_7B90* l = cLightMan_AddLight(g_LightMgr, 4);
            if (l) {
                Owner_7B90* o;
                float inner, outer;
                V4_7B90 v;
                inner = self->a.value;
                outer = self->b.value;
                o = SyncedOwner(self);
                cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(l, 4, tRGBA_ctor_tRGBR_float(&v, self->pos, 0.0f), o->mtx, 3);
                *(void**)((char*)l + 4) = D_004D9200;
                LightEffect_SetInner(l, inner);
                LightEffect_SetOuter(l, outer);
            }
            self->light = l;
            if (self->light) {
                self->light->Enable();
                if (self->b151)
                    self->light->flags |= 8;
                if (self->b150)
                    self->light->flags |= 0x10;
            }
        } else {
            Owner_7B90* o = SyncedOwner(self);
            self->light->Move(o->mtx);
            self->light->inner = self->a.value;
            self->light->outer = self->b.value;
        }
    } else if (self->light) {
        self->light->stop();
        if (self->light)
            self->light->dtor(1);
        self->light = 0;
    }
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNIEventFloatTrack_Update /* merge_units */
static inline void merge_flush_func_00237B90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237B90 */
