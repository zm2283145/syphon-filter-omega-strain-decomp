typedef struct { int a; int b; int c; } G;
extern int D_00518200[];
extern int _sceMcCoreReadPage2(int, int *, int, int, int);
int func_002BB3B0(int idx, G *g, int *out)
{
    int *buf = D_00518200;
    int cnt = 0;
    int k;
    int n = g->c / g->b;
    for (k = 1; k < n; k++) {
        int j;
        int found;
        int base;
        if (cnt >= 32) return 1;
        found = 0;
        base = k * g->b;
        for (j = 0; j < g->b; j += 2) {
            unsigned int m;
            if (!_sceMcCoreReadPage2(idx, buf, base + j, 2, 0)) return 0;
            for (m = 0; m < g->a / 2; m++) {
                if (buf[m] != -1) {
                    found++;
                    break;
                }
            }
        }
        if (found > 0) {
            *out++ = k;
            cnt++;
        }
    }
    return 1;
}


