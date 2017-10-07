# Build

In order to get this node to build correctly, the following steps are necessary:

1. add an import statement for the AudioUnit to AudioKit.h, so the swift code can find the AU:
  #import "AKChorusAudioUnit.h"
2. open the Headers phase in the Build Phases tab for the AudioKit project and move Chorus.h from
  "Project" to Public", otherwise XCode will generate an "Include of non-modular header inside framework module" error.


# Generate DSP code with Faust

Run the following command in the directory where the node's files reside:
`faust Chorus.dsp -o Chorus.hpp -cn ChorusDSP -a ios-audiokit.cpp`

 You should now be able to build the project in XCode.
