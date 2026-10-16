#include "types.h"
typedef struct { char pad[0xB8]; char sB8[0x40]; int aF8; char padFC[0x18]; int a114; int a118; } S361730;
extern int String_CStr(void* p);
extern void func_0033C9E0(S361730* o, int a, int b);
extern void func_0033C7C0(S361730* o, int a, int b);
extern int GuiScreen_HandleEvent(S361730* o);
int func_00361730(S361730* o, int id, unsigned short type)
{
    if (type == 2) {
        if (id == o->a118) {
            func_0033C9E0(o, o->aF8, String_CStr(o->sB8));
            return 1;
        }
        if (id == o->a114) {
            func_0033C7C0(o, o->aF8, String_CStr(o->sB8));
            return 1;
        }
    }
    return GuiScreen_HandleEvent(o);
}