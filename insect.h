#ifndef INSECT_H
#define INSECT_H
#include <FL/Fl_Group.h>
#include <FL/Fl_PNG_Image.h>

class KitchenFloor;

class Insect : public Fl_Group
{
private:
	static Fl_PNG_Image* png;
	KitchenFloor* floor;
public:
	Insect(KitchenFloor* f);
	void respondToMouse(int x, int y);
};
#endif
