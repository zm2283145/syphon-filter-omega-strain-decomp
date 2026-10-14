/*
 * main/node: range (5 files, 0015BE80-0015C080)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "node_types.h"

/* merge_units: begin func_0015BE80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNode virtual slots: position getters and default (empty) handlers.
 */


extern int ActorObj_BuildNodeMatrix(void* a0, cNode* node);

int cNode_v34(void* a0, cNode* node) {
    return ActorObj_BuildNodeMatrix(a0, node);
}

/* v35..v37: write the node translation as a point (w = 1). */
void cNode_v35(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

void cNode_v36(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

void cNode_v37(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

int cNode_v38(void* a0, cNode* node) {
    return ActorObj_BuildNodeMatrix(a0, node);
}

int cNode_v39(void* a0, cNode* node) {
    return ActorObj_BuildNodeMatrix(a0, node);
}

int cNode_v3B(void* a0, cNode* node) {
    return ActorObj_BuildNodeMatrix(a0, node);
}

void cNode_v0E(void) {
}

void cNode_v0F(void) {
}

void Actor_VirtualNop(void) {
}

void Node_SetFlag2C(cNode* self) {
    self->flag2C = 1;
}

void Node_ClearFlag2C(cNode* self) {
    self->flag2C = 0;
}

unsigned char Node_GetFlag2C(cNode* self) {
    return self->flag2C;
}

int func_0015BFB0(void) {
    return 0;
}

void func_0015BFC0(void) {
}

int func_0015BFD0(void) {
    return 0;
}

int func_0015BFE0(void) {
    return 0;
}

int func_0015BFF0(void) {
    return 0;
}

void func_0015C000(void) {
}

int func_0015C010(void) {
    return 0;
}

int func_0015C020(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015BE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015BE80 */

/* merge_units: begin func_0015C030 */
#pragma push /* merge_units */
/* Returns 1.0f. */
float func_0015C030(void)
{
    return 1.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C030 */

/* merge_units: begin func_0015C040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_0015C040(void) {
    return 0;
}

int func_0015C050(void) {
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C040 */

/* merge_units: begin func_0015C060 */
#pragma push /* merge_units */
typedef struct Object { char pad[0x58]; struct Object* attached; } Object;

/* Returns the object's attached object, or the object itself when none. */
Object* Object_GetAttachedOrSelf(Object* o)
{
    if (o->attached)
        return o->attached;
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C060 */

/* merge_units: begin func_0015C080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNode script type registration and small helpers.
 */


extern int D_004EA778; /* cNode script type key */
extern int D_004EA780; /* cNode script type id */
extern char D_00555070[]; /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void); /* address of the cGObj type key */
extern void ScriptType_SetParent(int type, int parentType);

void func_0015C080(void) {
}

int func_0015C090(void) {
    return 1;
}

int func_0015C0A0(void) {
    return 0;
}

/* IsType(object, mask): nonzero when the object's type bits intersect mask. */
int Script_cNode_IsType(NodeScriptArg* args) {
    NodeScriptObj* obj = args[0].p;
    return (unsigned int)(args[1].u16 & obj->typeMask) > 0u;
}

/* cNode derives from cGObj. */
void ScriptType_cNode_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004EA780, *parent);
}

/* volatile mirrors the original stack temporary. */
int cNode_Identity(int value) {
    volatile int tmp = value;
    return tmp;
}

void* func_0015C120(void* self) {
    return self;
}

int* func_0015C130(void) {
    return &D_004EA778;
}

int cNode_v0B(void) {
    return D_004EA778;
}

int cNode_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C080 */
