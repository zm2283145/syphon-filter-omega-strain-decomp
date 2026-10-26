typedef struct {
    char pad0[0x20];
    short start;
    short end;
    float f24;
    unsigned short f28;
} Sub317;

typedef struct {
    char pad0[0x8];
    char f8[0x28];
    float f30;
    float f34;
    char pad38[0x44 - 0x38];
    int f44;
    Sub317 *p48;
} Obj317;

extern int func_00323250(void);
extern void NellySTFTpeaks(void *a, void *b, float *buf, float *val, float *pos, int *count, int max);
extern void NellySeevocFlattop(float *buf, float *val, float *pos, int count, float *buf2, int max, float scale);
extern void NellySTCVoicing(void *o, float *buf, float *st, float *st2, float *val, float *pos, int count, int max);
extern void NellyLinearInterpolate(float scale, float *buf, int n);
extern void (*D_004E1D40)(float *a, float *b, int n);
extern void NellyLogEnvelopeToAs(float *buf, int n, float *st, float *val, float *pos);
extern void K2ASK(int n, float *pos, float *st);
extern void GetFrameSpCBM(void *out, int n, void *x, float *buf2);
extern void ScaleVector(float *a, void *x, float *b, float s);
extern void HammingWindowNormSC(float *a, void *x);
extern void TDPitchRefine(float *a, void *x, float s, float z, float *w);
extern float ModifyPv(float a, float b, float c, float d, float e);

void OuterFrameParam(void *out, void *a, void *b, float *st, Obj317 *o, void *x, int y, int unused, float *w)
{
    float val[100];
    float pos[100];
    float buf[256];
    float buf2[292];
    float tmp[256];
    int count;
    Sub317 *p;
    float scale;
    int max;
    float *sp;
    float *pb = buf;
    float *pp = pos;
    float *pv = val;

    max = 0x1C;
    scale = 512.0f;
    p = o->p48;
    if (func_00323250() == 0) max = 100;
    sp = st + 2;
    NellySTFTpeaks(a, b, pb, pv, pp, &count, max);
    scale = scale / sp[0];
    NellySeevocFlattop(buf, val, pos, count, buf, max, scale);
    NellySTCVoicing(o->f8, buf, sp, st + 3, val, pos, count, max);
    NellyLinearInterpolate(scale, buf, 0x100);
    if (o->f44 != 0 && p->f28 != 0) {
        int start = p->start;
        float s1 = 0.0f, s2 = 0.0f;
        int i;
        float d;
        for (i = 0; i < 256; i++) {
            int k = i + start;
            if (i >= p->end) {
                if (k >= 0 && k < 256) {
                    tmp[i] = buf[k];
                } else if (k >= 256) {
                    tmp[i] = pb[255];
                } else {
                    tmp[i] = buf[i];
                }
            } else {
                tmp[i] = buf[i];
            }
            s1 += buf[i];
            s2 += tmp[i];
        }
        d = (s1 - s2) * (1.0f / 256.0f);
        for (i = 0; i < 256; i++) tmp[i] += d;
        D_004E1D40(buf, tmp, 256);
    }
    NellyLogEnvelopeToAs(buf, 0xC, st + 4, pv, pp);
    if (o->f44 != 0) p->f24 = 1.0f;
    K2ASK(0xC, pos, st + 5);
    GetFrameSpCBM(out, y + 0x91, x, buf2);
    ScaleVector(buf2, x, buf2, 2.0f);
    HammingWindowNormSC(buf2, x);
    TDPitchRefine(buf2, x, sp[0], 0.0f, w);
    sp[1] = ModifyPv(*w, sp[1], o->f30, sp[0], o->f34);
}




