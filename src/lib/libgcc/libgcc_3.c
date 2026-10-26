/*
 * lib/libgcc: 13 files, 00120BC0-00121760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00120BC0 */
__asm__(".set nomove\n"
        "dpsub = SoftFloat_DoubleSub\n");
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
extern double func_0011EDD0(double x, double y);
extern double func_0011FBF8(double x, double y, int iy);
extern int func_0011CA20(double x, double *y);

double Math_CosDouble(double x)
{
	double y[2],z=0.0;
	int n,ix;

	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return func_0011EDD0(x,z);
	else if (ix>=0x7ff00000) return x-x;
	else {
	    n = func_0011CA20(x,y);
	    switch(n&3) {
		case 0: return  func_0011EDD0(y[0],y[1]);
		case 1: return -func_0011FBF8(y[0],y[1],1);
		case 2: return -func_0011EDD0(y[0],y[1]);
		default:
		        return  func_0011FBF8(y[0],y[1],1);
	    }
	}
}
/* merge_units: end func_00120BC0 */

/* merge_units: begin func_00120CE8 */
double Libc_Fabs(double x)
{
    unsigned int high;
    do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
    do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (high & 0x7fffffff); (x) = sh_u.value; } while (0);
    {
        /* asm label only (no instruction): stops delay-slot filling of the return move, as retail line notes did */
        register double r __asm__("$2") = x;
        __asm__ __volatile__("1:" : "+r"(r));
        return r;
    }
}
/* merge_units: end func_00120CE8 */

/* merge_units: begin func_00120D20 */
__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n");
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)
extern const double D_00499BA8;
#define huge D_00499BA8

double Libc_Floor(double x)
{
	int i0,i1,j0;
	unsigned int i,j;
	EXTRACT_WORDS(i0,i1,x);
	j0 = ((i0>>20)&0x7ff)-0x3ff;
	if(j0<20) {
	    if(j0<0) {
		if(x+huge>0.0) {
		    if(i0>=0) {i0=i1=0;}
		    else if(((i0&0x7fffffff)|i1)!=0)
			{ i0=0xbff00000;i1=0;}
		}
	    } else {
		i = (0x000fffff)>>j0;
		if(((i0&i)|i1)==0) return x;
		if(x+huge>0.0) {
		    if(i0<0) i0 += (0x00100000)>>j0;
		    i0 &= (~i); i1=0;
		}
	    }
	} else if (j0>51) {
	    if(j0==0x400) return x+x;
	    else return x;
	} else {
	    i = ((unsigned int)(0xffffffff))>>(j0-20);
	    if((i1&i)==0) return x;
	    if(x+huge>0.0) {
		if(i0<0) {
		    if(j0==20) i0+=1;
		    else {
			j = i1+(1<<(52-j0));
			if(j<i1) i0 +=1 ;
			i1=j;
		    }
		}
		i1 &= (~i);
	    }
	}
	INSERT_WORDS(x,i0,i1);
	return x;
}
/* merge_units: end func_00120D20 */

/* merge_units: begin func_00120F38 */
#include "types.h"
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
int func_00120F38(double x)
{
	int hx,lx;
	EXTRACT_WORDS(hx,lx,x);
	hx &= 0x7fffffff;
	hx |= (unsigned int)(lx|(-lx))>>31;
	hx = 0x7ff00000 - hx;
	return 1 - (int)((unsigned int)(hx|(-hx))>>31);
}
/* merge_units: end func_00120F38 */

/* merge_units: begin func_00120F80 */
int Double_IsNaN(double x)
{
    int hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (unsigned int)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (int)(((unsigned int)(hx)) >> 31);
}
/* merge_units: end func_00120F80 */

/* merge_units: begin func_00120FC0 */
__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpmul = SoftFloat_DoubleMultiply\n");extern const double D_00499BD8;
extern const double D_00499BE0;
#define tiny D_00499BD8
#undef huge /* merge_units */
#define huge D_00499BE0
#define two54 1.80143985094819840000e+16
#define twom54 5.55111512312578270212e-17
extern double func_00120B78(double, double);

double scalbn(double x, int n)
{
	int k,hx,lx;
	EXTRACT_WORDS(hx,lx,x);
        k = (hx&0x7ff00000)>>20;
        if (k==0) {
            if ((lx|(hx&0x7fffffff))==0) return x;
	    x *= two54;
	    GET_HIGH_WORD(hx,x);
	    k = ((hx&0x7ff00000)>>20) - 54;
            if (n< -50000) return x*tiny;
	    }
        if (k==0x7ff) return x+x;
        k = k+n;
        if (k >  0x7fe) return func_00120B78(huge,x)*huge;
        if (k > 0)
	    {SET_HIGH_WORD(x,(hx&0x800fffff)|(k<<20)); return x;}
        if (k <= -54) {
            if (n > 50000)
		return func_00120B78(huge,x)*huge;
	    else return func_00120B78(tiny,x)*tiny;
	}
        k += 54;
	SET_HIGH_WORD(x,(hx&0x800fffff)|(k<<20));
        return x*twom54;
}
/* merge_units: end func_00120FC0 */

/* merge_units: begin func_001211A8 */
__asm__(".set nomove\n"
        "dpsub = SoftFloat_DoubleSub\n");

