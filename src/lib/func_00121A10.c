typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
extern float func_001208F0(float x, float y, int k);
extern int func_0011E950(float x, float* y);
float Math_Tan(float x) { float y[2], z = 0.0f; int n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fda) return func_001208F0(x, z, 1); else { n = func_0011E950(x, y); return func_001208F0(y[0], y[1], 1 - ((n & 1) << 1)); } }
