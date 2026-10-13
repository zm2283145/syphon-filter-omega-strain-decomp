/*
 * guiManager.cc: the object returned by Gui_GetScreenList(). It loads .GUI
 * widget trees from the mounted HOG archives and owns the set-up widgets.
 * (loose02_types.h's GuiManager is the screen stack from Gui_GetScreenStack.)
 */
#ifndef GUIMANAGER_H
#define GUIMANAGER_H

/* GuiWidget.flags (0x14): set by vtable slot 3 (setup), cleared by slot 4 (teardown). */
#define GUI_WIDGET_SET_UP 0x1

/* .GUI file: "GUI", padding to a 4-byte boundary, 2 bytes, then the widget tree. */
#define GUI_FILE_HEADER_SKIP 2

/* std::list<T*> node and list head (sentinel node {prev, next} at +4). */
typedef struct GuiPtrNode {
    struct GuiPtrNode* prev;       /* 0x00 */
    struct GuiPtrNode* next;       /* 0x04 */
    void* item;                    /* 0x08 */
} GuiPtrNode;

typedef struct GuiPtrList {
    int count;                     /* 0x00 */
    GuiPtrNode* last;              /* 0x04 sentinel.prev */
    GuiPtrNode* first;             /* 0x08 sentinel.next */
} GuiPtrList;

typedef struct GuiScreenList {
    char pad00[0x14];
    GuiPtrList widgets;            /* 0x14 set-up widgets (GuiManager_AddWidget) */
    GuiPtrList pendingDelete;      /* 0x20 widgets destroyed by GuiManager_FlushDeleted */
    char loadedNames[0xC];         /* 0x2C list of String: names of loaded .GUI files */
} GuiScreenList;

#endif /* GUIMANAGER_H */
