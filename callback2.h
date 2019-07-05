#pragma once

#include "gnuplot-iostream.h" //gnuplot-iostream um gnuplot fenster zu öffnen.

void callback2(Fl_Widget*, void*) { //callback2-Funktion ruft beim drücken ein gnuplot-Fenster auf, in welchem die aufgenommenen y-Werte gegen die Zeit aufgetragen werden.
	Gnuplot gp;
	gp << R"(
		set terminal wxt size 750,750 enhanced font 'Verdana,20'
		set title 'Height vs Time'
		set xlabel 'Time (s)'
		set ylabel 'Height (m)'
		plot 'height_vs_time.txt' w l lw 3 notitle //Werte werden aus der Datei heightvstime.txt aus callback1 genommen
	)";
}
