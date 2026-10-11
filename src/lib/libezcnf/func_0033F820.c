typedef struct { char b[0x68]; } E0033F820;
typedef struct { unsigned int count; unsigned int cur; char pad[0x28]; E0033F820 e[1]; } T0033F820;
extern char D_004B9D10[], D_004B9D18[], D_004B9E40[], D_004B9E68[];
extern int func_0010F388(const char *, ...);
E0033F820 *ezNetCnfGetDefault(T0033F820 *t)
{
    if (t == 0 || t->count == 0) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9E40);
        return 0;
    }
    if (t->count < t->cur) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9E68, t->cur);
        return 0;
    }
    return &t->e[t->cur - 1];
}
