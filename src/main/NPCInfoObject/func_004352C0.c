#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002EB650(void **, int);                      
int NetGame_InitLocalSlot(int *, int);                        
int func_002EC460(int);                               
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005827A0;
extern unsigned char D_005827A8;
extern unsigned char D_005827B0;
extern unsigned char D_005827B8;
extern unsigned char D_005827C0;
extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;

void func_004352C0(void) {
    int sp3C;
    int sp38;
    int sp34;
    int sp30;
    int sp2C;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s0_5;
    int var_a0;
    int var_a0_2;
    int var_a0_3;
    int var_a0_4;
    int var_a0_5;

    if (D_005827A0 != 0) {
        temp_s0 = D_00582A78;
        func_002EB650(&sp3C, temp_s0);
        if (sp3C != NULL) {
            LOCALID_(var_a0)
            if (F_(sp3C, 0x4, int) == var_a0) {
                func_002EC460(temp_s0);
            }
        }
        D_005827A0 = 0;
    }
    if (D_005827A8 != 0) {
        temp_s0_2 = D_00582A80;
        func_002EB650(&sp38, temp_s0_2);
        if (sp38 != NULL) {
            LOCALID_(var_a0_2)
            if (F_(sp38, 0x4, int) == var_a0_2) {
                func_002EC460(temp_s0_2);
            }
        }
        D_005827A8 = 0;
    }
    if (D_005827B0 != 0) {
        temp_s0_3 = D_00582A88;
        func_002EB650(&sp34, temp_s0_3);
        if (sp34 != NULL) {
            LOCALID_(var_a0_3)
            if (F_(sp34, 0x4, int) == var_a0_3) {
                func_002EC460(temp_s0_3);
            }
        }
        D_005827B0 = 0;
    }
    if (D_005827B8 != 0) {
        temp_s0_4 = D_00582A90;
        func_002EB650(&sp30, temp_s0_4);
        if (sp30 != NULL) {
            LOCALID_(var_a0_4)
            if (F_(sp30, 0x4, int) == var_a0_4) {
                func_002EC460(temp_s0_4);
            }
        }
        D_005827B8 = 0;
    }
    if (D_005827C0 != 0) {
        temp_s0_5 = D_00582A98;
        func_002EB650(&sp2C, temp_s0_5);
        if (sp2C != NULL) {
            LOCALID_(var_a0_5)
            if (F_(sp2C, 0x4, int) == var_a0_5) {
                func_002EC460(temp_s0_5);
            }
        }
        D_005827C0 = 0;
    }
}
