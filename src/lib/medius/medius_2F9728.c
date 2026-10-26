extern void InitializePRNG(void);
extern int randomMT(void);
void KM_CreateRandomRCKey(int *a)
{
    unsigned char i;
    InitializePRNG();
    for (i = 0; i < 16; i++) a[i] = randomMT();
}