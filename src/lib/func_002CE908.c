typedef struct { unsigned char b[76]; } BlkE908;
extern int D_0048C408;
extern BlkE908 D_0051F008;
void func_002CE908(int mode, BlkE908 *src)
{
    D_0048C408 = mode;
    if (mode == 0) D_0051F008 = *src;
}
