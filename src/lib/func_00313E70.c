typedef struct { char pad[0x18]; unsigned int count; char pad2[0xA4 - 0x1C]; int sock; char pad3[0xFC - 0xA8]; int ids[64]; unsigned char busy; } Obj3E70;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj3E70 **out);
extern int func_002F5038(int sock, int h);
extern int func_00315E28(int r, int code);
int func_00313E70(int id, unsigned int idx)
{
    Obj3E70 *o;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    if (idx >= 64) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if (idx >= o->count) return 0x17;
    r = func_00315E28(func_002F5038(o->sock, o->ids[idx]), 0x2A);
    if (r == 0) o->busy = 0;
    return r;
}
