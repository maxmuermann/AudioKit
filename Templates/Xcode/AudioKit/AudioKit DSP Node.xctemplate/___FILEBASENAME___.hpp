// placeholder for faust-generated code

#include "GUI.hpp"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#ifndef _____VARIABLE_nodeName____H
#define _____VARIABLE_nodeName____H

class ___VARIABLE_nodeName___DSP : public dsp {

 private:

 public:

  void metadata(Meta* m) { }

  virtual void init(int samplingFreq) {}

  virtual int getNumInputs() { return 2; };
  virtual int getNumOutputs() { return 2; };

  virtual void buildUserInterface(UI* ui_interface) { }

  virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
      // simple stereo pass-through
      for (int i = 0; (i < count); i = (i + 1)) {
          outputs[0][i] = inputs[0][i];
          outputs[1][i] = inputs[1][i];
      }
  }

};

#endif
