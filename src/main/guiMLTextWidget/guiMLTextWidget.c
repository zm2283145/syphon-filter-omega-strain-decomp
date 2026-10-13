/*
 * main/guiMLTextWidget: 2 files, 0043DB80-0043DCE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043DB80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_DB80 { int p; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, void*, char**, char**);
Raw_DB80 func_0013B180(void*);
Raw_DB80 func_0043DB60(void*);
void func_0043DB70(char**, const Raw_DB80&);
void func_0043DB50(char**, const Raw_DB80&);
void func_0043BC70(void*, int, int, int, int);
}
struct S_DB80 { char pad[0x64]; int f64; int f68; int f6C; int f70; int f74; int f78; void* f7C; };
static inline void Upd_DB80(S_DB80* s) { func_0043BC70(s->f7C, 0, s->f68, 0, s->f70 - s->f64); }
extern "C" void func_0043DB80(char* self) {
    {
        char* end;
        {
            char* n;
            char* it;
            func_0043DB70(&it, func_0013B180(self + 0x70));
            n = it;
            while ((func_0043DB50(&end, func_0043DB60(self + 0x70)), n != end)) {
                void* e = F_(n, 0x8, void*);
                {
                    AllocGuard g;
                    Mem_Free(0, e, "guiMLTextWidget.cc", 0xCB);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            int res;
            char* first;
            char* last;
            last = self + 0x74;
            first = F_(self, 0x78, char*);
            ObjectList_EraseRange(&res, self + 0x70, &first, &last);
        }
    }
    S_DB80* s = (S_DB80*)self;
    s->f68 = 0;
    if (s->f7C) func_0043BC70(s->f7C, 0, s->f68, 0, s->f70 - s->f64);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043DB80 */

/* merge_units: begin func_0043DCE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Node_DCE0 { Node_DCE0* prev; Node_DCE0* next; char* str; };
extern "C" {
extern char D_004C0110[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
int func_0036AA50(void* font, const char* s, int n);
void func_0043E0B0(void* list, char* const& v);
void func_00138DA0(void* res, void* list, Node_DCE0* const& it);
char* strncpy(char*, const char*, int);
}

struct S_DCE0 {
    char pad[0x3C]; float f3C; char p40[0xC]; void* f4C; char p50[0x10];
    int f60; int f64; int f68; int f6C; int f70; int f74; Node_DCE0* f78; void* f7C;
};
extern "C" void func_0043DCE0(S_DCE0* self, char* text)
{
    char* cur;
    char* start;
    char* brk;
    int width;
    char* line;
    char* line2;
    if (text == 0 || *text == 0) return;
    cur = text;
    start = text;
    width = (int)self->f3C;
    brk = 0;
    while (*cur) {
        if (*cur == '\n' || func_0036AA50(self->f4C, start, cur - start + 1) >= width) {
            if (*cur == '\n') {
                brk = cur;
                cur++;
            } else {
                brk = brk ? brk : cur - 1;
                if (!(start < brk)) return;
            }
            {
                int n = brk - start;
                char* p;
                int i;
                {
                    AllocGuard g;
                    p = (char*)Mem_Alloc(0, n + 2, D_004C0110, 0x93);
                }
                line = p;
                strncpy(p + 1, start, n);
                line[0] = self->f6C + 0x10;
                line[n + 1] = 0;
                for (i = 0; i < n + 1; i++) {
                    char c = line[i];
                    if (c >= 0x10 && c < 0x18) self->f6C = c - 0x10;
                }
                func_0043E0B0(&self->f70, line);
                start = brk + 1;
                brk = 0;
            }
        } else {
            if (*cur == ' ') brk = cur;
            cur++;
        }
    }
    if (start < cur) {
        int n = cur - start;
        char* p;
        {
            AllocGuard g;
            p = (char*)Mem_Alloc(0, n + 1, D_004C0110, 0xB1);
        }
        line2 = p;
        strncpy(p, start, n);
        line2[n] = 0;
        func_0043E0B0(&self->f70, line2);
    }
    if (self->f60) {
        while (self->f70 > self->f60) {
            char* s = self->f78->str;
            {
                AllocGuard g;
                Mem_Free(0, s, D_004C0110, 0xBF);
            }
            {
                int res;
                Node_DCE0* it = self->f78;
                func_00138DA0(&res, &self->f70, it);
            }
        }
    }
    if (self->f7C) func_0043BC70(self->f7C, 0, self->f68, 0, self->f70 - self->f64);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043DCE0 */
