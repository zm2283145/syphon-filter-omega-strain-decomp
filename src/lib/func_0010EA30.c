int func_0010EA30(int c)
{
    while (*(volatile int*)0x1000F130 & 0x8000)
        ;
    *(volatile char*)0x1000F180 = c;
    return c;
}