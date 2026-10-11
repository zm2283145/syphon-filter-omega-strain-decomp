extern void *memset(void *, int, unsigned int);
typedef struct { int a0; int a4; char a8; char pad[11]; int a14, a18, a1C, a20, a24, a28, a2C, a30, a34; } S2E1500;
int func_002E1500(S2E1500 *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x38);
    p->a4 = -1;
    p->a1C = 2;
    p->a8 = 0;
    p->a14 = 0;
    p->a18 = 0;
    p->a20 = 0;
    p->a24 = 0;
    p->a28 = 0;
    p->a2C = 0;
    p->a30 = 0;
    p->a34 = 0;
    p->a0 = 1;
    return 0;
}
