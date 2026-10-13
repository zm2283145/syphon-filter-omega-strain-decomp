typedef struct TdxMgr {
    char pad0[8];
    char** names;
    char pad0c[4];
    int count;
} TdxMgr;
typedef struct TdxEnt {
    int id;
    char name[1];
} TdxEnt;
extern unsigned int strlen(const char* s);
extern int String_CompareNoCase(const char* a, const char* b);
extern char D_004BC2C8[];
extern void Tdx_Clone(TdxMgr* m, TdxEnt* e, int idx);

void func_003816F0(TdxMgr* m, TdxEnt* e)
{
    char* s = e->name;
    char buf[80];
    char* end;
    char* p;
    char* d;
    int idx;
    if (String_CompareNoCase(s + strlen(s) - 3, D_004BC2C8) == 0) {
        end = s + strlen(s);
        p = end;
        while (*p != '\\' && p != s) p--;
        if (*p == '\\') s = p + 1;
        d = buf;
        while (s != end && *s != '.') *d++ = *s++;
        *d = 0;
        {
        int i;
        idx = -1;
        for (i = 0; i < m->count; i++) {
            if (m->names[i] && String_CompareNoCase(buf, m->names[i]) == 0) break;
        }
        if (i < m->count) idx = i;
        }
        if (idx != -1) Tdx_Clone(m, e, idx);
    }
}


