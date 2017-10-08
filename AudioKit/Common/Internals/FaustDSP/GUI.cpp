//
//  GUI.cpp
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#include "GUI.hpp"

AKFaustUI::~AKFaustUI() {

}

void AKFaustUI::addButton(const char* label, float* zone) {
    addDiscreteParameter(label, zone, 0.0, 0.0, 1.0, 1.0);
}

void AKFaustUI::addCheckButton(const char* label, float* zone) {
    addDiscreteParameter(label, zone, 0.0, 0.0, 1.0, 1.0);
}

void AKFaustUI::addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) {
    addRampedParameter(label, zone, init, min, max, step);
}

void AKFaustUI::addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) {
    addRampedParameter(label, zone, init, min, max, step);
}

void AKFaustUI::addNumEntry(const char* label, float* zone, float init, float min, float max, float step) {
    addRampedParameter(label, zone, init, min, max, step);
}

void AKFaustUI::addRampedParameter(const char* label, float* zone, float init, float min, float max, float step) {
    AKFaustParameter* param = addDiscreteParameter(label, zone, init, min, max, step);
    param->ramper = new ParameterRamper(init);
}

AKFaustParameter* AKFaustUI::addDiscreteParameter(const char* label, float* zone, float init, float min, float max, float step) {
    AKFaustParameter* param = new AKFaustParameter();
    param->name = label;
    param->zone = zone;
    param->init = init;
    param->min = min;
    param->max = max;
    param->step = step;

    parameters.push_back(param);

    return param;
}


