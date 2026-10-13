extern char *strncpy(char *, const char *, unsigned int);
typedef struct { char p0[0xC]; int xC; char x10[0x48]; int x58; } A;
typedef struct { unsigned short x0, x2, x4, x6; char x8[0x3C]; } B;
void func_002EDC60(A *a, B *b)
{
    unsigned short u, v;
    u = a->x58;
    v = a->xC;
    b->x0 = 0x44;
    b->x4 = u;
    b->x2 = v;
    b->x6 = u;
    strncpy(b->x8, a->x10, 0x3C);
    b->x8[0x3B] = 0;
}
