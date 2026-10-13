extern const float D_004E1BD8;
extern int func_00321F48(void *s);
void func_00322340(int start, int end, void *state, float *out)
{
    int i;
    for (i = start; i < end; i++)
        out[i] = func_00321F48(state) * D_004E1BD8;
}
