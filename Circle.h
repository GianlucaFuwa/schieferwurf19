#pragma once

struct Circle : Shape { //Definition Kreis-Klasse, für geworfenes Objekt; ist eine Form-Unterklasse
	int radius;
	Circle(Point p, int r, int lw, int lc, int fc)  
		: radius(r), Shape(lw, lc, fc) {
		add(p);
		move(-radius, -radius); //Man gibt Mittelpunkt und Radius an, um Kreis zu erhalten
	}
	void relocate(int xnew, int ynew) { //relocate-Funktion, um die Position des Kreises während des Wurfs zu verändern
		pts[0].x = xnew - radius;
		pts[0].y = ynew - radius;
	}
	void draw() {
		fl_line_style(FL_SOLID, line_width);
		fl_color(fill_color);
		fl_pie(pts[0].x, pts[0].y, 2 * radius - 1,2 * radius - 1, 0, 360);
		fl_color(line_color);
		fl_arc(pts[0].x, pts[0].y, 2 * radius, 2 * radius,  0, 360); //Rand kann eine andere Farbe bekommen als innere Fläche
	}
};
