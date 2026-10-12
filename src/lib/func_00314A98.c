typedef struct { char pad[8]; unsigned char b8; unsigned char b9; unsigned char bA; char pad2; int size; char pad3[0xA4 - 0x10]; int sock; } Obj4A98;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj4A98 **out);
extern void func_002F4F60(int sock);
extern void func_002F5098(int sock);
extern int func_00314EA8(int id);
int func_00314A98(int id)
{
    Obj4A98 *o;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    func_002F4F60(o->sock);
    func_002F5098(o->sock);
    o->b8 = 0;
    o->bA = 0;
    o->size = 0x100;
    o->sock = 0;
    o->b9 = 0;
    func_00314EA8(id);
    return 0;
}
