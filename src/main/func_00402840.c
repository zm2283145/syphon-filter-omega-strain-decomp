#include "types.h"
typedef struct SklFile_h5 {
    int unk0;
    char name[0x9C];
} SklFile_h5;
extern signed char D_00493A60;
extern char D_0055D510[];
extern char D_0055D950[];
extern void func_0036E5D0(SklFile_h5* f);
extern void func_0036E140(SklFile_h5* f, char* path, int a, int b);
extern int func_0036DEF0(SklFile_h5* f);
extern int func_0036DE50(SklFile_h5* f);
extern void* func_0036DC60(SklFile_h5* f);
extern void func_0036DEC0(SklFile_h5* f);
extern void func_0036E220(SklFile_h5* f, int flags);
extern int sprintf(char* buf, const char* fmt, ...);
extern void Appearance_PackText(char* dst, void* text, int len);
void Skl_Load(void* self, char* skelPath, char* animPath)
{
    D_00493A60 = 0;
    {
        SklFile_h5 f;
        func_0036E5D0(&f);
        func_0036E140(&f, skelPath, 0, 0);
        if ((unsigned char)func_0036DEF0(&f)) {
            char msg[128];
            sprintf(msg, "Failed to open %s in LoadSKL\n", f.name);
            func_0036E220(&f, -1);
        } else {
            int len = func_0036DE50(&f);
            Appearance_PackText(D_0055D510, func_0036DC60(&f), len);
            func_0036DEC0(&f);
            func_0036E220(&f, -1);
        }
    }
    {
        SklFile_h5 f;
        func_0036E5D0(&f);
        func_0036E140(&f, animPath, 0, 0);
        if ((unsigned char)func_0036DEF0(&f)) {
            char msg[128];
            sprintf(msg, "Failed to open %s in LoadSKL\n", f.name);
            func_0036E220(&f, -1);
        } else {
            int len = func_0036DE50(&f);
            Appearance_PackText(D_0055D950, func_0036DC60(&f), len);
            func_0036DEC0(&f);
            func_0036E220(&f, -1);
        }
    }
}