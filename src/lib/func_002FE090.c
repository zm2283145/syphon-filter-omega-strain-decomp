typedef struct { char p[5]; unsigned char f5; unsigned short f6; } B;
extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern int func_002FE8B0(B *);
extern int func_00300D68(B *);
extern int func_002FF308(unsigned short *, B *);
int func_002FE090(unsigned short *a, B *b, unsigned char c)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (func_002FE720() != 1) return 2;
    if (func_002FE8B0(b) != 1) return 2;
    if (b->f5 != 1) return 2;
    if (*a != b->f6) return 2;
    r = func_00300D68(b);
    if (r) return r;
    if (c == 1) {
        r = func_002FF308(a, b);
        if (r) return r;
    }
    return 0;
}

