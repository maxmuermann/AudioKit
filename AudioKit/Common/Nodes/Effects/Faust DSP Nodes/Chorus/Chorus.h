/* ------------------------------------------------------------
author: "Albert Graef"
name: "Chorus"
version: "1.0"
Code generated with Faust 2.4.2 (http://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */
#include <stdlib.h>

#ifndef  __ChorusDSP_H__
#define  __ChorusDSP_H__




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

float sinf(float dummy0);

typedef struct {
	
	int iRec2[2];
	
} ChorusDSPSIG0;

static ChorusDSPSIG0* newChorusDSPSIG0() { return (ChorusDSPSIG0*)malloc(sizeof(ChorusDSPSIG0)); }
static void deleteChorusDSPSIG0(ChorusDSPSIG0* dsp) { free(dsp); }

int getNumInputsChorusDSPSIG0(ChorusDSPSIG0* dsp) {
	return 0;
	
}
int getNumOutputsChorusDSPSIG0(ChorusDSPSIG0* dsp) {
	return 1;
	
}
int getInputRateChorusDSPSIG0(ChorusDSPSIG0* dsp, int channel) {
	int rate;
	switch (channel) {
		default: {
			rate = -1;
			break;
		}
		
	}
	return rate;
	
}
int getOutputRateChorusDSPSIG0(ChorusDSPSIG0* dsp, int channel) {
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

static void instanceInitChorusDSPSIG0(ChorusDSPSIG0* dsp, int samplingFreq) {
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			dsp->iRec2[l3] = 0;
			
		}
		
	}
	
}

static void fillChorusDSPSIG0(ChorusDSPSIG0* dsp, int count, float* output) {
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			dsp->iRec2[0] = (dsp->iRec2[1] + 1);
			output[i] = sinf((9.58738019e-05f * (float)(dsp->iRec2[0] + -1)));
			dsp->iRec2[1] = dsp->iRec2[0];
			
		}
		
	}
	
};

float floorf(float dummy0);
static float ftbl0ChorusDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS ChorusDSP
#endif

typedef struct {
	
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
	
} ChorusDSP;

ChorusDSP* newChorusDSP() { 
	ChorusDSP* dsp = (ChorusDSP*)malloc(sizeof(ChorusDSP));
	return dsp;
}

void deleteChorusDSP(ChorusDSP* dsp) { 
	free(dsp);
}

void metadataChorusDSP(MetaGlue* m) { 
	m->declare(m->metaInterface, "author", "Albert Graef");
	m->declare(m->metaInterface, "category", "Modulation");
	m->declare(m->metaInterface, "filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
	m->declare(m->metaInterface, "filter.lib/copyright", "Julius O. Smith III");
	m->declare(m->metaInterface, "filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "filter.lib/license", "STK-4.3");
	m->declare(m->metaInterface, "filter.lib/name", "Faust Filter Library");
	m->declare(m->metaInterface, "filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
	m->declare(m->metaInterface, "filter.lib/version", "1.29");
	m->declare(m->metaInterface, "math.lib/author", "GRAME");
	m->declare(m->metaInterface, "math.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "math.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "math.lib/name", "Math Library");
	m->declare(m->metaInterface, "math.lib/version", "1.0");
	m->declare(m->metaInterface, "music.lib/author", "GRAME");
	m->declare(m->metaInterface, "music.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
	m->declare(m->metaInterface, "music.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "music.lib/name", "Music Library");
	m->declare(m->metaInterface, "music.lib/version", "1.0");
	m->declare(m->metaInterface, "name", "Chorus");
	m->declare(m->metaInterface, "version", "1.0");
}

int getSampleRateChorusDSP(ChorusDSP* dsp) { return dsp->fSamplingFreq; }

int getNumInputsChorusDSP(ChorusDSP* dsp) {
	return 2;
	
}
int getNumOutputsChorusDSP(ChorusDSP* dsp) {
	return 2;
	
}
int getInputRateChorusDSP(ChorusDSP* dsp, int channel) {
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
int getOutputRateChorusDSP(ChorusDSP* dsp, int channel) {
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

void classInitChorusDSP(int samplingFreq) {
	ChorusDSPSIG0* sig0 = newChorusDSPSIG0();
	instanceInitChorusDSPSIG0(sig0, samplingFreq);
	fillChorusDSPSIG0(sig0, 65536, ftbl0ChorusDSPSIG0);
	deleteChorusDSPSIG0(sig0);
	
}

void instanceResetUserInterfaceChorusDSP(ChorusDSP* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)0.5f;
	dsp->fHslider1 = (FAUSTFLOAT)0.02f;
	dsp->fHslider2 = (FAUSTFLOAT)0.02f;
	dsp->fHslider3 = (FAUSTFLOAT)3.0f;
	
}

void instanceClearChorusDSP(ChorusDSP* dsp) {
	dsp->IOTA = 0;
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; (l0 < 65536); l0 = (l0 + 1)) {
			dsp->fVec0[l0] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			dsp->fRec0[l1] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			dsp->fRec1[l2] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; (l4 < 65536); l4 = (l4 + 1)) {
			dsp->fVec1[l4] = 0.0f;
			
		}
		
	}
	
}

void instanceConstantsChorusDSP(ChorusDSP* dsp, int samplingFreq) {
	dsp->fSamplingFreq = samplingFreq;
	dsp->fConst0 = min(192000.0f, max(1.0f, (float)dsp->fSamplingFreq));
	dsp->fConst1 = (0.5f * dsp->fConst0);
	dsp->fConst2 = (1.0f / dsp->fConst0);
	
}

void instanceInitChorusDSP(ChorusDSP* dsp, int samplingFreq) {
	instanceConstantsChorusDSP(dsp, samplingFreq);
	instanceResetUserInterfaceChorusDSP(dsp);
	instanceClearChorusDSP(dsp);
}

void initChorusDSP(ChorusDSP* dsp, int samplingFreq) {
	classInitChorusDSP(samplingFreq);
	instanceInitChorusDSP(dsp, samplingFreq);
}

void buildUserInterfaceChorusDSP(ChorusDSP* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "chorus");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "name", "Delay");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "delay", &dsp->fHslider1, 0.0199999996f, 0.0f, 0.200000003f, 0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "name", "Depth");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "depth", &dsp->fHslider2, 0.0199999996f, 0.0f, 1.0f, 0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "name", "Freq");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "freq", &dsp->fHslider3, 3.0f, 0.0f, 10.0f, 0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "name", "Level");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "level", &dsp->fHslider0, 0.5f, 0.0f, 1.0f, 0.00999999978f);
	ui_interface->closeBox(ui_interface->uiInterface);
	
}

