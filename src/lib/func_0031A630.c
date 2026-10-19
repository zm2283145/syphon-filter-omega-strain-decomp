int func_0031A630(float *tab, float *mag, float *pos, int n, float w, float *outA, float *outB, int max)
{
    float half = w * 0.5f;
    float lo = half;
    float hi = lo + w;
    float best;
    int cnt = 0;
    int j = 0;
    int k;

    while (pos[j] < lo && j < n) j++;
    while (lo < 256.0f - half && cnt < max) {
        best = 0.0f;
        if (j < n) {
            k = j;
            if (pos[j] < hi) {
                do {
                    if (best < mag[k]) {
                        best = mag[k];
                        j = k;
                    }
                    k++;
                } while (pos[k] < hi && k < n);
            }
        }
        if (0.0f < best) {
            outA[cnt] = best;
            outB[cnt] = pos[j];
        } else {
            k = (int)((lo + hi) * 0.5f + 0.5f);
            outA[cnt] = tab[k] + 1e-6f;
            outB[cnt] = (float)k;
        }
        lo = outB[cnt] + half;
        hi = lo + w;
        if (256.0f < hi) hi = 256.0f;
        cnt++;
        while (pos[j] < lo && j < n) j++;
    }
    return cnt;
}
