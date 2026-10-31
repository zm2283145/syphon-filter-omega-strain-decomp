.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"



glabel func_002F1C38
    addiu      $sp, $sp, -0x40
    sq         $t2, 0x30($sp)
    sq         $t1, 0x20($sp)
    sq         $t0, 0x10($sp)
    sq         $v1, 0x0($sp)
    addiu      $v0, $zero, 0x400
    addiu      $t1, $zero, 0x20
    addiu      $t2, $a0, 0x7C
  .L002F1C58:
    lwu        $a0, 0x0($t2)
    addiu      $t2, $t2, -0x4
    bnez       $a0, .L002F1C80
    nop
    addiu      $t1, $t1, -0x1
    addiu      $v0, $v0, -0x20
    bnel       $t1, $zero, .L002F1C58
    nop
    b          .L002F1C9C
    nop
  .L002F1C80:
    lui        $t0, (0x80000000 >> 16)
    and        $v1, $a0, $t0
    bnez       $v1, .L002F1C9C
    nop
    plzcw      $t0, $a0
    addiu      $v0, $v0, -0x1
    subu       $v0, $v0, $t0
  .L002F1C9C:
    lq         $v1, 0x0($sp)
    lq         $t0, 0x10($sp)
    lq         $t1, 0x20($sp)
    lq         $t2, 0x30($sp)
    addiu      $sp, $sp, 0x40
    jr         $ra
    nop
endlabel func_002F1C38


glabel IsGreater
    addiu      $sp, $sp, -0x30
    sq         $v1, 0x0($sp)
    sq         $t0, 0x10($sp)
    sq         $t1, 0x20($sp)
    addiu      $v1, $zero, 0x20
    addiu      $a0, $a0, 0x7C
    addiu      $a1, $a1, 0x7C
    b          .L002F1CDC
    nop
  .L002F1CDC:
    lwu        $t0, 0x0($a0)
    lwu        $t1, 0x0($a1)
    addiu      $v1, $v1, -0x1
    sltu       $v0, $t1, $t0
    addiu      $a0, $a0, -0x4
    bgtz       $v0, .L002F1D14
    nop
    sltu       $v0, $t0, $t1
    addiu      $a1, $a1, -0x4
    bgtz       $v0, .L002F1D10
    nop
    bgtz       $v1, .L002F1CDC
    nop
  .L002F1D10:
    or         $v0, $zero, $zero
  .L002F1D14:
    lq         $t1, 0x20($sp)
    lq         $t0, 0x10($sp)
    lq         $v1, 0x0($sp)
    addiu      $sp, $sp, 0x30
    jr         $ra
    nop
endlabel IsGreater


glabel IsSmaller
    addiu      $sp, $sp, -0x30
    sq         $v1, 0x0($sp)
    sq         $t0, 0x10($sp)
    sq         $t1, 0x20($sp)
    addiu      $v1, $zero, 0x20
    addiu      $a0, $a0, 0x7C
    addiu      $a1, $a1, 0x7C
    b          .L002F1D7C
    nop
  .L002F1D50:
    lwu        $t0, 0x0($a0)
    lwu        $t1, 0x0($a1)
    addiu      $v1, $v1, -0x1
    sltu       $v0, $t0, $t1
    addiu      $a0, $a0, -0x4
    bgtz       $v0, .L002F1D88
    nop
    sltu       $v0, $t1, $t0
    addiu      $a1, $a1, -0x4
    bgtz       $v0, .L002F1D84
    nop
  .L002F1D7C:
    bgtz       $v1, .L002F1D50
    nop
  .L002F1D84:
    or         $v0, $zero, $zero
  .L002F1D88:
    lq         $t1, 0x20($sp)
    lq         $t0, 0x10($sp)
    lq         $v1, 0x0($sp)
    addiu      $sp, $sp, 0x30
    jr         $ra
    nop
endlabel IsSmaller


glabel IsNotGreater
    addiu      $sp, $sp, -0x30
    sq         $v1, 0x0($sp)
    sq         $t0, 0x10($sp)
    sq         $t1, 0x20($sp)
    addiu      $v1, $zero, 0x20
    addiu      $a0, $a0, 0x7C
    addiu      $a1, $a1, 0x7C
    b          .L002F1DC4
    nop
  .L002F1DC4:
    lwu        $t0, 0x0($a0)
    lwu        $t1, 0x0($a1)
    addiu      $v1, $v1, -0x1
    sltu       $v0, $t0, $t1
    addiu      $a0, $a0, -0x4
    bgtz       $v0, .L002F1E08
    nop
    sltu       $v0, $t1, $t0
    addiu      $a1, $a1, -0x4
    bgtz       $v0, .L002F1E04
    nop
    bgtz       $v1, .L002F1DC4
    nop
    ori        $v0, $zero, 0x1
    b          .L002F1E08
    nop
  .L002F1E04:
    or         $v0, $zero, $zero
  .L002F1E08:
    lq         $t1, 0x20($sp)
    lq         $t0, 0x10($sp)
    lq         $v1, 0x0($sp)
    addiu      $sp, $sp, 0x30
    jr         $ra
    nop
