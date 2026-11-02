/*
 * Libs/SFOLib/Source/specfx: 5 files, 003EC3E0-003EC690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC3E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003EC3E0 { char vpad[20]; virtual int v0(...); };
extern "C" {
int std_list_deleter_voidPtr_erase_listdeleter(...);                     
int std_list_deleter_voidPtr_begin_void(...);                          
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);                      
int cLListIterator_cSfxSchedulerPtr_ctor(...);                        
int std_list_cSfxSchedulerPtr_end(...);                          
int std_list_cSfxSchedulerPtr_generic_iterator_ctor(...);                      
extern char D_0055C0A8;
}
extern "C" void nDynamicSfxList_Clear(void) {
    int sp3C;
    char * sp38;
    char * sp34;
    int sp30;
    int sp2C;
    int sp28;
    int sp24;
    char * temp_a0;
    char * temp_v0;
    char * var_s0;

    std_list_deleter_voidPtr_begin_void(&sp28, &D_0055C0A8);
    std_list_cSfxSchedulerPtr_generic_iterator_ctor(&sp38, &sp28);
    var_s0 = sp38;
    std_list_cSfxSchedulerPtr_end(&sp24, &D_0055C0A8);
    cLListIterator_cSfxSchedulerPtr_ctor(&sp3C, &sp24);
    if ((int)(var_s0) != (int)(sp3C)) {
        do {
            temp_a0 = (char *)(F_(var_s0, 0x8, int));
            if (temp_a0 != NULL) {
                ((VC003EC3E0 *)(temp_a0))->v0(1);
            }
            temp_v0 = var_s0;
            var_s0 = (char *)(F_(var_s0, 0x4, int));
            sp34 = temp_v0;
            std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp2C, &sp34);
            std_list_deleter_voidPtr_erase_listdeleter(&sp30, &D_0055C0A8, &sp2C);
            std_list_cSfxSchedulerPtr_end(&sp24, &D_0055C0A8);
            cLListIterator_cSfxSchedulerPtr_ctor(&sp3C, &sp24);
        } while ((int)(var_s0) != (int)(sp3C));
    }
}
static inline void merge_flush_func_003EC3E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC3E0 */

/* merge_units: begin func_003EC4C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on

struct VC003EC4C0 { char vpad[12]; unsigned char dead; char pad[7]; virtual void v0(int); virtual void v1(float); };
extern "C" {
}
extern "C" void nDynamicSfxList_NextFrame(float dt) {
    int sp5C;
    char * sp58;
    char * sp54;
    int sp50;
    int sp4C;
    int sp48;
    int sp44;
    VC003EC4C0 * obj;
    char * temp_v0;
    char * var_s0;

    std_list_deleter_voidPtr_begin_void(&sp48, &D_0055C0A8);
    std_list_cSfxSchedulerPtr_generic_iterator_ctor(&sp58, &sp48);
    var_s0 = sp58;
    std_list_cSfxSchedulerPtr_end(&sp44, &D_0055C0A8);
    cLListIterator_cSfxSchedulerPtr_ctor(&sp5C, &sp44);
    if ((int)(var_s0) != (int)(sp5C)) {
        do {
            obj = F_(var_s0, 0x8, VC003EC4C0 *);
            obj->v1(dt);
            if (obj->dead) {
                if (obj != 0) {
                    obj->v0(1);
                }
                temp_v0 = var_s0;
                var_s0 = (char *)(F_(var_s0, 0x4, int));
                sp54 = temp_v0;
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp4C, &sp54);
                std_list_deleter_voidPtr_erase_listdeleter(&sp50, &D_0055C0A8, &sp4C);
            } else {
                var_s0 = (char *)(F_(var_s0, 0x4, int));
            }
            std_list_cSfxSchedulerPtr_end(&sp44, &D_0055C0A8);
            cLListIterator_cSfxSchedulerPtr_ctor(&sp5C, &sp44);
        } while ((int)(var_s0) != (int)(sp5C));
    }
}
static inline void merge_flush_func_003EC4C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC4C0 */

/* merge_units: begin func_003EC5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
class OC5E0 {
public:
    int m0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct NC5E0 { int m0; NC5E0* next; OC5E0** data; };
extern "C" {
#if 0 /* merge_units */
void std_list_deleter_voidPtr_begin_void(int* out, void* list);
#endif /* merge_units */

#if 0 /* merge_units */
void std_list_tItemPtr_generic_iterator_ctor(NC5E0** out, int* in);
#endif /* merge_units */
Word* std_list_tItemPtr_generic_iterator_ctor(Word* dst, Word* src); /* merge_units */
#define std_list_tItemPtr_generic_iterator_ctor(a0, a1) ((void)std_list_tItemPtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_tItemPtr_end(int* out, void* list);
#endif /* merge_units */
void std_list_tItemPtr_end(Iter* out, Tree* t); /* merge_units */
#define std_list_tItemPtr_end(a0, a1) (std_list_tItemPtr_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cLListIterator_tItemPtr_ctor(NC5E0** out, int* in);
#endif /* merge_units */
Word* cLListIterator_tItemPtr_ctor(Word* dst, Word* src); /* merge_units */
#define cLListIterator_tItemPtr_ctor(a0, a1) ((void)cLListIterator_tItemPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

}
extern "C" void cSfxScheduler_Render(void* self)
{
    NC5E0* e;
    NC5E0* it;
    int t1;
    int t2;
    NC5E0* n;
    std_list_deleter_voidPtr_begin_void(&t1, self);
    std_list_tItemPtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_tItemPtr_end(&t2, self), cLListIterator_tItemPtr_ctor(&e, &t2), n != e; n = n->next)
        (*n->data)->v4();
}
#undef std_list_tItemPtr_generic_iterator_ctor /* merge_units */
#undef std_list_tItemPtr_end /* merge_units */
#undef cLListIterator_tItemPtr_ctor /* merge_units */
static inline void merge_flush_func_003EC5E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC5E0 */

/* merge_units: begin func_003EC690 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */


Word* cLListIterator_tItemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_tItemPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_tItemPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003EC690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC690 */

/* merge_units: begin func_003EC6C0 */
#pragma push /* merge_units */
typedef struct { int busy; int pad4; int pad8; unsigned char done; char padD[3]; float time; } OC6C0;
extern void cSfxScheduler_UpdateItemList(OC6C0* a, OC6C0* b);
void cSfxScheduler_NextFrame(OC6C0* s, float dt) {
    s->time += dt;
    cSfxScheduler_UpdateItemList(s, s);
    if (s->busy == 0) s->done = 1;
}
static inline void merge_flush_func_003EC6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC6C0 */
