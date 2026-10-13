typedef struct { unsigned char d[48]; } Info5f30;
extern void *memset(void *, int, unsigned int);
extern int ReferThreadStatus(int id, Info5f30 *info);

int func_00305F30(int id, Info5f30 *out, unsigned int size, int *len)
{
    Info5f30 info;
    if (len == 0) return 2;
    *len = 0;
    if (out == 0) return 2;
    if (size < sizeof(Info5f30)) return 2;
    memset(&info, 0, sizeof(info));
    if (ReferThreadStatus(id, &info) != -1) {
        *out = info;
        *len = sizeof(Info5f30);
    }
    return 0;
}
