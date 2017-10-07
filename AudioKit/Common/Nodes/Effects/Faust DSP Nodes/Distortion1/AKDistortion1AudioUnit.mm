//  
//  AKDistortion1AudioUnit.mm
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#import "AKDistortion1AudioUnit.h"
#import "AKDistortion1DSPKernel.hpp"

#import "BufferedAudioBus.hpp"

#import <AudioKit/AudioKit-Swift.h>

@implementation AKDistortion1AudioUnit {
    // C++ members need to be ivars; they would be copied on access if they were properties.
    AKDistortion1DSPKernel _kernel;
    BufferedInputBus _inputBus;
}
@synthesize parameterTree = _parameterTree;

standardKernelPassthroughs()

- (void)createParameters {

    standardSetup(Distortion1) // for generator nodes, use generatorSetup(AKDistortion1AudioUnit) instead

    // Create the parameter tree.
    _parameterTree = [AUParameterTree tree:@[
                                             ]];

    parameterTreeBlock(Distortion1)
}

AUAudioUnitOverrides(Distortion1);

@end


