/* newlib 1.9.0 stdlib/dtoa.c: _dtoa_r (quorem = func_00121E78 is its own matched unit). Retail newlib was built with -g. */
__asm__(".set nomove\n dpadd = func_0011C1A8\n dpsub = func_0011C200\n dpmul = func_0011C268\n dpdiv = func_0011C4F0\n litodp = func_0011C7A0\n dptoli = func_0011C858\n dpcmp = SoftFloat_UnpackAndCompare\n");
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
#define _dtoa_r func_001220A8
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
#define quorem	func_00121E78
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

char *
_DEFUN (_dtoa_r,
	(ptr, _d, mode, ndigits, decpt, sign, rve),
	struct _reent *ptr _AND
	double _d _AND
	int mode _AND
	int ndigits _AND
	int *decpt _AND
	int *sign _AND
	char **rve)
{
  /*	Arguments ndigits, decpt, sign are similar to those
	of ecvt and fcvt; trailing zeros are suppressed from
	the returned string.  If not null, *rve is set to point
	to the end of the return value.  If d is +-Infinity or NaN,
	then *decpt is set to 9999.

	mode:
		0 ==> shortest string that yields d when read in
			and rounded to nearest.
		1 ==> like 0, but with Steele & White stopping rule;
			e.g. with IEEE P754 arithmetic , mode 0 gives
			1e23 whereas mode 1 gives 9.999999999999999e22.
		2 ==> max(1,ndigits) significant digits.  This gives a
			return value similar to that of ecvt, except
			that trailing zeros are suppressed.
		3 ==> through ndigits past the decimal point.  This
			gives a return value similar to that from fcvt,
			except that trailing zeros are suppressed, and
			ndigits can be negative.
		4-9 should give the same return values as 2-3, i.e.,
			4 <= mode <= 9 ==> same return as mode
			2 + (mode & 1).  These modes are mainly for
			debugging; often they run slower but sometimes
			faster than modes 2-3.
		4,5,8,9 ==> left-to-right digit generation.
		6-9 ==> don't try fast floating-point estimate
			(if applicable).

		Values of mode other than 0-9 are treated as mode 0.

		Sufficient space is allocated to the return value
		to hold the suppressed trailing zeros.
	*/

  int bbits, b2, b5, be, dig, i, ieps, ilim, ilim0, ilim1, j, j1, k, k0,
    k_check, leftright, m2, m5, s2, s5, spec_case, try_quick;
  union double_union d, d2, eps;
  __Long L;
#ifndef Sudden_Underflow
  int denorm;
  __ULong x;
#endif
  _Bigint *b, *b1, *delta, *mlo, *mhi, *S;
  double ds;
  char *s, *s0;

  d.d = _d;

  if (ptr->_result)
    {
      ptr->_result->_k = ptr->_result_k;
      ptr->_result->_maxwds = 1 << ptr->_result_k;
      Bfree (ptr, ptr->_result);
      ptr->_result = 0;
    }

  if (word0 (d) & Sign_bit)
    {
      /* set sign for everything, including 0's and NaNs */
      *sign = 1;
      word0 (d) &= ~Sign_bit;	/* clear sign bit */
    }
  else
    *sign = 0;

#if defined(IEEE_Arith) + defined(VAX)
#ifdef IEEE_Arith
  if ((word0 (d) & Exp_mask) == Exp_mask)
#else
  if (word0 (d) == 0x8000)
#endif
    {
      /* Infinity or NaN */
      *decpt = 9999;
      s =
#ifdef IEEE_Arith
	!word1 (d) && !(word0 (d) & 0xfffff) ? "Infinity" :
#endif
	"NaN";
      if (rve)
	*rve =
#ifdef IEEE_Arith
	  s[3] ? s + 8 :
#endif
	  s + 3;
      return s;
    }
#endif
#ifdef IBM
  d.d += 0;			/* normalize */
#endif
  if (!d.d)
    {
      *decpt = 1;
      s = "0";
      if (rve)
	*rve = s + 1;
      return s;
    }

  b = d2b (ptr, d.d, &be, &bbits);
#ifdef Sudden_Underflow
  i = (int) (word0 (d) >> Exp_shift1 & (Exp_mask >> Exp_shift1));
#else
  if ((i = (int) (word0 (d) >> Exp_shift1 & (Exp_mask >> Exp_shift1))) != 0)
    {
#endif
      d2.d = d.d;
      word0 (d2) &= Frac_mask1;
      word0 (d2) |= Exp_11;
#ifdef IBM
      if (j = 11 - hi0bits (word0 (d2) & Frac_mask))
	d2.d /= 1 << j;
#endif

      /* log(x)	~=~ log(1.5) + (x-1.5)/1.5
		 * log10(x)	 =  log(x) / log(10)
		 *		~=~ log(1.5)/log(10) + (x-1.5)/(1.5*log(10))
		 * log10(d) = (i-Bias)*log(2)/log(10) + log10(d2)
		 *
		 * This suggests computing an approximation k to log10(d) by
		 *
		 * k = (i - Bias)*0.301029995663981
		 *	+ ( (d2-1.5)*0.289529654602168 + 0.176091259055681 );
		 *
		 * We want k to be too large rather than too small.
		 * The error in the first-order Taylor series approximation
		 * is in our favor, so we just round up the constant enough
		 * to compensate for any error in the multiplication of
		 * (i - Bias) by 0.301029995663981; since |i - Bias| <= 1077,
		 * and 1077 * 0.30103 * 2^-52 ~=~ 7.2e-14,
		 * adding 1e-13 to the constant term more than suffices.
		 * Hence we adjust the constant term to 0.1760912590558.
		 * (We could get a more accurate k by invoking log10,
		 *  but this is probably not worthwhile.)
		 */

      i -= Bias;
#ifdef IBM
      i <<= 2;
      i += j;
#endif
#ifndef Sudden_Underflow
      denorm = 0;
    }
  else
    {
      /* d is denormalized */

      i = bbits + be + (Bias + (P - 1) - 1);
      x = (i > 32) ? (word0 (d) << (64 - i)) | (word1 (d) >> (i - 32))
       : (word1 (d) << (32 - i));
      d2.d = x;
      word0 (d2) -= 31 * Exp_msk1;	/* adjust exponent */
      i -= (Bias + (P - 1) - 1) + 1;
      denorm = 1;
    }
#endif
  ds = (d2.d - 1.5) * 0.289529654602168 + 0.1760912590558 + i * 0.301029995663981;
  k = (int) ds;
  if (ds < 0. && ds != k)
    k--;			/* want k = floor(ds) */
  k_check = 1;
  if (k >= 0 && k <= Ten_pmax)
    {
      if (d.d < tens[k])
	k--;
      k_check = 0;
    }
  j = bbits - i - 1;
  if (j >= 0)
    {
      b2 = 0;
      s2 = j;
    }
  else
    {
      b2 = -j;
      s2 = 0;
    }
  if (k >= 0)
    {
      b5 = 0;
      s5 = k;
      s2 += k;
    }
  else
    {
      b2 -= k;
      b5 = -k;
      s5 = 0;
    }
  if (mode < 0 || mode > 9)
    mode = 0;
  try_quick = 1;
  if (mode > 5)
    {
      mode -= 4;
      try_quick = 0;
    }
  leftright = 1;
  ilim = ilim1 = -1;
  switch (mode)
    {
    case 0:
    case 1:
      i = 18;
      ndigits = 0;
      break;
    case 2:
      leftright = 0;
      /* no break */
    case 4:
      if (ndigits <= 0)
	ndigits = 1;
      ilim = ilim1 = i = ndigits;
      break;
    case 3:
      leftright = 0;
      /* no break */
    case 5:
      i = ndigits + k + 1;
      ilim = i;
      ilim1 = i - 1;
      if (i <= 0)
	i = 1;
    }
  j = sizeof (__ULong);
  for (ptr->_result_k = 0; sizeof (_Bigint) - sizeof (__ULong) + j <= i;
       j <<= 1)
    ptr->_result_k++;
  ptr->_result = Balloc (ptr, ptr->_result_k);
  s = s0 = (char *) ptr->_result;

  if (ilim >= 0 && ilim <= Quick_max && try_quick)
    {
      /* Try to get by with floating-point arithmetic. */

      i = 0;
      d2.d = d.d;
      k0 = k;
      ilim0 = ilim;
      ieps = 2;			/* conservative */
      if (k > 0)
	{
	  ds = tens[k & 0xf];
	  j = k >> 4;
	  if (j & Bletch)
	    {
	      /* prevent overflows */
	      j &= Bletch - 1;
	      d.d /= bigtens[n_bigtens - 1];
	      ieps++;
	    }
	  for (; j; j >>= 1, i++)
	    if (j & 1)
	      {
		ieps++;
		ds *= bigtens[i];
	      }
	  d.d /= ds;
	}
      else if ((j1 = -k) != 0)
	{
	  d.d *= tens[j1 & 0xf];
	  for (j = j1 >> 4; j; j >>= 1, i++)
	    if (j & 1)
	      {
		ieps++;
		d.d *= bigtens[i];
	      }
	}
      if (k_check && d.d < 1. && ilim > 0)
	{
	  if (ilim1 <= 0)
	    goto fast_failed;
	  ilim = ilim1;
	  k--;
	  d.d *= 10.;
	  ieps++;
	}
      eps.d = ieps * d.d + 7.;
      word0 (eps) -= (P - 1) * Exp_msk1;
      if (ilim == 0)
	{
	  S = mhi = 0;
	  d.d -= 5.;
	  if (d.d > eps.d)
	    goto one_digit;
	  if (d.d < -eps.d)
	    goto no_digits;
	  goto fast_failed;
	}
#ifndef No_leftright
      if (leftright)
	{
	  /* Use Steele & White method of only
	   * generating digits needed.
	   */
	  eps.d = 0.5 / tens[ilim - 1] - eps.d;
	  for (i = 0;;)
	    {
	      L = d.d;
	      d.d -= L;
	      *s++ = '0' + (int) L;
	      if (d.d < eps.d)
		goto ret1;
	      if (1. - d.d < eps.d)
		goto bump_up;
	      if (++i >= ilim)
		break;
	      eps.d *= 10.;
	      d.d *= 10.;
	    }
	}
      else
	{
#endif
	  /* Generate ilim digits, then fix them up. */
	  eps.d *= tens[ilim - 1];
	  for (i = 1;; i++, d.d *= 10.)
	    {
	      L = d.d;
	      d.d -= L;
	      *s++ = '0' + (int) L;
	      if (i == ilim)
		{
		  if (d.d > 0.5 + eps.d)
		    goto bump_up;
		  else if (d.d < 0.5 - eps.d)
		    {
		      while (*--s == '0');
		      s++;
		      goto ret1;
		    }
		  break;
		}
	    }
#ifndef No_leftright
	}
#endif
    fast_failed:
      s = s0;
      d.d = d2.d;
      k = k0;
      ilim = ilim0;
    }

  /* Do we have a "small" integer? */

  if (be >= 0 && k <= Int_max)
    {
      /* Yes. */
      ds = tens[k];
      if (ndigits < 0 && ilim <= 0)
	{
	  S = mhi = 0;
	  if (ilim < 0 || d.d <= 5 * ds)
	    goto no_digits;
	  goto one_digit;
	}
      for (i = 1;; i++)
	{
	  L = d.d / ds;
	  d.d -= L * ds;
#ifdef Check_FLT_ROUNDS
	  /* If FLT_ROUNDS == 2, L will usually be high by 1 */
	  if (d.d < 0)
	    {
	      L--;
	      d.d += ds;
	    }
#endif
	  *s++ = '0' + (int) L;
	  if (i == ilim)
	    {
	      d.d += d.d;
             if ((d.d > ds) || ((d.d == ds) && (L & 1)))
		{
		bump_up:
		  while (*--s == '9')
		    if (s == s0)
		      {
			k++;
			*s = '0';
			break;
		      }
		  ++*s++;
		}
	      break;
	    }
	  if (!(d.d *= 10.))
	    break;
	}
      goto ret1;
    }

  m2 = b2;
  m5 = b5;
  mhi = mlo = 0;
  if (leftright)
    {
      if (mode < 2)
	{
	  i =
#ifndef Sudden_Underflow
	    denorm ? be + (Bias + (P - 1) - 1 + 1) :
#endif
#ifdef IBM
	    1 + 4 * P - 3 - bbits + ((bbits + be - 1) & 3);
#else
	    1 + P - bbits;
#endif
	}
      else
	{
	  j = ilim - 1;
	  if (m5 >= j)
	    m5 -= j;
	  else
	    {
	      s5 += j -= m5;
	      b5 += j;
	      m5 = 0;
	    }
	  if ((i = ilim) < 0)
	    {
	      m2 -= i;
	      i = 0;
	    }
	}
      b2 += i;
      s2 += i;
      mhi = i2b (ptr, 1);
    }
  if (m2 > 0 && s2 > 0)
    {
      i = m2 < s2 ? m2 : s2;
      b2 -= i;
      m2 -= i;
      s2 -= i;
    }
  if (b5 > 0)
    {
      if (leftright)
	{
	  if (m5 > 0)
	    {
	      mhi = pow5mult (ptr, mhi, m5);
	      b1 = mult (ptr, mhi, b);
	      Bfree (ptr, b);
	      b = b1;
	    }
         if ((j = b5 - m5) != 0)
	    b = pow5mult (ptr, b, j);
	}
      else
	b = pow5mult (ptr, b, b5);
    }
  S = i2b (ptr, 1);
  if (s5 > 0)
    S = pow5mult (ptr, S, s5);

  /* Check for special case that d is a normalized power of 2. */

  spec_case = 0;
  if (mode < 2)
    {
      if (!word1 (d) && !(word0 (d) & Bndry_mask)
#ifndef Sudden_Underflow
	  && word0 (d) & Exp_mask
#endif
	)
	{
	  /* The special case */
	  b2 += Log2P;
	  s2 += Log2P;
	  spec_case = 1;
	}
    }

  /* Arrange for convenient computation of quotients:
   * shift left if necessary so divisor has 4 leading 0 bits.
   *
   * Perhaps we should just compute leading 28 bits of S once
   * and for all and pass them and a shift to quorem, so it
   * can do shifts and ors to compute the numerator for q.
   */

#ifdef Pack_32
  if ((i = ((s5 ? 32 - hi0bits (S->_x[S->_wds - 1]) : 1) + s2) & 0x1f) != 0)
    i = 32 - i;
#else
  if ((i = ((s5 ? 32 - hi0bits (S->_x[S->_wds - 1]) : 1) + s2) & 0xf) != 0)
    i = 16 - i;
#endif
  if (i > 4)
    {
      i -= 4;
      b2 += i;
      m2 += i;
      s2 += i;
    }
  else if (i < 4)
    {
      i += 28;
      b2 += i;
      m2 += i;
      s2 += i;
    }
  if (b2 > 0)
    b = lshift (ptr, b, b2);
  if (s2 > 0)
    S = lshift (ptr, S, s2);
  if (k_check)
    {
      if (cmp (b, S) < 0)
	{
	  k--;
	  b = multadd (ptr, b, 10, 0);	/* we botched the k estimate */
	  if (leftright)
	    mhi = multadd (ptr, mhi, 10, 0);
	  ilim = ilim1;
	}
    }
  if (ilim <= 0 && mode > 2)
    {
      if (ilim < 0 || cmp (b, S = multadd (ptr, S, 5, 0)) <= 0)
	{
	  /* no digits, fcvt style */
	no_digits:
	  k = -1 - ndigits;
	  goto ret;
	}
    one_digit:
      *s++ = '1';
      k++;
      goto ret;
    }
  if (leftright)
    {
      if (m2 > 0)
	mhi = lshift (ptr, mhi, m2);

      /* Compute mlo -- check for special case
       * that d is a normalized power of 2.
       */

      mlo = mhi;
      if (spec_case)
	{
	  mhi = Balloc (ptr, mhi->_k);
	  Bcopy (mhi, mlo);
	  mhi = lshift (ptr, mhi, Log2P);
	}

      for (i = 1;; i++)
	{
	  dig = quorem (b, S) + '0';
	  /* Do we yet have the shortest decimal string
	   * that will round to d?
	   */
	  j = cmp (b, mlo);
	  delta = diff (ptr, S, mhi);
	  j1 = delta->_sign ? 1 : cmp (b, delta);
	  Bfree (ptr, delta);
#ifndef ROUND_BIASED
	  if (j1 == 0 && !mode && !(word1 (d) & 1))
	    {
	      if (dig == '9')
		goto round_9_up;
	      if (j > 0)
		dig++;
	      *s++ = dig;
	      goto ret;
	    }
#endif
         if ((j < 0) || ((j == 0) && !mode
#ifndef ROUND_BIASED
	      && !(word1 (d) & 1)
#endif
           ))
	    {
	      if (j1 > 0)
		{
		  b = lshift (ptr, b, 1);
		  j1 = cmp (b, S);
                 if (((j1 > 0) || ((j1 == 0) && (dig & 1)))
		      && dig++ == '9')
		    goto round_9_up;
		}
	      *s++ = dig;
	      goto ret;
	    }
	  if (j1 > 0)
	    {
	      if (dig == '9')
		{		/* possible if i == 1 */
		round_9_up:
		  *s++ = '9';
		  goto roundoff;
		}
	      *s++ = dig + 1;
	      goto ret;
	    }
	  *s++ = dig;
	  if (i == ilim)
	    break;
	  b = multadd (ptr, b, 10, 0);
	  if (mlo == mhi)
	    mlo = mhi = multadd (ptr, mhi, 10, 0);
	  else
	    {
	      mlo = multadd (ptr, mlo, 10, 0);
	      mhi = multadd (ptr, mhi, 10, 0);
	    }
	}
    }
  else
    for (i = 1;; i++)
      {
	*s++ = dig = quorem (b, S) + '0';
	if (i >= ilim)
	  break;
	b = multadd (ptr, b, 10, 0);
      }

  /* Round off last digit */

  b = lshift (ptr, b, 1);
  j = cmp (b, S);
  if ((j > 0) || ((j == 0) && (dig & 1)))
    {
    roundoff:
      while (*--s == '9')
	if (s == s0)
	  {
	    k++;
	    *s++ = '1';
	    goto ret;
	  }
      ++*s++;
    }
  else
    {
      while (*--s == '0');
      s++;
    }
ret:
  Bfree (ptr, S);
  if (mhi)
    {
      if (mlo && mlo != mhi)
	Bfree (ptr, mlo);
      Bfree (ptr, mhi);
    }
ret1:
  Bfree (ptr, b);
  *s = 0;
  *decpt = k + 1;
  if (rve)
    *rve = s;
  return s0;
}
