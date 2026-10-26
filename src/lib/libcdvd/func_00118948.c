#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int sceSifAddCmdHandler(int, int *, int);                         
int DIntr();                                
int EIntr();                                  
extern int D_004878A4;
extern int D_004878C0;
extern int _sceCd_Poff_Intr;

int PowerOffCB(void) {
    int temp_s0;

    D_004878A4 = 1;
    temp_s0 = DIntr();
    sceSifAddCmdHandler(0x80000012, &_sceCd_Poff_Intr, 0);
    if (temp_s0 != 0) {
        EIntr();
    }
    D_004878A4 = 0;
    D_004878C0 = 1;
    return 1;
}
