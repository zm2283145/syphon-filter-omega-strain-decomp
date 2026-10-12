typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } ieee_double_shape_type;
double func_00120CE8(double x)
{
    unsigned int high;
    do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
    do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (high & 0x7fffffff); (x) = sh_u.value; } while (0);
    {
        /* asm label only (no instruction): stops delay-slot filling of the return move, as retail line notes did */
        register double r __asm__("$2") = x;
        __asm__ __volatile__("1:" : "+r"(r));
        return r;
    }
}
