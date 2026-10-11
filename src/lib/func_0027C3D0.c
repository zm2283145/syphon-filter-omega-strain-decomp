#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0027C328();                                
int memset(int *, int, int);                                
extern int D_005040C0;

int func_0027C3D0(void) {
    int temp_s0;

    temp_s0 = func_0027C328();
    memset(&D_005040C0, 0, 0x310);
    return temp_s0;
}
