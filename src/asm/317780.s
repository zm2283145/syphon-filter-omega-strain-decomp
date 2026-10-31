.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"



glabel DotProd
    lwc1       $f0, 0x0($a0)
    addiu      $a0, $a0, 0x4
    lwc1       $f1, 0x0($a1)
    addiu      $a1, $a1, 0x4
    addiu      $a2, $a2, -0x2
    mula.s     $f0, $f1
  .L00317798:
    lwc1       $f0, 0x0($a0)
    addiu      $a0, $a0, 0x4
    lwc1       $f1, 0x0($a1)
    addiu      $a1, $a1, 0x4
    addiu      $a2, $a2, -0x1
    madda.s    $f0, $f1
    bgtz       $a2, .L00317798
    nop
    lwc1       $f0, 0x0($a0)
    nop
    lwc1       $f1, 0x0($a1)
    nop
    jr         $ra
    madd.s    $f0, $f0, $f1
endlabel DotProd
