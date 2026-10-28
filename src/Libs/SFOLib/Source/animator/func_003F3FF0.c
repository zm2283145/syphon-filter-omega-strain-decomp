#include "types.h"
typedef struct { float x, y, z; } cXyz;

typedef struct { float t; cXyz v; } Key;
typedef struct {
    char pad0[0x18];
    int cur;
    cXyz* out;
    char pad20[4];
    int count;
    Key* keys;
} Curve;

static inline Key* KeyAt(Key* k, int i) { return &k[i]; }
static inline void Scale(cXyz* r, const cXyz* a, float s) { r->z = a->z * s; r->y = a->y * s; r->x = a->x * s; }
static inline void ScaleF(cXyz* r, const cXyz* a, float s) { float x = a->x * s, y = a->y * s, z = a->z * s; r->x = x; r->y = y; r->z = z; }
static inline void Add(cXyz* r, const cXyz* a, const cXyz* b) { r->x = a->x + b->x; r->y = a->y + b->y; r->z = a->z + b->z; }
static inline Key* Last(Curve* c) { return c->keys + c->count - 1; }

static inline void Interp(cXyz* o, const Key* k0, const Key* k1, float t)
{
    float d1, d0;
    cXyz a, b, s;
    d0 = t - k0->t;
    d1 = k1->t - t;
    Scale(&a, &k0->v, d1);
    Scale(&b, &k1->v, d0);
    Add(&s, &b, &a);
    ScaleF(o, &s, 1.0f / (k1->t - k0->t));
}
#pragma opt_strength_reduction off
#pragma opt_propagation off
void cKeyframeAnimation_cXyz_Update(Curve* c, float t)
{
    Curve* cc = c;
    int i;
    Key* keys;
    Key** pk;
    if (*(volatile int*)&c->count > 0) {
        pk = &c->keys;
        keys = c->keys;
        if (t <= KeyAt(keys, 0)->t) {
            { cXyz* o = c->out; Key* k = KeyAt(keys, 0); o->x = k->v.x; o->y = k->v.y; o->z = k->v.z; }
            c->cur = 0;
        } else if (!(t < Last(c)->t)) {
            { cXyz* o = c->out; Key* k = Last(c); o->x = k->v.x; o->y = k->v.y; o->z = k->v.z; }
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
            Interp(c->out, KeyAt(*pk, i), KeyAt(*pk, i + 1), t);
        }
    }
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
