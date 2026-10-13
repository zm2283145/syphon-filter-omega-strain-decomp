extern void func_002DFAE8(unsigned int port, int slot, unsigned char flag, unsigned short n, int arg);
void func_002E6120(int port, unsigned short n, int x)
{
    if (x == 0 && port != -2) {
        func_002DFAE8(0, port, 1, n, 0);
        return;
    }
    func_002DFAE8(0, 0x100, 0, 0, 1);
}