endlabel IsNotGreater


glabel IsNotSmaller
    addiu      $sp, $sp, -0x30
    sq         $v1, 0x0($sp)
    sq         $t0, 0x10($sp)
    sq         $t1, 0x20($sp)
    addiu      $v1, $zero, 0x20
    addiu      $a0, $a0, 0x7C
    addiu      $a1, $a1, 0x7C
    b          .L002F1E44
    nop
  .L002F1E44:
    lwu        $t0, 0x0($a0)
    lwu        $t1, 0x0($a1)
    addiu      $v1, $v1, -0x1
    sltu       $v0, $t1, $t0
    addiu      $a0, $a0, -0x4
    bgtz       $v0, .L002F1E88
    nop
    sltu       $v0, $t0, $t1
    addiu      $a1, $a1, -0x4
    bgtz       $v0, .L002F1E84
    nop
    bgtz       $v1, .L002F1E44
    nop
    ori        $v0, $zero, 0x1
    b          .L002F1E88
    nop
  .L002F1E84:
    or         $v0, $zero, $zero
  .L002F1E88:
    lq         $t1, 0x20($sp)
    lq         $t0, 0x10($sp)
    lq         $v1, 0x0($sp)
    addiu      $sp, $sp, 0x30
    jr         $ra
    nop
endlabel IsNotSmaller


glabel ShiftRight
    addiu      $sp, $sp, -0x90
    sq         $a0, 0x0($sp)
    sq         $a1, 0x10($sp)
    sq         $a2, 0x20($sp)
    sq         $a3, 0x30($sp)
    sq         $t0, 0x40($sp)
    sq         $t1, 0x50($sp)
    sq         $s0, 0x60($sp)
    sq         $s1, 0x70($sp)
    sq         $s2, 0x80($sp)
    or         $s1, $a0, $zero
    or         $a0, $a1, $zero
    or         $a1, $a0, $zero
    dsll32     $a0, $a0, 27
    dsrl       $a1, $a1, 5
    dsrl32     $a0, $a0, 27
    dsll       $a1, $a1, 2
    or         $t0, $a0, $zero
    addiu      $t1, $zero, 0x20
    dsubu      $t1, $t1, $t0
    daddu      $s2, $s1, $a1
    dsrl       $a1, $a1, 2
    lwu        $a2, 0x0($s2)
    addiu      $s0, $zero, 0x20
    nop
    dsll       $a0, $s0, 2
    nop
    addu       $s1, $s1, $a0
  .L002F1F10:
    addiu      $s1, $s1, -0x4
    lwu        $a0, 0x0($s1)
    bnez       $a0, .L002F1F34
    nop
    addiu      $s0, $s0, -0x1
    bnel       $s0, $a1, .L002F1F10
    nop
    addiu      $s1, $s1, 0x4
    addiu      $s0, $s0, 0x1
  .L002F1F34:
    lq         $s1, 0x0($sp)
    addiu      $s2, $s2, 0x4
    addiu      $s0, $s0, -0x1
    b          .L002F1F70
    nop
  .L002F1F48:
    lwu        $a0, 0x0($s2)
    or         $a3, $a2, $zero
    or         $a2, $a0, $zero
    dsrlv      $a3, $a3, $t0
    dsllv      $a0, $a0, $t1
    addiu      $s0, $s0, -0x1
    or         $a0, $a0, $a3
    addiu      $s2, $s2, 0x4
    sw         $a0, 0x0($s1)
    addiu      $s1, $s1, 0x4
  .L002F1F70:
    bne        $s0, $a1, .L002F1F48
    nop
    dsrlv      $a2, $a2, $t0
    sw         $a2, 0x0($s1)
    or         $a0, $zero, $zero
    b          .L002F1F9C
    nop
  .L002F1F8C:
    addiu      $s1, $s1, 0x4
    addiu      $s0, $s0, -0x1
    sw         $a0, 0x0($s1)
    nop
  .L002F1F9C:
    nop
    bnez       $s0, .L002F1F8C
    nop
    lq         $s2, 0x80($sp)
    lq         $s1, 0x70($sp)
    lq         $s0, 0x60($sp)
    lq         $t1, 0x50($sp)
    lq         $t0, 0x40($sp)
    lq         $a3, 0x30($sp)
    lq         $a2, 0x20($sp)
    lq         $a1, 0x10($sp)
    lq         $a0, 0x0($sp)
    addiu      $sp, $sp, 0x90
    jr         $ra
    nop
endlabel ShiftRight


