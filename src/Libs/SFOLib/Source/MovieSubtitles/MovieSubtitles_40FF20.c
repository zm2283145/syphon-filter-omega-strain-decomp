/*
 * main/MovieSubtitles: range (2 files, 0040FF20-00410630)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_0040FF20 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct {
    char text[3][100];   /* 0x000 */
    int count;           /* 0x12C */
    float start;         /* 0x130 */
    float end;           /* 0x134 */
    int flags;           /* 0x138 */
    int lang;            /* 0x13C */
} SubEntry;

typedef struct {
    char pad00[0x60];
    SubEntry* entries;   /* 0x60 */
    int max;             /* 0x64 */
    int num;             /* 0x68 */
} Subs40FF20;

static char D_004BEEA8[] = "PRINT";
static char D_004BEEB0[] = "TYPE";
static char D_004BEEB8[] = "LEFT";
static char D_004BEEC0[] = "CENTER";

extern "C" {
extern char D_004BEE90[];
extern char D_004BEE08[];
extern char D_004BEE30[];
extern char D_004BEE40[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
char* std_basic_string_char_char_traits_char_c_str(void* s);
int Libc_Strncmp(char* a, char* b, int n);
int atof(char* s);
float SoftFloat_DoubleToFloat(int v);
void func_003FD2D0(char* s);
}

static inline bool IsSp_40FF20(char c) { return c == ' '; }
static inline bool IsTab_40FF20(char c) { return c == '\t'; }

static inline char* SkipWord_40FF20(char* p)
{
    while (*p && !IsSp_40FF20(*p) && !IsTab_40FF20(*p)) p++;
    return p;
}

static inline char* SkipBlank_40FF20(char* p)
{
    while (*p && IsSp_40FF20(*p) || IsTab_40FF20(*p)) p++;
    return p;
}

static inline SubEntry* Alloc_40FF20(int size)
{
    AllocGuard g;
    return (SubEntry*)cMemMan_Allocate(0, size, D_004BEE90, 0x37E);
}

extern "C" void cSubtitleFeed_ParseINISectionFEED(Subs40FF20* self, void* line)
{
    char* p;
    if (self->max == 0) return;
    if (self->entries == 0) {
        int size = self->max * sizeof(SubEntry);
        self->entries = Alloc_40FF20(size);
        self->num = 0;
    }
    p = SkipBlank_40FF20(std_basic_string_char_char_traits_char_c_str(line));
    if (*p == 0) return;
    if (*p != '"') {
        char* fType;
        char* fLang;
        char* t2;
        char* fAlign;
        char* t1 = p;
        char* fRest;
        t2 = SkipWord_40FF20(t1); while (*t2 && IsSp_40FF20(*t2) || IsTab_40FF20(*t2)) t2++;
        fType = SkipWord_40FF20(t2); while (*fType && IsSp_40FF20(*fType) || IsTab_40FF20(*fType)) fType++;
        fAlign = SkipWord_40FF20(fType); while (*fAlign && IsSp_40FF20(*fAlign) || IsTab_40FF20(*fAlign)) fAlign++;
        fLang = SkipWord_40FF20(fAlign); while (*fLang && IsSp_40FF20(*fLang) || IsTab_40FF20(*fLang)) fLang++;
        fRest = SkipWord_40FF20(fLang); while (*fRest && IsSp_40FF20(*fRest) || IsTab_40FF20(*fRest)) fRest++;
        float h1 = SoftFloat_DoubleToFloat(atof(t1));
        float m1 = SoftFloat_DoubleToFloat(atof(t1 + 3));
        float s1 = SoftFloat_DoubleToFloat(atof(t1 + 6));
        float h2 = SoftFloat_DoubleToFloat(atof(t2));
        float m2 = SoftFloat_DoubleToFloat(atof(t2 + 3));
        float s2 = SoftFloat_DoubleToFloat(atof(t2 + 6));
        int flags = 0;
        int lang;

        if (Libc_Strncmp(fType, D_004BEEA8, 5) == 0) flags |= 1;
        else if (Libc_Strncmp(fType, D_004BEEB0, 4) == 0) flags |= 8;
        if (Libc_Strncmp(fAlign, D_004BEEB8, 4) == 0) flags |= 2;
        else if (Libc_Strncmp(fAlign, D_004BEEC0, 6) == 0) flags |= 4;
        lang = 0;
        if (Libc_Strncmp(fLang, D_004BEE08, 7) == 0) lang = 1;
        else if (Libc_Strncmp(fLang, D_004BEE30, 8) == 0) lang = 6;
        else if (Libc_Strncmp(fLang, D_004BEE40, 7) == 0) lang = 7;
        if (self->num < self->max) {
            SubEntry* e = &self->entries[self->num++];
            e->start = h1 * 60.0f + m1 + s1 / 100.0f;
            e->end = h2 * 60.0f + m2 + s2 / 100.0f;
            e->flags = flags;
            e->lang = lang;
            e->count = 0;
        }
    } else {
        p = SkipBlank_40FF20(p);
        if (self->num > 0) {
            SubEntry* e = &self->entries[self->num - 1];
            if (e->count < 3) {
                char* d = e->text[e->count];
                int i;
                if (*p == '"') p++;
                for (i = 0; *p != '"' && i < 99; i++) *d++ = *p++;
                *d = 0;
                func_003FD2D0(e->text[e->count]);
                e->count++;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040FF20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040FF20 */

/* merge_units: begin func_00410630 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct {
    int w0;
    int w1;
    char* w2;
} Key_410630;

typedef struct {
    char name[0x50];  /* 0x00 */
    float color[4];   /* 0x50 */
    int f60;          /* 0x60 */
    int numLines;     /* 0x64 */
} Font_410630;

static char D_004BEEC8[] = "Font";
static char D_004BEED0[] = "NumLines";
static char D_004BEEE0[] = "Color";

extern "C" {
void std_basic_string_char_char_traits_char_ctor_charP(Key_410630* s, const char* c);
void String_Dtor(Key_410630* s, short f);
int cString_Find(void* line, Key_410630* key);
char* cString_CStr(void* line);
int cString_Length(Key_410630* key);
int atoi(char* s);
}

static inline bool IsSp_410630(char c) { return c == ' '; }
static inline bool IsTab_410630(char c) { return c == '\t'; }

static inline char* SkipWord_410630(char* p)
{
    while (*p && !IsSp_410630(*p) && !IsTab_410630(*p)) p++;
    return p;
}

static inline char* SkipBlank_410630(char* p)
{
    while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
    return p;
}

static inline char* Find_410630(void* line, const char* name)
{
    Key_410630 key;
    char* p;
    std_basic_string_char_char_traits_char_ctor_charP(&key, name);
    p = 0;
    int r = cString_Find(line, &key);
    if (r > -1) {
        p = cString_CStr(line) + r + cString_Length(&key);
        while (*p == ' ' || *p == '\t') p++;
    }
    String_Dtor(&key, 0);
    return p;
}

extern "C" void cSubtitleFeed_ParseINISectionINIT(Font_410630* self, void* line)
{
    char* p;
    if ((p = Find_410630(line, D_004BEEC8)) != 0) {
        char* d = self->name;
        int i;
        char* q = SkipWord_410630(p);
        while (*q && IsSp_410630(*q) || IsTab_410630(*q)) q++;
        if (*p == '"') p++;
        for (i = 0; *p != '"' && i < 63; i++) *d++ = *p++;
        *d = 0;
    } else if ((p = Find_410630(line, D_004BEED0)) != 0) {
        self->numLines = atoi(p);
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
    } else if ((p = Find_410630(line, D_004BEEE0)) != 0) {
        self->color[0] = SoftFloat_DoubleToFloat(atof(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
        self->color[1] = SoftFloat_DoubleToFloat(atof(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
        self->color[2] = SoftFloat_DoubleToFloat(atof(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
        self->color[3] = SoftFloat_DoubleToFloat(atof(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00410630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00410630 */
