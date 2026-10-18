/*
 * lib/libgcc: 10 files, 0011C750-0011D7A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011C750 */
#include "types.h"
typedef unsigned long fractype;
typedef unsigned int halffractype;
typedef double DFtype;
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union { fractype ll; halffractype l[2]; } fraction;
} fp_number_type;
typedef union { DFtype value; fractype value_raw; } FLO_union_type;
extern void func_0011BE88(FLO_union_type* src, fp_number_type* dst);
extern DFtype func_0011BDB0(fp_number_type* src);
extern int SoftFloat_DoubleCompare(fp_number_type* a, fp_number_type* b);
int SoftFloat_UnpackAndCompare(DFtype arg_a, DFtype arg_b)
{
    fp_number_type a;
    fp_number_type b;
    FLO_union_type au, bu;
    au.value = arg_a;
    bu.value = arg_b;
    func_0011BE88(&au, &a);
    func_0011BE88(&bu, &b);
    return SoftFloat_DoubleCompare(&a, &b);
}
/* merge_units: end func_0011C750 */

/* merge_units: begin func_0011C7A0 */
DFtype func_0011C7A0(int arg_a)
{
    fp_number_type in;
    in.class = CLASS_NUMBER;
    in.sign = arg_a < 0;
    if (!arg_a) {
        in.class = CLASS_ZERO;
    } else {
        in.normal_exp = 60;
        if (in.sign) {
            if (arg_a == (-0x7fffffff - 1)) {
                return (DFtype)(-0x7fffffff - 1);
            }
            in.fraction.ll = (-arg_a);
        } else
            in.fraction.ll = arg_a;
        while (in.fraction.ll < ((fractype)1 << 60)) {
            in.fraction.ll <<= 1;
            in.normal_exp -= 1;
        }
    }
    return func_0011BDB0(&in);
}
/* merge_units: end func_0011C7A0 */

/* merge_units: begin func_0011C858 */
static __inline__ int isnan_(fp_number_type* x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
static __inline__ int isinf_(fp_number_type* x) { return x->class == CLASS_INFINITY; }
static __inline__ int iszero_(fp_number_type* x) { return x->class == CLASS_ZERO; }
int func_0011C858(DFtype arg_a)
{
    fp_number_type a;
    int tmp;
    FLO_union_type au;
    au.value = arg_a;
    func_0011BE88(&au, &a);
    if (iszero_(&a)) return 0;
    if (isnan_(&a)) return 0;
    if (isinf_(&a)) return a.sign ? (-0x7fffffff) - 1 : 0x7fffffff;
    if (a.normal_exp < 0) return 0;
    if (a.normal_exp > 30) return a.sign ? (-0x7fffffff) - 1 : 0x7fffffff;
    tmp = a.fraction.ll >> (60 - a.normal_exp);
    return a.sign ? (-tmp) : (tmp);
}
/* merge_units: end func_0011C858 */

/* merge_units: begin func_0011C8F8 */
DFtype func_0011C8F8(fp_class_type class, unsigned int sign, int exp, fractype frac)
{
    fp_number_type in;
    in.class = class;
    in.sign = sign;
    in.normal_exp = exp;
    in.fraction.ll = frac;
    return func_0011BDB0(&in);
}
/* merge_units: end func_0011C8F8 */

/* merge_units: begin func_0011C928 */
extern float func_0011BD40(fp_class_type class, unsigned int sign, int exp, unsigned int frac);
float SoftFloat_DoubleToFloat(DFtype arg_a)
{
    fp_number_type in;
    unsigned int sffrac;
    FLO_union_type au;
    au.value = arg_a;
    func_0011BE88(&au, &in);
    sffrac = in.fraction.ll >> 30;
    if ((in.fraction.ll & (((unsigned int)1 << 30) - 1)) != 0)
        sffrac |= 1;
    return func_0011BD40(in.class, in.sign, in.normal_exp, sffrac);
}
/* merge_units: end func_0011C928 */

/* merge_units: begin func_0011C980 */
unsigned int func_0011C980(DFtype arg_a)
{
    fp_number_type a;
    FLO_union_type au;
    au.value = arg_a;
    func_0011BE88(&au, &a);
    if (iszero_(&a)) return 0;
    if (isnan_(&a)) return 0;
    if (a.sign) return 0;
    if (isinf_(&a)) return 0xffffffff;
    if (a.normal_exp < 0) return 0;
    if (a.normal_exp > 31) return 0xffffffff;
    else if (a.normal_exp > 60)
        return a.fraction.ll << (a.normal_exp - 60);
    else
        return a.fraction.ll >> (60 - a.normal_exp);
}
/* merge_units: end func_0011C980 */

/* merge_units: begin func_0011CA20 */
/* __ieee754_rem_pio2 (newlib e_rem_pio2.c); retail newlib was built with -g. */
__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = func_0011C200\n"
        "dpmul = SoftFloat_DoubleMultiply\n"
        "litodp = func_0011C7A0\n"
        "dptoli = func_0011C858\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n");
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef union { double value; struct { __uint32_t lsw; __uint32_t msw; } parts; } ieee_double_shape_type;
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define GET_LOW_WORD(i,d) do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)
#define SET_LOW_WORD(d,v) do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)

