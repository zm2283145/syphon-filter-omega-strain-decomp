typedef struct { volatile int f0; volatile int f4; volatile int f8; volatile int fC; char p[0x2C]; volatile int f3C; } H34A418;

/* Header init: returns 2 for a null pointer or a size below 0x80, else stores size-0x40 and zeroes the rest. */
int func_0034A418(H34A418 *p, unsigned int n) {
    H34A418 *h;
    if (p == 0) return 2;
    if (n < 0x80) return 2;
    if (n < 0x40) return 2;
    h = p;
    p = (H34A418 *)(n - 0x40);
    h->fC = (int)p;
    h->f3C = 0;
    h->f8 = (int)p;
    h->f4 = 0;
    h->f0 = 0;
    return 0;
}
