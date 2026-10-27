/*
 * lib/libgcc: 5 files, 0011D980-0011E170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011D980 */
#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const float dat_004994E0[4] = { 0.5f, -0.5f, 9.9999994e29f, 7.8886086e-31f };
static const float dat_004994F0[2] = { 0.69313813f, -0.69313813f };
static const float dat_004994F8[8] = { 9.058001e-6f, -9.058001e-6f, 1.44269491f, 0.16666666f, -0.0027777777f, 6.6137553e-5f, -1.6533902e-6f, 4.1381366e-8f };
static const float dat_00499518[4] = { 3.4028235e38f, 0.0f, 1.0f, 0.0f };
#define halF ((const float*)dat_004994E0)
#define ln2HI ((const float*)dat_004994F0)
#define ln2LO ((const float*)dat_004994F8)
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
	    return (*(const float*)dat_00499518);
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
/* merge_units: end func_0011D980 */

/* merge_units: begin func_0011DBD8 */
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
/* merge_units: end func_0011DBD8 */

/* merge_units: begin func_0011DDA8 */
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
	const float two25 = 3.355443200e+07;
	const float zero   =  0.0;
	float hfsq,f,s,z,R,w,t1,t2,dk;
	int k,ix,i,j;

	GET_FLOAT_WORD(ix,x);

	k=0;
	if ((ix&0x7fffffff) < 0x00800000L)
	    return -two25/zero;
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
/* merge_units: end func_0011DDA8 */

/* merge_units: begin func_0011E088 */
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
/* merge_units: end func_0011E088 */

