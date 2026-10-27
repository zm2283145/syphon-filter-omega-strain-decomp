/*
 * cHumanCollisionRoutine_InitLedgeSearchWorkSpace: builds the nine collision preset descriptors on the
 * stack (candidate masks, height/distance/cosine ranges) and appends them to
 * g_HumanColPresetMgr; the last append is expanded in place.
 */
#include "types.h"
#include "humanCollision_types.h"

/* Preset descriptor built on the stack and appended to the manager. */
typedef struct HumanColDesc {
    signed char selector;           /* 0x00 */
    signed char kind;               /* 0x01 */
    char pad02[2];
    int masks[4];                   /* 0x04 */
    HumanColPresetCfg cfg;          /* 0x14 */
    unsigned char descFlag;         /* 0x30 */
} HumanColDesc;

extern float Libc_Cosf(float);
extern int* cBitArray_19_ctor_cBitArrayR(int* dst, int* src);
extern int* cBitArray_5_ctor_cBitArrayR(int* dst, int* src);
extern HumanColPresetCfg* cHumanCollisionRoutine_cLedgeSearchLimits_ctor(HumanColPresetCfg* dst, HumanColPresetCfg* src);
extern HumanColPresetMgr* cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(HumanColPresetMgr* mgr, HumanColDesc* desc);
extern HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_eLedgeSubtype_cBitArrayR_cBitArrayR_cBitArrayR_etc(HumanColPreset* p, int selector, int* mask0, int* mask1,
                                                int* mask2, int* mask3, HumanColPresetCfg* cfg, int enabled);
extern void cArray_FixedCapacity_cIntermediateLedgeSearchInfo_9_PushBackActual(HumanColPresetMgr* mgr, HumanColPreset* p);
extern HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor(HumanColPreset* self, short flag);
extern HumanColPresetMgr* g_HumanColPresetMgr;
extern float D_004A0400;
extern float D_004A0408;

static inline void Range_Set(float* r, float lo, float hi) {
    r[0] = lo;
    r[1] = hi;
}

#define Cfg_Init(c, a, b, d, e, angLo, angHi, en) \
    ((c)->range0Min = (a), (c)->range0Max = (b), (c)->range1Min = (d), (c)->range1Max = (e), \
     Range_Set(&(c)->range2Min, Libc_Cosf(angLo), Libc_Cosf(angHi)), (c)->enabled = (en))

static inline void Desc_Tail(HumanColDesc* d, int* m2, int* m3, HumanColPresetCfg* cfg, int flag) {
    cBitArray_5_ctor_cBitArrayR(&d->masks[2], m2);
    cBitArray_5_ctor_cBitArrayR(&d->masks[3], m3);
    cHumanCollisionRoutine_cLedgeSearchLimits_ctor(&d->cfg, cfg);
    d->descFlag = flag;
}

