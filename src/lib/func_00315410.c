typedef struct { char pad[4]; unsigned char b4; unsigned char b5; unsigned char b6; } Ent5410;
typedef struct { char pad[0xA4]; int sock; } Obj5410;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_002E6088(int h);
extern int func_00315028(int id, Obj5410 **out);
extern int func_003151D8(Obj5410 *o, int i, Ent5410 **out);
extern void func_002F4FF0(int sock, int sz);
int func_00315410(int id, int sz)
{
    Obj5410 *o;
    Ent5410 *e;
    int ok, st, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    st = func_002E6088(sz);
    if (st != ok) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    r = func_003151D8(o, sz, &e);
    if (r != 0) return r;
    if (e->b5 == st) {
        func_002F4FF0(o->sock, sz);
        e->b5 = 0;
    }
    e->b4 = 0;
    e->b6 = 0;
    return 0;
}
