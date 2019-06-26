#include <iostream>
#include <cmath>
#include <chrono> //chrono-lib zur Messung und Wiedergabe der Wurfzeit und Runtime der callback-Funktion.

void callback1(Fl_Widget*, void*) { //Definition callback1-Funktion
	double R{ 20 }; //Radius des Kreises wird festgelegt
	double xmin{ R }, xmax{ w - R }, ymin{ h / 4 + R }, ymax{ h - R }; // Minimal- und Maximalwerte fuer Hoehe und Breite werden definiert
	double x0{ 0 }, y0{ slider1.get_value() * 0.001 * (h - R - h / 4 - R) + ymin }; //Koordinaten des Kreis-Mittelpunkts werden festgelegt. Man muss beachten, dass der Koordinaten Ursprung in der linken oberen Ecke liegt und man beim addieren nach unten geht.
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
	steady_clock::time_point t1 = steady_clock::now();
	steady_clock::time_point t2 = steady_clock::now();
	double showtime = 0; //Die Bedetung dieser Variable wird unten erklärt.
	while (true) { // fuehre if-Bedingung aus, die das Verhalten des Balls beim Aufprall auf die Raender des Fensters definiert.
		outbox3.set_value(to_string(h - 930 - 2.170213 - ((slider1.get_value() * 0.001 * (h - R - h / 4 - R) + ymin) / 117.5))); //Wurfhöhe wird in drittem Output-Fenster angezeigt. Die Zahlenwerte sind so gewählt, dass die Höhe bei minimalem Regeler-Wert gleich 0 ist.
		t2 = steady_clock::now();
		double duration = duration_cast<microseconds>(t2 - t1).count() / pow(10, 6); //steady_clock zeichnet die Zeit auf. Mit duration_cast kann die Differenz zwischen den Zeiten t1 und t2 auf 6 Nachkommastellen genau angezeigt werden.
		outbox1.set_value(to_string(duration)); //erstes Output-Fenster zeigt Zeit seit Beginn der callback Funktion an.
		if (x[0] > xmax) {
			vx[0] *= -1;
			x[0] = xmax;
		}
		else if (x[0] < xmin) {
			vx[0] *= -1;
			x[0] = xmin;
		}
		vy[0] = stod(inbox2.get_value()) * 0.1 * sin(theta); //beim Aufprall auf den "Boden" soll der Wurf erneut durchgefuehrt werden, wobei die Geschwindigkeit und Höhe zwischen zwei Wuerfen geändert werden kann.
			x[0] = 0;
			y[0] = slider1.get_value() * 0.001 * (h - R - h / 4 - R) + ymin;
			double falltime = duration - showtime; //Die angezeigte Wurfzeit soll bei erneuter Durchfuehrung nicht addiert werden. Deshalb hängt die Wurfzeit von der Runtime der Funktion ab, damit immer nur die Zeit für einen Wurf angezeigt wird.
			outbox2.set_value(to_string(falltime)); 
			showtime += falltime; 
		}
		else if (y[0] < ymin) {
			vy[0] *= -1;
			y[0] = ymin;
		}
		x[0] += vx[0] * dt;
		y[0] += vy[0] * dt;
		circle1.relocate(x[0], y[0]);
		v0 = sqrt(vx[0] * vx[0] + vy[0] * vy[0]);
		vy[0] += 0.0098 * 0.4; //Gravitation verringert y-Koordinate der Geschwindigkeit. Faktor so gewählt, dass die Wurfzeit dem theoretischen Wert nahe kommt.
		Fl::check();
		Fl::redraw();
		
	}
}
