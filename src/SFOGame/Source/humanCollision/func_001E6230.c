#pragma opt_common_subs off
#pragma opt_propagation off
#pragma peephole off
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 v0; V4 v1; V4 v2; V4 n; } Tri;
static inline void V4_Sub(V4 *o, V4 *a, V4 *b) {
    V4 *q = a;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(o)
    }
}
static inline void V4_Scale(V4 *p, V4 *a, float k) {
    int t;
    V4 *q = a;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(q)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(p)
        .set reorder
    }
}
static inline void V4_Cross(V4 *p, V4 *a, V4 *b) {
    long long t;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(p)
        paddub t, zero, zero
    }
}
static inline void V4_Copy(V4 *d, V4 *s) {
    asm {
        lq s, 0x0(s)
        sq s, 0x0(d)
    }
}
void cCollisionFace_CalculateUnitNormal(Tri *t)
{
    V4 e1;
    V4 e2;
    V4 r;
    V4 n;
    V4 t1;
    V4 t2;
    V4 ts;
    V4 tc;
    float k;
    V4_Sub(&t1, &t->v1, &t->v0);
    V4_Copy(&e1, &t1);
    V4_Sub(&t2, &t->v2, &t->v0);
    V4_Copy(&e2, &t2);
    k = t->n.w;
    V4_Cross(&tc, &e1, &e2);
    n = tc;
    {
        V4 *ps = &ts;
        V4_Scale(ps, &n, k);
        r = *ps;
    }
    t->n = r;
}
