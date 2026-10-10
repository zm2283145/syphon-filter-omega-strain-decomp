typedef struct { char b[0x3C]; } G1E;
typedef struct { int cap; int count; G1E* data; } G1Arr;
extern void func_001AEF70(G1E* e, int a);
void func_00292630(G1Arr* a)
{
    G1E* b = a->data;
    G1E* e = b + a->count;
    while (b < e) {
        e--;
        func_001AEF70(e, -1);
    }
    a->count = 0;
}