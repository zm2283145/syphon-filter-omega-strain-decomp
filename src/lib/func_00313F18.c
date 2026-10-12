typedef struct { int id; unsigned int idx; int val; } Res3F18;
typedef struct {
    char pad[0x18];
    unsigned int count;
    char pad2[0xA4 - 0x1C];
    int sock;
    char pad3[0x208 - 0xA8];
    unsigned char state;
    char pad4[3];
    Res3F18 res;
} Obj3F18;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj3F18 **out);
extern int func_002F50C0(int sock, int (*cb)(), int arg);
extern int func_003158D8();
extern int func_00315E28(int r, int code);
int func_00313F18(int id, unsigned int idx, Res3F18 *out)
{
    Obj3F18 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (out == 0) return 0x17;
    if (idx >= 64) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if (idx >= o->count) return 0x17;
    o->state = ok;
    o->res.id = id;
    o->res.idx = idx;
    r = func_002F50C0(o->sock, func_003158D8, 0);
    if (o->state == ok) return 0x29;
    o->state = 0;
    r = func_00315E28(r, 0x2A);
    if (r != 0) return r;
    *out = o->res;
    return r;
}
