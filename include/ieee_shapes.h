#ifndef IEEE_SHAPES_H
#define IEEE_SHAPES_H

/*
 * fdlibm word-access unions and macros (math_private.h style, little-endian
 * EE) used by the libm functions in src/lib (~30 files re-derive them).
 * Plain C; ee-gcc 2.96 (-G0) and MW alike. Each macro is #ifndef-guarded.
 */
typedef union {
    float value;
    unsigned int word;
} ieee_float_shape_type;

typedef union {
    double value;
    struct {
        unsigned int lsw;
        unsigned int msw;
    } parts;
} ieee_double_shape_type;

#ifndef GET_FLOAT_WORD
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#endif
#ifndef SET_FLOAT_WORD
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#endif
#ifndef EXTRACT_WORDS
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#endif
#ifndef GET_HIGH_WORD
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#endif
#ifndef GET_LOW_WORD
#define GET_LOW_WORD(i,d) do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#endif
#ifndef INSERT_WORDS
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)
#endif
#ifndef SET_HIGH_WORD
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#endif
#ifndef SET_LOW_WORD
#define SET_LOW_WORD(d,v) do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)
#endif

#endif /* IEEE_SHAPES_H */
