/*
 * main/Objective: Objective.cc (79 files, 00224F30-00229AD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "Objective_types.h"
#include "scriptUtils_types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "net_local_id.h"
#include "objective_set_label.h"
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_00224F30 */
#pragma push /* merge_units */
void* Objective_ResolveReceiver(void* self); /* gsynth: defined below */
typedef struct { char pad[0x10]; int id; char pad14[0x11]; unsigned char active; } ObjAct_e8;
void Objective_Activate(ObjAct_e8* self); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script-native bindings for the cObjective script type. Each callback receives
 * the script argument block; args[0] is the objective receiver.
 */


extern int GObj_IdentityB(int);
#if 0 /* merge_units */
extern int Objective_Activate(cObjective*);
#endif /* merge_units */
#define Objective_Activate(a0) (Objective_Activate((void *)(a0))) /* merge_units */

extern void Objective_Deactivate();
#if 0 /* merge_units */
extern cObjective* Objective_ResolveReceiver(void*);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((cObjective *)Objective_ResolveReceiver((a0))) /* merge_units */

#pragma push
#pragma cplusplus on
struct Obj228;
struct Tracked;
extern "C" void cObjective_ClearMapObject(Obj228*, int);
extern "C" void cObjective_SetMapObject(Obj228*, Tracked*, char*, int);
#pragma pop

#define cObjective_ClearMapObject(a0, a1) (cObjective_ClearMapObject((struct Obj228 *)(a0), (a1))) /* merge_units */
extern void cObjective_SetAddLabel();
extern void cObjective_SetCompleteLabel();
extern void cObjective_SetFailLabel();
extern void cObjective_SetMapLabel();
#define cObjective_SetMapObject(a0, a1, a2, a3) (cObjective_SetMapObject((struct Obj228 *)(a0), (struct Tracked *)(a1), (char *)(a2), (a3))) /* merge_units */
extern void cObjective_SetMenuLabel();
extern void cObjective_SetNameLabel();
extern void cObjective_SetPluralLabel();
extern void cObjective_SetSingleLabel();

/* ClearMapObject(bool) */
int Script_cObjective_ClearMapObject_2(ScriptArg* args) {
    cObjective* obj = Objective_ResolveReceiver(args[0].p);
    cObjective_ClearMapObject(obj, args[1].i != 0);
    return 0;
}

int Script_cObjective_ClearMapObject(ScriptArg* args) {
    cObjective_ClearMapObject(Objective_ResolveReceiver(args[0].p), 0);
    return 0;
}

/* SetMapObject(gobj, int); volatile locals mirror the original stack temporaries. */
int Script_cObjective_SetMapObject_2(ScriptArg* args) {
    volatile int arg2 = args[2].i;
    cObjective* obj = Objective_ResolveReceiver(args[0].p);
    int gobj = GObj_IdentityB(args[1].i);
    cObjective_SetMapObject(obj, gobj, arg2, 0);
    return 0;
}

int Script_cObjective_SetMapObject(ScriptArg* args) {
    cObjective* obj = Objective_ResolveReceiver(args[0].p);
    cObjective_SetMapObject(obj, GObj_IdentityB(args[1].i), 0, 0);
    return 0;
}

int Objective_ScriptDeactivate(ScriptArg* args) {
    Objective_Deactivate(Objective_ResolveReceiver(args[0].p));
    return 0;
}

int Objective_ScriptActivate(ScriptArg* args) {
    Objective_Activate(Objective_ResolveReceiver(args[0].p));
    return 0;
}

int Script_cObjective_IsActive(ScriptArg* args) {
    return Objective_ResolveReceiver(args[0].p)->active;
}

int Script_Objective_WasFailed(ScriptArg* args) {
    return Objective_ResolveReceiver(args[0].p)->state == OBJECTIVE_FAILED;
}

int Script_Objective_IsComplete(ScriptArg* args) {
    return Objective_ResolveReceiver(args[0].p)->state == OBJECTIVE_COMPLETE;
}

int Script_cObjective_SetState(ScriptArg* args) {
    unsigned char state = args[1].u8;
    Objective_ResolveReceiver(args[0].p)->state = state;
    return 0;
}

int Script_cObjective_GetState(ScriptArg* args) {
    return (unsigned char)Objective_ResolveReceiver(args[0].p)->state;
}

int Script_cObjective_SetPluralLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetPluralLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetSingleLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetSingleLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetFailLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetFailLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetCompleteLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetCompleteLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetAddLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetAddLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetMapLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetMapLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetMenuLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetMenuLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetNameLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetNameLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}
#undef Objective_Activate /* merge_units */
#undef Objective_ResolveReceiver /* merge_units */
#undef cObjective_ClearMapObject /* merge_units */
#undef cObjective_SetMapObject /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00224F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00224F30 */

/* merge_units: begin func_00225380 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" int Objective_DupString(int d0, int arg1); /* gsynth: defined below */
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */

#pragma pop

typedef struct ObjectiveP {
    char pad00[0x64];
    int pluralString; /* 0x64 */
} ObjectiveP;

