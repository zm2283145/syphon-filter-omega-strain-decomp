#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern const float D_0049955C;
float func_0011DDA8(float x)
{
	const float
	ln2_hi =   6.9313812256e-01,
	ln2_lo =   9.0580006145e-06,
	Lg1 = 6.6666668653e-01,
	Lg2 = 4.0000000596e-01,
	Lg3 = 2.8571429849e-01,
	Lg4 = 2.2222198546e-01,
	Lg5 = 1.8183572590e-01,
	Lg6 = 1.5313838422e-01,
	Lg7 = 1.4798198640e-01;
	const float zero   =  0.0;
	float hfsq,f,s,z,R,w,t1,t2,dk;
	int k,ix,i,j;

	GET_FLOAT_WORD(ix,x);

	k=0;
	if ((ix&0x7fffffff) < 0x00800000L)
	    return D_0049955C;
	if (ix<0) return (x-x)/zero;
	k += (ix>>23)-127;
	ix &= 0x007fffff;
	i = (ix+(0x95f64<<3))&0x800000;
	SET_FLOAT_WORD(x,ix|(i^0x3f800000));
	k += (i>>23);
	f = x-(float)1.0;
	if((0x007fffff&(15+ix))<16) {
	    if(f==zero) { if(k==0) return zero;  else {dk=(float)k;
				 return dk*ln2_hi+dk*ln2_lo;}}
	    R = f*f*((float)0.5-(float)0.33333333333333333*f);
	    if(k==0) return f-R; else {dk=(float)k;
	    	     return dk*ln2_hi-((R-dk*ln2_lo)-f);}
	}
	s = f/((float)2.0+f);
	dk = (float)k;
	z = s*s;
	i = ix-(0x6147a<<3);
	w = z*z;
	j = (0x6b851<<3)-ix;
	t1= w*(Lg2+w*(Lg4+w*Lg6));
	t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
	i |= j;
	R = t2+t1;
	if(i>0) {
	    hfsq=(float)0.5*f*f;
	    if(k==0) return f-(hfsq-s*(hfsq+R)); else
		     return dk*ln2_hi-((hfsq-(s*(hfsq+R)+dk*ln2_lo))-f);
	} else {
	    if(k==0) return f-s*(f-R); else
		     return dk*ln2_hi-((s*(f-R)-dk*ln2_lo)-f);
	}
}
