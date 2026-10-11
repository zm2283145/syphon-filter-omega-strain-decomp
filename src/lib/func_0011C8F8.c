#include "types.h"
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
typedef union { DFtype value; fractype value_raw; } FLO_union_type;
extern void func_0011BE88(FLO_union_type* src, fp_number_type* dst);
extern DFtype func_0011BDB0(fp_number_type* src);
DFtype func_0011C8F8(fp_class_type class, unsigned int sign, int exp, fractype frac)
{
    fp_number_type in;
    in.class = class;
    in.sign = sign;
    in.normal_exp = exp;
    in.fraction.ll = frac;
    return func_0011BDB0(&in);
}