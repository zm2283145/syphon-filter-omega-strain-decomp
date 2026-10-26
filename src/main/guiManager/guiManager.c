/*
 * main/guiManager: 2 files, 00418FD0-00419020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00418FD0 */
#pragma push /* merge_units */
#include "loose04_types.h"
#include "guiManager.h"

extern GuiWidget* GuiManager_LoadNode(GuiScreenList* self, char** cursor, GuiWidget* existing);
extern void GuiManager_AddWidget(GuiScreenList* self, GuiWidget* widget);

/* Read a widget tree at *cursor and add the root when creation succeeds. */
GuiWidget* GuiManager_ReadTree(GuiScreenList* self, char** cursor, GuiWidget* existing) {
    GuiWidget* widget = GuiManager_LoadNode(self, cursor, existing);
    if (widget != 0) {
        GuiManager_AddWidget(self, widget);
    }
    return widget;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418FD0 */

/* merge_units: begin func_00419020 */
#pragma push /* merge_units */
#include "types.h"
#include "guiManager.h"

extern void FileMan_FindMember(void* f);             /* file: begin access */
extern char* FileMan_ReadData(void* f);
extern void cFileMan_Close(void* f);             /* file: end access */

static inline char Rd8_419020(char* volatile* c) { char* t = *c; char v = *t; *c = t + 1; return v; }

/* Check the "GUI" magic of an opened .GUI file and load its widget tree. */
GuiWidget* GuiManager_LoadGuiFile(GuiScreenList* self, void* file, GuiWidget* existing)
{
    char* volatile p;
    char m0;
    char m1;
    char m2;
    GuiWidget* root;
    FileMan_FindMember(file);
    p = FileMan_ReadData(file);
    m0 = Rd8_419020(&p);
    m1 = Rd8_419020(&p);
    m2 = Rd8_419020(&p);
    if (m0 != 'G' || m1 != 'U' || m2 != 'I') return 0;
    p = (char*)(((int)p + 3) & ~3);
    p += GUI_FILE_HEADER_SKIP;
    root = GuiManager_ReadTree(self, (char**)&p, existing);
    cFileMan_Close(file);
    return root;
}
#pragma pop /* merge_units */
/* merge_units: end func_00419020 */
