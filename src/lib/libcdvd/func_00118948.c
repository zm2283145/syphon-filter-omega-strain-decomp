#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0010F748(int, int *, int);                         
int func_001161A0();                                
int func_001161F8();                                  
extern int D_004878A4;
extern int D_004878C0;
extern int func_001188F0;

int func_00118948(void) {
    int temp_s0;

    D_004878A4 = 1;
    temp_s0 = func_001161A0();
    func_0010F748(0x80000012, &func_001188F0, 0);
    if (temp_s0 != 0) {
        func_001161F8();
    }
    D_004878A4 = 0;
    D_004878C0 = 1;
    return 1;
}
