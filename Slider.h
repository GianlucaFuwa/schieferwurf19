#pragma once

struct Slider : Widget { //Regeler-Klasse als Widget-Unterklasse. Der Regeler wird im GUI für die Bestimmung der Höhe des Balls benutzt.
	Fl_Slider* pw; //Fl_Slider wird in der Addresse pw aufgerufen
	Slider(Point p, int w, int h, string s) //Position und Größe des Regelers wird definiert. Regeler bekommt Label zur Identifikation
		: Widget(p, w, h, s, 0) {} 
	void set_value(int v) { pw->value(v); } //Werte des Vektors werden aus pw Addresse entnommen.
	int get_value() { return pw->value(); }
	void set_bounds(int b1, int b2) { pw->bounds(b1, b2); } //Minimaler und maximaler Regelerwert werden in Source File bestimmt
	void attach(Windows& window) {
		pw = new Fl_Slider(xy.x, xy.y, width, height, label.c_str()); //Eigenschaften des Regelers unter Fltk Standards werden definiert
		pw->type(FL_HOR_NICE_SLIDER);
		pw->align(FL_ALIGN_RIGHT);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window; //own als Speicheraddresse der Fenster-Klasse 
	}
};
