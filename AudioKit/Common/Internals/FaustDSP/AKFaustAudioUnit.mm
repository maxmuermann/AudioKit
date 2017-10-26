//  
//  AKFaustAudioUnit.mm
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#import "AKFaustAudioUnit.h"
#import "AKFaustDSPKernel.hpp"

#import "BufferedAudioBus.hpp"

#import <AudioKit/AudioKit-Swift.h>

@implementation AKFaustAudioUnit {
    // C++ members need to be ivars; they would be copied on access if they were properties.
    AKFaustDSPKernel _kernel;
    BufferedInputBus _inputBus;
}
@synthesize parameterTree = _parameterTree;

-(void)setDSP:(void*)DSP {
    _kernel.setDSP((dsp*)DSP);
}

-(NSArray<AUParameter*>*)getParameters {
    return _parameterTree.allParameters;
}

standardKernelPassthroughs()

- (void)createParameters {

    standardSetup(Faust) // for generator nodes, use generatorSetup() instead

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

    __block AKFaustDSPKernel *blockKernel = &_kernel;
    
    self.parameterTree.implementorValueObserver = ^(AUParameter *param, AUValue value) {
        blockKernel->setParameter(param.address, value);
    };

    self.parameterTree.implementorValueProvider = ^(AUParameter *param) {
        return blockKernel->getParameter(param.address);
    };
}

AUAudioUnitOverrides(Faust);

@end


