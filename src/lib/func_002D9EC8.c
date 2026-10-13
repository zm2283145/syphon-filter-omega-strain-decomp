typedef struct C {
    char pad0[0x34];
    int x34;
    char pad38[0x84C - 0x38];
    void *x84C;
} C;
typedef struct S S;
typedef void (*CB)(S *, int, int, char *, int);
struct S {
    char pad0[0x4C];
    CB cb4C;
};
extern int func_002DC288(void *);
/* weak never-linked stub (.dtors_drop is discarded at link): steers reorg delay-slot choice */
void * __attribute__((weak, section(".dtors_drop"))) func_002D8AD8(S *p0) { return 0; }
extern void func_002F3F00(void *, void *);
extern void *func_002F3CD0(void *, int);
extern int func_002DC620(void *, int, int, char *, int);
extern int func_002F3220(C *);
extern void func_002F3238(C *, int);

int func_002D9EC8(S *o, C *c, int x, int y, int flag)
{
    char buf[0x800];
    int r = 0;
    int n;
    if (c->x84C) {
        if (flag) {
            if (func_002DC288(c->x84C) != x) {
                func_002F3F00(func_002D8AD8(o), c->x84C);
                c->x84C = 0;
            }
        } else {
            x = func_002DC288(c->x84C);
        }
    }
    if (c->x84C == 0) {
        c->x84C = func_002F3CD0(func_002D8AD8(o), x);
        if (c->x84C == 0)
            return r;
    }
    n = func_002DC620(c->x84C, y, flag, buf, 0x800);
    if (n) {
        r = n;
        if (o->cb4C)
            o->cb4C(o, x, c->x34, buf, r);
    } else if (!flag && (func_002F3220(c) & 0x1000)) {
        func_002F3F00(func_002D8AD8(o), c->x84C);
        c->x84C = 0;
        func_002F3238(c, 0x1000);
        if (o->cb4C)
            o->cb4C(o, x, c->x34, buf, 0);
    }
    return r;
}

