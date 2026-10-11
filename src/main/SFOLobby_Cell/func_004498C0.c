#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char *);                            
int func_00443E70();                                
int func_00451B00(char * , int, char *, int);                 
int func_00466F50(char *, char *);                        
int memset(char *, int, int);                                
int strncpy(char *, char * , int);                          
extern int D_004977E8;
extern char D_004C0D10;
extern char D_004C0D38;
extern char func_004482E0;

#pragma push
#pragma opt_common_subs off
void func_004498C0(char * arg0) {
    struct { char name[0x15]; char ip[0x13]; int f58; int f5C; } sl;
    int temp_a0;
    int temp_s1;

    temp_s1 = F_(arg0, 0x2584, int);
    temp_a0 = func_00443E70() - temp_s1;
    if ((temp_s1 == 0) || (D_004977E8 < temp_a0)) {
        memset(&sl, 0, 0x30);
        String_Copy(sl.name, &D_004C0D38);
        strncpy(sl.ip, arg0 + 0x2418, 0x11);
        sl.f58 = 1;
        sl.f5C = 0x3E7;
        F_(arg0, 0x24C, int) = func_00466F50(&sl, &func_004482E0);
        if (F_(arg0, 0x24C, int) != 0) {
            func_00451B00(arg0, 1, &D_004C0D10, 0x53F);
        }
        F_(arg0, 0x2584, int) = func_00443E70();
    }
}
#pragma pop
