extern unsigned char D_004908EC;
extern int func_002FE8B0(void);
extern int func_003060C0(void *tm);
extern int func_003060F0(void *tm, unsigned int *elapsed);
extern int Socket_Write(int sock, unsigned char *data, int len, unsigned short *done);
int func_00300AE8(int sock_, unsigned char *data, int len, unsigned int timeout)
{
    /* pinned copy: retail keeps sock in s3 and timeout in s4 (as func_00303BB8) */
    register int sock asm("$19") = sock_;
    char tm[16];
    unsigned int elapsed = 0;
    unsigned short done = 0;
    unsigned char st = D_004908EC;
    int r;
    if (st != 1) return 5;
    if (func_002FE8B0() != st) return 2;
    if (data == 0) return 2;
    if (func_003060C0(tm) != 0) return 0x18;
    do {
        r = Socket_Write(sock, data, len, &done);
        if (r != 0) return r;
        len -= done;
        data += done;
        if (func_003060F0(tm, &elapsed) != 0) return 0x18;
        if (timeout < elapsed) return 0xD;
    } while (len != 0);
    return 0;
}
