typedef struct { int a, b, c; } Str_328140;
typedef struct { Str_328140 name; int val; Str_328140 desc; unsigned char flag; char pad[0x2C - 0x1D]; } E_328140;
typedef struct { char p0[0xC]; char list[4]; int count; E_328140* data; char p18[8]; } G_328140;
typedef struct {
    char pad[0x4C];
    int count;
    G_328140* data;
} O_328140;
extern char D_004B8790[];
void cString_ctor_void(void* s);
void std_basic_string_char_char_traits_char_ctor_charP(Str_328140* s, char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_328140* d, Str_328140* s);
void String_Dtor(void* s, int f);
void std_vector_imp_Slide_insert(void* v, E_328140* pos, int n, E_328140* e);

static inline void CtorE_328140(E_328140* e)
{
    cString_ctor_void(&e->name);
    cString_ctor_void(&e->desc);
}
static inline void DtorS_328140(Str_328140* s)
{
    if (s) String_Dtor(s, 0);
}
static inline G_328140* At_328140(O_328140* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->data[i];
}

int GuiSlideShow_AddSlide(O_328140* o, int idx, char* name, int val, char* desc)
{
    G_328140* g = At_328140(o, idx);
    if (g == 0) return -1;
    {
        E_328140 e;
        Str_328140 ta;
        Str_328140 tb;
        int r;
        CtorE_328140(&e);
        std_basic_string_char_char_traits_char_ctor_charP(&ta, name);
        std_basic_string_char_char_traits_char_assign_basicstringR(&e.name, &ta);
        String_Dtor(&ta, 0);
        e.val = val;
        { Str_328140* p = &tb; std_basic_string_char_char_traits_char_ctor_charP(p, desc ? desc : D_004B8790); }
        std_basic_string_char_char_traits_char_assign_basicstringR(&e.desc, &tb);
        String_Dtor(&tb, 0);
        e.flag = 0;
        std_vector_imp_Slide_insert(g->list, g->data + g->count, 1, &e);
        r = g->count - 1;
        DtorS_328140(&e.desc);
        String_Dtor(&e, 0);
        return r;
    }
}

