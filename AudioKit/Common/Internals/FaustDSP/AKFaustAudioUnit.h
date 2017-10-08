//  
//  AKChorusAudioUnit.h
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#ifndef __AK_FAUST_AUDIO_UNIT_H
#define __AK_FAUST_AUDIO_UNIT_H
#import "AKAudioUnit.h"

@interface AKFaustAudioUnit : AKAudioUnit
-(void)setDSP:(void*)DSP;
-(void)createParameters;
@end
#endif