glabel ShiftLeft
    addiu      $sp, $sp, -0x90
    sq         $a0, 0x0($sp)
    sq         $a1, 0x10($sp)
    sq         $a2, 0x20($sp)
    sq         $a3, 0x30($sp)
    sq         $t0, 0x40($sp)
    sq         $t1, 0x50($sp)
    sq         $s0, 0x60($sp)
    sq         $s1, 0x70($sp)
    sq         $s2, 0x80($sp)
    or         $s1, $a0, $zero
    or         $a0, $a1, $zero
    or         $a1, $a0, $zero
    dsll32     $a0, $a0, 27
    dsrl       $a1, $a1, 5
    dsrl32     $a0, $a0, 27
    dsll       $a1, $a1, 2
    or         $t0, $a0, $zero
    addiu      $s0, $zero, 0x20
    addiu      $t1, $zero, 0x20
    dsll       $s0, $s0, 2
    dsubu      $t1, $t1, $t0
    daddu      $s1, $s1, $s0
    dsrl       $s0, $s0, 2
    dsubu      $s2, $s1, $a1
    dsrl       $a1, $a1, 2
  .L002F2040:
    addiu      $s2, $s2, -0x4
    addiu      $s0, $s0, -0x1
    lwu        $a2, 0x0($s2)
    bnez       $a2, .L002F2064
    nop
    bnel       $s0, $a1, .L002F2040
    nop
    b          .L002F20C0
    nop
  .L002F2064:
    addiu      $at, $zero, 0x1F
    beq        $s0, $at, .L002F207C
    nop
    addiu      $s2, $s2, 0x4
    addiu      $s0, $s0, 0x1
    lwu        $a2, 0x0($s2)
  .L002F207C:
    dsll       $s1, $a1, 2
    addu       $s1, $s1, $s2
    addiu      $s1, $s1, 0x4
    b          .L002F20B8
    nop
  .L002F2090:
    addiu      $s2, $s2, -0x4
    addiu      $s1, $s1, -0x4
    lwu        $a0, 0x0($s2)
    or         $a3, $a2, $zero
    or         $a2, $a0, $zero
    dsllv      $a3, $a3, $t0
    dsrlv      $a0, $a0, $t1
    addiu      $s0, $s0, -0x1
    or         $a0, $a0, $a3
    sw         $a0, 0x0($s1)
  .L002F20B8:
    bne        $s0, $a1, .L002F2090
    nop
  .L002F20C0:
    addiu      $s1, $s1, -0x4
    dsllv      $a2, $a2, $t0
    sw         $a2, 0x0($s1)
    or         $a0, $zero, $zero
    b          .L002F20E8
    nop
  .L002F20D8:
    addiu      $s1, $s1, -0x4
    addiu      $s0, $s0, -0x1
    sw         $a0, 0x0($s1)
    nop
  .L002F20E8:
    nop
    bnez       $s0, .L002F20D8
    nop
    lq         $s2, 0x80($sp)
    lq         $s1, 0x70($sp)
    lq         $s0, 0x60($sp)
    lq         $t1, 0x50($sp)
    lq         $t0, 0x40($sp)
    lq         $a3, 0x30($sp)
    lq         $a2, 0x20($sp)
    lq         $a1, 0x10($sp)
    lq         $a0, 0x0($sp)
    addiu      $sp, $sp, 0x90
    jr         $ra
    nop
endlabel ShiftLeft


glabel lintAddIP
    addiu      $sp, $sp, -0x60
    sq         $a0, 0x0($sp)
    sq         $a1, 0x10($sp)
    sq         $a2, 0x20($sp)
    sq         $s4, 0x30($sp)
    sq         $s5, 0x40($sp)
    sq         $s6, 0x50($sp)
    addiu      $s4, $zero, 0x20
    or         $s5, $a0, $zero
    or         $s6, $a1, $zero
    or         $a0, $zero, $zero
    b          .L002F217C
    nop
  .L002F2158:
    lwu        $a1, 0x0($s5)
    lwu        $a2, 0x0($s6)
    addiu      $s4, $s4, -0x1
    daddu      $a0, $a0, $a1
    addiu      $s5, $s5, 0x4
    daddu      $a0, $a0, $a2
    addiu      $s6, $s6, 0x4
    sw         $a0, -0x4($s5)
    dsrl32     $a0, $a0, 0
  .L002F217C:
    bnez       $s4, .L002F2158
    nop
    lq         $s6, 0x50($sp)
    lq         $s5, 0x40($sp)
    lq         $s4, 0x30($sp)
    lq         $a2, 0x20($sp)
    lq         $a1, 0x10($sp)
    lq         $a0, 0x0($sp)
    addiu      $sp, $sp, 0x60
    jr         $ra
    nop
endlabel lintAddIP


