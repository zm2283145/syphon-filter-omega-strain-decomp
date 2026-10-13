#pragma cplusplus on
#include "types.h"
typedef struct { unsigned int word; int len; char* data; } Str_BEB0;
typedef struct { char c; } Tag_BEB0;
extern "C" {
extern char D_004BF2C8[];
void String_Replace(Str_BEB0* s, int pos, int n, const char* first, const char* last, Tag_BEB0 tag);
unsigned int strlen(const char* s);
char* Loc_LookupText(const char* key);
void String_CtorCStr_13B480(Str_BEB0* s, const char* c);
void func_0013D680(Str_BEB0* d, Str_BEB0* s);
void String_Dtor(Str_BEB0* s, int flags);
}
class W_BEB0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void Refresh();
    char pad04[0x44];
    Str_BEB0 text;
};
extern "C" void func_0041BEB0(W_BEB0* self, const char* text, unsigned char localize)
{
    if (!text || !*text) {
        Tag_BEB0 tag;
        String_Replace(&self->text, 0, -1, 0, 0, tag);
    } else if (localize && strlen(text) > 1U && text[0] == '$') {
        if (text[1] != '$') {
            char* t = Loc_LookupText(text + 1);
            Str_BEB0 s;
            Str_BEB0* ps = &s;
            String_CtorCStr_13B480(ps, t ? t : D_004BF2C8);
            func_0013D680(&self->text, &s);
            String_Dtor(&s, 0);
            return;
        } else {
            Str_BEB0 s;
            String_CtorCStr_13B480(&s, text + 1);
            func_0013D680(&self->text, &s);
            String_Dtor(&s, 0);
        }
    } else {
        Str_BEB0 s;
        String_CtorCStr_13B480(&s, text);
        func_0013D680(&self->text, &s);
        String_Dtor(&s, 0);
    }
    self->Refresh();
}



