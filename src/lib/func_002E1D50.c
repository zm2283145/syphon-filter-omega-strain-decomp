typedef struct { int a; unsigned short id; short p; int type; void (*cb)(); int time; int x; int y; } E;
typedef struct { int f0; unsigned char slot; unsigned char f5; char pad[2]; } M;
extern E D_0058D188[];
extern int D_0048C450;
extern int D_0058806C;
extern int D_005983DC;
extern int Net_SendLocked(int, int, int, int, int, int, void *);
extern int func_002E1BA0(void);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern int func_002DDAC8(int *);
extern void func_002DD380(void *, void *);
extern void func_002E1BE8();

void func_002E1D50(unsigned int id)
{
    M m;
    void *p = 0;
    char s;

    if (id >= 0x100) return;
    m.f5 = 1;
    m.slot = func_002E1BA0();
    if ((char)m.slot == 0x7F) return;
    m.f0 = D_0058806C;
    Net_SendLocked(-0x80, D_0048C450, id, 0, D_005983DC, 8, &m);
    if (func_002E52D8(D_0048C450, id, &p) != 0) return;
    if (p == 0) return;
    func_002DDAC8(&D_0058D188[m.slot].time);
    func_002DD380(&D_0058D188[m.slot], p);
    D_0058D188[m.slot].id = *(unsigned short *)((char *)p + 0x10);
    D_0058D188[m.slot].cb = func_002E1BE8;
    D_0058D188[m.slot].type = 1;
    D_0058D188[m.slot].x = D_0048C450;
    D_0058D188[m.slot].y = id;
}


