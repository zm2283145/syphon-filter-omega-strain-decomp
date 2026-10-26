/*
 * lib/medius: 2 files, 002DBBF8-002DBD58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DBBF8 */
typedef struct {
    char pad0[0x14];
    enum { S0, S1, S2, S3, S4, S5 } state;
    char pad18[0x24 - 0x18];
    int f24;
} Player;

typedef struct {
    unsigned int slot;
    int id;
    int ctx;
} Msg;

extern void (*D_0048C488)(Msg *);
extern int D_0048C48C;
extern int NetIsValidClientIndex(int);
extern int NetGetClientInfo(unsigned int, int, Player **);
extern int NetSetSessionMasterClientIndex(unsigned int, int);

int NetFindNextSessionMaster(unsigned int slot, int self, int *out)
{
    Msg m;
    Player *pl = 0;
    int best = 0x0FFFFFFF;
    int i;
    int r, t;
    if (slot >= 4)
        return 0x17;
    if (NetIsValidClientIndex(self) != 1)
        return 0x17;
    if (out == 0)
        return 0x17;
    *out = 0x100;
    for (i = 0; i < 0x100; i++) {
        if (self == i)
            continue;
        r = NetGetClientInfo(slot, i, &pl);
        if (r)
            return r;
        if (pl && pl->state == 4 && (t = pl->f24) > 0 && t < best) {
            *out = i;
            best = t;
        }
    }
    if (*out != 0x100) {
        r = NetGetClientInfo(slot, *out, &pl);
        if (r)
            return r;
        if (pl == 0)
            return 0;
        pl->state = 5;
        NetSetSessionMasterClientIndex(slot, *out);
        if (D_0048C488) {
            m.slot = slot;
            m.id = *out;
            m.ctx = D_0048C48C;
            D_0048C488(&m);
        }
    }
    return 0;
}
/* merge_units: end func_002DBBF8 */

/* merge_units: begin func_002DBD58 */
typedef struct Codec {
    int type;
    int mode;
    int inBlk;
    int outBlk;
    int x10;
    int x14;
    int x18;
    int x1C;
    void *x20;
    void *x24;
    void *fn;
    void *fn2;
    char pad30[8];
    int owner;
    int ctx;
} Codec;

extern int Net_AllocZeroed(void *, int);
extern void DestroyCodec(Codec *);
extern int stubCreate(void);
extern void stubDestroy(void);
extern void stubInit(void);
extern int stubEncode(void);
extern int stubDecode(void);
extern int gsmCreate(void);
extern void gsmDestroy(void);
extern void gsmInit(void);
extern int gsmEncode(void);
extern int gsmDecode(void);
extern int lpc10Create(void);
extern void lpc10Init(void);
extern int lpc10Encode(void);
extern int lpc10Decode(void);
extern void lpc10Destroy(void);
extern int lpcCreate(void);
extern void lpcInit(void);
extern int lpcEncode(void);
extern int lpcDecode(void);
extern void lpcDestroy(void);

#define SET_22() \
        p->ctx = gsmCreate(); \
        p->x20 = gsmInit; \
        p->x24 = gsmDestroy; \
        p->inBlk = 0x140; \
        p->outBlk = 0x21; \
        p->x10 = 0x140; \
        p->x14 = 0x140; \
        p->x18 = 0x140; \
        p->x1C = 0x140; \
        p->fn = gsmEncode; \
        p->fn2 = gsmDecode
#define SET_23() \
        p->ctx = lpc10Create(); \
        p->x20 = lpc10Init; \
        p->x24 = lpc10Destroy; \
        p->inBlk = 0x168; \
        p->outBlk = 7; \
        p->x10 = 0x168; \
        p->x14 = 0x168; \
        p->x18 = 0x168; \
        p->x1C = 0x168; \
        p->fn = lpc10Encode; \
        p->fn2 = lpc10Decode
#define SET_24() \
        p->ctx = lpcCreate(); \
        p->x20 = lpcInit; \
        p->x24 = lpcDestroy; \
        p->inBlk = 0x140; \
        p->outBlk = 8; \
        p->x10 = 0x140; \
        p->x14 = 0x140; \
        p->x18 = 0x140; \
        p->x1C = 0x140; \
        p->fn = lpcEncode; \
        p->fn2 = lpcDecode
#define SET_21() \
        p->ctx = stubCreate(); \
        p->x20 = stubInit; \
        p->x24 = stubDestroy; \
        p->inBlk = 0; \
        p->outBlk = 0; \
        p->x10 = 0; \
        p->x14 = 0; \
        p->x18 = 0; \
        p->x1C = 0; \
        p->fn = stubEncode; \
        p->fn2 = stubDecode

Codec *CreateCodec(int owner, int type, int mode)
{
    Codec *p = 0;

    Net_AllocZeroed(&p, 0xA20);
    if (p == 0) return 0;
    p->type = type;
    p->mode = mode;
    p->owner = owner;
    if (p->mode == 1) {
        switch (p->type) {
        case 0x22: SET_22(); break;
        case 0x23: SET_23(); break;
        case 0x24: SET_24(); break;
        case 0x21:
        case 0x3F: SET_21(); break;
        }
    } else if (p->mode == 2) {
        switch (p->type) {
        case 0x22: SET_22(); break;
        case 0x23: SET_23(); break;
        case 0x24: SET_24(); break;
        case 0x21:
        case 0x3F: SET_21(); break;
        }
    } else {
        DestroyCodec(p);
        p = 0;
    }
    if (p != 0 && p->ctx == 0) {
        DestroyCodec(p);
        p = 0;
    }
    return p;
}
/* merge_units: end func_002DBD58 */
