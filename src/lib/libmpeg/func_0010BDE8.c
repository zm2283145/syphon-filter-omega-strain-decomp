typedef unsigned long u_long __attribute__((mode(DI)));
typedef unsigned int u_int;

#define REG(a) (*(volatile unsigned int *)(a))

extern void func_0010D3E0(int);
extern int func_001161A0(void);
extern void func_001161F8(void);

typedef struct {
    u_long tag;
    u_long pad;
} DmaTag;

void func_0010BDE8(char *mp, int addr, int size)
{
    DmaTag *base;
    DmaTag *t;
    int len;
    int oldintr;
    int id;
    u_int a;

    base = (DmaTag *)(((u_int)(mp + 0x88F) >> 4) << 4);
    t = base;
    while (size > 0) {
        len = size > 0xFFF40 ? 0xFFF40 : size;
        a = addr & 0xFFFFFFF;
        size -= len;
        id = size ? 3 : 0;
        t->tag = ((u_long)a << 32) | ((u_long)id << 28) | (u_long)(u_int)((len + 15) / 16);
        __asm__ __volatile__("sync");
        addr += len;
        t++;
    }
    func_0010D3E0(0);
    oldintr = func_001161A0();
    REG(0x1000B430) = (u_int)base & 0xFFFFFFF;
    REG(0x1000B420) = 0;
    REG(0x1000B400) = 0x105;
    if (oldintr)
        func_001161F8();
}