extern double func_00120CE8(double);
extern int func_0011F0A8(double*, double*, int, int, int, const __int32_t*);

static const __int32_t two_over_pi[] = {
0xA2F983, 0x6E4E44, 0x1529FC, 0x2757D1, 0xF534DD, 0xC0DB62,
0x95993C, 0x439041, 0xFE5163, 0xABDEBB, 0xC561B7, 0x246E3A,
0x424DD2, 0xE00649, 0x2EEA09, 0xD1921C, 0xFE1DEB, 0x1CB129,
0xA73EE8, 0x8235F5, 0x2EBB44, 0x84E99C, 0x7026B4, 0x5F7E41,
0x3991D6, 0x398353, 0x39F49C, 0x845F8B, 0xBDF928, 0x3B1FF8,
0x97FFDE, 0x05980F, 0xEF2F11, 0x8B5A0A, 0x6D1F6D, 0x367ECF,
0x27CB09, 0xB74F46, 0x3F669E, 0x5FEA2D, 0x7527BA, 0xC7EBE5,
0xF17B3D, 0x0739F7, 0x8A5292, 0xEA6BFB, 0x5FB11F, 0x8D5D08,
0x560330, 0x46FC7B, 0x6BABF0, 0xCFBC20, 0x9AF436, 0x1DA9E3,
0x91615E, 0xE61B08, 0x659985, 0x5F14A0, 0x68408D, 0xFFD880,
0x4D7327, 0x310606, 0x1556CA, 0x73A8C9, 0x60E27B, 0xC08C6B,
};

static const __int32_t npio2_hw[] = {
0x3FF921FB, 0x400921FB, 0x4012D97C, 0x401921FB, 0x401F6A7A, 0x4022D97C,
0x4025FDBB, 0x402921FB, 0x402C463A, 0x402F6A7A, 0x4031475C, 0x4032D97C,
0x40346B9C, 0x4035FDBB, 0x40378FDB, 0x403921FB, 0x403AB41B, 0x403C463A,
0x403DD85A, 0x403F6A7A, 0x40407E4C, 0x4041475C, 0x4042106C, 0x4042D97C,
0x4043A28C, 0x40446B9C, 0x404534AC, 0x4045FDBB, 0x4046C6CB, 0x40478FDB,
0x404858EB, 0x404921FB,
};

static const double
zero =  0.00000000000000000000e+00,
half =  5.00000000000000000000e-01,
two24 =  1.67772160000000000000e+07,
invpio2 =  6.36619772367581382433e-01,
pio2_1  =  1.57079632673412561417e+00,
pio2_1t =  6.07710050650619224932e-11,
pio2_2  =  6.07710050630396597660e-11,
pio2_2t =  2.02226624879595063154e-21,
pio2_3  =  2.02226624871116645580e-21,
pio2_3t =  8.47842766036889956997e-32;

