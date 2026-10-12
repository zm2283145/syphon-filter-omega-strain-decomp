typedef struct { int a; int b; int c; int result; int user; } Req5BB0;
typedef struct Obj5BB0 {
    char pad0[9];
    unsigned char state;
    char pad1[0x54 - 10];
    void (*cb)(Req5BB0 *);
    int user;
    char pad2[0xA9 - 0x5C];
    unsigned char mode;
} Obj5BB0;
extern int func_003150D0(int id, Obj5BB0 **out);
int func_00315BB0(int id, int a, int b, int c)
{
    Obj5BB0 *o = 0;
    Req5BB0 r;
    if (a == 0) return -1;
    if (b == 0) return -1;
    if (c == 0) return -1;
    if (func_003150D0(id, &o) != 0) return -1;
    r.result = 0;
    if (o->cb && o->state == 1 && o->mode == 1) {
        r.user = o->user;
        r.a = a;
        r.b = b;
        r.c = c;
        o->cb(&r);
    }
    return r.result;
}
