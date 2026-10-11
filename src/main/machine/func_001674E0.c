#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int Alloc_Unlock();                                  
int Archive_Open();                   
char * Mem_Alloc(int, int, char *, int);                      
int func_0027B680();                            
char * func_0027B900(char * , int, char *);              
int func_0036DEF0();                             
int func_0036E220();                            
int func_0036E4B0();                    
int sprintf();                           
extern char D_0048B2F8;
extern char D_0049C390;
extern char D_0049C430;
extern char D_0049C448;
extern char D_004FFB8C;
extern unsigned char D_00533880;
extern int D_00533888;

#pragma opt_common_subs off
void func_001674E0(char * arg0) {
    int spE0[36];
    int sp40[40];
    int temp_s0;
    char * var_s2;

    if (F_(arg0, 0x27C, int) == NULL) {
        sprintf(spE0, &D_0049C430, &D_0048B2F8);
        func_0036E4B0(sp40, spE0, 0, 0);
        if (!(func_0036DEF0(sp40) & 0xFF)) {
            temp_s0 = Archive_Open(&D_004FFB8C, spE0, 0, 0);
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            var_s2 = (char *)(Mem_Alloc(0, 0x58, &D_0049C390, 0x5B7));
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            if (var_s2 != NULL) {
                var_s2 = (char *)(func_0027B900(var_s2, temp_s0, &D_0049C448));
            }
            F_(arg0, 0x27C, int) = (int)(var_s2);
            F_(F_(arg0, 0x27C, int), 0x56, signed char) = 1;
            func_0027B680(F_(arg0, 0x27C, int));
        }
        func_0036E220(sp40, -1);
    }
}
