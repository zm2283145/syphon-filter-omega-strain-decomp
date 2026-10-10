#include "types.h"
extern char D_00587D50[];
extern char D_00587D60[];
extern void func_00425DB0(void* self, const char* name);
extern void func_00425EA0(void* self, void* data, int a, int b);
/* Sets the name (depending on whether data is given), then initialises with data. */
void func_00455AE0(void* self, void* data, int a, int b)
{
    func_00425DB0(self, data == 0 ? D_00587D50 : D_00587D60);
    func_00425EA0(self, data, a, b);
}
