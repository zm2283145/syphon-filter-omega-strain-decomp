extern char D_00498148[];
extern int func_0010F388(const char *, ...);

int func_00103330(unsigned long *tag)
{
    unsigned int i = 0;
    while (*(volatile int *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_0010F388(D_00498148);
            return -1;
        }
    }
    *(volatile int *)0x1000A020 = (int)(tag[0] & 0x7FFF) + 1;
    if (((unsigned int)tag & 0x70000000) == 0x70000000)
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)tag & 0x0FFFFFFF) | 0x80000000;
    else
        *(volatile unsigned int *)0x1000A010 = (unsigned int)tag & 0x0FFFFFFF;
    *(volatile int *)0x1000A000 = 0x101;
    return 0;
}