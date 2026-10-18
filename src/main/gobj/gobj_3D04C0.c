/*
 * main/gobj: 7 files, 003D04C0-003D0B10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D04C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    int x0;
    int x4;
    int w;
    char pad0C[8];
    char str[0xC];
    void* font;
    char pad24[0x30];
    float align;
    unsigned char b58;
    unsigned char b59;
    unsigned char b5A;
    unsigned char b5B;
} T04C0;
extern int String_Length(void* s);
extern char* String_CStr(void* s);
extern char* strchr(const char* s, int c);
extern int strlen(const char* s);
extern int Font_GetStringWidth(void* font, const char* s, int n);

int TextObj_GetLineCount(T04C0* t)
{
    float x, right, lim;
    char* p;
    char* next;
    char* q;
    int lines, cnt, wd, i, len, w;

    if (!String_Length(t->str) || t->b58)
        return 1;
    if (t->b5B) {
        char* s = String_CStr(t->str);
        int n = 1;
        if (s) {
            do {
                s = strchr(s, '\n');
                if (s) {
                    n++;
                    s++;
                }
            } while (s);
        }
        return n;
    }
    x = (float)t->x0;
    w = t->w > 0 ? t->w : -t->w;
    right = x + (float)w;
    p = String_CStr(t->str);
    lines = 0;
    do {
        lim = x + (1.0f - t->align) * (right - x);
        do {
            if (*p) {
                len = strlen(p + 1);
                for (i = 0; i < len; i++) {
                    if (p[i + 1] == ' ' || p[i + 1] == '\n')
                        break;
                }
                next = (char*)(i + (int)p + 1);
            } else {
                next = 0;
            }
            if (next)
                cnt = next - p;
            else
                cnt = strlen(p) + 1;
            wd = Font_GetStringWidth(t->font, p, cnt);
            if (x + wd < right || (x == (float)t->x0 && t->align == 1.0f)) {
                p = next;
                x += wd;
            } else if (t->align != 1.0f && x <= lim) {
                q = p;
                for (i = 0; i < cnt; i++) {
                    if (!(x + Font_GetStringWidth(t->font, p, i + 1) < right))
                        break;
                    q++;
                }
                p = q;
                break;
            }
            if (next && *next == '\n')
                break;
        } while (p && x + wd < right);
        lines++;
        x = (float)t->x0;
        if (p && *p == ' ') {
            do {
                p++;
            } while (*p == ' ');
        }
    } while (p && *p);
    return lines;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D04C0 */

/* merge_units: begin func_003D0810 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void TextObj_SetColour(int arg0, int arg1) {
    if (F_(arg0, 0x59, unsigned char) == 0) {
        F_(arg0, 0x30, float) = F_(arg1, 0x0, float);
        F_(arg0, 0x34, float) = F_(arg1, 0x4, float);
        F_(arg0, 0x38, float) = F_(arg1, 0x8, float);
        F_(arg0, 0x3C, float) = F_(arg1, 0xC, float);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D0810 */

/* merge_units: begin func_003D0850 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; float f3C; char pad40[0xC]; float f4C; float f50; char pad54[5]; char b59; } S3D0850;
void TextObj_StartFade(S3D0850* s, float x, float t) {
    if (t == 0.0f) {
        s->f3C = x;
        s->b59 = 0;
    } else {
        s->f50 = x;
        s->f4C = (x - s->f3C) / (1000.0f * t);
        s->b59 = 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D0850 */

/* merge_units: begin func_003D08B0 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_CtorCStr_13B480();                      
typedef struct { char c; } Tag_08B0;
int String_Replace(void*, int, int, int, int, Tag_08B0);                  
int String_Dtor();                            
int func_0013D680();                          

void TextObj_SetText(char * arg0, int arg1) {
    int sp20[3];

    if (arg1 != 0) {
        String_CtorCStr_13B480(sp20);
        func_0013D680(arg0 + 0x14, sp20);
        String_Dtor(sp20, 0);
        F_(arg0, 0x44, int) = 0;
        F_(arg0, 0x40, float) = (float) -F_(arg0, 0x8, int);
        F_(arg0, 0x4C, int) = 0;
        F_(arg0, 0x59, signed char) = 0;
        F_(arg0, 0x5A, signed char) = 0;
        return;
    }
    { Tag_08B0 tag; String_Replace(arg0 + 0x14, 0, -1, 0, 0, tag); }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D08B0 */

/* merge_units: begin func_003D0940 */
#pragma push /* merge_units */
typedef struct { int f0; char f4[0xC]; char f10[0xC]; unsigned char b1C; } M3D1020;
extern signed char D_00543740;
extern M3D1020 D_00543760;
extern char D_00543764[];
extern char D_00543770[];
extern char D_00543748[];
extern char TextManager_Destroy[];
extern int D_004937F0;
extern void List_InitEmpty(void* p);
extern void ScalarCollection_Init(void* p);
extern void __register_global_object(void* o, void* d, void* l);
#pragma push
#pragma opt_propagation off
static inline M3D1020* Def_3D0940(void)
{
    if (!D_00543740) {
        M3D1020* m = &D_00543760;
        D_00543760.f0 = 0;
        List_InitEmpty(D_00543764);
        ScalarCollection_Init(D_00543770);
        m->b1C = 1;
        __register_global_object(m, TextManager_Destroy, D_00543748);
        D_00543740 = 1;
    }
    return &D_00543760;
}
typedef struct { float x, y, z, w; } V4_940;
typedef struct S3D0940 {
    int a0, a4, a8, aC;
    unsigned char b10, b11, b12;
    int i14, i18, i1C;
    int i20;
    char pad24[0xC];
    V4_940 v30;
    float f40;
    int i44;
    float f48;
    int i4C, i50;
    float f54;
    unsigned char b58, b59, b5A, b5B;
} S3D0940;
S3D0940* TextObj_Construct(S3D0940* s, int a, int b, int c, int d, int e, V4_940* v)
{
    s->a0 = a;
    s->a4 = b;
    s->a8 = c;
    s->aC = d;
    s->b10 = 0;
    s->b11 = 0;
    s->b12 = 0;
    s->i14 = 0;
    s->i18 = 0;
    s->i1C = 0;
    s->i20 = e ? e : (Def_3D0940(), D_00543760.f0);
    s->v30.x = v->x;
    s->v30.y = v->y;
    s->v30.z = v->z;
    s->v30.w = v->w;
    s->f40 = (float)-s->a8;
    s->i44 = 0;
    s->f48 = (float)D_004937F0;
    s->i4C = 0;
    s->i50 = 0;
    s->f54 = 0.6f;
    s->b58 = 0;
    s->b59 = 0;
    s->b5A = 0;
    s->b5B = 0;
    return s;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003D0940 */

/* merge_units: begin func_003D0A90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_003D0A90)
#pragma pop /* merge_units */
/* merge_units: end func_003D0A90 */

/* merge_units: begin func_003D0B10 */
#pragma push /* merge_units */
typedef struct { int m0; int m4; int m8; } T0B10;
extern void func_003D10B0(int* out, T0B10* self, int* first, int* last);
extern void operator_delete(void* p);
T0B10* func_003D0B10(T0B10* self, short del)
{
    if (self) {
        if (self) {
            if (self) {
                int r;
                int first;
                int last;
                last = (int)&self->m4;
                first = self->m8;
                func_003D10B0(&r, self, &first, &last);
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D0B10 */