/* merge_units: begin func_0011E170 */
static const float
bp[] = {1.0, 1.5,},
dp_h[] = { 0.0, 5.84960938e-01,},
dp_l[] = { 0.0, 1.56322085e-06,};
extern const float D_004995FC;
extern float Math_Sqrtf(float x);
extern float Libc_Fabsf(float x);
extern float scalbnf(float x, int n);
float Math_PowfKernel(float x, float y)
{
	const float
	zero    =  0.0,
	one	=  1.0,
	two	=  2.0,
	huge	=  1.0e30,
	tiny    =  1.0e-30,
	L1  =  6.0000002384e-01,
	L2  =  4.2857143283e-01,
	L3  =  3.3333334327e-01,
	L4  =  2.7272811532e-01,
	L5  =  2.3066075146e-01,
	L6  =  2.0697501302e-01,
	P1   =  1.6666667163e-01,
	P2   = -2.7777778450e-03,
	P3   =  6.6137559770e-05,
	P4   = -1.6533901999e-06,
	P5   =  4.1381369442e-08,
	lg2  =  6.9314718246e-01,
	lg2_h  =  6.93145752e-01,
	lg2_l  =  1.42860654e-06,
	ovt =  4.2995665694e-08,
	cp    =  9.6179670095e-01,
	cp_h  =  9.6179199219e-01,
	cp_l  =  4.7017383622e-06,
	ivln2    =  1.4426950216e+00,
	ivln2_h  =  1.4426879883e+00,
	ivln2_l  =  7.0526075433e-06;
	float z,ax,z_h,z_l,p_h,p_l;
	float y1,t1,t2,r,s,t,u,v,w;
	int i,j,k,yisint,n;
	int hx,hy,ix,iy,is;

	GET_FLOAT_WORD(hx,x);
	GET_FLOAT_WORD(hy,y);
	ix = hx&0x7fffffff;  iy = hy&0x7fffffff;

	if(iy < 0x00800000L) return one;

	yisint  = 0;
	if(hx<0) {
	    if(iy>=0x4b800000) yisint = 2;
	    else if(iy>=0x3f800000) {
		k = (iy>>23)-0x7f;
		j = iy>>(23-k);
		if((j<<(23-k))==iy) yisint = 2-(j&1);
	    }
	}

	if(iy==0x3f800000) {
	    if(hy<0) return one/x; else return x;
	}
	if(hy==0x40000000) return x*x;
	if(hy==0x3f000000) {
	    if(hx>=0)
	    return Math_Sqrtf(x);
	}

	ax   = Libc_Fabsf(x);
	if(ix < 0x00800000L||ix==0x3f800000){
	    z = ax;
	    if(hy<0) z = one/z;
	    if(hx<0) {
		if(((ix-0x3f800000)|yisint)==0) {
		    z = (z-z)/(z-z);
		} else if(yisint==1)
		    z = -z;
	    }
	    return z;
	}

	if(((((unsigned int)hx>>31)-1)|yisint)==0) return (x-x)/(x-x);

	if(iy>0x4d000000) {
	    if(ix<0x3f7ffff8) return (hy<0)? D_004995FC:tiny*tiny;
	    if(ix>0x3f800007) return (hy>0)? D_004995FC:tiny*tiny;
	    t = x-1;
	    w = (t*t)*((float)0.5-t*((float)0.333333333333-t*(float)0.25));
	    u = ivln2_h*t;
	    v = t*ivln2_l-w*ivln2;
	    t1 = u+v;
	    GET_FLOAT_WORD(is,t1);
	    SET_FLOAT_WORD(t1,is&0xfffff000);
	    t2 = v-(t1-u);
	} else {
	    float s2,s_h,s_l,t_h,t_l;
	    n = 0;
	    n  += ((ix)>>23)-0x7f;
	    j  = ix&0x007fffff;
	    ix = j|0x3f800000;
	    if(j<=0x1cc471) k=0;
	    else if(j<0x5db3d7) k=1;
	    else {k=0;n+=1;ix -= 0x00800000;}
	    SET_FLOAT_WORD(ax,ix);

	    u = ax-bp[k];
	    v = one/(ax+bp[k]);
	    s = u*v;
	    s_h = s;
	    GET_FLOAT_WORD(is,s_h);
	    SET_FLOAT_WORD(s_h,is&0xfffff000);
	    SET_FLOAT_WORD(t_h,((ix>>1)|0x20000000)+0x0040000+(k<<21));
	    t_l = ax - (t_h-bp[k]);
	    s_l = v*((u-s_h*t_h)-s_h*t_l);
	    s2 = s*s;
	    r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
	    r += s_l*(s_h+s);
	    s2  = s_h*s_h;
	    t_h = (float)3.0+s2+r;
	    GET_FLOAT_WORD(is,t_h);
	    SET_FLOAT_WORD(t_h,is&0xfffff000);
	    t_l = r-((t_h-(float)3.0)-s2);
	    u = s_h*t_h;
	    v = s_l*t_h+t_l*s;
	    p_h = u+v;
	    GET_FLOAT_WORD(is,p_h);
	    SET_FLOAT_WORD(p_h,is&0xfffff000);
	    p_l = v-(p_h-u);
	    z_h = cp_h*p_h;
	    z_l = cp_l*p_h+p_l*cp+dp_l[k];
	    t = (float)n;
	    t1 = (((z_h+z_l)+dp_h[k])+t);
	    GET_FLOAT_WORD(is,t1);
	    SET_FLOAT_WORD(t1,is&0xfffff000);
	    t2 = z_l-(((t1-t)-dp_h[k])-z_h);
	}

	s = one;
	if(((((unsigned int)hx>>31)-1)|(yisint-1))==0)
	    s = -one;

	GET_FLOAT_WORD(is,y);
	SET_FLOAT_WORD(y1,is&0xfffff000);
	p_l = (y-y1)*t1+y*t2;
	p_h = y1*t1;
	z = p_l+p_h;
	GET_FLOAT_WORD(j,z);
	i = j&0x7fffffff;
	if (j>0) {
	    if (i>0x43010000)
	        return s*huge*huge;
	    else if (i==0x43010000)
	        if(p_l+ovt>z-p_h) return s*huge*huge;
        } else if (i>0x42fc0000) {
	        return s*tiny*tiny;
	} else if (i==0x42fc0000) {
	    if(p_l<=z-p_h) return s*tiny*tiny;
	}
	k = (i>>23)-0x7f;
	n = 0;
	if(i>0x3f000000) {
	    n = j+(0x00800000>>(k+1));
	    k = ((n&0x7fffffff)>>23)-0x7f;
	    SET_FLOAT_WORD(t,n&~(0x007fffff>>k));
	    n = ((n&0x007fffff)|0x00800000)>>(23-k);
	    if(j<0) n = -n;
	    p_h -= t;
	}
	t = p_l+p_h;
	GET_FLOAT_WORD(is,t);
	SET_FLOAT_WORD(t,is&0xfffff000);
	u = t*lg2_h;
	v = (p_l-(t-p_h))*lg2+t*lg2_l;
	z = u+v;
	w = v-(z-u);
	t  = z*z;
	t1  = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	r  = (z*t1)/(t1-two)-(w+z*w);
	z  = one-(r-z);
	GET_FLOAT_WORD(j,z);
	j += (n<<23);
	if((j>>23)<=0) z = scalbnf(z,(int)n);
	else SET_FLOAT_WORD(z,j);
	return s*z;
}
/* merge_units: end func_0011E170 */
