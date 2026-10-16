/* compiler: ee-gcc 2.95 -O2 (check_match -c gcc). DECI2 open (kind 1): protocol, opt, handler, uncached buffer. */
extern int func_0010D590(int kind, void *req);
extern char D_004E2810[];

int func_0010E2B0(unsigned short protocol, void *opt, void (*handler)(int, int, void *))
{
    unsigned int args[4];
    args[0] = protocol;
    args[1] = (unsigned int)opt;
    args[2] = (unsigned int)handler;
    args[3] = (unsigned int)D_004E2810 | 0x20000000;
    return func_0010D590(1, (void *)args);
}
