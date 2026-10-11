#ifndef Q4_ASM_COPY_H
#define Q4_ASM_COPY_H
/* 64-byte copy, two quads alternating (retail matrix copy form). */
static inline void Q4Copy(void* d, void* s) {
    __int128 qa, qb;
    asm {
        .set noreorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(d)
        lq qa, 0x20(s)
        sq qb, 0x10(d)
        lq qb, 0x30(s)
        sq qa, 0x20(d)
        sq qb, 0x30(d)
        .set reorder
    }
}
#endif
