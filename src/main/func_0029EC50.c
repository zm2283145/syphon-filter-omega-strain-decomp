#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Service_Lookup(char *, char *);                       
int SoundMgr_UnloadLevel(int);                               
int func_002B4E50();                                  
int func_002B4FA8(int);                               
int func_0037E320(char *);                               
extern char D_004F2CC0;
extern char D_004FFB50;
extern char D_005381F0;
extern int *D_0055A830;


void func_0029EC50(void) {
    int temp_v0;
    int var_a0;

    func_0037E320(&D_005381F0);
    temp_v0 = Service_Lookup(&D_004FFB50, &D_004F2CC0);
    if (temp_v0 != 0) {
        SoundMgr_UnloadLevel(temp_v0);
    }
    var_a0 = D_0055A830 ? *D_0055A830 : -1;
    if (var_a0 != -1) {
        func_002B4FA8(var_a0);
    }
    func_002B4E50();
}
