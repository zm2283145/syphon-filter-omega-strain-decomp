/* asm("" : "+r"(c) : "r"(spec)) emits no code; the extra use of the spec base
 * address tips global-alloc priority so it gets $s4 (retail) instead of $s5. */
extern float D_004B3968[];
extern float D_004E1C80;
extern float func_00317780(float* a, float* b, int n);
extern float func_00316ED8(float* h, int m, float f, float* a, int n, float g);
extern int func_0031CB78(float f, float* spec, float* out, float thr);
extern int func_0031CC50(float* spec, int* idx, int* sel);
extern void func_0031CDC0(float* spec, int* idx, int* cnt, int* sel);
extern void func_0031CF58(float* spec, int pk, int* idx, int* cnt, int* sel);
extern float func_0031D088(int k, float* h, int m, float* a, int n, float g, float* best);

int func_0031C8D8(float* a, int n, float* h, int m, float x, float y, float* d, float* e0, int* k)
{
    float* e = e0;
    int idx[8];
    float spec[74];
    float t;
    int sel;
    int cnt;
    float v;
    float scale;
    int i;
    int pk;
    int c;
    float tmp;
    int last;

    scale = func_00317780(a, a, n) + D_004E1C80;
    scale = 10.0f / scale;
    for (i = 0; i < 74; i += 2)
        spec[i] = func_00316ED8(h, m, D_004B3968[i], a, n, scale);
    for (i = 1; i < 74; i += 2)
        spec[i] = spec[i - 1];
    pk = func_0031CB78(x, spec, &t, y);
    tmp = t;
    t = spec[pk];
    spec[pk] = tmp;
    cnt = func_0031CC50(spec, idx, &sel);
    func_0031CDC0(spec, idx, &cnt, &sel);
    func_0031CF58(spec, pk, idx, &cnt, &sel);
    tmp = t;
    t = spec[pk];
    spec[pk] = tmp;
    c = 0;
    last = cnt - 1;
    for (i = 0; i < cnt; i++) {
        if (i == 0 || i == last || i == sel) {
            int j;
            if (i == sel)
                *k = c;
            j = idx[i];
            v = spec[j];
            d[c] = func_0031D088(j, h, m, a, n, scale, &v);
            if (j == pk) {
                float f = v;
                if (f < y)
                    f = (y + f) * 0.5f;
                v = f;
            }
            e[c] = v;
            c++;
        }
    }
    __asm__("" : "+r"(c) : "r"(spec)); /* ref barrier, emits no code */
    return c;
}
