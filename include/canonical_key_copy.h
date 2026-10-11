#ifndef CANONICAL_KEY_COPY_H
#define CANONICAL_KEY_COPY_H
/* Inlined CanonicalKey construction (48-byte key): copy up to 47 chars then NUL-pad,
   or quad-zero the key when the source is NULL. Needs #pragma opt_rotateloops off and
   #pragma opt_common_subs off on the enclosing function.
   The empty asm block in the then-arm keeps it as a separate (empty) block, so the
   hoisted ckc_c = 0 lands in the beqz delay slot and the jump over the load keeps a nop. */
static inline void ckc_qzero(void* dd, int nn)
{
    int n = nn; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}

#define CKC_COPY(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i; \
        for (ckc_i = 0; ckc_i < 0x2F; ckc_i++) { \
            if ((src)[ckc_i] == 0) ckc_end = 1; \
            { char ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = (src)[ckc_i]; (dst)[ckc_i] = ckc_c; } \
        } \
        (dst)[ckc_i] = 0; \
    }

/* Variant with the source pointer in its own local (declared last, so it gets the
   lowest register); used when the source is a global string (no NULL test). */
#define CKC_COPY_S(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            ckc_c = 0; \
            if (ckc_end) asm { .set reorder } else ckc_c = ckc_s[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }

#define CANONICAL_KEY_INIT(dst, src) \
    if (src) CKC_COPY(dst, src) else ckc_qzero((dst), 3);

/* Index-first address form (addu v0, i, src), seen when src lives in an s-register. */
#define CKC_COPY_IX(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i; \
        for (ckc_i = 0; ckc_i < 0x2F; ckc_i++) { \
            if (*(char*)(ckc_i + (int)(src)) == 0) ckc_end = 1; \
            { char ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = *(char*)(ckc_i + (int)(src)); (dst)[ckc_i] = ckc_c; } \
        } \
        (dst)[ckc_i] = 0; \
    }

#define CANONICAL_KEY_INIT_IX(dst, src) \
    if (src) CKC_COPY_IX(dst, src) else ckc_qzero((dst), 3);

#endif

