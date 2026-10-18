/* HumanBounds_BuildTable: build the static table of bone-attached bounding spheres once
   (each element registered for destruction) and push a pointer to every entry into out. */
#pragma inline_depth(10)
#pragma cplusplus on

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

/* Bone-attached bounding sphere: bone index, offset-is-zero flag, radius, offset point. */
struct Sphere {
    int bone;
    unsigned char zero;
    float radius;
    V offset;
};

struct PtrVec;

extern "C" {
V* Vec4_Assign(V* d, const V* s);
V* func_0019E660(V* v, float w);
void func_001B06F0(Sphere* s, int flags);
int __register_global_object(void* obj, void* dtor, void* rec);
int func_001B06D0(PtrVec* v, Sphere** p);

extern signed char D_004EEAE0;
extern char D_004EEAE8[12][0x10];
extern Sphere D_004EEBB0[12];
}

static inline V AsPoint(const V& v)
{
    V t;
    V* r = func_0019E660(Vec4_Assign(&t, &v), 1.0f);
    asm { .set reorder } /* scheduling: ends the noreorder region the VU0 test leaves open (retail order up to here) */
    return *r;
}

/* VU0 offset-is-zero test; the block deliberately does not restore .set reorder (see AsPoint) */
static inline unsigned char IsZeroXYZ(const V* v)
{
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
    }
    return r;
}

static inline void InitSphere(Sphere* s, int bone, const V& off, float radius)
{
    s->bone = bone;
    s->zero = IsZeroXYZ(&off);
    s->radius = radius;
    s->offset = AsPoint(off);
}

extern "C" void HumanBounds_BuildTable(PtrVec* out)
{
    int i;
    if (!D_004EEAE0) {
        InitSphere(&D_004EEBB0[0], 0x0, V(0.0f, 0.0f, 0.0f, 0.0f), 0.75f);
        __register_global_object(&D_004EEBB0[0], (void*)func_001B06F0, D_004EEAE8[0]);
        InitSphere(&D_004EEBB0[1], 0x4, V(0.0f, 0.0f, 0.0f, 0.0f), 0.41666666f);
        __register_global_object(&D_004EEBB0[1], (void*)func_001B06F0, D_004EEAE8[1]);
        InitSphere(&D_004EEBB0[2], 0x6, V(0.0f, 0.0f, 0.0f, 0.0f), 0.41666666f);
        __register_global_object(&D_004EEBB0[2], (void*)func_001B06F0, D_004EEAE8[2]);
        InitSphere(&D_004EEBB0[3], 0xc, V(0.0f, 0.0f, 0.0f, 0.0f), 0.75f);
        __register_global_object(&D_004EEBB0[3], (void*)func_001B06F0, D_004EEAE8[3]);
        InitSphere(&D_004EEBB0[4], 0x10, V(0.0f, 0.0f, 0.0f, 0.0f), 0.75f);
        __register_global_object(&D_004EEBB0[4], (void*)func_001B06F0, D_004EEAE8[4]);
        InitSphere(&D_004EEBB0[5], 0xe, V(0.0f, 0.0f, 0.0f, 0.0f), 1.0f);
        __register_global_object(&D_004EEBB0[5], (void*)func_001B06F0, D_004EEAE8[5]);
        InitSphere(&D_004EEBB0[6], 0xd, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[6], (void*)func_001B06F0, D_004EEAE8[6]);
        InitSphere(&D_004EEBB0[7], 0xf, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[7], (void*)func_001B06F0, D_004EEAE8[7]);
        InitSphere(&D_004EEBB0[8], 0x11, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[8], (void*)func_001B06F0, D_004EEAE8[8]);
        InitSphere(&D_004EEBB0[9], 0x12, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[9], (void*)func_001B06F0, D_004EEAE8[9]);
        InitSphere(&D_004EEBB0[10], 0x13, V(0.0f, 0.0f, 0.0f, 0.0f), 0.6666667f);
        __register_global_object(&D_004EEBB0[10], (void*)func_001B06F0, D_004EEAE8[10]);
        InitSphere(&D_004EEBB0[11], 0x14, V(0.0f, 0.0f, 0.0f, 0.0f), 0.6666667f);
        __register_global_object(&D_004EEBB0[11], (void*)func_001B06F0, D_004EEAE8[11]);
        D_004EEAE0 = 1;
    }
    for (i = 0; i < 12; i++) {
        Sphere* p;
        Sphere** pp = &p;
        p = &D_004EEBB0[i];
        func_001B06D0(out, pp);
    }
}
