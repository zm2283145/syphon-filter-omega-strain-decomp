extern int D_00486190;
extern int func_0010E970(void);
extern int func_0010E728(int, int);
int func_0010D728(int mode, int a, int b)
{
    if (mode == 1 || mode == 2) {
        if (!D_00486190) {
            if (!func_0010E970())
                return -1;
            D_00486190 = 1;
        }
        return func_0010E728(a, b);
    }
    return -1;
}

