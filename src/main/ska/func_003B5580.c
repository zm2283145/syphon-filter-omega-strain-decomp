#pragma cplusplus on
#pragma inline_depth(8)
extern "C" {
#include "types.h"
struct StrP_5580 { unsigned int word; unsigned int length; char* data; };
typedef struct { unsigned int word; unsigned int length; char* data; } Str2_5580;
typedef struct { char* data; unsigned int len; } Src_5580;
typedef struct { Src_5580* s; unsigned int pos; unsigned char empty; } Tok_5580;
typedef struct { unsigned int cap; unsigned int count; int* data; } Vec_5580;
typedef struct { float f0; Vec_5580 keys; char pad10[0x24]; Vec_5580 clips; } Skas_5580;
extern void String_CtorCStr_13B480(StrP_5580* s, char* c);
extern void func_0013D680(StrP_5580* d, StrP_5580* s);
extern void func_00138B70(StrP_5580* s, int f);
extern void String_PushBack(StrP_5580* s, char c);
extern int String_AssignCStr_1C43A0(StrP_5580* s, char* c);
extern void func_00298690(Str2_5580* s);
extern void func_00138350(Str2_5580* s, int f);
extern Tok_5580* func_003B6150(Tok_5580* self, Str2_5580* out);
extern char* func_00189540(Str2_5580* s);
extern int func_00121BC8(char* s);
extern long long func_00121BB0(char* s);
extern float func_0011C928(long long a);
extern int func_002071F0(StrP_5580* s);
extern char* func_002071A0(StrP_5580* s);
extern int func_0022A360(Vec_5580* v, int* pos, int n, char* value);
extern void func_001C00D0(StrP_5580* out, StrP_5580* a, char* b);
extern char* String_CStr(StrP_5580* s);
extern unsigned int* func_0036D3C0(void* o, char* name, int n);
extern void Skas_RegisterClip(int* out, void* self, char* name, unsigned int* clip);
extern void AnchorKeys_Reserve(Vec_5580* v, unsigned int n);
extern void func_001396D0(Vec_5580* v, int n);
extern char D_004BD008[];
extern char D_00499C70[];
extern char D_004BCD78[];
extern char D_004BCD80[];
extern char D_004BCD90[];
extern char D_004BCDA0[];
extern char D_004BCDC0[];
extern char D_004BCDD0[];
extern char D_004BCDE0[];
#define isspace_(c) ((D_00499C70 + 1)[c] & 8)

}
#include "alloc_guard.h"
struct Str_5580 : StrP_5580 { Str_5580() { int i; unsigned int* p = &word; for (i = 0; i < 3; i++) *p++ = 0; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Str_5580() { func_00138B70(this, 0); } };
static inline void Str_Init(StrP_5580* s) { s->word = 0; s->length = 0; s->data = 0; }

static inline void ReadToken(Tok_5580* self, StrP_5580* out)
{
    int started;
    {
        StrP_5580 t;
        String_CtorCStr_13B480(&t, D_004BD008);
        func_0013D680(out, &t);
        func_00138B70(&t, 0);
    }
    started = 0;
    if (self->s) {
        for (; self->pos < self->s->len; self->pos++) {
            char c = self->s->data[self->pos];
            int sp = isspace_(c) != 0;
            if (!(unsigned char)started && !sp) started = 1;
            if ((unsigned char)started == 1) {
                if (sp) break;
                String_PushBack(out, c);
            }
        }
    }
    self->empty = (unsigned char)started == 0;
}

static inline int ReadInt0(Tok_5580* tok)
{
    int r;
    Str2_5580 t;
    func_00298690(&t);
    func_003B6150(tok, &t);
    r = func_00121BC8(func_00189540(&t));
    func_00138350(&t, -1);
    return r;
}

static inline void ReadFloat0(Tok_5580* tok, float* out)
{
    Str2_5580 t;
    func_00298690(&t);
    func_003B6150(tok, &t);
    *out = func_0011C928(func_00121BB0(func_00189540(&t)));
    func_00138350(&t, -1);
}

static inline int ReadInt(Tok_5580* tok) { return ReadInt0(tok); }
static inline void ReadFloat(Tok_5580* tok, float* out) { ReadFloat0(tok, out); }

#define RET return

extern "C" void Skas_Load(Skas_5580* self, Tok_5580* tok, void* list)
{
    char key[4];
    int clipRes;
    Str_5580 a;
    Str_5580 b;
    Str_5580 c;
    StrP_5580 tmp;
    int count;
    unsigned int pass;
    count = 0;
    for (pass = 0; pass < 2; pass++) {
        int state = 0;
        int nKeys = 0;
        int nClips = 0;
        while (!tok->empty) {
            ReadToken(tok, &a);
            switch (state) {
            case 0:
                if (!tok->empty) {
                    if (String_AssignCStr_1C43A0(&a, D_004BCD80) == 0) {
                        ReadToken(tok, &a);
                        if (!tok->empty && String_AssignCStr_1C43A0(&a, D_004BCD90) == 0) state++;
                        else RET;
                    } else {
                        if (String_AssignCStr_1C43A0(&a, D_004BCDA0) == 0 || String_AssignCStr_1C43A0(&a, D_004BCDC0) == 0) RET;
                    }
                } else RET;
                break;
            case 1:
                if (!tok->empty) {
                    if (String_AssignCStr_1C43A0(&a, D_004BCDD0) == 0) {
                        count = ReadInt(tok);
                        if (!tok->empty) {
                            state++;
                            if (count > 1) RET;
                        } else RET;
                        break;
                    }
                } else RET;
                if (String_AssignCStr_1C43A0(&a, D_004BCDA0) != 0) break;
                state++;            case 2:
                if (!tok->empty) {
                    if (String_AssignCStr_1C43A0(&a, D_004BCDA0) == 0) {
                        ReadFloat(tok, &self->f0);
                        if (!tok->empty) state++;
                        else RET;
                    } else {
                        if (String_AssignCStr_1C43A0(&a, D_004BCDC0) == 0) RET;
                    }
                } else RET;
                break;
            case 3:
                if (!tok->empty) {
                    if (String_AssignCStr_1C43A0(&a, D_004BCDE0) == 0) {
                        ReadToken(tok, &a);
                        if (!tok->empty) {
                            switch (pass) {
                            case 0:
                                nKeys++;
                                break;
                            case 1: {
                                int i;
                                for (i = 0; i < sizeof(key); i++)
                                    key[i] = (i < func_002071F0(&a)) ? func_002071A0(&a)[i] : 0;
                                func_0022A360(&self->keys, self->keys.data + self->keys.count, 1, key);
                                break;
                            }
                            }
                        } else RET;
                    } else if (String_AssignCStr_1C43A0(&a, D_004BCDC0) == 0) {
                        ReadToken(tok, &a);
                        if (!tok->empty) {
                            switch (pass) {
                            case 0:
                                nClips++;
                                break;
                            case 1: {
                                unsigned int* clip;
                                if (count > 0) {
                                    func_0013D680(&c, &a);
                                    ReadToken(tok, &a);
                                }
                                func_001C00D0(&tmp, &a, D_004BCD78);
                                func_0013D680(&b, &tmp);
                                func_00138B70(&tmp, 0);
                                clip = func_0036D3C0(list, String_CStr(&b), 0);
                                if (!clip) RET;
                                if (*clip > 3) RET;
                                if (count > 0) {
                                    char name[0x30];
                                    int i;
                                    for (i = 0; i < 0x2F; i++)
                                        name[i] = (i < func_002071F0(&c)) ? func_002071A0(&c)[i] : 0;
                                    name[i] = 0;
                                    Skas_RegisterClip(&clipRes, self, name, clip);
                                }
                                break;
                            }
                            }
                        } else RET;
                    } else if (String_AssignCStr_1C43A0(&a, D_004BCD80) == 0 || String_AssignCStr_1C43A0(&a, D_004BCDA0) == 0) {
                        RET;
                    }
                }
                break;
            }
        }
        if (pass == 0) {
            AnchorKeys_Reserve(&self->keys, nKeys);
            func_001396D0(&self->clips, nClips);
            tok->pos = 0;
            tok->empty = 0;
        }
    }
}
