#include "types.h"
struct ObjCC260 { char pad[0x310]; unsigned char b310; };
extern struct ObjCC260* D_004FFC04;
extern unsigned char D_0051EEB0;
extern char D_0055A300[];
void func_002CBAD0(struct ObjCC260*);
void func_002CBB30(struct ObjCC260*);
void func_0036A0F0(void*);
void* func_004147A0(void);
void func_00415870(void*);
void func_0041DF00(void*, int, int, int);

void func_002CC260(int arg0, int arg1)
{
    int i;

    if (D_0051EEB0 != 0) {
        return;
    }
    D_0051EEB0 = 1;
    if (arg0 == 0) {
        if (D_004FFC04->b310 == 0 || arg1 == 0x3039) {
            func_002CBB30(D_004FFC04);
            func_002CBAD0(D_004FFC04);
        }
    } else if (arg0 == 1) {
        func_0036A0F0(D_0055A300);
        func_00415870(func_004147A0());
        if (D_004FFC04->b310 == 0) {
            func_002CBB30(D_004FFC04);
            func_002CBAD0(D_004FFC04);
        }
    } else if (arg0 == 2) {
        if (arg1 == 2) {
            func_0041DF00(func_004147A0(), 0x2001, 0, 0);
            if (D_004FFC04->b310 == 0) {
                for (i = 0; i < 3; i++) {
                    func_002CBB30(D_004FFC04);
                    func_002CBAD0(D_004FFC04);
                }
            }
        }
    } else if (arg0 == 3) {
        func_0041DF00(func_004147A0(), 0x2002, arg1, 0);
    }
    D_0051EEB0 = 0;
}
