typedef struct {
    unsigned short id; short pad;
    int f4;
    int f8;
    char pad2[0x84 - 0xC];
    void (*cb)(unsigned short, int, int, int, int);
} O;
extern int func_002FE860(unsigned short, O **);
extern int func_002FDAE8(O *, unsigned char);
extern int func_00301060(int);
extern int func_002FE7C0(unsigned short);
extern int func_00301038(O *, int);
int func_002FDA18(unsigned short id, unsigned char k)
{
    O *o[1];
    int r;
    o[0] = 0;
    r = func_002FE860(id, o);
    if (r) return r;
    r = func_002FDAE8(o[0], k);
    if (r != 0 && k == 1 && func_00301060(o[0]->f8) == 1) {
    if (o[0]->cb) {
        unsigned short h = o[0]->id;
        o[0]->cb(id, 0, 0, 0, 1);
        if (func_002FE7C0(h) == 0) return 0xB;
    }
    func_00301038(o[0], 0xB);
    }
    return r;
}

