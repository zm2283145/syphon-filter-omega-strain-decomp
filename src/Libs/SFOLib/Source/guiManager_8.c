/*
 * Libs/SFOLib/Source/guiManager: 1 file, 00419110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419110 */
#pragma push /* merge_units */
#include "types.h"
#include "guiManager.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { char data[0xA0]; } HogFile;     /* file object read from a HOG archive */

extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(void* list, String* s);  /* list<String>::push_back */
extern void String_Dtor(String* s, int flags);   /* String dtor */
extern int sprintf(char* buf, const char* fmt, ...);
extern void cFileMan_ctor_void(HogFile* file);           /* ctor */
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(HogFile* file, char* name, int hog, int b);
extern int GuiManager_ConstructWidgetFromFile(GuiScreenList* self, HogFile* file, int existing);
extern void cFileMan_dtor(HogFile* file, int flags); /* dtor */

/* Remember name as loaded, open "<name>.GUI" from the given HOG and load its widget tree. */
int GuiManager_ConstructWidget_cHogFileR_charP_GuiWidgetP(GuiScreenList* self, int hog, const char* name, int existing)
{
    HogFile file;
    char path[0x20];
    String str;
    int root;
    std_basic_string_char_char_traits_char_ctor_charP(&str, name);
    std_basic_string_char_char_traits_char_assign_basicstringR(self->loadedNames, &str);
    String_Dtor(&str, 0);
    sprintf(path, "%s.GUI", name);
    cFileMan_ctor_void(&file);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&file, path, hog, 0);
    root = GuiManager_ConstructWidgetFromFile(self, &file, existing);
    cFileMan_dtor(&file, -1);
    return root;
}
static inline void merge_flush_func_00419110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00419110 */
