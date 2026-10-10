#include "types.h"
typedef struct F1Game1695 { char pad0[0x250]; unsigned char b250; char pad251[3]; int x254; int x258; int pad25C; int x260; } F1Game1695;
typedef struct F1Cfg1695 { char pad0[0x1C]; float scale; } F1Cfg1695;
extern unsigned char D_004FFBA0;
extern F1Cfg1695* D_004FFD2C;
extern float D_004C1FC8;
extern int D_005383D4;
extern int D_005383C0;
extern void* D_004FFC04;
extern char D_0048B2F8[];
extern char D_005381F0[];
extern char D_0049C538[];
extern void* func_0010D050(void);
extern void func_0010CFF0(void* p, int n);
extern void func_003A65F0(int n);
extern void func_00165E40(F1Game1695* g);
extern void Game_LoadIni(F1Game1695* g);
extern void Loc_LoadCommonPool(char* name);
extern void func_003A6560(void);
extern void func_00165DD0(F1Game1695* g);
extern void func_0037E780(void* p, int a, int b, int c, int d, int e, int f, int g);
extern void func_00165950(F1Game1695* g);
extern void func_002CB8C0(void* p, int n);
extern void func_002C7D90(void* p, int a, void* b, int c);
void StringPool_Load(F1Game1695* g)
{
    func_0010CFF0(func_0010D050(), 10);
    func_003A65F0(1);
    func_00165E40(g);
    Game_LoadIni(g);
    Loc_LoadCommonPool(D_0048B2F8);
    func_003A6560();
    func_00165DD0(g);
    if (D_004FFBA0 == 9) {
        func_0037E780(D_005381F0, g->x254, g->x258, 0x20, 0x10, g->b250, 4000, 500);
        D_005383D4 = g->x260;
        D_005383C0 = (unsigned char)(int)(D_004C1FC8 * D_004FFD2C->scale);
        func_00165950(g);
        func_002CB8C0(D_004FFC04, 0);
        func_002C7D90(D_004FFC04, 1, D_0049C538, 0);
    }
}