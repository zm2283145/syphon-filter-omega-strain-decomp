/*
 * SFOGame/Source/GameGOBJ: 6 files, 00219050-002193B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00219050 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Elem16* std_vector_cVector_opIndex(Elem16Vec* v, int i) {
    return &v->data[i];
}

int func_00219060(Elem16Vec* v) {
    return v->count;
}
static inline void merge_flush_func_00219050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219050 */

/* merge_units: begin func_00219070 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "gobj_v07_register.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_v06_update.h"
#pragma pop

#pragma cplusplus on
typedef struct Obj_00219070 { char pad[0xC]; int id; } Obj_00219070;
typedef struct { char d[0x9C]; } Str_00219070;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00219070 s78;
    Str_00219070 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_00219070;
typedef struct LiftMsg_00219070 { void* vtable; char base[0x20]; int kind; int floor; int from; int to; char pad34[0xC]; } LiftMsg_00219070;
typedef struct Notice_00219070 { void* vtable; char base[0x20]; int kind; int arg; char pad2C[4]; } Notice_00219070;
typedef struct Node_00219070 { char pad[0x49]; unsigned char type; } Node_00219070;
struct Handler_00219070 { virtual void v0(); virtual void Receive(void* ev); };
typedef struct Path_00219070 {
    char pad0[0x64]; Handler_00219070* handler; char pad68[8]; int count; char pad74[8]; Node_00219070** nodes;
    char pad80[0xDC - 0x80]; unsigned char bDC; char padDD[3]; int fE0; void* preset;
} Path_00219070;
extern int g_TriggerMsgKey;
extern "C" {
extern char D_004F5450[];
extern char D_004DAE90[];
extern char D_004DAF10[];
extern char D_004DAE30[];
extern char g_Game[];
extern int D_0055D4D8;
extern int g_TeleportMsgClass;
extern int* cMessage_Name(void* ev);
extern void cMessage_ctor_cMessageNameR(void* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void cPlaySoundMsg_ctor_cSndFxR(Snd_00219070* e, void* preset, void* owner);
extern void cFileMan_dtor(Str_00219070* s, int flag);
extern int cGOBJ_HandleMessage(Path_00219070* self, void* ev);
}
static inline int ObjId_00219070(Obj_00219070* o) { return o ? o->id : 0; }
#pragma opt_strength_reduction off
extern "C" int cPathedGOBJ_HandleMessage(Path_00219070* self, void* ev)
{
    int t = *cMessage_Name(ev);
    if (t == g_TriggerMsgKey) {
        int i;
        Snd_00219070 s;
        LiftMsg_00219070 msg;
        Notice_00219070 n;
        {
            self->bDC = 0;
            cMessage_ctor_cMessageNameR(&n, D_004F5450);
            n.vtable = D_004DAE90;
            n.kind = 1;
            n.arg = -1;
            QueueMessage_cMessageR_cSystemP_int(&n, self, 0);
            n.vtable = D_004DAE90;
            cMessage_dtor(&n, 0);
        }
        self->fE0 = 0;
        if (self->preset) {
            cPlaySoundMsg_ctor_cSndFxR(&s, self->preset, self);
            s.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&s, g_Game, 1);
            s.vt = D_004DAE30;
            cFileMan_dtor(&s.s114, -1);
            cFileMan_dtor(&s.s78, -1);
            cMessage_dtor(&s, 0);
        }
        for (i = 0; i < self->count; i++) {
            if (self->nodes[i]->type == 0xB) {
                LiftMsg_00219070* m = &msg;
                cMessage_ctor_cMessageNameR(m, &g_TriggerMsgKey);
                msg.vtable = D_004DAF10;
                msg.kind = 0;
                msg.floor = 0;
                m->to = ObjId_00219070(0);
                m->from = ObjId_00219070(0);
                QueueMessage_cMessageR_cSystemP_int(&msg, self->nodes[i], 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
        }
        return 1;
    }
    t = *cMessage_Name(ev);
    if (t == D_0055D4D8 || (t = *cMessage_Name(ev), t == g_TeleportMsgClass)) {
        Handler_00219070* h = self->handler;
        if (h)
            h->Receive(ev);
        return cGOBJ_HandleMessage(self, ev);
    }
    return cGOBJ_HandleMessage(self, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00219070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00219070 */

/* merge_units: begin func_002192F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 7: notify attached object, update, register. */
DEFINE_GOBJ_V07_REGISTER(cPathedGOBJ_NetDeactivate)
static inline void merge_flush_func_002192F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002192F0 */

/* merge_units: begin func_00219350 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 6: notify attached object, update, call slot 47. */
DEFINE_GOBJ_V06_UPDATE(cPathedGOBJ_NetActivate)
static inline void merge_flush_func_00219350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219350 */

/* merge_units: begin func_002193B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Path: only the slots used here are named (vtable offset in comments). */
struct Path {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Method60(); /* +0x60 */
};

typedef struct cPathedGOBJ { char pad[0x64]; Path* path; /* +0x64 */ } cPathedGOBJ;

extern char g_TargetVisMgr[];
extern "C" void cGOBJ_Deactivate(cPathedGOBJ* self, void* arg);
#if 0 /* merge_units */
extern "C" void cTargetManager_RemoveGobj(void* list, cPathedGOBJ* obj);
#endif /* merge_units */
#define cTargetManager_RemoveGobj(a0, a1) (cTargetManager_RemoveGobj((a0), (GobjV07 *)(a1))) /* merge_units */


/* Notifies the path (virtual +0x60), runs the base handler, then cTargetManager_RemoveGobj(g_TargetVisMgr, self). */
extern "C" void cPathedGOBJ_Deactivate(cPathedGOBJ* self, void* arg)
{
    if (self->path)
        self->path->Method60();
    cGOBJ_Deactivate(self, arg);
    cTargetManager_RemoveGobj(g_TargetVisMgr, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002193B0(void) {}
#undef cTargetManager_RemoveGobj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002193B0 */

/* merge_units: begin func_00219410 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Door {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(); /* +0x5C */
};

struct cPathedGOBJ_00219410 {
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

extern "C" void cGOBJ_Activate(cPathedGOBJ_00219410* self, void* arg);

/* Notifies the door object (+0x64, virtual +0x5C), runs cGOBJ_Activate and virtual +0xC4. */
extern "C" void cPathedGOBJ_Activate(cPathedGOBJ_00219410* self, void* arg)
{
    if (self->door)
    self->door->Method5C();
    cGOBJ_Activate(self, arg);
    self->MethodC4();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00219410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00219410 */
