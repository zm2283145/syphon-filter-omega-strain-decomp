#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int ScalarCollection_Init();                       
int __construct_array();                
int __register_global_object();          
int func_00437470();                     
extern char D_00582820;
extern char D_00582AA0;
extern char D_00582AB0;
extern char D_00582AC0;
extern char D_00582AD0;
extern char D_00582AE0;
extern char D_00582AF0;
extern char D_00582B00;
extern char D_00582B10;
extern char D_00582B20;
extern char D_00582B30;
extern char D_00582B40;
extern char D_00582B50;
extern char func_004374F0;
extern char func_00437550;
extern char func_004375B0;

void func_004D7640(void) {
    int sp1C;
    int sp18;

    __construct_array(&D_00582820, &func_004375B0, 0, 4, 145);
    ScalarCollection_Init(&D_00582AB0);
    __register_global_object(&D_00582AB0, &func_00437550, &D_00582AA0);
    ScalarCollection_Init(&D_00582AD0);
    __register_global_object(&D_00582AD0, &func_00437550, &D_00582AC0);
    ScalarCollection_Init(&D_00582AF0);
    __register_global_object(&D_00582AF0, &func_00437550, &D_00582AE0);
    ScalarCollection_Init(&D_00582B10);
    __register_global_object(&D_00582B10, &func_00437550, &D_00582B00);
    ScalarCollection_Init(&D_00582B30);
    __register_global_object(&D_00582B30, &func_00437550, &D_00582B20);
    func_00437470(&D_00582B50, &sp1C, &sp18);
    __register_global_object(&D_00582B50, &func_004374F0, &D_00582B40);
}