glabel lintAddIPR
    addiu      $sp, $sp, -0x60
    sq         $a0, 0x0($sp)
    sq         $a1, 0x10($sp)
    sq         $a2, 0x20($sp)
    sq         $s4, 0x30($sp)
    sq         $s5, 0x40($sp)
    sq         $s6, 0x50($sp)
    or         $s4, $a2, $zero
    or         $s5, $a0, $zero
    dsrl       $s4, $s4, 5
    or         $s6, $a1, $zero
    addiu      $s4, $s4, 0x1
    or         $a0, $zero, $zero
    sltiu      $v0, $s4, 0x20
    bnez       $v0, .L002F2218
    nop
    addiu      $s4, $zero, 0x20
    b          .L002F2218
    nop
  .L002F21F4:
    lwu        $a1, 0x0($s5)
    lwu        $a2, 0x0($s6)
    addiu      $s4, $s4, -0x1
    daddu      $a0, $a0, $a1
    addiu      $s5, $s5, 0x4
    daddu      $a0, $a0, $a2
    addiu      $s6, $s6, 0x4
    sw         $a0, -0x4($s5)
    dsrl32     $a0, $a0, 0
  .L002F2218:
    bnez       $s4, .L002F21F4
    nop
    lq         $s6, 0x50($sp)
    lq         $s5, 0x40($sp)
    lq         $s4, 0x30($sp)
    lq         $a2, 0x20($sp)
    lq         $a1, 0x10($sp)
    lq         $a0, 0x0($sp)
    addiu      $sp, $sp, 0x60
    jr         $ra
    nop
endlabel lintAddIPR


glabel lintSubIP
    addiu      $sp, $sp, -0x60
    sq         $a0, 0x0($sp)
    sq         $a1, 0x10($sp)
    sq         $a2, 0x20($sp)
    sq         $s4, 0x30($sp)
    sq         $s5, 0x40($sp)
    sq         $s6, 0x50($sp)
    addiu      $s4, $zero, 0x20
    or         $s5, $a0, $zero
    or         $s6, $a1, $zero
    or         $a0, $zero, $zero
    b          .L002F229C
    nop
  .L002F2278:
    lwu        $a1, 0x0($s5)
    lwu        $a2, 0x0($s6)
    addiu      $s4, $s4, -0x1
    daddu      $a0, $a0, $a1
    addiu      $s5, $s5, 0x4
    dsubu      $a0, $a0, $a2
    addiu      $s6, $s6, 0x4
    sw         $a0, -0x4($s5)
    dsra32     $a0, $a0, 0
  .L002F229C:
    bnez       $s4, .L002F2278
    nop
    lq         $s6, 0x50($sp)
    lq         $s5, 0x40($sp)
    lq         $s4, 0x30($sp)
    lq         $a2, 0x20($sp)
    lq         $a1, 0x10($sp)
    lq         $a0, 0x0($sp)
    addiu      $sp, $sp, 0x60
    jr         $ra
    nop
endlabel lintSubIP


glabel lintSubIPR
    addiu      $sp, $sp, -0x60
    sq         $a0, 0x0($sp)
    sq         $a1, 0x10($sp)
    sq         $a2, 0x20($sp)
    sq         $s4, 0x30($sp)
    sq         $s5, 0x40($sp)
    sq         $s6, 0x50($sp)
    or         $s4, $a2, $zero
    or         $s5, $a0, $zero
    dsrl       $s4, $s4, 5
    or         $s6, $a1, $zero
    addiu      $s4, $s4, 0x1
    or         $a0, $zero, $zero
    sltiu      $v0, $s4, 0x20
    bnez       $v0, .L002F2338
    nop
    addiu      $s4, $zero, 0x20
    b          .L002F2338
    nop
  .L002F2314:
    lwu        $a1, 0x0($s5)
    lwu        $a2, 0x0($s6)
    addiu      $s4, $s4, -0x1
    daddu      $a0, $a0, $a1
    addiu      $s5, $s5, 0x4
    dsubu      $a0, $a0, $a2
    addiu      $s6, $s6, 0x4
    sw         $a0, -0x4($s5)
    dsra32     $a0, $a0, 0
  .L002F2338:
    bnez       $s4, .L002F2314
    nop
    lq         $s6, 0x50($sp)
    lq         $s5, 0x40($sp)
    lq         $s4, 0x30($sp)
    lq         $a2, 0x20($sp)
    lq         $a1, 0x10($sp)
    lq         $a0, 0x0($sp)
    addiu      $sp, $sp, 0x60
    jr         $ra
    nop
endlabel lintSubIPR


