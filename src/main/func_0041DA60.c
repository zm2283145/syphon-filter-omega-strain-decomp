typedef struct GuiWidgetValueSlot {
    char pad00[0x10];
    int value;
} GuiWidgetValueSlot;

extern GuiWidgetValueSlot* GuiWidget_FindChildByName(void* self, const char* name);

/* Set a named widget's value when that widget exists. */
int GuiWidget_SetChildValue(void* self, const char* name, int value)
{
    GuiWidgetValueSlot* widget = GuiWidget_FindChildByName(self, name);
    if (widget) {
        widget->value = value;
        return 1;
    }
    return 0;
}
