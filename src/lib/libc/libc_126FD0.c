/* newlib 1.9.0 stdlib/mprec.c: d2b. */
__asm__(".set nomove\n");
typedef unsigned int size_t;
typedef unsigned int __uint32_t;
typedef int __int32_t;
typedef unsigned int __ULong;
typedef int __Long;
#define _DEFUN(name, arglist, args) name(args)
#define _AND ,
#define _CONST const
#define _EXFUN(name, proto) name proto
#define DBL_MAX_EXP 1024
#define IEEE_8087
#define NULL 0
struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; __ULong _x[1]; };
struct _reent { char _pad[0x40]; struct _Bigint *_result; int _result_k; struct _Bigint *_p5s; struct _Bigint **_freelist; };
extern void *memcpy(void *, const void *, size_t);
#ifdef Unsigned_Shifts
#define Sign_Extend(a,b) if (b < 0) a |= (__uint32_t)0xffff0000;
#else
#define Sign_Extend(a,b) /*no-op*/
#endif

#if defined(IEEE_8087) + defined(IEEE_MC68k) + defined(VAX) + defined(IBM) != 1
Exactly one of IEEE_8087, IEEE_MC68k, VAX, or IBM should be defined.
#endif

/* If we are going to examine or modify specific bits in a double using
   the word0 and/or word1 macros, then we must wrap the double inside
   a union.  This is necessary to avoid undefined behavior according to
   the ANSI C spec.  */
union double_union
{
  double d;
  __uint32_t i[2];
};

#ifdef IEEE_8087
#define word0(x) (x.i[1])
#define word1(x) (x.i[0])
#else
#define word0(x) (x.i[0])
#define word1(x) (x.i[1])
#endif

/* The following definition of Storeinc is appropriate for MIPS processors.
 * An alternative that might be better on some machines is
 * #define Storeinc(a,b,c) (*a++ = b << 16 | c & 0xffff)
 */
#if defined(IEEE_8087) + defined(VAX)
#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, \
((unsigned short *)a)[0] = (unsigned short)c, a++)
#else
#define Storeinc(a,b,c) (((unsigned short *)a)[0] = (unsigned short)b, \
((unsigned short *)a)[1] = (unsigned short)c, a++)
#endif

/* #define P DBL_MANT_DIG */
/* Ten_pmax = floor(P*log(2)/log(5)) */
/* Bletch = (highest power of 2 < DBL_MAX_10_EXP) / 16 */
/* Quick_max = floor((P-1)*log(FLT_RADIX)/log(10) - 1) */
/* Int_max = floor(P*log(FLT_RADIX)/log(10) - 1) */

#if defined(IEEE_8087) + defined(IEEE_MC68k)
#if defined (_DOUBLE_IS_32BITS) 
#define Exp_shift   23
#define Exp_shift1  23
#define Exp_msk1    ((__uint32_t)0x00800000L)
#define Exp_msk11   ((__uint32_t)0x00800000L)
#define Exp_mask    ((__uint32_t)0x7f800000L)
#define P    	    24
#define Bias 	    127
#if 0
#define IEEE_Arith  /* it is, but the code doesn't handle IEEE singles yet */
#endif
#define Emin        (-126)
#define Exp_1       ((__uint32_t)0x3f800000L)
#define Exp_11      ((__uint32_t)0x3f800000L)
#define Ebits 	    8
#define Frac_mask   ((__uint32_t)0x007fffffL)
#define Frac_mask1  ((__uint32_t)0x007fffffL)
#define Ten_pmax    10
#define Sign_bit    ((__uint32_t)0x80000000L)
#define Ten_pmax    10
#define Bletch	    2
#define Bndry_mask  ((__uint32_t)0x007fffffL)
#define Bndry_mask1 ((__uint32_t)0x007fffffL)
#define LSB 1
#define Sign_bit    ((__uint32_t)0x80000000L)
#define Log2P 	    1
#define Tiny0 	    0
#define Tiny1 	    1
#define Quick_max   5
#define Int_max     6
#define Infinite(x) (word0(x) == ((__uint32_t)0x7f800000L))
#undef word0
#undef word1

#define word0(x) (x.i[0])
#define word1(x) 0
#else

