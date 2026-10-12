#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __construct_array(char *, char *, int, int, int);                
int __register_global_object(char *, char *, char *);          
int func_003FCC80(char *, char *, char *);                     
int func_003FCCA0(char *, char *, char *);                     
extern char D_0055C758;
extern char D_0055C770;
extern char D_0055C788;
extern char D_0055C7A0;
extern char D_0055C7C0;
extern char func_003FCD80;
extern char func_003FCDD0;
extern char func_003FCE30;

void func_004D6A80(void) {
    int sp1C;
    int sp18;
    int sp14;
    int sp10;

    func_003FCC80(&D_0055C770, &sp1C, &sp18);
    __register_global_object(&D_0055C770, &func_003FCE30, &D_0055C758);
    func_003FCCA0(&D_0055C7A0, &sp14, &sp10);
    __register_global_object(&D_0055C7A0, &func_003FCDD0, &D_0055C788);
    __construct_array(&D_0055C7C0, &func_003FCD80, 0, 0x98, 3);
}
