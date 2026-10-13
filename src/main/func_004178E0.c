#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Str_4178E0 { int w0; int len; char* data; };
struct PStr_4178E0 {
    signed char len;
    char text[0x80];
};
static inline void Cat_4178E0(PStr_4178E0* p, const char* s)
{
    char* d;
    const char* t;
    int n;
    t = s;
    n = p->len;
    d = &p->text[n];
    if (n < 0x7E) {
        while ((*d++ = *t++) != 0) {
            if (++n >= 0x7E) {
                n++;
                d[0] = '\n';
                d[1] = 0;
                break;
            }
        }
    }
    p->len = n;
}
struct W_4178E0 {
    VPAD1(p)
    virtual void Reset();
    Str_4178E0 name;
    char pad10[0xC];
    int f1C;
};
struct O_4178E0 {
    int f0;
    W_4178E0* w;
    Str_4178E0 file;
    Str_4178E0 text;
    int id;
    void* inst;
    char pad28[8];
    char f30[4];
};
extern "C" {
char* String_CStr(Str_4178E0* s);
int func_002071F0(Str_4178E0* s);
int func_00412F80(void* db, char* name);
int* func_00413370(void* db, int id);
void* func_003EE840(int scene, char* name);
void* func_003EF010(void* n);
void func_003E8DE0(void* i, int a);
void func_003E8040(void* i, void* p);
extern char D_00571DC0[];
extern char D_004BF070[];
}
static inline bool Empty_4178E0(Str_4178E0* s) { return func_002071F0(s) == 0; }

extern "C" void func_004178E0(O_4178E0* o)
{
    int* rec;
    o->w->Reset();
    o->id = func_00412F80(D_00571DC0, String_CStr(&o->file));
    if (o->id == -1) return;
    rec = func_00413370(D_00571DC0, o->id);
    if (rec && *rec) {
        PStr_4178E0 buf;
        void* n;
        const char* s;
        Empty_4178E0(&o->text) ? (s = String_CStr(&o->w->name)) : (s = String_CStr(&o->text));
        {
            char* d = buf.text;
            int n = 0;
            while ((*d++ = *s++) != 0) {
                if (++n >= 0x7E) {
                    n++;
                    d[0] = '\n';
                    d[1] = 0;
                    break;
                }
            }
            buf.len = n;
        }
        if (o->w->f1C == 0) Cat_4178E0(&buf, D_004BF070);
        n = func_003EE840(*rec, (char*)&buf + 1);
        if (n) {
            o->inst = func_003EF010(n);
            func_003E8DE0(o->inst, 0);
            func_003E8040(o->inst, o->f30);
        }
    }
}





