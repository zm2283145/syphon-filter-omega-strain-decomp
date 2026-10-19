#include "types.h"

typedef struct String {
    int a, b, c;
} String;

typedef struct Obj84 {
    char pad[0x6C];
    String name;
    String desc;
    int value;
} Obj84;

extern void String_CtorCStr_13B480(String*, const char*);
extern void String_AssignString(String*, String*);
extern void String_Dtor(String*, int);

/* Sets two string fields and an int. */
void GuiSlideShow_SetReturn(Obj84* o, const char* name, const char* desc, int value) {
    String tmp2;
    String tmp1;
    String_CtorCStr_13B480(&tmp1, name);
    String_AssignString(&o->name, &tmp1);
    String_Dtor(&tmp1, 0);
    String_CtorCStr_13B480(&tmp2, desc);
    String_AssignString(&o->desc, &tmp2);
    String_Dtor(&tmp2, 0);
    o->value = value;
}
