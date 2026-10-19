/*
 * lib/libgcc: 11 files, 0011BA88-0011BD70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011BA88 */
/* libgcc2 __fixdfdi. Retail libgcc was assembled without delay-slot swapping (as with gas -g);
   `.set nomove` reproduces that. The EE soft-float libcalls are aliased to their retail functions. */
__asm__(".set nomove\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpsub = func_0011C200");

typedef int SItype;
typedef unsigned int USItype;
typedef long DItype;
typedef unsigned long UDItype;
typedef float SFtype;
typedef double DFtype;

#define WORD_SIZE (sizeof (SItype) * 8)
#define HIGH_HALFWORD_COEFF (((UDItype) 1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((UDItype) 1) << WORD_SIZE)
extern UDItype func_0011B970(DFtype a);

DItype func_0011BA88(DFtype a)
{
  if (a < 0)
    return - func_0011B970 (-a);
  return func_0011B970 (a);
}
/* merge_units: end func_0011BA88 */

/* merge_units: begin func_0011BB00 */
/* libgcc2 __fixunssfdi. Retail libgcc was assembled without delay-slot swapping (as with gas -g);
   `.set nomove` reproduces that. The EE soft-float libcalls are aliased to their retail functions. */
__asm__(".set nomove\n"
        "fptodp = SoftFloat_FloatToDouble\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpmul = SoftFloat_DoubleMultiply\n"
        "dptoul = func_0011C980\n"
        "__floatdidf = func_0011B7E0\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = func_0011C200");UDItype func_0011BB00(SFtype original_a)
{
  DFtype a = original_a;
  DFtype b;
  UDItype v;

  if (a < 0)
    return 0;

  b = (a / HIGH_WORD_COEFF);
  v = (USItype) b;
  v <<= WORD_SIZE;
  a -= (DFtype) v;
  if (a < 0)
    v -= (USItype) (- a);
  else
    v += (USItype) a;
  return v;
}
/* merge_units: end func_0011BB00 */

