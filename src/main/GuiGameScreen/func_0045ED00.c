#include "types.h"

typedef struct InteractOwner {
    char pad000[0x6A4];
    void* display; /* 0x6A4 */
} InteractOwner;

extern InteractOwner* D_004FFC2C;
extern void func_0045D070(void* display, int a, int b, int show);

/* Shows the interact prompt on the current display, if any. */
void Global_DisplayInteract(int a, int b) {
    if (D_004FFC2C && D_004FFC2C->display) {
        func_0045D070(D_004FFC2C->display, a, b, 1);
    }
}
