.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel _sceSDC
    lui        $a3, (0xFFFFF000 >> 16)
    daddu      $a2, $zero, $zero
    ori        $a3, $a3, (0xFFFFF000 & 0xFFFF)
    nop
  .L0010D9C0:
    sync
    cache      0x10, 0x0($a2) /* handwritten instruction */
    sync
    mfc0       $v0, $28 /* handwritten instruction */
    and        $v0, $v0, $a3
    addu       $v0, $v0, $a2
    sltu       $v1, $a1, $v0
    sltu       $v0, $v0, $a0
    bnez       $v0, .L0010D9FC
    nop
    bnez       $v1, .L0010D9FC
    nop
    sync
    cache      0x14, 0x0($a2) /* handwritten instruction */
    sync
  .L0010D9FC:
    sync
    cache      0x10, 0x1($a2) /* handwritten instruction */
    sync
    mfc0       $v0, $28 /* handwritten instruction */
    and        $v0, $v0, $a3
    addu       $v0, $v0, $a2
    sltu       $v1, $a1, $v0
    sltu       $v0, $v0, $a0
    bnez       $v0, .L0010DA38
    nop
    bnez       $v1, .L0010DA38
    nop
    sync
    cache      0x14, 0x1($a2) /* handwritten instruction */
    sync
  .L0010DA38:
    sync
    addiu      $a2, $a2, 0x40
    slti       $v0, $a2, 0x1000
    bnez       $v0, .L0010D9C0
    nop
    jr         $ra
    nop
endlabel _sceSDC
    nop
