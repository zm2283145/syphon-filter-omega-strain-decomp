/*
 * SFOGame/Source/scene: 5 files, 0013D8A0-0013D940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin game_13D8A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct Nd_D8A0 { struct Nd_D8A0* prev; struct Nd_D8A0* next; int obj; } Nd_D8A0;
struct It_D8A0 { Nd_D8A0* n; It_D8A0() {} void operator=(const It_D8A0& o) { const float* s = (const float*)&o; float* d = (float*)this; *d = *s; } };
extern "C" {
#if 0 /* merge_units */
void std_list_deleter_voidPtr_begin_void(It_D8A0*, int);
#endif /* merge_units */
void std_list_deleter_voidPtr_begin_void(void*, int); /* merge_units */
#define std_list_deleter_voidPtr_begin_void(a0, a1) (std_list_deleter_voidPtr_begin_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_deleter_voidPtr_end_void(It_D8A0*, int);
#endif /* merge_units */
void std_list_deleter_voidPtr_end_void(void*, int); /* merge_units */
#define std_list_deleter_voidPtr_end_void(a0, a1) (std_list_deleter_voidPtr_end_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_cScenePtr_generic_iterator_ctor(It_D8A0*, It_D8A0*);
#endif /* merge_units */
Word* std_list_cScenePtr_generic_iterator_ctor(Word* dst, Word* src); /* merge_units */
#define std_list_cScenePtr_generic_iterator_ctor(a0, a1) ((void)std_list_cScenePtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

int cScene_UpdateActivation(int);
}
/* run cScene_UpdateActivation over every entry of the list (begin/end iterators) */
#pragma push
#pragma opt_propagation off
extern "C" void cSceneManager_UpdateActivation(int l)
{
    It_D8A0 it;
    It_D8A0 tmp;
    It_D8A0 b;
    It_D8A0 e;
    It_D8A0 t1;
    It_D8A0 t2;
    Nd_D8A0* n;
    std_list_deleter_voidPtr_begin_void(&t1, l);
    std_list_cScenePtr_generic_iterator_ctor(&b, &t1);
    n = b.n;
    std_list_deleter_voidPtr_end_void(&t2, l);
    std_list_cScenePtr_generic_iterator_ctor(&e, &t2);
    tmp.n = n;
    n = e.n;
    it = tmp;
    /* the iterator lives in memory: every access reloads it (volatile view) */
#define IT (((volatile It_D8A0*)&it)->n)
    while (IT != n) {
        cScene_UpdateActivation(IT->obj);
        IT = IT->next;
    }
#undef IT
}
#pragma pop
#undef std_list_deleter_voidPtr_begin_void /* merge_units */
#undef std_list_deleter_voidPtr_end_void /* merge_units */
#undef std_list_cScenePtr_generic_iterator_ctor /* merge_units */
static inline void merge_flush_game_13D8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_13D8A0 */

/* merge_units: begin func_0013D940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* std_list_cScenePtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0013D940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013D940 */

/* merge_units: begin func_0013D950 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Nd_D950 { struct Nd_D950* prev; struct Nd_D950* next; int obj; } Nd_D950;
struct It_D950 { Nd_D950* n; It_D950() {} void operator=(const It_D950& o) { const float* s = (const float*)&o; float* d = (float*)this; *d = *s; } };
extern "C" {
#if 0 /* merge_units */
void std_list_deleter_voidPtr_begin_void(It_D950*, int);
#endif /* merge_units */
#define std_list_deleter_voidPtr_begin_void(a0, a1) (std_list_deleter_voidPtr_begin_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_deleter_voidPtr_end_void(It_D950*, int);
#endif /* merge_units */
#define std_list_deleter_voidPtr_end_void(a0, a1) (std_list_deleter_voidPtr_end_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_cScenePtr_generic_iterator_ctor(It_D950*, It_D950*);
#endif /* merge_units */
#define std_list_cScenePtr_generic_iterator_ctor(a0, a1) ((void)std_list_cScenePtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */


int cScene_Render(int);
}
/* run cScene_Render over every entry of the list (begin/end iterators) */
#pragma push
#pragma opt_propagation off
extern "C" void cSceneManager_Render(int l)
{
    It_D950 it;
    It_D950 tmp;
    It_D950 b;
    It_D950 e;
    It_D950 t1;
    It_D950 t2;
    Nd_D950* n;
    std_list_deleter_voidPtr_begin_void(&t1, l);
    std_list_cScenePtr_generic_iterator_ctor(&b, &t1);
    n = b.n;
    std_list_deleter_voidPtr_end_void(&t2, l);
    std_list_cScenePtr_generic_iterator_ctor(&e, &t2);
    tmp.n = n;
    n = e.n;
    it = tmp;
    /* the iterator lives in memory: every access reloads it (volatile view) */
#define IT (((volatile It_D950*)&it)->n)
    while (IT != n) {
        cScene_Render(IT->obj);
        IT = IT->next;
    }
#undef IT
}
#pragma pop
#undef std_list_deleter_voidPtr_begin_void /* merge_units */
#undef std_list_deleter_voidPtr_end_void /* merge_units */
#undef std_list_cScenePtr_generic_iterator_ctor /* merge_units */
static inline void merge_flush_func_0013D950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013D950 */

/* merge_units: begin func_0013D9F0 */
#pragma push /* merge_units */
typedef struct { char b[0xC]; } ScalarCollection;
extern signed char D_004EA100;
extern int D_004EA108;
extern ScalarCollection D_004EA118;
extern void std_list_deleter_voidPtr_ctor_void(ScalarCollection* c);
extern void cSceneManager_dtor(void);
extern void __register_global_object(void* obj, void* dtor, void* link);

/* Returns the lazily constructed static collection at D_004EA118. */
ScalarCollection* GetSceneManager(void)
{
    if (D_004EA100 == 0) {
        std_list_deleter_voidPtr_ctor_void(&D_004EA118);
        __register_global_object(&D_004EA118, cSceneManager_dtor, &D_004EA108);
        D_004EA100 = 1;
    }
    return &D_004EA118;
}
static inline void merge_flush_func_0013D9F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013D9F0 */

/* merge_units: begin func_0013DA50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cScenePtr_dtor)
static inline void merge_flush_func_0013DA50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013DA50 */
