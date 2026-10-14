/*
 * main/npc: range (43 files, 00148CD0-001495B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00148CD0 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_types.h"
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef struct GObj {
    char pad[0x2C];
    unsigned char enabled; /* +0x2C */
    unsigned char active;  /* +0x2D */
    unsigned char paused;  /* +0x2E */
} GObj;

/* Virtual-call view of cNPCCtl: only the slots used here are named (vtable offset in comments). */
struct cNPCCtl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void Method48(); /* +0x48 */
    char pad04[0x30 - 4];
    GObj* owner; /* +0x30 */
    char pad34[0x5C - 0x34];
    unsigned char live; /* +0x5C */
};

extern "C" void func_001489D0(void* arg, cNPCCtl* self);

static inline bool IsLive(GObj* o)
{
    return o->active && o->enabled && !o->paused;
}

/* Runs func_001489D0, then virtual +0x48 with the +0x5C flag set to whether the owner is live. */
extern "C" void func_00148CD0(cNPCCtl* self, void* arg)
{
    func_001489D0(arg, self);
    self->live = IsLive(self->owner);
    self->Method48();
    self->live = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148CD0 */

/* merge_units: begin func_00148D50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cNPC_00148D50 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85();
    virtual int GetItemCount(int item); /* +0x220 */
};

/* Script native: returns cNPC::GetItemCount(args[1]). */
extern "C" int Script_cNPC_GetItemCount(ScriptArg* args)
{
    volatile int count;
    int part[1];
    cNPC_00148D50* npc;
    part[0] = args[1].i;
    npc = (cNPC_00148D50*)args[0].p;
    count = npc->GetItemCount(*(int*)part);
    return count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148D50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148D50 */

/* merge_units: begin func_00148D90 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148D90 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00148D90;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148D90 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84();
    virtual void RemoveItem(int item, int count); /* +0x21C */
};

/* Script native: cNPC::RemoveItem(args[1], 100000) (removes all). Returns 0. */
extern "C" int Script_cNPC_RemoveItem_2(ScriptArg_00148D90* args)
{
    int part[1];
    cNPC_00148D90* obj;
    part[0] = args[1].i;
    obj = (cNPC_00148D90*)args[0].p;
    obj->RemoveItem(*(int*)part, 100000);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148D90 */

/* merge_units: begin func_00148DD0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00148DD0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84();
    virtual void RemoveItem(int item, int count); /* +0x21C */
};

/* Script native: cNPC::RemoveItem(args[1], args[2]); returns 0. */
extern "C" int Script_cNPC_RemoveItem(ScriptArg* args)
{
    int count[1];
    int item[1];
    cNPC_00148DD0* npc;
    count[0] = args[2].i;
    item[0] = args[1].i;
    npc = (cNPC_00148DD0*)args[0].p;
    npc->RemoveItem(*(int*)item, *(int*)count);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148DD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148DD0 */

/* merge_units: begin func_00148E10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148E10 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00148E10;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148E10 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void AddItem(int item, int count); /* +0x218 */
};

