.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel iSetTLBEntry
    addiu      $v1, $zero, -0x56
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iSetTLBEntry

/* Handwritten function */

glabel GetTLBEntry
    addiu      $v1, $zero, 0x57
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetTLBEntry

/* Handwritten function */

glabel iGetTLBEntry
    addiu      $v1, $zero, -0x57
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iGetTLBEntry

/* Handwritten function */

glabel ProbeTLBEntry
    addiu      $v1, $zero, 0x58
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ProbeTLBEntry

/* Handwritten function */

glabel iProbeTLBEntry
    addiu      $v1, $zero, -0x58
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iProbeTLBEntry

/* Handwritten function */

glabel ExpandScratchPad
    addiu      $v1, $zero, 0x59
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ExpandScratchPad
