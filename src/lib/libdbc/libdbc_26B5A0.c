typedef struct {
    unsigned long cmd : 14;
    unsigned long mode : 2;
    unsigned long len : 8;
    unsigned long dev : 8;
} DbcCmd_b5a0;


typedef struct {
    int h0;
    int active;
    char rest[0x334 - 8];
} Dev_b5a0;

typedef struct {
    unsigned char b0;
    int active;
} Ent_b5a0;

extern Dev_b5a0 D_004FBB88[];
extern int scePad2LinkDriver(int dev);
extern int scePad2CheckDma(int dev);
extern Ent_b5a0 *scePad2GetSide2(int dev);
extern void scePad2InitDmaDBuff(int dev);
extern int sceDbcReceiveData(int a, int b, int *len, unsigned char *out);

int scePad2GetState(int dev)
{
    unsigned char data;
    int len;
    long c;
    Ent_b5a0 *p;

    if (D_004FBB88[dev].active == 0) {
        if (scePad2LinkDriver(dev) < 0) return 0;
    }
    if (scePad2CheckDma(dev) != 0) {
        p = scePad2GetSide2(dev);
        if (p->active == 0) {
            if (scePad2LinkDriver(dev) < 0) goto fail;
        }
        data = p->b0;
    } else {
        c &= ~0x3FFFL;
        c |= 12;
        c &= ~0xC000L;
        c |= 0x8000;
        c &= ~0xFF0000L;
        c |= 0x10000;
        c &= ~0xFF000000L;
        c |= 0x1000000;
        if (sceDbcReceiveData(dev, c, &len, &data) < 0) {
        fail:
            D_004FBB88[dev].active = 0;
            scePad2InitDmaDBuff(dev);
            return 0;
        }
    }
    return data;
}
