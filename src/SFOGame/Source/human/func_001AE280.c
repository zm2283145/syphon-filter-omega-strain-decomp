void MEMCLEAR16(void* dst, unsigned int num)
{
    asm {
        .set noreorder
    lp:
        nop
        addi num, num, -1
        sq zero, 0(dst)
        bgtz num, lp
        addiu dst, dst, 16
        .set reorder
    }
}
