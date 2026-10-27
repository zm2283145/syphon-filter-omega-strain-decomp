#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int String_CompareNoCase(int, int);
int **std_vector_EnumDefPtr_opIndex(char * , int);
extern char * D_00554F30;

int cScriptInterpreter_findEnum(int d0, int arg1) {
    int i;
    int n = F_(D_00554F30, 0x4, int);
    for (i = 0; i < n; i++) {
        if (String_CompareNoCase(arg1, **std_vector_EnumDefPtr_opIndex(D_00554F30, i)) == 0) {
            return *(int *)((char *)F_(D_00554F30, 0x8, int) + (i * 4));
        }
    }
    return 0;
}
