.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel SetT2
    mfc0       $v1, $12 /* handwritten instruction */
    lui        $v0, (0x10000 >> 16)
    and        $v1, $v1, $v0
    beqz       $v1, .L00116A3C
    lui       $a2, (0x10000 >> 16)
    nop
  .L00116A18:
    di /* handwritten instruction */
    sync.p
    mfc0       $v0, $12 /* handwritten instruction */
    and        $v0, $v0, $a2
    nop
    nop
    nop
    bnez       $v0, .L00116A18
    nop
  .L00116A3C:
    mfc0       $v0, $12 /* handwritten instruction */
    sync.p
    ori        $v0, $v0, 0x6
    xori       $v0, $v0, 0x2
    or         $v0, $v0, $v1
    mtc0       $v0, $12 /* handwritten instruction */
    sync.p
    sw         $a1, 0x0($a0)
    mtc0       $ra, $30 /* handwritten instruction */
    sync.p
    eret /* handwritten instruction */
    jr         $ra
    nop
endlabel SetT2
