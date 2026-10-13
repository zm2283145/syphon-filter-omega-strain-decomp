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

