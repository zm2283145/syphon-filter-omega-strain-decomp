/*
 * main/materialProperties: 4 files, 0040A070-0040A290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040A070 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char d[0x38]; } E124;
typedef struct { char base[0xC]; E124 e[5]; } T124;
extern void cString_opAssign(T124* d, const T124* s);
extern void cMaterialProperties_MatPropInfo_opAssign(E124* d, const E124* s);
static inline void t124_assign(T124* d, const T124* s) {
    E124* a;
    const E124* b;
    cString_opAssign(d, s);
    a = d->e;
    b = s->e;
    do {
        cMaterialProperties_MatPropInfo_opAssign(a, b);
        a++;
        b++;
    } while (a != d->e + 5);
}/* Copies [first, last) backward so it ends at result. */
T124* std_copy_backward_cMaterialProperties_copy_backward(T124* first, T124* last, T124* result) {
    while (first < last) {
        --last;
        --result;
        t124_assign(result, last);
    }
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040A070 */

/* merge_units: begin func_0040A110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"
extern "C" void String_Reserve(ShortStr* self, unsigned int n);
struct V40A110 { int a, b, c; };
extern "C" V40A110* cString_ctor_cStringR(V40A110* dst, const V40A110* src);
struct E40A110 { V40A110 a; int b; int c; V40A110 d; V40A110 e; int f; float g; char h; };
struct S40A110 { ShortStr s; E40A110 e[5]; };
extern "C" S40A110* cMaterialProperties_ctor(S40A110* self, const S40A110* src)
{
    E40A110* d;
    const E40A110* s;
    if (!ShortStr_IsLong(&src->s)) {
        self->s = src->s;
    } else {
        self->s.u.l.word = 0;
        self->s.u.l.length = 0;
        self->s.u.l.data = 0;
        String_Reserve(&self->s, src->s.u.l.length);
        ShortStrIterTag tag;
        String_Replace(&self->s, 0, 0, src->s.u.l.data, src->s.u.l.data + src->s.u.l.length, tag);
    }
    d = self->e;
    s = src->e;
    do {
        cString_ctor_cStringR(&d->a, &s->a);
        d->b = s->b;
        d->c = s->c;
        cString_ctor_cStringR(&d->d, &s->d);
        cString_ctor_cStringR(&d->e, &s->e);
        d->f = s->f;
        d->g = s->g;
        d->h = s->h;
        d++;
        s++;
    } while (d != self->e + 5);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040A110 */

/* merge_units: begin func_0040A210 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_004BEC88[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(std_vector_deleter_cMaterialProperties_dtor, std_vector_deleter_cMaterialProperties_clear, opDelete_cMaterialPropertiesP_int_bool_charP_etc, D_004BEC88)
#pragma pop /* merge_units */
/* merge_units: end func_0040A210 */

/* merge_units: begin func_0040A290 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void __destroy_array(void* p, void* dtor, int size, int n);
void cMaterialProperties_MatPropInfo_dtor(void);
void String_Dtor_138350(void* self, int flags);
}
extern "C" void opDelete_cMaterialPropertiesP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            __destroy_array((char*)allocation + 0xC, (void*)cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
            String_Dtor_138350(allocation, -1);
        }
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040A290 */
