/*
 * Libs/SFOLib/Source/ska: 9 files, 003B50A0-003B62E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B50A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_50A0;
typedef struct { char* p; } It_50A0;
typedef struct { char pad[0x148]; struct { int a; int n; }* p148; } Obj_50A0;
extern int cHogFile_GetBlock_int(Obj_50A0* o, int i);
extern char* cHogFile_GetBlockName(Obj_50A0* o, int i);
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_50A0* s, char* c);
#endif /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(void*, char*); /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(Str_50A0* s, int f);
#endif /* merge_units */
void String_Dtor(void* tmp, int flag); /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */

extern void std_basic_string_char_char_traits_char_begin(It_50A0* out, Str_50A0* s);
extern void std_basic_string_char_char_traits_char_end(It_50A0* out, Str_50A0* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_50A0* a, It_50A0* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_50A0* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_50A0* a);
extern int std_basic_string_char_char_traits_char_rfind_basicstringR_uint(Str_50A0* s, Str_50A0* t, int n);
#if 0 /* merge_units */
extern void cString_Substr(Str_50A0* out, Str_50A0* s, int a, int b);
#endif /* merge_units */
int cString_Substr(); /* merge_units */


#if 0 /* merge_units */
extern int cString_Length(Str_50A0* s);
#endif /* merge_units */
int cString_Length(void* s); /* merge_units */
#define cString_Length(a0) (cString_Length((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char* cString_opCast_constcharPtr(Str_50A0* s);
#endif /* merge_units */
char* cString_opCast_constcharPtr(void* s); /* merge_units */
#define cString_opCast_constcharPtr(a0) (cString_opCast_constcharPtr((void *)(a0))) /* merge_units */

extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(int* out, void* self, char* name, int clip);
extern char D_004BCD78[];

void cSkaAnimationSet_AddAllAnimationsFromSkaHog(void* self, Obj_50A0* o)
{
    int r;
    It_50A0 it;
    It_50A0 end;
    Str_50A0 s;
    Str_50A0 t;
    Str_50A0 u;
    char name[0x30];
    int n = o->p148->n;
    int i;
    for (i = 0; i < n; i++) {
        int clip = cHogFile_GetBlock_int(o, i);
        if (clip) {
            int idx;
            std_basic_string_char_char_traits_char_ctor_charP(&s, cHogFile_GetBlockName(o, i));
            std_basic_string_char_char_traits_char_begin(&it, &s);
            std_basic_string_char_char_traits_char_end(&end, &s);
            while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
                if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
                std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
            }
            std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BCD78);
            idx = std_basic_string_char_char_traits_char_rfind_basicstringR_uint(&s, &t, -1);
            String_Dtor(&t, 0);
            if (idx != -1) {
                int j;
                cString_Substr(&u, &s, 0, idx);
                for (j = 0; j < 47; j++) {
                    name[j] = (j < cString_Length(&u)) ? cString_opCast_constcharPtr(&u)[j] : 0;
                }
                name[j] = 0;
                String_Dtor(&u, 0);
                cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(&r, self, name, clip);
            }
            String_Dtor(&s, 0);
        }
    }
}
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef String_Dtor /* merge_units */
#undef cString_Length /* merge_units */
#undef cString_opCast_constcharPtr /* merge_units */
static inline void merge_flush_func_003B50A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B50A0 */

/* merge_units: begin func_003B52B0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_substr(void* tmp);
#endif /* merge_units */
void std_basic_string_char_char_traits_char_substr(); /* merge_units */

extern void std_basic_string_char_char_traits_char_ctor_basicstringR(void* self, void* tmp);
extern void String_Dtor(void* tmp, int flag);


/* Builds a temporary object, applies it to self, then destroys it; returns 0. */
int cString_Substr(void* self) {
    char tmp[16];
    std_basic_string_char_char_traits_char_substr(tmp);
    std_basic_string_char_char_traits_char_ctor_basicstringR(self, tmp);
    String_Dtor(tmp, -1);
    return 0;
}
static inline void merge_flush_func_003B52B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B52B0 */

