.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel _sceIDC
    lui        $a3, (0xFFFFF000 >> 16)
    daddu      $a2, $zero, $zero
    ori        $a3, $a3, (0xFFFFF000 & 0xFFFF)
    nop
  .L0010DB00:
    sync
    cache      0x10, 0x0($a2) /* handwritten instruction */
    sync
    mfc0       $v0, $28 /* handwritten instruction */
    and        $v0, $v0, $a3
    addu       $v0, $v0, $a2
    sltu       $v1, $a1, $v0
    sltu       $v0, $v0, $a0
    bnez       $v0, .L0010DB3C
    nop
    bnez       $v1, .L0010DB3C
    nop
    sync
    cache      0x16, 0x0($a2) /* handwritten instruction */
    sync
  .L0010DB3C:
    sync
    cache      0x10, 0x1($a2) /* handwritten instruction */
    sync
    mfc0       $v0, $28 /* handwritten instruction */
    and        $v0, $v0, $a3
    addu       $v0, $v0, $a2
    sltu       $v1, $a1, $v0
    sltu       $v0, $v0, $a0
    bnez       $v0, .L0010DB78
    nop
    bnez       $v1, .L0010DB78
    nop
    sync
    cache      0x16, 0x1($a2) /* handwritten instruction */
    sync
  .L0010DB78:
    sync
    addiu      $a2, $a2, 0x40
    slti       $v0, $a2, 0x1000
    bnez       $v0, .L0010DB00
    nop
    jr         $ra
    nop
endlabel _sceIDC
    nop
