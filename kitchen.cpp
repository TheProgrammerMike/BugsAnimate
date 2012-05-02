#include "kitchen.h"
#include <FL/Fl.H>
#include <iostream>
using std::cout;

KitchenFloor::KitchenFloor()
: Fl_Double_Window(640, 480)
{
	color(FL_WHITE);
	for(int i = 0; i < NUM_INSECTS; i++)
	{
		insect[i] = new Insect(this);
		insect[i]->end(); // MUST not add subsequent widgets
	}
	end();
}

int KitchenFloor::handle(int event)
{
	switch(event)
	{
	case FL_ENTER:
		cout << "Enter!\n";
		return 1;
	case FL_MOVE:
		for(int i = 0; i < NUM_INSECTS; i++)
		{
			insect[i]->respondToMouse(Fl::event_x(),
				Fl::event_y());
		}
		return 1;
	}
	return 0;
}
