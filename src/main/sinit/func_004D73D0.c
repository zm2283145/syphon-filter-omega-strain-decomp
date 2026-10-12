#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __construct_array(char *, char *, int, int, int);                
int __register_global_object(char *, char *, char *);          
int func_0042B9E0(char *);
extern char D_00572440;
extern char D_00572490;
extern char D_005724A0;
extern signed char D_005724AC;
extern char func_0013D5B0;
extern char func_0042B890;

void func_004D73D0(void) {
    __construct_array(&D_00572440, &func_0013D5B0, 0, 0x14, 2);
    func_0042B9E0(&D_005724A0);
    D_005724AC = 1;
    __register_global_object(&D_005724A0, &func_0042B890, &D_00572490);
}
