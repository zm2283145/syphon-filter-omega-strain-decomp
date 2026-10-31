#define UNCACHED(p) (((unsigned int)(p) & 0x0fffffff) | 0x20000000)

void _initRefImages(int *p0, int *p1, int *p2, int *p3, int *p4, int *p5,
                    int *p6, int *p7, int *p8, char *y, char *cb, char *cr,
                    int w, int h)
{
    int n;
    int a, b, c;
    *p0 = UNCACHED(y);
    *p1 = UNCACHED(cb);
    *p2 = UNCACHED(cr);
    *p3 = UNCACHED(y);
    *p4 = UNCACHED(cb);
    *p5 = UNCACHED(cr);
    n = w * h / 512;
    a = n * 384; a += (int)y;
    b = n * 384; b += (int)cb;
    c = n * 384; c += (int)cr;
    *p6 = UNCACHED(a);
    *p7 = UNCACHED(b);
    *p8 = UNCACHED(c);
}
