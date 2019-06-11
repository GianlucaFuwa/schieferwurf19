#pragma once

struct Line : Shape {    // Line-Unterklasse wird definiert.
	Line(Point p1, Point p2, int lw, int lc)
	Line(Point p1, Point p2, int lw, int lc)  // Die Linie wird mit Anfangs- und Endpunkt definiert.
		
		add(p1);
		add(p2);
	}
	void draw() {
		fl_line_style(FL_SOLID, line_width);
		fl_color(line_color);
		fl_line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
	}
};
