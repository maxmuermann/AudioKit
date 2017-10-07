#include <stdlib.h>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

typedef void (* addHorizontalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addVerticalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addCheckButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* openBoxFun) (void* ui_interface, const char * label);
typedef void (* closeBoxFun) (void* ui_interface);
typedef void (* declareFun) (void* ui_interface, void* thing, const char *s1, const char *s2);
typedef void (* addNumEntryFun) (void* ui_interface, char* label, void* thing, float f0, float f1, float f2, float f3);

typedef struct {
    void* uiInterface;
    addHorizontalSliderFun addHorizontalSlider;
    addVerticalSliderFun addVerticalSlider;
    addCheckButtonFun addCheckButton;
    addNumEntryFun addNumEntry;
    openBoxFun openVerticalBox;
    openBoxFun openHorizontalBox;
    closeBoxFun closeBox;
    declareFun declare;
} UIGlue;


typedef void (* declareMetaFun) (void* meta_interface, const char *s1, const char *s2);

typedef struct {
    void* metaInterface;
    declareMetaFun declare;
} MetaGlue;
