#define F_(b, o, T) (*(T *)((char *)(b) + (o)))

extern void *memset(void *, int, unsigned int);
extern void func_0010BD90(void *, const char *);
extern void func_0010B5D0(void *, void *, int);
extern int func_0010B608(void *, void *, int, int);
extern void func_0010BC20(void *);
extern void func_0010B398(void *);
extern int func_0010B3F8(void *);
extern void func_0010B5E8(void *);
extern int func_0010C698();
extern int func_0010C6C0();
extern char D_004986A0[];

int func_0010AFF8(char *mp, char *work, int size)
{
    char *p;
    unsigned int rem;

    memset(work, 0, size);
    p = (char *)(((unsigned int)work + 3) >> 2 << 2);
    rem = size - (p - work);
    if (rem < 0x10C0) {
        func_0010BD90(p, D_004986A0);
        return 0;
    }
    F_(mp, 0x40, char *) = p;
    func_0010B5D0(p + 0x120, p + 0x10C0, rem - 0x10C0);
    F_(mp, 0x0, int) = 0;
    F_(mp, 0x4, int) = 0;
    F_(mp, 0x8, int) = 0;
    F_(mp, 0x10, long) = -1;
    F_(mp, 0x18, long) = -1;
    F_(mp, 0x20, long) = 0;
    F_(mp, 0x28, long) = -1;
    F_(mp, 0x30, long) = -1;
    F_(mp, 0x38, long) = 0;
    F_(p, 0xCC, int) = 0;
    F_(p, 0xD0, int) = 0;
    F_(p, 0xD4, int) = 0;
    F_(p, 0xD8, int) = 0;
    F_(p, 0xDC, int) = 0;
    F_(p, 0xE0, int) = 0;
    F_(p, 0xE4, int) = 0;
    F_(p, 0xE8, int) = 0;
    F_(p, 0xEC, int) = 0;
    F_(p, 0xF0, int) = 0;
    F_(p, 0xF4, int) = 0;
    F_(p, 0xF8, int) = 0;
    F_(p, 0xFC, int) = 0;
    F_(p, 0x100, int) = 0;
    F_(p, 0x110, int) = 0;
    F_(p, 0xC, int) = 0;
    F_(p, 0x18, int) = 0;
    F_(p, 0x3C, int) = 0;
    F_(p, 0x48, int) = 0;
    F_(p, 0x54, int) = 0;
    F_(p, 0x108, long) = -1;
    F_(p, 0x24, void *) = func_0010C698;
    F_(p, 0x30, void *) = func_0010C6C0;
    F_(p, 0x60, int) = func_0010B608(p, p + 0x120, 0x800, 8);
    F_(p, 0x64, int) = 0;
    F_(p, 0x114, int) = 0;
    F_(p, 0x118, int) = 0;
    F_(p, 0x11C, int) = 0;
    F_(p, 0x8C, int) = 0;
    F_(p, 0x90, long) = 0;
    F_(p, 0x98, int) = -1;
    F_(p, 0xA0, long) = 0;
    F_(p, 0xA8, int) = 0;
    F_(p, 0xC4, int) = 0;
    F_(p, 0xAC, int) = -1;
    F_(p, 0xB0, int) = -1;
    F_(p, 0xB4, int) = -1;
    F_(p, 0x870, char *) = mp;
    F_(p, 0xC8, int) = 1;
    func_0010BC20(p);
    func_0010B398(mp);
    func_0010B3F8(mp);
    F_(p, 0x1D0, char *) = p + 0x200;
    F_(p, 0x1D4, char *) = p + 0x268;
    F_(p, 0x1DC, char *) = p + 0x2D0;
    F_(p, 0x1E0, char *) = p + 0x338;
    F_(p, 0x1E4, char *) = p + 0x3A0;
    F_(p, 0x1EC, char *) = p + 0x408;
    F_(p, 0x1F0, char *) = p + 0x470;
    F_(p, 0x1F4, char *) = p + 0x4D8;
    F_(p, 0x1FC, char *) = p + 0x540;
    func_0010B5E8(p + 0x120);
    F_(p, 0x868, int) = -1;
    F_(p, 0x864, int) = 0;
    F_(p, 0x834, int) = 0x70003600;
    F_(p, 0x86C, int) = 0;
    return 1;
}



