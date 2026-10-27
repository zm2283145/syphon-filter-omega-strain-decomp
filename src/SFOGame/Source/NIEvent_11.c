/*
 * SFOGame/Source/NIEvent: 1 file, 00239CF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00239CF0 */
#pragma push /* merge_units */
/* NiEvent float track init: one key {0, f, 0, 0}; value-initialised Key temporaries give the byte-zero loops. */
#include "types.h"
#pragma cplusplus on
struct Key_239CF0 { float a; float t; float c; float d; };
struct Vec_239CF0 {
    int capacity; int count; Key_239CF0* data;
};
struct Track_239CF0 {
    float cur;
    Vec_239CF0 keys;
    int pad10;
    int w14;
    int w18;
    unsigned char b1C;
};
extern "C" void std_vector_imp_FloatKey_resize(Vec_239CF0* v, unsigned int n, const Key_239CF0& value);
static inline void Assign_239CF0(Vec_239CF0* v, unsigned int n, const Key_239CF0& fill = Key_239CF0()) { std_vector_imp_FloatKey_resize(v, 0, Key_239CF0()); std_vector_imp_FloatKey_resize(v, n, fill); }
extern "C" void cNIEventFloatTrack_Init_float(Track_239CF0* self, float f)
{
    Assign_239CF0(&self->keys, 1);
    self->keys.data[0].a = 0;
    self->keys.data[0].t = f;
    self->keys.data[0].c = 0;
    self->keys.data[0].d = 0;
    self->w14 = -1;
    self->b1C = 0;
    self->cur = f;
    self->w18 = 0;
    {
        Key_239CF0** pd = &self->keys.data;
        if (self->keys.count > 0)
            self->cur = (*pd)[0].t;
    }
}
static inline void merge_flush_func_00239CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00239CF0 */
