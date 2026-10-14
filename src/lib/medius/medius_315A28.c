typedef struct { int handle; int a; int b; int result; int user; } Req5A28;
typedef struct Obj5A28 {
    char pad0[9];
    unsigned char state;
    char pad1[0x3C - 10];
    void (*cb)(Req5A28 *);
    int user;
    char pad2[0xA9 - 0x44];
    unsigned char mode;
} Obj5A28;
extern int func_003150D0(int id, Obj5A28 **out);
extern int func_00315608(int handle, int dst);
int func_00315A28(int id, int dst, int a, int b)
{
    Obj5A28 *o = 0;
    Req5A28 r;
    if (a == 0) return 0;
    if (dst == 0) return 0;
    if (func_003150D0(id, &o) != 0) return 0;
    r.handle = 0;
    r.result = 0;
    if (o->cb && o->state == 1 && o->mode == 1) {
        int u = o->user;
        r.a = a;
        r.b = b;
        r.user = u;
        o->cb(&r);
    }
    if (func_00315608(r.handle, dst) != 0) return 0;
    return r.result;
}
