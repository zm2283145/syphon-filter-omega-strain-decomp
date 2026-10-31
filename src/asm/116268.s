.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel Copy_void_2
    addiu      $v1, $zero, 0x5A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel Copy_void_2
