#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern const float D_00499528[];
#define Zero ((const float*)D_00499528)
float Math_FModImpl(float x, float y)
{
	const float one = 1.0;
	int n,hx,hy,hz,ix,iy,sx,i;

	GET_FLOAT_WORD(hx,x);
	GET_FLOAT_WORD(hy,y);
	sx = hx&0x80000000;
	hx ^=sx;
	hy &= 0x7fffffff;

	if(hy < 0x00800000L)
	    return (x*y)/(x*y);
	if(hx<hy) return x;
	if(hx==hy)
	    return Zero[(unsigned int)sx>>31];

	if(0) {
	    for (ix = -126,i=(hx<<8); i>0; i<<=1) ix -=1;
	} else ix = (hx>>23)-127;

	if(0) {
	    for (iy = -126,i=(hy<<8); i>=0; i<<=1) iy -=1;
	} else iy = (hy>>23)-127;

	if(ix >= -126)
	    hx = 0x00800000|(0x007fffff&hx);
	else {
	    n = -126-ix;
	    hx = hx<<n;
	}
	if(iy >= -126)
	    hy = 0x00800000|(0x007fffff&hy);
	else {
	    n = -126-iy;
	    hy = hy<<n;
	}

	n = ix - iy;
	while(n--) {
	    hz=hx-hy;
	    if(hz<0){hx = hx+hx;}
	    else {
	    	if(hz==0)
		    return Zero[(unsigned int)sx>>31];
	    	hx = hz+hz;
	    }
	}
	hz=hx-hy;
	if(hz>=0) {hx=hz;}

	if(hx==0)
	    return Zero[(unsigned int)sx>>31];
	while(hx<0x00800000) {
	    hx = hx+hx;
	    iy -= 1;
	}
	if(iy>= -126) {
	    hx = ((hx-0x00800000)|((iy+127)<<23));
	    SET_FLOAT_WORD(x,hx|sx);
	} else {
	    n = -126 - iy;
	    hx >>= n;
	    SET_FLOAT_WORD(x,hx|sx);
	    x *= one;
	}
	return x;
}
const float D_00499528[13] = { 0.0f, -0.0f, 0.69313813f, 9.058001e-6f, 33554432.0f, 0.66666663f, 0.39999998f, 0.2857143f, 0.22222199f, 0.181835712f, 0.15313837f, 0.147981972f, 0.0f };
