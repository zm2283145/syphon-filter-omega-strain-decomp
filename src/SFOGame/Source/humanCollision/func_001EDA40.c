#pragma cplusplus on
#include "types.h"

/* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes: build the ledge-probe mask for a collision query mask. A rule table is
 * built on first use (each element registered for destruction); every rule whose required
 * bits are all set in the query and whose forbidden bits are all clear adds its bit. */

struct Mask { int w[1]; };
struct Rule { signed char bit; Mask need; Mask forbid; };

extern "C" {
extern signed char D_004F5310;   /* rule table built */
extern Rule D_004A0380[];        /* rule table, terminated by bit -1 */
extern Rule D_004A038C;
extern Rule D_004A0398;
extern Rule D_004A03A4;
extern signed char D_0048A978;
extern signed char D_0048A980;
extern signed char D_0048A988;
extern char D_004F5318[];        /* destruction records */
extern char D_004F5328[];
extern char D_004F5338[];
extern char D_004F5348[];

void __register_global_object(void* obj, void* dtor, void* rec);
void* func_001EDCC0(void* self, short flag);
void* cBitArray_5_dtor(void* self, short flag);
int cBitArray_5_opAnd(Mask* out, Mask* a, Mask* b);
int cBitArray_5_opCompl(Mask* out, Mask* a);
int cBitArray_5_opEq(Mask* a, Mask* b);
int cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes(Mask* out, void* self, Mask* q);
}

/* the element initialisers write through the element's this pointer; the int round trip keeps
 * MW from folding the constant address into each store (retail stores through a0) */
static inline Rule* This(Rule* r) { return (Rule*)(int)r; }
static inline Mask* MaskRef(Mask* m) { return (Mask*)(int)m; }

static inline Mask* MaskBit(Mask* t, int set)
{
    t->w[0] = 0;
    t->w[0] |= set;
    return MaskRef(t);
}

static inline void RuleInit(Rule* r, signed char bit, Mask* f)
{
    int i;
    r->bit = bit;
    r->need.w[0] = 0;
    for (i = 0; i < 1; i++) r->forbid.w[i] = f->w[i];
}

static inline bool MaskEq(Mask* a, Mask* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (a->w[i] != b->w[i]) return false;
    }
    return true;
}

int cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes(Mask* out, void* self, Mask* q)
{
    Mask res;
    Rule* e;
    int i;
    if (!D_004F5310) {
        {
            Mask t;
            Mask* f = MaskBit(&t, 0x10);
            Rule* r;
            D_004A0380[0].bit = D_0048A978;
            r = This(D_004A0380);
            r->need.w[0] = 0;
            for (i = 0; i < 1; i++) r->forbid.w[i] = f->w[i];
        }
        __register_global_object(D_004A0380, func_001EDCC0, D_004F5318);
        { Mask t; RuleInit(This(&D_004A038C), D_0048A980, MaskBit(&t, 0x4)); }
        __register_global_object(This(&D_004A038C), func_001EDCC0, D_004F5328);
        { Mask t; RuleInit(This(&D_004A0398), D_0048A988, MaskBit(&t, 0x2)); }
        __register_global_object(This(&D_004A0398), func_001EDCC0, D_004F5338);
        {
            Rule* r = This(&D_004A03A4);
            r->bit = -1;
            r->need.w[0] = 0;
            r->forbid.w[0] = 0;
        }
        __register_global_object(This(&D_004A03A4), func_001EDCC0, D_004F5348);
        D_004F5310 = 1;
    }
    res.w[0] = 0;
    for (e = D_004A0380; e->bit != -1; e++) {
        Mask t;
        cBitArray_5_opAnd(&t, q, &e->need);
        if (MaskEq(&t, &e->need)) {
            Mask n;
            Mask u;
            unsigned char ok;
            cBitArray_5_opCompl(&n, q);
            cBitArray_5_opAnd(&u, &n, &e->forbid);
            ok = cBitArray_5_opEq(&u, &e->forbid);
            cBitArray_5_dtor(&u, -1);
            cBitArray_5_dtor(&n, -1);
            if (ok) res.w[e->bit / 32] |= 1 << (e->bit & 31);
        }
    }
    for (i = 0; i < 1; i++) out->w[i] = res.w[i];
    return 0;
}
