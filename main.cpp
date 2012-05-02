#include <FL/Fl.H>
#include <FL/Fl_Shared_Image.H>
#include <cstdlib>
#include <ctime>
#include "kitchen.h"

int main() {
	srand(time(NULL)); // initialize random
    fl_register_images();
	Fl_Window* win = new KitchenFloor();
	win->show();
    return(Fl::run());
}
