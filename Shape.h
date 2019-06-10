#pragma once

struct Shape { //Form-Klasse wird definiert.
	int line_width, line_color, fill_color; //Form enthält einen Rand mit einer bestimmten Farbe und ein inneres mit bestimmter Farbe.
	vector<Point> pts;
	Shape(int lw, int lc, int fc)
		: line_width(lw), line_color(lc), fill_color(fc) {} 
	void add(Point p) { pts.push_back(p); } //Form-Bereich wird festgelegt.
	void move(int dx, int dy) {
		for (unsigned int i=0; i<pts.size(); i++) {
			pts[i].x += dx;
			pts[i].y += dy;
		}
	}
	virtual void draw() {} //virtuelle draw Funktion, damit wir diese bei vererbten Klassen überschreiben können.
};
