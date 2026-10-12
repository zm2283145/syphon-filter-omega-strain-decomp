typedef struct { int a; int b; int result; int user; } Req5C60;
typedef struct Obj5C60 {
    char pad0[9];
    unsigned char state;
    char pad1[0x5C - 10];
    void (*cb)(Req5C60 *);
    int user;
    char pad2[0xA9 - 0x64];
    unsigned char mode;
} Obj5C60;
extern int func_003150D0(int id, Obj5C60 **out);
int func_00315C60(int id, int a, int b)
{
    Obj5C60 *o = 0;
    Req5C60 r;
    if (b == 0) return -1;
    if (func_003150D0(id, &o) != 0) return -1;
    r.result = 0;
    if (o->cb && o->state == 1 && o->mode == 1) {
        int u = o->user;
        r.a = a;
        r.b = b;
        r.user = u;
        o->cb(&r);
    }
    return r.result;
}
