typedef struct { char pad[0x14]; char x14[0x40]; void *x54; } Sock9728;
typedef struct { char pad[0xC]; int xC; int x10; int x14; char x18[0x10]; int x28; } Req9728;
extern void *memset(void *, int, unsigned int);
extern int func_0034ACC8(void *, int, void *);
extern int func_0034AD40(void *, int, int, int);
extern int func_00358578(int);

int func_00359728(Sock9728 *s, Req9728 *r)
{
    int n;
    if (r->xC != 0) return 0;
    if (r->x10 != 0 && r->x10 != 3) return 0x80;
    memset(r->x18, 0, 0x10);
    r->x28 = 0;
    if (r->x14 == 0) r->x14 = -1;
    n = func_0034ACC8(s->x14, (int)s->x54, &r->x10);
    if (n > 0) {
        r->xC = n;
        n = func_0034AD40(s->x14, (int)s->x54, n, -1);
        if (n >= 0) goto ok;
    }
    return func_00358578(n);
ok:
    return 0;
}
