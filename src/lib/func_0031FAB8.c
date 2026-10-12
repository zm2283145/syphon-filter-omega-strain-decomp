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

extern float D_004B5C98[];
extern float D_004B5CB8[];
extern float D_004E1BE4;
extern float D_004E1BE8;
extern float func_00121AD0(float x);
extern float func_0031FA08(float a, float b, float c, float d);
extern void func_003194A0(int *src, float *dst, int n, int arg, float v);

void func_0031FAB8(Obj_fab8 *o, Prm_fab8 *p, int arg, Out_fab8 *out)
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
    q[0] = func_00121AD0(D_004E1BE8 - (float)p->i8 * D_004E1BE4);
    q[0] = q[0] * o->gain;
    if (q[0] < 8.0f) q[0] = 8.0f;
    if (160.0f < q[0]) q[0] = 160.0f;
    out->f0 = func_0031FA08(b, q[0], a, q[1]);
    w = p->i0;
    if (w >= 64) w = 0;
    out->f10 = D_004B5CB8[w];
    func_003194A0(p->sub, out->f14, 12, arg, q[1]);
}
