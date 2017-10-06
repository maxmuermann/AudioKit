// placeholder for faust-generated code

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float param0;
} ___VARIABLE_nodeName___DSP;

void classInit___VARIABLE_nodeName___DSP(int samplingFreq) {};
___VARIABLE_nodeName___DSP* new___VARIABLE_nodeName___DSP() {
    ___VARIABLE_nodeName___DSP* dsp = (___VARIABLE_nodeName___DSP*)malloc(sizeof(___VARIABLE_nodeName___DSP));
    return dsp;
};
void init___VARIABLE_nodeName___DSP(___VARIABLE_nodeName___DSP* dsp, int samplingFreq) {};
void compute___VARIABLE_nodeName___DSP(___VARIABLE_nodeName___DSP* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
    printf("computeDSP\n");
    // simple stereo pass-through
    for (int i = 0; (i < count); i = (i + 1)) {
        outputs[0][i] = inputs[0][i];
        outputs[1][i] = inputs[1][i];
    }
};
void delete___VARIABLE_nodeName___DSP(___VARIABLE_nodeName___DSP* dsp) {};

#ifdef __cplusplus
};
#endif
