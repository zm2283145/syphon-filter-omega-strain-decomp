#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define huge 1.0e30f
float func_00121570(float x)
{
    int i0, j0;
    unsigned int i, ix;
    GET_FLOAT_WORD(i0, x);
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge + x > (float)0.0) {
                if (i0 < 0) { i0 = 0x80000000; }
                else if (!FLT_UWORD_IS_ZERO(ix)) { i0 = 0x3f800000; }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge + x > (float)0.0) {
                if (i0 > 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
