#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __construct_array(char *, char *, int, int, int);                
int __register_global_object(char *, char *, char *);          
int func_003ECAF0(char *);
extern char D_0055A890;
extern char D_0055C098;
extern char D_0055C0A8;
extern char func_003ECA90;
extern char func_003ECB30;

void func_004D69B0(void) {
    __construct_array(&D_0055A890, &func_003ECB30, 0, 0x10, 384);
    func_003ECAF0(&D_0055C0A8);
    __register_global_object(&D_0055C0A8, &func_003ECA90, &D_0055C098);
}
