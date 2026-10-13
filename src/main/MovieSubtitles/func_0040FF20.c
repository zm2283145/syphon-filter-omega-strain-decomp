#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"

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
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
char* String_CStr(void* s);
int String_CompareN(char* a, char* b, int n);
int func_00121BB0(char* s);
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
    return (SubEntry*)Mem_Alloc(0, size, D_004BEE90, 0x37E);
}

extern "C" void func_0040FF20(Subs40FF20* self, void* line)
{
    char* p;
    if (self->max == 0) return;
    if (self->entries == 0) {
        int size = self->max * sizeof(SubEntry);
        self->entries = Alloc_40FF20(size);
        self->num = 0;
    }
    p = SkipBlank_40FF20(String_CStr(line));
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
        float h1 = SoftFloat_DoubleToFloat(func_00121BB0(t1));
        float m1 = SoftFloat_DoubleToFloat(func_00121BB0(t1 + 3));
        float s1 = SoftFloat_DoubleToFloat(func_00121BB0(t1 + 6));
        float h2 = SoftFloat_DoubleToFloat(func_00121BB0(t2));
        float m2 = SoftFloat_DoubleToFloat(func_00121BB0(t2 + 3));
        float s2 = SoftFloat_DoubleToFloat(func_00121BB0(t2 + 6));
        int flags = 0;
        int lang;

        if (String_CompareN(fType, D_004BEEA8, 5) == 0) flags |= 1;
        else if (String_CompareN(fType, D_004BEEB0, 4) == 0) flags |= 8;
        if (String_CompareN(fAlign, D_004BEEB8, 4) == 0) flags |= 2;
        else if (String_CompareN(fAlign, D_004BEEC0, 6) == 0) flags |= 4;
        lang = 0;
        if (String_CompareN(fLang, D_004BEE08, 7) == 0) lang = 1;
        else if (String_CompareN(fLang, D_004BEE30, 8) == 0) lang = 6;
        else if (String_CompareN(fLang, D_004BEE40, 7) == 0) lang = 7;
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



