typedef struct { char pad[0xA4]; int sock; char pad2[1]; unsigned char mode; } Obj4208;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj4208 **out);
extern int func_002F5050(int sock);
int func_00314208(int id, int *out)
{
    Obj4208 *o;
    int st;
    int r;
    if (D_00491432 <= 0) return 0x11;
    st = D_00491430;
    if (st != 1) return 0x11;
    if (out == 0) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if ((func_002F5050(o->sock) & 8) && o->mode == st) *out = o->mode;
    else *out = 0;
    return 0;
}
