#pragma once

struct Windows : Fl_Double_Window {
	Windows(Point topleft, int width, int height, string title) //Eigenschaften des Fensters werden in Source-File festgelegt
		: Fl_Double_Window(topleft.x, topleft.y, width, height, title.c_str()) {
		color(FL_BLACK); //Farbe des Hintergrunds 
		show();
	}
	vector<Shape*> shapes;
	void attach(Shape& s) { shapes.push_back(&s); } //shapes können in ein Fenster eingefügt werden
	void attach(Widget& w) {
		begin();
		w.attach(*this);
		end();
	}
	void draw() { //Fenster wird mit gegebenen Eigenschaften konstruiert
		Fl_Double_Window::draw(); 
		for (unsigned int i=0; i<shapes.size(); i++) 
			shapes[i]->draw();
		
	}

};
