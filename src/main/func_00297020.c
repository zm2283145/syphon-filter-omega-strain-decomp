#include "types.h"
typedef struct { int pad0; int name; char pad8[0xC]; } Item_7020;
typedef struct { int a; int count; Item_7020* items; char flag; } List_7020;
extern char D_004FFB50;
extern unsigned char D_0048B868;
extern char* D_0048C160[];
extern unsigned char D_004ACD30[];
extern int D_005063D0[];
extern unsigned char D_004ACC70[];
extern unsigned char D_004FFBB5;
extern unsigned char* D_004FFC04;
int Agent_GetSelected(void*, int);
void func_00296FA0(List_7020*);
void func_003334C0(int, int, List_7020*);
int func_00332FE0(int, __int128);
__int128 func_003FDA40(char*);
char* Loc_GetStoredKey(int);
int String_CompareNoCase(char*, char*);
void func_00299360(List_7020*, int);

#pragma opt_strength_reduction off
void func_00297020(char* self) {
    int k;
    int i;
    unsigned char ok;
    char* name;
    int j;
    int sel;
    List_7020 list;
    char** pn;
    unsigned char* pe;
    int* pi;
    unsigned char* pc;
    for (k = 0; k < 0x11; k++) self[0x178 + k] = 0;
    self[0x18F] = 0;
    sel = Agent_GetSelected(&D_004FFB50, -1);
    func_00296FA0(&list);
    list.flag = 1;
    if (D_0048B868) func_003334C0(sel, 3, &list);
    for (i = 0, pn = D_0048C160, pe = D_004ACD30, pi = D_005063D0, pc = D_004ACC70; i <= 0x11; i++, pi++, pc++, pn++, pe++) {
        name = *pn;
        ok = 0;
        if (*pe) {
            if (D_004FFBB5) {
                if (name) {
                    if (i != 0x11) {
                        int s = Agent_GetSelected(&D_004FFB50, -1);
                        if (func_00332FE0(s, func_003FDA40(name))) ok = 1;
                    } else {
                        ok = 1;
                    }
                }
            } else {
                ok = 1;
            }
        }
        if (D_0048B868) {
            *pi = -1;
            for (j = 0; j < list.count; j++) {
                Loc_GetStoredKey(list.items[j].name);
                if (String_CompareNoCase(Loc_GetStoredKey(list.items[j].name), name) == 0) {
                    *pi = j;
                    break;
                }
            }
        }
        if (i == 0x11) {
            self[0x18F] = ok && !D_004FFC04[0x30];
        } else {
            if (ok && D_004FFC04[0x30]) ok = *pc;
            self[0x178 + i] = ok;
        }
    }
    D_0048B868 = 0;
    func_00299360(&list, 0);
}