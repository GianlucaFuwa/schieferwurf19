#include <cmath>

void callback1(Fl_Widget*, void*) { //Definition callback1-Funktion
	double R{ 20 }; //Radius des Kreises wird festgelegt
	double x0{ 0 }, y0{ slider1.get_value() * 0.001 * (h - R - h / 4 - R) + ymin }; //Koordinaten des Kreis-Mittelpunkts werden festgelegt
	vector<double>x, y; 
	x.push_back(x0);
	y.push_back(y0); //Mittelpunktkoordinaten werden in einen Kreis-Vektor eingefuegt.
	Circle circle1(Point(x0, y0), R, 1, FL_GREEN, FL_BLUE); //Konstruierung des Kreises via Fltk mit Farbe usw.
	window.attach(circle1); //Kreis wird in das Fenster eingebunden.
}
