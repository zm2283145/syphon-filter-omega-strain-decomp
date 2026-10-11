typedef struct { unsigned int v[100]; unsigned int n; } T2DCE20;
extern int func_002E50C8(unsigned int, T2DCE20 **);
int func_002DCE20(unsigned int *out, unsigned int id)
{
    unsigned int a[100];
    unsigned int p[1];
    int i, j, r, k;
    unsigned int t;
    p[0] = 0;
    if (id >= 0x100) return 0x17;
    if (out == 0) return 0x17;
    r = func_002E50C8(id, (T2DCE20 **)p);
    if (r) return r;
    if (p[0] == 0) return 0x16;
    for (i = 0; i < 100; i++) a[i] = ((T2DCE20 *)p[0])->v[i];
    for (i = ((T2DCE20 *)p[0])->n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) { t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
        }
    }
    k = ((T2DCE20 *)p[0])->n / 20;
    if (k <= 0) k = 1;
    *out = a[k];
    return 0;
}


