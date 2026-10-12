/* volatile fields keep the retail source-order stores (no store scheduling) */
typedef struct { volatile int f[21]; } Cfg4430;
extern void *memset(void *d, int c, unsigned int n);
int func_00314430(Cfg4430 *c)
{
    if (c == 0) return 0x17;
    memset((void *)c, 0, 0x54);
    c->f[1] = 0;
    c->f[0] = 1;
    c->f[9] = 16;
    c->f[10] = 8000;
    c->f[2] = 1;
    c->f[3] = 1;
    c->f[4] = 0;
    c->f[5] = 1;
    c->f[6] = 16;
    c->f[7] = 8000;
    c->f[8] = 1;
    c->f[11] = 0;
    c->f[12] = 0;
    c->f[13] = 0;
    c->f[14] = 0;
    c->f[15] = 0;
    c->f[16] = 0;
    c->f[17] = 0;
    c->f[18] = 0;
    c->f[19] = 0;
    c->f[20] = 0;
    return 0;
}
