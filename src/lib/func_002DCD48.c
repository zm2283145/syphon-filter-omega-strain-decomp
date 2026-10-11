typedef struct { unsigned int v[100]; } A2DCD48;
extern int func_002E50C8(unsigned int, A2DCD48 **);
int func_002DCD48(unsigned int *out, unsigned int idx)
{
    unsigned int buf[100];
    A2DCD48 *src = 0;
    unsigned int t;
    int i, j;
    int r;
    if (idx >= 0x100) return 0x17;
    if (out == 0) return 0x17;
    r = func_002E50C8(idx, &src);
    if (r) return r;
    if (src == 0) return 0x16;
    for (i = 0; i < 100; i++) buf[i] = src->v[i];
    for (i = 99; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (buf[j] > buf[j + 1]) {
                t = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = t;
            }
        }
    }
    *out = buf[50];
    return 0;
}
