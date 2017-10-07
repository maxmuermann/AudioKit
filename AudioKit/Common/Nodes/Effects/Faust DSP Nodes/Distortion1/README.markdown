# Build

In order to get this node to build correctly, the following steps are necessary:

1. add an import statement for the AudioUnit to AudioKit.h, so the swift code can find the AU:
  #import "AKDistortion1AudioUnit.h"
2. open the Headers phase in the Build Phases tab for the AudioKit project and move Distortion1.h from
  "Project" to Public", otherwise XCode will generate an "Include of non-modular header inside framework module" error.


# Generate DSP code with Faust

Run the following command in the directory where the node's files reside:
`faust Distortion1.dsp -o Distortion1.hpp -cn Distortion1DSP -a ios-audiokit.cpp

 You should now be able to build the project in XCode.
