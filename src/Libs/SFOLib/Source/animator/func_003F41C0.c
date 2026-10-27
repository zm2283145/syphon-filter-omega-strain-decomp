#include "types.h"

/* cKeyframeAnimation_tRGB_Update: piecewise-linear evaluation of a 3-component (colour) track;
 * the key search is cKeyframeAnimation_float_Update's (interface_model_3F3E70.c). */
typedef struct { float t; float v[3]; } Key;
typedef struct {
    char pad0[0x18];
    int cur;
    float* out;
    char pad20[4];
    int count;
    Key* keys;
} Curve;

static inline Key* KeyAt(Key* k, int i) { return &k[i]; }
static inline void Copy3(float* o, Key* k) { o[0] = k->v[0]; o[1] = k->v[1]; o[2] = k->v[2]; }
static inline Key* Last(Curve* c) { return c->keys + c->count - 1; }

#pragma opt_strength_reduction off
#pragma opt_propagation off
void cKeyframeAnimation_tRGB_Update(Curve* c, float t)
{
    /* Local declaration order matters for register allocation.
     * `cc` (an un-propagated alias of c) makes the second scan loop reload
     * keys from memory each iteration, as retail does. */
    Curve* cc = c;
    int i;
    Key* keys;
    Key** pk;
    float* o; /* declared last: keeps out in t0 (retail) */
    if (*(volatile int*)&c->count > 0) {
        pk = &c->keys;
        keys = c->keys;
        if (t <= KeyAt(keys, 0)->t) {
            Copy3(c->out, KeyAt(keys, 0));
            c->cur = 0;
        } else if (!(t < Last(c)->t)) {
            Copy3(c->out, Last(c));
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
                float r, g, b; float sb, sg, sr;
                t0 = k0->t;
                /* each sum is computed before its scale (retail's fused/unfused split) */
                sb = k1->v[2] * (t - t0) + k0->v[2] * (k1->t - t);
                b = sb * (1.0f / (k1->t - t0));
                sg = k1->v[1] * (t - t0) + k0->v[1] * (k1->t - t);
                g = sg * (1.0f / (k1->t - t0));
                sr = k1->v[0] * (t - t0) + k0->v[0] * (k1->t - t);
                r = sr * (1.0f / (k1->t - t0));
                o = c->out;
                o[0] = r;
                o[1] = g;
                o[2] = b;
            }
        }
    }
}
