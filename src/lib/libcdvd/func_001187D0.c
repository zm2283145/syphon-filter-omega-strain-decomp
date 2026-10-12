#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0010D170(int);                               
int func_0010D180(int);                               
int func_0010F7C0(int);                                 
int func_001161A0();                                
int func_001161F8();                                  
extern int D_00487894;
extern int D_004878A0;
extern int D_004878A8;
extern int D_004878AC;
extern int D_004878B0;
extern int D_004878D8;

void func_001187D0(void) {
    int temp_s0;

    if (D_00487894 != 0) {
        D_004878D8 = -1;
        /* Publish shutdown before signaling the waiting thread. */
        __asm__ volatile("" ::: "memory");
        func_0010D180(D_004878A0);
    }
    func_0010D170(D_004878A8);
    func_0010D170(D_004878AC);
    func_0010D170(D_004878B0);
    func_0010D170(D_004878A0);
    temp_s0 = func_001161A0();
    func_0010F7C0(0x80000012);
    if (temp_s0 != 0) {
        func_001161F8();
    }
}


