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

