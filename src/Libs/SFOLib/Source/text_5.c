/*
 * Libs/SFOLib/Source/text: 1 file, 003D0EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin gobj_3D0EF0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } Str3D;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_EF0;
typedef struct {
    Str3D name;
    int i;
    V4_EF0 v;
    float f0, f1;
} Ent3D;
typedef struct { int value; } Word;
extern void std_basic_string_char_char_traits_char_ctor_charP(Str3D* s, const char* c);
extern void String_Dtor(Str3D* s, int d);
extern void std_list_deleter_cText_insert(Word* out, void* list, Word* pos, Ent3D* e);
void cTextSystem_Print_charP_cFontR_tRGBAR_int_etc(char* o, const char* name, int i, V4_EF0* v, int a, int b)
{
    Ent3D e;
    Word out;
    Word pos;
    std_basic_string_char_char_traits_char_ctor_charP(&e.name, name);
    e.i = i;
    e.v.x = v->x;
    e.v.y = v->y;
    e.v.z = v->z;
    e.v.w = v->w;
    e.f0 = (float)a;
    e.f1 = (float)b;
    pos.value = (int)(o + 8);
    std_list_deleter_cText_insert(&out, o + 4, &pos, &e);
    String_Dtor(&e.name, 0);
}
static inline void merge_flush_gobj_3D0EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end gobj_3D0EF0 */
