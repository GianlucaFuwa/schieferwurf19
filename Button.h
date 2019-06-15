#pragma once

struct  Button : Widget { //Knopf-Klasse als Widget-Unterklasse
	Fl_Button* pw; //Speicheradresse wird benannt
	Button(Point p, int w, int h, string s, Callback cb) //Knopf erhält Position, Größe, ein Label und eine Funktion
		: Widget(p, w, h, s, cb) {}
	void attach(Windows& window) {
		pw = new Fl_Button(xy.x, xy.y, width, height, label.c_str()); //Die Proportionen werden zur selben Adresse geschickt
		pw->callback(do_it); //Nach dem Drücken des Knopfes wird die callback-Funktion ausgeführt
		pw->color(FL_DARK_BLUE);
		pw->labelfont(FL_COURIER_BOLD_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};
