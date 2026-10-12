#pragma opt_propagation off
extern void* func_00185C70(int id);
extern char* func_00336170(void* p);
extern char* func_0012F5D0(void* tbl, int id);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004FFB50[];
extern char D_004ACF28[];

typedef struct {
    char pad[0xB70];
    unsigned char active;
} Ent9270;

static inline void Append(char* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = buf[0];
    d = buf + n + 1;
    p = s;
    if (n < 0x7E) {
        while ((*d++ = *p++) != 0) {
            if (++n >= 0x7E) {
                n++;
                d[0] = '\n';
                d[1] = 0;
                break;
            }
        }
    }
    buf[0] = n;
}


void func_002C9270(char* buf, int id, int nameId, int newline)
{
    char tmp[0x70];
    char c;
    if (func_00185C70(id) && ((Ent9270*)func_00185C70(id))->active) {
        Append(buf, func_00336170(func_00185C70(id)));
    }
    c = newline ? '\n' : ' ';
    sprintf(tmp, D_004ACF28, (char)c, 0x11, func_0012F5D0(D_004FFB50, nameId), 0x10);
    Append(buf, tmp);
}
