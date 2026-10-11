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
static __inline__ int isnan_(fp_number_type* x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
static __inline__ int isinf_(fp_number_type* x) { return x->class == CLASS_INFINITY; }
static __inline__ int iszero_(fp_number_type* x) { return x->class == CLASS_ZERO; }
unsigned int func_0011C980(DFtype arg_a)
{
    fp_number_type a;
    FLO_union_type au;
    au.value = arg_a;
    func_0011BE88(&au, &a);
    if (iszero_(&a)) return 0;
    if (isnan_(&a)) return 0;
    if (a.sign) return 0;
    if (isinf_(&a)) return 0xffffffff;
    if (a.normal_exp < 0) return 0;
    if (a.normal_exp > 31) return 0xffffffff;
    else if (a.normal_exp > 60)
        return a.fraction.ll << (a.normal_exp - 60);
    else
        return a.fraction.ll >> (60 - a.normal_exp);
}