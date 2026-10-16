/*
 * lib/libgcc: 2 files, 00121760-00121788
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00121760 */
#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
float func_00121760(float x)
{
	unsigned int ix;
	GET_FLOAT_WORD(ix,x);
	SET_FLOAT_WORD(x,ix&0x7fffffff);
	return x;
}
/* merge_units: end func_00121760 */

/* merge_units: begin func_00121788 */
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define huge 1.0e30f
float Math_Floorf(float x)
{
    int i0, j0;
    unsigned int i, ix;
    GET_FLOAT_WORD(i0, x);
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge + x > (float)0.0) {
                if (i0 >= 0) { i0 = 0; }
                else if (!FLT_UWORD_IS_ZERO(ix)) { i0 = 0xbf800000; }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge + x > (float)0.0) {
                if (i0 < 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
/* merge_units: end func_00121788 */