/* Script native: cNPC::AddItem(args[1], 1). Returns 0. */
extern "C" int Script_cNPC_AddItem_2(ScriptArg_00148E10* args)
{
    int part[1];
    cNPC_00148E10* obj;
    part[0] = args[1].i;
    obj = (cNPC_00148E10*)args[0].p;
    obj->AddItem(*(int*)part, 1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148E10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148E10 */

/* merge_units: begin func_00148E50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148E50 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00148E50;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148E50 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void AddItem(int item, int count); /* +0x218 */
};

/* Script native: cNPC::AddItem(args[1], args[2]); both go through stack temporaries. Returns 0. */
extern "C" int Script_cNPC_AddItem(ScriptArg_00148E50* args)
{
    int count[1];
    int item[1];
    cNPC_00148E50* obj;
    count[0] = args[2].i;
    item[0] = args[1].i;
    obj = (cNPC_00148E50*)args[0].p;
    obj->AddItem(*(int*)item, *(int*)count);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148E50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148E50 */

/* merge_units: begin func_00148E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* Script: cNPC.ForceOnRadar(on). */
int Script_cNPC_ForceOnRadar(NpcScriptArgs* args) {
    args->npc->forceOnRadar = (0U < (unsigned int)args->arg1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148E90 */

/* merge_units: begin func_00148EB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148EB0 { int i; float f; void* p; } ScriptArg_00148EB0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148EB0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void ActivateByRadiusOff(); /* +0x1D0 */
};

/* Script native: cNPC::ActivateByRadiusOff() on args[0]; returns 0. */
extern "C" int Script_cNPC_ActivateByRadiusOff(ScriptArg_00148EB0* args)
{
    cNPC_00148EB0* obj = (cNPC_00148EB0*)args[0].p;
    obj->ActivateByRadiusOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148EB0 */

/* merge_units: begin func_00148EE0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00148EE0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70();
    virtual void ActivateByRadius(float value); /* +0x1CC */
};

/* Script native: cNPC::ActivateByRadius(args[1]) on args[0]; returns 0. */
extern "C" int Script_cNPC_ActivateByRadius_2(ScriptArg* args)
{
    int part[1];
    cNPC_00148EE0* obj;
    part[0] = args[1].i;
    obj = (cNPC_00148EE0*)args[0].p;
    obj->ActivateByRadius(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148EE0 */

/* merge_units: begin func_00148F20 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148F20 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00148F20;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148F20 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70();
    virtual void ActivateByRadius(float radius); /* +0x1CC */
};

/* Script native: cNPC::ActivateByRadius(0.0f) on args[0]; returns 0. */
extern "C" int Script_cNPC_ActivateByRadius(ScriptArg_00148F20* args)
{
    cNPC_00148F20* obj = (cNPC_00148F20*)args[0].p;
    obj->ActivateByRadius(0.0f);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148F20 */

/* merge_units: begin func_00148F50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00148F50 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81(); virtual void v82();
    virtual void SetNotTargetable(int value); /* +0x214 */
};

/* Script native: cNPC::SetNotTargetable(args[1].i != 0) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetNotTargetable(ScriptArg* args)
{
    cNPC_00148F50* obj = (cNPC_00148F50*)args[0].p;
    obj->SetNotTargetable(args[1].i != 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148F50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148F50 */

/* merge_units: begin func_00148F80 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148F80 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00148F80;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148F80 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80(); virtual void v81();
    virtual void SetNotGasable(bool on); /* +0x210 */
};

/* Script native: cNPC::SetNotGasable(args[1].i != 0) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetNotGasable(ScriptArg_00148F80* args)
{
    cNPC_00148F80* obj = (cNPC_00148F80*)args[0].p;
    obj->SetNotGasable(args[1].i != 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148F80 */

/* merge_units: begin func_00148FB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00148FB0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F(); virtual void v80();
    virtual void SetNotTaserable(int value); /* +0x20C */
};

/* Script native: cNPC::SetNotTaserable(args[1].i != 0) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetNotTaserable(ScriptArg* args)
{
    cNPC_00148FB0* obj = (cNPC_00148FB0*)args[0].p;
    obj->SetNotTaserable(args[1].i != 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148FB0 */

/* merge_units: begin func_00148FE0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00148FE0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00148FE0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00148FE0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E(); virtual void v7F();
    virtual void SetUnconscious(); /* +0x208 */
};

/* Script native: cNPC::SetUnconscious() on args[0]; returns 0. */
extern "C" int Script_cNPC_SetUnconscious(ScriptArg_00148FE0* args)
{
    cNPC_00148FE0* obj = (cNPC_00148FE0*)args[0].p;
    obj->SetUnconscious();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00148FE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00148FE0 */

/* merge_units: begin func_00149010 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149010 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149010;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149010 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void v7E();
    virtual void SetFireInvulnerability(bool on); /* +0x204 */
};

/* Script native: cNPC::SetFireInvulnerability(args[1].i != 0) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetFireInvulnerability(ScriptArg_00149010* args)
{
    cNPC_00149010* obj = (cNPC_00149010*)args[0].p;
    obj->SetFireInvulnerability(args[1].i != 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149010 */

/* merge_units: begin func_00149040 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00149040 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D();
    virtual void DontDropWeapons(); /* +0x200 */
};

