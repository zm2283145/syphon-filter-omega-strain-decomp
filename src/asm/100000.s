.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"



glabel cActivateBodyTossMsg_v06
    nop
endlabel cActivateBodyTossMsg_v06
    nop

/* Handwritten function */

glabel _start
    padduw     $at, $zero, $zero
    padduw     $v0, $zero, $zero
    padduw     $v1, $zero, $zero
    padduw     $a0, $zero, $zero
    padduw     $a1, $zero, $zero
    padduw     $a2, $zero, $zero
    padduw     $a3, $zero, $zero
    padduw     $t0, $zero, $zero
    padduw     $t1, $zero, $zero
    padduw     $t2, $zero, $zero
    padduw     $t3, $zero, $zero
    padduw     $t4, $zero, $zero
    padduw     $t5, $zero, $zero
    padduw     $t6, $zero, $zero
    padduw     $t7, $zero, $zero
    padduw     $s0, $zero, $zero
    padduw     $s1, $zero, $zero
    padduw     $s2, $zero, $zero
    padduw     $s3, $zero, $zero
    padduw     $s4, $zero, $zero
    padduw     $s5, $zero, $zero
    padduw     $s6, $zero, $zero
    padduw     $s7, $zero, $zero
    padduw     $t8, $zero, $zero
    padduw     $t9, $zero, $zero
    padduw     $gp, $zero, $zero
    padduw     $sp, $zero, $zero
    padduw     $fp, $zero, $zero
    padduw     $ra, $zero, $zero
    mthi       $zero
    mthi1      $zero
    mtlo       $zero
    mtlo1      $zero
    mtsah      $zero, 0x0
    mtc1       $zero, $f0
    mtc1       $zero, $f1
    mtc1       $zero, $f2
    mtc1       $zero, $f3
    mtc1       $zero, $f4
    mtc1       $zero, $f5
    mtc1       $zero, $f6
    mtc1       $zero, $f7
    mtc1       $zero, $f8
    mtc1       $zero, $f9
    mtc1       $zero, $f10
    mtc1       $zero, $f11
    mtc1       $zero, $f12
    mtc1       $zero, $f13
    mtc1       $zero, $f14
    mtc1       $zero, $f15
    mtc1       $zero, $f16
    mtc1       $zero, $f17
    mtc1       $zero, $f18
    mtc1       $zero, $f19
    mtc1       $zero, $f20
    mtc1       $zero, $f21
    mtc1       $zero, $f22
    mtc1       $zero, $f23
    mtc1       $zero, $f24
    mtc1       $zero, $f25
    mtc1       $zero, $f26
    mtc1       $zero, $f27
    mtc1       $zero, $f28
    mtc1       $zero, $f29
    mtc1       $zero, $f30
    mtc1       $zero, $f31
    adda.s     $f0, $f1
    sync.p
    ctc1       $zero, $31
    lui        $v0, %hi(D_004E1D80)
    lui        $v1, %hi(D_598980)
    addiu      $v0, $v0, %lo(D_004E1D80)
    addiu      $v1, $v1, %lo(D_598980)
  alabel func_0010012C
    andi       $a0, $v0, 0xF
    beqz       $a0, .L0010014C
    nop
    sb         $zero, 0x0($v0)
    addiu      $v0, $v0, 0x1
    nop
    j          func_0010012C
    nop
  .L0010014C:
    lui        $a0, (0xFFFFFFF0 >> 16)
    ori        $a0, $a0, (0xFFFFFFF0 & 0xFFFF)
    and        $a0, $v1, $a0
  alabel func_00100158
    beq        $v0, $a0, func_00100178
    nop
    sq         $zero, 0x0($v0)
    addiu      $v0, $v0, 0x10
    nop
    nop
    j          func_00100158
    nop
  alabel func_00100178
    beq        $v0, $v1, .L00100198
    nop
    sb         $zero, 0x0($v0)
    addiu      $v0, $v0, 0x1
    nop
    nop
    j          func_00100178
    nop
  .L00100198:
    lui        $a0, %hi(D_004E9B70)
    lui        $a1, %hi(D_1FF0000)
    lui        $a2, 0x1
    lui        $a3, %hi(D_00533400)
    lui        $t0, %hi(func_00100220)
    addiu      $a0, $a0, %lo(D_004E9B70)
    addiu      $a1, $a1, %lo(D_1FF0000)
    addiu      $a2, $a2, (0x10000 & 0xFFFF)
    addiu      $a3, $a3, %lo(D_00533400)
    addiu      $t0, $t0, %lo(func_00100220)
    or         $gp, $a0, $zero
    addiu      $v1, $zero, 0x3C
    syscall    0 /* handwritten instruction */
    or         $sp, $v0, $zero
    lui        $a0, %hi(D_598980)
    lui        $a1, (0x0 >> 16)
    addiu      $a0, $a0, %lo(D_598980)
    addiu      $a1, $a1, -0x1
    addiu      $v1, $zero, 0x3D
    syscall    0 /* handwritten instruction */
    jal        _InitSys
    nop
    jal        FlushCache
    or        $a0, $zero, $zero
    ei /* handwritten instruction */
    lui        $v0, %hi(D_00533400)
    addiu      $v0, $v0, %lo(D_00533400)
    lw         $a0, 0x0($v0)
    jal        Game_ParseCommandLine
    addiu     $a1, $v0, 0x4
    j          Libc_Exit
    or        $a0, $v0, $zero
endlabel _start
