typedef struct { unsigned char b[0x310]; } BlkC548;
extern BlkC548 D_005040C0;

int sceNetcnfifGetResult(BlkC548 *dst)
{
    *dst = D_005040C0;
    return 0;
}