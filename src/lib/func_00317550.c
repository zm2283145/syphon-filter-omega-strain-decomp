extern float D_004B36F0[];
extern float D_004E1CC0;
extern const float D_004E1BB8;
extern const float D_004E1C30;
extern const float D_004E1BEC;
extern void func_0031AD68(float *a, int p, float *c, int n, float gain);

void func_00317550(float *lpc, float *cep, float *err, float *dist, int p, float gain)
{
    float tmp[13];
    float d;
    int i;

    func_0031AD68(lpc, p, tmp, 13, gain);
    *err = __builtin_fabsf(cep[0] - tmp[0]);
    *dist = 0;
    for (i = 1; i < 13; i++) {
        tmp[i] *= D_004B36F0[i - 1];
        d = tmp[i] - cep[i];
        *dist += d * d;
    }
    *dist *= D_004E1CC0;
    if (*dist < D_004E1BB8) {
        for (i = 0; i < 13; i++)
            cep[i] = tmp[i] * D_004E1C30 + cep[i] * D_004E1BEC;
    } else {
        for (i = 0; i < 13; i++)
            cep[i] = tmp[i];
    }
}
