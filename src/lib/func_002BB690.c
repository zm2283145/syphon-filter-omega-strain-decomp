typedef struct { int count, max_count, init_count, wait_threads, attr, option; } P2BB690;
typedef struct { int x0, x4, x8, xC, x10, x14, x18; } E2BB690;
extern int D_0048C098;
extern int D_00518A00[];
extern E2BB690 D_00518A08[];
extern int CreateSema(P2BB690 *);
int _sceMcCoreInit(void)
{
    P2BB690 p;
    int i;
    D_0048C098 = 0;
    p.init_count = 0;
    p.max_count = 0x7F;
    p.option = 0;
    D_00518A00[0] = CreateSema(&p);
    p.max_count = 0x7F;
    p.init_count = 0;
    p.option = 0;
    D_00518A00[1] = CreateSema(&p);
    for (i = 0; i < 2; i++) {
        D_00518A08[i].x0 = 0;
        D_00518A08[i].x8 = 0x200;
        D_00518A08[i].xC = 0x10;
        D_00518A08[i].x10 = 0x4000;
    }
    return 1;
}
