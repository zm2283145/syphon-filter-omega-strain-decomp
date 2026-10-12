/* emulates retail newlib's -g build: gas then skips delay-slot swapping */
__asm__(".set nomove");
struct _reent;
union double_union {
    double d;
    unsigned int i[2];
};
#define word0(x) (x.i[1])
#define Sign_bit 0x80000000
#define ALT 0x001
extern double func_0011C200(double a, double b);
extern int SoftFloat_UnpackAndCompare(double a, double b);
extern char *func_001220A8(struct _reent *ptr, double d, int mode, int ndigits, int *decpt, int *sign, char **rve);

char *func_0012DA78(struct _reent *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length)
{
    int mode, dsgn;
    char *digits, *bp, *rve;
    union double_union tmp;

    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2;
    }

    tmp.d = value;
    if (word0(tmp) & Sign_bit) {
        value = func_0011C200(0, value);
        *sign = '-';
    } else
        *sign = '\000';
    digits = func_001220A8(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || flags & ALT) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && SoftFloat_UnpackAndCompare(value, 0) != 0)
                *decpt = -ndigits + 1;
            bp += *decpt;
        }
        if (SoftFloat_UnpackAndCompare(value, 0) == 0)
            rve = bp;
        while (rve < bp)
            *rve++ = '0';
    }
    *length = rve - digits;
    return (digits);
}