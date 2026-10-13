/*
 * main/GobjMan: 5 files, 0040C1E0-0040C460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040C1E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc
 */

#include "types.h"
#include "GobjMan_types.h"

/* Address of the vector's data pointer. */
int** IdVec_DataRef(PtrVec* v) {
    return &v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C1E0 */

/* merge_units: begin func_0040C1F0 */
#pragma push /* merge_units */
extern char g_GobjIdText[];
extern int sprintf(char* buf, const char* fmt, ...);

/* Formats an id as "(category index)" into a static buffer and returns it. */
char* Object_ToString(GobjId* id)
{
    sprintf(g_GobjIdText, "(%d %d)", (id->word & 0xFF0000) >> 16, id->word & 0xFFFF);
    return g_GobjIdText;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C1F0 */

/* merge_units: begin func_0040C240 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int IdMgr_FindCollision(int category, int index);
/* Next index per category (256 counters). */
extern char g_GobjIdCounters;

/*
 * Allocates a fresh id in a category: bumps the category's counter (wrapping
 * after 0xFFFF) until no visible object uses the index.
 */
void IdMgr_Allocate(GobjId* out, int category) {
    int next;
    int* counter;
    int cat;

    cat = category & 0xFF;
    counter = (int*)(&g_GobjIdCounters + (cat * 4));
    do {
        next = *counter + 1;
        *counter = next;
        if (next > 0xFFFF) {
            *counter = 0;
        }
    } while (IdMgr_FindCollision(cat, *counter) != 0);
    out->word = *counter | (cat << 0x10);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C240 */

/* merge_units: begin func_0040C2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BECA8[]; /* "GobjMan.cc" */
extern GobjScope* g_GobjRootScope;
extern GobjScope* g_GobjWorldScope;
#if 0 /* merge_units */
extern int g_GobjIdCounters[256];
#endif /* merge_units */
#define g_GobjIdCounters ((int*)&g_GobjIdCounters) /* merge_units */

void* Mem_Alloc(int, int, char*, int);
void GobjScopeBase_Ctor(GobjScope* self, int capacity, GobjScope* parent);
}
static inline void* AllocL_n1(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
/* Creates the root and world scopes and resets the per-category id counters. */
extern "C" void IdMgr_Init(void)
{
    int i;
    GobjScope* scope;
    scope = (GobjScope*)AllocL_n1(sizeof(GobjScope), D_004BECA8, 0xCF);
    if (scope) {
        GobjScopeBase_Ctor(scope, 4500, 0);
    }
    g_GobjRootScope = scope;
    scope = (GobjScope*)AllocL_n1(sizeof(GobjScope), D_004BECA8, 0xD0);
    if (scope) {
        GobjScopeBase_Ctor(scope, 2500, g_GobjRootScope);
    }
    g_GobjWorldScope = scope;
    for (i = 0; i < 256; i++) {
        g_GobjIdCounters[i] = 0;
    }
}
#undef g_GobjIdCounters /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C2D0 */
/* merge_units: begin func_0040C460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: scope chain accessors used by the script object lookup.
 */


GobjScope* Scope_GetParent(GobjScope* self) {
    return self->parent;
}

GobjScope* Object_GetScope(GobjEntry* self) {
    return self->scope;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C460 */
