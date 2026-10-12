#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                    
int func_00268B50(char *, void **);                      
extern char D_004A82B8;
extern char D_004F83E0;
extern unsigned char D_00533880;
extern int D_00533888;

char * ScriptArray_Create(int arg0) {
    char * sp4C;
    char * temp_s0;
    char * temp_s2;

    sp4C = NULL;
    if ((arg0 > 0) && (arg0 < 0x3E8)) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0 = (char *)(Mem_Alloc(0, 0xC, &D_004A82B8, 0x19E));
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0 != NULL) {
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            temp_s2 = (char *)(Mem_Alloc(0, arg0 * 4, &D_004A82B8, 0x127));
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            F_(temp_s0, 0x0, int) = (int)(temp_s2);
            F_(temp_s0, 0x4, int) = arg0;
            F_(temp_s0, 0x8, int) = 0;
        }
        sp4C = temp_s0;
        func_00268B50(&D_004F83E0, &sp4C);
    }
    return sp4C;
}
