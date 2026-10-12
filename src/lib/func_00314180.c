typedef struct { char pad[0xA4]; int sock; } Obj4180;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj4180 **out);
extern int func_00315608(int h, int *out);
extern int func_002F5080(int sock, int h, int a, int b);
extern int func_00315E28(int r, int code);
int func_00314180(int id, int h)
{
    Obj4180 *o;
    int t;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    r = func_00315608(h, &t);
    if (r != 0) return r;
    return func_00315E28(func_002F5080(o->sock, t, 0, 0), 0x2A);
}
