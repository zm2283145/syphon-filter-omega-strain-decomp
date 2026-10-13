extern int func_002E6098(unsigned int);
extern int func_002E6088(unsigned int);
extern void func_003154F0(unsigned int, unsigned char *);

int func_002E86A8(unsigned int port, int unused, unsigned int b, unsigned char *m)
{
    if (m == 0) return -1;
    if (func_002E6098(port) != 1) return -1;
    if (func_002E6088(b) != 1) return -1;
    func_003154F0(port, m);
    return 0x1C;
}
