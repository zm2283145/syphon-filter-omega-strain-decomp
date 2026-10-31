.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel setup_void_4
    addiu      $v1, $zero, 0x74
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel setup_void_4
