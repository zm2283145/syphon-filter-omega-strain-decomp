/*
 * main/interface_manager: range (3 files, 004133B0-004136F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_004133B0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Str4134B0 { int a; int b; int c; };
struct List4134B0 { int pad0; int count; Str4134B0* data; };
struct Self4134B0 { char pad[0x1E4]; List4134B0* list; int arc; };
extern "C" bool cInterfaceManager_FindHogFile(Self4134B0* self, Str4134B0* out, const char* name, unsigned char* isPak); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

struct Str4133B0 { int a; int b; int c; };
struct List4133B0 { int pad0; int count; Str4133B0* data; };
struct Self4133B0 { char pad[0x1E0]; int h1E0; int p1E4; int arc; List4133B0* list; };

extern "C" {
#if 0 /* merge_units */
int cInterfaceManager_FindHogFile(Self4133B0* self, Str4133B0* out, int name, unsigned char* isPak);
#endif /* merge_units */
#define cInterfaceManager_FindHogFile(a0, a1, a2, a3) ((int)cInterfaceManager_FindHogFile((Self4134B0 *)(a0), (Str4134B0 *)(a1), (const char *)(a2), (a3))) /* merge_units */

char* std_basic_string_char_char_traits_char_c_str(Str4133B0* s);
int cHogList_OpenFromHog(int h, char* name, int arc);
int cHogList_Open(int h, char* name, int a, int b);
void std_vector_imp_cString_insert(List4133B0* list, Str4133B0* pos, int n, Str4133B0* value);
void String_Dtor(Str4133B0* s, int flags);
}

#pragma push
#pragma opt_propagation off
extern "C" int cInterfaceManager_OpenHogFile(Self4133B0* self, int* out, int name)
{
    if (!self->list) return 0;
    {
        unsigned char inPak;
        Str4133B0 s;
        Str4133B0* ps = &s;
        ps->a = 0; ps->b = 0; ps->c = 0;
        if (cInterfaceManager_FindHogFile(self, ps, name, &inPak)) {
            if (inPak) {
                *out = cHogList_OpenFromHog(self->h1E0, std_basic_string_char_char_traits_char_c_str(&s), self->arc);
            } else {
                *out = cHogList_Open(self->h1E0, std_basic_string_char_char_traits_char_c_str(&s), 0, 0);
            }
            std_vector_imp_cString_insert(self->list, &self->list->data[self->list->count], 1, &s);
            String_Dtor(&s, 0);
            return 1;
        }
        String_Dtor(&s, 0);
        return 0;
    }
}
#pragma pop
#undef cInterfaceManager_FindHogFile /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004133B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004133B0 */

/* merge_units: begin func_004134B0 */
#pragma push /* merge_units */
#pragma cplusplus on




struct Hog4134B0 { char pad[0xA0]; };

extern "C" {
#if 0 /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(Str4134B0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((Str4133B0 *)(a0))) /* merge_units */

void cFileMan_ctor_void(Hog4134B0* h);
void cFileMan_dtor(Hog4134B0* h, int flags);
void cFileMan_EncodeFilename_charP_cFileIOP_bool(Hog4134B0* h, char* name, int a, int b);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog4134B0* h, char* name, int arc, int z);
int cFileMan_Open(Hog4134B0* h);
void std_basic_string_char_char_traits_char_ctor_charP(Str4134B0* s, char* src);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str4134B0* dst, Str4134B0* src);
#if 0 /* merge_units */
void String_Dtor(Str4134B0* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str4133B0 *)(a0), (a1))) /* merge_units */

}

#pragma push
#pragma opt_strength_reduction off
extern "C" bool cInterfaceManager_FindHogFile(Self4134B0* self, Str4134B0* out, const char* name, unsigned char* isPak)
{
    Str4134B0 tmp;
    Str4134B0 tmp2;
    char buf[0x80];
    Hog4134B0 h;
    char buf2[0x80];
    Hog4134B0 h2;
    int i;
    if (!name || !*name || !self->list)
        return false;
    for (i = self->list->count - 1; i >= 0; i--) {
        char* p;
        cFileMan_ctor_void(&h);
        sprintf(buf, "%s\\%s.HOG", std_basic_string_char_char_traits_char_c_str(&self->list->data[i]), name);
        for (p = buf; *p; p++) {
            char c = *p;
            if (c >= 'a' && c <= 'z')
                *p -= 0x20;
        }
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&h, buf, 0, 0);
        if ((unsigned char)cFileMan_Open(&h)) {
            cFileMan_dtor(&h, -1);
            continue;
        }
        {
            std_basic_string_char_char_traits_char_ctor_charP(&tmp, buf);
            std_basic_string_char_char_traits_char_assign_basicstringR(out, &tmp);
            String_Dtor(&tmp, 0);
        }
        if (isPak)
            *isPak = 0;
        cFileMan_dtor(&h, -1);
        return true;
    }
    if (self->arc) {
        cFileMan_ctor_void(&h2);
        sprintf(buf2, "%s.HOG", name);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(&h2, buf2, self->arc, 0);
        if ((unsigned char)cFileMan_Open(&h2)) {
            cFileMan_dtor(&h2, -1);
            return false;
        }
        {
            std_basic_string_char_char_traits_char_ctor_charP(&tmp2, buf2);
            std_basic_string_char_char_traits_char_assign_basicstringR(out, &tmp2);
            String_Dtor(&tmp2, 0);
        }
        if (isPak)
            *isPak = 1;
        cFileMan_dtor(&h2, -1);
        return true;
    }
    return false;
}
#pragma pop
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef String_Dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004134B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004134B0 */

/* merge_units: begin func_004136F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Str4136F0 { int a; int b; int c; };
struct List4136F0 { int pad0; int count; Str4136F0* data; };
struct Self4136F0 { char pad[0x1E4]; List4136F0* list; };

extern "C" {
int std_basic_string_char_char_traits_char_compare_charP(Str4136F0* s, char* name);
int cArray_cString_Size(List4136F0* v);
Str4136F0* std_vector_cString_opIndex(List4136F0* v, int index);
Str4136F0* cString_opAssign(Str4136F0* dst, Str4136F0* src);
void StringVec_PopBack(List4136F0* v);
}

#pragma push
#pragma opt_strength_reduction off
extern "C" void cInterfaceManager_RemoveHogPath(Self4136F0* self, char* name)
{
    int i;
    if (self->list) {
        for (i = 0; i < self->list->count; i++) {
            if (!std_basic_string_char_char_traits_char_compare_charP(&self->list->data[i], name)) {
                List4136F0* v = self->list;
                int n = cArray_cString_Size(v);
                if (i >= 0 && i < n) {
                    int j;
                    for (j = i + 1; j < n; j++) {
                        cString_opAssign(std_vector_cString_opIndex(v, j - 1), std_vector_cString_opIndex(v, j));
                    }
                    StringVec_PopBack(v);
                }
                return;
            }
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004136F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004136F0 */
