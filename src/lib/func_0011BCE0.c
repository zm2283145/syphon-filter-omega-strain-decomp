typedef union { float value; unsigned int value_raw; struct { unsigned int fraction:23; unsigned int exp:8; unsigned int sign:1; } bits; } FLO_0011BCE0;
typedef struct { int class; unsigned int sign; int normal_exp; union { unsigned int ll; } fraction; } fpn_0011BCE0;
void func_0011BCE0(FLO_0011BCE0 *src, fpn_0011BCE0 *dst)
{
  unsigned int fraction = src->bits.fraction;
  int exp = src->bits.exp;
  int sign = src->bits.sign;

  dst->sign = sign;
  if (exp == 0)
    {
      dst->class = 2;
    }
  else
    {
      dst->normal_exp = exp - 127;
      dst->class = 3;
      dst->fraction.ll = (fraction << 7) | (1 << 30);
    }
}