typedef struct {
    unsigned char sts;
    unsigned char std;
    unsigned char mfd;
    unsigned char rcycle;
    unsigned short express;
    unsigned short notify;
    unsigned short sqwc;
    unsigned short tqwc;
    void *rbadr;
    unsigned int rbmsk;
} sceDmaEnv;

static unsigned char D_00498348[10] = { 0, 0, 0, 3, 0, 1, 0, 0, 2, 0 };
static unsigned char D_00498358[10] = { 0, 1, 2, 0, 0, 0, 3, 0, 0, 0 };
static unsigned char D_00498368[10] = { 0, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
extern sceDmaEnv D_004E1DB8;

#define D_CTRL ((volatile unsigned int *)0x1000E000)
#define D_PCR  ((volatile unsigned int *)0x1000E020)
#define D_SQWC ((volatile unsigned int *)0x1000E030)
#define D_RBSR ((volatile unsigned int *)0x1000E040)
#define D_RBOR ((volatile unsigned int *)0x1000E050)

int func_00103E48(sceDmaEnv *env)
{
    unsigned int ctrl = *D_CTRL;
    unsigned int pcr = *D_PCR;
    unsigned int sqwc = *D_SQWC;
    unsigned int rbor = *D_RBOR;
    unsigned int rbsr = *D_RBSR;

    if (env->sts >= 10) return -1;
    if (env->std >= 10) return -2;
    if (env->mfd >= 10) return -3;
    if (env->rcycle >= 7) return -4;
    ctrl = (ctrl & ~0x30) | (D_00498348[env->sts] << 4);
    ctrl = (ctrl & ~0xC0) | (D_00498358[env->std] << 6);
    ctrl = (ctrl & ~0xC) | (D_00498368[env->mfd] << 2);
    if (env->rcycle) {
        ctrl |= 2;
        ctrl = (ctrl & ~0x300) | ((env->rcycle - 1) << 8);
    } else {
        ctrl &= ~2;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (unsigned int)env->rbadr;
    rbsr = env->rbmsk;
    *D_CTRL = ctrl;
    *D_PCR = pcr;
    *D_SQWC = sqwc;
    *D_RBOR = rbor;
    *D_RBSR = rbsr;
    D_004E1DB8 = *env;
    return 0;
}

