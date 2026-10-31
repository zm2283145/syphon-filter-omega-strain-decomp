.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel sceSifWriteBackDCache
    lui        $t9, (0xFFFFFFC0 >> 16)
    ori        $t9, $t9, (0xFFFFFFC0 & 0xFFFF)
    blez       $a1, .L0010FBB4
    addu      $t2, $a0, $a1
    and        $t0, $a0, $t9
    addiu      $t2, $t2, -0x1
    and        $t1, $t2, $t9
    subu       $t2, $t1, $t0
    srl        $t3, $t2, 6
    addiu      $t3, $t3, 0x1
    andi       $t1, $t3, 0x7
    beqz       $t1, .L0010FB60
    srl       $t2, $t3, 3
  .L0010FB44:
    sync
    cache      0x18, 0x0($t0) /* handwritten instruction */
    sync
    nop
    addiu      $t1, $t1, -0x1
    bgtz       $t1, .L0010FB44
    addiu     $t0, $t0, 0x40
  .L0010FB60:
    beqz       $t2, .L0010FBB4
  .L0010FB64:
    addiu     $t2, $t2, -0x1
    sync
    cache      0x18, 0x0($t0) /* handwritten instruction */
    sync
    cache      0x18, 0x40($t0) /* handwritten instruction */
    sync
    cache      0x18, 0x80($t0) /* handwritten instruction */
    sync
    cache      0x18, 0xC0($t0) /* handwritten instruction */
    sync
    cache      0x18, 0x100($t0) /* handwritten instruction */
    sync
    cache      0x18, 0x140($t0) /* handwritten instruction */
    sync
    cache      0x18, 0x180($t0) /* handwritten instruction */
    sync
    cache      0x18, 0x1C0($t0) /* handwritten instruction */
    sync
    bgtz       $t2, .L0010FB64
    addiu     $t0, $t0, 0x200
  .L0010FBB4:
    jr         $ra
    nop
endlabel sceSifWriteBackDCache
