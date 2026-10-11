#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int memset(int , int, int);                                
extern short D_00497CC0;
extern int D_00497CD0;

int func_004689B0(void) {
    int var_v0;

    memset(&D_00497CD0, 0, 0x11);
    if (!(D_00497CC0 == 1)) return -0xF;
    D_00497CC0 = 0;
    return 0;
}
