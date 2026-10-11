extern char D_004BADB8[], D_004BADC0[], D_004BAF18[];
extern int func_0010F388(const char *, ...);
extern int func_0010D520(void *, int);
extern int func_0010D500(int);
int func_003532F8(int a, int b, int size, int wait)
{
    struct { int a, b, size, x; } p;
    int r;
    p.a = a;
    p.b = b;
    p.size = (size + 0xF) & ~0xF;
    p.x = 0;
    if (size & 0xF) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAF18, size, p.size);
    }
    do {
        r = func_0010D520(&p, 1);
    } while (r == 0);
    if (!wait)
        while (func_0010D500(r) >= 0)
            ;
    return r;
}
