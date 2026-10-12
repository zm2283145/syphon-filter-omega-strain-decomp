typedef struct { unsigned char type; unsigned char x; unsigned short c; unsigned short port; unsigned short y; } M2DA290;
extern char *func_002DA3A0(char *);
extern unsigned char func_002ED938(char *);
extern unsigned short func_002D8B20(char *);
extern void func_002ED940(char *, int, M2DA290 *, int, int);
extern void func_002D8AE8(char *);
int func_002DA290(char *s, int b, int c)
{
    M2DA290 m; int t;
    char *h = func_002DA3A0(s);
    if (h == 0) return 0;
    t = 0xB0; m.type = t;
    m.port = *(unsigned short *)(s + 0x78);
    m.x = func_002ED938(h);
    m.c = c;
    m.y = func_002D8B20(s);
    func_002ED940(h, *(int *)(s + 0x78), &m, b, m.c);
    if (c == 0) func_002D8AE8(s);
    return c;
}
