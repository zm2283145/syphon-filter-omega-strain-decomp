#include "types.h"
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