glabel MODIP
    addiu      $sp, $sp, -0x140
    sq         $s7, 0xB0($sp)
    sq         $s6, 0xA0($sp)
    sq         $s5, 0x90($sp)
    sq         $s4, 0x80($sp)
    sq         $s3, 0x70($sp)
    sq         $s2, 0x60($sp)
    sq         $s1, 0x50($sp)
    sq         $s0, 0x40($sp)
    sq         $ra, 0x30($sp)
    or         $s5, $a0, $zero
    or         $s6, $a1, $zero
    addiu      $s7, $sp, 0xC0
    sw         $s5, 0xC($sp)
    addiu      $v1, $zero, 0x20
    b          .L002F23C4
    nop
  .L002F23A8:
    lq         $a0, 0x0($s6)
    lq         $a1, 0x10($s6)
    addiu      $v1, $v1, -0x8
    addiu      $s6, $s6, 0x20
    sq         $a0, 0x0($s7)
    sq         $a1, 0x10($s7)
    addiu      $s7, $s7, 0x20
  .L002F23C4:
    bnez       $v1, .L002F23A8
    nop
    addiu      $s6, $s6, -0x80
    addiu      $s7, $s7, -0x80
    or         $a0, $s5, $zero
    jal        func_002F1C38
    nop
    sw         $v0, 0x0($sp)
    or         $a0, $s6, $zero
    jal        func_002F1C38
    nop
    sw         $v0, 0x4($sp)
    lwu        $v1, 0x0($sp)
    sw         $v0, 0x8($sp)
    sltu       $v1, $v0, $v1
    beqz       $v1, .L002F24D8
    nop
    lwu        $v1, 0x0($sp)
    or         $s1, $s7, $zero
    subu       $v0, $v1, $v0
    or         $s0, $v1, $zero
    or         $a0, $v0, $zero
    addiu      $s0, $s0, 0x1F
    or         $a1, $a0, $zero
    dsll32     $a0, $a0, 27
    dsrl       $a1, $a1, 5
    dsrl32     $a0, $a0, 27
    dsll       $a1, $a1, 2
    or         $t0, $a0, $zero
    dsrl       $s0, $s0, 5
    addiu      $t1, $zero, 0x20
    dsll       $s0, $s0, 2
    dsubu      $t1, $t1, $t0
    daddu      $s1, $s1, $s0
    dsrl       $s0, $s0, 2
    dsubu      $s2, $s1, $a1
    dsrl       $a1, $a1, 2
    addiu      $s2, $s2, -0x4
    addiu      $s0, $s0, -0x1
    lwu        $a2, 0x0($s2)
    b          .L002F2494
    nop
  .L002F246C:
    addiu      $s2, $s2, -0x4
    addiu      $s1, $s1, -0x4
    lwu        $a0, 0x0($s2)
    or         $a3, $a2, $zero
    or         $a2, $a0, $zero
    dsllv      $a3, $a3, $t0
    dsrlv      $a0, $a0, $t1
    addiu      $s0, $s0, -0x1
    or         $a0, $a0, $a3
    sw         $a0, 0x0($s1)
  .L002F2494:
    bne        $s0, $a1, .L002F246C
    nop
    addiu      $s1, $s1, -0x4
    dsllv      $a2, $a2, $t0
    sw         $a2, 0x0($s1)
    or         $a0, $zero, $zero
    b          .L002F24C4
    nop
  .L002F24B4:
    addiu      $s1, $s1, -0x4
    addiu      $s0, $s0, -0x1
    sw         $a0, 0x0($s1)
    nop
  .L002F24C4:
    nop
    bnez       $s0, .L002F24B4
    nop
    lwu        $a0, 0x0($sp)
    sw         $a0, 0x4($sp)
  .L002F24D8:
    lwu        $a0, 0x0($sp)
    lwu        $a1, 0x4($sp)
    lwu        $a2, 0x8($sp)
    sltu       $v1, $a0, $a2
    bnez       $v1, .L002F2760
    nop
    sltu       $v1, $a0, $a1
    beqz       $v1, .L002F25C0
    nop
    lwu        $a0, 0x0($sp)
    lwu        $a1, 0x4($sp)
    sw         $a0, 0x4($sp)
    subu       $a1, $a1, $a0
    lwu        $s0, 0x4($sp)
    addiu      $s1, $sp, 0xC0
    addiu      $s0, $s0, 0x1F
    or         $a0, $a1, $zero
    dsrl       $s0, $s0, 5
    dsll32     $a0, $a0, 27
    sltiu      $v0, $s0, 0x20
    dsrl       $a1, $a1, 5
    addu       $s0, $s0, $v0
    dsrl32     $a0, $a0, 27
    dsll       $a1, $a1, 2
    or         $t0, $a0, $zero
    addiu      $t1, $zero, 0x20
    dsubu      $t1, $t1, $t0
    daddu      $s2, $s1, $a1
    dsrl       $a1, $a1, 2
    lwu        $a2, 0x0($s2)
    addiu      $s2, $s2, 0x4
    addiu      $s0, $s0, -0x1
    b          .L002F2588
    nop
  .L002F2560:
    lwu        $a0, 0x0($s2)
    or         $a3, $a2, $zero
    or         $a2, $a0, $zero
    dsrlv      $a3, $a3, $t0
    dsllv      $a0, $a0, $t1
    addiu      $s0, $s0, -0x1
    or         $a0, $a0, $a3
    addiu      $s2, $s2, 0x4
    sw         $a0, 0x0($s1)
    addiu      $s1, $s1, 0x4
  .L002F2588:
    bne        $s0, $a1, .L002F2560
    nop
    dsrlv      $a2, $a2, $t0
    sw         $a2, 0x0($s1)
    or         $a0, $zero, $zero
    b          .L002F25B4
    nop
  .L002F25A4:
    addiu      $s1, $s1, 0x4
    addiu      $s0, $s0, -0x1
    sw         $a0, 0x0($s1)
    nop
  .L002F25B4:
    nop
    bnez       $s0, .L002F25A4
    nop
  .L002F25C0:
    lwu        $v1, 0x0($sp)
    lwu        $a0, 0xC($sp)
    addiu      $v1, $v1, -0x1
    addiu      $a1, $sp, 0xC0
    dsrl       $v1, $v1, 5
    dsll       $v0, $v1, 2
    addiu      $v1, $v1, 0x1
    addu       $a0, $a0, $v0
    addu       $a1, $a1, $v0
    b          .L002F2618
    nop
  .L002F25EC:
    lwu        $t0, 0x0($a0)
    lwu        $t1, 0x0($a1)
    addiu      $v1, $v1, -0x1
    sltu       $v0, $t1, $t0
    addiu      $a0, $a0, -0x4
    bgtz       $v0, .L002F2620
    nop
    sltu       $v0, $t0, $t1
    addiu      $a1, $a1, -0x4
    bgtz       $v0, .L002F2684
    nop
  .L002F2618:
    bgtz       $v1, .L002F25EC
    nop
  .L002F2620:
    lwu        $s4, 0x0($sp)
    lwu        $s5, 0xC($sp)
    addiu      $s4, $s4, 0x1F
    addiu      $s6, $sp, 0xC0
    dsrl       $s4, $s4, 5
    or         $a0, $zero, $zero
    b          .L002F2664
    nop
  .L002F2640:
    lwu        $a1, 0x0($s5)
    lwu        $a2, 0x0($s6)
    addiu      $s4, $s4, -0x1
    daddu      $a0, $a0, $a1
    addiu      $s5, $s5, 0x4
    dsubu      $a0, $a0, $a2
    addiu      $s6, $s6, 0x4
    sw         $a0, -0x4($s5)
    dsra32     $a0, $a0, 0
  .L002F2664:
    bnez       $s4, .L002F2640
    nop
    lwu        $a0, 0xC($sp)
    jal        func_002F1C38
    nop
    sw         $v0, 0x0($sp)
    b          .L002F24D8
    nop
  .L002F2684:
    lwu        $a1, 0x4($sp)
    lwu        $a2, 0x8($sp)
    sltu       $v1, $a2, $a1
    beqz       $v1, .L002F2760
    nop
    addiu      $a2, $a1, -0x1
    addiu      $a1, $zero, 0x1
    sw         $a2, 0x4($sp)
    lwu        $s0, 0x4($sp)
    addiu      $s1, $sp, 0xC0
    addiu      $s0, $s0, 0x1F
    or         $a0, $a1, $zero
    dsrl       $s0, $s0, 5
    dsll32     $a0, $a0, 27
    sltiu      $v0, $s0, 0x20
    dsrl       $a1, $a1, 5
    addu       $s0, $s0, $v0
    dsrl32     $a0, $a0, 27
    dsll       $a1, $a1, 2
    or         $t0, $a0, $zero
    addiu      $t1, $zero, 0x20
    dsubu      $t1, $t1, $t0
    daddu      $s2, $s1, $a1
    dsrl       $a1, $a1, 2
    lwu        $a2, 0x0($s2)
    addiu      $s2, $s2, 0x4
    addiu      $s0, $s0, -0x1
    b          .L002F2720
    nop
  .L002F26F8:
    lwu        $a0, 0x0($s2)
    or         $a3, $a2, $zero
    or         $a2, $a0, $zero
    dsrlv      $a3, $a3, $t0
    dsllv      $a0, $a0, $t1
    addiu      $s0, $s0, -0x1
    or         $a0, $a0, $a3
    addiu      $s2, $s2, 0x4
    sw         $a0, 0x0($s1)
    addiu      $s1, $s1, 0x4
  .L002F2720:
    bne        $s0, $a1, .L002F26F8
    nop
    dsrlv      $a2, $a2, $t0
    sw         $a2, 0x0($s1)
    or         $a0, $zero, $zero
    b          .L002F274C
    nop
  .L002F273C:
    addiu      $s1, $s1, 0x4
    addiu      $s0, $s0, -0x1
    sw         $a0, 0x0($s1)
    nop
  .L002F274C:
    nop
    bnel       $s0, $zero, .L002F273C
    nop
    b          .L002F24D8
    nop
  .L002F2760:
    lq         $ra, 0x30($sp)
    lq         $s0, 0x40($sp)
    lq         $s1, 0x50($sp)
    lq         $s2, 0x60($sp)
    lq         $s3, 0x70($sp)
    lq         $s4, 0x80($sp)
    lq         $s5, 0x90($sp)
    lq         $s6, 0xA0($sp)
    lq         $s7, 0xB0($sp)
    addiu      $sp, $sp, 0x140
    jr         $ra
    nop
