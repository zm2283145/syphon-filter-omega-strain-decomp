.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel setup_void_5
    addiu      $v1, $zero, 0x74
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel setup_void_5

/* Handwritten function */

glabel Copy_void_5
    addiu      $v1, $zero, 0x5A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel Copy_void_5
