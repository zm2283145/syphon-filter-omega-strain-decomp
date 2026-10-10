#include "types.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { char data[0xA0]; } TextObj;
typedef struct { char pad[0x2C]; char names[1]; } Obj419;

extern char D_004BF148[];
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(void* list, String* s);
extern void func_00138B70(String* s, int flags);
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_0036E5D0(TextObj* obj);
extern void Hog_Register(TextObj* obj, char* text, int a, int b);
extern int func_00419020(Obj419* self, TextObj* obj, int c);
extern void func_0036E220(TextObj* obj, int flags);

/* Records name in the object's name list, builds a formatted text object from it and adds it; returns the result. */
int func_00419110(Obj419* self, int a, const char* name, int c)
{
    TextObj obj;
    char buf[0x20];
    String str;
    int result;
    String_CtorCStr_13B480(&str, name);
    func_0013D680(self->names, &str);
    func_00138B70(&str, 0);
    sprintf(buf, D_004BF148, name);
    func_0036E5D0(&obj);
    Hog_Register(&obj, buf, a, 0);
    result = func_00419020(self, &obj, c);
    func_0036E220(&obj, -1);
    return result;
}
