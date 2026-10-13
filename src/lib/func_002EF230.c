#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int key; int a; int used; int b; int c; } E2EF230;
extern int func_002DA900(void *, int *);
extern int func_002D8AD8(int);
extern int func_002F3BE8(int);
extern int func_002F3BF8(int);
extern int func_002F33D8(void *);
void func_002EF230(void *s)
{
    int me = 0xFFFF;
    int h, a, i;
    func_002DA900(F(s, void *, 8), &me);
    for (i = 0; i < F(s, int, 0x5C); i++)
        if (F(s, E2EF230 *, 0x60)[i].used == 2) break;
    if (i < F(s, int, 0x5C)) {
        h = func_002D8AD8(F(s, int, 8));
        a = func_002F3BE8(h);
        if (func_002F3BF8(h) < a) goto one;
        if (func_002F33D8((char *)s + 0x50) <= a + 1) goto one;
    }
    F(s, int, 0x68) = 0;
    return;
one:
    F(s, int, 0x68) = 1;
}



