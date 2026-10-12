typedef struct { int pad; int id; int h; int flag; } Arg42A0;
typedef struct { char pad[0xA4]; int sock; } Obj42A0;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj42A0 **out);
extern int func_002E6088(int h);
extern int func_002F5008(int sock, int h, int mode);
extern int func_00315E28(int r, int code);
int func_003142A0(Arg42A0 *a)
{
    Obj42A0 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (a == 0) return 0x17;
    if (func_002E6088(a->h) != ok) return 0x17;
    r = func_00315028(a->id, &o);
    if (r != 0) return r;
    if (a->flag) {
        r = func_00315E28(func_002F5008(o->sock, a->h, 3), 0x2A);
        if (r != 0) return r;
    } else {
        r = func_00315E28(func_002F5008(o->sock, a->h, 0), 0x2A);
        if (r != 0) return r;
    }
    return 0;
}
