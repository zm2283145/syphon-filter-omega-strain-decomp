/*
 * main/scriptUtils: 2 files, 002683B0-002683F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002683B0 */
#pragma push /* merge_units */
#include "types.h"

extern void* g_Hud;
extern void cHud_SetCallout(void* mgr, void* target, int id, int a3, int a4, int a5, float delay, float a7);

/* Registers a callout for obj (at +0xC) with id, delay (seconds as int) and extra value. */
void nScriptUtils_SetCallout_cGOBJP_charP_int_bool(char* obj, int id, int delay, int extra)
{
    cHud_SetCallout(g_Hud, obj + 0xC, id, 0, 0, extra, (float)delay, 0.0f);
}
#pragma pop /* merge_units */
/* merge_units: end func_002683B0 */

/* merge_units: begin func_002683F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* nScriptUtils_Reset: release every scripted object and every script array, then empty both global lists */
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern char D_004A82B8[];
}
/* script array: frees its data buffer */
struct SgArr {
    void* data;
    void Destroy() { void* d = data; AllocGuard g2; cMemMan_Deallocate(0, d, D_004A82B8, 0x12D); }
};
typedef struct SgNode { struct SgNode* prev; struct SgNode* next; void* e; } SgNode;
typedef struct { SgNode* n; } SgIt;
typedef struct { int pad; SgNode header; } SgList;
extern "C" {
extern SgList D_004F83C0;
extern SgList D_004F83E0;
void std_list_deleter_voidPtr_begin_void(SgIt* out, SgList* l);
SgIt* std_list_cNodeListPtr_generic_iterator_ctor(SgIt* dst, SgIt* src);
void std_list_cNodeListPtr_end(SgIt* out, SgList* l);
SgIt* cLListIterator_cNodeListPtr_ctor(SgIt* dst, SgIt* src);
SgIt* std_list_ArrayPtr_generic_iterator_ctor(SgIt* dst, SgIt* src);
void std_list_ArrayPtr_end(SgIt* out, SgList* l);
SgIt* cLListIterator_ArrayPtr_ctor_listR(SgIt* dst, SgIt* src);
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(SgIt* out, SgList* l, SgIt* first, SgIt* last);
void nGobjManager_RemoveGOBJ(void* o);
void cSystem_ActualScheduleDelete(void* o, float t);
void nScriptUtils_Reset(void);
}
static inline void Begin1(SgIt* out, SgList* l) { SgIt b; std_list_deleter_voidPtr_begin_void(&b, l); std_list_cNodeListPtr_generic_iterator_ctor(out, &b); }
static inline void End1(SgIt* out, SgList* l) { SgIt t; std_list_cNodeListPtr_end(&t, l); cLListIterator_cNodeListPtr_ctor(out, &t); }
static inline void Begin2(SgIt* out, SgList* l) { SgIt b; std_list_deleter_voidPtr_begin_void(&b, l); std_list_ArrayPtr_generic_iterator_ctor(out, &b); }
static inline void End2(SgIt* out, SgList* l) { SgIt t; std_list_ArrayPtr_end(&t, l); cLListIterator_ArrayPtr_ctor_listR(out, &t); }
static inline void Begin1x(SgIt* out, SgList* l) { Begin1(out, l); }
static inline void End1x(SgIt* out, SgList* l) { End1(out, l); }
static inline void Begin2x(SgIt* out, SgList* l) { Begin2(out, l); }
static inline void End2x(SgIt* out, SgList* l) { End2(out, l); }
void nScriptUtils_Reset(void)
{
    SgIt end;
    SgIt end2;
    SgIt it;
    SgIt it2;
    SgArr* a;
    SgNode* n;
    Begin1x(&it, &D_004F83C0);
    for (n = it.n; End1x(&end, &D_004F83C0), n != end.n; n = n->next) {
        nGobjManager_RemoveGOBJ(n->e);
        cSystem_ActualScheduleDelete(n->e, 0.1f);
    }
    Begin2x(&it2, &D_004F83E0);
    for (n = it2.n; End2x(&end2, &D_004F83E0), n != end2.n; ) {
        a = (SgArr*)n->e;
        n = n->next;
        AllocGuard g;
        if (a) a->Destroy();
        cMemMan_Deallocate(0, a, D_004A82B8, 0x1E7);
    }
    SgIt r;
    SgIt first;
    SgIt last;
    last.n = &D_004F83C0.header;
    first.n = D_004F83C0.header.next;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, &D_004F83C0, &first, &last);
    SgIt r2;
    SgIt first2;
    SgIt last2;
    last2.n = &D_004F83E0.header;
    first2.n = D_004F83E0.header.next;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r2, &D_004F83E0, &first2, &last2);
}
#pragma pop /* merge_units */
/* merge_units: end func_002683F0 */
