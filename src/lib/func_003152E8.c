typedef struct { char pad[4]; unsigned char b4; unsigned char b5; unsigned char b6; } Ent52E8;
typedef struct {
    char pad[0xA];
    unsigned char mode;
    char pad1[0xA4 - 0xB];
    int sock;
    unsigned char bA8;
    unsigned char bA9;
    char pad2[2];
    char info[0x14];
} Obj52E8;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_002E6088(int h);
extern int func_00315028(int id, Obj52E8 **out);
extern int func_002F4F90(int sock, int *out);
extern int func_002F4FB0(int sock, int sz, char *info);
extern int func_003151D8(Obj52E8 *o, int i, Ent52E8 **out);
extern int func_00315818(Obj52E8 *o, Ent52E8 *e);
extern int func_00315E28(int r, int code);
int func_003152E8(int id, int sz)
{
    Obj52E8 *o;
    int x;
    Ent52E8 *e;
    int ok, st, m, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    st = func_002E6088(sz);
    if (st != ok) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    m = o->mode;
    if (m != st) return 0x29;
    r = func_00315E28(func_002F4F90(o->sock, &x), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FB0(o->sock, x, o->info), 0x2A);
    if (r != 0) return r;
    r = func_003151D8(o, sz, &e);
    if (r != 0) return r;
    e->b4 = m;
    if (o->bA9 == m) {
        r = func_00315818(o, e);
        if (r != 0) return r;
    }
    return 0;
}
