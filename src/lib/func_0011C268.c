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
extern unsigned long UInt64_Multiply(unsigned long a, unsigned long b) __attribute__((const));
static __inline__ fp_number_type* _fpmul_parts(fp_number_type* a, fp_number_type* b, fp_number_type* tmp)
{
    fractype low = 0;
    fractype high = 0;
    if (isnan_(a)) { a->sign = a->sign != b->sign; return a; }
    if (isnan_(b)) { b->sign = a->sign != b->sign; return b; }
    if (isinf_(a)) { if (iszero_(b)) return nan_(); a->sign = a->sign != b->sign; return a; }
    if (isinf_(b)) { if (iszero_(a)) { return nan_(); } b->sign = a->sign != b->sign; return b; }
    if (iszero_(a)) { a->sign = a->sign != b->sign; return a; }
    if (iszero_(b)) { b->sign = a->sign != b->sign; return b; }
    {
        unsigned long nl = a->fraction.ll & 0xffffffff;
        unsigned long nh = a->fraction.ll >> 32;
        unsigned long ml = b->fraction.ll & 0xffffffff;
        unsigned long mh = b->fraction.ll >> 32;
        unsigned long pp_ll = UInt64_Multiply(ml, nl);
        unsigned long pp_hl = UInt64_Multiply(mh, nl);
        unsigned long pp_lh = UInt64_Multiply(ml, nh);
        unsigned long pp_hh = UInt64_Multiply(mh, nh);
        unsigned long res2 = 0;
        unsigned long res0 = 0;
        unsigned long ps_hh__ = pp_hl + pp_lh;
        if (ps_hh__ < pp_hl)
            res2 += 0x100000000LL;
        pp_hl = (ps_hh__ << 32) & 0xffffffff00000000LL;
        res0 = pp_ll + pp_hl;
        if (res0 < pp_ll)
            res2++;
        res2 += ((ps_hh__ >> 32) & 0xffffffffL) + pp_hh;
        high = res2;
        low = res0;
    }
    tmp->normal_exp = a->normal_exp + b->normal_exp;
    tmp->sign = a->sign != b->sign;
    tmp->normal_exp += 4;
    while (high >= ((fractype)1 << 61)) {
        tmp->normal_exp++;
        if (high & 1) {
            low >>= 1;
            low |= (fractype)1 << 63;
        }
        high >>= 1;
    }
    while (high < ((fractype)1 << 60)) {
        tmp->normal_exp--;
        high <<= 1;
        if (low & ((fractype)1 << 63))
            high |= 1;
        low <<= 1;
    }
    tmp->fraction.ll = high;
    tmp->class = CLASS_NUMBER;
    return tmp;
}
DFtype func_0011C268(DFtype arg_a, DFtype arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type* res;
    FLO_union_type au, bu;
    au.value = arg_a;
    bu.value = arg_b;
    func_0011BE88(&au, &a);
    func_0011BE88(&bu, &b);
    res = _fpmul_parts(&a, &b, &tmp);
    return func_0011BDB0(res);
}