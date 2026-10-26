#define REG(a) (*(volatile unsigned int *)(a))
#define ExitHandler() __asm__ volatile("sync\n\tei")

typedef struct {
    unsigned int cnt;
    unsigned int addr;
} DmaChunk;

int _ch4dma(int ch, DmaChunk *s)
{
    REG(0x1000E010) = 0x10;
    if (s->cnt == 0) {
        ExitHandler();
        return 1;
    }
    if (s->cnt > 0xFFFF) {
        REG(0x1000B410) = s->addr;
        REG(0x1000B420) = 0xFFFF;
        REG(0x1000B400) = 0x101;
        s->addr = (s->addr + 0xFFFF0) & 0x0FFFFFFF;
        s->cnt -= 0xFFFF;
    } else {
        REG(0x1000B410) = s->addr;
        REG(0x1000B420) = s->cnt;
        REG(0x1000B400) = 0x101;
        s->cnt = 0;
    }
    ExitHandler();
    return 0;
}

