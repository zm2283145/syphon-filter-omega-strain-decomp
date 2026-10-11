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
DFtype func_0011C7A0(int arg_a)
{
    fp_number_type in;
    in.class = CLASS_NUMBER;
    in.sign = arg_a < 0;
    if (!arg_a) {
        in.class = CLASS_ZERO;
    } else {
        in.normal_exp = 60;
        if (in.sign) {
            if (arg_a == (-0x7fffffff - 1)) {
                return (DFtype)(-0x7fffffff - 1);
            }
            in.fraction.ll = (-arg_a);
        } else
            in.fraction.ll = arg_a;
        while (in.fraction.ll < ((fractype)1 << 60)) {
            in.fraction.ll <<= 1;
            in.normal_exp -= 1;
        }
    }
    return func_0011BDB0(&in);
}