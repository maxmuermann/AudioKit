//  
//  AKChorusAudioUnit.mm
//  AudioKit
//
//  Created by Max Muermann on 6/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#import "AKChorusAudioUnit.h"
#import "AKChorusDSPKernel.hpp"

#import "BufferedAudioBus.hpp"

#import <AudioKit/AudioKit-Swift.h>

@implementation AKChorusAudioUnit {
    // C++ members need to be ivars; they would be copied on access if they were properties.
    AKChorusDSPKernel _kernel;
    BufferedInputBus _inputBus;
}
@synthesize parameterTree = _parameterTree;

standardKernelPassthroughs()

- (void)createParameters {

    standardSetup(Chorus) // for generator nodes, use generatorSetup(AKChorusAudioUnit) instead

    // Create the parameter tree.
    _parameterTree = [AUParameterTree tree:@[
                                             ]];

    parameterTreeBlock(Chorus)
}

AUAudioUnitOverrides(Chorus);

@end


