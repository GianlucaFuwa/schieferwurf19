#pragma once

struct Out_box : Widget { // Definition der Out_Box als Widget-Unterklasse
	Fl_Text_Display* pw; //  Speicheradresse pw mit Informationen zu Farbe und Form wird definiert.
	Fl_Text_Buffer* buff; //  Speicheradresse des Text-Buffers; in Zukunft können Callback-Funktionen bei Veränderung des Buffers initialisiert werden.
	Out_box(Point p, int w, int h, string s) // Position und Größe der Box sowie 
		: Widget(p, w, h, s, 0) {}
	void set_value(string s) { buff->text(s.c_str()); }
	void attach(Windows& window) {
		pw = new Fl_Text_Display(xy.x, xy.y, width, height, label.c_str());
		buff = new Fl_Text_Buffer();
		pw->buffer(buff);
		pw->align(FL_ALIGN_RIGHT); // Informationen zu Form und Farbe der Box werden zur Konstruktion in der void-Funktion verwendet.
		pw->color(FL_BLACK);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_WHITE);
		pw->textsize(12);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};
