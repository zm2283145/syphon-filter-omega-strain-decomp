#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (D_005721C8) { if (D_00494178 == -1) func_002EBAF8(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002EB650(void **, int);                      
int func_002EBAF8(int *, int);                        
int func_002EC460(int);                               
int func_002EC878(int, int);                          
int func_00325A28(int);                             
int func_0042B1A0(int);                               
int func_0042BF90();                                  
int func_0042C1D0();                                  
int lgAudClose(int);                                  
int lgAudStopPlayback(int);                           
extern int D_00494178;
extern int D_00497548;
unsigned int D_00497550[2] = { 0xFFFFFFFF, 0x0 };
unsigned int D_00497558[2] = { 0xFFFFFFFF, 0x0 };
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_00582B88;
extern signed char D_00582D00;
extern int D_00582D08;
extern int D_00582D10;
extern int D_00582D18;
extern signed char D_00582D28;
extern signed char D_00583860;
extern int D_00583870;

void func_00437BF0(void) {
    int sp2C;
    int var_s0;
    int var_v0;

    if (D_00582B88 != 0) {
        func_002EB650(&sp2C, D_00583870);
        var_s0 = -1;
        if (sp2C != NULL) {
            var_s0 = F_(sp2C, 0x4, int);
        }
        LOCALID_(var_v0)
        if (var_s0 == var_v0) {
            func_002EC460(D_00583870);
            D_00582D28 = 1;
        }
        if (D_00582B88 != 0) {
            if (func_00325A28(D_00497548) == 0x80000006) {
                D_00582B88 = 0;
            }
            D_00582D08 = func_0042B1A0(1) + 0x7D0;
        }
        D_00583860 = 0;
        if (D_00582B88 != 0) {
            if (func_00325A28(D_00497548) == 0x80000006) {
                D_00582B88 = 0;
            }
            D_00582D08 = func_0042B1A0(1) + 0x7D0;
        }
        lgAudStopPlayback(D_00497548);
        D_00582B88 = 0;
        lgAudClose(D_00497548);
        func_002EC878((*(int*)D_00497550), *(volatile int*)&(*(int*)D_00497558));
        D_00582D00 = 0;
        (*(int*)D_00497550) = -1;
        (*(int*)D_00497558) = -1;
        func_0042BF90();
        func_0042C1D0();
        D_00582D18 = 0;
        D_00497548 = -1;
        D_00582D10 = 0;
    }
}
