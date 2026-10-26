/* libmpeg _motionComp0 (SDK 2.2 mpc.c) on the context-pointer libmpeg: the tag loop is split out into dmaRefImage,
   _getAllRefs is func_00104980, _Error1 is func_0010BD58. */
typedef struct {
    int refBuf;
    int pad4;
    int srcAddr[2][4];
    char pad28[0x128 - 0x28];
    int dst;
    int count;
    int intra;
    int coded;
    int busy;
    char pad13C[0x140 - 0x13C];
} MCRec;

typedef struct {
    int *buf;
    int pad4[3];
    int w;
} MpegFrame;

typedef struct {
    char pad0[0x134];
    int isError;
    char pad138[0x144 - 0x138];
    int widthMB;
    char pad148[0x18C - 0x148];
    int picture_structure;
    char pad190[0x1D8 - 0x190];
    int *curFrame;
    char pad1DC[0x1E8 - 0x1DC];
    int *curTop;
    char pad1EC[0x1F8 - 0x1EC];
    int *curBot;
    char pad1FC[0x5A8 - 0x1FC];
    MCRec rec[2];
    char pad828[0x828 - 0x5A8 - 0x280];
    int cur;
} Mpeg4730;

#define D9_CHCR ((volatile unsigned int *)0x1000D400)

extern void func_0010BD58(Mpeg4730 *, const char *, int);
extern void func_00104980(Mpeg4730 *, int, int, int, int, int (*)[2][2], int (*)[2], int *);
extern void dmaRefImage(Mpeg4730 *);

int func_00104730(Mpeg4730 *mp, int mba, int inc, int mb_type, int motion_type, int PMV[2][2][2],
                  int mv_field_sel[2][2], int *dmvector)
{
    int col = mba % mp->widthMB;
    int row = mba / mp->widthMB;
    int x = col * 16;
    int y = row * 16;
    int intra = mb_type & 1;

    if (intra) {
        while ((*D9_CHCR >> 8) & 1) {}
        mp->rec[mp->cur].busy = 0;
    } else {
        if ((unsigned int)(motion_type - 1) >= 3) {
            func_0010BD58(mp, "Invalid modion type -- ignored(%d)", motion_type);
            mp->isError = 1;
            return 0;
        }
        func_00104980(mp, x, y, mb_type, motion_type, PMV, mv_field_sel, dmvector);
        while ((*D9_CHCR >> 8) & 1) {}
        dmaRefImage(mp);
        mp->rec[mp->cur].busy = 1;
    }
    if (inc == 1 && (mb_type & 2)) {
        mp->rec[mp->cur].coded = inc;
    } else {
        mp->rec[mp->cur].coded = 0;
    }
    mp->rec[mp->cur].intra = intra;
    if (mp->picture_structure == 3) {
        int *p = mp->curFrame;
        mp->rec[mp->cur].dst = p[0] + (col * p[4] + row) * 0x180;
    } else {
        int *p = mp->picture_structure == 2 ? mp->curBot : mp->curTop;
        mp->rec[mp->cur].dst = p[0] + (col * p[4] + row) * 0x180;
    }
    return 1;
}