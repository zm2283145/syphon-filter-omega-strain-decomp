typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct {
    unsigned char trycount;
    unsigned char spindlctrl;
    unsigned char datapattern;
    unsigned char pad;
} CdRMode;
typedef struct {
    int lsn;
    int sectors;
    void *buf;
    unsigned char trycount;
    unsigned char spindlctrl;
    unsigned char datapattern;
    unsigned char pad;
    int *intr_data;
    int *cur_pos;
} CdReadCmd;
extern int D_00487890;
extern volatile int D_004878B8;
extern volatile int D_004878D8;
extern volatile int D_004878B4;
extern volatile int D_004878A8;
extern int D_00487980[];
extern int D_00488980[];
extern int D_00488A40[];
extern RpcCd D_00488A50;
extern char D_00498E08[];
extern char D_00498E20[];
extern int sceCdNcmdDiskReady(void);
extern int _sceCd_ncmd_prechk(int);
extern void _sceCd_cd_read_intr(void *);
extern void sceSifWriteBackDCache(void *, int);
extern int SignalSema(int);
extern int sceSifCallRpc(RpcCd *, int, int, void *, int, void *, int, void *, void *);
extern void scePrintf(const char *, ...);

int sceCdRead(int lsn, int sectors, void *buf, CdRMode *mode)
{
    CdReadCmd *sd = (CdReadCmd *)D_00487980;
    int size;

    if ((D_004878B8 & 1) == 0) {
        if (sceCdNcmdDiskReady() == 6) {
            return 0;
        }
    }
    if (_sceCd_ncmd_prechk(4) == 0) {
        return 0;
    }
    sd->lsn = lsn;
    sd->sectors = sectors;
    sd->buf = buf;
    sd->trycount = mode->trycount;
    sd->spindlctrl = mode->spindlctrl;
    sd->datapattern = mode->datapattern;
    sd->intr_data = D_00488980;
    sd->cur_pos = D_00488A40;
    switch (mode->datapattern) {
    case 1:
        size = sectors * 2328;
        break;
    case 2:
        size = sectors * 2340;
        break;
    case 0:
    default:
        size = sectors * 2048;
        break;
    }
    D_00488A40[0] = 0;
    if ((D_004878B8 & 2) == 0) {
        sceSifWriteBackDCache(buf, size);
    }
    sceSifWriteBackDCache(D_00488980, 144);
    sceSifWriteBackDCache(sd, 24);
    sceSifWriteBackDCache(D_00488A40, 4);
    if (D_00487890 > 0) {
        scePrintf(D_00498E08);
    }
    D_004878D8 = 1;
    D_004878B4 = 1;
    if (sceSifCallRpc(&D_00488A50, 1, 1, sd, 24, 0, 0, _sceCd_cd_read_intr, D_00488980) < 0) {
        D_004878D8 = 0;
        D_004878B4 = 0;
        SignalSema(D_004878A8);
        return 0;
    }
    if (D_00487890 > 0) {
        scePrintf(D_00498E20);
    }
    return 1;
}
