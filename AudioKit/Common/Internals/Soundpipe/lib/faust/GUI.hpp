//
//  GUI.hpp
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include <map>
#include "AudioToolkit/AudioToolkit.h"

class UI {
public:
    virtual void addButton(const char* label, float* zone);
    virtual void addCheckButton(const char* label, float* zone);
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step);
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step);
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step);

    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max);
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max);

    virtual void openTabBox(const char* label);
    virtual void openHorizontalBox(const char* label);
    virtual void openVerticalBox(const char* label);
    virtual void closeBox();

    virtual void declare(float* zone, const char* name, const char* value);
};

class AKFaustUI: public UI {
    ~AKFaustUI();

private:
    std::map<AUParameterAdress, AKFaustParameter*> parameters;
};

class Meta {
public:
    void declare(const char* name, const char* value);
};

class dsp {
public:
    static void classInit(int samplingFreq);

    dsp() {}
    virtual ~dsp() {}
    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual void buildUserInterface(UI* interface) = 0;
    virtual void init(int samplingRate) = 0;
    virtual void compute(int len, float** inputs, float** outputs) = 0;
};


#endif /* GUI_hpp */
