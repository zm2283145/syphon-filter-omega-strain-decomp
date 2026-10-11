#pragma cplusplus on

#include "types.h"

/* Load a SKA clip by (a, b) key, then finish registering it. */
struct Key_3B6270 { int a; int b; };
struct Desc_3B6270 { Key_3B6270* key; int n; unsigned char flag; };

extern "C" {
void Skas_Load(void* self, Desc_3B6270* d, void* arg);
void func_003B50A0(void* self, void* arg);
}

extern "C" void func_003B6270(void* self, int a, int b, void* arg)
{
    Key_3B6270 key;
    Desc_3B6270 d;
    key.b = 0;
    key.a = a;
    key.b = b;
    d.key = &key;
    d.n = 0;
    d.flag = 0;
    Skas_Load(self, &d, arg);
    func_003B50A0(self, arg);
}