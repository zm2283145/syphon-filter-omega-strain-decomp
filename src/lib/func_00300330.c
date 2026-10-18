#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern int func_003019B0(unsigned char *, unsigned short *);
extern int func_002FEE78(void *, void *);
extern int func_00301038(void *, int);
extern void *memcpy(void *, const void *, unsigned int);
int func_00300330(void *s, int kind, unsigned char *src, unsigned int len)
{
    register int x asm("$20"); /* gcc296 allocation tie: pin x to $s4 like retail (cf. func_00300068.c) */
    unsigned char st = D_004908EC;
    int r;
    char *p;
    if (st != 1) return 5;
    r = func_002FE720();
    if (r != st) return 2;
    if (src == 0) return 2;
    x = F(s, int, 4);
    if (x != r) return r;
    p = F(s, char *, 0x7C);
    if (p == 0) return 9;
    if (len < 0x10) return r;
    memcpy(p + 8, src, 16);
    { unsigned char *a = src + 16; /* computed before the length check: lands in the beqz delay slot, and src dies before p+0x18 is formed */
    { unsigned int n = 0x11; if (n >= len) return r; } /* compare through a variable keeps retail's li/sltu */
    if (func_003019B0(a, (unsigned short *)(p + 0x18)) != 0) return 7; }
    if (F(p, unsigned short, 0x18) == 0) return 1;
    F(p, unsigned char, 5) = x;
    r = func_002FEE78(s, p);
    if (r != 0) return r;
    r = func_00301038(s, 6);
    __asm__ __volatile__(""); /* keeps the final call a jal (no tail call), as in retail */
    return r;
}
