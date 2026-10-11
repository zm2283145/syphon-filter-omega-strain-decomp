#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char * , int);                         
int func_00121BC8(int);                             
int func_00128E80(int, char *);                          
extern char D_004C0618;
extern char D_004C0620;
extern char D_004C0630;
extern char D_004C0638;
extern char D_004C0648;
extern char D_004C0650;
extern char D_004C0660;
extern char D_004C0670;
extern char D_004C0680;
extern char D_004C06A0;
extern char D_004C06C0;
extern char D_004C06E0;
extern char D_004C0700;

void func_00443260(char * arg0, int arg1, int arg2) {
    signed char temp_s1;
    int var_v0;

    if (arg2 != 0) {
        var_v0 = func_00121BC8(arg2);
    } else {
        var_v0 = 0;
    }
    temp_s1 = var_v0 != 0;
    if (func_00128E80(arg1, &D_004C0618) == 0) {
        String_Copy(arg0 + 0x1FFC, arg2);
        return;
    }
    if (func_00128E80(arg1, &D_004C0620) == 0) {
        F_(arg0, 0x207C, int) = var_v0;
        return;
    }
    if (func_00128E80(arg1, &D_004C0630) == 0) {
        String_Copy(arg0 + 0x2100, arg2);
        return;
    }
    if (func_00128E80(arg1, &D_004C0638) == 0) {
        String_Copy(arg0 + 0x2080, arg2);
        return;
    }
    if (func_00128E80(arg1, &D_004C0648) == 0) {
        String_Copy(arg0 + 0x1F7C, arg2);
        return;
    }
    if (func_00128E80(arg1, &D_004C0650) == 0) {
        F_(arg0, 0x2180, int) = var_v0;
        return;
    }
    if (func_00128E80(arg1, &D_004C0660) == 0) {
        F_(arg0, 0x2184, signed char) = temp_s1;
        return;
    }
    if (func_00128E80(arg1, &D_004C0670) == 0) {
        if (var_v0 > 1) {
            F_(arg0, 0x1EA4, int) = var_v0;
        }
    } else {
        if (func_00128E80(arg1, &D_004C0680) == 0) {
            F_(arg0, 0x1E98, int) = 0;
            F_(arg0, 0x1E9C, int) = 0;
            return;
        }
        if (func_00128E80(arg1, &D_004C06A0) == 0) {
            String_Copy(arg0 + 0x23B5, arg2);
            return;
        }
        if (func_00128E80(arg1, &D_004C06C0) == 0) {
            F_(arg0, 0x23D5, signed char) = temp_s1;
            return;
        }
        if (func_00128E80(arg1, &D_004C06E0) == 0) {
            F_(arg0, 0x23D6, signed char) = temp_s1;
            return;
        }
        if (func_00128E80(arg1, &D_004C0700) == 0) {
            F_(arg0, 0x17C, signed char) = temp_s1;
        }
    }
}
