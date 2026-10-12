typedef struct { int a; int index; int b; int c; char name[16]; int key; } R2EB00;
extern char* strncpy(char* d, const char* s, unsigned int n);
extern int sprintf(char* buf, const char* fmt, ...);
extern int Loc_FindKeyThunk(char* key);
R2EB00* func_0032EB00(R2EB00* r, int a, int b, int c, int index, const char* name)
{
    char buf[16];
    r->a = a;
    r->b = b;
    r->c = c;
    r->index = index;
    if (name)
        strncpy(r->name, name, 16);
    else
        r->name[0] = 0;
    sprintf(buf, "S_RANK_%2.2d", r->index + 1);
    r->key = Loc_FindKeyThunk(buf);
    return r;
}