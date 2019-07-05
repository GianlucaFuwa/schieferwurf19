#pragma once

#define WIN32
#include <FL/Fl.h> //Fltk-libraries werden included zur Visualisierung des Wurfs.
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <string> //weitere notwendige includes
#include <vector>
#include <fstream>

using namespace std;
using Callback = void(*)(Fl_Widget*, void*); //callback-Funktion wird definiert.

int w{Fl::w()/2 + 500}, h{Fl::h() - 100}; //Fenstergröße wird festgelegt.

#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Text.h"
#include "Widget.h"
#include "Slider.h"
#include "In_box.h"
#include "Button.h"
#include "Out_Box.h"
#include "Windows.h"
