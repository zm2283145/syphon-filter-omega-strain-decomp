.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel EIntr
    mfc0       $v0, $12 /* handwritten instruction */
    lui        $v1, (0x10000 >> 16)
    and        $v0, $v0, $v1
    ei /* handwritten instruction */
    jr         $ra
    sltu      $v0, $zero, $v0
endlabel EIntr
