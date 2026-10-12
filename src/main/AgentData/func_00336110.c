typedef struct { char pad[0xB50]; int* p; } T36110;
extern void* D_004FFC04;
extern char* func_002C9070(void* p);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(char* key);
char* func_00336110(T36110* self)
{
    char buf[16];
    char* r = func_002C9070(D_004FFC04);
    if (r)
        return r;
    sprintf(buf, "S_%s", *self->p);
    return Loc_LookupText(buf);
}