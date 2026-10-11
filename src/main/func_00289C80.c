#pragma cplusplus on
#include "types.h"
struct Fl_00289C80 { char pad[0x14]; unsigned short flags; };
struct Txt_00289C80 { char pad[0x14]; unsigned short flags; char pad16[0x32]; char s48[4]; };
struct Ag_00289C80 { char pad[0x8CC]; char name[4]; };
struct Mgr_00289C80 { char pad[0x265]; unsigned char b265; };
struct S_00289C80 {
    char pad0[0x4C]; unsigned char b4C; char pad4D[0x3B]; Txt_00289C80* p88; Txt_00289C80* p8C; Txt_00289C80* p90; Txt_00289C80* p94; Txt_00289C80* p98;
    Ag_00289C80* p9C; void* pA0; unsigned char bA4; char padA5[7]; unsigned char bAC; unsigned char bAD;
};
extern "C" {
extern unsigned char D_00506378;
extern Mgr_00289C80* D_004FFC04;
extern char D_004A96F8[];
extern char D_004A9708[];
extern char D_004A9718[];
extern char D_004A9720[];
extern char D_004A9730[];
extern char D_004A9770[];
extern char D_004A9788[];
int func_0033CF90(S_00289C80* self, void* w, int msg, int sub);
void func_0028A230(S_00289C80* self);
void func_0028A180(S_00289C80* self);
void func_00289440(S_00289C80* self);
void func_00288E90(S_00289C80* self);
void* func_004147A0(void);
void func_00414B30(void* ui, void* w);
char* func_001692D0(void* s);
int strcmp(const char* a, const char* b);
void String_Copy(char* d, const char* s);
char* func_00336170(Ag_00289C80* ag);
void func_00441C20(S_00289C80* self, char* n);
void func_00441A10(S_00289C80* self);
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
void func_002CA640(void* ui, int a);
void* func_00414790(void);
void* func_00418A80(void* a, char* b, char* c);
void func_00414AC0(void* ui, S_00289C80* self, void* pg);
}
static inline int StrNe_00289C80(const char* a, const char* b) { return strcmp(a, b); }
extern "C" int func_00289C80(S_00289C80* self, void* w, int msg, int sub, char* text)
{
    unsigned short m;
    if (D_00506378)
        return func_0033CF90(self, w, msg, sub);
    m = msg;
    if (m == 2) {
        Txt_00289C80* a = self->p88;
        if (w == a && self->p8C) {
            func_0028A230(self);
        } else if (w == self->p90 && self->p94) {
            func_0028A180(self);
        } else if (w == self->p98) {
            D_00506378 = 1;
            if (!self->bAD)
                func_00289440(self);
            else
                func_00288E90(self);
            D_00506378 = 0;
        } else if (w == self->p8C) {
            if (a)
                a->flags |= 4;
            if (self->p90)
                self->p90->flags |= 4;
            if (self->p98)
                self->p98->flags |= 4;
            self->p8C->flags &= ~4;
            func_00414B30(func_004147A0(), self->p88);
        } else if (w == self->p94) {
            if (a)
                a->flags |= 4;
            if (self->p90)
                self->p90->flags |= 4;
            if (self->p98)
                self->p98->flags |= 4;
            self->p94->flags &= ~4;
            func_00414B30(func_004147A0(), self->p90);
        } else {
            return func_0033CF90(self, w, msg, sub);
        }
        return 1;
    }
    if (m == 0x1A || m == 0x1B) {
        if (m == 0x1A) {
            if (sub == 0x23 || sub == 0x24) {
                unsigned char changed;
                char* cur;
                char* n;
                self->bAC = 1;
                changed = 0;
                cur = self->p9C->name;
                if (StrNe_00289C80(func_001692D0(self->p94->s48), cur)) {
                    String_Copy(self->p9C->name, func_001692D0(self->p94->s48));
                    changed = 1;
                }
                n = func_001692D0(self->p8C->s48);
                if (strcmp(n, func_00336170(self->p9C))) {
                    func_00441C20(self, func_001692D0(self->p8C->s48));
                } else {
                    unsigned char* f = &D_004FFC04->b265;
                    if (*f)
                        changed = 1;
                    if (changed) {
                        *f = 0;
                        self->b4C = 1;
                        func_00441A10(self);
                    } else {
                        if (self->pA0)
                            func_0041BEB0(self->pA0, Loc_LookupText(D_004A96F8), 0);
                        if (self->p98)
                            func_0041BEB0(self->p98, Loc_LookupText(D_004A9718), 0);
                        self->bAD = 0;
                    }
                }
                return 1;
            }
            if (sub == 0x1F) {
                if (self->pA0)
                    func_0041BEB0(self->pA0, Loc_LookupText(D_004A9708), 0);
                if (self->p98)
                    func_0041BEB0(self->p98, Loc_LookupText(D_004A9720), 0);
                self->bAD = 1;
                return 1;
            }
            if (sub == 0x1E) {
                void* pg;
                func_002CA640(D_004FFC04, 1);
                pg = func_00418A80(func_00414790(), D_004A9770, D_004A9788);
                func_00414AC0(func_004147A0(), self, pg);
                return 1;
            }
            if (sub == 0x21) {
                if (self->p8C) {
                    func_0041BEB0(self->p8C, text ? text : D_004A9730, 0);
                }
                return 1;
            }
            if (sub == 0x22) {
                if (self->p94) {
                    func_0041BEB0(self->p94, text ? text : D_004A9730, 0);
                }
                return 1;
            }
            if (sub == 0x25) {
                self->bA4 = 1;
                func_0028A230(self);
                return 1;
            }
        }
    }
    return func_0033CF90(self, w, msg, sub);
}