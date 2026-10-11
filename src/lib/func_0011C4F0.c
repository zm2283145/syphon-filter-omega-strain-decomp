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
extern fp_number_type D_00499270;
static __inline__ fp_number_type* nan_(void) { return &D_00499270; }
static __inline__ fp_number_type* _fpdiv_parts(fp_number_type* a, fp_number_type* b)
{
    fractype bit;
    fractype numerator;
    fractype denominator;
    fractype quotient;
    if (isnan_(a)) { return a; }
    if (isnan_(b)) { return b; }
    a->sign = a->sign ^ b->sign;
    if (isinf_(a) || iszero_(a)) {
        if (a->class == b->class)
            return nan_();
        return a;
    }
    if (isinf_(b)) {
        a->fraction.ll = 0;
        a->normal_exp = 0;
        return a;
    }
    if (iszero_(b)) {
        a->class = CLASS_INFINITY;
        return a;
    }
    {
        a->normal_exp = a->normal_exp - b->normal_exp;
        numerator = a->fraction.ll;
        denominator = b->fraction.ll;
        if (numerator < denominator) {
            numerator *= 2;
            a->normal_exp--;
        }
        bit = (fractype)1 << 60;
        quotient = 0;
        while (bit) {
            if (numerator >= denominator) {
                quotient |= bit;
                numerator -= denominator;
            }
            bit >>= 1;
            numerator *= 2;
        }
        a->fraction.ll = quotient;
        return (a);
    }
}
DFtype func_0011C4F0(DFtype arg_a, DFtype arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type* res;
    func_0011BE88((FLO_union_type*)&arg_a, &a);
    func_0011BE88((FLO_union_type*)&arg_b, &b);
    res = _fpdiv_parts(&a, &b);
    return func_0011BDB0(res);
}