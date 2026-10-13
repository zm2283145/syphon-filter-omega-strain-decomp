__asm__(".set nomove\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpmul = func_0011C268\n");
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
extern const double D_00499BD8;
extern const double D_00499BE0;
#define tiny D_00499BD8
#define huge D_00499BE0
#define two54 1.80143985094819840000e+16
#define twom54 5.55111512312578270212e-17
extern double func_00120B78(double, double);

double func_00120FC0(double x, int n)
{
	int k,hx,lx;
	EXTRACT_WORDS(hx,lx,x);
        k = (hx&0x7ff00000)>>20;
        if (k==0) {
            if ((lx|(hx&0x7fffffff))==0) return x;
	    x *= two54;
	    GET_HIGH_WORD(hx,x);
	    k = ((hx&0x7ff00000)>>20) - 54;
            if (n< -50000) return x*tiny;
	    }
        if (k==0x7ff) return x+x;
        k = k+n;
        if (k >  0x7fe) return func_00120B78(huge,x)*huge;
        if (k > 0)
	    {SET_HIGH_WORD(x,(hx&0x800fffff)|(k<<20)); return x;}
        if (k <= -54) {
            if (n > 50000)
		return func_00120B78(huge,x)*huge;
	    else return func_00120B78(tiny,x)*tiny;
	}
        k += 54;
	SET_HIGH_WORD(x,(hx&0x800fffff)|(k<<20));
        return x*twom54;
}

