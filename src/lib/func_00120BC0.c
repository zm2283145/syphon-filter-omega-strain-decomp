__asm__(".set nomove\n"
        "dpsub = func_0011C200\n");
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
extern double func_0011EDD0(double x, double y);
extern double func_0011FBF8(double x, double y, int iy);
extern int func_0011CA20(double x, double *y);

double func_00120BC0(double x)
{
	double y[2],z=0.0;
	int n,ix;

	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return func_0011EDD0(x,z);
	else if (ix>=0x7ff00000) return x-x;
	else {
	    n = func_0011CA20(x,y);
	    switch(n&3) {
		case 0: return  func_0011EDD0(y[0],y[1]);
		case 1: return -func_0011FBF8(y[0],y[1],1);
		case 2: return -func_0011EDD0(y[0],y[1]);
		default:
		        return  func_0011FBF8(y[0],y[1],1);
	    }
	}
}
