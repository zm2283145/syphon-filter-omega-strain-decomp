extern char D_0058C178[];
int func_002E68C0(int n)
{
    int i, j, k, ok;
    if ((unsigned)n >= 0x1000) return 0x100;
    for (i = 0; i < 0x1000 - n; i++) {
        if (D_0058C178[i] == 0) {
            ok = 1;
            for (j = i + 1; j < i + n; j++) {
                if (D_0058C178[j] != 0) { ok = 0; break; }
            }
            if (ok) {
                for (k = i; k < i + n; k++) D_0058C178[k] = 1;
                return i;
            }
        }
    }
    return -1;
}
