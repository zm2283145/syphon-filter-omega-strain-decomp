extern const double D_00499E38[];
extern double func_0011C268(double a, double b);
double func_00127228(int dig)
{
  double v = 1.0;
  if (dig < 24)
    return D_00499E38[dig];
  while (dig > 0)
    {
      v = func_0011C268(v, 10.0);
      dig--;
    }
  return v;
}