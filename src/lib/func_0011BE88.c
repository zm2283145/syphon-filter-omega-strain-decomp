typedef unsigned long fractype;
typedef unsigned int halffractype;
typedef double DFtype;
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union { fractype ll; halffractype l[2]; } fraction;
} fp_number_type;
typedef union {
    DFtype value;
    fractype value_raw;
    struct {
        fractype fraction:52 __attribute__((packed));
        unsigned int exp:11 __attribute__((packed));
        unsigned int sign:1 __attribute__((packed));
    } bits;
} FLO_union_type;
void func_0011BE88(FLO_union_type *src, fp_number_type *dst)
{
    fractype fraction = src->bits.fraction;
    int exp = src->bits.exp;
    int sign = src->bits.sign;
    dst->sign = sign;
    if (exp == 0) {
        dst->class = CLASS_ZERO;
    } else if (exp == 0x7FF) {
        dst->normal_exp = 0x3FF;
        if (fraction == 0) {
            dst->class = CLASS_INFINITY;
            dst->fraction.ll = (fractype)1 << 60;
        } else {
            if (fraction & ((fractype)1 << 51))
                dst->class = CLASS_QNAN;
            else
                dst->class = CLASS_SNAN;
            dst->fraction.ll = fraction;
        }
    } else {
        dst->normal_exp = exp - 0x3FF;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << 8) | ((fractype)1 << 60);
    }
}
