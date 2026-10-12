typedef struct { unsigned char type; char pad; unsigned short val; } Pfx09C8;
extern int func_003018E0(unsigned char *dst, unsigned char v);
extern int func_00301988(unsigned char *dst, unsigned short v);
int NetPacket_WritePrefix(unsigned char *dst, Pfx09C8 *p, unsigned short *len)
{
    if (dst == 0) return 2;
    if (p == 0) return 2;
    if (len == 0) return 2;
    *len = 0;
    if (func_003018E0(dst, p->type) != 0) return 7;
    (*len)++;
    if (func_00301988(dst + 1, p->val) != 0) return 7;
    *len += 2;
    return 0;
}
