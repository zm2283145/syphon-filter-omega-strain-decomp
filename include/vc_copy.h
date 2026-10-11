#ifndef VC_COPY_H
#define VC_COPY_H
/* Freely scheduled unfolded quad copies (vc1).
 * MW asm blocks default to noreorder: an instruction in a plain asm block is
 * not folded by the peephole (addiu rX,base,off stays, access uses 0(rX)).
 * `.set reorder` inside the block lets the scheduler move the instruction
 * (lq above the address addiu, sq into a jr/jal delay slot).
 * Declare the destination/source pointer locals in retail's register order. */
static inline __int128 VLoadF(const void* s) {
    __int128 t;
    asm { .set reorder; lq t, 0(s) }
    return t;
}
static inline void VStoreN(void* d, __int128 t) {
    asm { sq t, 0(d) }
}
static inline void VStoreF(void* d, __int128 t) {
    asm { .set reorder; sq t, 0(d) }
}
/* lq free, sq unfolded */
static inline void VCopyF(void* d, const void* s) {
    __int128 t;
    asm { .set reorder; lq t, 0(s) }
    asm { sq t, 0(d) }
}
/* both free */
static inline void VCopyFF(void* d, const void* s) {
    __int128 t;
    asm { .set reorder; lq t, 0(s) }
    asm { .set reorder; sq t, 0(d) }
}
static inline void VZeroF(void* d) {
    asm { .set reorder; sq zero, 0(d) }
}
#endif