//
//  FaustDSP.hpp
//  AudioKit For iOS
//
//  Created by Max Muermann on 8/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#ifdef __cplusplus

#ifndef FaustDSP_h
#define FaustDSP_h

class UI {
public:
    virtual void addButton(const char* label, float* zone) = 0;
    virtual void addCheckButton(const char* label, float* zone) = 0;
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;

    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;

    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;

    virtual void declare(float* zone, const char* name, const char* value) = 0;
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

class Meta {
public:
    virtual void declare(const char* name, const char* value) = 0;
};

#endif /* FaustDSP_h */

#endif /* __cplusplus */
