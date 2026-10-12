#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Node_DCE0 { Node_DCE0* prev; Node_DCE0* next; char* str; };
extern "C" {
extern char D_004C0110[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
int func_0036AA50(void* font, const char* s, int n);
void func_0043E0B0(void* list, char* const& v);
void func_00138DA0(void* res, void* list, Node_DCE0* const& it);
void func_0043BC70(void*, int, int, int, int);
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