unsigned char D_004908DC = 0;
extern void setNewSeed(int id);
void InitializePRNG(void)
{
    if (D_004908DC == 0) {
        D_004908DC = 1;
        setNewSeed(0x35D2325);
    }
}
