typedef struct {
    char pad0[0x24];
    float gain;
    char pad28[0x24];
    float f4C;
    float f50;
} Obj_fab8;

typedef struct {
    int i0;
    int i4;
    int i8;
    int sub[3];
} Prm_fab8;

typedef struct {
    float f0;
    float f4;
    float q[2];
    float f10;
    float f14[3];
} Out_fab8;

/* hex literals: this compiler's decimal float parsing is not exact */
static const float D_004B5C98[8] = {
    0.0f, 0x1.24dd2ep-3f, 0x1.24dd2ep-2f, 0x1.b74bc6p-2f,
    0x1.245a1cp-1f, 0x1.6d9168p-1f, 0x1.b6c8b4p-1f, 1.0f,
};
static const float D_004B5CB8[64] = {
    -0x1.56d7fp+1f, -0x1.d29d62p+0f, -0x1.62393ep+0f, -0x1.12d9cep+0f,
    -0x1.84e7eep-1f, -0x1.e06d92p-2f, -0x1.8b3e56p-3f, 0x1.8a633p-4f,
    0x1.596bfcp-2f, 0x1.19d648p-1f, 0x1.7f531cp-1f, 0x1.ed4046p-1f,
    0x1.30156ep+0f, 0x1.693ab4p+0f, 0x1.a9d5e4p+0f, 0x1.ed2598p+0f,
    0x1.15fedap+1f, 0x1.2d077cp+1f, 0x1.422b5p+1f, 0x1.57ed9cp+1f,
    0x1.6cb274p+1f, 0x1.821c3ep+1f, 0x1.98f4c6p+1f, 0x1.b147fp+1f,
    0x1.ca6a2ap+1f, 0x1.e2cfa6p+1f, 0x1.f8cf94p+1f, 0x1.07985ep+2f,
    0x1.12fbf4p+2f, 0x1.1dce3p+2f, 0x1.28911p+2f, 0x1.34aa2ap+2f,
    0x1.3f1da2p+2f, 0x1.4a538ep+2f, 0x1.54eb06p+2f, 0x1.605dbep+2f,
    0x1.6af112p+2f, 0x1.756dacp+2f, 0x1.804e92p+2f, 0x1.8a56f6p+2f,
    0x1.950634p+2f, 0x1.9f6fb8p+2f, 0x1.a9f1bep+2f, 0x1.b5355cp+2f,
    0x1.c06cb4p+2f, 0x1.cc0a24p+2f, 0x1.d74c54p+2f, 0x1.e33d28p+2f,
    0x1.eea4f8p+2f, 0x1.fa2156p+2f, 0x1.02c068p+3f, 0x1.08967ep+3f,
    0x1.0ea7e8p+3f, 0x1.14df4cp+3f, 0x1.1be6dcp+3f, 0x1.23528ap+3f,
    0x1.2ae138p+3f, 0x1.32d9c2p+3f, 0x1.3b718ap+3f, 0x1.44d29ap+3f,
    0x1.4e8556p+3f, 0x1.5a01b8p+3f, 0x1.674e62p+3f, 0x1.773b2ep+3f,
};
extern float D_004E1BE4;
extern float D_004E1BE8;
extern float Libc_Expf(float x);
extern float func_0031FA08(float a, float b, float c, float d);
extern void NellyMSVQDecPred(int *src, float *dst, int n, int arg, float v);

void unquantize(Obj_fab8 *o, Prm_fab8 *p, int arg, Out_fab8 *out)
{
    float *q = out->q;
    float a = o->f50;
    float b = o->f4C;
    int v = p->i4;
    int bit = v & 8;
    int w;
    float t;

    v -= bit;
    if (v >= 8) v = 0;
    t = D_004B5C98[v];
    q[1] = t;
    if (bit == 0) out->f4 = a;
    else out->f4 = t;
    q[0] = Libc_Expf(D_004E1BE8 - (float)p->i8 * D_004E1BE4);
    q[0] = q[0] * o->gain;
    if (q[0] < 8.0f) q[0] = 8.0f;
    if (160.0f < q[0]) q[0] = 160.0f;
    out->f0 = func_0031FA08(b, q[0], a, q[1]);
    w = p->i0;
    if (w >= 64) w = 0;
    out->f10 = D_004B5CB8[w];
    NellyMSVQDecPred(p->sub, out->f14, 12, arg, q[1]);
}