/* Script native: cNPC::DontDropWeapons() on args[0]; returns 0. */
extern "C" int Script_cNPC_DontDropWeapons(ScriptArg* args)
{
    cNPC_00149040* obj = (cNPC_00149040*)args[0].p;
    obj->DontDropWeapons();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149040 */

/* merge_units: begin func_00149070 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149070 { int i; float f; void* p; } ScriptArg_00149070;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149070 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79();
    virtual void EquipGoggles(int on); /* +0x1F0 */
};

/* Script native: cNPC::EquipGoggles(args[1] != 0); returns 0. */
extern "C" int Script_cNPC_EquipGoggles(ScriptArg_00149070* args)
{
    cNPC_00149070* npc = (cNPC_00149070*)args[0].p;
    npc->EquipGoggles(args[1].i != 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149070 */

/* merge_units: begin func_001490A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001490A0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_001490A0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001490A0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78();
    virtual void RequestDeathAnimation(int value); /* +0x1EC */
};

/* Script native: cNPC::RequestDeathAnimation(args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_RequestDeathAnimation(ScriptArg_001490A0* args)
{
    int part[1];
    cNPC_001490A0* obj;
    part[0] = args[1].i;
    obj = (cNPC_001490A0*)args[0].p;
    obj->RequestDeathAnimation(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001490A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001490A0 */

/* merge_units: begin func_001490E0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_001490E0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void SetInvulnerable(int on, int flag); /* +0x1E8 */
};

