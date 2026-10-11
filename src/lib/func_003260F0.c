#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00326080();                                  
extern signed char D_004914A8;

int func_003260F0(void) {
    if (F_(&D_004914A8, 0x0, signed char) == 0) {
        func_00326080();
    }
    return F_(&D_004914A8, 0x4, signed char) == 0x54;
}
