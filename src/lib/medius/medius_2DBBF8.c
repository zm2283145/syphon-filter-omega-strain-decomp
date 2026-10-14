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
extern int func_002E6088(int);
extern int func_002E52D8(unsigned int, int, Player **);
extern int func_002E5550(unsigned int, int);

int func_002DBBF8(unsigned int slot, int self, int *out)
{
    Msg m;
    Player *pl = 0;
    int best = 0x0FFFFFFF;
    int i;
    int r, t;
    if (slot >= 4)
        return 0x17;
    if (func_002E6088(self) != 1)
        return 0x17;
    if (out == 0)
        return 0x17;
    *out = 0x100;
    for (i = 0; i < 0x100; i++) {
        if (self == i)
            continue;
        r = func_002E52D8(slot, i, &pl);
        if (r)
            return r;
        if (pl && pl->state == 4 && (t = pl->f24) > 0 && t < best) {
            *out = i;
            best = t;
        }
    }
    if (*out != 0x100) {
        r = func_002E52D8(slot, *out, &pl);
        if (r)
            return r;
        if (pl == 0)
            return 0;
        pl->state = 5;
        func_002E5550(slot, *out);
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
extern void func_002DC1F0(Codec *);
extern int func_002DCA38(void);
extern void func_002DCA50(void);
extern void func_002DCA58(void);
extern int func_002DCA60(void);
extern int func_002DCA68(void);
extern int func_0032E120(void);
extern void func_0032E128(void);
extern void func_0032E130(void);
extern int func_0032E138(void);
extern int func_0032E140(void);
extern int func_00357128(void);
extern void func_00357130(void);
extern int func_00357138(void);
extern int func_00357140(void);
extern void func_00357148(void);
extern int func_00316688(void);
extern void func_00316690(void);
extern int func_00316698(void);
extern int func_003166A0(void);
extern void func_003166A8(void);

#define SET_22() \
        p->ctx = func_0032E120(); \
        p->x20 = func_0032E130; \
        p->x24 = func_0032E128; \
        p->inBlk = 0x140; \
        p->outBlk = 0x21; \
        p->x10 = 0x140; \
        p->x14 = 0x140; \
        p->x18 = 0x140; \
        p->x1C = 0x140; \
        p->fn = func_0032E138; \
        p->fn2 = func_0032E140
#define SET_23() \
        p->ctx = func_00357128(); \
        p->x20 = func_00357130; \
        p->x24 = func_00357148; \
        p->inBlk = 0x168; \
        p->outBlk = 7; \
        p->x10 = 0x168; \
        p->x14 = 0x168; \
        p->x18 = 0x168; \
        p->x1C = 0x168; \
        p->fn = func_00357138; \
        p->fn2 = func_00357140
#define SET_24() \
        p->ctx = func_00316688(); \
        p->x20 = func_00316690; \
        p->x24 = func_003166A8; \
        p->inBlk = 0x140; \
        p->outBlk = 8; \
        p->x10 = 0x140; \
        p->x14 = 0x140; \
        p->x18 = 0x140; \
        p->x1C = 0x140; \
        p->fn = func_00316698; \
        p->fn2 = func_003166A0
#define SET_21() \
        p->ctx = func_002DCA38(); \
        p->x20 = func_002DCA58; \
        p->x24 = func_002DCA50; \
        p->inBlk = 0; \
        p->outBlk = 0; \
        p->x10 = 0; \
        p->x14 = 0; \
        p->x18 = 0; \
        p->x1C = 0; \
        p->fn = func_002DCA60; \
        p->fn2 = func_002DCA68

Codec *func_002DBD58(int owner, int type, int mode)
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
        func_002DC1F0(p);
        p = 0;
    }
    if (p != 0 && p->ctx == 0) {
        func_002DC1F0(p);
        p = 0;
    }
    return p;
}
/* merge_units: end func_002DBD58 */
