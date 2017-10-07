/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "Distortion1"
version: "0.01"
Code generated with Faust 2.4.2 (http://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __Distortion1DSP_H__
#define  __Distortion1DSP_H__




#include "GUI.hpp"
#include <math.h>

#define max(a,b) ((a < b) ? b : a)
#define min(a,b) ((a < b) ? a : b)


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

#include <math.h>

static float Distortion1DSP_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS Distortion1DSP
#endif

class Distortion1DSP : public dsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fVslider0;
	int iVec0[2];
	float fRec1[2];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fVslider3;
	int IOTA;
	float fVec1[4096];
	FAUSTFLOAT fVslider4;
	float fRec3[2];
	float fRec4[2];
	float fConst8;
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fEntry1;
	float fVec2[2];
	float fRec6[2];
	float fRec5[2];
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	float fVec3[2];
	float fRec10[2];
	float fVec4[2];
	float fRec9[2];
	float fRec8[3];
	float fRec7[3];
	float fConst9;
	float fConst10;
	float fConst11;
	float fRec2[3];
	float fConst12;
	float fConst13;
	float fRec0[3];
	float fVec5[2];
	float fRec14[2];
	float fVec6[2];
	float fRec13[2];
	float fRec12[3];
	float fRec11[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("HighShelf.dsp/id", "HighShelf");
		m->declare("author", "brummer");
		m->declare("copyright", "(c)brummer 2008");
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
		m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
		m->declare("effect.lib/exciter_license", "MIT License (MIT)");
		m->declare("effect.lib/exciter_name", "Harmonic Exciter");
		m->declare("effect.lib/exciter_version", "1.0");
		m->declare("effect.lib/license", "STK-4.3");
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/version", "1.33");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter.lib/version", "1.29");
		m->declare("id", "distortion1");
		m->declare("license", "BSD");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/version", "1.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("maxmsp.lib/author", "GRAME");
		m->declare("maxmsp.lib/copyright", "GRAME");
		m->declare("maxmsp.lib/license", "LGPL");
		m->declare("maxmsp.lib/name", "MaxMSP compatibility Library");
		m->declare("maxmsp.lib/version", "1.1");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
		m->declare("name", "Distortion1");
		m->declare("version", "0.01");
	}

	virtual int getNumInputs() {
		return 1;
		
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
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(192000.0f, max(1.0f, float(fSamplingFreq)));
		fConst1 = (6.28318548f * (max(0.0f, ((0.5f * fConst0) + -100.0f)) / fConst0));
		fConst2 = cosf(fConst1);
		fConst3 = (0.683772206f * fConst2);
		fConst4 = (0.00562341325f * sinf(fConst1));
		fConst5 = (fConst3 + fConst4);
		fConst6 = (1.0f / (fConst5 + 1.31622779f));
		fConst7 = (0.316227764f * (fConst4 + (1.31622779f - fConst3)));
		fConst8 = (3.14159274f / fConst0);
		fConst9 = (1.31622779f * fConst2);
		fConst10 = (2.0f * (-0.683772206f - fConst9));
		fConst11 = (fConst3 + (1.31622779f - fConst4));
		fConst12 = (0.0f - (0.632455528f * (fConst9 + -0.683772206f)));
		fConst13 = (0.316227764f * (1.31622779f - fConst5));
		
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fVslider0 = FAUSTFLOAT(2.0f);
		fVslider1 = FAUSTFLOAT(0.01f);
		fVslider2 = FAUSTFLOAT(0.64000000000000001f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fVslider3 = FAUSTFLOAT(0.12f);
		fVslider4 = FAUSTFLOAT(1.0f);
		fEntry0 = FAUSTFLOAT(130.0f);
		fEntry1 = FAUSTFLOAT(5000.0f);
		fVslider5 = FAUSTFLOAT(5000.0f);
		fVslider6 = FAUSTFLOAT(130.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
			
		}
		IOTA = 0;
		for (int l2 = 0; (l2 < 4096); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec4[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec7[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec2[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec0[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec5[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec14[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec6[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec12[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec11[l21] = 0.0f;
			
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
	
	virtual Distortion1DSP* clone() {
		return new Distortion1DSP();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Distortion1");
		ui_interface->addVerticalSlider("drive", &fVslider2, 0.639999986f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addVerticalSlider("gain", &fVslider0, 2.0f, -10.0f, 10.0f, 0.100000001f);
		ui_interface->addVerticalSlider("level", &fVslider1, 0.00999999978f, 0.0f, 0.5f, 0.00999999978f);
		ui_interface->openHorizontalBox("low_highcutoff");
		ui_interface->declare(&fVslider5, "name", "high freq");
		ui_interface->declare(&fVslider5, "tooltip", "high-freq cutoff Hz");
		ui_interface->addVerticalSlider("speaker.high_freq", &fVslider5, 5000.0f, 1000.0f, 12000.0f, 10.0f);
		ui_interface->declare(&fVslider6, "name", "low freq");
		ui_interface->declare(&fVslider6, "tooltip", "low-freq cutoff Hz");
		ui_interface->addVerticalSlider("speaker.low_freq", &fVslider6, 130.0f, 20.0f, 1000.0f, 10.0f);
		ui_interface->declare(&fCheckbox0, "name", "low highcutoff");
		ui_interface->addCheckButton("speaker.on_off", &fCheckbox0);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("low_highpass");
		ui_interface->declare(&fEntry0, "name", "high freq");
		ui_interface->addNumEntry("filter.high_freq", &fEntry0, 130.0f, 20.0f, 7040.0f, 10.0f);
		ui_interface->declare(&fEntry1, "name", "low freq");
		ui_interface->addNumEntry("filter.low_freq", &fEntry1, 5000.0f, 20.0f, 12000.0f, 10.0f);
		ui_interface->declare(&fCheckbox1, "name", "low highpass");
		ui_interface->addCheckButton("filter.on_off", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->declare(&fCheckbox2, "name", "resonat");
		ui_interface->addCheckButton("resonator.on_off", &fCheckbox2);
		ui_interface->addVerticalSlider("trigger", &fVslider3, 0.119999997f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addVerticalSlider("vibrato", &fVslider4, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = int(float(fCheckbox0));
		float fSlow1 = (0.00100000005f * powf(10.0f, (0.0500000007f * (float(fVslider0) + -10.0f))));
		float fSlow2 = float(fVslider1);
		float fSlow3 = (fConst6 * powf(10.0f, (2.0f * float(fVslider2))));
		int iSlow4 = int(float(fCheckbox1));
		int iSlow5 = int(float(fCheckbox2));
		float fSlow6 = (1.0f - float(fVslider3));
		float fSlow7 = float(fVslider4);
		int iSlow8 = (int((fSlow7 + -1.0f)) & 4095);
		int iSlow9 = (int(fSlow7) & 4095);
		float fSlow10 = (1.0f / tanf((fConst8 * float(fEntry0))));
		float fSlow11 = (fSlow10 + 1.0f);
		float fSlow12 = (0.0f - ((1.0f - fSlow10) / fSlow11));
		float fSlow13 = (1.0f / fSlow11);
		float fSlow14 = (1.0f / tanf((fConst8 * float(fEntry1))));
		float fSlow15 = (fSlow14 + 1.0f);
		float fSlow16 = (0.0f - ((1.0f - fSlow14) / fSlow15));
		float fSlow17 = (1.0f / fSlow15);
		float fSlow18 = (0.0f - fSlow10);
		float fSlow19 = tanf((fConst8 * float(fVslider5)));
		float fSlow20 = (1.0f / fSlow19);
		float fSlow21 = (1.0f / (((fSlow20 + 0.765366852f) / fSlow19) + 1.0f));
		float fSlow22 = (1.0f / (((fSlow20 + 1.84775901f) / fSlow19) + 1.0f));
		float fSlow23 = (fConst8 * float(fVslider6));
		float fSlow24 = (1.0f / (fSlow23 + 1.0f));
		float fSlow25 = (1.0f - fSlow23);
		float fSlow26 = (((fSlow20 + -1.84775901f) / fSlow19) + 1.0f);
		float fSlow27 = (2.0f * (1.0f - (1.0f / Distortion1DSP_faustpower2_f(fSlow19))));
		float fSlow28 = (((fSlow20 + -0.765366852f) / fSlow19) + 1.0f);
		for (int i = 0; (i < count); i = (i + 1)) {
			iVec0[0] = 1;
			fRec1[0] = (fSlow1 + (0.999000013f * fRec1[1]));
			float fTemp0 = float(input0[i]);
			float fTemp1 = ((fSlow6 * fRec3[1]) + fTemp0);
			fVec1[(IOTA & 4095)] = fTemp1;
			fRec3[0] = (0.5f * (fVec1[((IOTA - iSlow8) & 4095)] + fVec1[((IOTA - iSlow9) & 4095)]));
			float fTemp2 = (iSlow5?fRec3[0]:fTemp0);
			fRec4[0] = ((9.99999968e-21f * float((1 - iVec0[1]))) - fRec4[1]);
			float fTemp3 = (fTemp2 + (2.0f * fRec4[0]));
			fVec2[0] = fTemp3;
			fRec6[0] = ((fSlow16 * fRec6[1]) + (fSlow17 * (fTemp3 + fVec2[1])));
			fRec5[0] = ((fSlow12 * fRec5[1]) + (fSlow13 * ((fSlow10 * fRec6[0]) + (fSlow18 * fRec6[1]))));
			float fTemp4 = (iSlow4?fRec5[0]:(fTemp2 + fRec4[0]));
			float fTemp5 = ((fRec4[0] + fTemp4) + 9.99999968e-21f);
			fVec3[0] = (fSlow24 * fTemp5);
			fRec10[0] = ((fSlow24 * (fTemp5 + (fSlow25 * fRec10[1]))) - fVec3[1]);
			fVec4[0] = (fSlow24 * fRec10[0]);
			fRec9[0] = ((fSlow24 * (fRec10[0] + (fSlow25 * fRec9[1]))) - fVec4[1]);
			fRec8[0] = (fRec9[0] - (fSlow22 * ((fSlow26 * fRec8[2]) + (fSlow27 * fRec8[1]))));
			fRec7[0] = ((fSlow22 * (fRec8[2] + (fRec8[0] + (2.0f * fRec8[1])))) - (fSlow21 * ((fSlow28 * fRec7[2]) + (fSlow27 * fRec7[1]))));
			fRec2[0] = ((iSlow0?(fSlow21 * (fRec7[2] + (fRec7[0] + (2.0f * fRec7[1])))):(fTemp4 + 9.99999968e-21f)) - (fConst6 * ((fConst10 * fRec2[1]) + (fConst11 * fRec2[2]))));
			float fTemp6 = max(-1.0f, min(1.0f, (fSlow2 + (fSlow3 * (((fConst7 * fRec2[0]) + (fConst12 * fRec2[1])) + (fConst13 * fRec2[2]))))));
			fRec0[0] = (((fRec1[0] * fTemp6) * (1.0f - (0.333333343f * Distortion1DSP_faustpower2_f(fTemp6)))) - (fConst6 * ((fConst11 * fRec0[2]) + (fConst10 * fRec0[1]))));
			float fTemp7 = (fConst6 * (((fConst7 * fRec0[0]) + (fConst12 * fRec0[1])) + (fConst13 * fRec0[2])));
			float fTemp8 = (fRec4[0] + fTemp7);
			fVec5[0] = (fSlow24 * fTemp8);
			fRec14[0] = ((fSlow24 * (fTemp8 + (fSlow25 * fRec14[1]))) - fVec5[1]);
			fVec6[0] = (fSlow24 * fRec14[0]);
			fRec13[0] = ((fSlow24 * (fRec14[0] + (fSlow25 * fRec13[1]))) - fVec6[1]);
			fRec12[0] = (fRec13[0] - (fSlow22 * ((fSlow27 * fRec12[1]) + (fSlow26 * fRec12[2]))));
			fRec11[0] = ((fSlow22 * (fRec12[2] + (fRec12[0] + (2.0f * fRec12[1])))) - (fSlow21 * ((fSlow27 * fRec11[1]) + (fSlow28 * fRec11[2]))));
			float fTemp9 = (iSlow0?(fSlow21 * (fRec11[2] + (fRec11[0] + (2.0f * fRec11[1])))):fTemp7);
			output0[i] = FAUSTFLOAT(fTemp9);
			output1[i] = FAUSTFLOAT(fTemp9);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fVec2[1] = fVec2[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fVec3[1] = fVec3[0];
			fRec10[1] = fRec10[0];
			fVec4[1] = fVec4[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fVec5[1] = fVec5[0];
			fRec14[1] = fRec14[0];
			fVec6[1] = fVec6[0];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			
		}
		
	}

	
};


#endif
