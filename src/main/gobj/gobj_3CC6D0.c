/*
 * main/gobj: range (6 files, 003CC6D0-003CC870)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "gobj_types.h"

/* merge_units: begin func_003CC6D0 */
#pragma push /* merge_units */
typedef struct GObjHp {
    char pad[0x40];
    float hitpoints;
} GObjHp;

typedef struct GObjArgs {
    GObjHp* obj;
} GObjArgs;

/* Script native: cGOBJ.GetHitpoints - returns hitpoints truncated to int. */
int Script_cGOBJ_GetHitpoints(GObjArgs* args) {
    volatile int hp = args->obj->hitpoints;
    return hp;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC6D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC6D0 */

/* merge_units: begin func_003CC700 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */


int Script_cGOBJ_CreateBlast(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC700 */

/* merge_units: begin func_003CC710 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003CC710 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_003CC710;

/* Virtual-call view of TeamInfo: only the slots used here are named (vtable offset in comments). */
struct TeamInfo {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsNPC(); /* +0x58 */
};

struct TeamInfo;
typedef struct cGOBJ_003CC710 { char pad[0x58]; struct TeamInfo* team; /* +0x58 */ } cGOBJ_003CC710;

/* Script native: 1 when the object's team info reports an NPC, else 0. */
extern "C" int Script_cGOBJ_IsNPC(ScriptArg_003CC710* args)
{
    unsigned char result = 0;
    TeamInfo* info = ((cGOBJ_003CC710*)args[0].p)->team;
    if (info && info->IsNPC())
        result = 1;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC710 */

/* merge_units: begin func_003CC760 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003CC760 { int i; float f; void* p; unsigned char b; } ScriptArg_003CC760;

struct Component {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int IsPlayer(); /* +0x54 */
};

typedef struct cGOBJ_003CC760 { char pad[0x58]; Component* component; /* +0x58 */ } cGOBJ_003CC760;

/* Script native: whether the object component (+0x58) reports itself as a player (virtual +0x54). */
extern "C" int Script_IsPlayer(ScriptArg_003CC760* args)
{
    cGOBJ_003CC760* obj = (cGOBJ_003CC760*)args[0].p;
    Component* component = obj->component;
    unsigned char result = 0;
    if (component) {
        if (component->IsPlayer())
            result = 1;
    }
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC760 */

/* merge_units: begin func_003CC7B0 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ script type registration, identity conversions and accessors.
 */


extern int D_005436B8;   /* cGOBJ script-type key */
extern int D_005436C0;   /* cGOBJ script-type value */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cSystem_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);
extern int* cDamageMsg_SOBJ_getClassId(void);

/* Registers the cGOBJ script type: parent type, then one accepted interface. */
int ScriptType_cGOBJ_Init(void) {
    int* key;

    key = cSystem_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_005436C0, *key);
    key = cDamageMsg_SOBJ_getClassId();
    return ScriptType_AddAccepted(D_005436C0, *key);
}

/* Identity conversion of a GOBJ script value; the volatile mirrors the stack temporary. */
int GObj_IdentityA(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* GObj_IdentityB(void* self) {
    return self;
}

/* Address of the cGOBJ script-type key. */
int* cGOBJ_GetScriptTypeKeyPtr(void) {
    return &D_005436B8;
}

int cGOBJ_v0B(void) {
    return D_005436B8;
}

int cGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC7B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC7B0 */

/* merge_units: begin func_003CC870 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x5C]; int script; unsigned char flag; char pad2[3]; int owner; } SubScript;

extern char D_004DFE40[];
extern void cGOBJ_ctor(SubScript* self, int* a, int b, int* c);

/* SubScript constructor. */
SubScript* SubScript_ctor(SubScript* self, int script, int owner)
{
    int c = 0;
    int a = 0;
    cGOBJ_ctor(self, &a, 0, &c);
    self->vtable = D_004DFE40;
    self->script = script;
    self->owner = owner;
    self->flag = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC870 */