/* Script native: cNPC::SetInvulnerable(args[1] != 0, 0); returns 0. */
extern "C" int Script_cNPC_SetInvulnerable(ScriptArg* args)
{
    cNPC_001490E0* npc = (cNPC_001490E0*)args[0].p;
    npc->SetInvulnerable(args[1].i != 0, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001490E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001490E0 */

/* merge_units: begin func_00149120 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00149120 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
    virtual float GetAimPercent(); /* +0x1E4 */
};

/* Script native: returns cNPC::GetAimPercent() of args[0] (float bits). */
extern "C" int Script_cNPC_GetAimPercent(ScriptArg* args)
{
    cNPC_00149120* npc = (cNPC_00149120*)args[0].p;
    volatile float percent = npc->GetAimPercent();
    return *(int*)&percent;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149120 */

/* merge_units: begin func_00149150 */
#pragma push /* merge_units */
/* vtable slot 0x77: GetAimPercent. */
float cNPC_GetAimPercent(cNPC* self) {
    return self->aimPercent;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149150 */

/* merge_units: begin func_00149160 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149160 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149160;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149160 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual int GetDarkness(); /* +0x1E0 */
};

/* Script native: returns cNPC::GetDarkness() of args[0]. */
extern "C" int Script_cNPC_GetDarkness(ScriptArg_00149160* args)
{
    cNPC_00149160* obj = (cNPC_00149160*)args[0].p;
    volatile int result = obj->GetDarkness(); /* returned through a stack temporary */
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149160 */

/* merge_units: begin func_00149190 */
#pragma push /* merge_units */
/* vtable slot 0x76: GetDarkness (read from the owning actor). */
int cNPC_GetDarkness(cNPC* self) {
    return self->actor->darkness;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149190 */

/* merge_units: begin func_001491A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001491A0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_001491A0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001491A0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74();
    virtual void SetDarkness(int value); /* +0x1DC */
};

/* Script native: cNPC::SetDarkness(args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_SetDarkness(ScriptArg_001491A0* args)
{
    int part[1];
    cNPC_001491A0* obj;
    part[0] = args[1].i;
    obj = (cNPC_001491A0*)args[0].p;
    obj->SetDarkness(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001491A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001491A0 */

/* merge_units: begin func_001491E0 */
#pragma push /* merge_units */
/* vtable slot 0x75: SetDarkness (no-op for cNPC). */
void cNPC_SetDarkness(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001491E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001491E0 */

/* merge_units: begin func_001491F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_001491F0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73();
    virtual void SetHasDisguise(int on, int flag); /* +0x1D8 */
};

/* Script native: cNPC::SetHasDisguise(args[1] != 0, 1); returns 0. */
extern "C" int Script_cNPC_SetHasDisguise(ScriptArg* args)
{
    cNPC_001491F0* npc = (cNPC_001491F0*)args[0].p;
    npc->SetHasDisguise(args[1].i != 0, 1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001491F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001491F0 */

/* merge_units: begin func_00149230 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149230 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149230;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149230 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72();
    virtual void SetPickupable(bool on, int flag); /* +0x1D4 */
};

/* Script native: cNPC::SetPickupable(args[1].i != 0, 1) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetPickupable(ScriptArg_00149230* args)
{
    cNPC_00149230* obj = (cNPC_00149230*)args[0].p;
    obj->SetPickupable(args[1].i != 0, 1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149230 */

/* merge_units: begin func_00149270 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00149270 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual unsigned char InViewCone(void* target); /* +0x188 */
};

extern "C" void* GObj_IdentityB(void* object);

/* Script native: whether the object args[1] is inside the NPC view cone. */
extern "C" int Script_cNPC_InViewCone(ScriptArg* args)
{
    cNPC_00149270* npc = (cNPC_00149270*)args[0].p;
    return npc->InViewCone(GObj_IdentityB(args[1].p));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149270 */

/* merge_units: begin func_001492B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001492B0 { int i; float f; void* p; } ScriptArg_001492B0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001492B0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E();
    virtual void SetViewConeAngle(float value); /* +0x184 */
};

/* Script native: cNPC::SetViewConeAngle(args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_SetViewConeAngle(ScriptArg_001492B0* args)
{
    int part[1];
    cNPC_001492B0* obj;
    part[0] = args[1].i;
    obj = (cNPC_001492B0*)args[0].p;
    obj->SetViewConeAngle(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001492B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001492B0 */

/* merge_units: begin func_001492F0 */
#pragma push /* merge_units */
/* vtable slot 0x5F: SetViewConeAngle(degrees); stores the half angle in radians. */
void cNPC_SetViewConeAngle(cNPC* self, float degrees) {
    NpcAi* ai;

    ai = self->ai;
    ai->viewConeHalfAngle = (0.01745329238474369f * (0.5f * degrees));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001492F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001492F0 */

/* merge_units: begin func_00149320 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_00149320 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D();
    virtual void SetViewConeRadius(float value); /* +0x180 */
};

/* Script native: cNPC::SetViewConeRadius(args[1]) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetViewConeRadius(ScriptArg* args)
{
    int part[1];
    cNPC_00149320* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149320*)args[0].p;
    obj->SetViewConeRadius(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149320 */

/* merge_units: begin func_00149360 */
#pragma push /* merge_units */
/* vtable slot 0x5E: SetViewConeRadius. */
void cNPC_SetViewConeRadius(cNPC* self, float radius) {
    self->ai->viewConeRadius = radius;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149360 */

/* merge_units: begin func_00149370 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149370 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149370;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149370 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C();
    virtual void SetOnFire(float value); /* +0x17C */
};

/* Script native: cNPC::SetOnFire((float)args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_SetOnFire_2(ScriptArg_00149370* args)
{
    int part[1];
    cNPC_00149370* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149370*)args[0].p;
    obj->SetOnFire(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149370 */

/* merge_units: begin func_001493B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_001493B0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C();
    virtual void SetOnFire(float duration); /* +0x17C */
};

/* Script native: sets the NPC on fire indefinitely (-1); returns 0. */
extern "C" int Script_cNPC_SetOnFire(ScriptArg* args)
{
    cNPC_001493B0* npc = (cNPC_001493B0*)args[0].p;
    npc->SetOnFire(-1.0f);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001493B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001493B0 */

/* merge_units: begin func_001493F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_001493F0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void* GetClosestPlayer(); /* +0xF0 */
};

extern "C" int GObj_IdentityA(void* object);

/* Script native: script id of the closest player to the NPC. */
extern "C" int Script_cNPC_GetClosestPlayer(ScriptArg* args)
{
    cNPC_001493F0* npc = (cNPC_001493F0*)args[0].p;
    return GObj_IdentityA(npc->GetClosestPlayer());
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001493F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001493F0 */

/* merge_units: begin func_00149420 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149420 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149420;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149420 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual void AddAwarenessOfPlayers(); /* +0xEC */
};

/* Script native: cNPC::AddAwarenessOfPlayers() on args[0]; returns 0. */
extern "C" int Script_cNPC_AddAwarenessOfPlayers(ScriptArg_00149420* args)
{
    cNPC_00149420* obj = (cNPC_00149420*)args[0].p;
    obj->AddAwarenessOfPlayers();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149420 */

/* merge_units: begin func_00149450 */
#pragma push /* merge_units */
extern void cNPC_SetMaxActiveNpcCount(int count);

/* Script: cNPC.SetMaxActiveNpcCount(count). */
int Script_cNPC_SetMaxActiveNpcCount(NpcScriptArgs* args) {
    int count[1]; /* staged through the stack like the other argument readers */

    *(int*)(char*)count = args->arg1;
    cNPC_SetMaxActiveNpcCount(*(int*)(char*)count);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149450 */

/* merge_units: begin func_00149480 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149480 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149480;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149480 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C();
    virtual void RemoveGroupFromPathRegion(void* target); /* +0x1FC */
};

extern "C" void* func_0015C120(void* handle);

/* Script native: cNPC::RemoveGroupFromPathRegion(func_0015C120(args[1])); returns 0. */
extern "C" int Script_cNPC_RemoveGroupFromPathRegion(ScriptArg_00149480* args)
{
    cNPC_00149480* npc = (cNPC_00149480*)args[0].p;
    npc->RemoveGroupFromPathRegion(func_0015C120(args[1].p));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149480 */

/* merge_units: begin func_001494C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNPC_001494C0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B();
    virtual void AddGroupToPathRegion(void* group); /* +0x1F8 */
};

#if 0 /* merge_units */
extern "C" void* func_0015C120(void* id);
#endif /* merge_units */
#define func_0015C120(a0) (func_0015C120((a0))) /* merge_units */


/* Script native: adds node group args[1] to the NPC path region. */
extern "C" int Script_cNPC_AddGroupToPathRegion(ScriptArg* args)
{
    cNPC_001494C0* npc = (cNPC_001494C0*)args[0].p;
    npc->AddGroupToPathRegion(func_0015C120(args[1].p));
    return 0;
}
#undef func_0015C120 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001494C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001494C0 */

/* merge_units: begin func_00149500 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149500 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00149500;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149500 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A();
    virtual void RestrictMovementToNodeGroup(void* target); /* +0x1F4 */
};

/* Script native: cNPC::RestrictMovementToNodeGroup(func_0015C120(args[1])); returns 0. */
extern "C" int Script_cNPC_RestrictMovementToNodeGroup(ScriptArg_00149500* args)
{
    cNPC_00149500* npc = (cNPC_00149500*)args[0].p;
    npc->RestrictMovementToNodeGroup(func_0015C120(args[1].p));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149500 */

/* merge_units: begin func_00149540 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149540 { int i; float f; void* p; } ScriptArg_00149540;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149540 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B();
    virtual void CheckHotbox(void* hotbox); /* +0x178 */
};

extern "C" void* func_0016FE30(void* object);

/* Script native: cNPC::CheckHotbox(hotbox of args[1]); returns 0. */
extern "C" int Script_cNPC_CheckHotbox(ScriptArg_00149540* args)
{
    cNPC_00149540* npc = (cNPC_00149540*)args[0].p;
    npc->CheckHotbox(func_0016FE30(args[1].p));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149540 */

/* merge_units: begin func_00149580 */
#pragma push /* merge_units */
typedef struct cNPC_5C {
    char pad000[0x141];
    unsigned char flag0 : 1; /* 0x141 */
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 4;
    char pad142[0x72];
    int unk1B4;              /* 0x1B4 */
} cNPC_5C;

/* cNPC virtual slot 0x5C: stores the value at +0x1B4 and clears flag bit 3. */
void cNPC_v5C(cNPC_5C* self, int value) {
    self->unk1B4 = value;
    self->flag3 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149580 */

/* merge_units: begin func_001495B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001495B0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_001495B0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001495B0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A();
    virtual void SetHitPoints(int value); /* +0x174 */
};

/* Script native: cNPC::SetHitPoints(args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_SetHitPoints(ScriptArg_001495B0* args)
{
    int part[1];
    cNPC_001495B0* obj;
    part[0] = args[1].i;
    obj = (cNPC_001495B0*)args[0].p;
    obj->SetHitPoints(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001495B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001495B0 */
