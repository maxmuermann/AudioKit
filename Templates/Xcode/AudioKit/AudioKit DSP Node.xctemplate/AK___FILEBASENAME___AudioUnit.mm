//  ___FILEHEADER___

#import "AK___VARIABLE_nodeName___AudioUnit.h"
#import "AK___VARIABLE_nodeName___DSPKernel.hpp"

#import "BufferedAudioBus.hpp"

#import <AudioKit/AudioKit-Swift.h>

@implementation AK___VARIABLE_nodeName___AudioUnit {
    // C++ members need to be ivars; they would be copied on access if they were properties.
    AK___VARIABLE_nodeName___DSPKernel _kernel;
    BufferedInputBus _inputBus;
}
@synthesize parameterTree = _parameterTree;

standardKernelPassthroughs()

- (void)createParameters {

    standardSetup(___VARIABLE_nodeName___) // for generator nodes, use generatorSetup(___FILEBASENAMEASIDENTIFIER___) instead

    // Create the parameter tree.
    _parameterTree = [AUParameterTree tree:@[
                                             ]];

    parameterTreeBlock(___VARIABLE_nodeName___)
}

AUAudioUnitOverrides(___VARIABLE_nodeName___);

@end


