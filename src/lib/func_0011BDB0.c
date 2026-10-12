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
static __inline__ int isinf_(fp_number_type *x) { return x->class == CLASS_INFINITY; }
static __inline__ int iszero_(fp_number_type *x) { return x->class == CLASS_ZERO; }
DFtype func_0011BDB0(fp_number_type *src)
{
    FLO_union_type dst;
    fractype fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;
    if (src->class == CLASS_QNAN || src->class == CLASS_SNAN) {
        exp = 0x7FF;
        fraction |= (fractype)1 << 51;
    } else if (isinf_(src)) {
        exp = 0x7FF;
        fraction = 0;
    } else if (iszero_(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -1022) {
            fraction = 0;
        } else if (src->normal_exp > 1023) {
            exp = 0x7FF;
            fraction = 0;
        } else {
            exp = src->normal_exp + 1023;
            fraction >>= 8;
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
