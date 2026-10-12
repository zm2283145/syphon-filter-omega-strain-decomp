typedef struct { unsigned char type; char pad; unsigned short val; } Pfx0A58;
extern int func_00301900(unsigned char *dst, Pfx0A58 *p);
extern int func_003019B0(unsigned char *dst, unsigned short *v);
int func_00300A58(unsigned char *dst, Pfx0A58 *p, unsigned short *len)
{
    if (dst == 0) return 2;
    if (p == 0) return 2;
    if (len == 0) return 2;
    *len = 0;
    if (func_00301900(dst, p) != 0) return 7;
    (*len)++;
    if (func_003019B0(dst + 1, &p->val) != 0) return 7;
    *len += 2;
    return 0;
}
