
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

void std_list_deleter_voidPtr_begin_void(void* out, void* list);
void std_list_GameInfoPtr_generic_iterator_ctor(void* out, void* in);
void cLListIterator_GameInfoPtr_ctor(void* out, void* in);
void std_list_GameInfoPtr_end(void* out, void* list);
void cAnimator_AnimateTo(int h, float a);
void cAnimator_StartAnimation(int h, int b, float a, float c);

#pragma opt_loop_invariants off
void cHudNetLobby_SetActive(char* arg0) {
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
                cAnimator_StartAnimation(*q, 1, 0.0f, 8.0f);
            } else {
                cAnimator_AnimateTo(*q, 0.0f);
            }
        }
    } else if (F_(arg0, 0x3C, int) == 1) {
        int j = 0;
        char* n;
        std_list_deleter_voidPtr_begin_void(&sp54, arg0 + 0x2C);
        std_list_GameInfoPtr_generic_iterator_ctor(&sp58, &sp54);
        n = sp58;
        std_list_GameInfoPtr_end(&sp50, arg0 + 0x2C);
        cLListIterator_GameInfoPtr_ctor(&sp5C, &sp50);
        if ((int)n != sp5C) {
            do {
                if (j == F_(arg0, 0x38, int)) {
                    cAnimator_StartAnimation(F_(F_(n, 0x8, int), 0x14, int), 1, 0.0f, 8.0f);
                } else {
                    cAnimator_AnimateTo(F_(F_(n, 0x8, int), 0x14, int), 0.0f);
                }
                n = F_(n, 0x4, char*);
                j++;
                std_list_GameInfoPtr_end(&sp50, arg0 + 0x2C);
                cLListIterator_GameInfoPtr_ctor(&sp5C, &sp50);
            } while ((int)n != sp5C);
        }
    }
}