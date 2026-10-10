#include "types.h"

extern char D_0049AAF0[]; /* format */
extern char D_0048B2F8[];
extern char D_0053B540[];
extern int sprintf(char* buf, const char* fmt, ...); /* sprintf */
extern void* Archive_Open(void* self, const char* text, int a2, int a3);
extern void func_00397B20(void* list, void* item);
extern void func_003F9530(void* self, const char* text);
extern int* func_00236F20(int index);
extern void func_0038B8B0(int slot, int value);

/* Sets up the title text and copies the four configured values into slots (1, 0, 2, 3). */
void func_001368D0(void* self)
{
    char buf[0x80];
    sprintf(buf, D_0049AAF0, D_0048B2F8);
    func_00397B20(D_0053B540, Archive_Open(self, buf, 1, 0));
    func_003F9530(self, buf);
    func_0038B8B0(1, *func_00236F20(0));
    func_0038B8B0(0, *func_00236F20(1));
    func_0038B8B0(2, *func_00236F20(2));
    func_0038B8B0(3, *func_00236F20(3));
}
