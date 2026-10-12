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
extern void func_0031A820(void *a, void *b, float *buf, float *val, float *pos, int *count, int max);
extern void func_0031A490(float *buf, float *val, float *pos, int count, float *buf2, int max, float scale);
extern void func_0031D680(void *o, float *buf, float *st, float *st2, float *val, float *pos, int count, int max);
extern void func_00317D08(float scale, float *buf, int n);
extern void (*D_004E1D40)(float *a, float *b, int n);
extern void func_0031AB98(float *buf, int n, float *st, float *val, float *pos);
extern void func_0031B030(int n, float *pos, float *st);
extern void func_0031A1E0(void *out, int n, void *x, float *buf2);
extern void func_0031BAF0(float *a, void *x, float *b, float s);
extern void func_00319DC0(float *a, void *x);
extern void func_0031BE68(float *a, void *x, float s, float z, float *w);
extern float func_0031DA90(float a, float b, float c, float d, float e);

void func_00317F08(void *out, void *a, void *b, float *st, Obj317 *o, void *x, int y, int unused, float *w)
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
    func_0031A820(a, b, pb, pv, pp, &count, max);
    scale = scale / sp[0];
    func_0031A490(buf, val, pos, count, buf, max, scale);
    func_0031D680(o->f8, buf, sp, st + 3, val, pos, count, max);
    func_00317D08(scale, buf, 0x100);
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
    func_0031AB98(buf, 0xC, st + 4, pv, pp);
    if (o->f44 != 0) p->f24 = 1.0f;
    func_0031B030(0xC, pos, st + 5);
    func_0031A1E0(out, y + 0x91, x, buf2);
    func_0031BAF0(buf2, x, buf2, 2.0f);
    func_00319DC0(buf2, x);
    func_0031BE68(buf2, x, sp[0], 0.0f, w);
    sp[1] = func_0031DA90(*w, sp[1], o->f30, sp[0], o->f34);
}




