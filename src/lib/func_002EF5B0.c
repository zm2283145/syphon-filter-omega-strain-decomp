#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int w[8]; } S2EF5B0;
typedef struct { int key; char *obj; int type; int b; int c; } E2EF5B0;
extern int func_002F3220(char *);
int func_002EF5B0(void *s, int (*cb)(void *, int, S2EF5B0 *), int arg)
{
    int i;
    E2EF5B0 *e;
    S2EF5B0 tmp;
    for (i = 0; i < F(s, int, 0x5C); i++) {
        e = &F(s, E2EF5B0 *, 0x60)[i];
        if (e->type != 2) continue;
        if (e->obj == 0) continue;
        tmp = *(S2EF5B0 *)(e->obj + 0x20);
        if (func_002F3220(e->obj) & 0x4000) tmp.w[6] |= 0x8000;
        else tmp.w[6] &= ~0x8000;
        if (cb(F(s, void *, 8), arg, &tmp) == 0) break;
    }
    return 0;
}