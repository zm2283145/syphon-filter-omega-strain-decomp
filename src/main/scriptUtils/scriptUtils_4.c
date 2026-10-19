/*
 * main/scriptUtils: 2 files, 002683B0-002683F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002683B0 */
#pragma push /* merge_units */
#include "types.h"

extern void* g_Hud;
extern void Hud_ShowCallout(void* mgr, void* target, int id, int a3, int a4, int a5, float delay, float a7);

/* Registers a callout for obj (at +0xC) with id, delay (seconds as int) and extra value. */
void Global_SetCallout(char* obj, int id, int delay, int extra)
{
    Hud_ShowCallout(g_Hud, obj + 0xC, id, 0, 0, extra, (float)delay, 0.0f);
}
#pragma pop /* merge_units */
/* merge_units: end func_002683B0 */

/* merge_units: begin func_002683F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* func_002683F0: release every scripted object and every script array, then empty both global lists */
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004A82B8[];
}
/* script array: frees its data buffer */
struct SgArr {
    void* data;
    void Destroy() { void* d = data; AllocGuard g2; Mem_Free(0, d, D_004A82B8, 0x12D); }
};
typedef struct SgNode { struct SgNode* prev; struct SgNode* next; void* e; } SgNode;
typedef struct { SgNode* n; } SgIt;
typedef struct { int pad; SgNode header; } SgList;
extern "C" {
extern SgList D_004F83C0;
extern SgList D_004F83E0;
void List_Begin(SgIt* out, SgList* l);
SgIt* func_002686D0(SgIt* dst, SgIt* src);
void func_002686C0(SgIt* out, SgList* l);
SgIt* func_002686B0(SgIt* dst, SgIt* src);
SgIt* func_002686A0(SgIt* dst, SgIt* src);
void func_00268690(SgIt* out, SgList* l);
SgIt* func_00268680(SgIt* dst, SgIt* src);
void ObjectList_EraseRange(SgIt* out, SgList* l, SgIt* first, SgIt* last);
void Object_Unregister(void* o);
void Object_DeleteLater(void* o, float t);
void func_002683F0(void);
}
static inline void Begin1(SgIt* out, SgList* l) { SgIt b; List_Begin(&b, l); func_002686D0(out, &b); }
static inline void End1(SgIt* out, SgList* l) { SgIt t; func_002686C0(&t, l); func_002686B0(out, &t); }
static inline void Begin2(SgIt* out, SgList* l) { SgIt b; List_Begin(&b, l); func_002686A0(out, &b); }
static inline void End2(SgIt* out, SgList* l) { SgIt t; func_00268690(&t, l); func_00268680(out, &t); }
static inline void Begin1x(SgIt* out, SgList* l) { Begin1(out, l); }
static inline void End1x(SgIt* out, SgList* l) { End1(out, l); }
static inline void Begin2x(SgIt* out, SgList* l) { Begin2(out, l); }
static inline void End2x(SgIt* out, SgList* l) { End2(out, l); }
void func_002683F0(void)
{
    SgIt end;
    SgIt end2;
    SgIt it;
    SgIt it2;
    SgArr* a;
    SgNode* n;
    Begin1x(&it, &D_004F83C0);
    for (n = it.n; End1x(&end, &D_004F83C0), n != end.n; n = n->next) {
        Object_Unregister(n->e);
        Object_DeleteLater(n->e, 0.1f);
    }
    Begin2x(&it2, &D_004F83E0);
    for (n = it2.n; End2x(&end2, &D_004F83E0), n != end2.n; ) {
        a = (SgArr*)n->e;
        n = n->next;
        AllocGuard g;
        if (a) a->Destroy();
        Mem_Free(0, a, D_004A82B8, 0x1E7);
    }
    SgIt r;
    SgIt first;
    SgIt last;
    last.n = &D_004F83C0.header;
    first.n = D_004F83C0.header.next;
    ObjectList_EraseRange(&r, &D_004F83C0, &first, &last);
    SgIt r2;
    SgIt first2;
    SgIt last2;
    last2.n = &D_004F83E0.header;
    first2.n = D_004F83E0.header.next;
    ObjectList_EraseRange(&r2, &D_004F83E0, &first2, &last2);
}
#pragma pop /* merge_units */
/* merge_units: end func_002683F0 */
