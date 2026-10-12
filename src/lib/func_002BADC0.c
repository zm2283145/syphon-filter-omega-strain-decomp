typedef struct { int a; int b; int s; int c; char d[0x2000]; } R;
typedef struct { char pad0[0x2A]; unsigned short m; unsigned short n; char pad2E[6]; int base; char pad38[0x14C]; } Info;
extern R D_005141C0[];
extern Info D_0048BD90[];
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002BAD48(int);
int func_002BADC0(int i, char *src, int blk)
{
    Info *p = &D_0048BD90[i];
    int sec = blk + p->base;
    int s = sec * p->m / p->n;
    int r;
    if (D_005141C0[i].a == -1) {
        D_005141C0[i].a = sec;
        D_005141C0[i].b = sec;
        D_005141C0[i].s = s;
        D_005141C0[i].c = 0;
        memcpy(D_005141C0[i].d, src, 0x400);
        D_005141C0[i].c++;
        return 1;
    }
    if (sec == D_005141C0[i].b + 1 && D_005141C0[i].c < 8 && D_005141C0[i].s == s) {
        D_005141C0[i].b = sec;
        memcpy(D_005141C0[i].d + D_005141C0[i].c * 0x400, src, 0x400);
        D_005141C0[i].c++;
        return 1;
    }
    r = func_002BAD48(i);
    D_005141C0[i].a = sec;
    D_005141C0[i].b = sec;
    D_005141C0[i].s = s;
    D_005141C0[i].c = 0;
    memcpy(D_005141C0[i].d, src, 0x400);
    D_005141C0[i].c++;
    return r;
}
