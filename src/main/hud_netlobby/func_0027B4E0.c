
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

void List_Begin(void* out, void* list);
void func_0027AA80(void* out, void* in);
void func_0027AC70(void* out, void* in);
void func_0027AC80(void* out, void* list);
void IeElement_Fade(int h, float a);
void IeElement_PlayRange(int h, int b, float a, float c);

#pragma opt_loop_invariants off
void func_0027B4E0(char* arg0) {
    int sp5C;
    char* sp58;
    int sp54;
    int sp50;
    int arr[2];

    if (F_(arg0, 0x56, unsigned char) != 0) return;
    if (F_(arg0, 0x3C, int) == 0) {
        int i;
        int* q;
        __clear((char*)arr, 8);
        arr[0] = F_(arg0, 0x10, int);
        arr[1] = F_(arg0, 0x8, int);
        for (i = 0, q = arr; i < 2; i++, q++) {
            if (i == F_(arg0, 0x38, int)) {
                IeElement_PlayRange(*q, 1, 0.0f, 8.0f);
            } else {
                IeElement_Fade(*q, 0.0f);
            }
        }
    } else if (F_(arg0, 0x3C, int) == 1) {
        int j = 0;
        char* n;
        List_Begin(&sp54, arg0 + 0x2C);
        func_0027AA80(&sp58, &sp54);
        n = sp58;
        func_0027AC80(&sp50, arg0 + 0x2C);
        func_0027AC70(&sp5C, &sp50);
        if ((int)n != sp5C) {
            do {
                if (j == F_(arg0, 0x38, int)) {
                    IeElement_PlayRange(F_(F_(n, 0x8, int), 0x14, int), 1, 0.0f, 8.0f);
                } else {
                    IeElement_Fade(F_(F_(n, 0x8, int), 0x14, int), 0.0f);
                }
                n = F_(n, 0x4, char*);
                j++;
                func_0027AC80(&sp50, arg0 + 0x2C);
                func_0027AC70(&sp5C, &sp50);
            } while ((int)n != sp5C);
        }
    }
}