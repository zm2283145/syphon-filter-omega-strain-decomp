.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel GetEntryAddress_void
    addiu      $v1, $zero, 0x5B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetEntryAddress_void

/* Handwritten function */

glabel setup_void
    addiu      $v1, $zero, 0x74
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel setup_void