/* merge_units: begin func_003B5300 */
#pragma push /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_basicstringR_uint_uint_cAllocatorR(int a, int b, int c, int d, int e);
void std_basic_string_char_char_traits_char_substr(int a, int b, int c, int d) {
    std_basic_string_char_char_traits_char_ctor_basicstringR_uint_uint_cAllocatorR(a, b, c, d, b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B5300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B5300 */

/* merge_units: begin func_003B5310 */
#pragma push /* merge_units */
void cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(int a, void* str, unsigned int* desc); /* gsynth: defined below */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_5310;
struct Buf_5310 { char* p; };
typedef struct { int a; char name[1]; } File_5310;
typedef struct { char pad[0x14]; char list[1]; } Self_5310;
extern "C" {
int cFileMan_Open(File_5310* f);
int cFileMan_GetSize(File_5310* f);
int cFileMan_Read_charPP_int(File_5310* f, char** buf, int size);
void cFileMan_Close(File_5310* f);
void* cMemMan_Allocate(int a, int size, char* file, int line);
#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_5310* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(Str_5310* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(Self_5310* self, Str_5310* s, char* buf);
#endif /* merge_units */
void cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(int a, void* str, unsigned int* desc); /* merge_units */
#define cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(a0, a1, a2) (cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR((int)(a0), (void *)(a1), (unsigned int *)(a2))) /* merge_units */


void std_vector_charPtr_push_back_charPR(void* list, struct Buf_5310* buf);
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
extern "C" void cSkaAnimationSet_AddAnimation_cFileManR(Self_5310* self, File_5310* f)
{
    Buf_5310 buf;
    Buf_5310 tmp;
    int size;
    int r;
    if (cFileMan_Open(f) & 0xFF) return;
    size = cFileMan_GetSize(f);
    { char* p; { AllocGuard g; p = (char*)cMemMan_Allocate(0, size, &D_004BCD70, 0x1A3); } buf.p = p; }
    if (!buf.p) return;
    tmp = buf;
    r = cFileMan_Read_charPP_int(f, &tmp.p, size);
    cFileMan_Close(f);
    if (r & 0xFF) return;
    { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_5310(dst, src, size); }
    {
        Str_5310 s;
        std_basic_string_char_char_traits_char_ctor_charP(&s, f->name);
        cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(self, &s, buf.p);
        String_Dtor(&s, 0);
    }
    std_vector_charPtr_push_back_charPR(self->list, &buf);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B5310(void) {}
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef String_Dtor /* merge_units */
#undef cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B5310 */

/* merge_units: begin func_003B54C0 */
#pragma push /* merge_units */
extern int cString_Length(void* s);
extern char* cString_opCast_constcharPtr(void* s);
#if 0 /* merge_units */
extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(int* out, int a, char* name, unsigned int* desc);
#endif /* merge_units */
#define cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(a0, a1, a2, a3) (cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR((a0), (void *)(a1), (a2), (int)(a3))) /* merge_units */


void cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(int a, void* str, unsigned int* desc)
{
    int out;
    char buf[0x30];
    if (*desc < 4) {
        int i;
        for (i = 0; i < 0x2F; i++) {
            char c;
            if (i < cString_Length(str)) c = cString_opCast_constcharPtr(str)[i]; else c = 0;
            buf[i] = c;
        }
        buf[i] = 0;
        cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(&out, a, buf, desc);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B54C0(void) {}
#undef cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B54C0 */

/* merge_units: begin func_003B5580 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_6150;
typedef struct { char* data; unsigned int len; } Src_6150;
typedef struct { Src_6150* s; unsigned int pos; unsigned char empty; } Tok_6150;
Tok_6150* cSkaAnimationSet_cMyIStream_opShr(Tok_6150* self, Str_6150* out); /* gsynth: defined below */
#pragma cplusplus on
#pragma inline_depth(8)
extern "C" {struct StrP_5580 { unsigned int word; unsigned int length; char* data; };
typedef struct { unsigned int word; unsigned int length; char* data; } Str2_5580;
typedef struct { char* data; unsigned int len; } Src_5580;
typedef struct { Src_5580* s; unsigned int pos; unsigned char empty; } Tok_5580;
typedef struct { unsigned int cap; unsigned int count; int* data; } Vec_5580;
typedef struct { float f0; Vec_5580 keys; char pad10[0x24]; Vec_5580 clips; } Skas_5580;
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(StrP_5580* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_assign_basicstringR(StrP_5580* d, StrP_5580* s);
#endif /* merge_units */
void std_basic_string_char_char_traits_char_assign_basicstringR(void*, void*); /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) (std_basic_string_char_char_traits_char_assign_basicstringR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(StrP_5580* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_opAddAssign(StrP_5580* s, char c);
#endif /* merge_units */
void std_basic_string_char_char_traits_char_opAddAssign(void*, char); /* merge_units */
#define std_basic_string_char_char_traits_char_opAddAssign(a0, a1) (std_basic_string_char_char_traits_char_opAddAssign((void *)(a0), (a1))) /* merge_units */

extern int std_basic_string_char_char_traits_char_compare_charP(StrP_5580* s, char* c);
extern void cString_ctor_void(Str2_5580* s);
extern void String_Dtor_138350(Str2_5580* s, int f);
#if 0 /* merge_units */
extern Tok_5580* cSkaAnimationSet_cMyIStream_opShr(Tok_5580* self, Str2_5580* out);
#endif /* merge_units */
Tok_6150* cSkaAnimationSet_cMyIStream_opShr(Tok_6150* self, Str_6150* out); /* merge_units */
#define cSkaAnimationSet_cMyIStream_opShr(a0, a1) ((Tok_5580 *)cSkaAnimationSet_cMyIStream_opShr((Tok_6150 *)(a0), (Str_6150 *)(a1))) /* merge_units */


extern char* cString_CStr(Str2_5580* s);
extern int atoi(char* s);
extern long long atof(char* s);
extern float SoftFloat_DoubleToFloat(long long a);
#if 0 /* merge_units */
extern int cString_Length(StrP_5580* s);
#endif /* merge_units */
#define cString_Length(a0) (cString_Length((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern char* cString_opCast_constcharPtr(StrP_5580* s);
#endif /* merge_units */
#define cString_opCast_constcharPtr(a0) (cString_opCast_constcharPtr((void *)(a0))) /* merge_units */


extern int std_vector_imp_cString4_insert(Vec_5580* v, int* pos, int n, char* value);
extern void opAdd_cStringR_charP(StrP_5580* out, StrP_5580* a, char* b);
extern char* std_basic_string_char_char_traits_char_c_str(StrP_5580* s);
extern unsigned int* cHogFile_GetBlock_charP_bool(void* o, char* name, int n);
#if 0 /* merge_units */
extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(int* out, void* self, char* name, unsigned int* clip);
#endif /* merge_units */
#define cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(a0, a1, a2, a3) (cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR((a0), (a1), (a2), (int)(a3))) /* merge_units */


extern void std_vector_imp_cString4_reserve(Vec_5580* v, unsigned int n);
extern void std_vector_pod_int_reserve(Vec_5580* v, int n);
extern char D_004BD008[];
extern char D_00499C70[];
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
        std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BD008);
        std_basic_string_char_char_traits_char_assign_basicstringR(out, &t);
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
                std_basic_string_char_char_traits_char_opAddAssign(out, c);
            }
        }
    }
    self->empty = (unsigned char)started == 0;
}

static inline int ReadInt0(Tok_5580* tok)
{
    int r;
    Str2_5580 t;
    cString_ctor_void(&t);
    cSkaAnimationSet_cMyIStream_opShr(tok, &t);
    r = atoi(cString_CStr(&t));
    String_Dtor_138350(&t, -1);
    return r;
}

static inline void ReadFloat0(Tok_5580* tok, float* out)
{
    Str2_5580 t;
    cString_ctor_void(&t);
    cSkaAnimationSet_cMyIStream_opShr(tok, &t);
    *out = SoftFloat_DoubleToFloat(atof(cString_CStr(&t)));
    String_Dtor_138350(&t, -1);
}

static inline int ReadInt(Tok_5580* tok) { return ReadInt0(tok); }
static inline void ReadFloat(Tok_5580* tok, float* out) { ReadFloat0(tok, out); }

#define RET return

extern "C" void cSkaAnimationSet_InitWithSkasFile(Skas_5580* self, Tok_5580* tok, void* list)
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
                    if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCD80) == 0) {
                        ReadToken(tok, &a);
                        if (!tok->empty && std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCD90) == 0) state++;
                        else RET;
                    } else {
                        if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDA0) == 0 || std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDC0) == 0) RET;
                    }
                } else RET;
                break;
            case 1:
                if (!tok->empty) {
                    if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDD0) == 0) {
                        count = ReadInt(tok);
                        if (!tok->empty) {
                            state++;
                            if (count > 1) RET;
                        } else RET;
                        break;
                    }
                } else RET;
                if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDA0) != 0) break;
                state++;            case 2:
                if (!tok->empty) {
                    if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDA0) == 0) {
                        ReadFloat(tok, &self->f0);
                        if (!tok->empty) state++;
                        else RET;
                    } else {
                        if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDC0) == 0) RET;
                    }
                } else RET;
                break;
            case 3:
                if (!tok->empty) {
                    if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDE0) == 0) {
                        ReadToken(tok, &a);
                        if (!tok->empty) {
                            switch (pass) {
                            case 0:
                                nKeys++;
                                break;
                            case 1: {
                                int i;
                                for (i = 0; i < sizeof(key); i++)
                                    key[i] = (i < cString_Length(&a)) ? cString_opCast_constcharPtr(&a)[i] : 0;
                                std_vector_imp_cString4_insert(&self->keys, self->keys.data + self->keys.count, 1, key);
                                break;
                            }
                            }
                        } else RET;
                    } else if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDC0) == 0) {
                        ReadToken(tok, &a);
                        if (!tok->empty) {
                            switch (pass) {
                            case 0:
                                nClips++;
                                break;
                            case 1: {
                                unsigned int* clip;
                                if (count > 0) {
                                    std_basic_string_char_char_traits_char_assign_basicstringR(&c, &a);
                                    ReadToken(tok, &a);
                                }
                                opAdd_cStringR_charP(&tmp, &a, D_004BCD78);
                                std_basic_string_char_char_traits_char_assign_basicstringR(&b, &tmp);
                                String_Dtor(&tmp, 0);
                                clip = cHogFile_GetBlock_charP_bool(list, std_basic_string_char_char_traits_char_c_str(&b), 0);
                                if (!clip) RET;
                                if (*clip > 3) RET;
                                if (count > 0) {
                                    char name[0x30];
                                    int i;
                                    for (i = 0; i < 0x2F; i++)
                                        name[i] = (i < cString_Length(&c)) ? cString_opCast_constcharPtr(&c)[i] : 0;
                                    name[i] = 0;
                                    cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(&clipRes, self, name, clip);
                                }
                                break;
                            }
                            }
                        } else RET;
                    } else if (std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCD80) == 0 || std_basic_string_char_char_traits_char_compare_charP(&a, D_004BCDA0) == 0) {
                        RET;
                    }
                }
                break;
            }
        }
        if (pass == 0) {
            std_vector_imp_cString4_reserve(&self->keys, nKeys);
            std_vector_pod_int_reserve(&self->clips, nClips);
            tok->pos = 0;
            tok->empty = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B5580(void) {}
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
#undef String_Dtor /* merge_units */
#undef std_basic_string_char_char_traits_char_opAddAssign /* merge_units */
#undef cSkaAnimationSet_cMyIStream_opShr /* merge_units */
#undef cString_Length /* merge_units */
#undef cString_opCast_constcharPtr /* merge_units */
#undef cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B5580 */

/* merge_units: begin func_003B6150 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_6150* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_assign_basicstringR(Str_6150* d, Str_6150* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) (std_basic_string_char_char_traits_char_assign_basicstringR((void *)(a0), (void *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void String_Dtor(Str_6150* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_opAddAssign(Str_6150* s, char c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_opAddAssign(a0, a1) (std_basic_string_char_char_traits_char_opAddAssign((void *)(a0), (a1))) /* merge_units */


Tok_6150* cSkaAnimationSet_cMyIStream_opShr(Tok_6150* self, Str_6150* out)
{
    int started;
    {
        Str_6150 t;
        std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BD008);
        std_basic_string_char_char_traits_char_assign_basicstringR(out, &t);
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
                std_basic_string_char_char_traits_char_opAddAssign(out, c);
            }
        }
    }
    self->empty = (unsigned char)started == 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B6150(void) {}
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
#undef String_Dtor /* merge_units */
#undef std_basic_string_char_char_traits_char_opAddAssign /* merge_units */
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
void cSkaAnimationSet_InitWithSkasFile(void* self, Desc_3B6270* d, void* arg);
#endif /* merge_units */
#define cSkaAnimationSet_InitWithSkasFile(a0, a1, a2) (cSkaAnimationSet_InitWithSkasFile((Skas_5580 *)(a0), (Tok_5580 *)(a1), (a2))) /* merge_units */


