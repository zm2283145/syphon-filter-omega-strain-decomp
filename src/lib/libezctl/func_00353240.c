extern int D_00492C34;
extern char D_00533280[];
extern char D_004BADB8[];
extern char D_004BADC0[];
extern char D_004BAE08[];
extern int func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
int ezNetCtlGetStatus(int *buf)
{
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    func_00110528(D_00533280, 3, 0, buf, 0x110, buf, 0x110, 0, 0);
    if (*buf) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388("ezNetCtlGetStatus returned %d\n", *buf);
    }
    return *buf;
}