double Math_SinDouble(double x)
{
	double y[2],z=0.0;
	int n,ix;

	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return func_0011FBF8(x,z,0);
	else if (ix>=0x7ff00000) return x-x;
	else {
	    n = func_0011CA20(x,y);
	    switch(n&3) {
		case 0: return  func_0011FBF8(y[0],y[1],1);
		case 1: return  func_0011EDD0(y[0],y[1]);
		case 2: return -func_0011FBF8(y[0],y[1],1);
		default:
			return -func_0011EDD0(y[0],y[1]);
	    }
	}
}
/* merge_units: end func_001211A8 */

/* merge_units: begin func_001212E0 */
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
static const float atanhi[] = {
  4.6364760399e-01, /* atan(0.5)hi */
  7.8539812565e-01, /* atan(1.0)hi */
  9.8279368877e-01, /* atan(1.5)hi */
  1.5707962513e+00, /* atan(inf)hi */
};
static const float atanlo[] = {
  5.0121582440e-09, /* atan(0.5)lo */
  3.7748947079e-08, /* atan(1.0)lo */
  3.4473217170e-08, /* atan(1.5)lo */
  7.5497894159e-08, /* atan(inf)lo */
};
static const float aT[] = {
  3.3333334327e-01,
 -2.0000000298e-01,
  1.4285714924e-01,
 -1.1111110449e-01,
  9.0908870101e-02,
 -7.6918758452e-02,
  6.6610731184e-02,
 -5.8335702866e-02,
  4.9768779427e-02,
 -3.6531571299e-02,
  1.6285819933e-02,
};
extern float Math_Fabsf(float x);
float Math_Atan(float x)
{
	const float one   = 1.0, huge   = 1.0e30;
	float w,s1,s2,z;
	int ix,hx,id;

	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix>=0x50800000) {
	    if(hx>0) return  atanhi[3]+atanlo[3];
	    else     return -atanhi[3]-atanlo[3];
	} if (ix < 0x3ee00000) {
	    if (ix < 0x31000000) {
		if(huge+x>one) return x;
	    }
	    id = -1;
	} else {
	x = Math_Fabsf(x);
	if (ix < 0x3f980000) {
	    if (ix < 0x3f300000) {
		id = 0; x = ((float)2.0*x-one)/((float)2.0+x);
	    } else {
		id = 1; x  = (x-one)/(x+one);
	    }
	} else {
	    if (ix < 0x401c0000) {
		id = 2; x  = (x-(float)1.5)/(one+(float)1.5*x);
	    } else {
		id = 3; x  = -(float)1.0/x;
	    }
	}}
	z = x*x;
	w = z*z;
	s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
	s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
	if (id<0) return x - x*(s1+s2);
	else {
	    z = atanhi[id] - ((x*(s1+s2) - atanlo[id]) - x);
	    return (hx<0)? -z:z;
	}
}
/* merge_units: end func_001212E0 */

/* merge_units: begin func_00121570 */
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#undef huge /* merge_units */
#define huge 1.0e30f
float Libc_Ceilf(float x)
{
    int i0, j0;
    unsigned int i, ix;
    GET_FLOAT_WORD(i0, x);
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge + x > (float)0.0) {
                if (i0 < 0) { i0 = 0x80000000; }
                else if (!FLT_UWORD_IS_ZERO(ix)) { i0 = 0x3f800000; }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge + x > (float)0.0) {
                if (i0 > 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
/* merge_units: end func_00121570 */

/* merge_units: begin func_00121648 */
float func_00121648(float x, float y)
{
	unsigned int ix,iy;
	GET_FLOAT_WORD(ix,x);
	GET_FLOAT_WORD(iy,y);
	SET_FLOAT_WORD(x,(ix&0x7fffffff)|(iy&0x80000000));
	return x;
}
/* merge_units: end func_00121648 */

/* merge_units: begin libgcc_121688 */
extern float Math_CosKernel(float x, float y);
extern float Math_SinKernel(float x, float y, int iy);
extern int Math_RemPio2(float x, float* y);
float Math_Cos(float x) {
    float y[2], z = 0.0f;
    int n, ix;
    do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) return Math_CosKernel(x, z);
    else if (!1) return x - x;
    else {
        n = Math_RemPio2(x, y);
        switch (n & 3) {
        case 0: return Math_CosKernel(y[0], y[1]);
        case 1: return -Math_SinKernel(y[0], y[1], 1);
        case 2: return -Math_CosKernel(y[0], y[1]);
        default: return Math_SinKernel(y[0], y[1], 1);
        }
    }
}
/* merge_units: end libgcc_121688 */

/* merge_units: begin func_00121760 */
float Math_Fabsf(float x)
{
	unsigned int ix;
	GET_FLOAT_WORD(ix,x);
	SET_FLOAT_WORD(x,ix&0x7fffffff);
	return x;
}
/* merge_units: end func_00121760 */

/* merge_units: begin func_00121788 */
float Math_Floorf(float x)
{
    int i0, j0;
    unsigned int i, ix;
    GET_FLOAT_WORD(i0, x);
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge + x > (float)0.0) {
                if (i0 >= 0) { i0 = 0; }
                else if (!FLT_UWORD_IS_ZERO(ix)) { i0 = 0xbf800000; }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge + x > (float)0.0) {
                if (i0 < 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
/* merge_units: end func_00121788 */
