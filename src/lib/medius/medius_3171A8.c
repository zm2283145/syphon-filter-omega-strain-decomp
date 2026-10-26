/*
 * lib/medius: 4 files, 003171A8-00317490
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003171A8 */
typedef struct { int x0; int x4; int x8; int xC[3]; } Out71A8;
typedef struct { char pad[0x38]; float f38; float f3C; } St71A8;
typedef struct { float f0; float f4; float f8; float fC; float f10; int x14[3]; } Prm71A8;
extern int QuanPvSC3(float a, float b, float c);
extern void UnQuanPvSC3(float x, int v, float *a, float *b);
extern int NellyQuanPitchSC3(float x);
extern float NellyUnQuanPitchSC3(int v);
extern float UnQuanMidPitchSC3(float a, float b, float c, float d);
extern int QuanGainSC3(float x);
extern void NellyMSVQEncPred(int *a, int *b, int n, float x);
void NellyQuantSC3(Out71A8 *o, St71A8 *st, Prm71A8 *p)
{
    float *q = &p->f8;
    o->x4 = QuanPvSC3(st->f38, p->f4, q[1]);
    UnQuanPvSC3(st->f38, o->x4, &p->f4, &p->fC);
    o->x8 = NellyQuanPitchSC3(q[0]);
    q[0] = NellyUnQuanPitchSC3(o->x8);
    p->f0 = UnQuanMidPitchSC3(st->f3C, q[0], st->f38, q[1]);
    o->x0 = QuanGainSC3(p->f10);
    NellyMSVQEncPred(p->x14, o->xC, 0xC, q[1]);
    st->f38 = q[1];
    st->f3C = q[0];
}
/* merge_units: end func_003171A8 */

/* merge_units: begin func_00317278 */
extern float *D_004E1D5C;

void corrfunc(float *best, int n, float *x, int *y, float *pos, float step, float f, float end, float init)
{
    int i, v;
    float sum;
    float k = 4096.0f;
    for (; f <= end; f += step) {
        v = (int)(f * k + 0.5f);
        sum = init;
        for (i = 0; i < n; i++)
            sum += x[i] * D_004E1D5C[(unsigned)(v * y[i] + 0x800000) >> 24];
        if (*best < sum) { *best = sum; *pos = f; }
    }
}
/* merge_units: end func_00317278 */

/* merge_units: begin func_00317330 */
typedef struct {
    int pad[2];
    float v[2];
    float gain;
} A;

typedef struct {
    float x;
    float y;
    float *cep;
} B;

extern void Cepstrum4VocalFry(float *lpc, float gain, float *cep, float *err, float *dist, int p);

int Detect_VocalFry(A *a, B *b, float *lpc, int p)
{
    float err, dist;
    float x = b->x, y = b->y;
    float *v;
    float h;
    int r = 0;
    v = a->v;
    Cepstrum4VocalFry(lpc, a->gain, b->cep, &err, &dist, p);
    if (x < v[0] && 0x1.999998p-3f <= v[1]) {
        h = v[0] * 0.5f;
        if (h * 0x1.bd70a2p-1f < x && x < h * 0x1.266666p+0f) r = 1;
    }
    if (r == 1 && err <= 2.0f && ((dist <= 0.5f && y >= 3.5f) || (dist <= 0x1.999998p-2f && y >= 2.5f) || (dist <= 0x1.999998p-4f && y >= 1.5f)))
        r = 1;
    else
        r = 0;
    return r;
}
/* merge_units: end func_00317330 */

/* merge_units: begin func_00317490 */
typedef struct { float x, y; } G7V2;
typedef struct { float a; float pad; G7V2 v; } G7A;
extern float D_004E1BE0, D_004E1CB8, D_004E1C4C, D_004E1C50, D_004E1C30, D_004E1CBC;
void UpdateVF_States(G7A* a, G7V2* b)
{
    G7V2* v = &a->v;
    float x = b->x;
    float y = b->y;
    float s;
    if (v->x * D_004E1BE0 < x && x < v->x * D_004E1CB8) {
        y += 1.0f;
        x = x * D_004E1C4C + v->x * D_004E1C50;
    } else if (D_004E1C4C <= v->y) {
        x = v->x;
        y = v->y;
    } else {
        x = 1000.0f;
        y = 0.0f;
    }
    s = a->a;
    b->x = x;
    if (s * D_004E1C30 < x && x < s * D_004E1CBC) y += 1.0f;
    b->y = y;
}
/* merge_units: end func_00317490 */
