//  
//  AKChorusDSPKernel.hpp
//  AudioKit
//
//  Created by Max Muermann on 6/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#pragma once

#import "AKDSPKernel.hpp"
#import "Chorus.cpp"

enum {
    param0Address = 0,
};

class AKChorusDSPKernel : public AKDSPKernel, public AKBuffered {
public:
    // MARK: Member Functions

    AKChorusDSPKernel() {}

    void init(int _channels, double _sampleRate) override {
        AKDSPKernel::init(_channels, _sampleRate);

        #warning depending on faust-generated code, this may not be necessary. It is only used when the faust DSP contains class-level variables.
        ChorusDSP::classInit(_sampleRate);
        dsp = new ChorusDSP();
        dsp->init(_sampleRate);

        //dsp->hSlider0 = 1.0;
        param0Ramper.init();
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
        param0Ramper.reset();
    }

    void setParam0(float value) {
        param0 = clamp(value, 0.0f, 1.0f);
        param0Ramper.setImmediate(param0);
    }

    void setParameter(AUParameterAddress address, AUValue value) {
        switch (address) {
            case param0Address:
                param0Ramper.setUIValue(clamp(value, 0.0f, 1.0f));
                break;
        }
    }

    AUValue getParameter(AUParameterAddress address) {
        switch (address) {
            case param0Address:
                return param0Ramper.getUIValue();
            default:
                return 0.0f;
        }
    }

    void startRamp(AUParameterAddress address, AUValue value, AUAudioFrameCount duration) override {
        switch (address) {
            case param0Address:
                param0Ramper.startRamp(clamp(value, 0.0f, 1.0f), duration);
                break;
        }
    }

    void process(AUAudioFrameCount frameCount, AUAudioFrameCount bufferOffset) override {

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

    ChorusDSP *dsp;
    float param0 = 1.0;

public:

    bool started = true;
    bool resetted = false;
    ParameterRamper param0Ramper = 1.0;
};