endlabel MODIP


glabel MULT
    addiu      $sp, $sp, -0x240
    sq         $ra, 0xB0($sp)
    sw         $a0, 0x18($sp)
    sw         $a1, 0x0($sp)
    sw         $a2, 0x4($sp)
    or         $a0, $a1, $zero
    jal        func_002F1C38
    nop
    or         $t9, $v0, $zero
    addiu      $v1, $v0, 0x1F
    srl        $v0, $v1, 5
    sw         $v0, 0x8($sp)
    lwu        $a0, 0x4($sp)
    jal        func_002F1C38
    nop
    addu       $t9, $t9, $v0
    addiu      $v1, $v0, 0x1F
    srl        $v0, $v1, 5
    sw         $v0, 0xC($sp)
    dsrl       $t9, $t9, 5
    addiu      $t9, $t9, 0x1
    sltiu      $v0, $t9, 0x20
    bnez       $v0, .L002F27F4
    nop
    addiu      $t9, $zero, 0x20
  .L002F27F4:
    addiu      $a0, $sp, 0x1C0
    or         $a1, $zero, $zero
    jal        lintSetSmallValue
    nop
    addiu      $a0, $sp, 0xC0
    or         $a1, $zero, $zero
    jal        lintSetSmallValue
    nop
    addiu      $a0, $sp, 0x140
    or         $a1, $zero, $zero
    jal        lintSetSmallValue
    nop
    addiu      $v1, $sp, 0xC0
    sw         $v1, 0x10($sp)
    addiu      $v1, $sp, 0x144
    sw         $v1, 0x14($sp)
    lwu        $t0, 0x0($sp)
    lwu        $t6, 0x8($sp)
    lwu        $t2, 0x10($sp)
    lwu        $t3, 0x14($sp)
    b          .L002F2908
  .L002F2848:
    lwu       $t1, 0x4($sp)
    lwu        $a0, 0x0($t0)
    lwu        $t7, 0xC($sp)
    b          .L002F2884
    nop
  .L002F285C:
    lwu        $a1, 0x0($t1)
    multu      $a0, $a1
    addiu      $t1, $t1, 0x4
    addiu      $t7, $t7, -0x1
    mflo       $v0
    mfhi       $v1
    sw         $v0, 0x0($t2)
    sw         $v1, 0x0($t3)
    addiu      $t2, $t2, 0x4
    addiu      $t3, $t3, 0x4
  .L002F2884:
    bnez       $t7, .L002F285C
    nop
    or         $t1, $t9, $zero
    addiu      $t3, $sp, 0x1C0
    addiu      $t4, $sp, 0xC0
    addiu      $t5, $sp, 0x140
    or         $a0, $zero, $zero
    b          .L002F28D8
    nop
  .L002F28A8:
    lwu        $a1, 0x0($t3)
    lwu        $a2, 0x0($t4)
    lwu        $a3, 0x0($t5)
    addiu      $t1, $t1, -0x1
    daddu      $a0, $a0, $a1
    addiu      $t3, $t3, 0x4
    daddu      $a0, $a0, $a2
    addiu      $t4, $t4, 0x4
    daddu      $a0, $a0, $a3
    addiu      $t5, $t5, 0x4
    sw         $a0, -0x4($t3)
    dsrl32     $a0, $a0, 0
  .L002F28D8:
    bnez       $t1, .L002F28A8
    nop
    lwu        $t2, 0x10($sp)
    lwu        $t3, 0x14($sp)
    sw         $zero, 0x0($t2)
    sw         $zero, 0x0($t3)
    addiu      $t2, $t2, 0x4
    addiu      $t3, $t3, 0x4
    addiu      $t6, $t6, -0x1
    sw         $t2, 0x10($sp)
    sw         $t3, 0x14($sp)
    addiu      $t0, $t0, 0x4
  .L002F2908:
    bnez       $t6, .L002F2848
    nop
    addiu      $t0, $zero, 0x20
    addiu      $t1, $sp, 0x1C0
    lwu        $t2, 0x18($sp)
    b          .L002F2940
    nop
  .L002F2924:
    lq         $a0, 0x0($t1)
    lq         $a1, 0x10($t1)
    addiu      $t0, $t0, -0x8
    addiu      $t1, $t1, 0x20
    sq         $a0, 0x0($t2)
    sq         $a1, 0x10($t2)
    addiu      $t2, $t2, 0x20
  .L002F2940:
    bnez       $t0, .L002F2924
    nop
    lq         $ra, 0xB0($sp)
    addiu      $sp, $sp, 0x240
    jr         $ra
    nop
