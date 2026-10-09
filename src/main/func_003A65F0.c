/*
 * Matched functions (byte-identical with the retail executable).
 * Startup helpers: memory init (mem.cc), library modules, DMA manager setup
 * (dmaman.cc) and overlay loading.
 */

#include "loose03_types.h"

extern char D_00537F80[];       /* DMA manager instance */
extern unsigned char D_0053BBB0;
extern int LibInitModules(int);
extern int Overlay_Load(int);
extern int func_0036B630(void);
extern int func_00375E50(void* mgr, int a1, int a2, int a3);

int func_003A65F0(int a0) {
    func_0036B630();
    LibInitModules(a0);
    func_00375E50(D_00537F80, 13312, 1075200, 204800);
    return Overlay_Load(1);
}

/* Set the byte flag D_0053BBB0 and return its previous value. */
int func_003A6650(int value) {
    unsigned char old;

    old = D_0053BBB0;
    D_0053BBB0 = value;
    return old;
}

int func_003A6670(int overlay) {
    return Overlay_Load(overlay);
}
