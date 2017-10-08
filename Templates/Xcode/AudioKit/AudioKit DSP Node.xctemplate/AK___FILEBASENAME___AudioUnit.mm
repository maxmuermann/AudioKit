//  ___FILEHEADER___

#import "AK___VARIABLE_nodeName___AudioUnit.h"
#import "___VARIABLE_nodeName___.hpp"

@implementation AK___VARIABLE_nodeName___AudioUnit: AKFaustAudioUnit

-(void)createParameters {
    [self setDSP:new ___VARIABLE_nodeName___DSP()];
    [super createParameters];
}
@end