endlabel MULT


glabel XMOD
    addiu      $sp, $sp, -0x240
    sq         $ra, 0xB0($sp)
    sw         $a0, 0x18($sp)
    sw         $a1, 0x0($sp)
    sw         $a2, 0x4($sp)
    sw         $a3, 0x1C($sp)
    or         $a0, $a1, $zero
    jal        func_002F1C38
    nop
    or         $t9, $v0, $zero
    addiu      $v1, $v0, 0x1F
    srl        $v0, $v1, 5
    sw         $v0, 0x8($sp)
    lwu        $a0, 0x4($sp)
    jal        func_002F1C38
    nop
    addu       $t9, $t9, $v0
    addiu      $v1, $v0, 0x1F
    srl        $v0, $v1, 5
    sw         $v0, 0xC($sp)
    dsrl       $t9, $t9, 5
    addiu      $t9, $t9, 0x1
    sltiu      $v0, $t9, 0x20
    bnez       $v0, .L002F29C0
    nop
    addiu      $t9, $zero, 0x20
  .L002F29C0:
    addiu      $a0, $sp, 0x1C0
    or         $a1, $zero, $zero
    jal        lintSetSmallValue
    nop
    addiu      $a0, $sp, 0xC0
    or         $a1, $zero, $zero
    jal        lintSetSmallValue
    nop
    addiu      $a0, $sp, 0x140
    or         $a1, $zero, $zero
    jal        lintSetSmallValue
    nop
    addiu      $v1, $sp, 0xC0
    sw         $v1, 0x10($sp)
    addiu      $v1, $sp, 0x144
    sw         $v1, 0x14($sp)
    lwu        $t0, 0x0($sp)
    lwu        $t6, 0x8($sp)
    lwu        $t2, 0x10($sp)
    lwu        $t3, 0x14($sp)
    b          .L002F2AD4
  .L002F2A14:
    lwu       $t1, 0x4($sp)
    lwu        $a0, 0x0($t0)
    lwu        $t7, 0xC($sp)
    b          .L002F2A50
    nop
  .L002F2A28:
    lwu        $a1, 0x0($t1)
    multu      $a0, $a1
    addiu      $t1, $t1, 0x4
    addiu      $t7, $t7, -0x1
    mflo       $v0
    mfhi       $v1
    sw         $v0, 0x0($t2)
    sw         $v1, 0x0($t3)
    addiu      $t2, $t2, 0x4
    addiu      $t3, $t3, 0x4
  .L002F2A50:
    bnez       $t7, .L002F2A28
    nop
    or         $t1, $t9, $zero
    addiu      $t3, $sp, 0x1C0
    addiu      $t4, $sp, 0xC0
    addiu      $t5, $sp, 0x140
    or         $a0, $zero, $zero
    b          .L002F2AA4
    nop
  .L002F2A74:
    lwu        $a1, 0x0($t3)
    lwu        $a2, 0x0($t4)
    lwu        $a3, 0x0($t5)
    addiu      $t1, $t1, -0x1
    daddu      $a0, $a0, $a1
    addiu      $t3, $t3, 0x4
    daddu      $a0, $a0, $a2
    addiu      $t4, $t4, 0x4
    daddu      $a0, $a0, $a3
    addiu      $t5, $t5, 0x4
    sw         $a0, -0x4($t3)
    dsrl32     $a0, $a0, 0
  .L002F2AA4:
    bnez       $t1, .L002F2A74
    nop
    lwu        $t2, 0x10($sp)
    lwu        $t3, 0x14($sp)
    sw         $zero, 0x0($t2)
    sw         $zero, 0x0($t3)
    addiu      $t2, $t2, 0x4
    addiu      $t3, $t3, 0x4
    addiu      $t6, $t6, -0x1
    sw         $t2, 0x10($sp)
    sw         $t3, 0x14($sp)
    addiu      $t0, $t0, 0x4
  .L002F2AD4:
    bnez       $t6, .L002F2A14
    nop
    addiu      $a0, $sp, 0x1C0
    lwu        $a1, 0x1C($sp)
    jal        MODIP
    nop
    addiu      $t0, $zero, 0x20
    addiu      $t1, $sp, 0x1C0
    lwu        $t2, 0x18($sp)
    b          .L002F2B1C
    nop
  .L002F2B00:
    lq         $a0, 0x0($t1)
    lq         $a1, 0x10($t1)
    addiu      $t0, $t0, -0x8
    addiu      $t1, $t1, 0x20
    sq         $a0, 0x0($t2)
    sq         $a1, 0x10($t2)
    addiu      $t2, $t2, 0x20
  .L002F2B1C:
    bnez       $t0, .L002F2B00
    nop
    lq         $ra, 0xB0($sp)
    addiu      $sp, $sp, 0x240
    jr         $ra
    nop
endlabel XMOD
    nop
