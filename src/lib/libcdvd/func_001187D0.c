#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int DeleteSema(int);
int SignalSema(int);
int func_0010F7C0(int);
int DIntr();
int EIntr();
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
        SignalSema(D_004878A0);
    }
    DeleteSema(D_004878A8);
    DeleteSema(D_004878AC);
    DeleteSema(D_004878B0);
    DeleteSema(D_004878A0);
    temp_s0 = DIntr();
    func_0010F7C0(0x80000012);
    if (temp_s0 != 0) {
        EIntr();
    }
}


