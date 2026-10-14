/*
 * main/game: 4 files, 0013D940-0013DA50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013D940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0013D940(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D940 */

/* merge_units: begin func_0013D950 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Nd_D950 { struct Nd_D950* prev; struct Nd_D950* next; int obj; } Nd_D950;
struct It_D950 { Nd_D950* n; It_D950() {} void operator=(const It_D950& o) { const float* s = (const float*)&o; float* d = (float*)this; *d = *s; } };
extern "C" {
void func_0013B180(It_D950*, int);
void func_0013B160(It_D950*, int);
#if 0 /* merge_units */
void func_0013D940(It_D950*, It_D950*);
#endif /* merge_units */
#define func_0013D940(a0, a1) ((void)func_0013D940((Word *)(a0), (Word *)(a1))) /* merge_units */

int World_DrawPass(int);
}
/* run World_DrawPass over every entry of the list (begin/end iterators) */
#pragma push
#pragma opt_propagation off
extern "C" void func_0013D950(int l)
{
    It_D950 it;
    It_D950 tmp;
    It_D950 b;
    It_D950 e;
    It_D950 t1;
    It_D950 t2;
    Nd_D950* n;
    func_0013B180(&t1, l);
    func_0013D940(&b, &t1);
    n = b.n;
    func_0013B160(&t2, l);
    func_0013D940(&e, &t2);
    tmp.n = n;
    n = e.n;
    it = tmp;
    /* the iterator lives in memory: every access reloads it (volatile view) */
#define IT (((volatile It_D950*)&it)->n)
    while (IT != n) {
        World_DrawPass(IT->obj);
        IT = IT->next;
    }
#undef IT
}
#pragma pop
#undef func_0013D940 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013D950 */

/* merge_units: begin func_0013D9F0 */
#pragma push /* merge_units */
typedef struct { char b[0xC]; } ScalarCollection;
extern signed char D_004EA100;
extern int D_004EA108;
extern ScalarCollection D_004EA118;
extern void ScalarCollection_Init(ScalarCollection* c);
extern void func_0013DAD0(void);
extern void __register_global_object(void* obj, void* dtor, void* link);

/* Returns the lazily constructed static collection at D_004EA118. */
ScalarCollection* func_0013D9F0(void)
{
    if (D_004EA100 == 0) {
        ScalarCollection_Init(&D_004EA118);
        __register_global_object(&D_004EA118, func_0013DAD0, &D_004EA108);
        D_004EA100 = 1;
    }
    return &D_004EA118;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D9F0 */

/* merge_units: begin func_0013DA50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_0013DA50)
#pragma pop /* merge_units */
/* merge_units: end func_0013DA50 */
