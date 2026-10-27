#include "types.h"
typedef struct SklFile_h5 {
    int unk0;
    char name[0x9C];
} SklFile_h5;
extern signed char D_00493A60;
extern char D_0055D510[];
extern char D_0055D950[];
extern void cFileMan_ctor_void(SklFile_h5* f);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(SklFile_h5* f, char* path, int a, int b);
extern int cFileMan_Open(SklFile_h5* f);
extern int cFileMan_GetSize(SklFile_h5* f);
extern void* cFileMan_Read_void(SklFile_h5* f);
extern void cFileMan_Close(SklFile_h5* f);
extern void cFileMan_dtor(SklFile_h5* f, int flags);
extern int sprintf(char* buf, const char* fmt, ...);
extern void SKL_ConvertSKL(char* dst, void* text, int len);
void Monster_LoadMenSKLs(void* self, char* skelPath, char* animPath)
{
    D_00493A60 = 0;
    {
        SklFile_h5 f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, skelPath, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char msg[128];
            sprintf(msg, "Failed to open %s in LoadSKL\n", f.name);
            cFileMan_dtor(&f, -1);
        } else {
            int len = cFileMan_GetSize(&f);
            SKL_ConvertSKL(D_0055D510, cFileMan_Read_void(&f), len);
            cFileMan_Close(&f);
            cFileMan_dtor(&f, -1);
        }
    }
    {
        SklFile_h5 f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, animPath, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char msg[128];
            sprintf(msg, "Failed to open %s in LoadSKL\n", f.name);
            cFileMan_dtor(&f, -1);
        } else {
            int len = cFileMan_GetSize(&f);
            SKL_ConvertSKL(D_0055D950, cFileMan_Read_void(&f), len);
            cFileMan_Close(&f);
            cFileMan_dtor(&f, -1);
        }
    }
}