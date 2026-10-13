#pragma push
#pragma opt_strength_reduction off
typedef struct { int id; } VInfo3E10D0;
typedef struct { char* name; VInfo3E10D0* info; } Var3E10D0;
typedef struct { int x0; int count; Var3E10D0** items; } Tbl3E10D0;

extern Tbl3E10D0* D_00554F18;
extern char D_004BD858[];
extern int sprintf(char*, const char*, ...);
extern int String_CompareNoCase(char*, char*);

Var3E10D0* func_003E10D0(void* self, char* name, int id)
{
    char buf[128];
    int i;
    Var3E10D0* v;
    int n;
    n = D_00554F18->count;
    sprintf(buf, D_004BD858, name);
    for (i = 0; i < n; i++) {
        v = D_00554F18->items[i];
        if (id < 0 || id == v->info->id) {
            if (!String_CompareNoCase(v->name, name) || !String_CompareNoCase(v->name, buf)) {
                return v;
            }
        }
    }
    return 0;
}
#pragma pop
