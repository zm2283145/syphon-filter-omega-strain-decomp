#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int D_004908F8;
extern int func_002FE810(int, void **);
extern int func_002F5818(void *, int *);
extern int func_00301220(int);
extern int func_002F5618(int, void *, int);
extern void func_00300AE8(void *, int, int, int);
extern void func_00301038(void *, int);
extern void func_002FED28(void *);
extern void func_002F5DB0(int);
extern void func_002FE5A8(int);
int func_002FCE88(unsigned short id)
{
    void *c = 0;
    int x = 0;
    unsigned char st = D_004908EC;
    int r;
    unsigned int i;
    void *q, *e;
    if (st != 1) return 5;
    r = func_002FE810(id, &c);
    if (r != 0) return r;
    if (c != 0) {
    if (F(c, int, 8) != st) {
        if (F(c, int, 8) == 8) {
            q = F(c, void *, 0x80);
            if (q != 0 && func_002F5818((char *)q + 0x68, &x) == 0) {
                if (x != 0) {
                    func_00301220(x);
                    if (func_002F5618(D_004908F8, (char *)q + 0x68, x) == 0)
                        func_00300AE8(q, D_004908F8, x, 10000);
                }
                func_00301038(c, 9);
                func_002FED28(q);
            }
        }
        func_00301038(c, 10);
        for (i = 0; i < 2; i++) {
            q = ((struct { char pad[0x70]; void *arr[2]; } *)((char *)c + 8))->arr[i];
            if (q) func_002F5DB0(F(q, int, 0x1C));
        }
        func_00301038(c, 1);
    }
    func_002FE5A8(id);
    }
    return 0;
}

