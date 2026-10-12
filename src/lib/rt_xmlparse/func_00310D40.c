extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0E50[];
extern char D_004B0E68[];
extern char D_004B0E90[];
extern char D_004B0EA8[];
extern char D_004B0EC0[];
extern char D_004B0ED8[];
extern char D_004B0F00[];
extern int func_00127358(const char *, ...);
extern int Net_AllocZeroed(void **pp, unsigned long size);
extern int func_002FB2D8(void **pp, unsigned long size);
extern void func_002FB3C0(void *pp);
typedef struct { char pad[0x8000]; unsigned int size; char pad2[0x8410 - 0x8004]; int x8410; } Ctx310D40;
int func_00310D40(Ctx310D40 **out, int flags, unsigned int size)
{
    Ctx310D40 *c = 0;
    void *h = 0;
    int r;
    if (out == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0xF4, D_004B0E50);
        return 3;
    }
    *out = 0;
    if (flags) {
        func_00127358(D_004B0DE0, D_004B0E18, 0xF6, D_004B0E68);
        return 6;
    }
    if (size == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0xF7, D_004B0E90);
        return 3;
    }
    r = Net_AllocZeroed((void **)&c, 0x8C2C);
    if (c == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0xFB, D_004B0EA8);
        return 2;
    }
    if (r) {
        func_00127358(D_004B0DE0, D_004B0E18, 0xFC, D_004B0EC0);
        return 2;
    }
    c->x8410 = 0x18;
    c->size = size;
    r = func_002FB2D8(&h, c->size);
    if (c == 0 || r != 0) {
        if (D_004B0ED8)
            func_00127358(D_004B0DE0, D_004B0E18, 0x104, D_004B0F00);
        func_002FB3C0(&c);
        return 2;
    }
    func_002FB3C0(&h);
    *out = c;
    return 0;
}