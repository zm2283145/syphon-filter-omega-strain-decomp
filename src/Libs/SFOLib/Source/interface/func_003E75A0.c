#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(int, char *);
int String_CompareNoCase(char *, int);
char * GetTextSystem();
unsigned int D_00493948[2] = { 0x1, 0x0 };
extern char D_004BDE78;
extern char D_004BDE80;
extern char D_004BDE90;
extern char D_004BDEB0;

#pragma push
#pragma opt_propagation off
int confunc_INTERFACE(int arg0, int *arg1, int arg2) {
    if (arg0 == 1) {
        if (String_CompareNoCase(&D_004BDE78, *arg1) == 0) {
            (*(signed char*)D_00493948) = 1;
            { int r; char *o = GetTextSystem(); r = 1; F_(o, 0x1C, signed char) = r; return r; }
        }
        if (String_CompareNoCase(&D_004BDE80, *arg1) == 0) {
            (*(signed char*)D_00493948) = 0;
            F_(GetTextSystem(), 0x1C, signed char) = 0;
            return 1;
        }
        Libc_Strcpy(arg2, &D_004BDE90);
        return 0;
    }
    Libc_Strcpy(arg2, &D_004BDEB0);
    return 0;
}

#pragma pop
