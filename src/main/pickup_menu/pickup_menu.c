/*
 * main/pickup_menu: 2 files, 00251040-00251060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00251040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "pickup_menu_types.h"

extern char D_004F7E70[];
extern float func_003D0810(PickupMenu* self, char* arg);

float func_00251040(PickupMenu* self) {
    self->unk10 = 1;
    self->unk11 = 1;
    return func_003D0810(self, D_004F7E70);
}
#pragma pop /* merge_units */
/* merge_units: end func_00251040 */

/* merge_units: begin func_00251060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Model_251060 { char pad[0x74]; int x74; };
struct Self_251060 { signed char kind; char pad1[3]; int id; int x8; void* a; void* b; Model_251060* m1; Model_251060* m2; };
extern "C" {
extern int D_004F7E90;
extern int D_004F7E98;
extern int D_0048AEF8;
extern char D_004A7998[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Model_251060* func_003EF010(int h);
void func_003F45A0(float t, Model_251060* m);
void func_003F44E0(float t, Model_251060* m);
#if 0 /* merge_units */
void func_00251040(int x);
#endif /* merge_units */
#define func_00251040(a0) ((void)func_00251040((PickupMenu *)(a0))) /* merge_units */

void* func_00259420(void* p);
void func_003EEBE0(int h, int a, int b);
}
extern "C" void func_00251060(Self_251060* s, signed char kind, int id, int t)
{
    void* p;
    s->kind = kind;
    s->id = id;
    s->x8 = 0;
    s->m1 = func_003EF010(D_004F7E90);
    func_003F45A0(t, s->m1);
    func_003F44E0(t + D_0048AEF8, s->m1);
    func_00251040(s->m1->x74);
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x68, D_004A7998, 0x352);
    }
    if (p)
        p = func_00259420(p);
    s->a = p;
    if (t) {
        func_003EEBE0(D_004F7E98, 0, 1);
        return;
    }
    func_003EEBE0(D_004F7E98, 1, 1);
    s->m2 = func_003EF010(D_004F7E98);
    func_003F45A0(t, s->m2);
    func_003F44E0(t + D_0048AEF8, s->m2);
    func_00251040(s->m2->x74);
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x68, D_004A7998, 0x35D);
    }
    if (p)
        p = func_00259420(p);
    s->b = p;
}
#undef func_00251040 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251060 */
