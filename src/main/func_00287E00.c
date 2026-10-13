#include "types.h"
typedef struct { char pad[0x260]; int f260; } Ui287E00;
typedef struct { char pad[0x4C]; float t; int h; } Obj287E00;
typedef struct { int m0; char str[4]; } Msg287E00;
extern int Loc_LookupText(char*);
extern int String_AssignCStr_1C43A0(void*, char*);
extern float func_001002D0(int);
extern void func_00288310(Obj287E00*, int);
extern void func_002C81D0(Ui287E00*);
extern void func_002C82F0(Ui287E00*);
extern void func_002CAC80(Ui287E00*, int);
extern int func_002CAE30(Ui287E00*, int, char*, int, int, int);
extern int func_003698B0(void);
extern int func_00414790(void);
extern int func_004147A0(void);
extern void func_00414AC0(int, Obj287E00*, int);
extern int func_00418A80(int, char*, char*);
extern int func_0041EF10(Obj287E00*, Msg287E00*, unsigned short, int, int);
extern char* D_0048B3E8;
extern char* D_0048B3F0;
extern char* D_0048B3F8;
extern char D_004A9578[];
extern char D_004A9580[];
extern char D_004A9590[];
extern char D_004A95A0[];
extern char D_004A95B0[];
extern char D_004A95C0[];
extern char D_004A95D0[];
extern char D_004A95E0[];
extern char D_004FFBB8;
extern Ui287E00* D_004FFC04;

int func_00287E00(Obj287E00* self, Msg287E00* msg, unsigned short id, int a3, int a4)
{
    self->t = func_001002D0(func_003698B0()) / 1000.0f;
    if (id == 0x1A) {
        if (a3 == 1) {
            D_004FFBB8 = 0;
            return 1;
        }
    } else if (id == 0x1B) {
        if (a3 == 1) {
            func_002CAC80(D_004FFC04, self->h);
            func_00288310(self, 1);
            return 1;
        }
    }
    if (id == 2) {
        int r = 0;
        if (String_AssignCStr_1C43A0(msg->str, D_0048B3E8) == 0) {
            unsigned char open = !D_004FFC04->f260;
            int tok = -2;
            if (open) {
                Ui287E00* ui;
                func_002C82F0(D_004FFC04);
                ui = D_004FFC04;
                tok = func_002CAE30(ui, 0, D_004A9578, Loc_LookupText(D_004A9580), 0, 0);
            }
            r = func_00418A80(func_00414790(), D_004A9590, D_004A95A0);
            if (open) {
                func_002CAC80(D_004FFC04, tok);
                func_002C81D0(D_004FFC04);
            }
        } else if (String_AssignCStr_1C43A0(msg->str, D_0048B3F0) == 0) {
            r = func_00418A80(func_00414790(), D_004A95B0, D_004A95C0);
        } else if (String_AssignCStr_1C43A0(msg->str, D_0048B3F8) == 0) {
            r = func_00418A80(func_00414790(), D_004A95D0, D_004A95E0);
        }
        if (r)
            func_00414AC0(func_004147A0(), self, r);
        return 1;
    }
    return func_0041EF10(self, msg, id, a3, a4);
}


