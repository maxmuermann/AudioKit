/* ------------------------------------------------------------
author: "Albert Graef"
name: "Chorus"
version: "1.0"
Code generated with Faust 2.4.2 (http://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */

#ifndef Chorus_h
#define Chorus_h

#include "GUI.hpp"
#include <math.h>

#define max(a,b) ((a < b) ? b : a)
#define min(a,b) ((a < b) ? a : b)

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class ChorusDSPSIG0 {
	
  private:
	
	int iRec2[2];
	
  public:
	
	int getNumInputsChorusDSPSIG0() {
		return 0;
		
	}
	int getNumOutputsChorusDSPSIG0() {
		return 1;
		
	}
	int getInputRateChorusDSPSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRateChorusDSPSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitChorusDSPSIG0(int samplingFreq) {
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec2[l3] = 0;
			
		}
		
	}
	
	void fillChorusDSPSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec2[0] = (iRec2[1] + 1);
			output[i] = sinf((9.58738019e-05f * float((iRec2[0] + -1))));
			iRec2[1] = iRec2[0];
			
		}
		
	}
};

ChorusDSPSIG0* newChorusDSPSIG0() { return (ChorusDSPSIG0*)new ChorusDSPSIG0(); }
void deleteChorusDSPSIG0(ChorusDSPSIG0* dsp) { delete dsp; }

static float ftbl0ChorusDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS ChorusDSP
#endif

class ChorusDSP : public dsp {
	
 private:
	
	int IOTA;
	float fVec0[65536];
	FAUSTFLOAT fHslider0;
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fRec1[2];
	float fVec1[65536];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Albert Graef");
		m->declare("category", "Modulation");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter.lib/version", "1.29");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/version", "1.0");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
		m->declare("name", "Chorus");
		m->declare("version", "1.0");
	}

	virtual int getNumInputs() {
		return 2;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		ChorusDSPSIG0* sig0 = newChorusDSPSIG0();
		sig0->instanceInitChorusDSPSIG0(samplingFreq);
		sig0->fillChorusDSPSIG0(65536, ftbl0ChorusDSPSIG0);
		deleteChorusDSPSIG0(sig0);
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(192000.0f, max(1.0f, float(fSamplingFreq)));
		fConst1 = (0.5f * fConst0);
		fConst2 = (1.0f / fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.02f);
		fHslider2 = FAUSTFLOAT(0.02f);
		fHslider3 = FAUSTFLOAT(3.0f);
		
	}
	
	virtual void instanceClear() {
		IOTA = 0;
		for (int l0 = 0; (l0 < 65536); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 65536); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual ChorusDSP* clone() {
		return new ChorusDSP();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("chorus");
		ui_interface->declare(&fHslider1, "name", "Delay");
		ui_interface->addHorizontalSlider("delay", &fHslider1, 0.0199999996f, 0.0f, 0.200000003f, 0.00999999978f);
		ui_interface->declare(&fHslider2, "name", "Depth");
		ui_interface->addHorizontalSlider("depth", &fHslider2, 0.0199999996f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fHslider3, "name", "Freq");
		ui_interface->addHorizontalSlider("freq", &fHslider3, 3.0f, 0.0f, 10.0f, 0.00999999978f);
		ui_interface->declare(&fHslider0, "name", "Level");
		ui_interface->addHorizontalSlider("level", &fHslider0, 0.5f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (0.00100000005f * float(fHslider1));
		float fSlow2 = float(fHslider2);
		float fSlow3 = (fConst2 * float(fHslider3));
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fVec0[(IOTA & 65535)] = fTemp0;
			fRec0[0] = (fSlow1 + (0.999000013f * fRec0[1]));
			fRec1[0] = (fSlow3 + (fRec1[1] - floorf((fSlow3 + fRec1[1]))));
			float fTemp1 = (65536.0f * (fRec1[0] - floorf(fRec1[0])));
			float fTemp2 = floorf(fTemp1);
			int iTemp3 = int(fTemp2);
			float fTemp4 = (fConst1 * (fRec0[0] * ((fSlow2 * (((fTemp2 + (1.0f - fTemp1)) * ftbl0ChorusDSPSIG0[(iTemp3 & 65535)]) + ((fTemp1 - fTemp2) * ftbl0ChorusDSPSIG0[((iTemp3 + 1) & 65535)]))) + 1.0f)));
			int iTemp5 = int(fTemp4);
			output0[i] = FAUSTFLOAT((fTemp0 + (fSlow0 * ((fVec0[((IOTA - (iTemp5 & 65535)) & 65535)] * (float(iTemp5) + (1.0f - fTemp4))) + ((fTemp4 - float(iTemp5)) * fVec0[((IOTA - ((iTemp5 + 1) & 65535)) & 65535)])))));
			float fTemp6 = float(input1[i]);
			fVec1[(IOTA & 65535)] = fTemp6;
			float fTemp7 = (65536.0f * (fRec1[0] + (0.25f - floorf((fRec1[0] + 0.25f)))));
			float fTemp8 = floorf(fTemp7);
			int iTemp9 = int(fTemp8);
			float fTemp10 = (fConst1 * (fRec0[0] * ((fSlow2 * (((fTemp8 + (1.0f - fTemp7)) * ftbl0ChorusDSPSIG0[(iTemp9 & 65535)]) + ((fTemp7 - fTemp8) * ftbl0ChorusDSPSIG0[((iTemp9 + 1) & 65535)]))) + 1.0f)));
			int iTemp11 = int(fTemp10);
			output1[i] = FAUSTFLOAT(((fSlow0 * ((fVec1[((IOTA - (iTemp11 & 65535)) & 65535)] * (float(iTemp11) + (1.0f - fTemp10))) + ((fTemp10 - float(iTemp11)) * fVec1[((IOTA - ((iTemp11 + 1) & 65535)) & 65535)]))) + fTemp6));
			IOTA = (IOTA + 1);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			
		}
		
	}

	
};

#endif
