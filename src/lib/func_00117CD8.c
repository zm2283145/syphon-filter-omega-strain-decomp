/* libgcc __floatdisf is the retail SoftFloat_S64ToFloat */
__asm__("__floatdisf = SoftFloat_S64ToFloat");
float func_00117CD8(unsigned long x)
{
    float f = (float)x;
    float r;
    /* div.s after the li.s mtc1: the SCE assembler pads the cop1 hazard with two nops */
    __asm__("nop\n\tnop\n\tdiv.s %0, %1, %2" : "=f"(r) : "f"(147456000.0f), "f"(f));
    return r;
}

