/*
 * main/ska: range (6 files, 003B5300-003B6270)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B5300 */
#pragma push /* merge_units */
#include "types.h"
extern void func_003B71A0(int a, int b, int c, int d, int e);
void func_003B5300(int a, int b, int c, int d) {
    func_003B71A0(a, b, c, d, b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B5300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B5300 */

/* merge_units: begin func_003B5310 */
#pragma push /* merge_units */
void Skas_AppendAnimation(int a, void* str, unsigned int* desc); /* gsynth: defined below */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_5310;
struct Buf_5310 { char* p; };
typedef struct { int a; char name[1]; } File_5310;
typedef struct { char pad[0x14]; char list[1]; } Self_5310;
extern "C" {
int FileMan_FindMember(File_5310* f);
int FileMan_GetSize(File_5310* f);
int FileMan_LoadMemberSync(File_5310* f, char** buf, int size);
void func_0036DEC0(File_5310* f);
void* Mem_Alloc(int a, int size, char* file, int line);
void String_CtorCStr_13B480(Str_5310* s, char* c);
void String_Dtor(Str_5310* s, int f);
#if 0 /* merge_units */
void Skas_AppendAnimation(Self_5310* self, Str_5310* s, char* buf);
#endif /* merge_units */
#define Skas_AppendAnimation(a0, a1, a2) (Skas_AppendAnimation((int)(a0), (void *)(a1), (unsigned int *)(a2))) /* merge_units */

void func_00146000(void* list, struct Buf_5310* buf);
extern char D_004BCD70;
}
static inline void MemCopy_5310(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
extern "C" void func_003B5310(Self_5310* self, File_5310* f)
{
    Buf_5310 buf;
    Buf_5310 tmp;
    int size;
    int r;
    if (FileMan_FindMember(f) & 0xFF) return;
    size = FileMan_GetSize(f);
    { char* p; { AllocGuard g; p = (char*)Mem_Alloc(0, size, &D_004BCD70, 0x1A3); } buf.p = p; }
    if (!buf.p) return;
    tmp = buf;
    r = FileMan_LoadMemberSync(f, &tmp.p, size);
    func_0036DEC0(f);
    if (r & 0xFF) return;
    { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_5310(dst, src, size); }
    {
        Str_5310 s;
        String_CtorCStr_13B480(&s, f->name);
        Skas_AppendAnimation(self, &s, buf.p);
        String_Dtor(&s, 0);
    }
    func_00146000(self->list, &buf);
}
#undef Skas_AppendAnimation /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B5310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B5310 */

/* merge_units: begin func_003B54C0 */
#pragma push /* merge_units */
extern int String_Length(void* s);
extern char* String_CStr_Thunk(void* s);
extern void Skas_RegisterClip(int* out, int a, char* name, unsigned int* desc);

void Skas_AppendAnimation(int a, void* str, unsigned int* desc)
{
    int out;
    char buf[0x30];
    if (*desc < 4) {
        int i;
        for (i = 0; i < 0x2F; i++) {
            char c;
            if (i < String_Length(str)) c = String_CStr_Thunk(str)[i]; else c = 0;
            buf[i] = c;
        }
        buf[i] = 0;
        Skas_RegisterClip(&out, a, buf, desc);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B54C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B54C0 */

/* merge_units: begin func_003B5580 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_6150;
typedef struct { char* data; unsigned int len; } Src_6150;
typedef struct { Src_6150* s; unsigned int pos; unsigned char empty; } Tok_6150;
Tok_6150* func_003B6150(Tok_6150* self, Str_6150* out); /* gsynth: defined below */
#pragma cplusplus on
#pragma inline_depth(8)
extern "C" {struct StrP_5580 { unsigned int word; unsigned int length; char* data; };
typedef struct { unsigned int word; unsigned int length; char* data; } Str2_5580;
typedef struct { char* data; unsigned int len; } Src_5580;
typedef struct { Src_5580* s; unsigned int pos; unsigned char empty; } Tok_5580;
typedef struct { unsigned int cap; unsigned int count; int* data; } Vec_5580;
typedef struct { float f0; Vec_5580 keys; char pad10[0x24]; Vec_5580 clips; } Skas_5580;
#if 0 /* merge_units */
extern void String_CtorCStr_13B480(StrP_5580* s, char* c);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str_5310 *)(a0), (a1))) /* merge_units */

extern void String_AssignString(StrP_5580* d, StrP_5580* s);
#if 0 /* merge_units */
extern void String_Dtor(StrP_5580* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_5310 *)(a0), (a1))) /* merge_units */

extern void String_PushBack(StrP_5580* s, char c);
extern int String_AssignCStr_1C43A0(StrP_5580* s, char* c);
extern void String_CtorEmpty(Str2_5580* s);
extern void String_Dtor_138350(Str2_5580* s, int f);
#if 0 /* merge_units */
extern Tok_5580* func_003B6150(Tok_5580* self, Str2_5580* out);
#endif /* merge_units */
#define func_003B6150(a0, a1) ((Tok_5580 *)func_003B6150((Tok_6150 *)(a0), (Str_6150 *)(a1))) /* merge_units */

extern char* String_CStr_189540(Str2_5580* s);
extern int atoi(char* s);
extern long long atof(char* s);
extern float SoftFloat_DoubleToFloat(long long a);
#if 0 /* merge_units */
extern int String_Length(StrP_5580* s);
#endif /* merge_units */
#define String_Length(a0) (String_Length((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char* String_CStr_Thunk(StrP_5580* s);
#endif /* merge_units */
#define String_CStr_Thunk(a0) (String_CStr_Thunk((void *)(a0))) /* merge_units */

extern int Vector_Insert_22A360(Vec_5580* v, int* pos, int n, char* value);
extern void func_001C00D0(StrP_5580* out, StrP_5580* a, char* b);
extern char* String_CStr(StrP_5580* s);
extern unsigned int* func_0036D3C0(void* o, char* name, int n);
#if 0 /* merge_units */
extern void Skas_RegisterClip(int* out, void* self, char* name, unsigned int* clip);
#endif /* merge_units */
#define Skas_RegisterClip(a0, a1, a2, a3) (Skas_RegisterClip((a0), (int)(a1), (a2), (a3))) /* merge_units */

extern void AnchorKeys_Reserve(Vec_5580* v, unsigned int n);
extern void PtrVec_Reserve(Vec_5580* v, int n);
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

}struct Str_5580 : StrP_5580 { Str_5580() { int i; unsigned int* p = &word; for (i = 0; i < 3; i++) *p++ = 0; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Str_5580() { String_Dtor(this, 0); } };
static inline void Str_Init(StrP_5580* s) { s->word = 0; s->length = 0; s->data = 0; }

static inline void ReadToken(Tok_5580* self, StrP_5580* out)
{
    int started;
    {
        StrP_5580 t;
        String_CtorCStr_13B480(&t, D_004BD008);
        String_AssignString(out, &t);
        String_Dtor(&t, 0);
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
    String_CtorEmpty(&t);
    func_003B6150(tok, &t);
    r = atoi(String_CStr_189540(&t));
    String_Dtor_138350(&t, -1);
    return r;
}

static inline void ReadFloat0(Tok_5580* tok, float* out)
{
    Str2_5580 t;
    String_CtorEmpty(&t);
    func_003B6150(tok, &t);
    *out = SoftFloat_DoubleToFloat(atof(String_CStr_189540(&t)));
    String_Dtor_138350(&t, -1);
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
                                    key[i] = (i < String_Length(&a)) ? String_CStr_Thunk(&a)[i] : 0;
                                Vector_Insert_22A360(&self->keys, self->keys.data + self->keys.count, 1, key);
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
                                    String_AssignString(&c, &a);
                                    ReadToken(tok, &a);
                                }
                                func_001C00D0(&tmp, &a, D_004BCD78);
                                String_AssignString(&b, &tmp);
                                String_Dtor(&tmp, 0);
                                clip = func_0036D3C0(list, String_CStr(&b), 0);
                                if (!clip) RET;
                                if (*clip > 3) RET;
                                if (count > 0) {
                                    char name[0x30];
                                    int i;
                                    for (i = 0; i < 0x2F; i++)
                                        name[i] = (i < String_Length(&c)) ? String_CStr_Thunk(&c)[i] : 0;
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
            PtrVec_Reserve(&self->clips, nClips);
            tok->pos = 0;
            tok->empty = 0;
        }
    }
}
#undef String_CtorCStr_13B480 /* merge_units */
#undef String_Dtor /* merge_units */
#undef func_003B6150 /* merge_units */
#undef String_Length /* merge_units */
#undef String_CStr_Thunk /* merge_units */
#undef Skas_RegisterClip /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B5580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B5580 */

