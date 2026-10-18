/*
 * lib/libgcc: 2 files, 0011EDD0-0011F0A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0011EDD0 */
__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = func_0011C200\n"
        "dpmul = SoftFloat_DoubleMultiply\n"
        "dptoli = func_0011C858\n");
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

double func_0011EDD0(double x, double y)
{
	const double
	one =  1.00000000000000000000e+00,
	C1  =  4.16666666666666019037e-02,
	C2  = -1.38888888888741095749e-03,
	C3  =  2.48015872894767294178e-05,
	C4  = -2.75573143513906633035e-07,
	C5  =  2.08757232129817482790e-09,
	C6  = -1.13596475577881948265e-11;
	double a,hz,z,r,qx;
	int ix;
	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix<0x3e400000) {
	    if(((int)x)==0) return one;
	}
	z  = x*x;
	r  = z*(C1+z*(C2+z*(C3+z*(C4+z*(C5+z*C6)))));
	if(ix < 0x3FD33333)
	    return one - (0.5*z - (z*r - x*y));
	else {
	    if(ix > 0x3fe90000) {
		qx = 0.28125;
	    } else {
	        INSERT_WORDS(qx,ix-0x00200000,0);
	    }
	    hz = 0.5*z-qx;
	    a  = one-qx;
	    return a - (hz - (z*r-x*y));
	}
}
/* merge_units: end func_0011EDD0 */

/* merge_units: begin func_0011F0A8 */
/* __kernel_rem_pio2 (newlib/fdlibm k_rem_pio2.c); retail newlib was built with -g. */
__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = func_0011C200\n"
        "dpmul = SoftFloat_DoubleMultiply\n"
        "litodp = func_0011C7A0\n"
        "dptoli = func_0011C858\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n");
typedef int __int32_t;

extern double scalbn(double, int); /* scalbn */
extern double func_00120D20(double);      /* floor */
#define scalbn scalbn
#define floor func_00120D20

/* init_jk / PIo2 tables (+ zero, one, two24, twon24) live in unowned .data */
extern const int D_00499A28[];
extern const double D_00499A38[];
#define init_jk D_00499A28
#define PIo2 D_00499A38

/* zero/one/two24/twon24 are folded into the code (their copies follow PIo2 in .data) */
#define zero 0.0
#define one 1.0
#define two24 1.67772160000000000000e+07
#define twon24 5.96046447753906250000e-08

int func_0011F0A8(double *x, double *y, int e0, int nx, int prec, const __int32_t *ipio2)
{
	__int32_t jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	double z,fw,f[20],fq[20],q[20];

	jk = init_jk[prec];
	jp = jk;

	jx =  nx-1;
	jv = (e0-3)/24; if(jv<0) jv=0;
	q0 =  e0-24*(jv+1);

	j = jv-jx; m = jx+jk;
	for(i=0;i<=m;i++,j++) f[i] = (j<0)? zero : (double) ipio2[j];

	for (i=0;i<=jk;i++) {
	    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
	}

	jz = jk;
recompute:
	for(i=0,j=jz,z=q[jz];j>0;i++,j--) {
	    fw    =  (double)((__int32_t)(twon24* z));
	    iq[i] =  (__int32_t)(z-two24*fw);
	    z     =  q[j-1]+fw;
	}

	z  = scalbn(z,(int)q0);
	z -= 8.0*floor(z*0.125);
	n  = (__int32_t) z;
	z -= (double)n;
	ih = 0;
	if(q0>0) {
	    i  = (iq[jz-1]>>(24-q0)); n += i;
	    iq[jz-1] -= i<<(24-q0);
	    ih = iq[jz-1]>>(23-q0);
	}
	else if(q0==0) ih = iq[jz-1]>>23;
	else if(z>=0.5) ih=2;

	if(ih>0) {
	    n += 1; carry = 0;
	    for(i=0;i<jz ;i++) {
		j = iq[i];
		if(carry==0) {
		    if(j!=0) {
			carry = 1; iq[i] = 0x1000000- j;
		    }
		} else  iq[i] = 0xffffff - j;
	    }
	    if(q0>0) {
	        switch(q0) {
	        case 1:
	    	   iq[jz-1] &= 0x7fffff; break;
	    	case 2:
	    	   iq[jz-1] &= 0x3fffff; break;
	        }
	    }
	    if(ih==2) {
		z = one - z;
		if(carry!=0) z -= scalbn(one,(int)q0);
	    }
	}

	if(z==zero) {
	    j = 0;
	    for (i=jz-1;i>=jk;i--) j |= iq[i];
	    if(j==0) {
		for(k=1;iq[jk-k]==0;k++);

		for(i=jz+1;i<=jz+k;i++) {
		    f[jx+i] = (double) ipio2[jv+i];
		    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
		    q[i] = fw;
		}
		jz += k;
		goto recompute;
	    }
	}

	if(z==0.0) {
	    jz -= 1; q0 -= 24;
	    while(iq[jz]==0) { jz--; q0-=24;}
	} else {
	    z = scalbn(z,-(int)q0);
	    if(z>=two24) {
		fw = (double)((__int32_t)(twon24*z));
		iq[jz] = (__int32_t)(z-two24*fw);
		jz += 1; q0 += 24;
		iq[jz] = (__int32_t) fw;
	    } else iq[jz] = (__int32_t) z ;
	}

	fw = scalbn(one,(int)q0);
	for(i=jz;i>=0;i--) {
	    q[i] = fw*(double)iq[i]; fw*=twon24;
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
/* merge_units: end func_0011F0A8 */
