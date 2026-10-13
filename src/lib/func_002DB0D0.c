typedef struct Hdr {
    unsigned char type;
    unsigned char flag;
    unsigned short len;
    unsigned short seq;
    unsigned short id;
} Hdr;
extern int func_002D8B20(void *, int, int);
extern void func_002D9A30(char *, int, Hdr *, unsigned short *, int);
void func_002DB0D0(char *o, int b)
{
    Hdr h;
    unsigned short s[1];
    register int n asm("$6") = 2;
    register signed char t asm("$2") = 0x81;
    h.len = n;
    /* scheduling barrier: retail stores h.len before loading o+0x98 */
    __asm__ volatile("" ::: "memory");
    s[0] = *(unsigned short *)(o + 0x98);
    h.type = t;
    h.id = func_002D8B20(o, b, n);
    h.seq = *(unsigned short *)(o + 0x78);
    h.flag = 0;
    func_002D9A30(o, b, &h, s, 2);
}
