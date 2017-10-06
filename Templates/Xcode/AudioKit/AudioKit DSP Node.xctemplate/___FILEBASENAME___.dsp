// compile with faust ___VARIABLE_nodeName___.dsp -o ___VARIABLE_nodeName___.h -a ios-audiokit.cpp -lang c
// Note: You will need Faust 2 to compile in order to generate C code

// faust metadata - not required, but nice to have?
declare name "___VARIABLE_nodeName___";
declare category "Modulation";
declare author "";
declare version "1.0";

import("music.lib");
import("filter.lib");

process         =
    // faust dsp code goes here
