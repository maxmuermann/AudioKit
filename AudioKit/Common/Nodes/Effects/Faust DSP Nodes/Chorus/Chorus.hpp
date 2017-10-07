//
//  Chorus.hpp
//  AudioKit For iOS
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

#include "GUI.hpp"
#include <math.h>

#ifndef Chorus_h
#define Chorus_h

#define max(a,b) ((a < b) ? b : a)
#define min(a,b) ((a < b) ? a : b)

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class ChorusDSP: public dsp {};

#endif /* Chorus_h */
