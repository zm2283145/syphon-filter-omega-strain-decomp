#include "types.h"

typedef struct {
    int count;
    unsigned short chars[0xDE];
    unsigned char buf[4][0x100];
    unsigned char* pages[256];
} Map_FBB0;

typedef struct { char pad[0xC4]; char* text; char padC8[8]; } File_FBB0;

extern char D_004C02A0[];
extern unsigned int strlen(const char*);
void FileHal_CtorDefault(File_FBB0* f);
void FileHal_Reopen(File_FBB0* f, const char* path, int mode);
unsigned int FileHal_ReadAll(File_FBB0* f);
void FileHal_Dtor(File_FBB0* f, int a);
int func_0043FE20(Map_FBB0* m, char* text);

int func_0043FBB0(Map_FBB0* m, const char* path)
{
    File_FBB0 f;
    unsigned int size;
    int i;
    int n;
    int j;
    FileHal_CtorDefault(&f);
    FileHal_Reopen(&f, path, 1);
    size = FileHal_ReadAll(&f);
    if (size <= strlen(D_004C02A0) + 2) {
        FileHal_Dtor(&f, -1);
        return 0;
    }
    if (!func_0043FE20(m, f.text)) {
        FileHal_Dtor(&f, -1);
        return 0;
    }
    for (i = 0; i < 256; i++) m->pages[i] = 0;
    m->pages[0] = m->buf[0];
    n = 1;
    for (i = 0; i < 32; i++) m->pages[0][i] = i;
    for (j = 0; j < m->count; j++) {
        unsigned short c = m->chars[j];
        if (!m->pages[c >> 8]) {
            if (n == 4) {
                FileHal_Dtor(&f, -1);
                return 0;
            }
            m->pages[c >> 8] = m->buf[n];
            n++;
        }
        m->pages[c >> 8][c & 0xFF] = j;
    }
    FileHal_Dtor(&f, -1);
    return 1;
}