#if 0 /* merge_units */
extern ObjectiveP* Objective_ResolveReceiver(void* obj);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((ObjectiveP *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(ObjectiveP* obj, int text);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script native: cObjective.SetPluralString(text). */
int Script_cObjective_SetPluralString(ScriptArg* args) {
    volatile int textSlot = args[1].i;
    int text = textSlot;
    ObjectiveP* obj = Objective_ResolveReceiver(args[0].p);
    obj->pluralString = Objective_DupString(obj, text);
    return 0;
}
#undef Objective_DupString /* merge_units */
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225380 */

/* merge_units: begin func_002253D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; int string; } Objective;
typedef union { int i; void* p; } ScriptArg_002253D0;

#if 0 /* merge_units */
extern Objective* Objective_ResolveReceiver(void* p);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(Objective* obj, int str);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script native: sets the objective's single string. */
int Script_cObjective_SetSingleString(ScriptArg_002253D0* args)
{
    int strArg[1];
    int str;
    Objective* obj;
    strArg[0] = args[1].i;
    str = *(int*)strArg;
    obj = Objective_ResolveReceiver(args[0].p);
    obj->string = Objective_DupString(obj, str);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002253D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002253D0 */

/* merge_units: begin func_00225420 */
#pragma push /* merge_units */
typedef union ScriptArg_00225420 { int i; float f; void* p; } ScriptArg_00225420;
typedef struct { char pad[0x80]; int failString; } Objective_00225420;
#if 0 /* merge_units */
extern Objective_00225420* Objective_ResolveReceiver(void* object);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective_00225420 *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(Objective_00225420* objective, int text);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script native: sets the objective's fail string from args[1]; returns 0. */
int Script_cObjective_SetFailString(ScriptArg_00225420* args)
{
    volatile int text = args[1].i;
    int value = text;
    Objective_00225420* objective = Objective_ResolveReceiver(args[0].p);
    objective->failString = Objective_DupString(objective, value);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225420 */

/* merge_units: begin func_00225470 */
#pragma push /* merge_units */
typedef union ScriptArg_00225470 {
    int i;
    float f;
    void* p;
} ScriptArg_00225470;

typedef struct Objective_00225470 {
    char pad[0x78];
    int completeString;
} Objective_00225470;

#if 0 /* merge_units */
extern Objective_00225470* Objective_ResolveReceiver(void*);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective_00225470 *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(Objective_00225470*, int);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script: cObjective.SetCompleteString(string). */
int Script_cObjective_SetCompleteString(ScriptArg_00225470* args) {
    volatile int str = args[1].i;
    int s = str;
    Objective_00225470* obj = Objective_ResolveReceiver(args[0].p);
    obj->completeString = Objective_DupString(obj, s);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225470 */

/* merge_units: begin func_002254C0 */
#pragma push /* merge_units */
typedef union ScriptArg_002254C0 { int i; float f; void* p; } ScriptArg_002254C0;
typedef struct { char pad[0x70]; int addString; } Objective_002254C0;
#if 0 /* merge_units */
extern Objective_002254C0* Objective_ResolveReceiver(void* object);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective_002254C0 *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(Objective_002254C0* objective, int text);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script native: sets the objective's "add" string from args[1]; returns 0. */
int Script_cObjective_SetAddString(ScriptArg_002254C0* args)
{
    volatile int text = args[1].i;
    int value = text;
    Objective_002254C0* objective = Objective_ResolveReceiver(args[0].p);
    objective->addString = Objective_DupString(objective, value);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002254C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002254C0 */

/* merge_units: begin func_00225510 */
#pragma push /* merge_units */
typedef struct ObjectiveMap {
    char pad[0x6C];
    int mapString;
} ObjectiveMap;

typedef struct ScriptArgs2 {
    int obj;
    int arg1;
} ScriptArgs2;

#if 0 /* merge_units */
extern ObjectiveMap* Objective_ResolveReceiver(int handle);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((ObjectiveMap *)Objective_ResolveReceiver((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(ObjectiveMap* obj, int str);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script native: cObjective.SetMapString(string). */
int Script_cObjective_SetMapString(ScriptArgs2* args) {
    volatile int arg = args->arg1;
    int str = arg;
    ObjectiveMap* obj = Objective_ResolveReceiver(args->obj);
    obj->mapString = Objective_DupString(obj, str);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225510 */

/* merge_units: begin func_00225560 */
#pragma push /* merge_units */
typedef union ScriptArg_00225560 {
    int i;
    float f;
    void* p;
} ScriptArg_00225560;

typedef struct Objective_00225560 {
    char pad[0x60];
    int menuString;
} Objective_00225560;

#if 0 /* merge_units */
extern Objective_00225560* Objective_ResolveReceiver(void*);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective_00225560 *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(Objective_00225560*, int);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */


/* Script: cObjective.SetMenuString(string). */
int Script_cObjective_SetMenuString(ScriptArg_00225560* args) {
    volatile int str = args[1].i;
    int s = str;
    Objective_00225560* obj = Objective_ResolveReceiver(args[0].p);
    obj->menuString = Objective_DupString(obj, s);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225560 */

/* merge_units: begin func_002255B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int name; } Objective002255B0;
#if 0 /* merge_units */
extern Objective002255B0* Objective_ResolveReceiver(int handle);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective002255B0 *)Objective_ResolveReceiver((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_DupString(Objective002255B0* obj, int name);
#endif /* merge_units */
#define Objective_DupString(a0, a1) (Objective_DupString((void *)(a0), (void *)(a1))) /* merge_units */

/* Script: cObjective.SetName(name). */
int Script_cObjective_SetName(int* args)
{
    volatile int name = args[1]; /* staged through the stack */
    Objective002255B0* obj;
    int n = name;
    obj = Objective_ResolveReceiver(args[0]);
    obj->name = Objective_DupString(obj, n);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_DupString /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002255B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002255B0 */

/* merge_units: begin func_00225600 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void Objective_ResolveReceiver(int handle);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((void)Objective_ResolveReceiver((void *)(a0))) /* merge_units */


/* Script native: Objective.SetMaxOwners - resolves the receiver object. */
int Objective_ScriptSetMaxOwners(int* args) {
    Objective_ResolveReceiver(args[0]);
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225600 */

/* merge_units: begin func_00225620 */
#pragma push /* merge_units */
typedef union ScriptArg_00225620 { int i; float f; void* p; } ScriptArg_00225620;
typedef struct { char pad[0x48]; int achievementId; } Objective_00225620;
#if 0 /* merge_units */
extern Objective_00225620* Objective_ResolveReceiver(void* object);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective_00225620 *)Objective_ResolveReceiver((a0))) /* merge_units */

/* Script native: sets objective args[0]'s achievement id to args[1]; returns 0. */
int Script_cObjective_SetAchievementID(ScriptArg_00225620* args)
{
    volatile int id = args[1].i;
    int value = id;
    Objective_ResolveReceiver(args[0].p)->achievementId = value;
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225620 */

/* merge_units: begin func_00225660 */
#pragma push /* merge_units */
typedef struct ObjectiveN {
    char pad00[0x54];
    unsigned char notifyType; /* 0x54 */
} ObjectiveN;

typedef struct ObjArgs {
    void* obj;
    unsigned char type;
} ObjArgs;

#if 0 /* merge_units */
extern ObjectiveN* Objective_ResolveReceiver(void* obj);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((ObjectiveN *)Objective_ResolveReceiver((a0))) /* merge_units */


/* Script native: cObjective.SetNotifyType(type). */
int Script_cObjective_SetNotifyType(ObjArgs* args) {
    unsigned char type = args->type;
    Objective_ResolveReceiver(args->obj)->notifyType = type;
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225660 */

/* merge_units: begin func_00225690 */
#pragma push /* merge_units */
typedef struct ObjectiveM {
    char pad00[0x27];
    unsigned char multiType;  /* 0x27 */
    unsigned char multiCount; /* 0x28 */
} ObjectiveM;

typedef struct MultiArgs {
    void* obj;
    unsigned char type;
    char pad5[3];
    int count;
} MultiArgs;

#if 0 /* merge_units */
extern ObjectiveM* Objective_ResolveReceiver(void* obj);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((ObjectiveM *)Objective_ResolveReceiver((a0))) /* merge_units */


/* Script native: cObjective.SetMultiType(type, count). */
int Script_cObjective_SetMultiType(MultiArgs* args) {
    volatile int countSlot;
    unsigned char type;
    int count;
    ObjectiveM* obj;

    countSlot = args->count;
    type = args->type;
    count = countSlot;
    obj = Objective_ResolveReceiver(args->obj);
    obj->multiType = type;
    obj->multiCount = count;
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225690 */

/* merge_units: begin func_002256E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x26]; unsigned char type; } Objective_002256E0;
typedef union { int i; unsigned char b; void* p; } ScriptArg_002256E0;

#if 0 /* merge_units */
extern Objective_002256E0* Objective_ResolveReceiver(void* p);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((Objective_002256E0 *)Objective_ResolveReceiver((a0))) /* merge_units */


/* Script native: sets the objective's type byte. */
int Script_cObjective_SetType(ScriptArg_002256E0* args)
{
    unsigned char type = args[1].b;
    Objective_ResolveReceiver(args[0].p)->type = type;
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002256E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002256E0 */

/* merge_units: begin func_00225710 */
#pragma push /* merge_units */
typedef struct { char pad[0x70]; int id; } cObjective_00225710;
void cObjective_Add(); /* gsynth: defined below */
#if 0 /* merge_units */
extern void* Objective_ResolveReceiver(int handle);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) (Objective_ResolveReceiver((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cObjective_Add(void* objective);
#endif /* merge_units */
#define cObjective_Add(a0) (cObjective_Add((void *)(a0))) /* merge_units */

/* Script: cObjective.Add(). */
int Script_cObjective_Add(int* args)
{
    cObjective_Add(Objective_ResolveReceiver(args[0]));
    return 0;
}
#undef Objective_ResolveReceiver /* merge_units */
#undef cObjective_Add /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225710 */

/* merge_units: begin func_00225740 */
#pragma push /* merge_units */
void* ObjMan_ResolveReceiver(void* self); /* gsynth: defined below */
typedef struct { char pad0[0xC]; int owner; } Obj_227A90;
void ObjMan_SetDisplayLabel(void* mgr, char* key, Obj_227A90* obj, int quiet); /* gsynth: defined below */
#pragma push
#pragma cplusplus on
struct ObjBase_227C60 {
    virtual void Destroy(int flags);
};
typedef struct {
    char pad0[0xB0];
    ObjBase_227C60* objs[32][32];
    ObjBase_227C60* extra[32];
    int counts[32];
    int extraCount;
} ObjMan_227C60;
extern "C" void ObjMan_DeleteAll(ObjMan_227C60* m); /* gsynth: defined below */
#pragma pop
/*
 * Matched functions (byte-identical with the retail executable).
 * cObjective script-type registration helpers and cObjectiveMan script-native
 * bindings (args[0] is the manager receiver).
 */


extern char D_004F7668[];
extern char D_004F7670[];
extern char D_00555070[];
#if 0 /* merge_units */
extern int ObjMan_DeleteAll(cObjectiveMan*);
#endif /* merge_units */
#define ObjMan_DeleteAll(a0) (ObjMan_DeleteAll((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int ObjMan_SetDisplayLabel(cObjectiveMan*, int, int, int);
#endif /* merge_units */
#define ObjMan_SetDisplayLabel(a0, a1, a2, a3) (ObjMan_SetDisplayLabel((void *)(a0), (void *)(a1), (void *)(a2), (a3))) /* merge_units */

extern int ScriptFilter_Dispatch(int, int, int);
extern int* func_002257A0(void);
#if 0 /* merge_units */
extern cObjectiveMan* ObjMan_ResolveReceiver(void*);
#endif /* merge_units */
#define ObjMan_ResolveReceiver(a0) ((cObjectiveMan *)ObjMan_ResolveReceiver((a0))) /* merge_units */

extern int* cSystem_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int, int);

/* Registers the cObjective script type with its parent type. */
void ScriptType_cObjective_Init(void) {
    int* parent = cSystem_GetScriptTypeKeyPtr();
    ScriptType_SetParent(*(int*)D_004F7670, *parent);
}

/* Script value conversion; the volatile mirrors the original stack temporary. */
int func_00225770(int value) {
    volatile int tmp = value;
    return tmp;
}

void* Objective_ResolveReceiver(void* self) {
    return self;
}

/* Address of the cObjective script-type key. */
int* func_002257A0(void) {
    return (int*)D_004F7668;
}

int cObjective_v0B(void) {
    return *func_002257A0();
}

int Objective_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int Script_cObjectiveMan_DestroyObjectives(ScriptArg* args) {
    ObjMan_DeleteAll(ObjMan_ResolveReceiver(args[0].p));
    return 0;
}

/* SetDisplayLabel(label, gobj) */
int ObjMan_ScriptSetDisplayLabelObj(ScriptArg* args) {
    volatile int tmp = args[1].i;
    int label = tmp;
    ObjMan_SetDisplayLabel(ObjMan_ResolveReceiver(args[0].p), label, GObj_IdentityB(args[2].i), 0);
    return 0;
}

/* SetDisplayLabel(label) */
int ObjMan_ScriptSetDisplayLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    ObjMan_SetDisplayLabel(ObjMan_ResolveReceiver(args[0].p), label, 0, 0);
    return 0;
}
#undef ObjMan_DeleteAll /* merge_units */
#undef ObjMan_SetDisplayLabel /* merge_units */
#undef ObjMan_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225740 */

/* merge_units: begin func_002258C0 */
#pragma push /* merge_units */
void ObjMan_Notify(cObjectiveMan* mgr, char* text); /* gsynth: defined below */
#if 0 /* merge_units */
extern void* ObjMan_ResolveReceiver(void* obj);
#endif /* merge_units */
#define ObjMan_ResolveReceiver(a0) (ObjMan_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern void ObjMan_Notify(void* man, int text);
#endif /* merge_units */
#define ObjMan_Notify(a0, a1) (ObjMan_Notify((void *)(a0), (void *)(a1))) /* merge_units */


/* Script native: cObjectiveMan.SetDisplayString(man, text). */
int Script_cObjectiveMan_SetDisplayString(ScriptArg* args) {
    int part[1]; /* staged through the stack */
    part[0] = args[1].i;
    ObjMan_Notify(ObjMan_ResolveReceiver(args[0].p), *(int*)part);
    return 0;
}
#undef ObjMan_ResolveReceiver /* merge_units */
#undef ObjMan_Notify /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002258C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002258C0 */

/* merge_units: begin func_00225900 */
#pragma push /* merge_units */
void cObjectiveMan_SetPartialSuccess(int d0, int arg1, int arg2); /* gsynth: defined below */
void cObjectiveMan_SucceedPart(void* self, void* obj); /* gsynth: defined below */
typedef struct { char p[0x4C]; int kind; } Act225FA0;
void Objective_Succeed(void* self, void* obj, Act225FA0* actor); /* gsynth: defined below */
typedef struct { char pad[0x4C]; int type; } E7FActor;
void Objective_Fail(void* self, void* obj, E7FActor* actor); /* gsynth: defined below */
typedef struct {
    char p0[0xA4];
    int cur;
    char pA8[0xB0 - 0xA8];
    void* lists[32][32];
    void* extra[32];
    int counts[32];
} C1Man_2273;
void ObjMan_StartStage(C1Man_2273* m, int stage, int quiet); /* gsynth: defined below */
typedef struct { char p[0x20]; int id; } C1Obj_2275;
typedef struct {
    char p0[0xB0];
    C1Obj_2275* lists[32][32];
    C1Obj_2275* extra[32];
    int counts[32];
    int nExtra;
} C1Man_2275;
C1Obj_2275* ObjMan_GetObjective(C1Man_2275* m, int id); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * cObjectiveMan script-native bindings: stage control, success/failure and
 * objective lookup. args[0] is the manager receiver.
 */


#if 0 /* merge_units */
extern cObjective* ObjMan_GetObjective(cObjectiveMan*, int);
#endif /* merge_units */
#define ObjMan_GetObjective(a0, a1) ((cObjective *)ObjMan_GetObjective((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int ObjMan_StartStage(cObjectiveMan*, int, int);
#endif /* merge_units */
#define ObjMan_StartStage(a0, a1, a2) (ObjMan_StartStage((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_Fail(cObjectiveMan*, cObjective*, int);
#endif /* merge_units */
#define Objective_Fail(a0, a1, a2) (Objective_Fail((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern cObjective* Objective_ResolveReceiver(void*);
#endif /* merge_units */
#define Objective_ResolveReceiver(a0) ((cObjective *)Objective_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_Succeed(cObjectiveMan*, cObjective*, int);
#endif /* merge_units */
#define Objective_Succeed(a0, a1, a2) (Objective_Succeed((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjectiveMan_SetPartialSuccess(cObjectiveMan*, cObjective*, int);
#endif /* merge_units */
#define cObjectiveMan_SetPartialSuccess(a0, a1, a2) (cObjectiveMan_SetPartialSuccess((int)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjectiveMan_SucceedPart(cObjectiveMan*, cObjective*);
#endif /* merge_units */
#define cObjectiveMan_SucceedPart(a0, a1) (cObjectiveMan_SucceedPart((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_00225770(cObjective*);
#endif /* merge_units */
#define func_00225770(a0) (func_00225770((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern cObjectiveMan* ObjMan_ResolveReceiver(void*);
#endif /* merge_units */
#define ObjMan_ResolveReceiver(a0) ((cObjectiveMan *)ObjMan_ResolveReceiver((a0))) /* merge_units */


int Script_cObjectiveMan_GetStage(ScriptArg* args) {
    volatile int stage = ObjMan_ResolveReceiver(args[0].p)->stage;
    return stage;
}

int ObjMan_ScriptStartStage(ScriptArg* args) {
    volatile int stage = args[1].i;
    ObjMan_StartStage(ObjMan_ResolveReceiver(args[0].p), stage, 0);
    return 0;
}

/* Fail(objective, gobj) */
int Script_cObjectiveMan_Fail(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Fail(mgr, Objective_ResolveReceiver(args[1].p), GObj_IdentityB(args[2].i));
    return 0;
}

/* Fail(objective) */
int Script_Objective_Fail(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Fail(mgr, Objective_ResolveReceiver(args[1].p), 0);
    return 0;
}

int Script_cObjectiveMan_SetPartialSuccess(ScriptArg* args) {
    volatile int value = args[2].i;
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    cObjective* obj = Objective_ResolveReceiver(args[1].p);
    cObjectiveMan_SetPartialSuccess(mgr, obj, value);
    return 0;
}

int Script_cObjectiveMan_SucceedPart(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    cObjectiveMan_SucceedPart(mgr, Objective_ResolveReceiver(args[1].p));
    return 0;
}

/* Succeed(objective, gobj) */
int Script_cObjectiveMan_Succeed(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Succeed(mgr, Objective_ResolveReceiver(args[1].p), GObj_IdentityB(args[2].i));
    return 0;
}

/* Succeed(objective) */
int Script_Objective_Succeed(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Succeed(mgr, Objective_ResolveReceiver(args[1].p), 0);
    return 0;
}

/* GetObjective(id): null when no objective has that ID. */
int Script_GetObjective(ScriptArg* args) {
    volatile int id = args[1].i;
    return func_00225770(ObjMan_GetObjective(ObjMan_ResolveReceiver(args[0].p), id));
}
#undef ObjMan_GetObjective /* merge_units */
#undef ObjMan_StartStage /* merge_units */
#undef Objective_Fail /* merge_units */
#undef Objective_ResolveReceiver /* merge_units */
#undef Objective_Succeed /* merge_units */
#undef cObjectiveMan_SetPartialSuccess /* merge_units */
#undef cObjectiveMan_SucceedPart /* merge_units */
#undef func_00225770 /* merge_units */
#undef ObjMan_ResolveReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225900 */

/* merge_units: begin func_00225BB0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" int ObjMan_AddObjective(cObjectiveMan* m, int stage); /* gsynth: defined below */
#pragma pop

typedef union ScriptArg_00225BB0 { int i; float f; void* p; } ScriptArg_00225BB0;
#if 0 /* merge_units */
extern void* ObjMan_ResolveReceiver(void* manager);
#endif /* merge_units */
#define ObjMan_ResolveReceiver(a0) (ObjMan_ResolveReceiver((a0))) /* merge_units */

#if 0 /* merge_units */
extern int ObjMan_AddObjective(void* objectives, int objective);
#endif /* merge_units */
#define ObjMan_AddObjective(a0, a1) (ObjMan_AddObjective((void *)(a0), (a1))) /* merge_units */


/* Script native: adds objective args[1] to the objective list of manager args[0]; returns the result. */
int ObjMan_ScriptAddObjective(ScriptArg_00225BB0* args)
{
    int part[1];
    volatile int result;
    part[0] = args[1].i;
    result = ObjMan_AddObjective(ObjMan_ResolveReceiver(args[0].p), *(int*)part);
    return result;
}
#undef ObjMan_ResolveReceiver /* merge_units */
#undef ObjMan_AddObjective /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225BB0 */

/* merge_units: begin func_00225BF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cObjectiveMan script-type registration and the manager service lookup.
 */


extern char D_004F7578[];
extern char D_004F75E8[];
extern char D_004F75F0[];
extern char g_Game[];
extern cObjectiveMan* Service_Lookup(int, int);
extern cObjectiveMan* func_00225C20(cObjectiveMan*);
extern int* func_00225C50(void);
extern cObjectiveMan* ObjMan_GetService();

/* Registers the cObjectiveMan script type with its parent type. */
void ScriptType_cObjectiveMan_Init(void) {
    int* parent = cSystem_GetScriptTypeKeyPtr();
    ScriptType_SetParent(*(int*)D_004F75F0, *parent);
}

/* Script value conversion; the volatile mirrors the original stack temporary. */
cObjectiveMan* func_00225C20(cObjectiveMan* value) {
    cObjectiveMan* volatile tmp = value;
    return tmp;
}

/* Receiver resolve for cObjectiveMan natives (identity). */
void* ObjMan_ResolveReceiver(void* self) {
    return self;
}

/* Address of the cObjectiveMan script-type key. */
int* func_00225C50(void) {
    return (int*)D_004F75E8;
}

int cObjectiveMan_v0B(void) {
    return *func_00225C50();
}

int cObjectiveMan_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

cObjectiveMan* Script_GetObjectiveManager(void) {
    return func_00225C20(ObjMan_GetService());
}

/* Looks up the objective manager in the global service registry. */
cObjectiveMan* ObjMan_GetService() {
    return Service_Lookup((int)g_Game, (int)D_004F7578);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225BF0 */

/* merge_units: begin func_00225CF0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct ObjBase_227450 {
    virtual void Destroy(int flags);
    char pad04[0x28];
    int kind;
};
typedef struct {
    char pad0[0xB0];
    ObjBase_227450* objs[33][32];
    int counts[32];
    int extraCount;
} ObjMan_227450;
extern "C" void func_00227450(ObjMan_227450* m, ObjBase_227450* o, int f); /* gsynth: defined below */
#pragma pop
typedef struct { char p[0xAC]; unsigned char bAC; } Man225CF0;
typedef struct { char p[0x2C]; unsigned char kind; char p2D[3]; int stage; int id; } Ev225CF0;
extern int D_005436B0;
int* Event_GetType(void* ev);
void ObjectiveMgr_DrawOverlay(); /* gsynth: defined below */
#if 0 /* merge_units */
void ObjMan_StartStage(Man225CF0* m, int stage, int f);
#endif /* merge_units */
#define ObjMan_StartStage(a0, a1, a2) (ObjMan_StartStage((void *)(a0), (a1), (a2))) /* merge_units */

void** NetMap_Lookup(int id);
unsigned char cObjectiveMan_v01(Man225CF0* self, Ev225CF0* ev)
{
    unsigned char r = 0;
    int t = *Event_GetType(ev);
    if (t == D_005436B0) {
        if (self->bAC) ObjectiveMgr_DrawOverlay(self, 0);
        r = 1;
    } else {
        t = *Event_GetType(ev);
        if (t == *(int*)D_0051F0B0) {
        switch (ev->kind) {
        case 4:
            ObjMan_StartStage(self, ev->stage, 1);
            r = 1;
            break;
        case 5: {
            void** o = NetMap_Lookup(ev->id);
            if (o) func_00227450((ObjMan_227450*)self, (struct ObjBase_227450*)*o, 1);
            r = 1;
            break;
        }
        }
        }
    }
    return r;
}
#undef ObjMan_StartStage /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225CF0 */

/* merge_units: begin func_00225DF0 */
#pragma push /* merge_units */
typedef struct { void* vt; } ObjEv225EA0;
ObjEv225EA0* ObjectiveEvent_Dtor(ObjEv225EA0* self, short flag); /* gsynth: defined below */
typedef struct { char pad[0x28]; char total; char count; } Obj00228BE0;
void func_00228BE0(Obj00228BE0* self, int n); /* gsynth: defined below */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Event_Construct(char **, char *);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (void *)(a1))) /* merge_units */
                       
int Event_Send(char **, int, int);                           
#if 0 /* merge_units */
int cMessage_dtor(char **, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */
                           
#if 0 /* merge_units */
int func_00228BE0(int, int);
#endif /* merge_units */
#define func_00228BE0(a0, a1) (func_00228BE0((void *)(a0), (a1))) /* merge_units */
                            
extern void Message_GetScriptTypeKey();
extern void ObjectiveEvent_Clone();
extern void ObjectiveEvent_Serialize();
extern char D_004DE4F0[];
#if 0 /* merge_units */
extern char D_0051F0B0;
#endif /* merge_units */
#define D_0051F0B0 (*(char*)&D_0051F0B0) /* merge_units */

extern unsigned char g_IsMultiplayer;

void cObjectiveMan_SetPartialSuccess(int d0, int arg1, int arg2) {
    struct { char * f30[7]; int f4C; signed char f50[12]; signed char f5C[4]; int f60[8]; } sl;

    if (g_IsMultiplayer != 0) {
        Event_Construct(sl.f30, &D_0051F0B0);
        sl.f60[0] = arg2;
        sl.f30[0] = &(*(char*)D_004DE4F0);
        sl.f5C[0] = 3;
        sl.f4C = 0x40;
        sl.f50[0] = 4;
        sl.f4C = 0x40;
        Event_Send(sl.f30, arg1, 0);
        sl.f30[0] = &(*(char*)D_004DE4F0);
        cMessage_dtor(sl.f30, 0);
    }
    func_00228BE0(arg1, arg2);
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef func_00228BE0 /* merge_units */
#undef D_0051F0B0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225DF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225DF0 */

/* merge_units: begin func_00225EA0 */
#pragma push /* merge_units */
extern char D_004DE4F0[];
#if 0 /* merge_units */
extern int cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void operator_delete(void*);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

ObjEv225EA0* ObjectiveEvent_Dtor(ObjEv225EA0* self, short flag) {
    if (self) {
        self->vt = D_004DE4F0;
        cMessage_dtor(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
#undef cMessage_dtor /* merge_units */
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225EA0 */

/* merge_units: begin func_00225F00 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Obj8C30 {
    char pad[0x24]; signed char x24; char p25[2]; signed char x27; signed char max; signed char cur;
    char p2A[0x3A]; char* x64; char* x68; char p6C[4]; int x70; char p74[4]; char* name;
    void Format();
    int Remaining() { return max - cur; }
};
extern "C" void Objective_FormatStatusText(Obj8C30* self); /* gsynth: defined below */
#pragma pop
typedef struct { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[0xB]; unsigned char b2C; char p2D[3]; int f30; char p34[0x1C]; } Msg225F00;
#if 0 /* merge_units */
extern char D_0051F0B0[];
#endif /* merge_units */
#define D_0051F0B0 ((char*)&D_0051F0B0) /* merge_units */

#if 0 /* merge_units */
int Event_Construct(void* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int Event_Send(void* m, void* target, int immediate);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void Objective_FormatStatusText(void* o);
#endif /* merge_units */
#define Objective_FormatStatusText(a0) (Objective_FormatStatusText((void *)(a0))) /* merge_units */

static inline void SetF225F00(int* p, int v) { *p = v; }
#pragma push
#pragma opt_propagation off
#pragma opt_dead_assignments off
void cObjectiveMan_SucceedPart(void* self, void* obj)
{
    if (g_IsMultiplayer) {
        Msg225F00 m;
        Event_Construct(&m, D_0051F0B0);
        m.vtable = D_004DE4F0;
m.f30 = -1;
m.b2C = 2;
SetF225F00(&m.f1C, 0x40);
m.b20 = 4;
        SetF225F00(&m.f1C, 0x40);
        Event_Send(&m, obj, 0);
        m.vtable = D_004DE4F0;
        cMessage_dtor(&m, 0);
    }
    Objective_FormatStatusText(obj);
}
#pragma pop
#undef D_0051F0B0 /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef Objective_FormatStatusText /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225F00 */

/* merge_units: begin func_00225FA0 */
#pragma push /* merge_units */
int ObjectiveMgr_GetCompleted(void* a, void* b, void* c, unsigned char flag); /* gsynth: defined below */
typedef struct { char pad0[0xA4]; int cur; char pad1[0x1130-0xA8]; int counts[32]; int total; } ObjManD4;
int ObjMan_GetTotalCount(ObjManD4* m); /* gsynth: defined below */
typedef struct { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[0xB]; unsigned char b2C; char p2D[3]; int f30; char p34[0x1C]; } Msg225FA0;
#if 0 /* merge_units */
extern char D_0051F0B0[];
#endif /* merge_units */
#define D_0051F0B0 ((char*)&D_0051F0B0) /* merge_units */

#if 0 /* merge_units */
int Event_Construct(void* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int Event_Send(void* m, void* target, int immediate);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void Objective_SetCompleted(); /* gsynth: defined below */
#if 0 /* merge_units */
void* ObjMan_GetService();
#endif /* merge_units */
#define ObjMan_GetService() ((void *)ObjMan_GetService()) /* merge_units */

#if 0 /* merge_units */
int ObjMan_GetTotalCount(void* s);
#endif /* merge_units */
#define ObjMan_GetTotalCount(a0) (ObjMan_GetTotalCount((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int ObjectiveMgr_GetCompleted(void* s, int* buf, int n, int f);
#endif /* merge_units */
#define ObjectiveMgr_GetCompleted(a0, a1, a2, a3) (ObjectiveMgr_GetCompleted((a0), (void *)(a1), (void *)(a2), (unsigned char)(a3))) /* merge_units */

void Objective_QueueThresholdVoice(int id, int f);
void Actor_BuildVoiceKey(void* a, int v);
extern int g_HumanActorClassKey;

static inline void SetF225FA0(int* p, int v) { *p = v; }
#pragma push
#pragma opt_propagation off
#pragma opt_dead_assignments off
void Objective_Succeed(void* self, void* obj, Act225FA0* actor)
{
    int total;
    int half;
    int n;
    Msg225FA0 m;
    int buf[20];
    if (g_IsMultiplayer) {
        Event_Construct(&m, D_0051F0B0);
        m.vtable = D_004DE4F0;
        m.f30 = -1;
        m.b2C = 1;
        SetF225FA0(&m.f1C, 0x40);
        m.b20 = 4;
        SetF225FA0(&m.f1C, 0x40);
        Event_Send(&m, obj, 0);
        m.vtable = D_004DE4F0;
        cMessage_dtor(&m, 0);
    }
    Objective_SetCompleted(obj);
    total = ObjMan_GetTotalCount(ObjMan_GetService());
    half = total / 2;
    n = ObjectiveMgr_GetCompleted(ObjMan_GetService(), buf, 0x14, 1);
    if (n == total) Objective_QueueThresholdVoice(0x17, 1);
    else if (n >= half && n - 1 < half) Objective_QueueThresholdVoice(0x16, 1);
    if (actor && actor->kind == g_HumanActorClassKey) Actor_BuildVoiceKey(actor, 0xD);
}
#pragma pop
#undef D_0051F0B0 /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef ObjMan_GetService /* merge_units */
#undef ObjMan_GetTotalCount /* merge_units */
#undef ObjectiveMgr_GetCompleted /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00225FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00225FA0 */

/* merge_units: begin func_002260F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; unsigned char state; char pad2[0x5B]; int notify; } Objective_228DC0;
void Objective_SetFailed(Objective_228DC0* o); /* gsynth: defined below */
typedef struct {
    void* vtable;
    char base[0x18];
    int f1C;
    unsigned char b20;
    char pad21[0xB];
    unsigned char b2C;
    char pad2D[3];
    int f30;
    char pad34[0x10];
} E7FMsg;
#if 0 /* merge_units */
extern char D_0051F0B0[];
#endif /* merge_units */
#define D_0051F0B0 ((char*)&D_0051F0B0) /* merge_units */

#if 0 /* merge_units */
extern int Event_Construct(E7FMsg* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Event_Send(E7FMsg* msg, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cMessage_dtor(E7FMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Objective_SetFailed(void* obj);
#endif /* merge_units */
#define Objective_SetFailed(a0) (Objective_SetFailed((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Actor_BuildVoiceKey(E7FActor* a, int n);
#endif /* merge_units */
#define Actor_BuildVoiceKey(a0, a1) (Actor_BuildVoiceKey((void *)(a0), (a1))) /* merge_units */

void Objective_Fail(void* self, void* obj, E7FActor* actor)
{
    if (g_IsMultiplayer) {
        E7FMsg msg;
        Event_Construct(&msg, D_0051F0B0);
        msg.vtable = D_004DE4F0;
        msg.b2C = 0;
        msg.f30 = -1;
        msg.f1C = 0x40;
        msg.b20 = 4;
        Event_Send(&msg, obj, 0);
        msg.vtable = D_004DE4F0;
        cMessage_dtor(&msg, 0);
    }
    Objective_SetFailed(obj);
    if (actor && actor->type == g_HumanActorClassKey) {
        Actor_BuildVoiceKey(actor, 11);
    }
}
#undef D_0051F0B0 /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef Objective_SetFailed /* merge_units */
#undef Actor_BuildVoiceKey /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002260F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002260F0 */

/* merge_units: begin func_002261C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Objective manager teardown helper: if flag +0xAC is set, notifies the global
 * UI receiver and clears the flag.
 */


extern char g_Hud[]; /* global UI receiver */
extern void Hud_ClosePauseMenu(int);

void func_002261C0(cObjectiveMan* mgr) {
    if (mgr->unkAC != 0) {
        Hud_ClosePauseMenu(*(int*)g_Hud);
        mgr->unkAC = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002261C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002261C0 */

/* merge_units: begin func_00226200 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x24];
    signed char state;
    unsigned char active;
    signed char kind;
    char pad27[0x39];
    char* name;
} ObjEnt;

typedef struct {
    char pad0[0x280];
    int fonts[1];
} FontMgr;

typedef struct {
    char pad0[0xB0];
    ObjEnt* lists[1];
} ObjMgrHdr;

typedef struct {
    char pad0[0xA4];
    int cur;
    char pad_a8[0x10B0 - 0xA8];
    ObjEnt* ents[0x20];
    int counts[0x20];
    int n;
} ObjMgr;

extern signed char D_004F7560;
extern signed char D_0048AB20;
extern char D_004A5D08[];
extern char D_004A5D30[];
extern char D_004F7580[];
extern char D_004F75A0[];
extern FontMgr* App_GetInstance(void);
extern int Font_GetLineHeight(int font);
extern void* TextManager_Get(void);
extern void TextManager_QueueText(void* ctx, char* text, int font, char* color, int x, int y);

static inline int GetFont(signed char i)
{
    return *(int*)((char*)App_GetInstance()->fonts + ((unsigned char)i << 2));
}
extern void ObjectiveMgr_DrawMissionSection(ObjMgr* self, int* x, int* y, int* count, char* color);
extern void ObjectiveMgr_DrawCompletedSection();
extern void ObjectiveMgr_DrawFailedSection();
extern void ObjectiveMgr_DrawParametersSection(ObjMgr* self, int* x, int* y, int* count, char* color);

void ObjectiveMgr_DrawOverlay(ObjMgr* self, char* color)
{
    int y = 0x8C;
    int x = -0x69;
    int count = 0;
    int step;
    int font;

    font = GetFont(D_0048AB20);
    step = Font_GetLineHeight(font) + 2;
    ObjectiveMgr_DrawMissionSection(self, &x, &y, &count, color);
    y -= step;
    ObjectiveMgr_DrawCompletedSection(self, &x, &y, &count, color);
    y -= step;
    ObjectiveMgr_DrawFailedSection(self, &x, &y, &count, color);
    y -= step;
    ObjectiveMgr_DrawParametersSection(self, &x, &y, &count, color);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00226200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00226200 */

/* merge_units: begin func_002262F0 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x24];
    signed char state;
    unsigned char active;
    char pad26[0x3A];
    char* name;
} ObjEnt_002262F0;

typedef struct {
    char pad0[0xB0];
    ObjEnt_002262F0* lists[1];
} ObjMgrHdr_002262F0;

typedef struct {
    char pad0[0xA4];
    int cur;
    char pad_a8[0x10B0 - 0xA8];
    ObjEnt_002262F0* ents[0x20];
    int counts[0x20];
    int n;
} ObjMgr_002262F0;
extern char D_004A5D10[];
extern char D_004F75B0[];

void ObjectiveMgr_DrawFailedSection(ObjMgr_002262F0* self, int* x, int* y, int* count, char* color)
{
    int titleFont;
    int font;
    int step;
    char* none;
    int i;
    char* c;

    titleFont = GetFont(D_004F7560);
    font = GetFont(D_0048AB20);
    step = Font_GetLineHeight(font) + 2;
    none = D_004A5D08;
    c = color ? color : D_004F7580;
    TextManager_QueueText(TextManager_Get(), D_004A5D10, titleFont, c, *x, *y);
    *y -= step;
    *count = 0;
    for (i = 0; i < self->n; i++) {
        ObjEnt_002262F0* e = self->ents[i];
        if (e->active && e->state == 2) {
            char* name = e->name;
            c = color ? color : D_004F75B0;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    for (i = 0; i < self->counts[self->cur]; i++) {
        ObjEnt_002262F0* e = ((ObjMgrHdr_002262F0*)((char*)self + self->cur * 128))->lists[i];
        if (e->active && e->state == 2) {
            char* name = e->name;
            c = color ? color : D_004F75B0;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    if (*count == 0) {
        color = color ? color : D_004F75B0;
        TextManager_QueueText(TextManager_Get(), none, font, color, *x + 15, *y);
        *y -= step;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002262F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002262F0 */

/* merge_units: begin func_002265F0 */
#pragma push /* merge_units */
/* Draws the objective list (state 1, kind != 5) with a heading; prints the placeholder when empty. */
void ObjectiveMgr_DrawCompletedSection(ObjMgr* self, int* x, int* y, int* count, char* color)
{
    int titleFont;
    int font;
    int step;
    char* none;
    int i;
    char* c;

    titleFont = GetFont(D_004F7560);
    font = GetFont(D_0048AB20);
    step = Font_GetLineHeight(font) + 2;
    none = D_004A5D08;
    c = color ? color : D_004F7580;
    TextManager_QueueText(TextManager_Get(), D_004A5D30, titleFont, c, *x, *y);
    *y -= step;
    *count = 0;
    for (i = 0; i < self->n; i++) {
        ObjEnt* e = self->ents[i];
        if (e->active && e->state == 1 && e->kind != 5) {
            char* name = e->name;
            c = color ? color : D_004F75A0;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    for (i = 0; i < self->counts[self->cur]; i++) {
        ObjEnt* e = ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i];
        if (e->active && e->state == 1 && e->kind != 5) {
            char* name = e->name;
            c = color ? color : D_004F75A0;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    if (*count == 0) {
        color = color ? color : D_004F75A0;
        TextManager_QueueText(TextManager_Get(), none, font, color, *x + 15, *y);
        *y -= step;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002265F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002265F0 */

/* merge_units: begin func_00226910 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" {
extern char D_004A5D50[];
extern char D_004F7590[];
}

static inline bool Finished(ObjEnt* e) { return e->state == 1 || e->state == 2; }

static inline int CountKind5(ObjMgr* self)
{
    int n = 0;
    for (int i = 0; i < self->n; i++) {
        if (self->ents[i]->active && !Finished(self->ents[i]) && self->ents[i]->kind == 5)
            n++;
    }
    for (int i = 0; i < self->counts[self->cur]; i++) {
        if (((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i]->active && !Finished(((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i]) && ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i]->kind == 5)
            n++;
    }
    return n;
}
extern "C" void ObjectiveMgr_DrawParametersSection(ObjMgr* self, int* x, int* y, int* count, char* color)
{
    int titleFont;
    int font;
    int step;
    char* none;
    int i;
    char* c;

    titleFont = GetFont(D_004F7560);
    font = GetFont(D_0048AB20);
    step = Font_GetLineHeight(font) + 2;
    none = D_004A5D08;
    if (CountKind5(self) == 0)
        return;
    c = color ? color : D_004F7580;
    TextManager_QueueText(TextManager_Get(), D_004A5D50, titleFont, c, *x, *y);
    *y -= step;
    for (i = 0; i < self->n; i++) {
        ObjEnt* e = self->ents[i];
        if (e->active && !Finished(e) && e->kind == 5) {
            char* name = e->name;
            c = color ? color : D_004F7590;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    for (i = 0; i < self->counts[self->cur]; i++) {
        ObjEnt* e = ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i];
        if (e->active && !Finished(e) && e->kind == 5) {
            char* name = e->name;
            c = color ? color : D_004F7590;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    if (*count == 0) {
        color = color ? color : D_004F7590;
        TextManager_QueueText(TextManager_Get(), none, font, color, *x + 15, *y);
        *y -= step;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00226910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00226910 */

/* merge_units: begin func_00226D60 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" {
extern char D_004A5D70[];
}

extern "C" void ObjectiveMgr_DrawMissionSection(ObjMgr* self, int* x, int* y, int* count, char* color)
{
    int titleFont;
    int font;
    int step;
    char* none;
    int i;
    char* c;

    titleFont = GetFont(D_004F7560);
    font = GetFont(D_0048AB20);
    step = Font_GetLineHeight(font) + 2;
    none = D_004A5D08;
    c = color ? color : D_004F7580;
    TextManager_QueueText(TextManager_Get(), D_004A5D70, titleFont, c, *x, *y);
    *y -= step;
    for (i = 0; i < self->n; i++) {
        ObjEnt* e = self->ents[i];
        if (e->active && !Finished(e) && e->kind != 5) {
            char* name = e->name;
            c = color ? color : D_004F7590;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    for (i = 0; i < self->counts[self->cur]; i++) {
        ObjEnt* e = ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i];
        if (e->active && !Finished(e) && e->kind != 5) {
            char* name = e->name;
            c = color ? color : D_004F7590;
            TextManager_QueueText(TextManager_Get(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    if (*count == 0) {
        color = color ? color : D_004F7590;
        TextManager_QueueText(TextManager_Get(), none, font, color, *x + 15, *y);
        *y -= step;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00226D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00226D60 */

/* merge_units: begin func_002270A0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct {
    char pad0[0x24];
    signed char state;
    unsigned char flag25;
    signed char kind;
} Obj_227170;
typedef struct {
    char p0[0xA4];
    int cur;
    char pA8[0xB0 - 0xA8];
    Obj_227170* lists[32][32];
    Obj_227170* extra[32];
    int counts[32];
    int total;
} Man_227170;
extern "C" int ObjMan_GatherObjectives(Man_227170* m, Obj_227170** out, int max, int f25, int fActive, int fKind5, int fState1, int fState2); /* gsynth: defined below */
#pragma pop
/*
 * Matched functions (byte-identical with the retail executable).
 * Wrappers around the objective enumeration ObjMan_GatherObjectives(mgr, out, max, ...),
 * which collects up to max matching objectives (globals first, then the
 * current stage). The trailing five arguments are filters; -1 disables one.
 */


#if 0 /* merge_units */
extern int ObjMan_GatherObjectives(cObjectiveMan*, cObjective**, int, int, int, int, int, int);
#endif /* merge_units */
#define ObjMan_GatherObjectives(a0, a1, a2, a3, a4, a5, a6, a7) (ObjMan_GatherObjectives((void *)(a0), (void *)(a1), (a2), (a3), (a4), (a5), (a6), (a7))) /* merge_units */


int ObjectiveMgr_GetFailed(cObjectiveMan* mgr, cObjective** out, int max) {
    return ObjMan_GatherObjectives(mgr, out, max, 1, -1, -1, -1, 1);
}
#undef ObjMan_GatherObjectives /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002270A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002270A0 */

/* merge_units: begin func_002270C0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int ObjMan_GatherObjectives(void* a, void* b, void* c, int d, int e, int f, int g, int h);
#endif /* merge_units */
#define ObjMan_GatherObjectives(a0, a1, a2, a3, a4, a5, a6, a7) (ObjMan_GatherObjectives((void *)(a0), (void *)(a1), (int)(a2), (a3), (a4), (a5), (a6), (a7))) /* merge_units */


/* Wrapper: gathers objectives with a negated team mask and fixed defaults. */
int ObjectiveMgr_GetCompleted(void* a, void* b, void* c, unsigned char flag) {
    return ObjMan_GatherObjectives(a, b, c, 1, -1, -flag, 1, -1);
}
#undef ObjMan_GatherObjectives /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002270C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002270C0 */

/* merge_units: begin func_002270E0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int ObjMan_GatherObjectives(cObjectiveMan*, cObjective**, int, int, int, int, int, int);
#endif /* merge_units */
#define ObjMan_GatherObjectives(a0, a1, a2, a3, a4, a5, a6, a7) (ObjMan_GatherObjectives((void *)(a0), (void *)(a1), (a2), (a3), (a4), (a5), (a6), (a7))) /* merge_units */


int ObjectiveMgr_GetOpenParameters(cObjectiveMan* mgr, cObjective** out, int max) {
    return ObjMan_GatherObjectives(mgr, out, max, 1, 0, 1, -1, -1);
}

int ObjectiveMgr_GetOpenObjectives(cObjectiveMan* mgr, cObjective** out, int max) {
    return ObjMan_GatherObjectives(mgr, out, max, 1, 0, 0, -1, -1);
}
#undef ObjMan_GatherObjectives /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002270E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002270E0 */

/* merge_units: begin func_00227120 */
#pragma push /* merge_units */
int ObjMan_GetTotalCount(ObjManD4* m)
{
    int sum = 0;
    int i;
    for (i = 0; i < 2; i++) {
        int v;
        if (i == 0) v = m->total;
        else v = m->counts[m->cur];
        sum += v;
    }
    return sum;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227120 */

/* merge_units: begin func_00227170 */
#pragma push /* merge_units */
#pragma cplusplus on



static inline bool IsActive_227170(Obj_227170* o) { return o->state == 1 || o->state == 2; }
extern "C" int ObjMan_GatherObjectives(Man_227170* m, Obj_227170** out, int max, int f25, int fActive, int fKind5, int fState1, int fState2)
{
    int n;
    int pass;
    if (!out) return 0;
    n = 0;
    for (pass = 0; pass < 2; pass++) {
        int count;
        int i;
        Obj_227170** list;
        if (pass == 0) list = m->extra;
        else list = m->lists[m->cur];
        if (pass == 0) count = m->total;
        else count = m->counts[m->cur];
        for (i = 0; i < count && n < max; list++, i++) {
            if (f25 != -1 && (f25 == 1) != (*list)->flag25) continue;
            if (fActive != -1 && (fActive == 1) != IsActive_227170(*list)) continue;
            if (fKind5 != -1 && (fKind5 == 1) != ((*list)->kind == 5)) continue;
            if (fState1 != -1 && (fState1 == 1) != ((*list)->state == 1)) continue;
            if (fState2 != -1 && (fState2 == 1) != ((*list)->state == 2)) continue;
            n++;
            *out++ = *list;
        }
    }
    return n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227170 */

/* merge_units: begin func_00227330 */
#pragma push /* merge_units */
typedef struct {
    void* vtbl;
    char pad04[0x18];
    int size;
    unsigned char len;
    char pad21[0xB];
    unsigned char type;
    char pad2D[3];
    int id;
    char pad34[0x1C];
} C1Msg_2273;
#if 0 /* merge_units */
extern char D_0051F0B0[];
#endif /* merge_units */
#define D_0051F0B0 ((char*)&D_0051F0B0) /* merge_units */

#if 0 /* merge_units */
extern int Event_Construct(C1Msg_2273* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Event_Send(C1Msg_2273* m, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cMessage_dtor(C1Msg_2273* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void Objective_Deactivate(); /* gsynth: defined below */
void ObjMan_StartStage(C1Man_2273* m, int stage, int quiet)
{
    int i;
    if (g_IsMultiplayer && !quiet) {
        C1Msg_2273 msg;
        Event_Construct(&msg, D_0051F0B0);
        msg.vtbl = D_004DE4F0;
        msg.id = -1;
        msg.type = 4;
        msg.size = 0x40;
        msg.len = 4;
        Event_Send(&msg, m, 0);
        msg.vtbl = D_004DE4F0;
        cMessage_dtor(&msg, 0);
    }
    if (stage != m->cur) {
        for (i = 0; i < m->counts[m->cur]; i++)
            Objective_Deactivate(m->lists[m->cur][i]);
        m->cur = stage;
    }
}
#undef D_0051F0B0 /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227330 */

/* merge_units: begin func_00227450 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004A5D88[];
}





static inline void DelObj(ObjBase_227450* o, int line)
{
    AllocGuard g;
    o->Destroy(-1);
    Mem_Free(0, o, D_004A5D88, line);
}

extern "C" void func_00227450(ObjMan_227450* m, ObjBase_227450* o, int f)
{
    int k = o->kind;
    int i;
    for (i = 0; i < m->counts[k]; i++) {
        if (m->objs[k][i] == o) {
            m->counts[k]--;
            for (; i < m->counts[k]; i++) {
                m->objs[k][i] = m->objs[k][i + 1];
            }
            break;
        }
    }
    if (o) {
        DelObj(o, 0x3A8);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227450 */

/* merge_units: begin func_002275A0 */
#pragma push /* merge_units */
C1Obj_2275* ObjMan_GetObjective(C1Man_2275* m, int id)
{
    int i;
    int j;
    int k;
    for (k = 0; k < m->nExtra; k++) {
        if (id == m->extra[k]->id)
            return m->extra[k];
    }
    for (i = 0; i < 32; i++) {
        for (j = 0; j < m->counts[i]; j++) {
            if (id == m->lists[i][j]->id)
                return m->lists[i][j];
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002275A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002275A0 */

/* merge_units: begin func_00227670 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Obj_229900 {
    void* vtable;
    char pad4[8];
    int id;               /* 0x0C */
    int netid;            /* 0x10 */
    unsigned char active; /* 0x14 */
    char pad15[0xF];
    unsigned char b24;
    char b25;
    unsigned char b26, b27, b28, b29;
    char pad2a[2];
    int arg;              /* 0x2C */
    int x30;
    int x34;
    int x38;
    unsigned char b3C;
    char pad3d[3];
    int x40, x44, x48, x4C, x50;
    unsigned char b54;
    char pad55[3];
    int x58;
    unsigned char b5C;
    char pad5d[3];
    int x60, x64, x68, x6C, x70, x74, x78, x7C, x80, x84, x88;
};
extern "C" Obj_229900* Objective_Ctor(Obj_229900* self, int arg); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
#if 0 /* merge_units */
cObjective* Objective_Ctor(void* self, int stage);
#endif /* merge_units */
#define Objective_Ctor(a0, a1) ((cObjective *)Objective_Ctor((Obj_229900 *)(a0), (a1))) /* merge_units */

}

extern "C" int ObjMan_AddObjective(cObjectiveMan* m, int stage)
{
    if (stage == -1) {
        if (m->globalCount < 32) {
            cObjective* o;
            {
                AllocGuard guard;
                o = (cObjective*)Mem_Alloc(0, 0x8C, D_004A5D88, 0x363);
            }
            if (o)
                o = Objective_Ctor(o, stage);
            m->globalObjectives[m->globalCount] = o;
            m->globalCount++;
            o->id = m->nextId;
            m->nextId++;
            return m->nextId - 1;
        }
    } else {
        if (m->stageCounts[stage] < 32) {
            cObjective* o;
            {
                AllocGuard guard;
                o = (cObjective*)Mem_Alloc(0, 0x8C, D_004A5D88, 0x36E);
            }
            if (o)
                o = Objective_Ctor(o, stage);
            m->stageObjectives[stage][m->stageCounts[stage]] = o;
            m->stageCounts[stage]++;
            o->id = m->nextId;
            m->nextId++;
            return m->nextId - 1;
        }
    }
    return 0;
}
#undef Objective_Ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227670 */

/* merge_units: begin func_00227880 */
#pragma push /* merge_units */
void Global_SetObjectiveFailColor(int r, int g, int b, float a); /* gsynth: defined below */
typedef union ScriptArg_00227880 {
    int i;
    float f;
    void* p;
} ScriptArg_00227880;

#if 0 /* merge_units */
extern void Global_SetObjectiveFailColor(int, int, int, float);
#endif /* merge_units */
#define Global_SetObjectiveFailColor(a0, a1, a2, a3) ((void)Global_SetObjectiveFailColor((a0), (a1), (a2), (a3))) /* merge_units */


/* Script: SetObjectiveFailColor(r, g, b, a); arguments are staged through the stack. */
int Script_SetObjectiveFailColor(ScriptArg_00227880* args) {
    int r[1];
    int g[1];
    int b[1];
    int a[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetObjectiveFailColor(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
#undef Global_SetObjectiveFailColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227880 */

/* merge_units: begin func_002278D0 */
#pragma push /* merge_units */
typedef struct { float r, g, b, a; } ColorF;
void ObjectiveColor_SetRgba(ColorF* out, int r, int g, int b, float a); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script global: sets the failed objective text colour (16-byte colour record
 * at D_004F75B0) through the shared colour setter ObjectiveColor_SetRgba.
 */


#if 0 /* merge_units */
extern float ObjectiveColor_SetRgba(int, int, int, int, float);
#endif /* merge_units */
#define ObjectiveColor_SetRgba(a0, a1, a2, a3, a4) (ObjectiveColor_SetRgba((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */


void Global_SetObjectiveFailColor(int r, int g, int b, float a) {
    ObjectiveColor_SetRgba((int)D_004F75B0, r, g, b, a);
}
#undef ObjectiveColor_SetRgba /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002278D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002278D0 */

/* merge_units: begin func_002278F0 */
#pragma push /* merge_units */
void Global_SetObjectiveSuccColor(int r, int g, int b, float a); /* gsynth: defined below */
#if 0 /* merge_units */
extern void Global_SetObjectiveSuccColor(int objective, int a, int b, float c);
#endif /* merge_units */
#define Global_SetObjectiveSuccColor(a0, a1, a2, a3) ((void)Global_SetObjectiveSuccColor((a0), (a1), (a2), (a3))) /* merge_units */

/* Script: SetObjectiveSuccColor(objective, a, b, c). */
int Script_SetObjectiveSuccColor(int* args)
{
    int o[1];
    int a[1];
    int b[1];
    float c[1];
    *(int*)c = args[3];
    b[0] = args[2];
    a[0] = args[1];
    o[0] = args[0];
    Global_SetObjectiveSuccColor(*(int*)o, *(int*)a, *(int*)b, *(float*)c);
    return 0;
}
#undef Global_SetObjectiveSuccColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002278F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002278F0 */

/* merge_units: begin func_00227940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script global: sets the completed objective text colour (16-byte colour record
 * at D_004F75A0) through the shared colour setter ObjectiveColor_SetRgba.
 */


#if 0 /* merge_units */
extern float ObjectiveColor_SetRgba(int, int, int, int, float);
#endif /* merge_units */
#define ObjectiveColor_SetRgba(a0, a1, a2, a3, a4) (ObjectiveColor_SetRgba((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */


void Global_SetObjectiveSuccColor(int r, int g, int b, float a) {
    ObjectiveColor_SetRgba((int)D_004F75A0, r, g, b, a);
}
#undef ObjectiveColor_SetRgba /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227940 */

/* merge_units: begin func_00227960 */
#pragma push /* merge_units */
void Global_SetObjectiveCurrColor(int r, int g, int b, float a); /* gsynth: defined below */
#if 0 /* merge_units */
extern void Global_SetObjectiveCurrColor(int obj, int a, int b, float c);
#endif /* merge_units */
#define Global_SetObjectiveCurrColor(a0, a1, a2, a3) ((void)Global_SetObjectiveCurrColor((a0), (a1), (a2), (a3))) /* merge_units */


/* Script native: SetObjectiveCurrColor(obj, a, b, c).
 * volatile mirrors the original stack temporaries. */
int Script_SetObjectiveCurrColor(ScriptArg* args) {
    int v0;
    int v2;
    int v1;
    volatile int slot0;
    volatile int slot1;
    volatile int slot2;
    volatile int slot3;

    slot3 = args[3].i;
    slot2 = args[2].i;
    v1 = args[1].i;
    v2 = slot2;
    slot1 = v1;
    v0 = args[0].i;
    v1 = slot1;
    slot0 = v0;
    Global_SetObjectiveCurrColor(slot0, v1, v2, *(float*)&slot3);
    return 0;
}
#undef Global_SetObjectiveCurrColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227960 */

/* merge_units: begin func_002279B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script global: sets the current objective text colour (16-byte colour record
 * at D_004F7590) through the shared colour setter ObjectiveColor_SetRgba.
 */


#if 0 /* merge_units */
extern float ObjectiveColor_SetRgba(int, int, int, int, float);
#endif /* merge_units */
#define ObjectiveColor_SetRgba(a0, a1, a2, a3, a4) (ObjectiveColor_SetRgba((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */


void Global_SetObjectiveCurrColor(int r, int g, int b, float a) {
    ObjectiveColor_SetRgba((int)D_004F7590, r, g, b, a);
}
#undef ObjectiveColor_SetRgba /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002279B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002279B0 */

/* merge_units: begin func_002279D0 */
#pragma push /* merge_units */
void Global_SetObjectiveColor(int r, int g, int b, float a); /* gsynth: defined below */
typedef union { int i; float f; } ScriptArg_002279D0;

#if 0 /* merge_units */
extern void Global_SetObjectiveColor(int objective, int a, int b, float c);
#endif /* merge_units */
#define Global_SetObjectiveColor(a0, a1, a2, a3) ((void)Global_SetObjectiveColor((a0), (a1), (a2), (a3))) /* merge_units */


/* Script native: sets an objective's color. */
int Script_SetObjectiveColor(ScriptArg_002279D0* args)
{
    int objective[1];
    int a[1];
    int b[1];
    ScriptArg_002279D0 c[1];
    c[0].i = args[3].i;
    b[0] = args[2].i;
    a[0] = args[1].i;
    objective[0] = args[0].i;
    Global_SetObjectiveColor(*(int*)objective, *(int*)a, *(int*)b, c[0].f);
    return 0;
}
#undef Global_SetObjectiveColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002279D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002279D0 */

/* merge_units: begin func_00227A20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script global: sets the default objective text colour (16-byte colour record
 * at D_004F7580) through the shared colour setter ObjectiveColor_SetRgba.
 */


#if 0 /* merge_units */
extern float ObjectiveColor_SetRgba(int, int, int, int, float);
#endif /* merge_units */
#define ObjectiveColor_SetRgba(a0, a1, a2, a3, a4) (ObjectiveColor_SetRgba((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */


void Global_SetObjectiveColor(int r, int g, int b, float a) {
    ObjectiveColor_SetRgba((int)D_004F7580, r, g, b, a);
}
#undef ObjectiveColor_SetRgba /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227A20 */

/* merge_units: begin func_00227A40 */
#pragma push /* merge_units */
/* Converts 0-255 integer RGB to floats in [0,1] and sets alpha. */
void ObjectiveColor_SetRgba(ColorF* out, int r, int g, int b, float a)
{
    out->r = r / 255.0f;
    out->g = g / 255.0f;
    out->b = b / 255.0f;
    out->a = a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227A40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227A40 */

/* merge_units: begin func_00227A90 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } Msg_227A90;
extern int D_005721A8;
extern int D_00494178;
#if 0 /* merge_units */
extern void* g_Hud;
#endif /* merge_units */
#define g_Hud (*(void **)&g_Hud) /* merge_units */

extern char D_0051F098[];
extern char D_004DE280[];
extern void* Loc_LookupText(char* key);
extern void Hud_PostNotification(void* hud, void* text);
#if 0 /* merge_units */
extern int Event_Construct(Msg_227A90* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern int Loc_FindKeyThunk(char* s);
#if 0 /* merge_units */
extern void Transport_Send(int a, Msg_227A90* m, int b, int c);
#endif /* merge_units */
#define Transport_Send(a0, a1, a2, a3) (Transport_Send((a0), (void *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int cMessage_dtor(Msg_227A90* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern int Player_GetIndex(int);
#if 0 /* merge_units */
extern void NetGame_InitLocalSlot(int*, int);
#endif /* merge_units */
#define NetGame_InitLocalSlot(a0, a1) ((void)NetGame_InitLocalSlot((a0), (a1))) /* merge_units */

#define LOCALID_(X) { int ld_a = D_005721A8; if (g_IsMultiplayer) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
static inline int KeyOf_227A90(char* s) { return s ? Loc_FindKeyThunk(s) : -1; }
static inline int LocalId_227A90() { int r; LOCALID_(r); return r; }
static inline int IsMine_227A90(Obj_227A90* o) { int owner = o->owner; return Player_GetIndex(owner) == LocalId_227A90(); }
static inline int IsMine2_227A90(Obj_227A90* o) { int owner = o->owner; int me = LocalId_227A90(); return Player_GetIndex(owner) == me; }
void ObjMan_SetDisplayLabel(void* mgr, char* key, Obj_227A90* obj, int quiet)
{
    void* text = Loc_LookupText(key);
    if (g_IsMultiplayer) {
        if (obj) {
            int owner = obj->owner;
            int me;
            int pi;
            LOCALID_(me);
            pi = Player_GetIndex(owner);
            if (pi != me) goto skip;
        }
        Hud_PostNotification(g_Hud, text);
    skip:
        if (!quiet) {
            Msg_227A90 m;
            Msg_227A90* p = &m;
            Event_Construct(p, D_0051F098);
            m.b28 = 0;
            m.w24 = 0;
            m.vt = D_004DE280;
            p->key0 = KeyOf_227A90(key);
            p->key1 = KeyOf_227A90(0);
            if (!obj) {
                m.kind = 4;
                Transport_Send(0, &m, -1, -1);
            } else {
                Transport_Send(0, &m, 0, Player_GetIndex(obj->owner));
            }
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
    } else {
        Hud_PostNotification(g_Hud, text);
    }
}
#undef g_Hud /* merge_units */
#undef Event_Construct /* merge_units */
#undef Transport_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef NetGame_InitLocalSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227A90 */

/* merge_units: begin func_00227C50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Objective notification: forwards a text to the HUD notification queue of the
 * global UI receiver (null text is ignored by the callee).
 */


#if 0 /* merge_units */
extern void Hud_PostNotification(int, char*);
#endif /* merge_units */
#define Hud_PostNotification(a0, a1) (Hud_PostNotification((void *)(a0), (void *)(a1))) /* merge_units */


void ObjMan_Notify(cObjectiveMan* mgr, char* text) {
    Hud_PostNotification(*(int*)g_Hud, text);
}
#undef Hud_PostNotification /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227C50 */

/* merge_units: begin func_00227C60 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}





static inline void DelObj_00227C60(ObjBase_227C60* o, int line)
{
    AllocGuard g;
    o->Destroy(-1);
    Mem_Free(0, o, D_004A5D88, line);
}

extern "C" void ObjMan_DeleteAll(ObjMan_227C60* m)
{
    ObjBase_227C60* p;
    int i;
    int j;
    int k;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < m->counts[i]; j++) {
            if (m->objs[i][j]) {
                DelObj_00227C60(m->objs[i][j], 0x292);
                m->objs[i][j] = 0;
            }
        }
        m->counts[i] = 0;
    }
    for (k = 0; k < m->extraCount; k++) {
        p = m->extra[k];
        if (p) {
            DelObj_00227C60(p, 0x29C);
            m->extra[k] = 0;
        }
    }
    m->extraCount = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227C60 */

/* merge_units: begin func_00227E60 */
#pragma push /* merge_units */
typedef struct { void* vtable; } ObjMan00227E60;
extern unsigned char cObjectiveMan_v01();
#if 0 /* merge_units */
extern int cObjectiveMan_v0B();
#endif /* merge_units */
#define cObjectiveMan_v0B() (cObjectiveMan_v0B()) /* merge_units */

extern int cObjectiveMan_v0C();
extern void GObj_GetID();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern char D_004DB790[];
#if 0 /* merge_units */
extern void ObjMan_DeleteAll(ObjMan00227E60* self);
#endif /* merge_units */
#define ObjMan_DeleteAll(a0) (ObjMan_DeleteAll((void *)(a0))) /* merge_units */

extern void Receiver_Destruct(ObjMan00227E60* self, int flags);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

ObjMan00227E60* cObjectiveMan_dtor(ObjMan00227E60* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DB790);
        ObjMan_DeleteAll(self);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
extern char D_004DB790[];
#undef cObjectiveMan_v0B /* merge_units */
#undef ObjMan_DeleteAll /* merge_units */
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227E60 */

/* merge_units: begin func_00227ED0 */
#pragma push /* merge_units */
#pragma inline_depth(10)
typedef struct {
    char* vt; char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0xF]; unsigned char b24; char pad25[0x7F];
    int fA4; int fA8; unsigned char bAC; char padAD[0x1130 - 0xAD]; int arr[0x20]; int f11B0;
} ObjMan_7ED0;
#if 0 /* merge_units */
extern char D_004DB790[];
#endif /* merge_units */
#define D_004DB790 ((char*)&D_004DB790) /* merge_units */

void Receiver_Construct(ObjMan_7ED0* o, void* type);
void IdMgr_Allocate(int* out, int kind);
int NetMap_BindReceiver(int id, int owner, ObjMan_7ED0* o);
ObjMan_7ED0* ObjMan_Ctor(ObjMan_7ED0* o)
{
    int i;
    Receiver_Construct(o, D_004F7578);
    o->vt = D_004DB790;
    o->fA4 = 0;
    o->fA8 = 1;
    o->f11B0 = 0;
    for (i = 0; i < 0x20; i++) o->arr[i] = 0;
    o->b24 = 0;
    o->bAC = 0;
    if (g_IsMultiplayer) {
        int id[1];
        IdMgr_Allocate(id, 0xF6);
        o->idC = id[0];
        o->id10 = o->idC;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
        if (!(g_IsMultiplayer ? D_005721C0 : 1)) o->b14 = 0;
    }
    return o;
}
#undef D_004DB790 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00227ED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00227ED0 */

/* merge_units: begin func_00228050 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct Tracked { char pad[0xC]; int serial; } Tracked;
typedef struct { Tracked* obj; int serial; } WeakRef;

extern "C" {
int ObjMarkerMgr_RemoveDefault(void*, int*);
#if 0 /* merge_units */
int Event_Construct(void*, char*);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((ObjLabelMsg *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
int Event_Send(void*, void*, int);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((char * *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((ObjLabelMsg *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char D_0051F0B0;
#endif /* merge_units */
#define D_0051F0B0 (*(char*)&D_0051F0B0) /* merge_units */

}

struct ObjMap228 {
    void Remove(int* key) { ObjMarkerMgr_RemoveDefault(this, key); }
};
struct Mgr228 { char pad[0x90]; ObjMap228 map; };
#if 0 /* merge_units */
extern "C" Mgr228* g_Hud;
#endif /* merge_units */
#define g_Hud (*(Mgr228 **)&g_Hud) /* merge_units */


struct Ev228 {
    char* vt; char p4[0x18]; int f1C; signed char f20; char p21[0xB]; signed char f2C; char p2D[3]; int f30; int f34; char name[0x10];
};

typedef struct Obj228 { char pad[0x34]; WeakRef ref; } Obj228;

static inline Tracked* Get1(WeakRef* r)
{
    unsigned char valid = 1;
    Tracked* obj = r->obj;
    bool n = !obj;
    if (!n && obj->serial != r->serial)
        valid = 0;
    return valid ? obj : 0;
}
static inline Tracked* Get2(WeakRef* r)
{
    Tracked* obj = r->obj;
    bool n = !obj;
    return (n || obj->serial == r->serial) ? obj : 0;
}
static inline const int& IdOf(Tracked* p) { if (p) return p->serial; int m = -1; return m; }

extern "C" void cObjective_ClearMapObject(Obj228* self, int quiet)
{
    if (Get1(&self->ref)) {
        Mgr228* g = g_Hud;
        g->map.Remove(&Get2(&self->ref)->serial);
    }
    self->ref.obj = 0;
    self->ref.serial = IdOf(0);
    if (!quiet && g_IsMultiplayer) {
        Ev228 ev;
        Event_Construct(&ev, &D_0051F0B0);
        ev.vt = D_004DE4F0;
        ev.f30 = -1;
        ev.f2C = 7;
        ev.f1C = 0x40;
        ev.f20 = 4;
        Event_Send(&ev, self, 0);
        ev.vt = D_004DE4F0;
        cMessage_dtor(&ev, 0);
    }
}
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef D_0051F0B0 /* merge_units */
#undef g_Hud /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228050 */

/* merge_units: begin func_00228190 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" {
Tracked* Handle_Resolve(WeakRef* self);
int HudMarkers_SetMapObject(void*, int*, void*, char*);
#if 0 /* merge_units */
int Event_Construct(void*, char*);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((ObjLabelMsg *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
int Event_Send(void*, void*, int);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((char * *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((ObjLabelMsg *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char D_0051F0B0;
#endif /* merge_units */
#define D_0051F0B0 (*(char*)&D_0051F0B0) /* merge_units */

}

struct ObjMap228_00228190 {
    void Add(int* key, void* o, char* n) { HudMarkers_SetMapObject(this, key, o, n); }
};
struct Mgr228_00228190 { char pad[0x90]; ObjMap228_00228190 map; };
#if 0 /* merge_units */
extern "C" Mgr228_00228190* g_Hud;
#endif /* merge_units */
#define g_Hud (*(Mgr228_00228190 **)&g_Hud) /* merge_units */


struct Ev228_00228190 {
    char* vt; char p4[0x18]; int f1C; signed char f20; char p21[0xB]; signed char f2C; char p2D[7]; int f34; char name[0x10];
};

static inline Tracked* Get(WeakRef* r)
{
    Tracked* obj = r->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != r->serial)
        valid = 0;
    return valid ? obj : 0;
}
static inline Tracked* Get2_00228190(WeakRef* r)
{
    Tracked* obj = r->obj;
    return ((!obj) != 0 || obj->serial == r->serial) ? obj : 0;
}



extern "C" void cObjective_SetMapObject(Obj228* self, Tracked* obj, char* name, int quiet)
{
    if (Get1(&self->ref) || !obj)
        return;
    self->ref.obj = obj;
    self->ref.serial = IdOf(obj);
    if (Get(&self->ref)) {
        Mgr228_00228190* g = g_Hud;
        g->map.Add(&Get2_00228190(&self->ref)->serial, self, name);
    }
    if (!quiet && g_IsMultiplayer && Get1(&self->ref)) {
        int id = Handle_Resolve(&self->ref)->serial;
        Ev228_00228190 ev;
        Ev228_00228190* e = &ev;
        Event_Construct(e, &D_0051F0B0);
        ev.f34 = id;
        ev.vt = D_004DE4F0;
        ev.f2C = 6;
        if (name)
            strncpy(e->name, name, 0x10);
        e->f1C = 0x40;
        ev.f20 = 4;
        Event_Send(&ev, self, 0);
        ev.vt = D_004DE4F0;
        cMessage_dtor(&ev, 0);
    }
}
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef D_0051F0B0 /* merge_units */
#undef g_Hud /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228190 */

/* merge_units: begin func_002283A0 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetPluralLabel, 0x64, 0xF)
#pragma pop /* merge_units */
/* merge_units: end func_002283A0 */

/* merge_units: begin func_00228490 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetSingleLabel, 0x68, 0xE)
#pragma pop /* merge_units */
/* merge_units: end func_00228490 */

/* merge_units: begin func_00228580 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetFailLabel, 0x80, 0xD)
#pragma pop /* merge_units */
/* merge_units: end func_00228580 */

/* merge_units: begin func_00228670 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetCompleteLabel, 0x78, 0xC)
#pragma pop /* merge_units */
/* merge_units: end func_00228670 */

/* merge_units: begin func_00228760 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetAddLabel, 0x70, 0xB)
#pragma pop /* merge_units */
/* merge_units: end func_00228760 */

/* merge_units: begin func_00228850 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetMapLabel, 0x6C, 0xA)
#pragma pop /* merge_units */
/* merge_units: end func_00228850 */

/* merge_units: begin func_00228940 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetMenuLabel, 0x60, 0x9)
#pragma pop /* merge_units */
/* merge_units: end func_00228940 */

/* merge_units: begin func_00228A30 */
#pragma push /* merge_units */
DEFINE_OBJECTIVE_SET_LABEL(cObjective_SetNameLabel, 0x4C, 0x8)
#pragma pop /* merge_units */
/* merge_units: end func_00228A30 */

/* merge_units: begin func_00228B20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on

#pragma opt_common_subs off

extern "C" {
#if 0 /* merge_units */
int Mem_Alloc(int, int, char *, int);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) ((int)Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */
                      
#if 0 /* merge_units */
extern char D_004A5D88;
#endif /* merge_units */
#define D_004A5D88 (*(char*)&D_004A5D88) /* merge_units */

extern unsigned char g_ProfileLockEnabled;
}
extern "C" int Objective_DupString(ObjLabelObjective* d0, void* arg1) {
    int temp_s0;
    int temp_s0_2;

    temp_s0_2 = strlen((const char*)arg1) + 1;
    {
        AllocGuard g;
    temp_s0 = Mem_Alloc(0, temp_s0_2, &D_004A5D88, 0x18C);
    }
    String_Copy((void*)temp_s0, arg1);
    return temp_s0;
}
#undef Mem_Alloc /* merge_units */
#undef D_004A5D88 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228B20 */

/* merge_units: begin func_00228BE0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* ObjMan_GetService();
#endif /* merge_units */
#define ObjMan_GetService() ((void *)ObjMan_GetService()) /* merge_units */

#if 0 /* merge_units */
extern void Objective_Succeed(void* man, Obj00228BE0* obj, int flag);
#endif /* merge_units */
#define Objective_Succeed(a0, a1, a2) (Objective_Succeed((a0), (void *)(a1), (void *)(a2))) /* merge_units */

void func_00228BE0(Obj00228BE0* self, int n)
{
    self->count = n;
    if (!(self->count < self->total))
        Objective_Succeed(ObjMan_GetService(), self, 0);
}
#undef ObjMan_GetService /* merge_units */
#undef Objective_Succeed /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228BE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228BE0 */

/* merge_units: begin func_00228C30 */
#pragma push /* merge_units */
#pragma cplusplus on



extern "C" {
#if 0 /* merge_units */
extern void* ObjMan_GetService();
#endif /* merge_units */
#define ObjMan_GetService() ((void *)ObjMan_GetService()) /* merge_units */

#if 0 /* merge_units */
extern void ObjMan_Notify(void* m, char* text);
#endif /* merge_units */
#define ObjMan_Notify(a0, a1) (ObjMan_Notify((cObjectiveMan *)(a0), (a1))) /* merge_units */

extern char D_004A5DA0[];
extern char D_004A5DC0[];
extern char D_004A5DE0[];
extern char D_004A5E00[];
}

extern "C" void Objective_FormatStatusText(Obj8C30* self)
{
    int c, mx;
    char buf[0x80];
    void* m = ObjMan_GetService();
    self->cur++;
    mx = self->max; c = self->cur;
    if (c >= mx) {
        self->x24 = 1;
        sprintf(buf, D_004A5DA0, self->name, c, mx);
        return;
    }
    if (self->name == 0)
        return;
    switch (self->x27) {
    case 0:
        c = mx - c;
        if (c > 1)
            sprintf(buf, D_004A5DC0, self->name, c, self->x64);
        else
            sprintf(buf, D_004A5DE0, self->name, c, self->x68);
        break;
    case 1:
        sprintf(buf, D_004A5E00, self->x70);
        break;
    }
    ObjMan_Notify(m, buf);
}
#undef ObjMan_GetService /* merge_units */
#undef ObjMan_Notify /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228C30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228C30 */

/* merge_units: begin func_00228D50 */
#pragma push /* merge_units */
typedef struct Objective_00228D50 {
    char pad[0x24];
    unsigned char completed;
    char pad2[0x78 - 0x25];
    int outcome;
} Objective_00228D50;

#if 0 /* merge_units */
extern void ObjMan_Notify(int owner, int outcome);
#endif /* merge_units */
#define ObjMan_Notify(a0, a1) (ObjMan_Notify((void *)(a0), (void *)(a1))) /* merge_units */


/* Marks the objective completed and reports its outcome to the owner. */
void Objective_SetCompleted(Objective_00228D50* obj) {
    obj->completed = 1;
    ObjMan_Notify(ObjMan_GetService(obj), obj->outcome);
}
#undef ObjMan_Notify /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228D50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228D50 */

/* merge_units: begin func_00228D90 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void ObjMan_Notify(void* list, int id);
#endif /* merge_units */
#define ObjMan_Notify(a0, a1) (ObjMan_Notify((void *)(a0), (void *)(a1))) /* merge_units */

/* Registers the objective with its owner list. */
void cObjective_Add(cObjective_00225710* o) { ObjMan_Notify(ObjMan_GetService(o), o->id); }
#undef ObjMan_Notify /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228D90 */

/* merge_units: begin func_00228DC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* ObjMan_GetService();
#endif /* merge_units */
#define ObjMan_GetService() ((void *)ObjMan_GetService()) /* merge_units */

#if 0 /* merge_units */
extern void ObjMan_Notify(void* man, int id);
#endif /* merge_units */
#define ObjMan_Notify(a0, a1) (ObjMan_Notify((void *)(a0), (void *)(a1))) /* merge_units */

#pragma opt_common_subs off
void Objective_SetFailed(Objective_228DC0* o) {
    o->state = 2;
    if (o->notify != 0) {
        ObjMan_Notify(ObjMan_GetService(), o->notify);
    }
}
#pragma opt_common_subs reset
#undef ObjMan_GetService /* merge_units */
#undef ObjMan_Notify /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228DC0 */

/* merge_units: begin func_00228E10 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; unsigned char kind; char p1[3]; int arg; int id; char name[4]; } Ev228E10;
#if 0 /* merge_units */
extern int* Event_GetType(Ev228E10*);
#endif /* merge_units */
#define Event_GetType(a0) (Event_GetType((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Objective_SetFailed(void*);
#endif /* merge_units */
#define Objective_SetFailed(a0) (Objective_SetFailed((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Objective_FormatStatusText(void*);
#endif /* merge_units */
#define Objective_FormatStatusText(a0) (Objective_FormatStatusText((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_00228BE0(void*, int);
#endif /* merge_units */
#define func_00228BE0(a0, a1) (func_00228BE0((void *)(a0), (a1))) /* merge_units */

extern void* Object_LookupById(int*);
#if 0 /* merge_units */
extern void cObjective_SetMapObject(void*, void*, char*, int);
#endif /* merge_units */
#define cObjective_SetMapObject(a0, a1, a2, a3) ((void)cObjective_SetMapObject((void *)(a0), (void *)(a1), (char *)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cObjective_ClearMapObject(void*, int);
#endif /* merge_units */
#define cObjective_ClearMapObject(a0, a1) ((void)cObjective_ClearMapObject((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetNameLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetNameLabel(a0, a1, a2) (cObjective_SetNameLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetMenuLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetMenuLabel(a0, a1, a2) (cObjective_SetMenuLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetMapLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetMapLabel(a0, a1, a2) (cObjective_SetMapLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetAddLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetAddLabel(a0, a1, a2) (cObjective_SetAddLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetCompleteLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetCompleteLabel(a0, a1, a2) (cObjective_SetCompleteLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetFailLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetFailLabel(a0, a1, a2) (cObjective_SetFailLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetSingleLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetSingleLabel(a0, a1, a2) (cObjective_SetSingleLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int cObjective_SetPluralLabel(void*, char*, int);
#endif /* merge_units */
#define cObjective_SetPluralLabel(a0, a1, a2) (cObjective_SetPluralLabel((void *)(a0), (char *)(a1), (a2))) /* merge_units */

unsigned char Objective_ConsumeEvent(void* o, Ev228E10* e) {
    unsigned char r = 0;
    int* t = Event_GetType(e);
    if (*t == *(int*)D_0051F0B0) {
        switch (e->kind) {
        case 0: Objective_SetFailed(o); r = 1; break;
        case 1: Objective_SetCompleted(o); r = 1; break;
        case 2: Objective_FormatStatusText(o); r = 1; break;
        case 3: func_00228BE0(o, e->arg); r = 1; break;
        case 6: {
            int id = e->id;
            void* p = Object_LookupById(&id);
            if (p) cObjective_SetMapObject(o, p, e->name, 1);
            r = 1;
            break;
        }
        case 7: cObjective_ClearMapObject(o, 1); r = 1; break;
        case 8: cObjective_SetNameLabel(o, e->name, 1); break;
        case 9: cObjective_SetMenuLabel(o, e->name, 1); break;
        case 10: cObjective_SetMapLabel(o, e->name, 1); break;
        case 11: cObjective_SetAddLabel(o, e->name, 1); break;
        case 12: cObjective_SetCompleteLabel(o, e->name, 1); break;
        case 13: cObjective_SetFailLabel(o, e->name, 1); break;
        case 14: cObjective_SetSingleLabel(o, e->name, 1); break;
        case 15: cObjective_SetPluralLabel(o, e->name, 1); break;
        }
    }
    return r;
}
#undef Event_GetType /* merge_units */
#undef Objective_SetFailed /* merge_units */
#undef Objective_FormatStatusText /* merge_units */
#undef func_00228BE0 /* merge_units */
#undef cObjective_SetMapObject /* merge_units */
#undef cObjective_ClearMapObject /* merge_units */
#undef cObjective_SetNameLabel /* merge_units */
#undef cObjective_SetMenuLabel /* merge_units */
#undef cObjective_SetMapLabel /* merge_units */
#undef cObjective_SetAddLabel /* merge_units */
#undef cObjective_SetCompleteLabel /* merge_units */
#undef cObjective_SetFailLabel /* merge_units */
#undef cObjective_SetSingleLabel /* merge_units */
#undef cObjective_SetPluralLabel /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228E10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228E10 */

/* merge_units: begin func_00228FE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cObjective virtuals that clear/set the active byte (+0x25).
 */


void cObjective_v07(cObjective* self) {
    self->active = 0;
}

void cObjective_v06(cObjective* self) {
    self->active = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00228FE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00228FE0 */

/* merge_units: begin func_00229000 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x18];
    int flags;      /* 0x1C */
    int pad20;
    int target;     /* 0x24 */
    unsigned char b28;
} ObjActMsg_e8;
extern unsigned char D_005721D0;
extern char D_00572188[];
extern void func_00428CD0();
extern void func_00428E70();
extern char D_004E0E60[];
#if 0 /* merge_units */
extern int Event_Construct(ObjActMsg_e8* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern void func_00428FD0(ObjActMsg_e8* msg, int id);
#if 0 /* merge_units */
extern int cMessage_dtor(ObjActMsg_e8* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void Objective_Activate(ObjAct_e8* self)
{
    self->active = 1;
    if (g_IsMultiplayer && D_005721D0) {
        ObjActMsg_e8 msg;
        Event_Construct(&msg, D_00572188);
        msg.vtable = ((char*)D_004E0E60);
        msg.b28 = 0;
        msg.target = -1;
        msg.flags = 0x40;
        func_00428FD0(&msg, self->id);
        msg.vtable = ((char*)D_004E0E60);
        cMessage_dtor(&msg, 0);
    }
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00229000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00229000 */

/* merge_units: begin func_002290A0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" VtableObject* func_002290A0(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0E60;
        cMessage_dtor((ObjLabelMsg*)self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002290A0 */

/* merge_units: begin func_00229100 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x2C]; } Visitor;
typedef struct { char pad[0x10]; void* target; char pad2[0x11]; unsigned char active; } Objective_00229100;
extern char D_00572198[];
extern char D_004E0E80[];
#if 0 /* merge_units */
extern int Event_Construct(Visitor* v, void* arg);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern void func_00429200(Visitor* v, void* target, int flags);
#if 0 /* merge_units */
extern int cMessage_dtor(Visitor* v, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* Deactivates the objective and, when both global flags are set, notifies its target. */
void Objective_Deactivate(Objective_00229100* self)
{
    self->active = 0;
    if (g_IsMultiplayer && D_005721D0) {
        Visitor v;
        Event_Construct(&v, D_00572198);
        v.vtable = D_004E0E80;
        func_00429200(&v, self->target, -1);
        v.vtable = D_004E0E80;
        cMessage_dtor(&v, 0);
    }
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00229100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00229100 */

/* merge_units: begin func_00229180 */
#pragma push /* merge_units */
int cObjective_v04(void); /* gsynth: defined below */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
extern "C" int cObjective_v04();
#endif /* merge_units */
#define cObjective_v04() (cObjective_v04()) /* merge_units */

#if 0 /* merge_units */
extern "C" int cObjective_v0B();
#endif /* merge_units */
#define cObjective_v0B() (cObjective_v0B()) /* merge_units */

extern char D_004DB7D0[];
#if 0 /* merge_units */
void Receiver_Destruct(void* self, int flag);
#endif /* merge_units */
#define Receiver_Destruct(a0, a1) (Receiver_Destruct((ObjMan00227E60 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}
static inline void Del_00229180(void* p, int line) { if (p) { AllocGuard g; Mem_Free(0, p, D_004A5D88, line); } }
struct S_00229180 { void* vt; char pad4[0x48]; void* p4C; void* p50; char pad54[4]; void* p58; char pad5c[4]; void* p60; void* p64; void* p68; void* p6C; void* p70; void* p74; void* p78; void* p7C; void* p80; void* p84; void* p88; };
extern "C" S_00229180* cObjective_dtor(S_00229180* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004DB7D0);
        Del_00229180(self->p4C, 0x7A);
        Del_00229180(self->p50, 0x7D);
        Del_00229180(self->p58, 0x80);
        Del_00229180(self->p60, 0x83);
        Del_00229180(self->p64, 0x86);
        Del_00229180(self->p68, 0x89);
        Del_00229180(self->p6C, 0x8C);
        Del_00229180(self->p70, 0x8F);
        Del_00229180(self->p74, 0x92);
        Del_00229180(self->p78, 0x95);
        Del_00229180(self->p7C, 0x98);
        Del_00229180(self->p80, 0x9B);
        Del_00229180(self->p84, 0x9E);
        Del_00229180(self->p88, 0xA1);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
extern char D_004DB7D0[];
#undef cObjective_v04 /* merge_units */
#undef cObjective_v0B /* merge_units */
#undef Receiver_Destruct /* merge_units */
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00229180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00229180 */

/* merge_units: begin func_00229900 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}

extern "C" {
extern char D_004F7570[];
#if 0 /* merge_units */
extern char D_004DB7D0[];
#endif /* merge_units */
#define D_004DB7D0 ((char*)&D_004DB7D0) /* merge_units */

#if 0 /* merge_units */
void Receiver_Construct(Obj_229900* o, void* t);
#endif /* merge_units */
#define Receiver_Construct(a0, a1) (Receiver_Construct((ObjMan_7ED0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void Objective_Activate(Obj_229900* o);
#endif /* merge_units */
#define Objective_Activate(a0) (Objective_Activate((ObjAct_e8 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void IdMgr_Allocate(int* id, int n);
#endif /* merge_units */
#define IdMgr_Allocate(a0, a1) (IdMgr_Allocate((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int NetMap_BindReceiver(int a, int b, void* c);
#endif /* merge_units */
#define NetMap_BindReceiver(a0, a1, a2) (NetMap_BindReceiver((a0), (a1), (ObjMan_7ED0 *)(a2))) /* merge_units */

}
static inline int ObjId_229900(int& tmp)
{
    int id;
    int ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        id = NetLocalId();
    } else {
        func_002EBBA0(D_005721A8, &tmp);
        id = tmp;
    }
    return id;
}
struct IdObj { char pad[0xC]; int id; };
static inline int GetId_229900(IdObj* o, int& t)
{
    int* p;
    if (o) {
        p = &o->id;
    } else {
        t = -1;
        p = &t;
    }
    return *p;
}

extern "C" Obj_229900* Objective_Ctor(Obj_229900* self, int arg)
{
    int id;
    int tmp;
    int t;
    Receiver_Construct(self, D_004F7570);
    self->vtable = D_004DB7D0;
    self->x38 = -2;
    self->x34 = 0;
    self->arg = arg;
    self->b24 = 0;
    Objective_Activate(self);
    self->b26 = 0;
    self->b27 = 3;
    self->b28 = 1;
    self->b29 = 0;
    self->x30 = 0;
    self->x34 = 0;
    self->x38 = GetId_229900(0, t);
    self->b3C = 0;
    self->x40 = 0;
    self->x44 = 0;
    self->x48 = 0;
    self->x4C = 0;
    self->x50 = 0;
    self->b54 = 0;
    self->x58 = 0;
    self->b5C = 0;
    self->x60 = 0;
    self->x64 = 0;
    self->x68 = 0;
    self->x6C = 0;
    self->x70 = 0;
    self->x74 = 0;
    self->x78 = 0;
    self->x7C = 0;
    self->x80 = 0;
    self->x84 = 0;
    self->x88 = 0;
    if (g_IsMultiplayer) {
        IdMgr_Allocate(&id, 0xF6);
        self->id = id;
        self->netid = self->id;
        int nid = self->netid;
        NetMap_BindReceiver(nid, ObjId_229900(tmp), self);
        if (!(g_IsMultiplayer ? D_005721C0 : 1))
            self->active = 0;
    }
    return self;
}
#undef D_004DB7D0 /* merge_units */
#undef Receiver_Construct /* merge_units */
#undef Objective_Activate /* merge_units */
#undef IdMgr_Allocate /* merge_units */
#undef NetMap_BindReceiver /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00229900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00229900 */

/* merge_units: begin func_00229AD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script globals selecting the objective-screen fonts.
 */


#if 0 /* merge_units */
extern char D_0048AB20[]; /* objectives body font id */
#endif /* merge_units */
#define D_0048AB20 ((char*)&D_0048AB20) /* merge_units */

#if 0 /* merge_units */
extern char D_004F7560[]; /* objectives header font id */
#endif /* merge_units */
#define D_004F7560 ((char*)&D_004F7560) /* merge_units */

extern void Objectives_SetHeaderFont(int);
extern void Objectives_SetFont(int);

int Script_SetObjectivesHeaderFont(ScriptArg* args) {
    Objectives_SetHeaderFont(args[0].u8);
    return 0;
}

/* Sets the objectives header font. */
void Objectives_SetHeaderFont(int font) {
    *(char*)D_004F7560 = font;
}

int Script_SetObjectivesFont(ScriptArg* args) {
    Objectives_SetFont(args[0].u8);
    return 0;
}

/* Sets the objectives body font. */
void Objectives_SetFont(int font) {
    *(char*)D_0048AB20 = font;
}

int cObjective_v04(void) {
    return 1;
}
#undef D_0048AB20 /* merge_units */
#undef D_004F7560 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00229AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00229AD0 */
