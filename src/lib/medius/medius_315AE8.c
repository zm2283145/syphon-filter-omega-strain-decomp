typedef struct { int handle; int a; void * b; void * c; int result; void * user; } Req5AE8;
typedef struct Obj5AE8 {
    char pad0[9];
    unsigned char state;
    char pad1[0x44 - 10];
    void * cb;
    void * user;
    char pad2[0xA9 - 0x4C];
    unsigned char mode;
} Obj5AE8;
extern int func_003150D0(int id, Obj5AE8 **out);
/* weak stub: the callee was defined in the original unit (gives retail delay-slot choices); discarded at link */
int __attribute__((weak, section(".dtors_drop"))) func_003156A0(int src, Req5AE8 *req) { return 0; }
int func_00315AE8(int id, int src, int a, void * b, int c)
{
    Obj5AE8 *o = 0;
    Req5AE8 r;
    if (b == 0) return c;
    if (func_003150D0(id, &o) != 0) return c;
    r.result = c;
    if (o->cb && o->state == 1 && o->mode == 1) {
        void * u;
        void (*f)(Req5AE8 *);
        if (func_003156A0(src, &r) != 0) return c;
        r.a = a;
        u = o->user;
        r.b = b;
        r.c = c;
        r.user = u;
        f = (void (*)(Req5AE8 *))o->cb;
        f(&r);
    }
    return r.result;
}

