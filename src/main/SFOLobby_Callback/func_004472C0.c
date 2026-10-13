#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef struct { int x; char s[0x3EC]; } E4472C0;
extern char* D_00585E60;
extern char D_004C0CD0[];
extern int func_004505C0();
extern void String_Copy(char* d, const char* s);
extern int strlen(const char* s);
extern int String_CompareN(const char* a, const char* b, int n);
extern void func_00443BF0(char* g, char* s, int n, int f);
extern void func_0044F470(int a, E4472C0* e);
extern void* memcpy(void* dst, const void* src, int n);

#pragma opt_propagation off
void func_004472C0(int d0, int d1, int d2, char* msg)
{
    if (func_004505C0() == 0) {
        F_(D_00585E60, 0x1BC, int) = 1;
        if (F_(msg, 0x18, int) != 0) {
            F_(msg, 0x408, char) = 1;
        } else {
            E4472C0 e;
            char* pfx;
            int n;
            e.x = F_(msg, 0x1C, int);
            String_Copy(e.s, msg + 0x20);
            pfx = D_004C0CD0;
            n = strlen(pfx);
            if (String_CompareN(e.s, pfx, n) == 0) {
                func_00443BF0(D_00585E60, e.s + n, strlen(e.s) - n, 1);
            } else {
                func_0044F470(F_(D_00585E60, 0x2400, int), &e);
            }
        }
        memcpy(D_00585E60 + 0x5A4, msg, 0x40C);
    }
}

