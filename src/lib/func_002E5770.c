typedef struct { unsigned char state; char name[0x11]; unsigned short port; int x14[2]; int x1C[2]; } E2E5770;
extern E2E5770 D_00520358[];
extern int String_CompareN(char *, char *, int);
extern void func_003060F0(int *, int *);
void func_002E5770(char *name, unsigned short port)
{
    unsigned int i;
    if (name == 0 || name[0] == 0) return;
    for (i = 0; i < 0x100; i++) {
        if (String_CompareN(name, D_00520358[i].name, 0x10) == 0 && D_00520358[i].state == 2 && port == D_00520358[i].port) {
            func_003060F0(D_00520358[i].x14, D_00520358[i].x1C);
            D_00520358[i].state = 3;
            return;
        }
    }
}
