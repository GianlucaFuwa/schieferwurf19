#pragma once

struct In_box : Widget {     //Definition der Widget-Unterklasse In_box.
	Fl_Input* pw;    //Speicheradresse wird benannt.
	In_box(Point p, int w, int h, string s)    //Parameter zur Bestimmung der Größe und Form der Box werden definiert.
		: Widget(p, w, h, s, 0) {}
	void set_value(string s) { pw->value(s.c_str()); } //Die Input_Box erhält einen string der aus Zahlen besteht, um z.B. den Wurfwinkel oder die Geschwindigkeit festzulegen.
	string get_value() { return string(pw->value()); }
	void attach(Windows& window) {
		pw = new Fl_Input(xy.x, xy.y, width, height, label.c_str());
		pw->align(FL_ALIGN_RIGHT); // Eigenschaften wie Farbe der Box etc. werden definiert.
		pw->color(FL_WHITE);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_BLACK);
		pw->textsize(12);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};
