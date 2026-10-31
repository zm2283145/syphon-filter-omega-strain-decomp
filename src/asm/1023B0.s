.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel func_001023B0
    lq         $s0, 0x120($a0)
    lq         $s1, 0x130($a0)
    lq         $s2, 0x140($a0)
    lq         $s3, 0x150($a0)
    lq         $s4, 0x160($a0)
    lq         $s5, 0x170($a0)
    lq         $s6, 0x180($a0)
    lq         $s7, 0x190($a0)
    lq         $fp, 0x200($a0)
    lwc1       $f20, 0x288($a0)
    lwc1       $f21, 0x28C($a0)
    lwc1       $f22, 0x290($a0)
    lwc1       $f23, 0x294($a0)
    lwc1       $f24, 0x298($a0)
    lwc1       $f25, 0x29C($a0)
    lwc1       $f26, 0x2A0($a0)
    lwc1       $f27, 0x2A4($a0)
    lwc1       $f28, 0x2A8($a0)
    lwc1       $f29, 0x2AC($a0)
    lwc1       $f30, 0x2B0($a0)
    lwc1       $f31, 0x2B4($a0)
    lw         $sp, 0x1C($a0)
    lw         $v0, 0x224($a0)
    jr         $a2
    sub       $sp, $sp, $v0 /* handwritten instruction */
endlabel func_001023B0
    nop
    nop
    nop


glabel func_00102420
    paddub     $v0, $sp, $zero
    addiu      $sp, $sp, -0x2C0
    sq         $s0, 0x120($sp)
    sq         $s1, 0x130($sp)
    sq         $s2, 0x140($sp)
    sq         $s3, 0x150($sp)
    sq         $s4, 0x160($sp)
    sq         $s5, 0x170($sp)
    sq         $s6, 0x180($sp)
    sq         $s7, 0x190($sp)
    sq         $fp, 0x200($sp)
    swc1       $f20, 0x288($sp)
    swc1       $f21, 0x28C($sp)
    swc1       $f22, 0x290($sp)
    swc1       $f23, 0x294($sp)
    swc1       $f24, 0x298($sp)
    swc1       $f25, 0x29C($sp)
    swc1       $f26, 0x2A0($sp)
    swc1       $f27, 0x2A4($sp)
    swc1       $f28, 0x2A8($sp)
    swc1       $f29, 0x2AC($sp)
    swc1       $f30, 0x2B0($sp)
    swc1       $f31, 0x2B4($sp)
    sw         $v0, 0x14($sp)
    sw         $v0, 0x1C($sp)
    sw         $ra, 0x10($sp)
    sw         $a0, 0x0($sp)
    sw         $a1, 0x4($sp)
    sw         $a2, 0x8($sp)
    jal        func_00100D60
    paddub    $a0, $sp, $zero
endlabel func_00102420
    nop
