typedef struct {
    void* obj;
    int val;
    char name[16];
} E_4602C0;
typedef struct {
    char pad0[0x48];
    E_4602C0 e[15];
    int pad1B0;
    int n;
} O_4602C0;
extern char D_004C24A8[];
extern char D_004C24B0[];
extern char D_004C24B8[];
extern char D_004C24C0[];
int sprintf(char* buf, const char* fmt, ...);
void String_Copy(char* d, const char* s);
void func_00128F58(char* d, const char* s);
void func_0043C890(void* obj, char* name, int x);

void func_004602C0(O_4602C0* o, int x, int type, int sub, int val)
{
    char buf[256];
    E_4602C0* e;
    if (o->n < 15) {
        e = &o->e[o->n];
        sprintf(buf, D_004C24A8, type, sub);
        String_Copy(e->name, D_004C24B0);
        if (type != 7) func_00128F58(buf, D_004C24B8);
        func_00128F58(buf, D_004C24C0);
        if (e->obj) func_0043C890(e->obj, buf, x);
        e->val = val;
        o->n++;
    }
}

