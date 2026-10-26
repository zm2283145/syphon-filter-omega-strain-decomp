typedef struct { int a, b, c; } Str_328310;
typedef struct { int a, b, c, d; } Sub_328310;
typedef struct { Str_328310 name; Sub_328310 sub; int x; } E_328310;
typedef struct {
    char pad[0x48];
    char v48[4];
    int n4C;
    E_328310* v50;
} O_328310;
extern char D_004B8790[];
void String_CtorEmpty(void* s);
void cArray_Slide_ctor(void* s);
void String_CtorCStr_13B480(Str_328310* s, char* c);
void String_AssignString(Str_328310* d, Str_328310* s);
void String_Dtor(void* s, int f);
void std_vector_imp_Section_insert(void* v, E_328310* pos, int n, E_328310* e);
void std_vector_deleter_Slide_dtor(void* s, int f);

int GuiSlideShow_AddCategory(O_328310* o, char* s)
{
    E_328310 e;
    Str_328310 t;
    int r;
    Sub_328310* m;
    String_CtorEmpty(&e);
    m = &e.sub;
    cArray_Slide_ctor(m);
    { Str_328310* p = &t; String_CtorCStr_13B480(p, s ? s : D_004B8790); }
    String_AssignString(&e.name, &t);
    String_Dtor(&t, 0);
    e.x = 0;
    std_vector_imp_Section_insert(o->v48, o->v50 + o->n4C, 1, &e);
    r = o->n4C - 1;
    if (m) {
        if (m) {
            if (m) std_vector_deleter_Slide_dtor(m, 0);
        }
    }
    String_Dtor(&e, 0);
    return r;
}


