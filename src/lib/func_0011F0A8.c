/* __kernel_rem_pio2 (newlib/fdlibm k_rem_pio2.c); retail newlib was built with -g. */
__asm__(".set nomove\n"
        "dpadd = func_0011C1A8\n"
        "dpsub = func_0011C200\n"
        "dpmul = func_0011C268\n"
        "litodp = func_0011C7A0\n"
        "dptoli = func_0011C858\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n");
typedef int __int32_t;

extern double func_00120FC0(double, int); /* scalbn */
extern double func_00120D20(double);      /* floor */
#define scalbn func_00120FC0
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