#define Exp_shift  20
#define Exp_shift1 20
#define Exp_msk1    ((__uint32_t)0x100000L)
#define Exp_msk11   ((__uint32_t)0x100000L)
#define Exp_mask  ((__uint32_t)0x7ff00000L)
#define P 53
#define Bias 1023
#define IEEE_Arith
#define Emin (-1022)
#define Exp_1  ((__uint32_t)0x3ff00000L)
#define Exp_11 ((__uint32_t)0x3ff00000L)
#define Ebits 11
#define Frac_mask  ((__uint32_t)0xfffffL)
#define Frac_mask1 ((__uint32_t)0xfffffL)
#define Ten_pmax 22
#define Bletch 0x10
#define Bndry_mask  ((__uint32_t)0xfffffL)
#define Bndry_mask1 ((__uint32_t)0xfffffL)
#define LSB 1
#define Sign_bit ((__uint32_t)0x80000000L)
#define Log2P 1
#define Tiny0 0
#define Tiny1 1
#define Quick_max 14
#define Int_max 14
#define Infinite(x) (word0(x) == ((__uint32_t)0x7ff00000L)) /* sufficient test for here */
#endif

#else
#undef  Sudden_Underflow
#define Sudden_Underflow
#ifdef IBM
#define Exp_shift  24
#define Exp_shift1 24
#define Exp_msk1   ((__uint32_t)0x1000000L)
#define Exp_msk11  ((__uint32_t)0x1000000L)
#define Exp_mask  ((__uint32_t)0x7f000000L)
#define P 14
#define Bias 65
#define Exp_1  ((__uint32_t)0x41000000L)
#define Exp_11 ((__uint32_t)0x41000000L)
#define Ebits 8	/* exponent has 7 bits, but 8 is the right value in b2d */
#define Frac_mask  ((__uint32_t)0xffffffL)
#define Frac_mask1 ((__uint32_t)0xffffffL)
#define Bletch 4
#define Ten_pmax 22
#define Bndry_mask  ((__uint32_t)0xefffffL)
#define Bndry_mask1 ((__uint32_t)0xffffffL)
#define LSB 1
#define Sign_bit ((__uint32_t)0x80000000L)
#define Log2P 4
#define Tiny0 ((__uint32_t)0x100000L)
#define Tiny1 0
#define Quick_max 14
#define Int_max 15
#else /* VAX */
#define Exp_shift  23
#define Exp_shift1 7
#define Exp_msk1    0x80
#define Exp_msk11   ((__uint32_t)0x800000L)
#define Exp_mask  ((__uint32_t)0x7f80L)
#define P 56
#define Bias 129
#define Exp_1  ((__uint32_t)0x40800000L)
#define Exp_11 ((__uint32_t)0x4080L)
#define Ebits 8
#define Frac_mask  ((__uint32_t)0x7fffffL)
#define Frac_mask1 ((__uint32_t)0xffff007fL)
#define Ten_pmax 24
#define Bletch 2
#define Bndry_mask  ((__uint32_t)0xffff007fL)
#define Bndry_mask1 ((__uint32_t)0xffff007fL)
#define LSB ((__uint32_t)0x10000L)
#define Sign_bit ((__uint32_t)0x8000L)
#define Log2P 1
#define Tiny0 0x80
#define Tiny1 0
#define Quick_max 15
#define Int_max 15
#endif
#endif

#ifndef IEEE_Arith
#define ROUND_BIASED
#endif

#ifdef RND_PRODQUOT
#define rounded_product(a,b) a = rnd_prod(a, b)
#define rounded_quotient(a,b) a = rnd_quot(a, b)
#ifdef KR_headers
extern double rnd_prod(), rnd_quot();
#else
extern double rnd_prod(double, double), rnd_quot(double, double);
#endif
#else
#define rounded_product(a,b) a *= b
#define rounded_quotient(a,b) a /= b
#endif

#define Big0 (Frac_mask1 | Exp_msk1*(DBL_MAX_EXP+Bias-1))
#define Big1 ((__uint32_t)0xffffffffL)

#ifndef Just_16
/* When Pack_32 is not defined, we store 16 bits per 32-bit long.
 * This makes some inner loops simpler and sometimes saves work
 * during multiplications, but it often seems to make things slightly
 * slower.  Hence the default is now to store 32 bits per long.
 */

#ifndef Pack_32
#define Pack_32
#endif
#endif


