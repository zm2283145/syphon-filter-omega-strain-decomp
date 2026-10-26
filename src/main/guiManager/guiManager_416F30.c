/*
 * main/guiManager: 2 files, 00416F30-00416F70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00416F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

void func_00416F30(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* end() of the element vector. */
L4Elem18* func_00416F40(L4Elem18Vec* v) {
    return v->data + v->count;
}

void* func_00416F60(char* self) {
    return self + 8;
}
#pragma pop /* merge_units */
/* merge_units: end func_00416F30 */

/* merge_units: begin func_00416F70 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } Str_416F70;
typedef struct { float x, y, z, w; } V4_416F70;
typedef struct { Str_416F70 name; unsigned char b; char pad[3]; int c; int d; } E_416F70;
typedef struct {
    char pad[8]; Str_416F70 s8; Str_416F70 s14; char pad20[8]; unsigned char b28; char pad29[7];
    char m30[0x40]; char v70[4]; int n74; E_416F70* v78;
} O_416F70;
void* Gui_GetScreenList(void);
char* String_CStr(void* s);
void String_CtorCStr_13B480(Str_416F70* s, char* c);
void String_AssignString(Str_416F70* d, Str_416F70* s);
void String_Dtor(void* s, int f);
void Mtx_SetBasis(void* m, V4_416F70* a, V4_416F70* b, V4_416F70* c);
void Mtx_SetTranslation(void* m, V4_416F70* t);
void String_CtorEmpty(E_416F70* e);
void std_vector_imp_GuiAnimationTrack_insert(void* v, E_416F70* pos, int n, E_416F70* e);

static inline float RdF_416F70(char** c) { float* p = (float*)*c; *c = (char*)(p + 1); return *p; }
static inline unsigned short Rd16_416F70(char** c) { unsigned short* p = (unsigned short*)*c; unsigned short v = *p; *c = (char*)(p + 1); return v; }
static inline void RdV_416F70(char** c, V4_416F70* v, float w)
{
    float x = RdF_416F70(c);
    float y = RdF_416F70(c);
    float z = RdF_416F70(c);
    v->x = x; v->y = y; v->z = z; v->w = w;
}

int GuiInterfaceDecorator_Load(O_416F70* o, char** cur)
{
    V4_416F70 a;
    V4_416F70 b;
    V4_416F70 c;
    V4_416F70 d;
    Str_416F70 t1;
    Str_416F70 t2;
    Str_416F70 t3;
    E_416F70 e;
    char* s;
    int i;
    unsigned short n;
    s = *cur;
    while (*(*cur)++ != 0);
    if (s == 0 || *s == 0) s = String_CStr((char*)Gui_GetScreenList() + 0x2C);
    else o->b28 = 1;
    String_CtorCStr_13B480(&t1, s);
    String_AssignString(&o->s8, &t1);
    String_Dtor(&t1, 0);
    s = *cur;
    while (*(*cur)++ != 0);
    if (s != 0 && *s != 0) {
        String_CtorCStr_13B480(&t2, s);
        String_AssignString(&o->s14, &t2);
        String_Dtor(&t2, 0);
    }
    *cur = (char*)(((int)*cur + 3) & ~3);
    RdV_416F70(cur, &a, 0.0f);
    RdV_416F70(cur, &b, 0.0f);
    RdV_416F70(cur, &c, 0.0f);
    RdV_416F70(cur, &d, 1.0f);
    Mtx_SetBasis(o->m30, &a, &b, &c);
    Mtx_SetTranslation(o->m30, &d);
    n = Rd16_416F70(cur);
    for (i = 0; i < n; i++) {
        String_CtorEmpty(&e);
        s = *cur;
        while (*(*cur)++ != 0);
        String_CtorCStr_13B480(&t3, s);
        String_AssignString(&e.name, &t3);
        String_Dtor(&t3, 0);
        *cur = (char*)(((int)*cur + 3) & ~3);
        e.b = Rd16_416F70(cur);
        e.c = Rd16_416F70(cur);
        e.d = Rd16_416F70(cur);
        std_vector_imp_GuiAnimationTrack_insert(o->v70, o->v78 + o->n74, 1, &e);
        String_Dtor(&e, 0);
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00416F70 */
