/* libgcc2 __fixunsdfdi. Retail libgcc was assembled without delay-slot swapping (as with gas -g);
   `.set nomove` reproduces that. The EE soft-float libcalls are aliased to their retail functions. */
__asm__(".set nomove\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpmul = func_0011C268\n"
        "dptoul = func_0011C980\n"
        "__floatdidf = func_0011B7E0\n"
        "dpadd = SoftFloat_DoubleAdd\n"
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
UDItype func_0011B970(DFtype a)
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

