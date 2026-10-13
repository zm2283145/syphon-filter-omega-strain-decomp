#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                       
int func_0037B2C0(...);                        
int func_0037B2D0(...);                          
char * func_0037B2E0(...);                        
int func_0037FBA0(...);              
extern unsigned char D_00533880;
}
#pragma inline_depth(10)
static inline int ite0(char *l) { int r; func_0037B2C0(&r, func_0037B2D0(l)); return r; }
static inline void er0(char *l, char *n) { int sp84; char *sp80; sp80 = n; func_0037FBA0(&sp84, l, &sp80); }
static inline void er1(char *l, char *n) { er0(l, n); }
static inline int ite1(char *l) { return ite0(l); }
extern "C" void Video_FreeDeferredBuffers(char * arg0, int arg1) {
    int temp_s3;
    char * var_s2;
    char * temp_s1;
    int temp_s0;
    int temp_s0_2;

    if (F_(arg0, 0x1108, int) != 0) {
        var_s2 = (char *)(F_(func_0037B2E0(arg0 + 0x110C), 0x4, int));
        while (ite0(arg0 + 0x1108) != (int)var_s2) {
                F_(var_s2, 0x10, int) = (int) (F_(var_s2, 0x10, int) - 1);
                if ((F_(var_s2, 0x10, int) == 0) || (arg1 != 0)) {
temp_s1 = var_s2;
var_s2 = (char *)(F_(var_s2, 0x4, int));
temp_s0 = F_(temp_s1, 0xC, int);
                    if (temp_s0 == -1) {
                        temp_s0_2 = F_(temp_s1, 0x8, int);
                        {
                            AllocGuard g;
                        Mem_Free(0, temp_s0_2, "xlib.cc", 0x812);
                        }
                    } else {
                        temp_s3 = F_(temp_s1, 0x8, int);
                        {
                            AllocGuard g;
                        Mem_Free(temp_s0, temp_s3, "xlib.cc", 0x814);
                        }
                    }
                    er0(arg0 + 0x1108, temp_s1);
                } else {
                    var_s2 = (char *)(F_(var_s2, 0x4, int));
                }
        }
    }
}
