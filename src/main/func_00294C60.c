#pragma cplusplus on
#include "types.h"
struct Str_00294C60 { char d[0x10]; };
struct Str12_00294C60 { char d[0xC]; };
struct Sub_00294C60 { char pad[0x40]; char name[4]; };
struct Mgr_00294C60 { char pad[0x188]; Sub_00294C60 sub; };
struct S_00294C60 {
    char pad0[0x98]; void* p98; void* p9C; void* pA0; int fA4; int fA8; int fAC; int fB0;
    char padB4[0x178 - 0xB4]; unsigned char b178[0x78]; unsigned char b1F0[0x14]; Str12_00294C60 s204[0x11];
};
struct S2_00294C60 { char pad0[0x1CC]; int f1CC; int f1D0; };
extern "C" {
extern char D_004AA288[];
extern char* D_0048C160[];
extern char D_004FFC90[];
extern Mgr_00294C60* D_004FFC04;
extern char D_004AA200[];
extern char D_004AA290[];
extern char D_004AA298[];
extern char D_004AA2A8[];
extern char D_004AA2B8[];
void func_0041BEB0(void* w, char* s, int a);
char* strncpy(char* d, const char* s, int n);
char* Loc_LookupText(char* key);
void String_CtorCStr_13B480(Str_00294C60* s, const char* c);
void func_0013D680(Str12_00294C60* d, Str_00294C60* s);
void func_00138B70(Str_00294C60* s, int flags);
int func_002071F0(Str12_00294C60* s);
char* func_001692D0(Str12_00294C60* s);
void func_00294B20(S_00294C60* self, char* t);
void String_Copy(char* d, const char* s);
}
extern "C" void func_00294C60(S_00294C60* self)
{
    char* key;
    int i;
    if (!self->p98 || !self->p9C || !self->pA0)
        return;
    func_0041BEB0(self->p98, D_004AA288, 0);
    func_0041BEB0(self->p9C, D_004AA288, 0);
    func_0041BEB0(self->pA0, D_004AA288, 0);
    i = ((S2_00294C60*)self)->f1CC;
    if (i == -1)
        return;
    if (i < 0x11) {
        if (self->b178[i]) {

            unsigned char* f;
            Str12_00294C60* st;
            char* txt;
            key = D_0048C160[i];
            strncpy(D_004FFC90, key, 0x80);
            if (!self->b1F0[i]) {
                char* t = Loc_LookupText(key);
                if (t) {
                    Str_00294C60 s;
                    String_CtorCStr_13B480(&s, t);
                    func_0013D680(&self->s204[i], &s);
                    func_00138B70(&s, 0);
                }
                self->b1F0[i] = 1;
            }
            txt = (char*)&self->s204[i];
            {
                bool e = func_002071F0((Str12_00294C60*)txt) == 0;
                if (e) {
                    txt = 0;
                } else {
                    txt = func_001692D0((Str12_00294C60*)txt);
                    asm { .set reorder } /* scheduling barrier: keeps retail's branch layout */
                }
            }
            if (txt)
                func_00294B20(self, txt);
            else
                func_0041BEB0(self->p98, key, 0);
            {
                Sub_00294C60* sub = &D_004FFC04->sub;
                String_Copy(sub->name, txt ? txt : key);
            }
            return;
        } else {
            char* t = Loc_LookupText(D_004AA200);
            func_0041BEB0(self->pA0, t ? t : D_004AA288, 0);
            return;
        }
    }
    if (self->pA0) {
        int k = ((S2_00294C60*)self)->f1D0;
        if (k == self->fA8)
            func_0041BEB0(self->pA0, Loc_LookupText(D_004AA290), 0);
        else if (k == self->fA4)
            func_0041BEB0(self->pA0, Loc_LookupText(D_004AA298), 0);
        else if (k == self->fAC)
            func_0041BEB0(self->pA0, Loc_LookupText(D_004AA2A8), 0);
        else if (k == self->fB0)
            func_00294B20(self, Loc_LookupText(D_004AA2B8));
    }
}