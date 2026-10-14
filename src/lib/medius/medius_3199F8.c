typedef struct { float re; float im; } Cx;

static inline float Dist2(Cx* a, Cx* b)
{
    float r;
    __asm__ volatile (
        "lwc1 $f1, 0(%1)\n"
        "lwc1 $f0, 0(%2)\n"
        "lwc1 $f2, 4(%1)\n"
        "sub.s $f0, $f1, $f0\n"
        "lwc1 $f1, 4(%2)\n"
        "mula.s $f0, $f0\n"
        "sub.s $f0, $f2, $f1\n"
        "madd.s %0, $f0, $f0\n"
        : "=f"(r) : "r"(a), "r"(b) : "$f0", "$f1", "$f2");
    return r;
}

extern float D_004E1D1C[];

void func_003199F8(Cx *pos, Cx *tab, int n, int *idx, int k)
{
    float best[4];
    float d;
    int i, j;
    for (i = 0; i < k; i++) { idx[i] = 0; best[i] = D_004E1D1C[0]; }
    for (i = 0; i < n; i++) {
        d = Dist2(pos, tab);
        tab++;
        if (d < best[k - 1]) {
            for (j = k - 1; j > 0 && d <= best[j - 1]; j--) {
                best[j] = best[j - 1];
                idx[j] = idx[j - 1];
            }
            best[j] = d;
            idx[j] = i;
        }
    }
}