typedef struct _Bigint _Bigint;
#define Balloc	Newlib_Balloc
#define Bfree	Newlib_Bfree
#define multadd Newlib_Multadd
#define hi0bits Newlib_Hi0bits
#define lo0bits Newlib_Lo0bits
#define i2b	Newlib_I2b
#define mult	Newlib_Multiply
#define pow5mult	Newlib_Pow5mult
#define lshift	Newlib_Lshift
#define cmp	Newlib_Mcmp
#define diff	Newlib_Mdiff
#define d2b	Newlib_D2b
#define quorem	Newlib_Quorem
#define tens D_00499E38
#define bigtens D_00499F00
#define tinytens D_00499F28
_Bigint *Balloc(struct _reent *p, int k);
void Bfree(struct _reent *p, _Bigint *v);
_Bigint *multadd(struct _reent *p, _Bigint *, int, int);
_Bigint *i2b(struct _reent *, int);
_Bigint *mult(struct _reent *, _Bigint *, _Bigint *);
_Bigint *pow5mult(struct _reent *, _Bigint *, int k);
int hi0bits(__ULong);
int lo0bits(__ULong *);
_Bigint *d2b(struct _reent *p, double d, int *e, int *bits);
_Bigint *lshift(struct _reent *p, _Bigint *b, int k);
_Bigint *diff(struct _reent *p, _Bigint *a, _Bigint *b);
int cmp(_Bigint *a, _Bigint *b);
int quorem(_Bigint *b, _Bigint *S);
#define Bcopy(x,y) memcpy((char *)&x->_sign, (char *)&y->_sign, y->_wds*sizeof(__Long) + 2*sizeof(int))
#define n_bigtens 5
extern _CONST double tinytens[];
extern _CONST double bigtens[];
extern _CONST double tens[];
_Bigint *
_DEFUN (d2b,
	(ptr, _d, e, bits),
	struct _reent * ptr _AND
	double _d _AND
	int *e _AND
	int *bits)

{
  union double_union d;
  _Bigint *b;
  int de, i, k;
  __ULong *x, y, z;
#ifdef VAX
  __ULong d0, d1;
#endif
  d.d = _d;
#ifdef VAX
  d0 = word0 (d) >> 16 | word0 (d) << 16;
  d1 = word1 (d) >> 16 | word1 (d) << 16;
#else
#define d0 word0(d)
#define d1 word1(d)
  d.d = _d;
#endif

#ifdef Pack_32
  b = Balloc (ptr, 1);
#else
  b = Balloc (ptr, 2);
#endif
  x = b->_x;

  z = d0 & Frac_mask;
  d0 &= 0x7fffffff;		/* clear sign bit, which we ignore */
#ifdef Sudden_Underflow
  de = (int) (d0 >> Exp_shift);
#ifndef IBM
  z |= Exp_msk11;
#endif
#else
  if ((de = (int) (d0 >> Exp_shift)) != 0)
    z |= Exp_msk1;
#endif
#ifdef Pack_32
#ifndef _DOUBLE_IS_32BITS
  if (d1)
    {
      y = d1;
      k = lo0bits (&y);
      if (k)
	{
         x[0] = y | z << (32 - k);
	  z >>= k;
	}
      else
	x[0] = y;
      i = b->_wds = (x[1] = z) ? 2 : 1;
    }
  else
#endif
    {
#ifdef DEBUG
      if (!z)
	Bug ("Zero passed to d2b");
#endif
      k = lo0bits (&z);
      x[0] = z;
      i = b->_wds = 1;
#ifndef _DOUBLE_IS_32BITS
      k += 32;
#endif
    }
#else
  if (d1)
    {
      y = d1;
      k = lo0bits (&y);
      if (k)
	if (k >= 16)
	  {
	    x[0] = y | z << 32 - k & 0xffff;
	    x[1] = z >> k - 16 & 0xffff;
	    x[2] = z >> k;
	    i = 2;
	  }
	else
	  {
	    x[0] = y & 0xffff;
	    x[1] = y >> 16 | z << 16 - k & 0xffff;
	    x[2] = z >> k & 0xffff;
	    x[3] = z >> k + 16;
	    i = 3;
	  }
      else
	{
	  x[0] = y & 0xffff;
	  x[1] = y >> 16;
	  x[2] = z & 0xffff;
	  x[3] = z >> 16;
	  i = 3;
	}
    }
  else
    {
#ifdef DEBUG
      if (!z)
	Bug ("Zero passed to d2b");
#endif
      k = lo0bits (&z);
      if (k >= 16)
	{
	  x[0] = z;
	  i = 0;
	}
      else
	{
	  x[0] = z & 0xffff;
	  x[1] = z >> 16;
	  i = 1;
	}
      k += 32;
    }
  while (!x[i])
    --i;
  b->_wds = i + 1;
#endif
#ifndef Sudden_Underflow
  if (de)
    {
#endif
#ifdef IBM
      *e = (de - Bias - (P - 1) << 2) + k;
      *bits = 4 * P + 8 - k - hi0bits (word0 (d) & Frac_mask);
#else
      *e = de - Bias - (P - 1) + k;
      *bits = P - k;
#endif
#ifndef Sudden_Underflow
    }
  else
    {
      *e = de - Bias - (P - 1) + 1 + k;
#ifdef Pack_32
      *bits = 32 * i - hi0bits (x[i - 1]);
#else
      *bits = (i + 2) * 16 - hi0bits (x[i]);
#endif
    }
#endif
  return b;
}
#undef d0
#undef d1

