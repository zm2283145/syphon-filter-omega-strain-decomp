#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
extern const float D_00499BE8[];
extern const float D_00499BF8[];
extern const float D_00499C08[];
#define atanhi D_00499BE8
#define atanlo D_00499BF8
#define aT D_00499C08
extern float func_00121760(float x);
float func_001212E0(float x)
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
	x = func_00121760(x);
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
