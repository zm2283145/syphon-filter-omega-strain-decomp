typedef struct { int a; int op; int x8; int xC; char p[0x40C]; char name[0x80]; } R2B5628;
extern int D_0048BD88;
extern R2B5628 D_00506640;
extern int func_002BB898(void);
extern void func_002BC7E8(void);
extern unsigned int strlen(const char *);
extern void Libc_Strcpy(char *, char *);
int func_002B5628(int a, char *name)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (!func_002BB898()) return 0x81018002;
    if (D_00506640.op) return 0x81010010;
    if (strlen(name) >= 0x80) return 0x8101005B;
    D_00506640.a = a;
    D_00506640.op = 8;
    Libc_Strcpy(D_00506640.name, name);
    func_002BC7E8();
    return 0;
}
