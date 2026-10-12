#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
extern "C" {
int Mem_Free(int, int, char *, int);
int cGOBJ_dtor(char *, int);
int func_00135D80(char *, int);
int func_00177B80(char *, int);
int func_00177F60(int *, char *, int *, char **);
int operator_delete(char *);
extern char D_004A4A90;
extern char D_004DB680;
}
static inline char* Identity(char*a){return a;} static inline void clr0(char*a){int r;int f;char*l;l=Identity(a+0xA0);f=F_(a,0xA4,int);func_00177F60(&r,a+0x9C,&f,&l);}
static inline void clr1(char *a) { clr0(a); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" char *cGenerator_dtor(char *arg0, long long arg1) {
    int temp_s2;
    char *temp_a0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, char *) = &D_004DB680;
        F_(arg0, 0x78, int) = 0;
        clr0(arg0);
        temp_s2 = F_(arg0, 0x64, int);
        {
            AllocGuard g;
            Mem_Free(0, temp_s2, &D_004A4A90, 0x23C);
        }
        temp_a0 = arg0 + 0x9C;
        if (temp_a0 != NULL) func_00177B80(temp_a0, 0);
        temp_a0 = arg0 + 0x90;
        if (temp_a0 != NULL) func_00177B80(temp_a0, 0);
        temp_a0 = arg0 + 0x74;
        if (temp_a0 != NULL) func_00135D80(temp_a0, -1);
        cGOBJ_dtor(arg0, 0);
        if (((long long)(arg1 << 0x30) >> 0x30) > 0) operator_delete(arg0);
    }
    return arg0;
}
#pragma pop