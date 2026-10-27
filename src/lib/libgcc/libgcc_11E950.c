/*
 * lib/libgcc: 2 files, 0011E950-0011ED00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011E950 */
#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const int two_over_pi[198] = {
	0xA2, 0xF9, 0x83, 0x6E, 0x4E, 0x44, 0x15, 0x29,
	0xFC, 0x27, 0x57, 0xD1, 0xF5, 0x34, 0xDD, 0xC0,
	0xDB, 0x62, 0x95, 0x99, 0x3C, 0x43, 0x90, 0x41,
	0xFE, 0x51, 0x63, 0xAB, 0xDE, 0xBB, 0xC5, 0x61,
	0xB7, 0x24, 0x6E, 0x3A, 0x42, 0x4D, 0xD2, 0xE0,
	0x6, 0x49, 0x2E, 0xEA, 0x9, 0xD1, 0x92, 0x1C,
	0xFE, 0x1D, 0xEB, 0x1C, 0xB1, 0x29, 0xA7, 0x3E,
	0xE8, 0x82, 0x35, 0xF5, 0x2E, 0xBB, 0x44, 0x84,
	0xE9, 0x9C, 0x70, 0x26, 0xB4, 0x5F, 0x7E, 0x41,
	0x39, 0x91, 0xD6, 0x39, 0x83, 0x53, 0x39, 0xF4,
	0x9C, 0x84, 0x5F, 0x8B, 0xBD, 0xF9, 0x28, 0x3B,
	0x1F, 0xF8, 0x97, 0xFF, 0xDE, 0x5, 0x98, 0xF,
	0xEF, 0x2F, 0x11, 0x8B, 0x5A, 0xA, 0x6D, 0x1F,
	0x6D, 0x36, 0x7E, 0xCF, 0x27, 0xCB, 0x9, 0xB7,
	0x4F, 0x46, 0x3F, 0x66, 0x9E, 0x5F, 0xEA, 0x2D,
	0x75, 0x27, 0xBA, 0xC7, 0xEB, 0xE5, 0xF1, 0x7B,
	0x3D, 0x7, 0x39, 0xF7, 0x8A, 0x52, 0x92, 0xEA,
	0x6B, 0xFB, 0x5F, 0xB1, 0x1F, 0x8D, 0x5D, 0x8,
	0x56, 0x3, 0x30, 0x46, 0xFC, 0x7B, 0x6B, 0xAB,
	0xF0, 0xCF, 0xBC, 0x20, 0x9A, 0xF4, 0x36, 0x1D,
	0xA9, 0xE3, 0x91, 0x61, 0x5E, 0xE6, 0x1B, 0x8,
	0x65, 0x99, 0x85, 0x5F, 0x14, 0xA0, 0x68, 0x40,
	0x8D, 0xFF, 0xD8, 0x80, 0x4D, 0x73, 0x27, 0x31,
	0x6, 0x6, 0x15, 0x56, 0xCA, 0x73, 0xA8, 0xC9,
	0x60, 0xE2, 0x7B, 0xC0, 0x8C, 0x6B,
};
static const int npio2_hw[32] = {
	0x3FC90F00, 0x40490F00, 0x4096CB00, 0x40C90F00, 0x40FB5300, 0x4116CB00, 0x412FED00, 0x41490F00,
	0x41623100, 0x417B5300, 0x418A3A00, 0x4196CB00, 0x41A35C00, 0x41AFED00, 0x41BC7E00, 0x41C90F00,
	0x41D5A000, 0x41E23100, 0x41EEC200, 0x41FB5300, 0x4203F200, 0x420A3A00, 0x42108300, 0x4216CB00,
	0x421D1400, 0x42235C00, 0x4229A500, 0x422FED00, 0x42363600, 0x423C7E00, 0x4242C700, 0x42490F00,
};
extern float Libc_Fabsf(float x);
extern int Math_RemPio2Kernel(float *x, float *y, int e0, int nx, int prec, const int *ipio2);
int Math_RemPio2(float x, float *y)
{
	const float
	zero =  0.0000000000e+00,
	half =  5.0000000000e-01,
	two8 =  2.5600000000e+02,
	invpio2 =  6.3661980629e-01,
	pio2_1  =  1.5707855225e+00,
	pio2_1t =  1.0804334124e-05,
	pio2_2  =  1.0804273188e-05,
	pio2_2t =  6.0770999344e-11,
	pio2_3  =  6.0770943833e-11,
	pio2_3t =  6.1232342629e-17;
	float z,w,t,r,fn;
	float tx[3];
	int i,j,n,ix,hx;
	int e0,nx;

	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix<=0x3f490fd8)
	    {y[0] = x; y[1] = 0; return 0;}
	if(ix<0x4016cbe4) {
	    if(hx>0) {
		z = x - pio2_1;
		if((ix&0xfffffff0)!=0x3fc90fd0) {
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
		if((ix&0xfffffff0)!=0x3fc90fd0) {
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
	if(ix<=0x43490f80) {
	    t  = Libc_Fabsf(x);
	    n  = (int) (t*invpio2+half);
	    fn = (float)n;
	    r  = t-fn*pio2_1;
	    w  = fn*pio2_1t;
	    if(n<32&&(ix&0xffffff00)!=npio2_hw[n-1]) {
		y[0] = r-w;
	    } else {
	        unsigned int high;
	        j  = ix>>23;
	        y[0] = r-w;
		GET_FLOAT_WORD(high,y[0]);
	        i = j-((high>>23)&0xff);
	        if(i>8) {
		    t  = r;
		    w  = fn*pio2_2;
		    r  = t-w;
		    w  = fn*pio2_2t-((t-r)-w);
		    y[0] = r-w;
		    GET_FLOAT_WORD(high,y[0]);
		    i = j-((high>>23)&0xff);
		    if(i>25)  {
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
	e0 	= (int)((ix>>23)-134);
	SET_FLOAT_WORD(z, ix - ((int)e0<<23));
	for(i=0;i<2;i++) {
		tx[i] = (float)((int)(z));
		z     = (z-tx[i])*two8;
	}
	tx[2] = z;
	nx = 3;
	while(tx[nx-1]==zero) nx--;
	n  =  Math_RemPio2Kernel(tx,y,e0,nx,2,two_over_pi);
	if(hx<0) {y[0] = -y[0]; y[1] = -y[1]; return -n;}
	return n;
}
/* merge_units: end func_0011E950 */

/* merge_units: begin func_0011ED00 */
float Math_Sqrtf(float x)
{
	const float one = 1.0, tiny = 1.0e-30;
	float z;
	unsigned int r,hx;
	int ix,s,q,m,t,i;

	GET_FLOAT_WORD(ix,x);
	hx = ix&0x7fffffff;

	if(hx < 0x00800000L) return x;
	if(ix<0) return (x-x)/(x-x);

	m = (ix>>23);
	if(0) {
	    for(i=0;(ix&0x00800000L)==0;i++) ix<<=1;
	    m -= i-1;
	}
	m -= 127;
	ix = (ix&0x007fffffL)|0x00800000L;
	if(m&1)
	    ix += ix;
	m >>= 1;

	ix += ix;
	q = s = 0;
	r = 0x01000000L;

	while(r!=0) {
	    t = s+r;
	    if(t<=ix) {
		s    = t+r;
		ix  -= t;
		q   += r;
	    }
	    ix += ix;
	    r>>=1;
	}

	if(ix!=0) {
	    z = one-tiny;
	    if (z>=one) {
	        z = one+tiny;
		if (z>one)
		    q += 2;
		else
		    q += (q&1);
	    }
	}
	ix = (q>>1)+0x3f000000L;
	ix += (m <<23);
	SET_FLOAT_WORD(z,ix);
	return z;
}
/* merge_units: end func_0011ED00 */
