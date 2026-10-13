/* newlib 1.9.0 stdlib/strtod.c: _strtod_r. Retail newlib was built with -g. */
__asm__(".set nomove\n dpadd = func_0011C1A8\n dpsub = func_0011C200\n dpmul = func_0011C268\n dpdiv = func_0011C4F0\n litodp = func_0011C7A0\n dptoli = func_0011C858\n dpcmp = SoftFloat_UnpackAndCompare\n __floatdidf = func_0011B7E0\n __fixdfdi = func_0011BA88\n");
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
#define _strtod_r func_00129D08
struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; __ULong _x[1]; };
struct _reent { int _errno; char _pad[0x3C]; struct _Bigint *_result; int _result_k; struct _Bigint *_p5s; struct _Bigint **_freelist; };
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
#define Balloc	func_00126280
#define Bfree	func_00126328
#define multadd func_00126358
#define hi0bits func_00126590
#define lo0bits func_00126610
#define i2b	func_001266D0
#define mult	func_00126708
#define pow5mult	func_00126918
#define lshift	func_00126A18
#define cmp	func_00126B70
#define diff	func_00126BD8
#define d2b	func_00126FD0
#define s2b	func_00126460
#define ulp	func_00126D68
#define ratio	func_00127158
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
_Bigint *s2b(struct _reent *, const char *, int, int, __ULong);
double ulp(double x);
double ratio(_Bigint *a, _Bigint *b);
extern const double D_00499BB0[];
#define HUGE_VAL (D_00499BB0[0])
#define ERANGE 34
#define _HAVE_STDC
#define DBL_DIG 15
#define FLT_ROUNDS 0
#define DBL_MAX_10_EXP 308
#define FLT_RADIX 2
#define Bcopy(x,y) memcpy((char *)&x->_sign, (char *)&y->_sign, y->_wds*sizeof(__Long) + 2*sizeof(int))
#define n_bigtens 5
extern _CONST double tinytens[];
extern _CONST double bigtens[];
extern _CONST double tens[];

