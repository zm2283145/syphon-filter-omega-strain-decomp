/*
 * main/npc: range (76 files, 00149630-0014A810)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "npc_types.h"

/* merge_units: begin func_00149630 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149630 {
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
    virtual int GetHitPoints(); /* +0x170 */
};

/* Script native: returns cNPC::GetHitPoints() of args[0]. */
extern "C" int Script_cNPC_GetHitPoints(ScriptArg* args)
{
    cNPC_00149630* obj = (cNPC_00149630*)args[0].p;
    volatile int result = obj->GetHitPoints(); /* returned through a stack temporary */
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149630 */

/* merge_units: begin func_00149660 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; } NpcState;
typedef struct { char pad[0x30]; NpcState* state; } NpcObj;

/* Returns the NPC state float at +0x40 truncated to int. */
int cNPC_v5A(NpcObj* self)
{
    return (int)self->state->f40;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149660 */

/* merge_units: begin func_00149680 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149680 { int i; float f; void* p; unsigned char b; } ScriptArg_00149680;

struct cNPC_00149680 {
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
    virtual void v60(); virtual void v61(); virtual void v62();
    virtual void* GetDestinationNode(); /* +0x194 */
};

extern "C" int cNode_Identity(void* node);

/* Script native: id of the NPC destination node. */
extern "C" int Script_cNPC_GetDestinationNode(ScriptArg_00149680* args)
{
    cNPC_00149680* npc = (cNPC_00149680*)args[0].p;
    return cNode_Identity(npc->GetDestinationNode());
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149680 */

/* merge_units: begin func_001496B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001496B0 {
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
    virtual void v60(); virtual void v61();
    virtual void* GetNextNode(); /* +0x190 */
};

/* Script native: returns the id (cNode_Identity) of the NPC's next path node. */
extern "C" int Script_cNPC_GetNextNode(ScriptArg* args)
{
    cNPC_001496B0* npc = (cNPC_001496B0*)args[0].p;
    return cNode_Identity(npc->GetNextNode());
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001496B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001496B0 */

/* merge_units: begin func_001496E0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001496E0 { int i; float f; void* p; unsigned char b; } ScriptArg_001496E0;

struct cNPC_001496E0 {
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
    virtual void v60();
    virtual void* GetCurrentNode(); /* +0x18C */
};

/* Script native: id of the NPC current node. */
extern "C" int Script_cNPC_GetCurrentNode(ScriptArg_001496E0* args)
{
    cNPC_001496E0* npc = (cNPC_001496E0*)args[0].p;
    return cNode_Identity(npc->GetCurrentNode());
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001496E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001496E0 */

/* merge_units: begin func_00149710 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149710 { int i; float f; void* p; unsigned char b; } ScriptArg_00149710;

struct cNPC_00149710 {
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
    virtual void SetGrenadeThrowAngle(float value); /* +0x1A0 */
};

/* Script native: cNPC::SetGrenadeThrowAngle(args[1]) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetGrenadeThrowAngle(ScriptArg_00149710* args)
{
    int part[1];
    cNPC_00149710* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149710*)args[0].p;
    obj->SetGrenadeThrowAngle(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149710 */

/* merge_units: begin func_00149750 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* vtable slot 0x66: SetGrenadeThrowAngle. */
void cNPC_SetGrenadeThrowAngle(cNPC* self, float angle) {
    self->grenadeThrowAngle = angle;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149750 */

/* merge_units: begin func_00149760 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149760 { int i; float f; void* p; } ScriptArg_00149760;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149760 {
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
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void SetGrenadeTarget(void* target, float time, int flag); /* +0x19C */
};

extern "C" void* GObj_IdentityB(void* object);

/* Script native: cNPC::SetGrenadeTarget(target of args[1], args[2] as float, args[3] != 0); returns 0. */
extern "C" int Script_cNPC_SetGrenadeTarget_3(ScriptArg_00149760* args)
{
    cNPC_00149760* npc;
    int flag = args[3].i != 0;
    int part[1];
    part[0] = args[2].i;
    npc = (cNPC_00149760*)args[0].p;
    npc->SetGrenadeTarget(GObj_IdentityB(args[1].p), *(float*)part, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149760 */

/* merge_units: begin func_001497C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001497C0 { int i; float f; void* p; unsigned char b; } ScriptArg_001497C0;

struct cNPC_001497C0 {
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
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void SetGrenadeTarget(void* target, float time, int flag); /* +0x19C */
};

/* Script native: cNPC::SetGrenadeTarget(object args[1], args[2], 0); returns 0. */
extern "C" int Script_cNPC_SetGrenadeTarget_2(ScriptArg_001497C0* args)
{
    cNPC_001497C0* npc;
    int part[1];
    part[0] = args[2].i;
    npc = (cNPC_001497C0*)args[0].p;
    npc->SetGrenadeTarget(GObj_IdentityB(args[1].p), *(float*)part, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001497C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001497C0 */

/* merge_units: begin func_00149810 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149810 {
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
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void SetGrenadeTarget(void* target, float speed, int flag); /* +0x19C */
};

#if 0 /* merge_units */
extern "C" void* GObj_IdentityB(void* handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */


/* Script native: cNPC::SetGrenadeTarget(object of args[1], 4.0f, 0); returns 0. */
extern "C" int Script_cNPC_SetGrenadeTarget(ScriptArg* args)
{
    cNPC_00149810* npc = (cNPC_00149810*)args[0].p;
    npc->SetGrenadeTarget(GObj_IdentityB(args[1].p), 4.0f, 0);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149810 */

/* merge_units: begin func_00149860 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149860 {
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
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F();
    virtual void SetWeaponPreferenceDistance(float value); /* +0x1C8 */
};

/* Script native: cNPC::SetWeaponPreferenceDistance((float)args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_SetWeaponPreferenceDistance(ScriptArg* args)
{
    int part[1];
    cNPC_00149860* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149860*)args[0].p;
    obj->SetWeaponPreferenceDistance(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149860 */

/* merge_units: begin func_001498A0 */
#pragma push /* merge_units */
/* vtable slot 0x70: SetWeaponPreferenceDistance. */
void cNPC_SetWeaponPreferenceDistance(cNPC* self, float distance) {
    self->weaponPreferenceDistance = distance;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001498A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001498A0 */

/* merge_units: begin func_001498B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001498B0 { int i; float f; void* p; unsigned char b; } ScriptArg_001498B0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001498B0 {
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
    virtual void v6C(); virtual void v6D(); virtual void v6E();
    virtual void SetWeaponPreference(int weapon, unsigned char flag); /* +0x1C4 */
};

/* Script native: cNPC::SetWeaponPreference(args[1], (byte)args[2]); returns 0. */
extern "C" int Script_cNPC_SetWeaponPreference(ScriptArg_001498B0* args)
{
    int part[1];
    cNPC_001498B0* npc;
    unsigned char flag = args[2].b;
    part[0] = args[1].i;
    npc = (cNPC_001498B0*)args[0].p;
    npc->SetWeaponPreference(*(int*)part, flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001498B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001498B0 */

/* merge_units: begin func_001498F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001498F0 { int i; float f; void* p; unsigned char b; } ScriptArg_001498F0;

struct cNPC_001498F0 {
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
    virtual void v6C(); virtual void v6D();
    virtual int GetWeapon(unsigned char slot); /* +0x1C0 */
};

/* Script native: returns cNPC::GetWeapon(args[1]). */
extern "C" int Script_cNPC_GetWeapon(ScriptArg_001498F0* args)
{
    cNPC_001498F0* npc = (cNPC_001498F0*)args[0].p;
    volatile int weapon = npc->GetWeapon(args[1].b);
    return weapon;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001498F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001498F0 */

/* merge_units: begin func_00149930 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149930 { int i; float f; void* p; } ScriptArg_00149930;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149930 {
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
    virtual void v6C();
    virtual void RemoveWeapon(int value); /* +0x1BC */
};

/* Script native: cNPC::RemoveWeapon(args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_RemoveWeapon(ScriptArg_00149930* args)
{
    int part[1];
    cNPC_00149930* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149930*)args[0].p;
    obj->RemoveWeapon(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149930 */

/* merge_units: begin func_00149970 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149970 {
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
    virtual void AddWeapon(int value); /* +0x1B8 */
};

/* Script native: cNPC::AddWeapon(args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_AddWeapon(ScriptArg* args)
{
    int part[1];
    cNPC_00149970* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149970*)args[0].p;
    obj->AddWeapon(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149970 */

/* merge_units: begin func_001499B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_001499B0 { int i; float f; void* p; unsigned char b; } ScriptArg_001499B0;

struct cNPC_001499B0 {
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
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A();
    virtual void DropWeapon(); /* +0x1B4 */
};

/* Script native: cNPC::DropWeapon() on args[0]; returns 0. */
extern "C" int Script_cNPC_DropWeapon(ScriptArg_001499B0* args)
{
    cNPC_001499B0* obj = (cNPC_001499B0*)args[0].p;
    obj->DropWeapon();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001499B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001499B0 */

/* merge_units: begin func_001499E0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_001499E0 {
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
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void ChangeWeapon(); /* +0x1B0 */
};

/* Script native: cNPC::ChangeWeapon() on args[0]; returns 0. */
extern "C" int Script_cNPC_ChangeWeapon(ScriptArg* args)
{
    cNPC_001499E0* obj = (cNPC_001499E0*)args[0].p;
    obj->ChangeWeapon();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001499E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001499E0 */

/* merge_units: begin func_00149A10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149A10 { int i; float f; void* p; unsigned char b; } ScriptArg_00149A10;

struct cNPC_00149A10 {
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
    virtual void v66(); virtual void v67(); virtual void v68();
    virtual void DrawWeapon(int value); /* +0x1AC */
};

/* Script native: cNPC::DrawWeapon(args[1]) on args[0]; returns 0. */
extern "C" int Script_cNPC_DrawWeapon_2(ScriptArg_00149A10* args)
{
    int part[1];
    cNPC_00149A10* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149A10*)args[0].p;
    obj->DrawWeapon(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149A10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149A10 */

/* merge_units: begin func_00149A50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149A50 { int i; float f; void* p; unsigned char b; } ScriptArg_00149A50;

struct cNPC_00149A50 {
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
    virtual void v66(); virtual void v67(); virtual void v68();
    virtual void DrawWeapon(int value); /* +0x1AC */
};

/* Script native: cNPC::DrawWeapon(-1) on args[0]; returns 0. */
extern "C" int Script_cNPC_DrawWeapon(ScriptArg_00149A50* args)
{
    cNPC_00149A50* obj = (cNPC_00149A50*)args[0].p;
    obj->DrawWeapon(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149A50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149A50 */

/* merge_units: begin func_00149A80 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149A80 {
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
    virtual void v66(); virtual void v67();
    virtual void StoreWeapon(); /* +0x1A8 */
};

/* Script native: cNPC::StoreWeapon() on args[0]; returns 0. */
extern "C" int Script_cNPC_StoreWeapon(ScriptArg* args)
{
    cNPC_00149A80* obj = (cNPC_00149A80*)args[0].p;
    obj->StoreWeapon();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149A80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149A80 */

/* merge_units: begin func_00149AB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149AB0 { int i; float f; void* p; } ScriptArg_00149AB0;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149AB0 {
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
    virtual void v66();
    virtual int GetActiveWeapon(); /* +0x1A4 */
};

/* Script native: returns cNPC::GetActiveWeapon() (via a stack temporary). */
extern "C" int Script_cNPC_GetActiveWeapon(ScriptArg_00149AB0* args)
{
    cNPC_00149AB0* npc = (cNPC_00149AB0*)args[0].p;
    volatile int weapon = npc->GetActiveWeapon();
    return weapon;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149AB0 */

/* merge_units: begin func_00149AE0 */
#pragma push /* merge_units */
extern void cNPC_SetSkill(cNPC* npc, float skill);

/* Script: cNPC.SetSkill(skill); the argument word holds a float. */
int Script_cNPC_SetSkill(NpcScriptArgs* args) {
    NpcScriptWord skill;

    skill.i = args->arg1;
    cNPC_SetSkill(args->npc, skill.f);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149AE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149AE0 */

/* merge_units: begin func_00149B10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149B10 { int i; float f; void* p; unsigned char b; } ScriptArg_00149B10;

struct cNPC_00149B10 {
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
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual float SetFiringThreshold(float value); /* +0x16C */
};

/* Script native: cNPC::SetFiringThreshold(args[1]); returns the result as float bits. */
extern "C" int Script_cNPC_SetFiringThreshold(ScriptArg_00149B10* args)
{
    volatile float old;
    int part[1];
    cNPC_00149B10* npc;
    part[0] = args[1].i;
    npc = (cNPC_00149B10*)args[0].p;
    old = npc->SetFiringThreshold(*(float*)part);
    return *(int*)&old;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149B10 */

/* merge_units: begin func_00149B50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149B50 { int i; float f; void* p; unsigned char b; } ScriptArg_00149B50;

struct cNPC_00149B50 {
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
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void ForceWeaponFire(int count, float delay, int flag); /* +0x198 */
};

/* Script native: cNPC::ForceWeaponFire(args[1], args[3], args[2]); returns 0. */
extern "C" int Script_cNPC_ForceWeaponFire_3(ScriptArg_00149B50* args)
{
    int delay[1];
    int flag[1];
    int count[1];
    cNPC_00149B50* npc;
    delay[0] = args[3].i;
    flag[0] = args[2].i;
    count[0] = args[1].i;
    npc = (cNPC_00149B50*)args[0].p;
    npc->ForceWeaponFire(*(int*)count, *(float*)delay, *(int*)flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149B50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149B50 */

/* merge_units: begin func_00149BA0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149BA0 { int i; float f; void* p; unsigned char b; } ScriptArg_00149BA0;

struct cNPC_00149BA0 {
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
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void ForceWeaponFire(int count, float delay, int flag); /* +0x198 */
};

/* Script native: cNPC::ForceWeaponFire(args[1], 0, args[2]); returns 0. */
extern "C" int Script_cNPC_ForceWeaponFire_2(ScriptArg_00149BA0* args)
{
    int flag[1];
    int count[1];
    cNPC_00149BA0* npc;
    flag[0] = args[2].i;
    count[0] = args[1].i;
    npc = (cNPC_00149BA0*)args[0].p;
    npc->ForceWeaponFire(*(int*)count, 0.0f, *(int*)flag);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149BA0 */

/* merge_units: begin func_00149BF0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149BF0 { int i; float f; void* p; unsigned char b; } ScriptArg_00149BF0;

struct cNPC_00149BF0 {
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
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void ForceWeaponFire(int count, float delay, int flag); /* +0x198 */
};

/* Script native: cNPC::ForceWeaponFire(args[1], 0, -1); returns 0. */
extern "C" int Script_cNPC_ForceWeaponFire(ScriptArg_00149BF0* args)
{
    int part[1];
    cNPC_00149BF0* npc;
    part[0] = args[1].i;
    npc = (cNPC_00149BF0*)args[0].p;
    npc->ForceWeaponFire(*(int*)part, 0.0f, -1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149BF0 */

/* merge_units: begin func_00149C30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149C30 { int i; float f; void* p; unsigned char b; } ScriptArg_00149C30;

struct cNPC_00149C30 {
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
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40();
    virtual void Teleport(void* node); /* +0x10C */
};

extern "C" void* ScriptNode_Identity(void* id);

/* Script native: teleports the NPC to node args[1]. */
extern "C" int Script_Teleport(ScriptArg_00149C30* args)
{
    cNPC_00149C30* npc = (cNPC_00149C30*)args[0].p;
    npc->Teleport(ScriptNode_Identity(args[1].p));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149C30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149C30 */

/* merge_units: begin func_00149C70 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149C70 { int i; float f; void* p; } ScriptArg_00149C70;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149C70 {
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
    virtual void ResumeMovement(); /* +0x158 */
};

/* Script native: cNPC::ResumeMovement() on args[0]; returns 0. */
extern "C" int Script_cNPC_ResumeMovement(ScriptArg_00149C70* args)
{
    cNPC_00149C70* obj = (cNPC_00149C70*)args[0].p;
    obj->ResumeMovement();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149C70 */

/* merge_units: begin func_00149CA0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149CA0 {
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
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void StopMovement(float time, int priority); /* +0x154 */
};

/* Script native: cNPC::StopMovement((float)args[1], 100). Returns 0. */
extern "C" int Script_cNPC_StopMovement(ScriptArg* args)
{
    int part[1];
    cNPC_00149CA0* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149CA0*)args[0].p;
    obj->StopMovement(*(float*)part, 100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149CA0 */

/* merge_units: begin func_00149CE0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149CE0 {
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
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51();
    virtual void RequestAction(unsigned char action, int priority); /* +0x150 */
};

/* Script native: cNPC::RequestAction(args[1].b, 100) on args[0]; returns 0. */
extern "C" int Script_cNPC_RequestAction(ScriptArg* args)
{
    cNPC_00149CE0* obj = (cNPC_00149CE0*)args[0].p;
    obj->RequestAction(args[1].b, 100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149CE0 */

/* merge_units: begin func_00149D10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149D10 {
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
    virtual void v4E(); virtual void v4F();
    virtual float GetTravelSpeed(unsigned char mode); /* +0x148 */
};

/* Script native: returns cNPC::GetTravelSpeed((byte)args[1]) as raw float bits. */
extern "C" int Script_cNPC_GetTravelSpeed(ScriptArg* args)
{
    cNPC_00149D10* npc = (cNPC_00149D10*)args[0].p;
    volatile float speed = npc->GetTravelSpeed(args[1].b);
    return *(int*)&speed;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149D10 */

/* merge_units: begin func_00149D50 */
#pragma push /* merge_units */
const float D_00489DD0[4] = { 0.0f, 0.1f, 0.5f, 0.9f };

/* cNPC virtual slot 0x50: looks up a float table entry by byte index. */
float cNPC_v50(void* self, unsigned char i)
{
    return ((float*)D_00489DD0)[i];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149D50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149D50 */

/* merge_units: begin func_00149D70 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149D70 { int i; float f; void* p; unsigned char b; } ScriptArg_00149D70;

struct cNPC_00149D70 {
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
    virtual void v4E();
    virtual void ResumeAITravelSpeed(); /* +0x144 */
};

/* Script native: cNPC::ResumeAITravelSpeed() on args[0]; returns 0. */
extern "C" int Script_cNPC_ResumeAITravelSpeed(ScriptArg_00149D70* args)
{
    cNPC_00149D70* obj = (cNPC_00149D70*)args[0].p;
    obj->ResumeAITravelSpeed();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149D70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149D70 */

/* merge_units: begin func_00149DA0 */
#pragma push /* merge_units */
/* vtable slot 0x4F: ResumeAITravelSpeed (drop the scripted override). */
void cNPC_ResumeAITravelSpeed(cNPC* self) {
    self->travelSpeedOverride = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149DA0 */

/* merge_units: begin func_00149DB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149DB0 { int i; float f; void* p; unsigned char b; } ScriptArg_00149DB0;

struct cNPC_00149DB0 {
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
    virtual void SetTravelSpeed(float value); /* +0x140 */
};

/* Script native: cNPC::SetTravelSpeed(args[1]) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetTravelSpeed(ScriptArg_00149DB0* args)
{
    int part[1];
    cNPC_00149DB0* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149DB0*)args[0].p;
    obj->SetTravelSpeed(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149DB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149DB0 */

/* merge_units: begin func_00149DF0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149DF0 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C();
    virtual void ResumeAILookAt(int priority); /* +0x13C */
};

/* Script native: cNPC::ResumeAILookAt(100) on args[0]; returns 0. */
extern "C" int Script_cNPC_ResumeAILookAt(ScriptArg* args)
{
    cNPC_00149DF0* obj = (cNPC_00149DF0*)args[0].p;
    obj->ResumeAILookAt(100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149DF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149DF0 */

/* merge_units: begin func_00149E20 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149E20 { int i; float f; void* p; unsigned char b; } ScriptArg_00149E20;

struct cNPC_00149E20 {
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
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B();
    virtual void StopAndLookAround(int value); /* +0x138 */
};

/* Script native: cNPC::StopAndLookAround(100) on args[0]; returns 0. */
extern "C" int Script_cNPC_StopAndLookAround(ScriptArg_00149E20* args)
{
    cNPC_00149E20* obj = (cNPC_00149E20*)args[0].p;
    obj->StopAndLookAround(100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149E20 */

/* merge_units: begin func_00149E50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149E50 {
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
    virtual void v48(); virtual void v49(); virtual void v4A();
    virtual void LookAround(int priority); /* +0x134 */
};

/* Script native: cNPC::LookAround(100) on args[0]; returns 0. */
extern "C" int Script_cNPC_LookAround(ScriptArg* args)
{
    cNPC_00149E50* obj = (cNPC_00149E50*)args[0].p;
    obj->LookAround(100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149E50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149E50 */

/* merge_units: begin func_00149E80 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149E80 {
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
    virtual void v48();
    virtual void RequestFacial(void* target, float time, int priority); /* +0x12C */
};

#if 0 /* merge_units */
extern "C" void* GObj_IdentityB(void* handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */


/* Script native: cNPC::RequestFacial(object of args[1], (float)args[2], 100); returns 0. */
extern "C" int Script_cNPC_RequestFacial(ScriptArg* args)
{
    int time[1];
    cNPC_00149E80* npc;
    time[0] = args[2].i;
    npc = (cNPC_00149E80*)args[0].p;
    npc->RequestFacial(GObj_IdentityB(args[1].p), *(float*)time, 100);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149E80 */

/* merge_units: begin func_00149ED0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149ED0 { int i; float f; void* p; unsigned char b; } ScriptArg_00149ED0;

struct cNPC_00149ED0 {
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
    virtual void RequestLookAt(void* target, float time, int priority); /* +0x128 */
};

/* Script native: cNPC::RequestLookAt(object args[1], args[2], 100); returns 0. */
extern "C" int Script_cNPC_RequestLookAt(ScriptArg_00149ED0* args)
{
    cNPC_00149ED0* npc;
    int part[1];
    part[0] = args[2].i;
    npc = (cNPC_00149ED0*)args[0].p;
    npc->RequestLookAt(GObj_IdentityB(args[1].p), *(float*)part, 100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149ED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149ED0 */

/* merge_units: begin func_00149F20 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149F20 {
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
    virtual void v54();
    virtual void SetDesiredDistance(float minDist, float maxDist, int priority); /* +0x15C */
};

/* Script native: cNPC::SetDesiredDistance((float)args[1], (float)args[2], 100). Returns 0. */
extern "C" int Script_cNPC_SetDesiredDistance(ScriptArg* args)
{
    int maxDist[1];
    int minDist[1];
    cNPC_00149F20* obj;
    maxDist[0] = args[2].i;
    minDist[0] = args[1].i;
    obj = (cNPC_00149F20*)args[0].p;
    obj->SetDesiredDistance(*(float*)minDist, *(float*)maxDist, 100);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149F20 */

/* merge_units: begin func_00149F70 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_00149F70 {
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
    virtual void SetAggressiveness(float value); /* +0x110 */
};

/* Script native: cNPC::SetAggressiveness((float)args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cNPC_SetAggressiveness(ScriptArg* args)
{
    int part[1];
    cNPC_00149F70* obj;
    part[0] = args[1].i;
    obj = (cNPC_00149F70*)args[0].p;
    obj->SetAggressiveness(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149F70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149F70 */

/* merge_units: begin func_00149FB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149FB0 { int i; float f; void* p; unsigned char b; } ScriptArg_00149FB0;

struct cNPC_00149FB0 {
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
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void Kill(); /* +0x168 */
};

/* Script native: cNPC::Kill() on args[0]; returns 0. */
extern "C" int Script_cNPC_Kill(ScriptArg_00149FB0* args)
{
    cNPC_00149FB0* obj = (cNPC_00149FB0*)args[0].p;
    obj->Kill();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149FB0 */

/* merge_units: begin func_00149FE0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00149FE0 { int i; float f; void* p; unsigned char b; } ScriptArg_00149FE0;

struct cNPC_00149FE0 {
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
    virtual void v54(); virtual void v55();
    virtual void DeactivateDead(int value); /* +0x160 */
};

/* Script native: cNPC::DeactivateDead(args[1].i != 0) on args[0]; returns 0. */
extern "C" int Script_cNPC_DeactivateDead(ScriptArg_00149FE0* args)
{
    cNPC_00149FE0* obj = (cNPC_00149FE0*)args[0].p;
    obj->DeactivateDead(args[1].i != 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00149FE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00149FE0 */

/* merge_units: begin func_0014A010 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A010 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D();
    virtual void DeactivateForAllPlayers(); /* +0xC0 */
    char pad04[0x141 - 4];
    unsigned char flags141 : 7;
    unsigned char busy : 1; /* +0x141 bit 7 */
};

/* Script native: cNPC::DeactivateForAllPlayers() unless the +0x141 top bit is set; returns 0. */
extern "C" int Script_cNPC_DeactivateForAllPlayers(ScriptArg* args)
{
    cNPC_0014A010* npc = (cNPC_0014A010*)args[0].p;
    if (!npc->busy)
        npc->DeactivateForAllPlayers();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A010 */

/* merge_units: begin func_0014A050 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A050 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10();
    virtual void Deactivate(); /* +0x4C */
};

/* Script native: cNPC::Deactivate() on args[0]; returns 0. */
extern "C" int Script_cNPC_Deactivate_2(ScriptArg* args)
{
    cNPC_0014A050* obj = (cNPC_0014A050*)args[0].p;
    obj->Deactivate();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A050 */

/* merge_units: begin func_0014A080 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int GObj_IdentityB(int handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((int)GObj_IdentityB((void *)(a0))) /* merge_units */

extern int cNPC_Deactivate(cNPC* npc, int player);

/* Script: cNPC.Deactivate(player). */
int Script_cNPC_Deactivate(NpcScriptArgs* args) {
    cNPC* npc;
    int player;

    npc = args->npc;
    player = GObj_IdentityB(args->arg1);
    cNPC_Deactivate(npc, player);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A080 */

/* merge_units: begin func_0014A0C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A0C0 { int i; float f; void* p; unsigned char b; } ScriptArg_0014A0C0;

struct cNPC_0014A0C0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D();
    virtual void Deactivate(); /* +0xC0 */
    char pad04[0x141 - 4];
    unsigned char pad141 : 7;
    unsigned char noDeactivate : 1; /* +0x141 bit 7 */
};

/* Script native: deactivates the NPC unless its flag bit (+0x141 bit 7) is set. */
extern "C" int Script_cNPC_DeactivateAnon(ScriptArg_0014A0C0* args)
{
    cNPC_0014A0C0* npc = (cNPC_0014A0C0*)args[0].p;
    if (!npc->noDeactivate)
    npc->Deactivate();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A0C0 */

/* merge_units: begin func_0014A100 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A100 { int i; float f; void* p; unsigned char b; } ScriptArg_0014A100;

struct cNPC_0014A100 {
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
    virtual void ResumeAIAiming(); /* +0x11C */
};

/* Script native: cNPC::ResumeAIAiming() on args[0]; returns 0. */
extern "C" int Script_cNPC_ResumeAIAiming(ScriptArg_0014A100* args)
{
    cNPC_0014A100* obj = (cNPC_0014A100*)args[0].p;
    obj->ResumeAIAiming();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A100 */

/* merge_units: begin func_0014A130 */
#pragma push /* merge_units */
/* vtable slot 0x45: ResumeAIAiming. */
void cNPC_ResumeAIAiming(cNPC* self) {
    self->aimOverride = 0;
    self->aiAiming = 1;
    self->aimSubtarget = -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A130 */

/* merge_units: begin func_0014A150 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A150 {
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
    virtual void SetAimSubtarget(signed char sub); /* +0x118 */
};

/* Script native: cNPC::SetAimSubtarget(args[1].c) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetAimSubtarget(ScriptArg* args)
{
    cNPC_0014A150* obj = (cNPC_0014A150*)args[0].p;
    obj->SetAimSubtarget(args[1].c);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A150 */

/* merge_units: begin func_0014A180 */
#pragma push /* merge_units */
/* vtable slot 0x44: SetAimSubtarget. */
void cNPC_SetAimSubtarget(cNPC* self, signed char subtarget) {
    self->aimSubtarget = subtarget;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A180 */

/* merge_units: begin func_0014A190 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A190 { int i; float f; void* p; unsigned char b; } ScriptArg_0014A190;

struct cNPC_0014A190 {
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
    virtual void SetAimMode(unsigned char value); /* +0x114 */
};

/* Script native: cNPC::SetAimMode(args[1].b) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetAimMode(ScriptArg_0014A190* args)
{
    cNPC_0014A190* obj = (cNPC_0014A190*)args[0].p;
    obj->SetAimMode(args[1].b);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A190 */

/* merge_units: begin func_0014A1C0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int GObj_IdentityB(int handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((int)GObj_IdentityB((void *)(a0))) /* merge_units */

extern int NpcPerception_SetTarget(NpcAi* ai, int target, int priority);

/* Script: cNPC.ResumeAITargeting(). */
int Script_cNPC_ResumeAITargeting(NpcScriptArgs* args) {
    args->npc->ai->targetOverride = 0;
    return 0;
}

/* Script: cNPC.ClearTarget(). */
int Script_cNPC_ClearTarget(NpcScriptArgs* args) {
    NpcPerception_SetTarget(args->npc->ai, 0, 100);
    return 0;
}

/* Script: cNPC.SetTarget(gobj). */
int Script_cNPC_SetTarget(NpcScriptArgs* args) {
    int target;

    target = GObj_IdentityB(args->arg1);
    NpcPerception_SetTarget(args->npc->ai, target, 100);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A1C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A1C0 */

/* merge_units: begin func_0014A250 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A250 { int i; float f; void* p; } ScriptArg_0014A250;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A250 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void Activate(); /* +0x48 */
};

/* Script native: cNPC::Activate() on args[0]; returns 0. */
extern "C" int Script_cNPC_Activate_2(ScriptArg_0014A250* args)
{
    cNPC_0014A250* obj = (cNPC_0014A250*)args[0].p;
    obj->Activate();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A250 */

/* merge_units: begin func_0014A280 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int GObj_IdentityB(int handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((int)GObj_IdentityB((void *)(a0))) /* merge_units */

extern int NpcAi_ActivateForPlayer(cNPC* npc, int player);

/* Script: cNPC.Activate(player). */
int Script_cNPC_Activate(NpcScriptArgs* args) {
    cNPC* npc;
    int player;

    npc = args->npc;
    player = GObj_IdentityB(args->arg1);
    NpcAi_ActivateForPlayer(npc, player);
    return 0;
}

/* Script: cNPC.ActivateAnon(). */
int Script_cNPC_ActivateAnon(NpcScriptArgs* args) {
    NpcAi_ActivateForPlayer(args->npc, 0);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A280 */

/* merge_units: begin func_0014A2F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A2F0 {
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
    virtual void SendNewAwarenessOfPlayers(); /* +0xF8 */
};

/* Script native: cNPC::SendNewAwarenessOfPlayers() on args[0]; returns 0. */
extern "C" int Script_cNPC_SendNewAwarenessOfPlayers(ScriptArg* args)
{
    cNPC_0014A2F0* obj = (cNPC_0014A2F0*)args[0].p;
    obj->SendNewAwarenessOfPlayers();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A2F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A2F0 */

/* merge_units: begin func_0014A320 */
#pragma push /* merge_units */
typedef struct { char pad[0x21]; unsigned char flag : 1; unsigned char rest : 7; } Sub21;
typedef struct { char pad[0x1AC]; Sub21* sub; } Obj1AC;
/* Sets the low flag bit of the sub-object's byte at +0x21. */
void cNPC_v3C(Obj1AC* o) { o->sub->flag = 1; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A320 */

/* merge_units: begin func_0014A340 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A340 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A();
    virtual void ResendNewAwarenessMessage(void* target); /* +0xF4 */
};

#if 0 /* merge_units */
extern "C" void* GObj_IdentityB(void* handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */


/* Script native: cNPC::ResendNewAwarenessMessage(GObj_IdentityB(args[1])); returns 0. */
extern "C" int Script_cNPC_ResendNewAwarenessMessage_2(ScriptArg* args)
{
    cNPC_0014A340* npc = (cNPC_0014A340*)args[0].p;
    npc->ResendNewAwarenessMessage(GObj_IdentityB(args[1].p));
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A340 */

/* merge_units: begin func_0014A380 */
#pragma push /* merge_units */
extern int NpcPerception_ResendAwareness(NpcAi* ai, int player);

/* vtable slot 0x3B: ResendNewAwarenessMessage. */
int cNPC_ResendNewAwarenessMessage(cNPC* self, int player) {
    return NpcPerception_ResendAwareness(self->ai, player);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A380 */

/* merge_units: begin func_0014A390 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A390 { int i; float f; void* p; unsigned char b; } ScriptArg_0014A390;

struct cNPC_0014A390 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A();
    virtual void ResendNewAwarenessMessage(int value); /* +0xF4 */
};

/* Script native: cNPC::ResendNewAwarenessMessage(0) on args[0]; returns 0. */
extern "C" int Script_cNPC_ResendNewAwarenessMessage(ScriptArg_0014A390* args)
{
    cNPC_0014A390* obj = (cNPC_0014A390*)args[0].p;
    obj->ResendNewAwarenessMessage(0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A390 */

/* merge_units: begin func_0014A3C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A3C0 { int i; float f; void* p; unsigned char b; } ScriptArg_0014A3C0;

struct cNPC_0014A3C0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual void RemoveAwareness(void* target); /* +0xE8 */
};

/* Script native: removes the NPC awareness of object args[1]. */
extern "C" int Script_cNPC_RemoveAwareness(ScriptArg_0014A3C0* args)
{
    cNPC_0014A3C0* npc = (cNPC_0014A3C0*)args[0].p;
    npc->RemoveAwareness(GObj_IdentityB(args[1].p));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A3C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A3C0 */

/* merge_units: begin func_0014A400 */
#pragma push /* merge_units */
extern int NpcPerception_RemoveAwareness(NpcAi* ai, int gobj);

/* vtable slot 0x38: RemoveAwareness. */
int cNPC_RemoveAwareness(cNPC* self, int gobj) {
    return NpcPerception_RemoveAwareness(self->ai, gobj);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A400 */

/* merge_units: begin func_0014A410 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A410 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual void AddAwareness(void* target); /* +0xE4 */
};

#if 0 /* merge_units */
extern "C" void* GObj_IdentityB(void* handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */


/* Script native: cNPC::AddAwareness(GObj_IdentityB(args[1])); returns 0. */
extern "C" int Script_cNPC_AddAwareness(ScriptArg* args)
{
    cNPC_0014A410* npc = (cNPC_0014A410*)args[0].p;
    npc->AddAwareness(GObj_IdentityB(args[1].p));
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A410 */

/* merge_units: begin func_0014A450 */
#pragma push /* merge_units */
extern int NpcPerception_AddAwareness(NpcAi* ai, int gobj, int flag, float value);

/* vtable slot 0x37: AddAwareness. */
int cNPC_AddAwareness(cNPC* self, int gobj) {
    return NpcPerception_AddAwareness(self->ai, gobj, 1, 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A450 */

/* merge_units: begin func_0014A470 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A470 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void ResumeAIMode(); /* +0xE0 */
};

/* Script native: cNPC::ResumeAIMode() on args[0]; returns 0. */
extern "C" int Script_cNPC_ResumeAIMode(ScriptArg* args)
{
    cNPC_0014A470* obj = (cNPC_0014A470*)args[0].p;
    obj->ResumeAIMode();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A470 */

/* merge_units: begin func_0014A4A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A4A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetMode(unsigned char mode, void* node); /* +0xDC */
};

#if 0 /* merge_units */
extern "C" void* ScriptNode_Identity(void* handle);
#endif /* merge_units */
#define ScriptNode_Identity(a0) (ScriptNode_Identity((a0))) /* merge_units */


/* Script native: cNPC::SetMode((byte)args[1], node of args[2]); returns 0. */
extern "C" int Script_cNPC_SetMode_2(ScriptArg* args)
{
    cNPC_0014A4A0* npc;
    unsigned char mode;
    mode = args[1].b;
    npc = (cNPC_0014A4A0*)args[0].p;
    npc->SetMode(mode, ScriptNode_Identity(args[2].p));
    return 0;
}
#undef ScriptNode_Identity /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A4A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A4A0 */

/* merge_units: begin func_0014A4F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A4F0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetMode(unsigned char mode, int flag); /* +0xDC */
};

/* Script native: cNPC::SetMode(args[1].b, 0) on args[0]; returns 0. */
extern "C" int Script_cNPC_SetMode(ScriptArg* args)
{
    cNPC_0014A4F0* obj = (cNPC_0014A4F0*)args[0].p;
    obj->SetMode(args[1].b, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A4F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A4F0 */

/* merge_units: begin func_0014A520 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A520 {
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
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual unsigned char CarryBodyToNode(void* body, void* node); /* +0x108 */
};

#if 0 /* merge_units */
extern "C" void* GObj_IdentityB(void* handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */

#if 0 /* merge_units */
extern "C" void* ScriptNode_Identity(void* handle);
#endif /* merge_units */
#define ScriptNode_Identity(a0) (ScriptNode_Identity((a0))) /* merge_units */


/* Script native: returns cNPC::CarryBodyToNode(object of args[1], node of args[2]). */
extern "C" int Script_cNPC_CarryBodyToNode(ScriptArg* args)
{
    void* body;
    cNPC_0014A520* npc = (cNPC_0014A520*)args[0].p;
    body = GObj_IdentityB(args[1].p);
    return npc->CarryBodyToNode(body, ScriptNode_Identity(args[2].p));
}
#undef GObj_IdentityB /* merge_units */
#undef ScriptNode_Identity /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A520 */

/* merge_units: begin func_0014A580 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0014A580 { int i; float f; void* p; unsigned char b; } ScriptArg_0014A580;

struct cNPC_0014A580 {
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
    virtual void v3C(); virtual void v3D(); virtual void v3E();
    virtual unsigned char MoveToGobj(void* target); /* +0x104 */
};

/* Script native: orders the NPC to move to object args[1]; returns success. */
extern "C" int Script_cNPC_MoveToGobj(ScriptArg_0014A580* args)
{
    cNPC_0014A580* npc = (cNPC_0014A580*)args[0].p;
    return npc->MoveToGobj(GObj_IdentityB(args[1].p));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A580 */

/* merge_units: begin func_0014A5C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A5C0 {
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
    virtual void v3C(); virtual void v3D();
    virtual unsigned char MoveToNode(void* node); /* +0x100 */
};

#if 0 /* merge_units */
extern "C" void* ScriptNode_Identity(void* handle);
#endif /* merge_units */
#define ScriptNode_Identity(a0) (ScriptNode_Identity((a0))) /* merge_units */


/* Script native: returns cNPC::MoveToNode(node of args[1]). */
extern "C" int Script_cNPC_MoveToNode(ScriptArg* args)
{
    cNPC_0014A5C0* npc = (cNPC_0014A5C0*)args[0].p;
    return npc->MoveToNode(ScriptNode_Identity(args[1].p));
}
#undef ScriptNode_Identity /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A5C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A5C0 */

/* merge_units: begin func_0014A600 */
#pragma push /* merge_units */
extern int D_004EA3D0;          /* cAIModeChangeMsg script type */
extern int D_004EA3F0;
extern int D_004EA3F8;          /* cNPC script type */
extern char D_00555070[];       /* cNPC script filter table */
extern void Global_PlayerAddItem(int items, int item, int count);
extern int Global_PlayerGetItemCount(int items, int item);
extern void Global_PlayerRemoveItem(int items, int item, int count);
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cAI_SOBJ_getClassId(void);
extern int Actor_SetStunImmune(NpcActor* actor, int on, int a2);
extern int Actor_SetNotGasable(NpcActor* actor, int on, int a2);
extern int cNetSetFlagMsg_Send(NpcActor* actor, int on, int a2);
extern int* cGOBJTriggerEventMsg_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);
extern int* cDamageMsg_SOBJ_getClassId(void);

/* Registers the cNPC script type: base type, then the interfaces it accepts. */
int ScriptType_cNPC_Init(void) {
    int* base;
    int* iface;

    base = cAI_SOBJ_getClassId();
    ScriptType_SetParent(D_004EA3F8, *base);
    iface = cGOBJTriggerEventMsg_GetScriptTypeKeyPtr();
    ScriptType_AddAccepted(D_004EA3F8, *iface);
    ScriptType_AddAccepted(D_004EA3F8, D_004EA3D0);
    iface = cDamageMsg_SOBJ_getClassId();
    return ScriptType_AddAccepted(D_004EA3F8, *iface);
}

int NpcAi_GetIdentity(int value) {
    int word[1];

    *(int*)(char*)word = value;
    return *(int*)(char*)word;
}

void* NpcScript_GetReceiver(void* self) {
    return self;
}

int* cNPC_SOBJ_getClassId(void) {
    return &D_004EA3F0;
}

/* vtable slot 0x0B. */
int cNPC_v0B(void) {
    return D_004EA3F0;
}

/* vtable slot 0x0C: forwards to the cNPC script filter. */
int AiComponent_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* Script: cAIModeChangeMsg.GetAiMode(). */
int Script_cAIModeChangeMsg_GetAiMode(NpcAiMsg** args) {
    return args[0]->aiMode;
}

void ScriptType_cAIModeChangeMsg_Init(void) {
}

/* Returns the cAIModeChangeMsg script type. */
int cAIModeChangeMsg_v03(void) {
    return D_004EA3D0;
}

/* vtable slot 0x86: GetItemCount. */
int cNPC_GetItemCount(cNPC* self, int item) {
    NpcActor* actor;

    actor = self->actor;
    return Global_PlayerGetItemCount(actor->items, item);
}

/* vtable slot 0x85: RemoveItem. */
void cNPC_RemoveItem(cNPC* self, int item, int count) {
    NpcActor* actor;

    actor = self->actor;
    Global_PlayerRemoveItem(actor->items, item, count);
}

/* vtable slot 0x84: AddItem. */
void cNPC_AddItem(cNPC* self, int item, int count) {
    NpcActor* actor;

    actor = self->actor;
    Global_PlayerAddItem(actor->items, item, count);
}

/* vtable slot 0x83: SetNotTargetable. */
int cNPC_SetNotTargetable(cNPC* self, int on) {
    return cNetSetFlagMsg_Send(self->actor, on, 0);
}

/* vtable slot 0x82: SetNotGasable. */
int cNPC_SetNotGasable(cNPC* self, int on) {
    return Actor_SetNotGasable(self->actor, on, 0);
}

/* vtable slot 0x81: SetNotTaserable. */
int cNPC_SetNotTaserable(cNPC* self, int on) {
    return Actor_SetStunImmune(self->actor, on, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A600 */

/* merge_units: begin func_0014A770 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC_0014A770 {
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
    virtual void v3C(); virtual void v3D();
    virtual void Damage(float amount, cNPC_0014A770* source, int a, int type, int b, int c, int d); /* +0x100 */
    char pad04[0x33A5 - 4];
    unsigned char unconscious; /* +0x33A5 */
};

typedef struct NpcOwner { char pad[0x30]; cNPC_0014A770* npc; /* +0x30 */ } NpcOwner;

/* Knocks the NPC out (virtual +0x100 with type 7) unless already unconscious. */
extern "C" void cNPC_SetUnconscious(NpcOwner* self)
{
    cNPC_0014A770* npc = self->npc;
    if (!npc->unconscious)
        npc->Damage(0.0f, npc, 1, 7, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A770 */

/* merge_units: begin func_0014A7C0 */
#pragma push /* merge_units */
extern int Actor_SetDeathMotionOverride(NpcActor* actor, int a1, int a2);
extern int Goggles_SetMode(NpcActor* actor, int a1, int a2);

/* vtable slot 0x7F: SetFireInvulnerability. */
void cNPC_SetFireInvulnerability(cNPC* self, char on) {
    self->actor->fireInvulnerable = on;
}

/* vtable slot 0x7E: DontDropWeapons. */
void cNPC_DontDropWeapons(cNPC* self) {
    self->actor->weapons->dontDropWeapons = 1;
}

/* vtable slot 0x7A: EquipGoggles. */
int cNPC_EquipGoggles(cNPC* self, int a1) {
    return Goggles_SetMode(self->actor, a1, 0);
}

/* vtable slot 0x79: RequestDeathAnimation. */
int cNPC_RequestDeathAnimation(cNPC* self, int a1) {
    return Actor_SetDeathMotionOverride(self->actor, a1, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A7C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A7C0 */

/* merge_units: begin func_0014A810 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* actor; } cNPC_0014A810;
extern unsigned char g_IsMultiplayer;
extern void Actor_SetInvulnerable(void* actor, int on);
extern void NetEvent_Send(void* actor, int id, int size, unsigned char value, int a, int b, int c);
/* Sets invulnerability and replicates it when networked and not silent. */
void cNPC_SetInvulnerable(cNPC_0014A810* npc, int on, int silent)
{
    Actor_SetInvulnerable(npc->actor, on);
    if (g_IsMultiplayer && !silent)
        NetEvent_Send(npc->actor, 0x2E, 4, on, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014A810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014A810 */
