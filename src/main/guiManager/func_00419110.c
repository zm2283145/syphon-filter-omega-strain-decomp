#include "types.h"
#include "guiManager.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { char data[0xA0]; } HogFile;     /* file object read from a HOG archive */

extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(void* list, String* s);  /* list<String>::push_back */
extern void String_Dtor(String* s, int flags);   /* String dtor */
extern int sprintf(char* buf, const char* fmt, ...);
extern void Resource_Construct(HogFile* file);           /* ctor */
extern void Hog_Register(HogFile* file, char* name, int hog, int b);
extern int GuiManager_LoadGuiFile(GuiScreenList* self, HogFile* file, int existing);
extern void FileMan_Release(HogFile* file, int flags); /* dtor */

/* Remember name as loaded, open "<name>.GUI" from the given HOG and load its widget tree. */
int GuiManager_LoadGuiFromHog(GuiScreenList* self, int hog, const char* name, int existing)
{
    HogFile file;
    char path[0x20];
    String str;
    int root;
    String_CtorCStr_13B480(&str, name);
    func_0013D680(self->loadedNames, &str);
    String_Dtor(&str, 0);
    sprintf(path, "%s.GUI", name);
    Resource_Construct(&file);
    Hog_Register(&file, path, hog, 0);
    root = GuiManager_LoadGuiFile(self, &file, existing);
    FileMan_Release(&file, -1);
    return root;
}
