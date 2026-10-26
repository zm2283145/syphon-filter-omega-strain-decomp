#define REG(a) (*(volatile unsigned int *)(a))
#define ExitHandler() __asm__ volatile("sync\n\tei")

typedef struct {
    volatile int cnt;
    int done;
    int rem;
    unsigned int addr;
    int total;
} DmaState;

int _ch3dmaCSC(int ch, DmaState *s)
{
    int last;

    REG(0x1000E010) = 8;
    s->cnt++;
    if (REG(0x1000B020) != 0 || (REG(0x1000B000) & 0x100)) {
        s->done = 1;
        ExitHandler();
        return 0;
    }
    last = s->total - 1;
    if (s->cnt < last) {
        REG(0x1000B010) = s->addr;
        REG(0x1000B020) = 0xFFC0;
        REG(0x1000B000) = 0x100;
        REG(0x10002000) = 0x700003FF;
        s->addr = (s->addr + 0xFFC00) & 0x0FFFFFFF;
    } else if (s->cnt == last) {
        s->rem -= s->cnt * 1023;
        REG(0x1000B010) = s->addr;
        REG(0x1000B020) = s->rem << 6;
        REG(0x1000B000) = 0x100;
        REG(0x10002000) = s->rem | 0x70000000;
    }
    ExitHandler();
    return 0;
}


