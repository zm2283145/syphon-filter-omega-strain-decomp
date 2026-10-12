#ifndef FP_BIT_DF_H
#define FP_BIT_DF_H

/*
 * libgcc fp-bit.c types for the double-precision soft-float routines
 * (dpadd/dpsub/dpmul/dptoli/pack_d/unpack_d..., src/lib 0x0011BDB0-0x0011C9FF,
 * 14 files). ee-gcc 2.96 only (fractype is the 64-bit `unsigned long`).
 */
typedef unsigned long fractype;
typedef unsigned int halffractype;
typedef double DFtype;

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union {
        fractype ll;
        halffractype l[2];
    } fraction;
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

#endif /* FP_BIT_DF_H */
