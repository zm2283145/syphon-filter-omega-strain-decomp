/* Animation sample assignment: implicit member-wise operator= (byte id + four lq/sq quad copies). */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Sample {
    unsigned char id;
    V v[4];
};
extern "C" Sample* Anim_CopySample(Sample* d, const Sample* s)
{
    *d = *s; return d;
}

