typedef struct {
    volatile unsigned int chcr; unsigned int p0[3];
    volatile unsigned int madr; unsigned int p1[3];
    volatile unsigned int qwc; unsigned int p2[3];
    volatile unsigned int tadr; unsigned int p3[3];
    volatile unsigned int asr0; unsigned int p4[3];
    volatile unsigned int asr1; unsigned int p5[3];
    unsigned int p6[8];
    volatile unsigned int sadr; unsigned int p7[3];
} DmaChan;

typedef struct { unsigned char d[0x14]; } sceDmaEnv;

extern DmaChan *D_00485EE0[10];
extern int D_00498320[10];
extern void func_00103D08(void *, int);
extern int func_00103E48(sceDmaEnv *);

int func_00103D68(int mode)
{
    sceDmaEnv env;
    int ret = *(volatile unsigned int *)0x1000E000 & 1;
    int i;
    for (i = 0; i < 10; i++) {
        if (D_00498320[i]) {
            DmaChan *d = D_00485EE0[i];
            d->sadr = 0;
            d->chcr = 0;
            d->tadr = 0;
            d->madr = 0;
            d->asr1 = 0;
            d->asr0 = 0;
        }
    }
    *(unsigned int *)0x1000E010 = 0xFF1F;
    *(unsigned int *)0x1000E010 = *(volatile unsigned int *)0x1000E010 & 0xFF1F0000;
    func_00103D08(&env, sizeof(env));
    func_00103E48(&env);
    if (mode == 1)
        *(volatile unsigned int *)0x1000E000 |= 1;
    return ret;
}

