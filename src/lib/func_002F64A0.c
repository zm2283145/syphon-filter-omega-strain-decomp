typedef struct { char b[0x38]; } B2F64A0;
extern B2F64A0 D_00525508;
extern int func_002F68F0(void);
int func_002F64A0(B2F64A0 *out)
{
    int r;
    if (out == 0) return 2;
    r = func_002F68F0();
    if (r) return r;
    *out = D_00525508;
    return r;
}
