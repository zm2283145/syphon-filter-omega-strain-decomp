/* xC and x10 volatile: keeps retail store order after Libc_Strcpy */
typedef struct { int a; int op; int x8; volatile int xC; volatile int x10; int x14; int x18; char p[0x400]; char name[0x80]; char name2[0x80]; } RQ;
extern int D_0048BD88;
extern RQ D_00506640;
extern int func_002BB898(void);
extern void func_002BC7E8(void);
extern unsigned int strlen(const char *);
extern void Libc_Strcpy(char *, char *);
int sceMc2GetDirAsync(int a, char *name, int c, int d, int e, int f)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (!func_002BB898()) return 0x81018002;
    if (D_00506640.op) return 0x81010010;
    if (strlen(name) >= 0x80) return 0x8101005B;
    D_00506640.a = a;
    D_00506640.op = 10;
    Libc_Strcpy(D_00506640.name, name);
    D_00506640.xC = c;
    D_00506640.x18 = f;
    D_00506640.x14 = e;
    D_00506640.x10 = d;
    func_002BC7E8();
    return 0;
}
