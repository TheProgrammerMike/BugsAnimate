#include <FL/Fl_Double_Window.h>
#include "insect.h"

const int NUM_INSECTS = 5;

class KitchenFloor : public Fl_Double_Window
{
private:
	Insect* insect[NUM_INSECTS];
public:
	KitchenFloor();
	int handle(int event);
};
