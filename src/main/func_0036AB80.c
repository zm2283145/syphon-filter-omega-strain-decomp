#pragma opt_propagation off
#include "types.h"
typedef struct {
    char pad[0x9C];
} FileMan;
typedef struct {
    signed char len;
    char text[0x80];
} PStr;
typedef struct {
    int f0;
    char pad4[0x8C];
    unsigned char f90;
    char pad91[3];
    float f94;
    unsigned char f98;
    signed char f99;
    char pad9A[2];
    int f9C;
    char fA0[0xB40];
    unsigned char fBE0;
    char fBE1[1];
} ObjAB80;
extern int D_00539248;
extern void func_0036E5D0(FileMan* f);
extern void Hog_Register(FileMan* f, char* name, int a, int b);
extern void func_0036DEF0(FileMan* f);
extern int FileMan_GetSize(FileMan* f);
extern int func_0036D990(FileMan* f, unsigned char** out, int size);
extern void func_0036DEC0(FileMan* f);
extern void func_0036E220(FileMan* f, int flag);
extern int func_00380A40(int mgr, FileMan* f);
extern void* memcpy(void* d, const void* s, unsigned int n);
extern long long SoftFloat_FloatToDouble(float f);
extern long long func_0011C268(long long a, long long b);
extern float func_0011C928(long long a);

static inline void Copy(PStr* buf, char* t, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = t;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

static inline unsigned char Rd(unsigned char** pp) { return *(*pp)++; }
void func_0036AB80(ObjAB80* obj, int arg1, char* name)
{
    FileMan fm;
    PStr s;
    FileMan fm2;
    unsigned char* data;
    unsigned char flags;
    unsigned char* p;
    unsigned char ver;
    unsigned char nlen;
    int i;
    char* t;

    func_0036E5D0(&fm);
    t = s.text;
    s.len = 0;
    Copy(&s, t, name);
    Hog_Register(&fm, (char*)&s + 1, arg1, 0);
    func_0036DEF0(&fm);
    data = 0;
    func_0036D990(&fm, &data, FileMan_GetSize(&fm));
    func_0036DEC0(&fm);
    p = data;
    ver = p[0];
    flags = p[1];
    p += 2;
    nlen = p[0];
    p += 1;
    Copy(&s, t, (char*)p);
    for (i = s.len; i > 0; i--, t++) {
        if (*t >= 'a' && *t <= 'z') *t -= 0x20;
    }
    p += nlen;
    obj->f98 = ((signed char*)p)[0];
    obj->f99 = ((signed char*)p)[1];
    p += 2;
    if (ver == 3) {
        obj->f9C = *p++;
    } else {
        obj->f9C = 0x8E;
    }
    if (obj->f9C > 0xB4) {
        func_0036E220(&fm, -1);
        return;
    }
    memcpy(obj->fA0, p, obj->f9C << 4);
    p += obj->f9C << 4;
    if ((ver == 2 && flags >= 4) || ver > 2) {
        obj->f94 = *(signed char*)p++;
    } else {
        obj->f94 = func_0011C928(func_0011C268((long long)0x3FE00000 << 0x20, SoftFloat_FloatToDouble(obj->f98 / 2.0f * obj->f90)));
    }
    if ((ver == 2 && flags != 0) || ver > 2) {
        obj->fBE0 = *(signed char*)p != 0;
        if (obj->fBE0) {
            memcpy(obj->fBE1, p + 1, obj->f9C * obj->f9C);
        }
    } else {
        obj->fBE0 = 0;
    }
    func_0036E5D0(&fm2);
    Hog_Register(&fm2, (char*)&s + 1, arg1, 0);
    obj->f0 = func_00380A40(D_00539248, &fm2);
    func_0036E220(&fm2, -1);
    func_0036E220(&fm, -1);
}






