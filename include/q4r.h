#ifndef Q4R_COPY_H
#define Q4R_COPY_H
/* 64-byte copy, two quads alternating; the last sq is left schedulable
 * (it can fall into a branch/jr delay slot). Temps are passed in so the
 * caller's declaration order picks their registers (vc1). */
#define Q4COPY_R(d, s, qa, qb) \
    asm { .set noreorder; lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); .set reorder; sq qb, 0x30(d) }
#define Q4COPY_N(d, s, qa, qb) \
    asm { .set noreorder; lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d); .set reorder }
#endif