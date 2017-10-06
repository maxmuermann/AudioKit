# Build

In order to get this node to build correctly, the following steps are necessary:

1. add an import statement for the AudioUnit to AudioKit.h, so the swift code can find the AU:
  #import "AKDistortion1Unit.h"
2. open the Headers phase in the Build Phases tab for the AudioKit project and move Distortion1.h from
  "Project" to Public", otherwise XCode will generate an "Include of non-modular header inside framework module" error.


# Generate DSP code with Faust

## Install Faust
1. install llvm:
  `brew install --with-clang llvm`
2. Get the lastest faust source. You will need the faust2 branch in order to be able to generate C code:
  ```
  git clone https://github.com/grame-cncm/faust.git
  git checkout faust3
  make
  sudo make install
  ```

### Install Faust architecture template

After successful installation, copy the `ios-audiokit.cpp` file from <wherever this ends up> to `/usr/local/share/faust`

## Compile DSP code

Run the following command in the directory where the node's files reside:
`faust Distortion1.dsp -o Distortion1.h -cn Distortion1DSP -a ios-audiokit.cpp -lang c`

You should now be able to build the project in XCode.
