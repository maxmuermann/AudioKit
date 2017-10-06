/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "Distortion1"
version: "0.01"
Code generated with Faust 2.4.2 (http://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */
#include <stdlib.h>

#ifndef  __Distortion1DSP_H__
#define  __Distortion1DSP_H__




#include "CUI.h"
#include <math.h>

#define max(a,b) ((a < b) ? b : a)
#define min(a,b) ((a < b) ? a : b)


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

float cosf(float dummy0);
float sinf(float dummy0);
float powf(float dummy0, float dummy1);
float tanf(float dummy0);
static float Distortion1DSP_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS Distortion1DSP
#endif

typedef struct {
	
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
	
} Distortion1DSP;

Distortion1DSP* newDistortion1DSP() { 
	Distortion1DSP* dsp = (Distortion1DSP*)malloc(sizeof(Distortion1DSP));
	return dsp;
}

void deleteDistortion1DSP(Distortion1DSP* dsp) { 
	free(dsp);
}

void metadataDistortion1DSP(MetaGlue* m) { 
	m->declare(m->metaInterface, "HighShelf.dsp/id", "HighShelf");
	m->declare(m->metaInterface, "author", "brummer");
	m->declare(m->metaInterface, "copyright", "(c)brummer 2008");
	m->declare(m->metaInterface, "effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
	m->declare(m->metaInterface, "effect.lib/copyright", "Julius O. Smith III");
	m->declare(m->metaInterface, "effect.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
	m->declare(m->metaInterface, "effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
	m->declare(m->metaInterface, "effect.lib/exciter_license", "MIT License (MIT)");
	m->declare(m->metaInterface, "effect.lib/exciter_name", "Harmonic Exciter");
	m->declare(m->metaInterface, "effect.lib/exciter_version", "1.0");
	m->declare(m->metaInterface, "effect.lib/license", "STK-4.3");
	m->declare(m->metaInterface, "effect.lib/name", "Faust Audio Effect Library");
	m->declare(m->metaInterface, "effect.lib/version", "1.33");
	m->declare(m->metaInterface, "filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
	m->declare(m->metaInterface, "filter.lib/copyright", "Julius O. Smith III");
	m->declare(m->metaInterface, "filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "filter.lib/license", "STK-4.3");
	m->declare(m->metaInterface, "filter.lib/name", "Faust Filter Library");
	m->declare(m->metaInterface, "filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
	m->declare(m->metaInterface, "filter.lib/version", "1.29");
	m->declare(m->metaInterface, "id", "distortion1");
	m->declare(m->metaInterface, "license", "BSD");
	m->declare(m->metaInterface, "math.lib/author", "GRAME");
	m->declare(m->metaInterface, "math.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "math.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "math.lib/name", "Math Library");
	m->declare(m->metaInterface, "math.lib/version", "1.0");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.1");
	m->declare(m->metaInterface, "maxmsp.lib/author", "GRAME");
	m->declare(m->metaInterface, "maxmsp.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maxmsp.lib/license", "LGPL");
	m->declare(m->metaInterface, "maxmsp.lib/name", "MaxMSP compatibility Library");
	m->declare(m->metaInterface, "maxmsp.lib/version", "1.1");
	m->declare(m->metaInterface, "music.lib/author", "GRAME");
	m->declare(m->metaInterface, "music.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "music.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "music.lib/name", "Music Library");
	m->declare(m->metaInterface, "music.lib/version", "1.0");
	m->declare(m->metaInterface, "name", "Distortion1");
	m->declare(m->metaInterface, "version", "0.01");
}

int getSampleRateDistortion1DSP(Distortion1DSP* dsp) { return dsp->fSamplingFreq; }

int getNumInputsDistortion1DSP(Distortion1DSP* dsp) {
	return 1;
	
}
int getNumOutputsDistortion1DSP(Distortion1DSP* dsp) {
	return 2;
	
}
int getInputRateDistortion1DSP(Distortion1DSP* dsp, int channel) {
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
int getOutputRateDistortion1DSP(Distortion1DSP* dsp, int channel) {
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

void classInitDistortion1DSP(int samplingFreq) {
	
}

void instanceResetUserInterfaceDistortion1DSP(Distortion1DSP* dsp) {
	dsp->fCheckbox0 = (FAUSTFLOAT)0.0f;
	dsp->fVslider0 = (FAUSTFLOAT)2.0f;
	dsp->fVslider1 = (FAUSTFLOAT)0.01f;
	dsp->fVslider2 = (FAUSTFLOAT)0.64000000000000001f;
	dsp->fCheckbox1 = (FAUSTFLOAT)0.0f;
	dsp->fCheckbox2 = (FAUSTFLOAT)0.0f;
	dsp->fVslider3 = (FAUSTFLOAT)0.12f;
	dsp->fVslider4 = (FAUSTFLOAT)1.0f;
	dsp->fEntry0 = (FAUSTFLOAT)130.0f;
	dsp->fEntry1 = (FAUSTFLOAT)5000.0f;
	dsp->fVslider5 = (FAUSTFLOAT)5000.0f;
	dsp->fVslider6 = (FAUSTFLOAT)130.0f;
	
}

void instanceClearDistortion1DSP(Distortion1DSP* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			dsp->iVec0[l0] = 0;
			
		}
		
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			dsp->fRec1[l1] = 0.0f;
			
		}
		
	}
	dsp->IOTA = 0;
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; (l2 < 4096); l2 = (l2 + 1)) {
			dsp->fVec1[l2] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			dsp->fRec3[l3] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			dsp->fRec4[l4] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			dsp->fVec2[l5] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			dsp->fRec6[l6] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			dsp->fRec5[l7] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			dsp->fVec3[l8] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			dsp->fRec10[l9] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			dsp->fVec4[l10] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			dsp->fRec9[l11] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			dsp->fRec8[l12] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			dsp->fRec7[l13] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			dsp->fRec2[l14] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			dsp->fRec0[l15] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			dsp->fVec5[l16] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			dsp->fRec14[l17] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			dsp->fVec6[l18] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			dsp->fRec13[l19] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			dsp->fRec12[l20] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			dsp->fRec11[l21] = 0.0f;
			
		}
		
	}
	
}

void instanceConstantsDistortion1DSP(Distortion1DSP* dsp, int samplingFreq) {
	dsp->fSamplingFreq = samplingFreq;
	dsp->fConst0 = min(192000.0f, max(1.0f, (float)dsp->fSamplingFreq));
	dsp->fConst1 = (6.28318548f * (max(0.0f, ((0.5f * dsp->fConst0) + -100.0f)) / dsp->fConst0));
	dsp->fConst2 = cosf(dsp->fConst1);
	dsp->fConst3 = (0.683772206f * dsp->fConst2);
	dsp->fConst4 = (0.00562341325f * sinf(dsp->fConst1));
	dsp->fConst5 = (dsp->fConst3 + dsp->fConst4);
	dsp->fConst6 = (1.0f / (dsp->fConst5 + 1.31622779f));
	dsp->fConst7 = (0.316227764f * (dsp->fConst4 + (1.31622779f - dsp->fConst3)));
	dsp->fConst8 = (3.14159274f / dsp->fConst0);
	dsp->fConst9 = (1.31622779f * dsp->fConst2);
	dsp->fConst10 = (2.0f * (-0.683772206f - dsp->fConst9));
	dsp->fConst11 = (dsp->fConst3 + (1.31622779f - dsp->fConst4));
	dsp->fConst12 = (0.0f - (0.632455528f * (dsp->fConst9 + -0.683772206f)));
	dsp->fConst13 = (0.316227764f * (1.31622779f - dsp->fConst5));
	
}

void instanceInitDistortion1DSP(Distortion1DSP* dsp, int samplingFreq) {
	instanceConstantsDistortion1DSP(dsp, samplingFreq);
	instanceResetUserInterfaceDistortion1DSP(dsp);
	instanceClearDistortion1DSP(dsp);
}

void initDistortion1DSP(Distortion1DSP* dsp, int samplingFreq) {
	classInitDistortion1DSP(samplingFreq);
	instanceInitDistortion1DSP(dsp, samplingFreq);
}

void buildUserInterfaceDistortion1DSP(Distortion1DSP* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "Distortion1");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "drive", &dsp->fVslider2, 0.639999986f, 0.0f, 1.0f, 0.00999999978f);
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "gain", &dsp->fVslider0, 2.0f, -10.0f, 10.0f, 0.100000001f);
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "level", &dsp->fVslider1, 0.00999999978f, 0.0f, 0.5f, 0.00999999978f);
	ui_interface->openHorizontalBox(ui_interface->uiInterface, "low_highcutoff");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider5, "name", "high freq");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider5, "tooltip", "high-freq cutoff Hz");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "high_freq", &dsp->fVslider5, 5000.0f, 1000.0f, 12000.0f, 10.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider6, "name", "low freq");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider6, "tooltip", "low-freq cutoff Hz");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "low_freq", &dsp->fVslider6, 130.0f, 20.0f, 1000.0f, 10.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox0, "name", "low highcutoff");
	ui_interface->addCheckButton(ui_interface->uiInterface, "on_off", &dsp->fCheckbox0);
	ui_interface->closeBox(ui_interface->uiInterface);
	ui_interface->openHorizontalBox(ui_interface->uiInterface, "low_highpass");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fEntry0, "name", "high freq");
	ui_interface->addNumEntry(ui_interface->uiInterface, "high_freq", &dsp->fEntry0, 130.0f, 20.0f, 7040.0f, 10.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fEntry1, "name", "low freq");
	ui_interface->addNumEntry(ui_interface->uiInterface, "low_freq", &dsp->fEntry1, 5000.0f, 20.0f, 12000.0f, 10.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox1, "name", "low highpass");
	ui_interface->addCheckButton(ui_interface->uiInterface, "on_off", &dsp->fCheckbox1);
	ui_interface->closeBox(ui_interface->uiInterface);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox2, "name", "resonat");
	ui_interface->addCheckButton(ui_interface->uiInterface, "resonator.on_off", &dsp->fCheckbox2);
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "trigger", &dsp->fVslider3, 0.119999997f, 0.0f, 1.0f, 0.00999999978f);
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "vibrato", &dsp->fVslider4, 1.0f, 0.0f, 1.0f, 0.00999999978f);
	ui_interface->closeBox(ui_interface->uiInterface);
	
}

