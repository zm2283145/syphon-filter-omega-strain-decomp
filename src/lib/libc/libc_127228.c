/*
 * lib/libc: 2 files, 00127228-00127298
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00127228 */
extern const double D_00499E38[];
extern double SoftFloat_DoubleMultiply(double a, double b);
double func_00127228(int dig)
{
  double v = 1.0;
  if (dig < 24)
    return D_00499E38[dig];
  while (dig > 0)
    {
      v = SoftFloat_DoubleMultiply(v, 10.0);
      dig--;
    }
  return v;
}
/* merge_units: end func_00127228 */

/* merge_units: begin func_00127298 */
extern int D_0058805C;
extern int func_0010D820(int fd, void* buf, unsigned int cnt);
struct reent_00127298 { int _errno; };
int func_00127298(struct reent_00127298* ptr, int fd, void* buf, unsigned int cnt)
{
    int ret;
    D_0058805C = 0;
    if ((ret = func_0010D820(fd, buf, cnt)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}
/* merge_units: end func_00127298 */
