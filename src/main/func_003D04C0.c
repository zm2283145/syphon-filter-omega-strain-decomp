#include "types.h"
typedef struct {
    int x0;
    int x4;
    int w;
    char pad0C[8];
    char str[0xC];
    void* font;
    char pad24[0x30];
    float align;
    unsigned char b58;
    unsigned char b59;
    unsigned char b5A;
    unsigned char b5B;
} T04C0;
extern int func_002071F0(void* s);
extern char* String_CStr(void* s);
extern char* strchr(const char* s, int c);
extern int strlen(const char* s);
extern int func_0036AA50(void* font, const char* s, int n);

int func_003D04C0(T04C0* t)
{
    float x, right, lim;
    char* p;
    char* next;
    char* q;
    int lines, cnt, wd, i, len, w;

    if (!func_002071F0(t->str) || t->b58)
        return 1;
    if (t->b5B) {
        char* s = String_CStr(t->str);
        int n = 1;
        if (s) {
            do {
                s = strchr(s, '\n');
                if (s) {
                    n++;
                    s++;
                }
            } while (s);
        }
        return n;
    }
    x = (float)t->x0;
    w = t->w > 0 ? t->w : -t->w;
    right = x + (float)w;
    p = String_CStr(t->str);
    lines = 0;
    do {
        lim = x + (1.0f - t->align) * (right - x);
        do {
            if (*p) {
                len = strlen(p + 1);
                for (i = 0; i < len; i++) {
                    if (p[i + 1] == ' ' || p[i + 1] == '\n')
                        break;
                }
                next = (char*)(i + (int)p + 1);
            } else {
                next = 0;
            }
            if (next)
                cnt = next - p;
            else
                cnt = strlen(p) + 1;
            wd = func_0036AA50(t->font, p, cnt);
            if (x + wd < right || (x == (float)t->x0 && t->align == 1.0f)) {
                p = next;
                x += wd;
            } else if (t->align != 1.0f && x <= lim) {
                q = p;
                for (i = 0; i < cnt; i++) {
                    if (!(x + func_0036AA50(t->font, p, i + 1) < right))
                        break;
                    q++;
                }
                p = q;
                break;
            }
            if (next && *next == '\n')
                break;
        } while (p && x + wd < right);
        lines++;
        x = (float)t->x0;
        if (p && *p == ' ') {
            do {
                p++;
            } while (*p == ' ');
        }
    } while (p && *p);
    return lines;
}
