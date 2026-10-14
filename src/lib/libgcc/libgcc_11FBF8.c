/*
 * lib/libgcc: 6 files, 0011FBF8-00120B78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011FBF8 */
__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = func_0011C200\n"
        "dpmul = func_0011C268\n"
        "dptoli = func_0011C858\n");
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)

double func_0011FBF8(double x, double y, int iy)
{
	const double
	half =  5.00000000000000000000e-01,
	S1  = -1.66666666666666324348e-01,
	S2  =  8.33333333332248946124e-03,
	S3  = -1.98412698298579493134e-04,
	S4  =  2.75573137070700676789e-06,
	S5  = -2.50507602534068634195e-08,
	S6  =  1.58969099521155010221e-10;
	double z,r,v;
	int ix;
	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix<0x3e400000)
	   {if((int)x==0) return x;}
	z	=  x*x;
	v	=  z*x;
	r	=  S2+z*(S3+z*(S4+z*(S5+z*S6)));
	if(iy==0) return x+v*(S1+z*r);
	else      return x-((z*(half*y-v*r)-y)-v*S1);
}
/* merge_units: end func_0011FBF8 */

/* merge_units: begin func_0011FE30 */
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
/* merge_units: end func_0011FE30 */

/* merge_units: begin func_0011FF80 */
static const unsigned int dat_00499B08[4] = { 0x4, 0x7, 0x9, 0x0 };
static const float dat_00499B18[20] = { 1.5703125f, 0.00045776368f, 2.5987624e-5f, 7.543713e-8f, 6.0026644e-11f, 7.389644e-13f, 5.3845813e-15f, 5.637851e-18f, 8.300923e-20f, 3.275635e-22f, 6.3331016e-25f, 0.0f, 1.0f, 256.0f, 0.00390625f, 0.0f, 1.0f, 0.78539813f, 3.7748944e-8f, 0.0f };
#define init_jk ((const int*)dat_00499B08)
#define PIo2 ((const float*)dat_00499B18)
extern float scalbnf(float x, int n);
extern float func_00121788(float x);
#define scalbnf scalbnf
#define floorf func_00121788
int Math_RemPio2Kernel(float *x, float *y, int e0, int nx, int prec, const int *ipio2)
{
	const float
	zero   = 0.0,
	one    = 1.0,
	two8   =  2.5600000000e+02,
	twon8  =  3.9062500000e-03;
	int jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	float z,fw,f[20],fq[20],q[20];

	jk = init_jk[prec];
	jp = jk;

	jx =  nx-1;
	jv = (e0-3)/8; if(jv<0) jv=0;
	q0 =  e0-8*(jv+1);

	j = jv-jx; m = jx+jk;
	for(i=0;i<=m;i++,j++) f[i] = (j<0)? zero : (float) ipio2[j];

	for (i=0;i<=jk;i++) {
	    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
	}

	jz = jk;
recompute:
	for(i=0,j=jz,z=q[jz];j>0;i++,j--) {
	    fw    =  (float)((int)(twon8* z));
	    iq[i] =  (int)(z-two8*fw);
	    z     =  q[j-1]+fw;
	}

	z  = scalbnf(z,(int)q0);
	z -= (float)8.0*floorf(z*(float)0.125);
	n  = (int) z;
	z -= (float)n;
	ih = 0;
	if(q0>0) {
	    i  = (iq[jz-1]>>(8-q0)); n += i;
	    iq[jz-1] -= i<<(8-q0);
	    ih = iq[jz-1]>>(7-q0);
	}
	else if(q0==0) ih = iq[jz-1]>>8;
	else if(z>=(float)0.5) ih=2;

	if(ih>0) {
	    n += 1; carry = 0;
	    for(i=0;i<jz ;i++) {
		j = iq[i];
		if(carry==0) {
		    if(j!=0) {
			carry = 1; iq[i] = 0x100- j;
		    }
		} else  iq[i] = 0xff - j;
	    }
	    if(q0>0) {
	        switch(q0) {
	        case 1:
	    	   iq[jz-1] &= 0x7f; break;
	    	case 2:
	    	   iq[jz-1] &= 0x3f; break;
	        }
	    }
	    if(ih==2) {
		z = one - z;
		if(carry!=0) z -= scalbnf(one,(int)q0);
	    }
	}

	if(z==zero) {
	    j = 0;
	    for (i=jz-1;i>=jk;i--) j |= iq[i];
	    if(j==0) {
		for(k=1;iq[jk-k]==0;k++);

		for(i=jz+1;i<=jz+k;i++) {
		    f[jx+i] = (float) ipio2[jv+i];
		    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
		    q[i] = fw;
		}
		jz += k;
		goto recompute;
	    }
	}

	if(z==(float)0.0) {
	    jz -= 1; q0 -= 8;
	    while(iq[jz]==0) { jz--; q0-=8;}
	} else {
	    z = scalbnf(z,-(int)q0);
	    if(z>=two8) {
		fw = (float)((int)(twon8*z));
		iq[jz] = (int)(z-two8*fw);
		jz += 1; q0 += 8;
		iq[jz] = (int) fw;
	    } else iq[jz] = (int) z ;
	}

	fw = scalbnf(one,(int)q0);
	for(i=jz;i>=0;i--) {
	    q[i] = fw*(float)iq[i]; fw*=twon8;
	}

	for(i=jz;i>=0;i--) {
	    for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++) fw += PIo2[k]*q[i+k];
	    fq[jz-i] = fw;
	}

	switch(prec) {
	    case 0:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		break;
	    case 1:
	    case 2:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		fw = fq[0]-fw;
		for (i=1;i<=jz;i++) fw += fq[i];
		y[1] = (ih==0)? fw: -fw;
		break;
	    case 3:
		for (i=jz;i>0;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (i=jz;i>1;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (fw=0.0,i=jz;i>=2;i--) fw += fq[i];
		if(ih==0) {
		    y[0] =  fq[0]; y[1] =  fq[1]; y[2] =  fw;
		} else {
		    y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
		}
	}
	return n&7;
}
/* merge_units: end func_0011FF80 */

/* merge_units: begin func_001207E8 */
float Math_SinKernel(float x, float y, int iy)
{
	const float
half =  5.0000000000e-01,
S1  = -1.6666667163e-01,
S2  =  8.3333337680e-03,
S3  = -1.9841270114e-04,
S4  =  2.7557314297e-06,
S5  = -2.5050759689e-08,
S6  =  1.5896910177e-10;
	float z,r,v;
	int ix;
	GET_FLOAT_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix<0x32000000)
	   {if((int)x==0) return x;}
	z	=  x*x;
	v	=  z*x;
	r	=  S2+z*(S3+z*(S4+z*(S5+z*S6)));
	if(iy==0) return x+v*(S1+z*r);
	else      return x-((z*(half*y-v*r)-y)-v*S1);
}
/* merge_units: end func_001207E8 */

