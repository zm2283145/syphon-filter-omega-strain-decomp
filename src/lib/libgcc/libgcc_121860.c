#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern float func_00121648(float x, float y);
float scalbnf(float x, int n)
{
    const float huge = 1.0e+30, tiny = 1.0e-30;
    int k, ix;
    unsigned int hx;
    GET_FLOAT_WORD(ix, x);
    hx = ix & 0x7fffffff;
    k = hx >> 23;
    if (hx < 0x00800000L) return x;
    k = k + n;
    if (k > 0xff) return huge * func_00121648(huge, x);
    if (k > 0) { SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23)); return x; }
    if (n > 50000) return huge * func_00121648(huge, x);
    else return tiny * func_00121648(tiny, x);
}