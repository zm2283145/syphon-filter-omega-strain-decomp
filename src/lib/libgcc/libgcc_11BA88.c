/*
 * lib/libgcc: 4 files, 0011BA88-0011BCE0
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
