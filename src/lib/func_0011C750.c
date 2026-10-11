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
extern int SoftFloat_DoubleCompare(fp_number_type* a, fp_number_type* b);
int SoftFloat_UnpackAndCompare(DFtype arg_a, DFtype arg_b)
{
    fp_number_type a;
    fp_number_type b;
    FLO_union_type au, bu;
    au.value = arg_a;
    bu.value = arg_b;
    func_0011BE88(&au, &a);
    func_0011BE88(&bu, &b);
    return SoftFloat_DoubleCompare(&a, &b);
}