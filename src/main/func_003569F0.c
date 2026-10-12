#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class S3569F0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int f54();
    char s4[0xC];
};
extern "C" {
void* func_00414790(void);
void* func_004147A0(void);
int func_00418A80(void* mgr, char* a, char* b);
char* func_001692D0(void* str);
void func_00354E40(int snd, int a, char* s, int b, int c, int d, int e);
void func_00414AC0(void* mgr, void* self, int snd);
void func_003569F0(S3569F0* self, char* name, int b, int c, int d, int e);
}
void func_003569F0(S3569F0* self, char* name, int b, int c, int d, int e)
{
    int s = func_00418A80(func_00414790(), "GuiPersonnelMenu", name);
    if (s) {
        char* str = func_001692D0(self->s4);
        func_00354E40(s, self->f54(), str, b, c, d, e);
        func_00414AC0(func_004147A0(), self, s);
    }
}