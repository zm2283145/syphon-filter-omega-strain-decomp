#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern float func_001212E0(float x);
extern float func_00121760(float x);
float func_0011D7A0(float y, float x)
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
	if(hx==0x3f800000) return func_001212E0(y);
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
	else z=func_001212E0(func_00121760(y/x));
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
