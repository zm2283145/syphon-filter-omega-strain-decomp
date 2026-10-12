typedef union { float value; unsigned int value_raw; } FLO_0011BD70;
typedef struct { int class; unsigned int sign; int normal_exp; union { unsigned int ll; } fraction; } fpn_0011BD70;
extern void func_0011BCE0(FLO_0011BD70 *src, fpn_0011BD70 *dst);
extern double func_0011C8F8(int class, unsigned int sign, int exp, unsigned long long frac);
double SoftFloat_FloatToDouble(float arg_a)
{
  fpn_0011BD70 in;
  FLO_0011BD70 au;

  au.value = arg_a;
  func_0011BCE0 (&au, &in);
  return func_0011C8F8 (in.class, in.sign, in.normal_exp,
		    ((unsigned long long) in.fraction.ll) << 30);
}