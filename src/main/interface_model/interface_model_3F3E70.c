/*
 * main/interface_model: range (2 files, 003F3E70-003F3FC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003F3E70 */
#pragma push /* merge_units */
/* IeScalarTrack_Construct: piecewise-linear curve evaluation (interface_model area). */
typedef struct { float t; float v; } Key;
typedef struct {
    char pad0[0x18];
    int cur;
    float* out;
    char pad20[4];
    int count;
    Key* keys;
} Curve;

static inline Key* KeyAt(Key* k, int i) { return &k[i]; }
static inline Key* Last(Curve* c) { return c->keys + c->count - 1; }

#pragma opt_strength_reduction off
#pragma opt_propagation off
void IeScalarTrack_Construct(Curve* c, float t)
{
    /* Local declaration order matters for register allocation.
     * `cc` (an un-propagated alias of c) makes the second scan loop reload
     * keys from memory each iteration, as retail does. */
    Curve* cc = c;
    int i;
    Key* keys;
    Key** pk;
    if (*(volatile int*)&c->count > 0) {
        pk = &c->keys;
        keys = c->keys;
        if (t <= KeyAt(keys, 0)->t) {
            *c->out = KeyAt(keys, 0)->v;
            c->cur = 0;
        } else if (!(t < Last(c)->t)) {
            *c->out = Last(c)->v;
            c->cur = c->count - 1;
        } else {
            i = c->cur;
            while (t < KeyAt(keys, i)->t)
                i--;
            if (t > KeyAt(keys, i + 1)->t) {
                do {
                    i++;
                } while (t > KeyAt(cc->keys, i + 1)->t);
            }
            c->cur = i;
            {
                Key* ks = *pk;
                Key* k0 = &ks[i];
                Key* k1 = &ks[i + 1];
                float t0;
                t0 = k0->t;
                *c->out = (1.0f / (k1->t - t0)) * (k1->v * (t - t0) + k0->v * (k1->t - t));
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F3E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F3E70 */

/* merge_units: begin func_003F3FC0 */
#pragma push /* merge_units */
typedef struct { float t; float pad; } Key3F3FC0;
typedef struct { char pad[0x24]; int count; Key3F3FC0* keys; } List3F3FC0;
float func_003F3FC0(List3F3FC0* l)
{
    int n = l->count;
    unsigned int off = n * sizeof(Key3F3FC0);
    if (n > 0)
        return ((Key3F3FC0*)((char*)l->keys + off))[-1].t;
    return 0.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F3FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F3FC0 */
