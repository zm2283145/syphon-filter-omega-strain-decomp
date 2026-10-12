#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern float func_0011DDA8(float x);
static const float
two25      =  3.3554432000e+07,
ivln10     =  4.3429449201e-01,
log10_2hi  =  3.0102920532e-01,
log10_2lo  =  7.9034151668e-07;
static const float zero = 0.0;
float func_0011E088(float x)
{
	float y,z;
	int i,k,hx;
	GET_FLOAT_WORD(hx,x);
	k=0;
	if ((hx&0x7fffffff) < 0x00800000L)
	    return -two25/zero;
	if (hx<0) return (x-x)/zero;
	k += (hx>>23)-127;
	i  = ((unsigned int)k&0x80000000)>>31;
	hx = (hx&0x007fffff)|((0x7f-i)<<23);
	y  = (float)(k+i);
	SET_FLOAT_WORD(x,hx);
	z  = y*log10_2lo + ivln10*func_0011DDA8(x);
	return  z+y*log10_2hi;
}