__int32_t func_0011CA20(double x, double *y)
{
	double z,w,t,r,fn;
	double tx[3];
	__int32_t i,j,n,ix,hx;
	int e0,nx;
	__uint32_t low;

	GET_HIGH_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix<=0x3fe921fb)
	    {y[0] = x; y[1] = 0; return 0;}
	if(ix<0x4002d97c) {
	    if(hx>0) {
		z = x - pio2_1;
		if(ix!=0x3ff921fb) {
		    y[0] = z - pio2_1t;
		    y[1] = (z-y[0])-pio2_1t;
		} else {
		    z -= pio2_2;
		    y[0] = z - pio2_2t;
		    y[1] = (z-y[0])-pio2_2t;
		}
		return 1;
	    } else {
		z = x + pio2_1;
		if(ix!=0x3ff921fb) {
		    y[0] = z + pio2_1t;
		    y[1] = (z-y[0])+pio2_1t;
		} else {
		    z += pio2_2;
		    y[0] = z + pio2_2t;
		    y[1] = (z-y[0])+pio2_2t;
		}
		return -1;
	    }
	}
	if(ix<=0x413921fb) {
	    t  = func_00120CE8(x);
	    n  = (__int32_t) (t*invpio2+half);
	    fn = (double)n;
	    r  = t-fn*pio2_1;
	    w  = fn*pio2_1t;
	    if(n<32&&ix!=npio2_hw[n-1]) {
		y[0] = r-w;
	    } else {
	        __uint32_t high;
	        j  = ix>>20;
	        y[0] = r-w;
		GET_HIGH_WORD(high,y[0]);
	        i = j-((high>>20)&0x7ff);
	        if(i>16) {
		    t  = r;
		    w  = fn*pio2_2;
		    r  = t-w;
		    w  = fn*pio2_2t-((t-r)-w);
		    y[0] = r-w;
		    GET_HIGH_WORD(high,y[0]);
		    i = j-((high>>20)&0x7ff);
		    if(i>49)  {
		    	t  = r;
		    	w  = fn*pio2_3;
		    	r  = t-w;
		    	w  = fn*pio2_3t-((t-r)-w);
		    	y[0] = r-w;
		    }
		}
	    }
	    y[1] = (r-y[0])-w;
	    if(hx<0) 	{y[0] = -y[0]; y[1] = -y[1]; return -n;}
	    else	 return n;
	}
	if(ix>=0x7ff00000) {
	    y[0]=y[1]=x-x; return 0;
	}
	GET_LOW_WORD(low,x);
	SET_LOW_WORD(z,low);
	e0 	= (int)((ix>>20)-1046);
	SET_HIGH_WORD(z, ix - ((__int32_t)(e0<<20)));
	for(i=0;i<2;i++) {
		tx[i] = (double)((__int32_t)(z));
		z     = (z-tx[i])*two24;
	}
	tx[2] = z;
	nx = 3;
	while(tx[nx-1]==zero) nx--;
	n  =  func_0011F0A8(tx,y,e0,nx,2,two_over_pi);
	if(hx<0) {y[0] = -y[0]; y[1] = -y[1]; return -n;}
	return n;
}
/* merge_units: end func_0011CA20 */

/* merge_units: begin func_0011CFD8 */
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern float Math_Sqrtf(float x);
float Math_AcosKernel(float x)
{
	const float
	one =  1.0000000000e+00,
	pi =  3.1415925026e+00,
	pio2_hi =  1.5707962513e+00,
	pio2_lo =  7.5497894159e-08,
	pS0 =  1.6666667163e-01,
	pS1 = -3.2556581497e-01,
	pS2 =  2.0121252537e-01,
	pS3 = -4.0055535734e-02,
	pS4 =  7.9153501429e-04,
	pS5 =  3.4793309169e-05,
	qS1 = -2.4033949375e+00,
	qS2 =  2.0209457874e+00,
	qS3 = -6.8828397989e-01,
	qS4 =  7.7038154006e-02;
	float z,p,q,r,w,s,c,df;
	int hx,ix;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix==0x3f800000) {
	    if(hx>0) return 0.0;
	    else return pi+(float)2.0*pio2_lo;
	} else if(ix>0x3f800000) {
	    return (x-x)/(x-x);
	}
	if(ix<0x3f000000) {
	    if(ix<=0x23000000) return pio2_hi+pio2_lo;
	    z = x*x;
	    p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	    q = one+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	    r = p/q;
	    return pio2_hi - (x - (pio2_lo-x*r));
	} else  if (hx<0) {
	    z = (one+x)*(float)0.5;
	    p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	    q = one+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	    s = Math_Sqrtf(z);
	    r = p/q;
	    w = r*s-pio2_lo;
	    return pi - (float)2.0*(s+w);
	} else {
	    int idf;
	    z = (one-x)*(float)0.5;
	    s = Math_Sqrtf(z);
	    df = s;
	    GET_FLOAT_WORD(idf,df);
	    SET_FLOAT_WORD(df,idf&0xfffff000);
	    c  = (z-df*df)/(s+df);
	    p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	    q = one+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	    r = p/q;
	    w = r*s+c;
	    return (float)2.0*(df+w);
	}
}
/* merge_units: end func_0011CFD8 */

