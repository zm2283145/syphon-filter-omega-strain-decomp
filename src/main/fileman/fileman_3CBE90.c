/*
 * main/fileman: 4 files, 003CBE90-003CC060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CBE90 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Reserve(char *, int);                           
int FileMan_LoadMemberSync(char *, int *, int);                     
char * func_0036DD80(char *);                           
int func_0036DEC0(char *);                               
int FileMan_FindMember(char *);                             
int FileMan_Release(char *, int);                            
int func_0036E4B0(char *, int, int, int);                    
extern int D_00543658;
extern int D_00543660;
extern unsigned char D_00543668;
extern char D_00543680;
extern char D_005436A0;

int func_003CBE90(int arg0) {
    int sp10[40];

    if (D_00543668 == 0) {
        func_0036E4B0(sp10, arg0, 0, 0);
        if (!(FileMan_FindMember(sp10) & 0xFF)) {
            D_00543660 = F_(func_0036DD80(sp10), 0x2C, int);
            D_00543658 = 0;
            FileMan_LoadMemberSync(sp10, &D_00543658, 0);
            func_0036DEC0(sp10);
            D_00543668 = 1;
            String_Reserve(&D_00543680, 0x40);
            String_Reserve(&D_005436A0, 0x40);
            FileMan_Release(sp10, -1);
            return 1;
        }
        FileMan_Release(sp10, -1);
        goto block_5;
    }
block_5:
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CBE90 */

/* merge_units: begin func_003CBF70 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } SBF70L;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; char buf[11]; } SBF70S;
typedef struct { union { SBF70L l; SBF70S s; } u; } SBF70;
extern int func_003CBFB0(const SBF70* self, const char* s, unsigned int pos, unsigned int n);
static inline unsigned char SBF70_ShortLen(const SBF70* s) { return s->u.s.len; }
int func_003CBF70(const SBF70* self, const SBF70* str, unsigned int pos)
{
    const char* d;
    unsigned int n;
    if (!(str->u.l.word & 1)) {
        d = str->u.s.buf;
        n = SBF70_ShortLen(str);
    } else {
        d = str->u.l.data;
        n = str->u.l.length;
    }
    return func_003CBFB0(self, d, pos, n);
}
#pragma pop /* merge_units */
/* merge_units: end func_003CBF70 */

/* merge_units: begin func_003CBFB0 */
#pragma push /* merge_units */
int func_003CBFB0(const SBF70* self, const char* s, unsigned int pos, unsigned int n)
{
    const char* d;
    unsigned int size;
    unsigned int rem;
    const char* end;
    const char* p;
    if (!(self->u.l.word & 1)) {
        d = self->u.s.buf;
        size = SBF70_ShortLen(self);
    } else {
        d = self->u.l.data;
        size = self->u.l.length;
    }
    if (pos <= size) {
        p = d + pos;
        end = s + n;
        rem = size - pos;
        for (; rem >= n; rem--, p++) {
            const char* b = p;
            const char* a = s;
            for (; a < end; a++, b++) {
                if (*a != *b) goto next;
            }
            return p - d;
        next:;
        }
    }
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CBFB0 */

/* merge_units: begin func_003CC060 */
#pragma push /* merge_units */
typedef struct { unsigned char m0; int m4; int m8; int mC; } TC060;
#if 0 /* merge_units */
extern int FileMan_FindMember(void* src);
#endif /* merge_units */
#define FileMan_FindMember(a0) (FileMan_FindMember((char *)(a0))) /* merge_units */

extern int FileMan_GetSize(void* src);
#if 0 /* merge_units */
extern void FileMan_LoadMemberSync(void* src, int* out, int z);
#endif /* merge_units */
#define FileMan_LoadMemberSync(a0, a1, a2) ((void)FileMan_LoadMemberSync((char *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_0036DEC0(void* src);
#endif /* merge_units */
#define func_0036DEC0(a0) ((void)func_0036DEC0((char *)(a0))) /* merge_units */

unsigned char FileMan_LoadFile(TC060* self, void* src)
{
    if (!(unsigned char)FileMan_FindMember(src)) {
        self->mC = FileMan_GetSize(src);
        self->m8 = 0;
        FileMan_LoadMemberSync(src, &self->m8, 0);
        func_0036DEC0(src);
        self->m4 = self->m8;
        self->m0 = 1;
        return 1;
    }
    return 0;
}
#undef FileMan_FindMember /* merge_units */
#undef FileMan_LoadMemberSync /* merge_units */
#undef func_0036DEC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC060 */
