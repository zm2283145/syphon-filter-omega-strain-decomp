typedef struct { char d[20]; } E421540;
typedef struct { char p[0x94]; int count; E421540* items; } O421540;
extern char* String_CStr(E421540* e);
extern int strcmp(const char* a, const char* b);
#pragma opt_strength_reduction off
int func_00421540(O421540* o, const char* name)
{
    int i;
    for (i = 0; i < o->count; i++) {
        if (strcmp(name, String_CStr(&o->items[i])) == 0) {
            return i;
        }
    }
    return -1;
}

