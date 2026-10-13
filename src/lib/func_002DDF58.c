extern unsigned short func_002DCD00(unsigned int);
extern int func_002FBD48(unsigned short, unsigned short, void *, void *, unsigned short);
extern int printf(const char *, ...);
int Net_SendConvertRecipient(signed char a, unsigned int idx, int to, unsigned int len, void *data)
{
    int r; unsigned short recip;
    recip = to;
    if (to == -1) recip = 0xFFFE;
    else if (to == 0xFFFF) recip = 0xFFFF;
    r = func_002FBD48(func_002DCD00(idx), recip, (void *)(int)a, data, len);
    if (r) {
        printf("SendPacket error sending message, msg error code = %d\n", r);
        return 0xD;
    }
    return r;
}
