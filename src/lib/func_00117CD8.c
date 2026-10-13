/* libgcc __floatdisf is the retail func_0011B888 */
__asm__("__floatdisf = func_0011B888");
float func_00117CD8(unsigned long x)
{
    float f = (float)x;
    float r;
    /* div.s after the li.s mtc1: the SCE assembler pads the cop1 hazard with two nops */
    __asm__("nop\n\tnop\n\tdiv.s %0, %1, %2" : "=f"(r) : "f"(147456000.0f), "f"(f));
    return r;
}

