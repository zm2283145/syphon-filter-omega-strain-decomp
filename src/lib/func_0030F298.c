#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_001298B8(int *, int, int);
int func_0030F050(int, int, int);
extern int D_004B0838;

void func_0030F298(int arg0, int arg1) {
    if (F_(arg1, 0x20C, unsigned char) == 0) {
        if (func_0030F050(arg1 + 0x108, arg1 + 0x208, arg0) == 0) {
            F_(arg1, 0x20C, unsigned char) = 1U;
        }
        if (func_001298B8(&D_004B0838, arg0, 0x100) == 0) {
            F_(arg1, 0x8, signed char) = 0;
        }
    }
}