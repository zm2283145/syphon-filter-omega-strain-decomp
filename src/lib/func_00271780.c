typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam1780;
typedef struct E1780 { char p0[0x14]; int x14; int x18; int x1C; int x20; int x24; } E1780;
typedef struct { int x0; int x4; int x8; int xC; int x10; char p[0x10]; int x24; int x28; int x2C; } C1780;
extern char D_004A8CF0[];
extern char D_004FFB00[];
extern int scePrintf(const char *, ...);
extern void WaitSema(int);
extern void DeleteSema(int);
extern E1780 *func_002713C0(void *);
extern int CreateSema(SemaParam1780 *);
extern void func_00271468(E1780 *);
extern int func_0010F948(unsigned int, void *, int, int, int, int);
int func_00271780(C1780 *c, int a1)
{
    SemaParam1780 sp;
    E1780 *e;
    int s;
    if (a1) {
        scePrintf(D_004A8CF0);
        return -1;
    }
    WaitSema(c->x28);
    e = func_002713C0(D_004FFB00);
    if (e == 0) return -1;
    c->x4 = e->x18;
    c->x0 = (int)e;
    e->x20 = c->x10;
    e->x14 = (int)e;
    e->x1C = (int)c;
    e->x24 = c->x24;
    sp.initCount = 0;
    sp.maxCount = 1;
    sp.option = 0;
    s = CreateSema(&sp);
    c->x8 = s;
    if (s < 0) {
        func_00271468(e);
        return -3;
    }
    if (func_0010F948(0x8000001D, e, 0x40, 0, 0, 0) == 0) {
        func_00271468(e);
        DeleteSema(s);
        return -2;
    }
    WaitSema(s);
    DeleteSema(s);
    DeleteSema(c->x28);
    return c->x2C;
}