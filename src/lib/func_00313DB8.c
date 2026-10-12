typedef struct { char pad[0x18]; unsigned int count; char pad2[0xA4 - 0x1C]; int sock; char pad3[0xFC - 0xA8]; int ids[64]; unsigned char busy; char pad4[3]; unsigned int cur; } Obj3DB8;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj3DB8 **out);
extern int func_002F5020(int sock, int h);
extern int func_00315E28(int r, int code);
int func_00313DB8(int id, unsigned int idx)
{
    Obj3DB8 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (idx >= 64) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if (idx >= o->count) return 0x17;
    o->cur = idx;
    r = func_00315E28(func_002F5020(o->sock, o->ids[o->cur]), 0x2A);
    if (r == 0) o->busy = ok;
    return r;
}
