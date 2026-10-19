/*
 * main/AgentData: 11 files, 0032E470-0032E8C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032E470 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptUtils_types.h"

typedef struct OmegaRec {
    int data[8];
} OmegaRec;

extern char D_00532AB0[];
extern void* AwardRow_Construct(OmegaRec* out, int a, int zero, int b, int c, int zero2);
extern void func_00147600(void* list, void* rec);

/* Script native: cAgentData::RegisterOmega(a, b, c).
 * volatile mirrors the original stack temporaries. */
int Script_cAgentData__RegisterOmega(ScriptArg* args) {
    OmegaRec rec;
    volatile int slot2;
    volatile int slot1;
    volatile int slot0;
    int v;
    int c;
    int b;

    slot2 = args[2].i;
    v = args[1].i;
    c = slot2;
    slot1 = v;
    v = args[0].i;
    b = slot1;
    slot0 = v;
    func_00147600(D_00532AB0, AwardRow_Construct(&rec, slot0, 0, b, c, 0));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E470 */

/* merge_units: begin func_0032E4D0 */
#pragma push /* merge_units */
typedef union ScriptArg_0032E4D0 { int i; float f; void* p; unsigned char b; } ScriptArg_0032E4D0;
typedef struct { char data[0x20]; } Medal;
extern char D_00532A90[];
extern void* AwardRow_ConstructIndexed(Medal* c, int a, int b, int c2, int d, unsigned char e);
#if 0 /* merge_units */
extern void func_00147600(void* registry, void* c);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */


/* Script native: builds a medal from args[0..4] and registers it; returns 0. */
int Script_cAgentData__RegisterMedal_3(ScriptArg_0032E4D0* args)
{
    Medal c;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    unsigned char e = args[4].b;
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_00532A90, AwardRow_ConstructIndexed(&c, *(int*)p0, *(int*)p1, *(int*)p2, *(int*)p3, e));
    return 0;
}
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E4D0 */

