#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_00129C80(int *, int);                        
int func_0030F050(int, int, int);                   
extern int D_004B0DA0;

void func_00310820(int arg0, int arg1) {
    if (F_(arg1, 0x20C, unsigned char) == 0) {
        if (func_0030F050(arg1 + 0x108, arg1 + 0x208, arg0) == 0) {
            F_(arg1, 0x20C, unsigned char) = 1U;
        }
        if (func_00129C80(&D_004B0DA0, arg0) != 0) {
            F_(arg1, 0x8, signed char) = 0xA;
        }
    }
}
