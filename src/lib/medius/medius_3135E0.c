typedef struct { int a; int b; char pad[0xF8]; } ScfSlot;
typedef struct { int f0; int f4; int f8; int fC; ScfSlot slot[64]; } ScfSlotTbl;
extern int rt_memory_allocate_init_zero(void *pp, int size);
ScfSlotTbl *CreateSequence(void)
{
    ScfSlotTbl *t = 0;
    unsigned int i;
    rt_memory_allocate_init_zero(&t, 0x4010);
    if (t) {
        t->f4 = 0;
        t->f0 = 1;
        t->f8 = 0;
        t->fC = 0;
        for (i = 0; i < 64; i++) {
            t->slot[i].a = 0;
            t->slot[i].b = 0;
        }
    }
    return t;
}