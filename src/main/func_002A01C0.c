#pragma cplusplus on
extern "C" {
extern char* D_0048BA28;
extern char* D_0048BA30;
extern char* D_0048BA38;
extern char D_004AAE80[];
extern char D_004AAE98[];
extern char D_004AAEB0[];
extern char D_004AAEC8[];
extern char D_00532FE8;
struct Ctl_2A01C0 { char pad[0x32]; unsigned char b32; };
extern Ctl_2A01C0* D_004FFC04;
struct Pg_2A01C0 { char pad[0x10]; int f10; };
struct W_2A01C0 { int unk0; char name[4]; };
int String_AssignCStr_1C43A0(void* a, char* b);
void func_002CCA20(Ctl_2A01C0* c, int on);
void* func_00414790(void);
void* func_004147A0(void);
Pg_2A01C0* func_00418A80(void* a, char* b, char* c);
void func_00414AC0(void* ui, void* self, void* pg);
int func_0041EF10(void* self, W_2A01C0* w, int msg, int sub, char* text);
}

extern "C" int func_002A01C0(void* self, W_2A01C0* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 2) {
        if (!String_AssignCStr_1C43A0(w->name, D_0048BA28)) {
            void* pg;
            D_00532FE8 = 0;
            func_002CCA20(D_004FFC04, 1);
            D_004FFC04->b32 = 0;
            pg = func_00418A80(func_00414790(), D_004AAE80, D_004AAE98);
            func_00414AC0(func_004147A0(), self, pg);
            return 1;
        }
        if (!String_AssignCStr_1C43A0(w->name, D_0048BA30)) {
            Pg_2A01C0* pg;
            func_002CCA20(D_004FFC04, 0);
            D_004FFC04->b32 = 0;
            pg = func_00418A80(func_00414790(), D_004AAEB0, D_004AAEC8);
            pg->f10 = 1;
            func_00414AC0(func_004147A0(), self, pg);
            return 1;
        }
        if (!String_AssignCStr_1C43A0(w->name, D_0048BA38)) {
            Pg_2A01C0* pg;
            pg = func_00418A80(func_00414790(), D_004AAEB0, D_004AAEC8);
            pg->f10 = 1;
            func_00414AC0(func_004147A0(), self, pg);
            return 1;
        }
    }
    return func_0041EF10(self, w, msg, sub, text);
}
