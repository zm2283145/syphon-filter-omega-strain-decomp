typedef struct { char pad[9]; unsigned char state; char pad2[0xA4 - 10]; int sock; } Obj44C8;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj44C8 **out);
extern int func_002F5068(int sock);
extern int func_00315E28(int r, int code);
int func_003144C8(int id, unsigned char st)
{
    Obj44C8 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    o->state = st;
    r = func_002F5068(o->sock);
    o->state = ok;
    return func_00315E28(r, 0x2A);
}
