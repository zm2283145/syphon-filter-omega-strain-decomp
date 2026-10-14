/*
 * lib/medius: 3 files, 00317550-00317728
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00317550 */
/* hex literals: this compiler's decimal float parsing is not exact */
static const float D_004B36F0[12] = {
    0x1.46c5e2p+1f, 4.0f, 0x1.4f8768p+2f, 0x1.8c8db8p+2f, 0x1.b2ea5ep+2f, 7.0f,
    0x1.b2ea5ep+2f, 0x1.8c8dc2p+2f, 0x1.4f8768p+2f, 4.0f, 0x1.46c5e2p+1f, 1.0f,
};
extern float D_004E1CC0;
extern const float D_004E1BB8;
extern const float D_004E1C30;
extern const float D_004E1BEC;
extern void func_0031AD68(float *a, int p, float *c, int n, float gain);

void func_00317550(float *lpc, float *cep, float *err, float *dist, int p, float gain)
{
    float tmp[13];
    float d;
    int i;

    func_0031AD68(lpc, p, tmp, 13, gain);
    *err = __builtin_fabsf(cep[0] - tmp[0]);
    *dist = 0;
    for (i = 1; i < 13; i++) {
        tmp[i] *= D_004B36F0[i - 1];
        d = tmp[i] - cep[i];
        *dist += d * d;
    }
    *dist *= D_004E1CC0;
    if (*dist < D_004E1BB8) {
        for (i = 0; i < 13; i++)
            cep[i] = tmp[i] * D_004E1C30 + cep[i] * D_004E1BEC;
    } else {
        for (i = 0; i < 13; i++)
            cep[i] = tmp[i];
    }
}
/* merge_units: end func_00317550 */

/* merge_units: begin func_00317680 */
typedef struct { float f0; int x4; void *buf; } Obj7680;
extern void *(*D_004E1D34)(int n, int size);
extern void *(*D_004E1D3C)(void *d, int c, int n);
int func_00317680(Obj7680 **out)
{
    Obj7680 *o;
    void *b;
    if (out == 0) return 1;
    *out = 0;
    o = D_004E1D34(1, 0xC);
    if (o == 0) return 1;
    *out = o;
    b = D_004E1D34(0xD, 4);
    o->buf = b;
    if (b == 0) return 1;
    o->x4 = 0;
    o->f0 = 1000.0f;
    D_004E1D3C(b, 0, 0x34);
    return 0;
}
/* merge_units: end func_00317680 */

/* merge_units: begin func_00317728 */
typedef struct { char pad[8]; void *buf; } Obj7728;
extern void (*D_004E1D38)(void *p);
int func_00317728(Obj7728 **pp)
{
    Obj7728 *o = *pp;
    if (o != 0) {
        if (o->buf) {
            D_004E1D38(o->buf);
            o->buf = 0;
        }
        D_004E1D38(o);
    }
    return 0;
}
/* merge_units: end func_00317728 */
