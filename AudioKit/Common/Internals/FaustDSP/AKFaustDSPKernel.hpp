//  
//  AKChorusDSPKernel.hpp
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#pragma once

#import "AKDSPKernel.hpp"
#import "GUI.hpp"

class AKFaustDSPKernel : public AKDSPKernel, public AKBuffered {
public:
    // MARK: Member Functions

    AKFaustDSPKernel() {}

    void setDSP(dsp* pDSP) {
        dsp = pDSP;
        ui = new AKFaustUI();
        dsp->buildUserInterface(ui);
    }

    void init(int _channels, double _sampleRate) override {
        AKDSPKernel::init(_channels, _sampleRate);
        dsp->init(_sampleRate);
    }

    void start() {
        started = true;
    }

    void stop() {
        started = false;
    }

    void destroy() {
        free(dsp);
    }

    void reset() {
        resetted = true;
        for(AKFaustParameter* param : ui->parameters) {
            if (param->ramper) {
                param->ramper->reset();
            }
        }
    }

    void setParameter(AUParameterAddress address, AUValue value) {
        AKFaustParameter * param = ui->parameters[(unsigned long)address];
        float clampedValue = clamp(value, param->min, param->max);
        if (param->ramper) {
            param->ramper->setImmediate(clampedValue);
        } else {
            *(param->zone) = clampedValue;
        }
    }

    AUValue getParameter(AUParameterAddress address) {
        AKFaustParameter * param = ui->parameters[(unsigned long)address];
        if (param->ramper) {
            return param->ramper->getUIValue();
        } else {
            return *(param->zone);
        }
    }

    void startRamp(AUParameterAddress address, AUValue value, AUAudioFrameCount duration) override {
        AKFaustParameter * param = ui->parameters[(unsigned long)address];
        float clampedValue = clamp(value, param->min, param->max);
        if (param->ramper) {
            return param->ramper->startRamp(clampedValue, duration);
        } else {
            *(param->zone) = clampedValue;
        }
    }

    void process(AUAudioFrameCount frameCount, AUAudioFrameCount bufferOffset) override {
        // set all ramped parameters
        for (AKFaustParameter* param : ui->parameters) {
            if (param->ramper) {
                *(param->zone) = param->ramper->getAndStep();
            }
        }

        // process up to two channels, this will work for mono and stereo nodes
        float *tmpin[2];
        float *tmpout[2];
        for (int channel = 0; channel < channels; ++channel) {
            float *in  = (float *)inBufferListPtr->mBuffers[channel].mData  + bufferOffset;
            float *out = (float *)outBufferListPtr->mBuffers[channel].mData + bufferOffset;

            if (channel < 2) {
                tmpin[channel] = in;
                tmpout[channel] = out;
            }
        }
        if (started) {
            dsp->compute(frameCount, tmpin, tmpout);
        } else {
            tmpout[0] = tmpin[0];
            tmpout[1] = tmpin[1];
        }
    }

    // MARK: Member Variables

private:

    dsp *dsp;
    float param0 = 1.0;

public:

    bool started = true;
    bool resetted = false;

    AKFaustUI* ui;
};
