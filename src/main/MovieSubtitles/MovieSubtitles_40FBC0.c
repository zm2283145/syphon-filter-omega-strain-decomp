/*
 * main/MovieSubtitles: range (2 files, 0040FBC0-0040FE50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0040FBC0 */
#pragma push /* merge_units */
typedef struct { union { struct { unsigned int word; unsigned int length; char* data; } l; struct { unsigned char isLong : 1; unsigned char len : 7; } s; } u; } Str_40FE50;
char* func_0040FE50(void* a, Str_40FE50* s); /* gsynth: defined below */
typedef struct { int a; int b; int c; } Str40FBC0;
typedef struct {
    char pad00[0x40];
    unsigned char mode;  /* 0x40 */
    char pad41[3];
    int lang;            /* 0x44 */
    char pad48[0x1C];
    int f64;             /* 0x64 */
    int f68;             /* 0x68 */
} Subs40FBC0;

static char D_004BEEF8[] = "FEED";
static char D_004BEF00[] = "INIT";
static char D_004BEF08[] = "END";
extern void String_PushBack(Str40FBC0* s, int c);
extern char* String_CStr_Thunk(Str40FBC0* s);
extern void func_001F12D0(Str40FBC0* s, char* cs);
#if 0 /* merge_units */
extern int func_0040FE50(Str40FBC0* s, Str40FBC0* key);
#endif /* merge_units */
#define func_0040FE50(a0, a1) ((int)func_0040FE50((void *)(a0), (void *)(a1))) /* merge_units */

extern void String_Dtor_138350(Str40FBC0* s, int flags);
extern void String_Dtor(Str40FBC0* s, int flags);
extern int func_00412C40(Str40FBC0* s);
extern void func_00410630(Subs40FBC0* self, Str40FBC0* s);
extern void func_0040FF20(Subs40FBC0* self, Str40FBC0* s);

void func_0040FBC0(Subs40FBC0* self, const char* s, const char* end)
{
    const char* p = s;
    while (p < end) {
        Str40FBC0 line;
        int c;
        int* q = (int*)&line;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        while (!(p < end) == 0 && (c = *p) != '\n') {
            if (c == '\r') {
                p++;
            } else {
                p++;
                String_PushBack(&line, c);
            }
        }
        if (p < end && *p == '\n') p++;
        if (*String_CStr_Thunk(&line) != 0 && *String_CStr_Thunk(&line) != '#') {
            if (*String_CStr_Thunk(&line) == '%') {
                int r;
                Str40FBC0 k1;
                Str40FBC0 k2;
                Str40FBC0 k3;
                func_001F12D0(&k1, D_004BEF08);
                r = func_0040FE50(&line, &k1);
                String_Dtor_138350(&k1, -1);
                if (r) {
                    self->mode = 0;
                } else {
                    func_001F12D0(&k2, D_004BEF00);
                    r = func_0040FE50(&line, &k2);
                    String_Dtor_138350(&k2, -1);
                    if (r) {
                        self->mode = 1;
                    } else {
                        func_001F12D0(&k3, D_004BEEF8);
                        r = func_0040FE50(&line, &k3);
                        String_Dtor_138350(&k3, -1);
                        if (r) self->mode = 2;
                    }
                }
                switch (self->mode) {
                case 2:
                    { int r2 = func_00412C40(&line); if (r2 != self->lang) self->mode = 0; }
                    break;
                }
            } else {
                switch (self->mode) {
                case 1:
                    func_00410630(self, &line);
                    break;
                case 2:
                    func_0040FF20(self, &line);
                    break;
                }
            }
        }
        String_Dtor(&line, 0);
    }
    self->f64 = self->f68;
}
#undef func_0040FE50 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040FBC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040FBC0 */

/* merge_units: begin func_0040FE50 */
#pragma push /* merge_units */
extern int func_003CBF70(void* a, Str_40FE50* s, int c);
extern char* String_CStr(void* a);
static inline unsigned int Len_40FE50(Str_40FE50* s) { return (s->u.l.word & 1) ? s->u.l.length : (unsigned char)s->u.s.len; }
#pragma opt_rotateloops off
char* func_0040FE50(void* a, Str_40FE50* s)
{
    char* p = 0;
    int r = func_003CBF70(a, s, 0);
    if (r > -1) {
        p = String_CStr(a) + r + Len_40FE50(s);
        while (*p == ' ' || *p == '\t') p++;
    }
    return p;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040FE50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040FE50 */
