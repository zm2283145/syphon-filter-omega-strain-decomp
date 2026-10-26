typedef struct S7 { char pad[0x28]; unsigned long long x28; } S7;
typedef struct P {
    void *x0; int pad4[3]; int x10; int pad14; int x18; int pad1c;
    int x20; int x24; int x28; float x2C; float x30; float x34;
    int pad38[3]; int x44; S7 *x48; int x4C;
} P;
typedef struct Q { int pad[2]; float v[2]; } Q;

extern void updateVuFft();
extern void PutFrameSpCBM(void *, int, int, float *);
extern float CoarsePitchAndFrameEnergy(void *, int, float *);
extern void PitchAdaptiveSpectrum(int, void *, float *, float *, float, int *, int *);
extern void OuterFrameParam(void *, float *, float *, Q *, P *, int, int, int *, float *);
extern void MidFrameParam(P *, Q *, int, short, float, int);
extern void nemAgcVadMain(int, float, float);
extern void ApplyCustomVoiceFont(S7 *, float *, float *);

int NellyEncodeSC(short *src, P *p, Q *q)
{
    float buf[160];
    float b1[0x204];
    float b2[0x104];
    int n0;
    int k = 0;
    int n1 = 0;
    float g;
    float y, x;
    float *v = q->v;
    void *h = p->x0;
    S7 *s = p->x48;
    int i;
    float *d;
    float f;

    updateVuFft();
    if (!(p->x28 & p->x20))
        return 1;
    d = buf;
    i = 160;
    while (i-- > 0)
        *d++ = *src++;
    PutFrameSpCBM(h, 0, 160, buf);
    f = CoarsePitchAndFrameEnergy(h, p->x10, &p->x2C);
    v[0] = f;
    PitchAdaptiveSpectrum(p->x18, h, b1, b2, f, &n0, &n1);
    OuterFrameParam(h, b1, b2, q, p, n0, n1, &k, &g);
    MidFrameParam(p, q, 0xE1, p->x28, g, k);
    p->x34 = v[0];
    p->x24 = p->x28;
    p->x30 = v[1];
    if (p->x4C)
        nemAgcVadMain(p->x4C, p->x2C, v[1]);
    if (p->x44) {
        if (s->x28 & 0xFFFFFFFFFFFFULL) {
            y = v[1];
            x = v[0];
            ApplyCustomVoiceFont(s, &y, &x);
            v[0] = x;
            v[1] = y;
        }
    }
    return 0;
}
