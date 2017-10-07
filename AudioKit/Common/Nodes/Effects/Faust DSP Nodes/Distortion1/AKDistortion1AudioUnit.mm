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

    // automatically generate AudioUnit parameters from Faust UI definition
    NSMutableArray* auParameters = [[NSMutableArray alloc] init];
    int i = 0;
    for(AKFaustParameter* fParam : _kernel.ui->parameters) {
        AUParameter* param = [AUParameter parameter: [[NSString stringWithUTF8String: fParam->name] stringByReplacingOccurrencesOfString:@"." withString:@"_"] // parameter identifiers are not allowed to contain periods.
                                               name: [NSString stringWithUTF8String: fParam->name]
                                            address: i++
                                                min: fParam->min
                                                max: fParam->max
                                               unit:kAudioUnitParameterUnit_Generic];

        [auParameters addObject:param];
    }

    // Create the parameter tree.
    _parameterTree = [AUParameterTree tree: auParameters];


    parameterTreeBlock(Distortion1)
}

AUAudioUnitOverrides(Distortion1);

@end


