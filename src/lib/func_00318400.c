typedef struct {
    float x[4];
    float y[4];
    float p;
    float q;
    int idx;
    int lag;
} PitchState;

extern void GetFrameSpCBM(void* a0, int a1, int a2, float* a3);

#define fabsf_ __builtin_fabsf

int EstOnset(PitchState* s, void* a1, int a2, int a3, float* in)
{
    int idx = s->idx;
    int lim = s->lag - 0x96;
    float* xb = s->x;
    float* yb = s->y;
    float x = xb[idx];
    float y = yb[idx];
    float p = s->p;
    float q = s->q;
    register float bm __asm__("$f9");
    register float ba __asm__("$f8");
    register float gain __asm__("$f10");
    register float decay __asm__("$f7");
    int best = 0;
    int i;
    register int r __asm__("$5");

    GetFrameSpCBM(a1, a2, 0xA1, in);
    bm=1.0f;
    ba=0.16f;
    gain=0.031005859375f;
    decay=0.9689941f;
    for (i = 0; i < 0xA0; i += 2) {
        register float t0 asm("$f0");
        register float t1 asm("$f1");
        register float t2 asm("$f2");
        register float t3 asm("$f3");
        register float t4 asm("$f4");
        register float t5 asm("$f5");
        float m;
        t0 = in[0];
        t3 = x * decay;
        t1 = in[1];
        in += 2;
        t4 = t0 * gain;
        t2 = y * decay;
        t0 = t4 * t0;
        t1 = t4 * t1;
        y = t1 + t2;
        x = t0 + t3;
        idx = (idx + 1) % 4;
        t4 = xb[idx];
        t5 = yb[idx];
        t0 = y * p;
        t3 = x * q;
        xb[idx] = x;
        yb[idx] = y;
        t2 = p + x;
        /* Preserve sum/temporary lifetimes across the state stores. */
        __asm__("" : "+f"(t2), "+f"(t1) : "f"(q), "f"(x), "f"(x), "f"(y), "f"(y), "f"(p) : "memory");
        t1 = q + y;
        m = p * x;
        t0 = t0 - t3;
        p = t2 - t4;
        q = t1 - t5;
        t4 = fabsf_(t0);
        if (i >= lim) {
            /* Keep the absolute-value result live across comparison setup. */
            __asm__("" : "+f"(t4));
            t1 = t4 * bm;
            /* Preserve comparison lifetimes without emitting instructions. */
            __asm__("" : "+f"(t1), "+f"(m));
            t0 = m * ba;
            if (t1 > t0) {
                bm = m;
                ba = t4;
                best = i;
            }
        }
    }
    s->idx = idx;
    s->p = p;
    s->q = q;
    s->lag = best;
    if (best > 0x50) {
        register float u0 asm("$f0");
        register float u1 asm("$f1");
        register float u2 asm("$f2");
        register float u3 asm("$f3");
        { register int l __asm__("$2") = 0xA0-best; register int v __asm__("$3") = a2-(a3>>1);
        u1=(float)l; u2=(float)v; }
        u3 = 0.0125f;
        u0 = 0.5f;
        u1 = u1 * u2;
        u2 = u1 * u3;
        u0 = u2 + u0;
        r = (int)u0;
        if (r > 0x28)
            r = 0x28;
    } else {
        register float w0 asm("$f0");
        register float w1 asm("$f1");
        register float w2 asm("$f2");
        w2 = 0.0125f;
        w1 = 0.5f;
        w0 = (float)(best * (a2 - (a3 >> 1)));
        w2 = w0 * w2;
        w1 = w2 + w1;
        r = (int)w1;
        r = -r;
        if (r < -0x28)
            r = -0x28;
    }
    return r;
}