#if 0 /* merge_units */
void cSkaAnimationSet_AddAllAnimationsFromSkaHog(void* self, void* arg);
#endif /* merge_units */
#define cSkaAnimationSet_AddAllAnimationsFromSkaHog(a0, a1) (cSkaAnimationSet_AddAllAnimationsFromSkaHog((a0), (Obj_50A0 *)(a1))) /* merge_units */

}

extern "C" void cSkaAnimationSet_InitWithSkasFile_And_AddAllAnimationsFromSkaHog(void* self, int a, int b, void* arg)
{
    Key_3B6270 key;
    Desc_3B6270 d;
    key.b = 0;
    key.a = a;
    key.b = b;
    d.key = &key;
    d.n = 0;
    d.flag = 0;
    cSkaAnimationSet_InitWithSkasFile(self, &d, arg);
    cSkaAnimationSet_AddAllAnimationsFromSkaHog(self, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B6270(void) {}
#undef cSkaAnimationSet_InitWithSkasFile /* merge_units */
#undef cSkaAnimationSet_AddAllAnimationsFromSkaHog /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B6270 */

/* merge_units: begin func_003B62E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* cSkaAnimationSet_dtor: skeleton-set destructor (ska.cc): delete the owned objects of the vector at
 * +0x34, free the map values at +0x44 and the buffers of the vector at +0x14, run the member
 * destructors and free the object when the delete flag is positive. */

struct Obj { virtual void Destroy(int flag); };
struct It { void* p; };
struct Raw { void* p; };
struct MapNode { char pad[0x30]; void* value; };

struct SkSet {
    int x0;
    char v4[0x10];
    char v14[0x10];
    char v24[0x10];
    char v34[0x10];
    char m44[0x10];
};

extern "C" {
#if 0 /* merge_units */
extern char D_004BCD70[];
#endif /* merge_units */
#define D_004BCD70 ((char*)&D_004BCD70) /* merge_units */

void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void operator_delete(void* p);
void* std_vector_imp_cSkaNodePtr_1_begin(void* v);
void std_vector_cSkaNodePtr_pointer2iterator(It* out, void* v, void* const& r);
Raw std_vector_cSkaNodePtr_end(void* v);
void cArray_cSkaNodePtr_Iterator_ctor(It* out, const Raw& r);
void std_tree_pair_cString16N_value_compare_cAllocator_pair_begin(It* out, void* m);
void std_tree_pair_cString16N_value_compare_cAllocator_pair_end(It* out, void* m);
void std_red_black_tree_1_increment(It* it);
void* std_vector_imp_charPtr_1_begin(void* v);
void* std_vector_imp_charPtr_1_end(void* v);
void std_vector_charPtr_pointer2iterator(It* out, void* v, void* const& r);
void std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_dtor(void* p, int flag);
void std_vector_cSkaNodePtr_dtor(void* p, int flag);
void std_map_cString16N_3_int_cAllocator_pair_dtor(void* p, int flag);
void std_vector_charPtr_dtor_void(void* p, int flag);
void std_vector_deleter_cString4_dtor(void* p, int flag);
SkSet* cSkaAnimationSet_dtor(SkSet* s, short flag);
}

static inline Raw MkRaw(void* p) { Raw r; r.p = p; return r; }
static inline int Eq(void* a, void* b) { return a == b; }

#pragma bool off
SkSet* cSkaAnimationSet_dtor(SkSet* s, short flag)
{
    It itB;
    if (s) {
        {
            It e;
            It b;
            Obj* o;
            Obj** it;
            std_vector_cSkaNodePtr_pointer2iterator(&b, s->v34, std_vector_imp_cSkaNodePtr_1_begin(s->v34));
            it = (Obj**)b.p;
            while ((cArray_cSkaNodePtr_Iterator_ctor(&e, std_vector_cSkaNodePtr_end(s->v34)), Eq(it, e.p) ^ 1)) {
                o = *it;
                {
                    AllocGuard g;
                    o->Destroy(-1);
                    cMemMan_Deallocate(0, o, D_004BCD70, 0x35);
                }
                it++;
            }
        }
        {
            It b;
            It e;
            MapNode* end;
            std_tree_pair_cString16N_value_compare_cAllocator_pair_begin(&b, s->m44);
            itB = b;
            std_tree_pair_cString16N_value_compare_cAllocator_pair_end(&e, s->m44);
            end = (MapNode*)e.p;
            while (Eq(itB.p, end) ^ 1) {
                void* v = ((MapNode*)itB.p)->value;
                {
                    AllocGuard g;
                    cMemMan_Deallocate(0, v, D_004BCD70, 0x42);
                }
                std_red_black_tree_1_increment(&itB);
            }
        }
        {
            It b;
            It e;
            void** it;
            void** end;
            std_vector_charPtr_pointer2iterator(&b, s->v14, std_vector_imp_charPtr_1_begin(s->v14));
            it = (void**)b.p;
            std_vector_charPtr_pointer2iterator(&e, s->v14, std_vector_imp_charPtr_1_end(s->v14));
            end = (void**)e.p;
            /* volatile: retail re-reads e.p for the entry test (end is loaded in the delay slot) */
            if (Eq(it, *(void** volatile*)&e.p) ^ 1) {
                do {
                    void* v = *it;
                    {
                        AllocGuard g;
                        cMemMan_Deallocate(0, v, D_004BCD70, 0x4F);
                    }
                    it++;
                } while (Eq(it, end) ^ 1);
            }
        }
        if (s->m44) std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_dtor(s->m44, -1);
        if (s->v34) std_vector_cSkaNodePtr_dtor(s->v34, -1);
        if (s->v24) std_map_cString16N_3_int_cAllocator_pair_dtor(s->v24, -1);
        if (s->v14) std_vector_charPtr_dtor_void(s->v14, -1);
        { void* p = s->v4; if (p) if (p) if (p) std_vector_deleter_cString4_dtor(p, 0); }
        if (flag > 0) operator_delete(s);
    }
    return s;
}
#undef D_004BCD70 /* merge_units */
static inline void merge_flush_func_003B62E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B62E0 */
