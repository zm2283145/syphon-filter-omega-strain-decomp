/*
 * main/guiTextWidget: range (2 files, 0041BE50-0041BEB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

/* merge_units: begin func_0041BE50 */
#pragma push /* merge_units */
typedef struct { char p[0x48]; char m48[0x30]; void* f78; } W41BE50;
extern void* std_basic_string_char_char_traits_char_c_str(void* s);
extern void cTextArea_SetText(void* o, void* s);
extern void GuiWidget_SendParentsMessage(W41BE50* w, int kind, void* s, int z);
void GuiTextWidget_UpdateText(W41BE50* w)
{
    if (w->f78) cTextArea_SetText(w->f78, std_basic_string_char_char_traits_char_c_str(w->m48));
    GuiWidget_SendParentsMessage(w, 0x1C, std_basic_string_char_char_traits_char_c_str(w->m48), 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041BE50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041BE50 */

/* merge_units: begin func_0041BEB0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned int word; int len; char* data; } Str_BEB0;
typedef struct { char c; } Tag_BEB0;
extern "C" {
extern char D_004BF2C8[];
void std_basic_string_char_char_traits_char_do_replace(Str_BEB0* s, int pos, int n, const char* first, const char* last, Tag_BEB0 tag);
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
char* nGlobalization_GetString_charP(const char* key);
void std_basic_string_char_char_traits_char_ctor_charP(Str_BEB0* s, const char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_BEB0* d, Str_BEB0* s);
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
extern "C" void GuiTextWidget_SetText(W_BEB0* self, const char* text, unsigned char localize)
{
    if (!text || !*text) {
        Tag_BEB0 tag;
        std_basic_string_char_char_traits_char_do_replace(&self->text, 0, -1, 0, 0, tag);
    } else if (localize && strlen(text) > 1U && text[0] == '$') {
        if (text[1] != '$') {
            char* t = nGlobalization_GetString_charP(text + 1);
            Str_BEB0 s;
            Str_BEB0* ps = &s;
            std_basic_string_char_char_traits_char_ctor_charP(ps, t ? t : D_004BF2C8);
            std_basic_string_char_char_traits_char_assign_basicstringR(&self->text, &s);
            String_Dtor(&s, 0);
            return;
        } else {
            Str_BEB0 s;
            std_basic_string_char_char_traits_char_ctor_charP(&s, text + 1);
            std_basic_string_char_char_traits_char_assign_basicstringR(&self->text, &s);
            String_Dtor(&s, 0);
        }
    } else {
        Str_BEB0 s;
        std_basic_string_char_char_traits_char_ctor_charP(&s, text);
        std_basic_string_char_char_traits_char_assign_basicstringR(&self->text, &s);
        String_Dtor(&s, 0);
    }
    self->Refresh();
}
#undef strlen /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041BEB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041BEB0 */