static inline void Desc_Head(HumanColDesc* d, int kind, int sel, int* m0, int* m1) {
    d->selector = sel;
    d->kind = kind;
    cBitArray_19_ctor_cBitArrayR(&d->masks[0], m0);
    cBitArray_19_ctor_cBitArrayR(&d->masks[1], m1);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void cHumanCollisionRoutine_InitLedgeSearchWorkSpace(void) {
    int a0, a1, a2, a3;
    int b0, b1, b2, b3;
    int c0, c1, c2, c3;
    int d0, d1, d2, d3;
    int e0, e1, e2, e3;
    int f0, f1, f2, f3;
    int g0, g1, g2, g3;
    int h0, h1, h2, h3;
    int i0, i1, i2, i3;
    HumanColPresetCfg ca;
    HumanColDesc da;
    HumanColPresetCfg cb;
    HumanColDesc db;
    HumanColPresetCfg cc;
    HumanColDesc dc;
    HumanColPresetCfg cd;
    HumanColDesc dd;
    HumanColPresetCfg ce;
    HumanColDesc de;
    HumanColPresetCfg cf;
    HumanColDesc df;
    HumanColPresetCfg cg;
    HumanColDesc dg;
    HumanColPresetCfg ch;
    HumanColDesc dh;
    HumanColPresetCfg ci;
    HumanColDesc di;
    HumanColPreset tmp;
    HumanColPresetMgr* mgr;
    int one;
    float q;
    float r;
    HumanColDesc* p;

    a0 = 0; a1 = 0; a2 = 0; a3 = 0;
    Cfg_Init(&ca, -1.5f, 0.5f, -0.0f, 9.0f, 1.0471976f, 0.0f, 1);
    a3 |= 1; a1 |= 0x1000; a3 |= 8;
    p = &da;
    Desc_Head(&da, 0, 0, &a0, &a1);
    Desc_Tail(p, &a2, &a3, &ca, 0);

    b0 = 0; b1 = 0; b2 = 0; b3 = 0;
    Cfg_Init(&cb, -1.5f, 0.5f, -0.25f, 9.0f, 1.4835298f, 0.0f, one = 1);
    b3 |= 1; b1 |= 0x1000; b3 |= 8;
    p = &db;
    Desc_Head(&db, one, one, &b0, &b1);
    Desc_Tail(p, &b2, &b3, &cb, 0);

    c0 = 0; c1 = 0; c2 = 0; c3 = 0;
    Cfg_Init(&cc, 1.5f, 7.0f, -0.0f, 16.0f, 1.7453293f, 0.0f, 0);
    c3 |= 1; c1 |= 0x1000; c0 |= 0x10; c3 |= 8;
    p = &dc;
    Desc_Head(&dc, 3, 2, &c0, &c1);
    Desc_Tail(p, &c2, &c3, &cc, 0);

    d0 = 0; d1 = 0; d2 = 0; d3 = 0;
    Cfg_Init(&cd, 7.0f, 0.25f + D_004A0400, -0.0f, 16.0f, 3.1503193378448486f, 0.0f, 0);
    d3 |= 1; d1 |= 0x1000; d3 |= 8;
    p = &dd;
    Desc_Head(&dd, 5, 3, &d0, &d1);
    Desc_Tail(p, &d2, &d3, &cd, 0);

    e0 = 0; e1 = 0; e2 = 0; e3 = 0;
    q = 0.25f;
    Cfg_Init(&ce, q + D_004A0400, q + D_004A0408, -0.0f, 16.0f, 3.1503193378448486f, 0.0f, 0);
    e3 |= 1; e1 |= 0x1000; e3 |= 8;
    p = &de;
    Desc_Head(&de, 6, 4, &e0, &e1);
    Desc_Tail(p, &e2, &e3, &ce, 0);

    f0 = 0; f1 = 0; f2 = 0; f3 = 0;
    Cfg_Init(&cf, 2.5f, 5.0f, -0.0f, 25.0f, 1.4835298f, 0.0f, 0);
    f3 |= 1; f1 |= 0x1000; f3 |= 4; f3 |= 8;
    p = &df;
    Desc_Head(&df, 7, 5, &f0, &f1);
    Desc_Tail(p, &f2, &f3, &cf, 1);

    g0 = 0; g1 = 0; g2 = 0; g3 = 0;
    Cfg_Init(&cg, 5.5f, r = 9.0f, -2.25f, r, 1.0471976f, 0.0f, 0);
    g1 |= 0x1000;
    p = &dg;
    Desc_Head(&dg, 8, 6, &g0, &g1);
    Desc_Tail(p, &g2, &g3, &cg, 0);

    h0 = 0; h1 = 0; h2 = 0; h3 = 0;
    Cfg_Init(&ch, -3.4028235e38f, 0.5f, -0.0f, 25.0f, 3.1503193378448486f, 0.0f, 1);
    h3 |= 1; h3 |= 8; h1 |= 0x40000; h0 |= 0x1000;
    p = &dh;
    Desc_Head(&dh, 12, 7, &h0, &h1);
    Desc_Tail(p, &h2, &h3, &ch, 0);

    i0 = 0; i1 = 0; i2 = 0; i3 = 0;
    Cfg_Init(&ci, 1.5f, 8.5f, -0.0f, 25.0f, 3.1503193378448486f, 0.0f, 0);
    i3 |= 1; i1 |= 0x40000; i0 |= 0x1000; i3 |= 8;
    p = &di;
    Desc_Head(&di, 12, 8, &i0, &i1);
    Desc_Tail(p, &i2, &i3, &ci, 0);

    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(g_HumanColPresetMgr, &da);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &db);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dc);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dd);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &de);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &df);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dg);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dh);
    cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_eLedgeSubtype_cBitArrayR_cBitArrayR_cBitArrayR_etc(&tmp, di.kind, &di.masks[0], &di.masks[1], &di.masks[2], &di.masks[3], &di.cfg, di.descFlag);
    cArray_FixedCapacity_cIntermediateLedgeSearchInfo_9_PushBackActual(mgr, &tmp);
    cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor(&tmp, -1);
}
#pragma pop
