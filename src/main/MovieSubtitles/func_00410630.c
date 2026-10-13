#include "types.h"
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
void String_CtorCStr_13B480(Key_410630* s, const char* c);
void String_Dtor(Key_410630* s, short f);
int func_00410C10(void* line, Key_410630* key);
char* func_00189540(void* line);
int func_002071F0(Key_410630* key);
int func_00121BB0(char* s);
int atoi(char* s);
float SoftFloat_DoubleToFloat(int v);
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
    String_CtorCStr_13B480(&key, name);
    p = 0;
    int r = func_00410C10(line, &key);
    if (r > -1) {
        p = func_00189540(line) + r + func_002071F0(&key);
        while (*p == ' ' || *p == '\t') p++;
    }
    String_Dtor(&key, 0);
    return p;
}

extern "C" void func_00410630(Font_410630* self, void* line)
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
        self->color[0] = SoftFloat_DoubleToFloat(func_00121BB0(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
        self->color[1] = SoftFloat_DoubleToFloat(func_00121BB0(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
        self->color[2] = SoftFloat_DoubleToFloat(func_00121BB0(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
        self->color[3] = SoftFloat_DoubleToFloat(func_00121BB0(p));
        p = SkipWord_410630(p); while (*p && IsSp_410630(*p) || IsTab_410630(*p)) p++;
    }
}




