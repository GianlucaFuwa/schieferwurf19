#include <cmath>

void callback1(Fl_Widget*, void*) { //Definition callback1-Funktion
	double R{ 20 }; //Radius des Kreises wird festgelegt
	double xmin{ R }, xmax{ w - R }, ymin{ h / 4 + R }, ymax{ h - R }; // Minimal- und Maximalwerte fuer Hoehe und Breite werden definiert
	double x0{ 0 }, y0{ slider1.get_value() * 0.001 * (h - R - h / 4 - R) + ymin }; //Koordinaten des Kreis-Mittelpunkts werden festgelegt
	vector<double>x, y, vx, vy; // X- und Y- Komponenten des v-Vektors und des Kreismittelpunktes werden eingefuegt
	x.push_back(x0);
	y.push_back(y0); //Mittelpunktkoordinaten werden in einen Kreis-Vektor eingefuegt.
	Circle circle1(Point(x0, y0), R, 1, FL_GREEN, FL_BLUE); //Konstruierung des Kreises via Fltk mit Farbe usw.
	window.attach(circle1); //Kreis wird in das Fenster eingebunden.
	int N = stoi(inbox1.get_value()); //Startwinkel wird aus der inbox1 als integer im Gradmass eingelesen
	double v0{ stod(inbox2.get_value()) * 0.1 }, dt{ 1 }; //der string in inbox2 wird als double fuer den Betrag der Geschwindigkeit verwendet
	double theta{ -N * PI / 180 }; //Winkel wird in Bogenmass uebertragen
	vx.push_back(v0 * cos(theta));// Die X- und Y- Komponente des Geschwindigkeitsvektors werden definiert
	vy.push_back(v0 * sin(theta));
	while (true) { // fuehre if-Bedingung aus, die den Aufprall an die Raender des Fensters darstellt
		if (x[0] > xmax) {
			vx[0] *= -1;
			x[0] = xmax;
		}
		else if (x[0] < xmin) {
			vx[0] *= -1;
			x[0] = xmin;
		}
		if (y[0] > ymax) { // Wenn der Ball die Raender beruehrt, wird dieser elastisch abgestossen
			vy[0] *= -1;
			y[0] = ymax;
		}
		else if (y[0] < ymin) {
			vy[0] *= -1;
			y[0] = ymin;
		}
		x[0] += vx[0] * dt;
		y[0] += vy[0] * dt;
		circle1.relocate(x[0], y[0]);
		v0 = sqrt(vx[0] * vx[0] + vy[0] * vy[0]);
		Fl::check();
		Fl::redraw();
		
	}
}
