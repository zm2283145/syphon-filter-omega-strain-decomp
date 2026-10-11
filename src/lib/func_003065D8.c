typedef struct { int f0; int f4; int f8; } ScfCnt_5D8;
extern ScfCnt_5D8 D_00529830;
extern int Time_UpdateCounter(void);
int func_003065D8(int *out)
{
    int ret = 2;
    if (out == 0) return ret;
    if (Time_UpdateCounter() != 0) return 1;
    out[0] = D_00529830.f0;
    out[1] = D_00529830.f8;
    return 0;
}