void computeChorusDSP(ChorusDSP* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* input1 = inputs[1];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = (float)dsp->fHslider0;
	float fSlow1 = (0.00100000005f * (float)dsp->fHslider1);
	float fSlow2 = (float)dsp->fHslider2;
	float fSlow3 = (dsp->fConst2 * (float)dsp->fHslider3);
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = (float)input0[i];
			dsp->fVec0[(dsp->IOTA & 65535)] = fTemp0;
			dsp->fRec0[0] = (fSlow1 + (0.999000013f * dsp->fRec0[1]));
			dsp->fRec1[0] = (fSlow3 + (dsp->fRec1[1] - floorf((fSlow3 + dsp->fRec1[1]))));
			float fTemp1 = (65536.0f * (dsp->fRec1[0] - floorf(dsp->fRec1[0])));
			float fTemp2 = floorf(fTemp1);
			int iTemp3 = (int)fTemp2;
			float fTemp4 = (dsp->fConst1 * (dsp->fRec0[0] * ((fSlow2 * (((fTemp2 + (1.0f - fTemp1)) * ftbl0ChorusDSPSIG0[(iTemp3 & 65535)]) + ((fTemp1 - fTemp2) * ftbl0ChorusDSPSIG0[((iTemp3 + 1) & 65535)]))) + 1.0f)));
			int iTemp5 = (int)fTemp4;
			output0[i] = (FAUSTFLOAT)(fTemp0 + (fSlow0 * ((dsp->fVec0[((dsp->IOTA - (iTemp5 & 65535)) & 65535)] * ((float)iTemp5 + (1.0f - fTemp4))) + ((fTemp4 - (float)iTemp5) * dsp->fVec0[((dsp->IOTA - ((iTemp5 + 1) & 65535)) & 65535)]))));
			float fTemp6 = (float)input1[i];
			dsp->fVec1[(dsp->IOTA & 65535)] = fTemp6;
			float fTemp7 = (65536.0f * (dsp->fRec1[0] + (0.25f - floorf((dsp->fRec1[0] + 0.25f)))));
			float fTemp8 = floorf(fTemp7);
			int iTemp9 = (int)fTemp8;
			float fTemp10 = (dsp->fConst1 * (dsp->fRec0[0] * ((fSlow2 * (((fTemp8 + (1.0f - fTemp7)) * ftbl0ChorusDSPSIG0[(iTemp9 & 65535)]) + ((fTemp7 - fTemp8) * ftbl0ChorusDSPSIG0[((iTemp9 + 1) & 65535)]))) + 1.0f)));
			int iTemp11 = (int)fTemp10;
			output1[i] = (FAUSTFLOAT)(fTemp6 + (fSlow0 * ((dsp->fVec1[((dsp->IOTA - (iTemp11 & 65535)) & 65535)] * ((float)iTemp11 + (1.0f - fTemp10))) + ((fTemp10 - (float)iTemp11) * dsp->fVec1[((dsp->IOTA - ((iTemp11 + 1) & 65535)) & 65535)]))));
			dsp->IOTA = (dsp->IOTA + 1);
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			
		}
		
	}
	
}

#ifdef __cplusplus
}
#endif



#endif
