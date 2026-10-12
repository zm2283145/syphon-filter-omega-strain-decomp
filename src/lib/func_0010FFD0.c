typedef struct { char p0[0x10]; unsigned int x10; int x14; char p1[4]; int x1C; unsigned int x20; int x24; int x28; int x2C; } RFFD0;
extern RFFD0 *func_0010FE50(int);
extern RFFD0 *func_0010FE80(int, unsigned int);
extern int func_0010F988(unsigned int, void *, int, int, int, int);
extern void func_00117F48(int, void *, void *);
extern void func_0010FF90(void);
void func_0010FFD0(RFFD0 *p, int b)
{
    RFFD0 *r;
    if (p->x10 & 4) r = func_0010FE80(b, p->x10 >> 16);
    else r = func_0010FE50(b);
    { int t14 = p->x14; int t1C = p->x1C; r->x14 = t14; r->x1C = t1C; }
    r->x20 = 0x8000000C;
    r->x24 = p->x20;
    r->x28 = p->x24;
    r->x2C = p->x28;
    if (func_0010F988(0x80000008, r, 0x40, p->x20, p->x24, p->x28) == 0) func_00117F48(0x800, func_0010FF90, r);
}