#pragma once

#define WIN32
#include <FL/Fl.h> 
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using Callback = void(*)(Fl_Widget*, void*);

int w{Fl::w()/2 + 500}, h{Fl::h() - 100};
