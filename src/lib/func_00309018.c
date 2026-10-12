typedef struct { unsigned char b[4]; } ScfU32u;
extern char *func_002FAED0(void *pkt);
extern unsigned int func_002FAEE8(void *pkt);

int func_00309018(void *pkt, ScfU32u *out)
{
    char *p;
    int ret = 1;
    if (pkt == 0) return ret;
    if (out == 0) return ret;
    if (func_002FAEE8(pkt) >= 0x19) {
        p = func_002FAED0(pkt);
        p += func_002FAEE8(pkt);
        *out = *(ScfU32u *)(p - 4);
    } else {
        *(int *)out = 0;
    }
    return 0;
}