/* merge_units: begin func_001208F0 */
static const float T[] = {
	0.33333335f,
	0.133333341f,
	0.053968255f,
	0.021869487f,
	0.008863239f,
	0.0035920791f,
	0.0014562094f,
	0.00058804121f,
	0.00024646312f,
	7.8179445e-5f,
	7.1407253e-5f,
	-1.8558636e-5f,
	2.5907306e-5f,
};
extern float func_00121760(float x);
float Math_TanKernel(float x, float y, int iy)
{
	const float
	one   =  1.0000000000e+00,
	pio4  =  7.8539812565e-01,
	pio4lo=  3.7748947079e-08;
	float z,r,v,w,s;
	int ix,hx;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix<0x31800000)
	    {if((int)x==0) {
		if((ix|(iy+1))==0) return one/func_00121760(x);
		else return (iy==1)? x: -one/x;
	    }
	    }
	if(ix>=0x3f2ca140) {
	    if(hx<0) {x = -x; y = -y;}
	    z = pio4-x;
	    w = pio4lo-y;
	    x = z+w; y = 0.0;
	}
	z	=  x*x;
	w 	=  z*z;
	r = T[1]+w*(T[3]+w*(T[5]+w*(T[7]+w*(T[9]+w*T[11]))));
	v = z*(T[2]+w*(T[4]+w*(T[6]+w*(T[8]+w*(T[10]+w*T[12])))));
	s = z*x;
	r = y + z*(s*(r+v)+y);
	r += T[0]*s;
	w = x+r;
	if(ix>=0x3f2ca140) {
	    v = (float)iy;
	    return (float)(1-((hx>>30)&2))*(v-(float)2.0*(x-(w*w/(w+v)-r)));
	}
	if(iy==1) return w;
	else {
	    float a,t;
	    int i;
	    z  = w;
	    GET_FLOAT_WORD(i,z);
	    SET_FLOAT_WORD(z,i&0xfffff000);
	    v  = r-(z - x);
	    t = a  = -(float)1.0/w;
	    GET_FLOAT_WORD(i,t);
	    SET_FLOAT_WORD(t,i&0xfffff000);
	    s  = (float)1.0+t*z;
	    return t+a*(s+t*v);
	}
}
/* merge_units: end func_001208F0 */

/* merge_units: begin func_00120B78 */
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
double func_00120B78(double x, double y)
{
	unsigned int hx,hy;
	GET_HIGH_WORD(hx,x);
	GET_HIGH_WORD(hy,y);
	SET_HIGH_WORD(x,(hx&0x7fffffff)|(hy&0x80000000));
	return x;
}
/* merge_units: end func_00120B78 */
