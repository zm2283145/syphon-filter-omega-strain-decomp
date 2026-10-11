extern float func_00121AA0(float x);
void func_0031B030(unsigned int n, float *in, float *out)
{
    while (n != 0) {
        *out++ = func_00121AA0(*in++);
        n--;
    }
}