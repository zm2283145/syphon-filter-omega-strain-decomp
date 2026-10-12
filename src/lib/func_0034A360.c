typedef struct S {
    int x0;
    char pad4[0x1C - 4];
    int x1C;
    char pad20[0x3C - 0x20];
    int x3C;
} S;
extern int func_0034A6E8(S *p, S **q, unsigned char *c);

int func_0034A360(S *p, unsigned char a, unsigned char b, unsigned char *out)
{
    S *q;
    unsigned char c;
    int r;

    if (!out)
        return 2;
    *out = 0;
    if (!p)
        return 2;
    if (a == 1) {
        q = 0;
        if (b == 0) {
            c = 0;
            r = func_0034A6E8(p, &q, &c);
            if (r)
                return r;
            *out = c;
            return 0;
        }
        q = (S *)(p->x1C + p->x3C);
        if (q->x0 == 1 && q->x3C == 1)
            *out = 1;
        else
            *out = 0;
    } else {
        if (p->x0 > 0)
            *out = 1;
        else
            *out = 0;
    }
    return 0;
}
