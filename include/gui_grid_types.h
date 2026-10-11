#ifndef GUI_GRID_TYPES_H
#define GUI_GRID_TYPES_H

struct GuiGridRect {
    float x;
    float y;
    float width;
    float height;
};

struct GuiGridWidget {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void set_extent(unsigned int columns, unsigned int rows);
    virtual void draw_column(unsigned int column, GuiGridRect* rect);
    virtual void draw_row(unsigned int row, GuiGridRect* rect);
    virtual void draw_cell(unsigned int column, unsigned int row, GuiGridRect* rect);
    virtual void on_selected(unsigned int column, unsigned int row);   /* vtable +0x6C */
    virtual void on_deselected(unsigned int column, unsigned int row); /* vtable +0x70 */
    char pad04[0x30];
    float x;                       /* 0x34 */
    float y;                       /* 0x38 */
    float width;                   /* 0x3C */
    float height;                  /* 0x40 */
    void* handler;                 /* 0x44 */
    unsigned int columns;          /* 0x48 */
    unsigned int rows;             /* 0x4C */
    unsigned int selectedColumn;   /* 0x50 */
    unsigned int selectedRow;      /* 0x54 */
    unsigned char selectionMode;   /* 0x58 */
    char pad59[3];
    unsigned int rowHeight;        /* 0x5C */
    char pad60[8];
    unsigned int* columnWidths;    /* 0x68 */
    char pad6C[4];
    unsigned int visibleColumns;  /* 0x70 */
    unsigned int visibleRows;     /* 0x74 */
    unsigned int firstColumn;     /* 0x78 */
    unsigned int firstRow;        /* 0x7C */
    unsigned char pageNavigation; /* 0x80 */
    unsigned char wrapRows;       /* 0x81 */
    unsigned char fixedViewport;  /* 0x82 */
    char pad83;
    unsigned int centerRow;       /* 0x84 */
    GuiGridWidget* marker;        /* 0x88 */
    void* scrollbar;              /* 0x8C */
};

#endif
