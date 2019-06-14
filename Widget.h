#pragma once

struct Widget { // Definition der Widget-Klasse
	int width, height;  //Parameter zur Bestimmung der Position, Größe und Höhe des Widgets
	string label;
	Point xy;
	Callback do_it;  // führt beim "Drücken" eine Callback-Funktion aus
	Windows* own;
	Widget(Point p, int w, int h, string s, Callback cb)
		: xy(p), width(w), height(h), label(s), do_it(cb){}
	virtual void attach(Windows&) {}
};
