#include "types.h"
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
int func_00120F38(double x)
{
	int hx,lx;
	EXTRACT_WORDS(hx,lx,x);
	hx &= 0x7fffffff;
	hx |= (unsigned int)(lx|(-lx))>>31;
	hx = 0x7ff00000 - hx;
	return 1 - (int)((unsigned int)(hx|(-hx))>>31);
}
