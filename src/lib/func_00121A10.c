typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
extern float Math_TanKernel(float x, float y, int k);
extern int Math_RemPio2(float x, float* y);
float Math_Tan(float x) { float y[2], z = 0.0f; int n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fda) return Math_TanKernel(x, z, 1); else { n = Math_RemPio2(x, y); return Math_TanKernel(y[0], y[1], 1 - ((n & 1) << 1)); } }