void computeDistortion1DSP(Distortion1DSP* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	int iSlow0 = (int)(float)dsp->fCheckbox0;
	float fSlow1 = (0.00100000005f * powf(10.0f, (0.0500000007f * ((float)dsp->fVslider0 + -10.0f))));
	float fSlow2 = (float)dsp->fVslider1;
	float fSlow3 = (dsp->fConst6 * powf(10.0f, (2.0f * (float)dsp->fVslider2)));
	int iSlow4 = (int)(float)dsp->fCheckbox1;
	int iSlow5 = (int)(float)dsp->fCheckbox2;
	float fSlow6 = (1.0f - (float)dsp->fVslider3);
	float fSlow7 = (float)dsp->fVslider4;
	int iSlow8 = ((int)(fSlow7 + -1.0f) & 4095);
	int iSlow9 = ((int)fSlow7 & 4095);
	float fSlow10 = (1.0f / tanf((dsp->fConst8 * (float)dsp->fEntry0)));
	float fSlow11 = (fSlow10 + 1.0f);
	float fSlow12 = (0.0f - ((1.0f - fSlow10) / fSlow11));
	float fSlow13 = (1.0f / fSlow11);
	float fSlow14 = (1.0f / tanf((dsp->fConst8 * (float)dsp->fEntry1)));
	float fSlow15 = (fSlow14 + 1.0f);
	float fSlow16 = (0.0f - ((1.0f - fSlow14) / fSlow15));
	float fSlow17 = (1.0f / fSlow15);
	float fSlow18 = (0.0f - fSlow10);
	float fSlow19 = tanf((dsp->fConst8 * (float)dsp->fVslider5));
	float fSlow20 = (1.0f / fSlow19);
	float fSlow21 = (1.0f / (((fSlow20 + 0.765366852f) / fSlow19) + 1.0f));
	float fSlow22 = (1.0f / (((fSlow20 + 1.84775901f) / fSlow19) + 1.0f));
	float fSlow23 = (dsp->fConst8 * (float)dsp->fVslider6);
	float fSlow24 = (1.0f / (fSlow23 + 1.0f));
	float fSlow25 = (1.0f - fSlow23);
	float fSlow26 = (((fSlow20 + -1.84775901f) / fSlow19) + 1.0f);
	float fSlow27 = (2.0f * (1.0f - (1.0f / Distortion1DSP_faustpower2_f(fSlow19))));
	float fSlow28 = (((fSlow20 + -0.765366852f) / fSlow19) + 1.0f);
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			dsp->iVec0[0] = 1;
			dsp->fRec1[0] = (fSlow1 + (0.999000013f * dsp->fRec1[1]));
			float fTemp0 = (float)input0[i];
			float fTemp1 = (fTemp0 + (fSlow6 * dsp->fRec3[1]));
			dsp->fVec1[(dsp->IOTA & 4095)] = fTemp1;
			dsp->fRec3[0] = (0.5f * (dsp->fVec1[((dsp->IOTA - iSlow8) & 4095)] + dsp->fVec1[((dsp->IOTA - iSlow9) & 4095)]));
			float fTemp2 = (iSlow5?dsp->fRec3[0]:fTemp0);
			dsp->fRec4[0] = ((9.99999968e-21f * (float)(1 - dsp->iVec0[1])) - dsp->fRec4[1]);
			float fTemp3 = (fTemp2 + (2.0f * dsp->fRec4[0]));
			dsp->fVec2[0] = fTemp3;
			dsp->fRec6[0] = ((fSlow16 * dsp->fRec6[1]) + (fSlow17 * (fTemp3 + dsp->fVec2[1])));
			dsp->fRec5[0] = ((fSlow12 * dsp->fRec5[1]) + (fSlow13 * ((fSlow10 * dsp->fRec6[0]) + (fSlow18 * dsp->fRec6[1]))));
			float fTemp4 = (iSlow4?dsp->fRec5[0]:(fTemp2 + dsp->fRec4[0]));
			float fTemp5 = ((dsp->fRec4[0] + fTemp4) + 9.99999968e-21f);
			dsp->fVec3[0] = (fSlow24 * fTemp5);
			dsp->fRec10[0] = ((fSlow24 * (fTemp5 + (fSlow25 * dsp->fRec10[1]))) - dsp->fVec3[1]);
			dsp->fVec4[0] = (fSlow24 * dsp->fRec10[0]);
			dsp->fRec9[0] = ((fSlow24 * ((fSlow25 * dsp->fRec9[1]) + dsp->fRec10[0])) - dsp->fVec4[1]);
			dsp->fRec8[0] = (dsp->fRec9[0] - (fSlow22 * ((fSlow26 * dsp->fRec8[2]) + (fSlow27 * dsp->fRec8[1]))));
			dsp->fRec7[0] = ((fSlow22 * (dsp->fRec8[2] + ((2.0f * dsp->fRec8[1]) + dsp->fRec8[0]))) - (fSlow21 * ((fSlow28 * dsp->fRec7[2]) + (fSlow27 * dsp->fRec7[1]))));
			dsp->fRec2[0] = ((iSlow0?(fSlow21 * (dsp->fRec7[2] + ((2.0f * dsp->fRec7[1]) + dsp->fRec7[0]))):(fTemp4 + 9.99999968e-21f)) - (dsp->fConst6 * ((dsp->fConst10 * dsp->fRec2[1]) + (dsp->fConst11 * dsp->fRec2[2]))));
			float fTemp6 = max(-1.0f, min(1.0f, (fSlow2 + (fSlow3 * (((dsp->fConst7 * dsp->fRec2[0]) + (dsp->fConst12 * dsp->fRec2[1])) + (dsp->fConst13 * dsp->fRec2[2]))))));
			dsp->fRec0[0] = (((dsp->fRec1[0] * fTemp6) * (1.0f - (0.333333343f * Distortion1DSP_faustpower2_f(fTemp6)))) - (dsp->fConst6 * ((dsp->fConst11 * dsp->fRec0[2]) + (dsp->fConst10 * dsp->fRec0[1]))));
			float fTemp7 = (dsp->fConst6 * (((dsp->fConst7 * dsp->fRec0[0]) + (dsp->fConst12 * dsp->fRec0[1])) + (dsp->fConst13 * dsp->fRec0[2])));
			float fTemp8 = (dsp->fRec4[0] + fTemp7);
			dsp->fVec5[0] = (fSlow24 * fTemp8);
			dsp->fRec14[0] = ((fSlow24 * (fTemp8 + (fSlow25 * dsp->fRec14[1]))) - dsp->fVec5[1]);
			dsp->fVec6[0] = (fSlow24 * dsp->fRec14[0]);
			dsp->fRec13[0] = ((fSlow24 * (dsp->fRec14[0] + (fSlow25 * dsp->fRec13[1]))) - dsp->fVec6[1]);
			dsp->fRec12[0] = (dsp->fRec13[0] - (fSlow22 * ((fSlow27 * dsp->fRec12[1]) + (fSlow26 * dsp->fRec12[2]))));
			dsp->fRec11[0] = ((fSlow22 * (dsp->fRec12[2] + (dsp->fRec12[0] + (2.0f * dsp->fRec12[1])))) - (fSlow21 * ((fSlow27 * dsp->fRec11[1]) + (fSlow28 * dsp->fRec11[2]))));
			float fTemp9 = (iSlow0?(fSlow21 * (dsp->fRec11[2] + (dsp->fRec11[0] + (2.0f * dsp->fRec11[1])))):fTemp7);
			output0[i] = (FAUSTFLOAT)fTemp9;
			output1[i] = (FAUSTFLOAT)fTemp9;
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->IOTA = (dsp->IOTA + 1);
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec8[2] = dsp->fRec8[1];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec7[2] = dsp->fRec7[1];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec2[2] = dsp->fRec2[1];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec12[2] = dsp->fRec12[1];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec11[2] = dsp->fRec11[1];
			dsp->fRec11[1] = dsp->fRec11[0];
			
		}
		
	}
	
}

#ifdef __cplusplus
}
#endif



#endif
