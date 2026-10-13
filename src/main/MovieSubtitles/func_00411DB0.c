#pragma cplusplus on
#include "types.h"

typedef struct { float x, y, z, w; } Vec411DB0;
typedef struct {
    char pad00[0x50];
    void* src;           /* 0x50 */
    char pad54[0x8];
    char* textm1;        /* 0x5C */
    char* text[3];       /* 0x60 */
    char* cur[3];        /* 0x6C */
    int count;           /* 0x78 */
    char pad7C[4];
    Vec411DB0 color;     /* 0x80 */
    int len[3];          /* 0x90 */
    float start;         /* 0x9C */
    float stop;          /* 0xA0 */
    int flags;           /* 0xA4 */
    int fA8;             /* 0xA8 */
    unsigned char active;/* 0xAC */
    char padAD[7];
    float time;          /* 0xB4 */
} Sub411DB0;

extern "C" {
extern unsigned int D_0055C5A8;
extern int func_00412210(void* src);
extern int func_004121F0(void* src);
extern int func_004121D0(void* src);
extern char* func_00412190(void* src, int i);
extern int strlen(const char* s);
extern Vec411DB0* func_00412180(void* src);
extern void func_00412150(Vec411DB0* d, Vec411DB0* s);
extern float func_00412130(void* src);
extern float func_00412110(void* src);
extern int func_004120F0(void* src);
extern void func_004120C0(void* src);
extern void func_00412050(Sub411DB0* s);
}

extern "C" void MovieSubtitles_Update(Sub411DB0* s)
{
    int j;
    int i;
    if (!(s->time < s->start)) {
        if (s->time < s->stop) {
            s->active = 1;
            if (s->flags & 8) {
                for (i = 0; i < s->count; i++) {
                    if (s->cur[i] == 0) {
                        bool flag = false;
                        if (i == 0) {
                            flag = true;
                        } else if (s->cur[i - 1] == s->text[i - 1] + s->len[i - 1]) {
                            s->start = s->time;
                            flag = true;
                        }
                        if (flag) s->cur[i] = s->text[i];
                    }
                    {
                        char* e;
                        char* c;
                        char* t = s->text[i];
                        int n = s->len[i];
                        e = t + n;
                        if ((c = s->cur[i]) != 0 && c < e) {
                            float q = (s->time - s->start) / (0.1f * n);
                            s->cur[i] = t + (int)(q * n) + 1;
                        }
                    }
                }
            }
        }
        if (!(s->time < s->stop) && s->active) {
            s->active = 0;
            if (func_00412210(s->src)) {
                s->flags = func_004121F0(s->src);
                s->count = func_004121D0(s->src);
                for (j = 0; j < s->count; j++) {
                    s->text[j] = func_00412190(s->src, j);
                    s->len[j] = strlen(s->text[j]);
                    s->cur[j] = 0;
                }
                func_00412150(&s->color, func_00412180(s->src));
                s->start = func_00412130(s->src);
                s->stop = func_00412110(s->src);
                s->fA8 = func_004120F0(s->src);
                func_004120C0(s->src);
            } else {
                func_00412050(s);
            }
            if (!(s->time < s->start)) s->active = 1;
        }
    }
    s->time = (float)D_0055C5A8 / 60.0f;
}







