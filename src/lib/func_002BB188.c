typedef struct { int a; int b; int s; int c; char d[0x2000]; } R;
typedef struct { char pad0[0x2A]; unsigned short m; unsigned short n; char pad2E[6]; int base; char pad38[0x14C]; } Info;
extern R D_005141C0[];
extern Info D_0048BD90[];
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002BACB8(int, char *, int, int);
int func_002BB188(int i, char *dst, int blk)
{
    int sec = blk + D_0048BD90[i].base;
    if (sec >= D_005141C0[i].a && sec < D_005141C0[i].a + D_005141C0[i].c) {
        memcpy(dst, D_005141C0[i].d + (sec - D_005141C0[i].a) * 0x400, 0x400);
        return 1;
    }
    return func_002BACB8(i, dst, sec, 1);
}
