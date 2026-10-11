#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern const float D_004994E0[];
extern const float D_004994F0[];
extern const float D_004994F8[];
extern const float D_00499518;
#define halF D_004994E0
#define ln2HI D_004994F0
#define ln2LO D_004994F8
float func_0011D980(float x)
{
	const float
	one	= 1.0,
	huge	= 1.0e+30,
	twom100 = 7.8886090522e-31,
	invln2 =  1.4426950216e+00,
	P1   =  1.6666667163e-01,
	P2   = -2.7777778450e-03,
	P3   =  6.6137559770e-05,
	P4   = -1.6533901999e-06,
	P5   =  4.1381369442e-08;
	float y,hi,lo,c,t;
	int k,xsb,sx;
	unsigned int hx;

	GET_FLOAT_WORD(sx,x);
	xsb = (sx>>31)&1;
	hx = sx & 0x7fffffff;

	if(sx > 0x42b2d4fc)
	    return D_00499518;
	if(sx < 0 && hx > 0x42aeac50)
	    return twom100*twom100;

	if(hx > 0x3eb17218) {
	    if(hx < 0x3F851592) {
		hi = x-ln2HI[xsb]; lo=ln2LO[xsb]; k = 1-xsb-xsb;
	    } else {
		k  = invln2*x+halF[xsb];
		t  = k;
		hi = x - t*ln2HI[0];
		lo = t*ln2LO[0];
	    }
	    x  = hi - lo;
	}
	else if(hx < 0x31800000)  {
	    if(huge+x>one) return one+x;
	}
	else k = 0;

	t  = x*x;
	c  = x - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	if(k==0) 	return one-((x*c)/(c-(float)2.0)-x);
	else 		y = one-((lo-(x*c)/((float)2.0-c))-hi);
	if(k >= -125) {
	    unsigned int hy;
	    GET_FLOAT_WORD(hy,y);
	    SET_FLOAT_WORD(y,hy+(k<<23));
	    return y;
	} else {
	    unsigned int hy;
	    GET_FLOAT_WORD(hy,y);
	    SET_FLOAT_WORD(y,hy+((k+100)<<23));
	    return y*twom100;
	}
}
