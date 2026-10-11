#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_001115B0(int *, int);                          
int func_00111838(int);                               
int func_00111BF0(int, signed char *, int);                      
extern signed char D_004914A8;
extern int D_004B8610;

signed char *func_00326080(void) {
    int temp_v0;

    if (D_004914A8 == 0) {
        temp_v0 = func_001115B0(&D_004B8610, 1);
        if (temp_v0 >= 0) {
            func_00111BF0(temp_v0, &D_004914A8, 0xE);
            func_00111838(temp_v0);
        }
    }
    return &D_004914A8;
}
