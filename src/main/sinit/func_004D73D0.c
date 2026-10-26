#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __construct_array(char *, char *, int, int, int);                
int __register_global_object(char *, char *, char *);          
int std_vector_tServerPtr_ctor(char *);
extern char D_00572440;
extern char D_00572490;
extern char D_005724A0;
extern signed char D_005724AC;
extern char cDME_tServer_ctor;
extern char cArray_tServerPtr_dtor;

void StaticInit_DME(void) {
    __construct_array(&D_00572440, &cDME_tServer_ctor, 0, 0x14, 2);
    std_vector_tServerPtr_ctor(&D_005724A0);
    D_005724AC = 1;
    __register_global_object(&D_005724A0, &cArray_tServerPtr_dtor, &D_00572490);
}
