/*
 * lib/libgcc: 2 files, 0011B888-0011B970
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011B888 */
/* libgcc2 __floatdisf. Retail libgcc was assembled without delay-slot swapping (as with gas -g);
   `.set nomove` reproduces that. The EE soft-float libcalls are aliased to their retail functions. */
__asm__(".set nomove\n"
        "litodp = func_0011C7A0\n"
        "dpmul = func_0011C268\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dptofp = SoftFloat_DoubleToFloat");

typedef int SItype;
typedef unsigned int USItype;
typedef long DItype;
typedef unsigned long UDItype;
typedef float SFtype;
typedef double DFtype;

#define WORD_SIZE (sizeof (SItype) * 8)
#define HIGH_HALFWORD_COEFF (((UDItype) 1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((UDItype) 1) << WORD_SIZE)
#define DI_SIZE (sizeof (DItype) * 8)
#define DF_SIZE 53
#define SF_SIZE 24

SFtype SoftFloat_S64ToFloat(DItype u)
{
  DFtype f;

  if (DF_SIZE < DI_SIZE && DF_SIZE > (DI_SIZE - DF_SIZE + SF_SIZE))
    {
#define REP_BIT ((UDItype) 1 << (DI_SIZE - DF_SIZE))
      if (! (- ((DItype) 1 << DF_SIZE) < u
             && u < ((DItype) 1 << DF_SIZE)))
        {
          if ((UDItype) u & (REP_BIT - 1))
            u |= REP_BIT;
        }
    }
  f = (SItype) (u >> WORD_SIZE);
  f *= HIGH_HALFWORD_COEFF;
  f *= HIGH_HALFWORD_COEFF;
  f += (USItype) (u & (HIGH_WORD_COEFF - 1));

  return (SFtype) f;
}
/* merge_units: end func_0011B888 */

/* merge_units: begin func_0011B970 */
/* libgcc2 __fixunsdfdi. Retail libgcc was assembled without delay-slot swapping (as with gas -g);
   `.set nomove` reproduces that. The EE soft-float libcalls are aliased to their retail functions. */
__asm__(".set nomove\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpmul = func_0011C268\n"
        "dptoul = func_0011C980\n"
        "__floatdidf = func_0011B7E0\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = func_0011C200");UDItype func_0011B970(DFtype a)
{
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
/* merge_units: end func_0011B970 */
