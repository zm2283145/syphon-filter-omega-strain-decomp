typedef struct { unsigned char state; char name[0x11]; unsigned short port; int x14[2]; int x1C[2]; } E2E5AA8;
extern E2E5AA8 D_00520358[];
extern int func_001298B8(unsigned char *, char *, int);
int func_002E5AA8(unsigned char *name, unsigned int *out, unsigned short *cnt)
{
    unsigned int i;
    int found = 0;
    if (name == 0) return 0x17;
    if (out == 0) return 0x17;
    if (cnt == 0) return 0x17;
    if (name[0] == 0) return 0x17;
    *out = 0;
    *cnt = 0;
    for (i = 0; i < 0x100; i++) {
        if (D_00520358[i].state == 0) {
            *out = i;
            found = 1;
        }
        if (func_001298B8(name, D_00520358[i].name, 0x10) == 0) {
            if (!(D_00520358[i].port < *cnt)) *cnt = D_00520358[i].port + 1;
        }
    }
    return found ? 0 : 8;
}
