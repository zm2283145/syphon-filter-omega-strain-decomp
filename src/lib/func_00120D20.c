__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpcmp = SoftFloat_UnpackAndCompare\n");
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)
extern const double D_00499BA8;
#define huge D_00499BA8

double func_00120D20(double x)
{
	int i0,i1,j0;
	unsigned int i,j;
	EXTRACT_WORDS(i0,i1,x);
	j0 = ((i0>>20)&0x7ff)-0x3ff;
	if(j0<20) {
	    if(j0<0) {
		if(x+huge>0.0) {
		    if(i0>=0) {i0=i1=0;}
		    else if(((i0&0x7fffffff)|i1)!=0)
			{ i0=0xbff00000;i1=0;}
		}
	    } else {
		i = (0x000fffff)>>j0;
		if(((i0&i)|i1)==0) return x;
		if(x+huge>0.0) {
		    if(i0<0) i0 += (0x00100000)>>j0;
		    i0 &= (~i); i1=0;
		}
	    }
	} else if (j0>51) {
	    if(j0==0x400) return x+x;
	    else return x;
	} else {
	    i = ((unsigned int)(0xffffffff))>>(j0-20);
	    if((i1&i)==0) return x;
	    if(x+huge>0.0) {
		if(i0<0) {
		    if(j0==20) i0+=1;
		    else {
			j = i1+(1<<(52-j0));
			if(j<i1) i0 +=1 ;
			i1=j;
		    }
		}
		i1 &= (~i);
	    }
	}
	INSERT_WORDS(x,i0,i1);
	return x;
}

