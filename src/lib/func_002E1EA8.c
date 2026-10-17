typedef struct { int a; unsigned short id; short p; int type; void *cb; int time; int x; int y; } E;
typedef struct { int f0; unsigned char slot; unsigned char f5; char pad[2]; } M;
extern E D_0058D188[];
extern unsigned short D_0058C0B0;
extern int D_005983DC;
extern int Net_SendLocked(int, int, int, int, int, int, void *);
extern int func_002E1BA0(void);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern void *func_002E54A0(unsigned int);
extern int func_002DDAC8(int *);
extern int func_002DD380(void *, void *);

int func_002E1EA8(unsigned int a0, unsigned int a1, void *cb)
{
    M m;
    void *p = 0;
    int slot;
    int r;

    if (a0 >= 4) return 0x17;
    if (a1 >= 0x100 && a1 != 0xFFFF) return 0x17;
    if (cb == 0) return 0x17;
    if (a1 == (unsigned int)-1) return 8;
    slot = func_002E1BA0();
    if (slot == 0x7F) return 0x19;
    m.f5 = 1;
    m.f0 = 0;
    m.slot = slot;
    Net_SendLocked(-0x80, a0, a1, 0, D_005983DC, 8, &m);
    if (a1 == 0xFFFF) {
        r = func_002DD380(&D_0058D188[slot], func_002E54A0(a0));
        if (r != 0) return r;
        D_0058D188[slot].id = D_0058C0B0;
        D_0058D188[slot].x = 4;
        D_0058D188[slot].y = 0x100;
    } else {
        r = func_002E52D8(a0, a1, &p);
        if (r != 0) return r;
        if (p == 0) return r;
        r = func_002DD380(&D_0058D188[slot], p);
        if (r != 0) return r;
        D_0058D188[slot].x = a0;
        D_0058D188[slot].id = *(unsigned short *)((char *)p + 0x10);
        D_0058D188[slot].y = a1;
    }
    D_0058D188[slot].cb = cb;
    D_0058D188[slot].type = 0;
    func_002DDAC8(&D_0058D188[slot].time);
    return 0;
}
