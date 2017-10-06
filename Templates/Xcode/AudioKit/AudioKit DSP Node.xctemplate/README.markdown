# Build

In order to get this node to build correctly, the following steps are necessary:

1. add an import statement for the AudioUnit to AudioKit.h, so the swift code can find the AU:
  #import "AK___VARIABLE_nodeName___AudioUnit.h"
2. open the Headers phase in the Build Phases tab for the AudioKit project and move ___VARIABLE_nodeName___.h from
  "Project" to Public", otherwise XCode will generate an "Include of non-modular header inside framework module" error.


# Generate DSP code with Faust

Run the following command in the directory where the node's files reside:
`faust ___VARIABLE_nodeName___.dsp -o ___VARIABLE_nodeName___.h -cn ___VARIABLE_nodeName___DSP -a ios-audiokit.cpp -lang c`

 You should now be able to build the project in XCode.
