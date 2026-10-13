/*
 * main/guiManager: 2 files, 004191D0-00419260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004191D0 */
#pragma push /* merge_units */
#include "types.h"
#include "guiManager.h"
#define NULL 0
#pragma mpwc_relax on
int func_004133B0(char *, int *, signed char *);   /* open the archive that holds name */
int GuiManager_LoadGuiFromHog(GuiScreenList *, int, signed char *, int);
extern char D_00571DC0;                             /* interface manager */

/* Load "<name>.GUI" from whichever mounted archive contains name; 0 on failure. */
int GuiManager_LoadGui(GuiScreenList *self, signed char *name, int existing) {
    int hog;
    int root;

    if ((name == NULL) || (*name == 0)) {
        return 0;
    }
    if (func_004133B0(&D_00571DC0, &hog, name) != 0) {
        root = GuiManager_LoadGuiFromHog(self, hog, name, existing);
    } else {
        root = 0;
    }
    return root;
}
#pragma pop /* merge_units */
/* merge_units: end func_004191D0 */

/* merge_units: begin func_00419260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiManager.cc. Functions are named by address
 * until real names are known.
 */


#include "guiManager.h"

extern int GuiManager_FlushDeleted(GuiScreenList* self);

/* Per-frame update (callers pass dt): destroys the widgets queued for deletion. */
int GuiManager_Update(GuiScreenList* self) {
    return GuiManager_FlushDeleted(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_00419260 */
