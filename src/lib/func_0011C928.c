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
extern float func_0011BD40(fp_class_type class, unsigned int sign, int exp, unsigned int frac);
float SoftFloat_DoubleToFloat(DFtype arg_a)
{
    fp_number_type in;
    unsigned int sffrac;
    FLO_union_type au;
    au.value = arg_a;
    func_0011BE88(&au, &in);
    sffrac = in.fraction.ll >> 30;
    if ((in.fraction.ll & (((unsigned int)1 << 30) - 1)) != 0)
        sffrac |= 1;
    return func_0011BD40(in.class, in.sign, in.normal_exp, sffrac);
}