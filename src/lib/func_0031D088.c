extern float D_004B3968[];
extern float func_00316ED8(int a, int b, float f, int c, int d, float g);

float func_0031D088(int k, int a, int b, int c, int d, float *best, float g)
{
    float cand[2];
    float res = D_004B3968[k];
    float x, v;
    int n = 0, i;

    if (k > 0) cand[n++] = (res + D_004B3968[k - 1]) * 0.5f;
    k++;
    if (k < 74) cand[n++] = (res + D_004B3968[k]) * 0.5f;
    for (i = 0; i < n; i++) {
        x = cand[i];
        v = func_00316ED8(a, b, x, c, d, g);
        if (*best < v) {
            *best = v;
            res = x;
        }
    }
    return res;
}