/* merge_units: begin func_003B6150 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void String_CtorCStr_13B480(Str_6150* s, char* c);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_AssignString(Str_6150* d, Str_6150* s);
#endif /* merge_units */
#define String_AssignString(a0, a1) (String_AssignString((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(Str_6150* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_PushBack(Str_6150* s, char c);
#endif /* merge_units */
#define String_PushBack(a0, a1) (String_PushBack((void *)(a0), (a1))) /* merge_units */

Tok_6150* func_003B6150(Tok_6150* self, Str_6150* out)
{
    int started;
    {
        Str_6150 t;
        String_CtorCStr_13B480(&t, D_004BD008);
        String_AssignString(out, &t);
        String_Dtor(&t, 0);
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
    return self;
}
#undef String_CtorCStr_13B480 /* merge_units */
#undef String_AssignString /* merge_units */
#undef String_Dtor /* merge_units */
#undef String_PushBack /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B6150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B6150 */

/* merge_units: begin func_003B6270 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Load a SKA clip by (a, b) key, then finish registering it. */
struct Key_3B6270 { int a; int b; };
struct Desc_3B6270 { Key_3B6270* key; int n; unsigned char flag; };

extern "C" {
#if 0 /* merge_units */
void Skas_Load(void* self, Desc_3B6270* d, void* arg);
#endif /* merge_units */
#define Skas_Load(a0, a1, a2) (Skas_Load((Skas_5580 *)(a0), (Tok_5580 *)(a1), (a2))) /* merge_units */

void func_003B50A0(void* self, void* arg);
}

extern "C" void func_003B6270(void* self, int a, int b, void* arg)
{
    Key_3B6270 key;
    Desc_3B6270 d;
    key.b = 0;
    key.a = a;
    key.b = b;
    d.key = &key;
    d.n = 0;
    d.flag = 0;
    Skas_Load(self, &d, arg);
    func_003B50A0(self, arg);
}
#undef Skas_Load /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B6270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B6270 */
