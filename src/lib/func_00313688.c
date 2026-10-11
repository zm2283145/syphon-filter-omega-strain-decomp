typedef struct { int a; int b; char pad[0xF8]; } ScfSlot;
typedef struct { int f0; int f4; int f8; int fC; ScfSlot slot[64]; } ScfSlotTbl;
void func_00313688(ScfSlotTbl *t)
{
    unsigned int i;
    t->f0 = 1;
    t->f8 = 0;
    t->fC = 0;
    for (i = 0; i < 64; i++) {
        t->slot[i].a = 0;
        t->slot[i].b = 0;
    }
}