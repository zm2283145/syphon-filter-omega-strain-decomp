#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
float Math_CosKernel(float x, float y)
{
	const float
	one =  1.0000000000e+00,
	C1  =  4.1666667908e-02,
	C2  = -1.3888889225e-03,
	C3  =  2.4801587642e-05,
	C4  = -2.7557314297e-07,
	C5  =  2.0875723372e-09,
	C6  = -1.1359647598e-11;
	float a,hz,z,r,qx;
	int ix;
	GET_FLOAT_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix<0x32000000) {
	    if(((int)x)==0) return one;
	}
	z  = x*x;
	r  = z*(C1+z*(C2+z*(C3+z*(C4+z*(C5+z*C6)))));
	if(ix < 0x3e99999a)
	    return one - ((float)0.5*z - (z*r - x*y));
	else {
	    if(ix > 0x3f480000) {
		qx = (float)0.28125;
	    } else {
	        SET_FLOAT_WORD(qx,ix-0x01000000);
	    }
	    hz = (float)0.5*z-qx;
	    a  = one-qx;
	    return a - (hz - (z*r-x*y));
	}
}