double
_DEFUN (_strtod_r, (ptr, s00, se),
	struct _reent *ptr _AND
	_CONST char *s00 _AND
	char **se)
{
  int bb2, bb5, bbe, bd2, bd5, bbbits, bs2, c, dsign, e1, esign, i, j,
    k, nd, nd0, nf, nz, nz0, sign;
  long e;
  _CONST char *s, *s0, *s1;
  double aadj, aadj1, adj;
  long L;
  unsigned long z;
  __ULong y;
  union double_union rv, rv0;

  _Bigint *bb, *bb1, *bd, *bd0, *bs, *delta;
  sign = nz0 = nz = 0;
  rv.d = 0.;
  for (s = s00;; s++)
    switch (*s)
      {
      case '-':
	sign = 1;
	/* no break */
      case '+':
	if (*++s)
	  goto break2;
	/* no break */
      case 0:
	s = s00;
	goto ret;
      case '\t':
      case '\n':
      case '\v':
      case '\f':
      case '\r':
      case ' ':
	continue;
      default:
	goto break2;
      }
break2:
  if (*s == '0')
    {
      nz0 = 1;
      while (*++s == '0');
      if (!*s)
	goto ret;
    }
  s0 = s;
  y = z = 0;
  for (nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
    if (nd < 9)
      y = 10 * y + c - '0';
    else if (nd < 16)
      z = 10 * z + c - '0';
  nd0 = nd;
  if (c == '.')
    {
      c = *++s;
      if (!nd)
	{
	  for (; c == '0'; c = *++s)
	    nz++;
	  if (c > '0' && c <= '9')
	    {
	      s0 = s;
	      nf += nz;
	      nz = 0;
	      goto have_dig;
	    }
	  goto dig_done;
	}
      for (; c >= '0' && c <= '9'; c = *++s)
	{
	have_dig:
	  nz++;
	  if (c -= '0')
	    {
	      nf += nz;
	      for (i = 1; i < nz; i++)
		if (nd++ < 9)
		  y *= 10;
		else if (nd <= DBL_DIG + 1)
		  z *= 10;
	      if (nd++ < 9)
		y = 10 * y + c;
	      else if (nd <= DBL_DIG + 1)
		z = 10 * z + c;
	      nz = 0;
	    }
	}
    }
dig_done:
  e = 0;
  if (c == 'e' || c == 'E')
    {
      if (!nd && !nz && !nz0)
	{
	  s = s00;
	  goto ret;
	}
      s00 = s;
      esign = 0;
      switch (c = *++s)
	{
	case '-':
	  esign = 1;
	case '+':
	  c = *++s;
	}
      if (c >= '0' && c <= '9')
	{
	  while (c == '0')
	    c = *++s;
	  if (c > '0' && c <= '9')
	    {
	      e = c - '0';
	      s1 = s;
	      while ((c = *++s) >= '0' && c <= '9')
		e = 10 * e + c - '0';
	      if (s - s1 > 8)
		/* Avoid confusion from exponents
		 * so large that e might overflow.
		 */
		e = 9999999L;
	      if (esign)
		e = -e;
	    }
	  else
	    e = 0;
	}
      else
	s = s00;
    }
  if (!nd)
    {
      if (!nz && !nz0)
	s = s00;
      goto ret;
    }
  e1 = e -= nf;

  /* Now we have nd0 digits, starting at s0, followed by a
   * decimal point, followed by nd-nd0 digits.  The number we're
   * after is the integer represented by those digits times
   * 10**e */

  if (!nd0)
    nd0 = nd;
  k = nd < DBL_DIG + 1 ? nd : DBL_DIG + 1;
  rv.d = y;
  if (k > 9)
    rv.d = tens[k - 9] * rv.d + z;
  bd0 = 0;
  if (nd <= DBL_DIG
#ifndef RND_PRODQUOT
      && FLT_ROUNDS == 1
#endif
    )
    {
      if (!e)
	goto ret;
      if (e > 0)
	{
	  if (e <= Ten_pmax)
	    {
#ifdef VAX
	      goto vax_ovfl_check;
#else
	      /* rv.d = */ rounded_product (rv.d, tens[e]);
	      goto ret;
#endif
	    }
	  i = DBL_DIG - nd;
	  if (e <= Ten_pmax + i)
	    {
	      /* A fancier test would sometimes let us do
				 * this for larger i values.
				 */
	      e -= i;
	      rv.d *= tens[i];
#ifdef VAX
	      /* VAX exponent range is so narrow we must
	       * worry about overflow here...
	       */
	    vax_ovfl_check:
	      word0 (rv) -= P * Exp_msk1;
	      /* rv.d = */ rounded_product (rv.d, tens[e]);
	      if ((word0 (rv) & Exp_mask)
		  > Exp_msk1 * (DBL_MAX_EXP + Bias - 1 - P))
		goto ovfl;
	      word0 (rv) += P * Exp_msk1;
#else
	      /* rv.d = */ rounded_product (rv.d, tens[e]);
#endif
	      goto ret;
	    }
	}
#ifndef Inaccurate_Divide
      else if (e >= -Ten_pmax)
	{
	  /* rv.d = */ rounded_quotient (rv.d, tens[-e]);
	  goto ret;
	}
#endif
    }
  e1 += nd - k;

  /* Get starting approximation = rv.d * 10**e1 */

  if (e1 > 0)
    {
      if ((i = e1 & 15) != 0)
	rv.d *= tens[i];
      if (e1 &= ~15)
	{
	  if (e1 > DBL_MAX_10_EXP)
	    {
	    ovfl:
	      ptr->_errno = ERANGE;
#ifdef _HAVE_STDC
	      rv.d = HUGE_VAL;
#else
	      /* Can't trust HUGE_VAL */
#ifdef IEEE_Arith
	      word0 (rv) = Exp_mask;
#ifndef _DOUBLE_IS_32BITS
	      word1 (rv) = 0;
#endif
#else
	      word0 (rv) = Big0;
#ifndef _DOUBLE_IS_32BITS
	      word1 (rv) = Big1;
#endif
#endif
#endif
	      if (bd0)
		goto retfree;
	      goto ret;
	    }
	  if (e1 >>= 4)
	    {
	      for (j = 0; e1 > 1; j++, e1 >>= 1)
		if (e1 & 1)
		  rv.d *= bigtens[j];
	      /* The last multiplication could overflow. */
	      word0 (rv) -= P * Exp_msk1;
	      rv.d *= bigtens[j];
	      if ((z = word0 (rv) & Exp_mask)
		  > Exp_msk1 * (DBL_MAX_EXP + Bias - P))
		goto ovfl;
	      if (z > Exp_msk1 * (DBL_MAX_EXP + Bias - 1 - P))
		{
		  /* set to largest number */
		  /* (Can't trust DBL_MAX) */
		  word0 (rv) = Big0;
#ifndef _DOUBLE_IS_32BITS
		  word1 (rv) = Big1;
#endif
		}
	      else
		word0 (rv) += P * Exp_msk1;
	    }

	}
    }
  else if (e1 < 0)
    {
      e1 = -e1;
      if ((i = e1 & 15) != 0)
	rv.d /= tens[i];
      if (e1 &= ~15)
	{
	  e1 >>= 4;
	  if (e1 >= 1 << n_bigtens)
            goto undfl;
	  for (j = 0; e1 > 1; j++, e1 >>= 1)
	    if (e1 & 1)
	      rv.d *= tinytens[j];
	  /* The last multiplication could underflow. */
	  rv0.d = rv.d;
	  rv.d *= tinytens[j];
	  if (!rv.d)
	    {
	      rv.d = 2. * rv0.d;
	      rv.d *= tinytens[j];
	      if (!rv.d)
		{
		undfl:
		  rv.d = 0.;
		  ptr->_errno = ERANGE;
		  if (bd0)
		    goto retfree;
		  goto ret;
		}
#ifndef _DOUBLE_IS_32BITS
	      word0 (rv) = Tiny0;
	      word1 (rv) = Tiny1;
#else
	      word0 (rv) = Tiny1;
#endif
	      /* The refinement below will clean
	       * this approximation up.
	       */
	    }
	}
    }

  /* Now the hard part -- adjusting rv to the correct value.*/

  /* Put digits into bd: true value = bd * 10^e */

  bd0 = s2b (ptr, s0, nd0, nd, y);

  for (;;)
    {
      bd = Balloc (ptr, bd0->_k);
      Bcopy (bd, bd0);
      bb = d2b (ptr, rv.d, &bbe, &bbbits);	/* rv.d = bb * 2^bbe */
      bs = i2b (ptr, 1);

      if (e >= 0)
	{
	  bb2 = bb5 = 0;
	  bd2 = bd5 = e;
	}
      else
	{
	  bb2 = bb5 = -e;
	  bd2 = bd5 = 0;
	}
      if (bbe >= 0)
	bb2 += bbe;
      else
	bd2 -= bbe;
      bs2 = bb2;
#ifdef Sudden_Underflow
#ifdef IBM
      j = 1 + 4 * P - 3 - bbbits + ((bbe + bbbits - 1) & 3);
#else
      j = P + 1 - bbbits;
#endif
#else
      i = bbe + bbbits - 1;	/* logb(rv.d) */
      if (i < Emin)		/* denormal */
	j = bbe + (P - Emin);
      else
	j = P + 1 - bbbits;
#endif
      bb2 += j;
      bd2 += j;
      i = bb2 < bd2 ? bb2 : bd2;
      if (i > bs2)
	i = bs2;
      if (i > 0)
	{
	  bb2 -= i;
	  bd2 -= i;
	  bs2 -= i;
	}
      if (bb5 > 0)
	{
	  bs = pow5mult (ptr, bs, bb5);
	  bb1 = mult (ptr, bs, bb);
	  Bfree (ptr, bb);
	  bb = bb1;
	}
      if (bb2 > 0)
	bb = lshift (ptr, bb, bb2);
      if (bd5 > 0)
	bd = pow5mult (ptr, bd, bd5);
      if (bd2 > 0)
	bd = lshift (ptr, bd, bd2);
      if (bs2 > 0)
	bs = lshift (ptr, bs, bs2);
      delta = diff (ptr, bb, bd);
      dsign = delta->_sign;
      delta->_sign = 0;
      i = cmp (delta, bs);
      if (i < 0)
	{
	  /* Error is less than half an ulp -- check for
	   * special case of mantissa a power of two.
	   */
	  if (dsign || word1 (rv) || word0 (rv) & Bndry_mask)
	    break;
	  delta = lshift (ptr, delta, Log2P);
	  if (cmp (delta, bs) > 0)
	    goto drop_down;
	  break;
	}
      if (i == 0)
	{
	  /* exactly half-way between */
	  if (dsign)
	    {
	      if ((word0 (rv) & Bndry_mask1) == Bndry_mask1
		  && word1 (rv) == 0xffffffff)
		{
		  /*boundary case -- increment exponent*/
		  word0 (rv) = (word0 (rv) & Exp_mask)
		    + Exp_msk1
#ifdef IBM
		    | Exp_msk1 >> 4
#endif
		    ;
#ifndef _DOUBLE_IS_32BITS
		  word1 (rv) = 0;
#endif
		  break;
		}
	    }
	  else if (!(word0 (rv) & Bndry_mask) && !word1 (rv))
	    {
	    drop_down:
	      /* boundary case -- decrement exponent */
#ifdef Sudden_Underflow
	      L = word0 (rv) & Exp_mask;
#ifdef IBM
	      if (L < Exp_msk1)
#else
	      if (L <= Exp_msk1)
#endif
		goto undfl;
	      L -= Exp_msk1;
#else
	      L = (word0 (rv) & Exp_mask) - Exp_msk1;
#endif
	      word0 (rv) = L | Bndry_mask1;
#ifndef _DOUBLE_IS_32BITS
	      word1 (rv) = 0xffffffff;
#endif
#ifdef IBM
	      goto cont;
#else
	      break;
#endif
	    }
#ifndef ROUND_BIASED
	  if (!(word1 (rv) & LSB))
	    break;
#endif
	  if (dsign)
	    rv.d += ulp (rv.d);
#ifndef ROUND_BIASED
	  else
	    {
	      rv.d -= ulp (rv.d);
#ifndef Sudden_Underflow
	      if (!rv.d)
		goto undfl;
#endif
	    }
#endif
	  break;
	}
      if ((aadj = ratio (delta, bs)) <= 2.)
	{
	  if (dsign)
	    aadj = aadj1 = 1.;
	  else if (word1 (rv) || word0 (rv) & Bndry_mask)
	    {
#ifndef Sudden_Underflow
	      if (word1 (rv) == Tiny1 && !word0 (rv))
		goto undfl;
#endif
	      aadj = 1.;
	      aadj1 = -1.;
	    }
	  else
	    {
	      /* special case -- power of FLT_RADIX to be */
	      /* rounded down... */

	      if (aadj < 2. / FLT_RADIX)
		aadj = 1. / FLT_RADIX;
	      else
		aadj *= 0.5;
	      aadj1 = -aadj;
	    }
	}
      else
	{
	  aadj *= 0.5;
	  aadj1 = dsign ? aadj : -aadj;
#ifdef Check_FLT_ROUNDS
	  switch (FLT_ROUNDS)
	    {
	    case 2:		/* towards +infinity */
	      aadj1 -= 0.5;
	      break;
	    case 0:		/* towards 0 */
	    case 3:		/* towards -infinity */
	      aadj1 += 0.5;
	    }
#else
	  if (FLT_ROUNDS == 0)
	    aadj1 += 0.5;
#endif
	}
      y = word0 (rv) & Exp_mask;

      /* Check for overflow */

      if (y == Exp_msk1 * (DBL_MAX_EXP + Bias - 1))
	{
	  rv0.d = rv.d;
	  word0 (rv) -= P * Exp_msk1;
	  adj = aadj1 * ulp (rv.d);
	  rv.d += adj;
	  if ((word0 (rv) & Exp_mask) >=
	      Exp_msk1 * (DBL_MAX_EXP + Bias - P))
	    {
	      if (word0 (rv0) == Big0 && word1 (rv0) == Big1)
		goto ovfl;
#ifdef _DOUBLE_IS_32BITS
	      word0 (rv) = Big1;
#else
	      word0 (rv) = Big0;
	      word1 (rv) = Big1;
#endif
	      goto cont;
	    }
	  else
	    word0 (rv) += P * Exp_msk1;
	}
      else
	{
#ifdef Sudden_Underflow
	  if ((word0 (rv) & Exp_mask) <= P * Exp_msk1)
	    {
	      rv0.d = rv.d;
	      word0 (rv) += P * Exp_msk1;
	      adj = aadj1 * ulp (rv.d);
	      rv.d += adj;
#ifdef IBM
	      if ((word0 (rv) & Exp_mask) < P * Exp_msk1)
#else
	      if ((word0 (rv) & Exp_mask) <= P * Exp_msk1)
#endif
		{
		  if (word0 (rv0) == Tiny0
		      && word1 (rv0) == Tiny1)
		    goto undfl;
		  word0 (rv) = Tiny0;
		  word1 (rv) = Tiny1;
		  goto cont;
		}
	      else
		word0 (rv) -= P * Exp_msk1;
	    }
	  else
	    {
	      adj = aadj1 * ulp (rv.d);
	      rv.d += adj;
	    }
#else
	  /* Compute adj so that the IEEE rounding rules will
	   * correctly round rv.d + adj in some half-way cases.
	   * If rv.d * ulp(rv.d) is denormalized (i.e.,
	   * y <= (P-1)*Exp_msk1), we must adjust aadj to avoid
	   * trouble from bits lost to denormalization;
	   * example: 1.2e-307 .
	   */
	  if (y <= (P - 1) * Exp_msk1 && aadj >= 1.)
	    {
	      aadj1 = (double) (int) (aadj + 0.5);
	      if (!dsign)
		aadj1 = -aadj1;
	    }
	  adj = aadj1 * ulp (rv.d);
	  rv.d += adj;
#endif
	}
      z = word0 (rv) & Exp_mask;
      if (y == z)
	{
	  /* Can we stop now? */
	  L = aadj;
	  aadj -= L;
	  /* The tolerances below are conservative. */
	  if (dsign || word1 (rv) || word0 (rv) & Bndry_mask)
	    {
	      if (aadj < .4999999 || aadj > .5000001)
		break;
	    }
	  else if (aadj < .4999999 / FLT_RADIX)
	    break;
	}
    cont:
      Bfree (ptr, bb);
      Bfree (ptr, bd);
      Bfree (ptr, bs);
      Bfree (ptr, delta);
    }
retfree:
  Bfree (ptr, bb);
  Bfree (ptr, bd);
  Bfree (ptr, bs);
  Bfree (ptr, bd0);
  Bfree (ptr, delta);
ret:
  if (se)
    *se = (char *) s;
  return sign ? -rv.d : rv.d;
}

