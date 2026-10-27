typedef struct GuiWidgetValueSlot {
    char pad00[0x10];
    int value;
} GuiWidgetValueSlot;

extern GuiWidgetValueSlot* GuiWidget_FindChild_charP(void* self, const char* name);

/* Set a named widget's value when that widget exists. */
int GuiWidget_SetChildUserID(void* self, const char* name, int value)
{
    GuiWidgetValueSlot* widget = GuiWidget_FindChild_charP(self, name);
    if (widget) {
        widget->value = value;
        return 1;
    }
    return 0;
}
