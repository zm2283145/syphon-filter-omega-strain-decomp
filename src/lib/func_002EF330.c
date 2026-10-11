#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { short type; short id; unsigned short count; short pad; int self; int pad2; } H2EF330;
typedef struct { int key; int a; int used; int b; int c; } E2EF330;
extern int func_002DA900(void *, int *);
extern int func_002DA910(int);
extern void func_002EDD08(void *, void *, int, int);
extern int func_002D9A30(int, int, void *, void *, int);
int func_002EF330(void *s, int key, int force)
{
    char buf[16];
    H2EF330 h;
    int me = 0xFFFF;
    int n, c;
    E2EF330 *e;
    func_002DA900(F(s, void *, 8), &me);
    h.self = me;
    h.id = func_002DA910(F(s, int, 8));
    h.type = 0xC;
    h.count = 0;
    n = F(s, int, 0x5C);
    if (n > 0) {
        e = F(s, E2EF330 *, 0x60);
        c = 0;
        for (; n != 0; n--, e++)
            if (e->used == 0 || e->key == key) c++;
        h.count = c;
    }
    if (h.count == 0 && F(s, int, 0x58) == 0) h.count++;
    if (force != 0 || h.count != 0) {
        func_002EDD08(s, buf, 5, 0xC);
        return func_002D9A30(F(s, int, 8), key, buf, &h, 0xC);
    }
    return 0;
}