/* merge_units: begin func_0011D400 */
extern float Math_Fabsf(float x);
float Math_AsinfImpl(float x)
{
	const float
	one =  1.0000000000e+00,
	huge =  1.000e+30,
	pio2_hi =  1.5707962513e+00,
	pio2_lo =  7.5497894159e-08,
	pio4_hi =  7.8539818525e-01,
	pS0 =  1.6666667163e-01,
	pS1 = -3.2556581497e-01,
	pS2 =  2.0121252537e-01,
	pS3 = -4.0055535734e-02,
	pS4 =  7.9153501429e-04,
	pS5 =  3.4793309169e-05,
	qS1 = -2.4033949375e+00,
	qS2 =  2.0209457874e+00,
	qS3 = -6.8828397989e-01,
	qS4 =  7.7038154006e-02;
	float t,w,p,q,c,r,s;
	int hx,ix;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix==0x3f800000) {
	    return x*pio2_hi+x*pio2_lo;
	} else if(ix> 0x3f800000) {
	    return (x-x)/(x-x);
	} else if (ix<0x3f000000) {
	    if(ix<0x32000000) {
		if(huge+x>one) return x;
	    } else {
		t = x*x;
		p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
		q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
		w = p/q;
		return x+x*w;
	    }
	}
	w = one-Math_Fabsf(x);
	t = w*(float)0.5;
	p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
	q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
	s = Math_Sqrtf(t);
	if(ix>=0x3F79999A) {
	    w = p/q;
	    t = pio2_hi-((float)2.0*(s+s*w)-pio2_lo);
	} else {
	    int iw;
	    w  = s;
	    GET_FLOAT_WORD(iw,w);
	    SET_FLOAT_WORD(w,iw&0xfffff000);
	    c  = (t-w*w)/(s+w);
	    r  = p/q;
	    p  = (float)2.0*s*r-(pio2_lo-(float)2.0*c);
	    q  = pio4_hi-(float)2.0*w;
	    t  = pio4_hi-(p-q);
	}
	if(hx>0) return t; else return -t;
}
/* merge_units: end func_0011D400 */

/* merge_units: begin func_0011D7A0 */
extern float Math_Atan(float x);
float Math_Atan2Kernel(float y, float x)
{
	const float
	tiny  = 1.0e-30,
	pi_o_2  = 1.5707963705e+00,
	pi      = 3.1415925026e+00,
	pi_lo   = 1.5099578832e-07;
	float z;
	int k,m,hx,hy,ix,iy;

	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	GET_FLOAT_WORD(hy,y);
	iy = hy&0x7fffffff;
	if(hx==0x3f800000) return Math_Atan(y);
	m = ((hy>>31)&1)|((hx>>30)&2);

	if(iy < 0x00800000L) {
	    switch(m) {
		case 0:
		case 1: return y;
		case 2: return  pi+tiny;
		case 3: return -pi-tiny;
	    }
	}
	if(ix < 0x00800000L) return (hy<0)?  -pi_o_2-tiny: pi_o_2+tiny;

	k = (iy-ix)>>23;
	if(k > 60) z=pi_o_2+(float)0.5*pi_lo;
	else if(hx<0&&k<-60) z=0.0;
	else z=Math_Atan(Math_Fabsf(y/x));
	switch (m) {
	    case 0: return       z  ;
	    case 1: {
	    	      unsigned int zh;
		      GET_FLOAT_WORD(zh,z);
		      SET_FLOAT_WORD(z,zh ^ 0x80000000);
		    }
		    return       z  ;
	    case 2: return  pi-(z-pi_lo);
	    default:
	    	    return  (z-pi_lo)-pi;
	}
}
/* merge_units: end func_0011D7A0 */
