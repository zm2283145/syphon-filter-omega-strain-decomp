#ifndef GUI_TRAVERSAL_TYPES_H
#define GUI_TRAVERSAL_TYPES_H

struct TraversalWidget;

struct GuiMessageHandler {
    virtual void slot00();
    virtual void slot01();
    virtual void on_unregistered();
    virtual void slot03();
    virtual void slot04();
    virtual void request_state();
    virtual void propagate_state();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void draw();
    virtual void slot11();
    virtual void update(float elapsed);
    virtual unsigned char on_message(TraversalWidget* sender, int message, int first, int second);
};

struct ChildNode {
    ChildNode* previous;
    ChildNode* next;
    TraversalWidget* widget;
};

struct ChildList {
    int count;
    ChildNode* sentinel;
    ChildNode* first;
};

struct ChildIterator {
    ChildNode* node;
};

struct TraversalWidget {
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
    virtual TraversalWidget* first_descendant();
    virtual TraversalWidget* last_descendant();
    virtual TraversalWidget* find_forward(TraversalWidget* boundary, int restart);
    virtual TraversalWidget* find_backward(TraversalWidget* boundary, int restart);
    char name[0xC];                /* 0x04 small-string object */
    int id;                       /* 0x10 */
    unsigned short flags;          /* 0x14 */
    char pad16[6];
    TraversalWidget* parent;        /* 0x1C */
    TraversalWidget* selected;      /* 0x20 */
    TraversalWidget* owner;         /* 0x24 */
    ChildList children;            /* 0x28 */
    char pad34[0x10];
    GuiMessageHandler* handler;     /* 0x44 */
};

struct GuiFocusManager {
    char pad00[0x20];
    TraversalWidget* selected;      /* 0x20 */
};

#endif
