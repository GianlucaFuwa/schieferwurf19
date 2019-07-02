#include "GUI.h" //Interface mit allen Header-Files einbinden

Windows window(Point(w, 0), w, h, "schieferwurf19 DF"); //Programm-Fenstergröße und Titel wird festgelegt
Line line1(Point(0, h / 4), Point(w, h / 4), 3, FL_WHITE); 
Line line2(Point(w / 2, 0), Point(w / 2, h / 4), 3, FL_WHITE); //senkrechte udn waagerechte Linie zur Abgrenzung der Widgets werden definiert
Text text1(Point(200, 50), FL_HELVETICA, 25, FL_RED, "INPUT"); 
Text text2(Point(w / 2 + 200, 50), FL_HELVETICA, 25, FL_RED, "OUTPUT"); //Linke Seite enthält die Input-Boxen (Geschw., Wurfwinkel), Rechte Seite enthält die Output boxen (Höhe, Zeiten)

In_box inbox2(Point(50, 80), 100, 30, "m/s ;Particle speed."); //Widgets werden definiert
In_box inbox1(Point(50, 120), 100, 30, "° ;Angle in Degrees.");
Slider slider1(Point(w / 2 + 50, 120), 100, 30, "Starting height.");
Out_box outbox1(Point(w / 2 + 50, 80), 100, 30, "Time elapsed (s).");
Out_box outbox2(Point(w / 2 + 300, 80), 100, 30, "Time for throw.");
Out_box outbox3(Point(w / 2 + 300, 120), 100, 30, "m.");

#include "callback1.h" //callback1-Funktion wird eingebunden und auf bei Drücken von Button1 iniziiert
Button button1(Point(200, 200), 100, 30, "RUN", callback1);
#include "callback2.h" ////callback2-Funktion wird eingebunden und auf bei Drücken von Button2 iniziiert
Button button2(Point(w / 2 + 200, 200), 100, 30, "PLOT", callback2); 

int main() {
	window.attach(line1); //Alle Objekte werden in das Fenster eingefügt
	window.attach(line2);
	window.attach(text1);
	window.attach(text2);

	window.attach(inbox2);
	window.attach(slider1);
	window.attach(inbox1);
	window.attach(button1);
	window.attach(outbox1);
	window.attach(outbox2);
	window.attach(outbox3);
	window.attach(button2); 

	slider1.set_value(500); //Slider bekommt Minimal-, Maximal- und Startwert 
	slider1.set_bounds(1000, 0); 
	inbox1.set_value("45"); //Input-Boxen bekommen Startwerte 
	inbox2.set_value("5");
	outbox1.set_value("0");
	outbox2.set_value("0");
	return Fl::run();
}
