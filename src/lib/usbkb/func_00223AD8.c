typedef struct { int state; int cnt; int f8; int fc; } S223AD8;
typedef struct { int f0; int f4; int f8; int mode; S223AD8 s; char pad[0x18]; } E223AD8;
typedef struct { int count; E223AD8* tbl; } G223AD8;
extern G223AD8 D_004F5780;
int func_00223AD8(void)
{
    int i;
    for (i = 0; i < D_004F5780.count; i++) {
        S223AD8* p = &D_004F5780.tbl[i].s;
        if (p->f8 > 0 && p->fc > 0 && p->state != 0 && p->state >= 0 && p->state < 3) p->cnt++;
    }
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}
