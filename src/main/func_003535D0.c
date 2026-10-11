#include "types.h"
typedef struct {
    char pad[0x48]; int a48; char pad4C[0x18]; int a64; int a68; char pad6C[4]; int a70;
    char pad74[8]; signed char a7C; char pad7D[3]; char s80[0xC];
} S3535D0;
extern int func_00421480(int list);
extern char* func_001692D0(void* str);
extern void* func_004147A0(void);
extern void func_0041E0F0(void* self, void* mgr, int a, int b, int c);
extern void func_003569F0(void* self, char* s, int a, int b, int c, int d);
void func_003535D0(S3535D0* o, int arg)
{
    int i = func_00421480(o->a48);
    if (i == -1 || i >= o->a70) {
        func_0041E0F0(o, func_004147A0(), 0x10, 4, 0);
        return;
    }
    func_003569F0(o, func_001692D0(o->s80), o->a7C, arg, o->a64, i + o->a68);
    func_0041E0F0(o, func_004147A0(), 0x10, 0, 0);
}