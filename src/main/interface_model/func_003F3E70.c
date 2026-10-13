/* func_003F3E70: piecewise-linear curve evaluation (interface_model area). */
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
void func_003F3E70(Curve* c, float t)
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
