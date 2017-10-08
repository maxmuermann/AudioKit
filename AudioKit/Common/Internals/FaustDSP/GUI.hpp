//
//  GUI.hpp
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#ifndef GUI_hpp
#define GUI_hpp

#include "FaustDSP.hpp"
#include <vector>
#include <AudioToolbox/AUParameters.h>

typedef uint32_t AUAudioFrameCount;

#include "ParameterRamper.hpp"

class AKFaustParameter {
public:
    const char* name;
    float* zone;
    float init, min, max, step;
    ParameterRamper* ramper;
};

class AKFaustUI: public UI {
public:
    ~AKFaustUI();
    virtual void addButton(const char* label, float* zone);
    virtual void addCheckButton(const char* label, float* zone);
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step);
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step);
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step);

    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) {}
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) {}
    virtual void openTabBox(const char* label) {}
    virtual void openHorizontalBox(const char* label) {}
    virtual void openVerticalBox(const char* label) {}
    virtual void closeBox() {}
    virtual void declare(float* zone, const char* name, const char* value) {}

    std::vector<AKFaustParameter*> parameters;

private:

    virtual void addRampedParameter(const char* name, float* zone, float init, float min, float max, float step);
    virtual AKFaustParameter* addDiscreteParameter(const char* name, float* zone, float init, float min, float max, float step);
};

#endif /* GUI_hpp */
