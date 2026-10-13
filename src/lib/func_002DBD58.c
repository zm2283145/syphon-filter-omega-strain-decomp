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