/* merge_units: begin func_0011BC28 */
typedef union { float value; unsigned int value_raw; struct { unsigned int fraction:23; unsigned int exp:8; unsigned int sign:1; } bits; } FLO_0011BC28;
typedef struct { int class; unsigned int sign; int normal_exp; union { unsigned int ll; } fraction; } fpn_0011BC28;
static __inline__ int fp_iszero(fpn_0011BC28 *x) { return x->class == 2; }
/* fp-bit pack_f (no NaN/Inf/denormal variant) */
float func_0011BC28(fpn_0011BC28 *src)
{
    FLO_0011BC28 dst;
    unsigned int fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;
    if (fp_iszero(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -126) {
            exp = 0;
            fraction = 0;
        } else {
            if (src->normal_exp > 128 || (src->normal_exp == 128 && fraction >= 0x80000000)) {
                exp = 255;
                fraction = 0;
            } else {
                exp = src->normal_exp + 127;
                fraction >>= 7;
            }
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
/* merge_units: end func_0011BC28 */

/* merge_units: begin func_0011BCE0 */
typedef union { float value; unsigned int value_raw; struct { unsigned int fraction:23; unsigned int exp:8; unsigned int sign:1; } bits; } FLO_0011BCE0;
typedef struct { int class; unsigned int sign; int normal_exp; union { unsigned int ll; } fraction; } fpn_0011BCE0;
void func_0011BCE0(FLO_0011BCE0 *src, fpn_0011BCE0 *dst)
{
  unsigned int fraction = src->bits.fraction;
  int exp = src->bits.exp;
  int sign = src->bits.sign;

  dst->sign = sign;
  if (exp == 0)
    {
      dst->class = 2;
    }
  else
    {
      dst->normal_exp = exp - 127;
      dst->class = 3;
      dst->fraction.ll = (fraction << 7) | (1 << 30);
    }
}
/* merge_units: end func_0011BCE0 */

/* merge_units: begin libgcc_11BD40 */
#include "types.h"
typedef struct { int a; int b; int c; int d; } ReqBD40;
#if 0 /* merge_units */
extern void func_0011BC28(ReqBD40* req);
#endif /* merge_units */
#define func_0011BC28(a0) ((void)func_0011BC28((fpn_0011BC28 *)(a0))) /* merge_units */

void func_0011BD40(int a, int b, int c, int d)
{
    ReqBD40 req;
    req.a = a;
    req.b = b;
    req.c = c;
    req.d = d;
    func_0011BC28(&req);
}
#undef func_0011BC28 /* merge_units */
/* merge_units: end libgcc_11BD40 */

/* merge_units: begin func_0011BD70 */
typedef union { float value; unsigned int value_raw; } FLO_0011BD70;
typedef struct { int class; unsigned int sign; int normal_exp; union { unsigned int ll; } fraction; } fpn_0011BD70;
#if 0 /* merge_units */
extern void func_0011BCE0(FLO_0011BD70 *src, fpn_0011BD70 *dst);
#endif /* merge_units */
#define func_0011BCE0(a0, a1) (func_0011BCE0((FLO_0011BCE0 *)(a0), (fpn_0011BCE0 *)(a1))) /* merge_units */

extern double func_0011C8F8(int class, unsigned int sign, int exp, unsigned long long frac);
double SoftFloat_FloatToDouble(float arg_a)
{
  fpn_0011BD70 in;
  FLO_0011BD70 au;

  au.value = arg_a;
  func_0011BCE0 (&au, &in);
  return func_0011C8F8 (in.class, in.sign, in.normal_exp,
		    ((unsigned long long) in.fraction.ll) << 30);
}
#undef func_0011BCE0 /* merge_units */
/* merge_units: end func_0011BD70 */

/* merge_units: begin func_0011BDB0 */
typedef unsigned long fractype;
typedef unsigned int halffractype;
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union { fractype ll; halffractype l[2]; } fraction;
} fp_number_type;
typedef union {
    DFtype value;
    fractype value_raw;
    struct {
        fractype fraction:52 __attribute__((packed));
        unsigned int exp:11 __attribute__((packed));
        unsigned int sign:1 __attribute__((packed));
    } bits;
} FLO_union_type;
static __inline__ int isinf_(fp_number_type *x) { return x->class == CLASS_INFINITY; }
static __inline__ int iszero_(fp_number_type *x) { return x->class == CLASS_ZERO; }
DFtype func_0011BDB0(fp_number_type *src)
{
    FLO_union_type dst;
    fractype fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;
    if (src->class == CLASS_QNAN || src->class == CLASS_SNAN) {
        exp = 0x7FF;
        fraction |= (fractype)1 << 51;
    } else if (isinf_(src)) {
        exp = 0x7FF;
        fraction = 0;
    } else if (iszero_(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -1022) {
            fraction = 0;
        } else if (src->normal_exp > 1023) {
            exp = 0x7FF;
            fraction = 0;
        } else {
            exp = src->normal_exp + 1023;
            fraction >>= 8;
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
/* merge_units: end func_0011BDB0 */

/* merge_units: begin func_0011BE88 */
void func_0011BE88(FLO_union_type *src, fp_number_type *dst)
{
    fractype fraction = src->bits.fraction;
    int exp = src->bits.exp;
    int sign = src->bits.sign;
    dst->sign = sign;
    if (exp == 0) {
        dst->class = CLASS_ZERO;
    } else if (exp == 0x7FF) {
        dst->normal_exp = 0x3FF;
        if (fraction == 0) {
            dst->class = CLASS_INFINITY;
            dst->fraction.ll = (fractype)1 << 60;
        } else {
            if (fraction & ((fractype)1 << 51))
                dst->class = CLASS_QNAN;
            else
                dst->class = CLASS_SNAN;
            dst->fraction.ll = fraction;
        }
    } else {
        dst->normal_exp = exp - 0x3FF;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << 8) | ((fractype)1 << 60);
    }
}
/* merge_units: end func_0011BE88 */

/* merge_units: begin func_0011BF48 */
typedef long intfrac;
extern fp_number_type D_00499270;
#define fp_isnan(x) ((x)->class == CLASS_QNAN || (x)->class == CLASS_SNAN)
static __inline__ int fp_isinf(fp_number_type *x) { return x->class == CLASS_INFINITY; }
static __inline__ int fp_iszero_0011BF48(fp_number_type *x) { return x->class == CLASS_ZERO; }
#define LSHIFT(X) X = ((X) & 1) | ((X) >> 1)
fp_number_type *func_0011BF48(fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
    intfrac tfraction;
    int a_normal_exp;
    int b_normal_exp;
    fractype a_fraction;
    fractype b_fraction;

    if (fp_isnan(a)) return a;
    if (fp_isnan(b)) return b;
    if (fp_isinf(a)) {
        if (fp_isinf(b) && a->sign != b->sign) return &D_00499270;
        return a;
    }
    if (fp_isinf(b)) return b;
    if (fp_iszero_0011BF48(b)) {
        if (fp_iszero_0011BF48(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (fp_iszero_0011BF48(a)) return b;
    {
        int diff;
        a_normal_exp = a->normal_exp;
        b_normal_exp = b->normal_exp;
        a_fraction = a->fraction.ll;
        b_fraction = b->fraction.ll;
        diff = a_normal_exp - b_normal_exp;
        if (diff < 0) diff = -diff;
        if (diff < 64) {
            while (a_normal_exp > b_normal_exp) {
                b_normal_exp++;
                LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp) {
                a_normal_exp++;
                LSHIFT(a_fraction);
            }
        } else {
            if (a_normal_exp > b_normal_exp) {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            } else {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }
    if (a->sign != b->sign) {
        if (a->sign) tfraction = -a_fraction + b_fraction;
        else tfraction = a_fraction - b_fraction;
        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = tfraction;
        } else {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = -tfraction;
        }
        while (tmp->fraction.ll < ((fractype)1 << 60) && tmp->fraction.ll) {
            tmp->fraction.ll <<= 1;
            tmp->normal_exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction.ll = a_fraction + b_fraction;
    }
    tmp->class = CLASS_NUMBER;
    if (tmp->fraction.ll >= ((fractype)1 << 61)) {
        LSHIFT(tmp->fraction.ll);
        tmp->normal_exp++;
    }
    return tmp;
}
/* merge_units: end func_0011BF48 */

/* merge_units: begin func_0011C1A8 */
typedef union { DFtype value; fractype value_raw; } FLO_union_type_0011C1A8;
#if 0 /* merge_units */
extern void func_0011BE88(FLO_union_type_0011C1A8* src, fp_number_type* dst);
#endif /* merge_units */
#define func_0011BE88(a0, a1) (func_0011BE88((FLO_union_type *)(a0), (a1))) /* merge_units */


extern DFtype func_0011BDB0(fp_number_type* src);
extern fp_number_type* func_0011BF48(fp_number_type* a, fp_number_type* b, fp_number_type* tmp);
DFtype SoftFloat_DoubleAdd(DFtype arg_a, DFtype arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type* res;
    FLO_union_type_0011C1A8 au, bu;
    au.value = arg_a;
    bu.value = arg_b;
    func_0011BE88(&au, &a);
    func_0011BE88(&bu, &b);
    res = func_0011BF48(&a, &b, &tmp);
    return func_0011BDB0(res);
}
#undef func_0011BE88 /* merge_units */
/* merge_units: end func_0011C1A8 */

/* merge_units: begin func_0011C200 */
typedef union { DFtype value; fractype value_raw; } FLO_union_type_0011C200;
#if 0 /* merge_units */
extern void func_0011BE88(FLO_union_type_0011C200* src, fp_number_type* dst);
#endif /* merge_units */
#define func_0011BE88(a0, a1) (func_0011BE88((FLO_union_type *)(a0), (a1))) /* merge_units */


DFtype func_0011C200(DFtype arg_a, DFtype arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type* res;
    FLO_union_type_0011C200 au, bu;
    au.value = arg_a;
    bu.value = arg_b;
    func_0011BE88(&au, &a);
    func_0011BE88(&bu, &b);
    b.sign ^= 1;
    res = func_0011BF48(&a, &b, &tmp);
    return func_0011BDB0(res);
}
#undef func_0011BE88 /* merge_units */
/* merge_units: end func_0011C200 */
