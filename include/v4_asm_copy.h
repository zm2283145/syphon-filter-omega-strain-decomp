#ifndef V4_ASM_COPY_H
#define V4_ASM_COPY_H
/* 16-byte quad copies in retail's unfolded form (addiu rX,base,off ; lq/sq 0(rX)).
 * The lq sits in a .set noreorder region, so the peephole cannot fold the
 * materialised address into the offset; the sq is left schedulable (it can
 * move into a branch delay slot). Peephole stays ON for the rest of the function.
 * Works in C and C++ mode. */
static inline void V4Copy(void* d, const void* s) {
    __int128 t;
    asm {
        .set noreorder
        lq t, 0(s)
        .set reorder
        sq t, 0(d)
    }
}
/* lq/sq both fixed (sq cannot be scheduled into a delay slot). */
static inline void V4CopyNR(void* d, const void* s) {
    __int128 t;
    asm {
        .set noreorder
        lq t, 0(s)
        sq t, 0(d)
        .set reorder
    }
}
static inline __int128 V4Load(const void* s) {
    __int128 t;
    asm {
        .set noreorder
        lq t, 0(s)
        .set reorder
    }
    return t;
}
static inline void V4Store(void* d, __int128 t) {
    asm {
        .set noreorder
        sq t, 0(d)
        .set reorder
    }
}
static inline void V4StoreZero(void* d) {
    asm {
        .set noreorder
        sq zero, 0(d)
        .set reorder
    }
}
/* sqc2 vf0 (identity w=1) into *d. */
static inline void V4StoreVF0(void* d) {
    asm {
        .set noreorder
        sqc2 vf0, 0(d)
        .set reorder
    }
}
#endif