/* merge_units: begin func_0032E540 */
#pragma push /* merge_units */
typedef struct { char data[0x1C]; } Medal_0032E540;
#if 0 /* merge_units */
extern void* AwardRow_Construct(Medal_0032E540* m, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define AwardRow_Construct(a0, a1, a2, a3, a4, a5) (AwardRow_Construct((OmegaRec *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void* registry, void* item);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */


/* Script native: builds a medal from args[0..4] and registers it; returns 0. */
int Script_cAgentData__RegisterMedal_2(ScriptArg* args)
{
    Medal_0032E540 m;
    int p4[1];
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_00532A90, AwardRow_Construct(&m, *(int*)p0, *(int*)p1, *(int*)p2, *(int*)p3, *(int*)p4));
    return 0;
}
#undef AwardRow_Construct /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E540 */

/* merge_units: begin func_0032E5B0 */
#pragma push /* merge_units */
typedef struct { char data[0x1C]; } Medal_0032E5B0;
#if 0 /* merge_units */
extern void* AwardRow_Construct(Medal_0032E5B0* m, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define AwardRow_Construct(a0, a1, a2, a3, a4, a5) (AwardRow_Construct((OmegaRec *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void* registry, void* item);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */


/* Script native: builds a medal from args[0..3] (last field 0) and registers it; returns 0. */
int Script_cAgentData__RegisterMedal(ScriptArg* args)
{
    Medal_0032E5B0 m;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_00532A90, AwardRow_Construct(&m, *(int*)p0, *(int*)p1, *(int*)p2, *(int*)p3, 0));
    return 0;
}
#undef AwardRow_Construct /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E5B0 */

/* merge_units: begin func_0032E620 */
#pragma push /* merge_units */
typedef union ScriptArg_0032E620 { int i; float f; void* p; unsigned char b; } ScriptArg_0032E620;
typedef struct { char data[0x20]; } Commendation;
extern char D_00532A80[];
#if 0 /* merge_units */
extern void* AwardRow_ConstructIndexed(Commendation* c, int a, int b, int c2, int d, unsigned char e);
#endif /* merge_units */
#define AwardRow_ConstructIndexed(a0, a1, a2, a3, a4, a5) (AwardRow_ConstructIndexed((Medal *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void* registry, void* c);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */


/* Script native: builds a commendation from args[0..4] and registers it; returns 0. */
int Script_cAgentData__RegisterCommendatio_3(ScriptArg_0032E620* args)
{
    Commendation c;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    unsigned char e = args[4].b;
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_00532A80, AwardRow_ConstructIndexed(&c, *(int*)p0, *(int*)p1, *(int*)p2, *(int*)p3, e));
    return 0;
}
#undef AwardRow_ConstructIndexed /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E620 */

/* merge_units: begin func_0032E690 */
#pragma push /* merge_units */
typedef struct CommendationArgs {
    int a0, a1, a2, a3, a4;
} CommendationArgs;

/* Temporary commendation record built on the stack. */
typedef struct Commendation_0032E690 {
    char data[0x1C];
} Commendation_0032E690;
#if 0 /* merge_units */
extern int AwardRow_Construct(Commendation_0032E690* rec, int a0, int a1, int a2, int a3, int a4);
#endif /* merge_units */
#define AwardRow_Construct(a0, a1, a2, a3, a4, a5) ((int)AwardRow_Construct((OmegaRec *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void* registry, int rec);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (void *)(a1))) /* merge_units */


/* Script native: cAgentData._RegisterCommendation(a0, a1, a2, a3, a4). */
int Script_cAgentData__RegisterCommendatio_2(CommendationArgs* args) {
    Commendation_0032E690 rec;
    int v4, v3, v2, v1, v0;
    volatile int w4, w3, w2, w1, w0;
    w4 = args->a4;
    v4 = w4;
    w3 = args->a3;
    v3 = w3;
    w2 = args->a2;
    v2 = w2;
    w1 = args->a1;
    v1 = w1;
    w0 = args->a0;
    v0 = w0;
    func_00147600(D_00532A80, AwardRow_Construct(&rec, v0, v1, v2, v3, v4));
    return 0;
}
#undef AwardRow_Construct /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E690 */

/* merge_units: begin func_0032E700 */
#pragma push /* merge_units */
typedef struct CommendationArgs_0032E700 {
    int a0, a1, a2, a3;
} CommendationArgs_0032E700;

/* Temporary commendation record built on the stack. */
typedef struct Commendation_0032E700 {
    char data[0x20];
} Commendation_0032E700;
#if 0 /* merge_units */
extern int AwardRow_Construct(Commendation_0032E700* rec, int a0, int a1, int a2, int a3, int a4);
#endif /* merge_units */
#define AwardRow_Construct(a0, a1, a2, a3, a4, a5) ((int)AwardRow_Construct((OmegaRec *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void* registry, int rec);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (void *)(a1))) /* merge_units */


/* Script native: cAgentData._RegisterCommendation(a0, a1, a2, a3). */
int Script_cAgentData__RegisterCommendation(CommendationArgs_0032E700* args) {
    Commendation_0032E700 rec;
    int v3, v2, v1, v0;
    volatile int w3, w2, w1, w0;
    w3 = args->a3;
    v3 = w3;
    w2 = args->a2;
    v2 = w2;
    w1 = args->a1;
    v1 = w1;
    w0 = args->a0;
    v0 = w0;
    func_00147600(D_00532A80, AwardRow_Construct(&rec, v0, v1, v2, v3, 0));
    return 0;
}
#undef AwardRow_Construct /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E700 */

/* merge_units: begin func_0032E770 */
#pragma push /* merge_units */
typedef union ScriptArg_0032E770 {
    int i;
    float f;
    void* p;
    unsigned char uc;
} ScriptArg_0032E770;

typedef struct Ratio {
    char b[0x20];
} Ratio;

extern int D_00532A70;
#if 0 /* merge_units */
extern void* AwardRow_ConstructIndexed(Ratio*, int, int, int, int, unsigned char);
#endif /* merge_units */
#define AwardRow_ConstructIndexed(a0, a1, a2, a3, a4, a5) (AwardRow_ConstructIndexed((Medal *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void*, void*);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */


/* Script: cAgentData::RegisterSpecialRatio(a, b, c, d, flag). */
int Script_cAgentData__RegisterSpecialRati_3(ScriptArg_0032E770* args) {
    Ratio ratio;
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    unsigned char flag = args[4].uc;
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_00147600(&D_00532A70, AwardRow_ConstructIndexed(&ratio, *(int*)a, *(int*)b, *(int*)c, *(int*)d, flag));
    return 0;
}
#undef AwardRow_ConstructIndexed /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E770 */

/* merge_units: begin func_0032E7E0 */
#pragma push /* merge_units */
typedef struct Ratio_0032E7E0 {
    char b[0x1C];
} Ratio_0032E7E0;
#if 0 /* merge_units */
extern void* AwardRow_Construct(Ratio_0032E7E0*, int, int, int, int, int);
#endif /* merge_units */
#define AwardRow_Construct(a0, a1, a2, a3, a4, a5) (AwardRow_Construct((OmegaRec *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void*, void*);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */


/* Script: cAgentData::RegisterSpecialRatio(a, b, c, d, e). */
int Script_cAgentData__RegisterSpecialRati_2(ScriptArg* args) {
    Ratio_0032E7E0 ratio;
    int e[1];
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    e[0] = args[4].i;
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_00147600(&D_00532A70, AwardRow_Construct(&ratio, *(int*)a, *(int*)b, *(int*)c, *(int*)d, *(int*)e));
    return 0;
}
#undef AwardRow_Construct /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E7E0 */

/* merge_units: begin func_0032E850 */
#pragma push /* merge_units */
typedef struct { char data[0x20]; } Rating0032E850;
#if 0 /* merge_units */
extern char D_00532A70[];
#endif /* merge_units */
#define D_00532A70 ((char*)&D_00532A70) /* merge_units */

#if 0 /* merge_units */
extern void* AwardRow_Construct(Rating0032E850* out, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define AwardRow_Construct(a0, a1, a2, a3, a4, a5) (AwardRow_Construct((OmegaRec *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void func_00147600(void* list, void* rating);
#endif /* merge_units */
#define func_00147600(a0, a1) (func_00147600((a0), (a1))) /* merge_units */

/* Script: cAgentData::RegisterSpecialRating(a, b, c, d). */
int Script_cAgentData__RegisterSpecialRating(int* args)
{
    Rating0032E850 rating;
    int d[1]; /* staged through the stack */
    int c[1];
    int b[1];
    int a[1];
    d[0] = args[3];
    c[0] = args[2];
    b[0] = args[1];
    a[0] = args[0];
    func_00147600(D_00532A70, AwardRow_Construct(&rating, *(int*)a, *(int*)b, *(int*)c, *(int*)d, 0));
    return 0;
}
#undef D_00532A70 /* merge_units */
#undef AwardRow_Construct /* merge_units */
#undef func_00147600 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E850 */

/* merge_units: begin func_0032E8C0 */
#pragma push /* merge_units */
typedef union { int i; unsigned char uc; } Arg0032E8C0;
typedef struct { char data[0x20]; } Rating0032E8C0;
extern char D_00532AD0[];
extern void* RatingRow_ConstructIndexed(Rating0032E8C0* out, int a, int b, unsigned char c, int d, int e, unsigned char f);
extern void func_0032E930(void* list, void* rating);
/* Script: cAgentData::RegisterRating(a, b, c, d, e, f). */
int Script_cAgentData__RegisterRating_3(Arg0032E8C0* args)
{
    Rating0032E8C0 rating;
    unsigned char f;
    int e[1]; /* staged through the stack */
    int d[1];
    unsigned char c;
    int b[1];
    int a[1];
    f = args[5].uc;
    e[0] = args[4].i;
    d[0] = args[3].i;
    c = args[2].uc;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_0032E930(D_00532AD0, RatingRow_ConstructIndexed(&rating, *(int*)a, *(int*)b, c, *(int*)d, *(int*)e, f));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E8C0 */
