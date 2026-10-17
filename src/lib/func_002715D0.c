typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam15D0;
typedef struct E15D0 { char p0[0x14]; int x14; int x18; int x1C; int x20; int x24; int x28; int x2C; } E15D0;
typedef struct { int x0; int x4; int x8; int xC; int x10; char p[0x10]; int x24; int x28; int x2C; int x30; int x34; int x38; } C15D0;
extern char D_004A8CF0[];
extern char D_004FFB00[];
extern int scePrintf(const char *, ...);
extern void WaitSema(int);
extern int DeleteSema(int);
extern E15D0 *func_002713C0(void *);
extern int CreateSema(SemaParam15D0 *);
extern void func_00271468(E15D0 *);
extern int func_0010F948(unsigned int, void *, int, int, int, int);
int func_002715D0(C15D0 *c, int a1, int a2, int a3, int a4, int a5)
{
    SemaParam15D0 sp;
    E15D0 *e;
    int s;
    if (a2) {
        scePrintf(D_004A8CF0);
        return -1;
    }
    sp.option = 0;
    sp.initCount = 1;
    sp.maxCount = 1;
    { int t = CreateSema(&sp);
    c->x28 = t;
    if (t < 0)
        return -3;
    WaitSema(t); }
    c->x10 = a1;
    c->x24 = 0;
    c->x30 = a3;
    c->x34 = a4;
    c->x38 = a5;
    e = func_002713C0(D_004FFB00);
    if (e == 0) {
        DeleteSema(c->x28);
        return -1;
    }
    {
        int token = e->x18;
        c->x0 = (int)e;
        c->x4 = token;
    }
    e->x20 = a1;
    e->x24 = a3;
    e->x28 = a4;
    e->x2C = a5;
    e->x14 = (int)e;
    e->x1C = (int)c;
    sp.maxCount = 1;
    sp.initCount = 0;
    sp.option = 0;
    s = CreateSema(&sp);
    c->x8 = s;
    if (s < 0) {
        func_00271468(e);
        DeleteSema(c->x28);
        return -3;
    }
    if (func_0010F948(0x80000019, e, 0x40, 0, 0, 0) == 0) {
        func_00271468(e);
        DeleteSema(s);
        DeleteSema(c->x28);
        return -2;
    }
    WaitSema(s);
    DeleteSema(s);
    if (c->x24 == 0)
        DeleteSema(c->x28);
    return 0;
}



