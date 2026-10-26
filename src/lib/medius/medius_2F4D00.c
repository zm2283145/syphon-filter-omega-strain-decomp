extern void RSADecryptBlock(int, int, char *, char *);
int RSADecrypt(int a, int b, char *src, char *dst, unsigned int len)
{
    int done = 0;
    while (len >= 0x40) {
        RSADecryptBlock(a, b, src, dst);
        src += 0x40;
        dst += 0x40;
        len -= 0x40;
        done += 0x40;
    }
    return done;
}
