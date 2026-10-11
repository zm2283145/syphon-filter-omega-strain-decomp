
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_001069F0(char *);                             
int func_0010BD90();                          
extern char D_004985D0;
extern char D_004985F0;

int func_001089E0(char *arg0) {
    int temp_v0;
    char * var_s1;

    if ((F_(arg0, 0x18C, int) == 3) && (F_(arg0, 0x138, int) != 0)) {
        func_0010BD90(arg0, &D_004985D0);
        F_(arg0, 0x138, int) = 0;
    }
    switch (F_(arg0, 0x18C, int)) {                         
    case 3:
        var_s1 = (char *)(F_(arg0, 0x1D8, int));
        break;
    case 1:
        var_s1 = (char *)(F_(arg0, 0x1E8, int));
        break;
    case 2:
        var_s1 = (char *)(F_(arg0, 0x1F8, int));
        break;
    default:
        var_s1 = (char *)(F_(arg0, 0x1D8, int));
        func_0010BD90(arg0, &D_004985F0);
        break;
    }
    temp_v0 = func_001069F0(arg0);
    if (temp_v0 != 0) {
        F_(var_s1, 0x28, int) = 1;
    }
    return temp_v0;
}
