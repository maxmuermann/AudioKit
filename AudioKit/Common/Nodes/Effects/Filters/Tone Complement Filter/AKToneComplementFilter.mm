//
//  AKToneComplementFilter.mm
//  AudioKit
//
//  Created by Aurelius Prochazka, revision history on Github.
//  Copyright © 2018 AudioKit. All rights reserved.
//

#import "AKToneComplementFilterDSP.hpp"

// "Constructor" function for interop with Swift

extern "C" void* createToneComplementFilterDSP(int nChannels, double sampleRate) {
    AKToneComplementFilterDSP* dsp = new AKToneComplementFilterDSP();
    dsp->init(nChannels, sampleRate);
    return dsp;
}
