extern double func_0012AC20(void);
extern float func_0011C928(double);
float func_0012AC48(void)
{
    float r;
    /* asm label only (no instruction): keeps the argument move out of the jal delay slot, as retail line notes did */
    register double x __asm__("$4") = func_0012AC20();
    __asm__ __volatile__("1:" : "+r"(x));
    r = func_0011C928(x);
    /* empty barrier: stops the tail call */
    __asm__ __volatile__("");
    return r;
}
