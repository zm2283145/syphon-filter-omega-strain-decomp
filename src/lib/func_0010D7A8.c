extern int D_00486190;
extern int func_0010E970(void);
extern int func_0010E8A0(int, int);
int func_0010D7A8(int mode, int a, int b)
{
    if (mode == 0) {
        if (!D_00486190) {
            if (!func_0010E970())
                return -1;
            D_00486190 = 1;
        }
        return func_0010E8A0(a, b);
    }
    return -1;
}

