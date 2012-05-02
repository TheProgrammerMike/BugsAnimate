#include "insect.h"
#include "kitchen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using std::cout;

const char* image_filename = "bug-icon.png";

Fl_PNG_Image* Insect::png = 0;

Insect::Insect(KitchenFloor* f)
: Fl_Group(0, 0, 50, 50)
{
	floor = f;
	Fl_PNG_Image* png = new Fl_PNG_Image(image_filename);
	if(png->w() == 0)
	{
		perror(image_filename);
		abort();
	}
	cout << "Image is " << png->w() << "x" << png->h() << "\n";
	size(png->w(), png->h());
	align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
	image(png);
	// choose random location
	int x = rand() % floor->w();
	int y = rand() % floor->h();
	cout << "Moving to " << x << ", " << y << "\n";
	position(x, y);
	redraw();
}

void Insect::respondToMouse(int mx, int my)
{
	const double THREAT_MARGIN = 70.0;
	double cx = x() + w()/2.0;  // center of icon
	double cy = y() + h()/2.0;
	double dx = mx - cx;
	double dy = my - cy;
	double distance = sqrt(dx*dx + dy*dy); // Pythagorean
	cout << "distance(" << this << ") is " << distance << "\n";
	if( distance < THREAT_MARGIN )
	{
		if(mx<cx)
		{
			double danger = (THREAT_MARGIN - distance) / THREAT_MARGIN;
			cout << " --> moving danger " << danger << "\n";
			double ncx = danger * (cx + dx); // new center
		//	double ncy = danger * (cy - dy);
			int nx = (int)(ncx + w()/2.0)+x();
		//	int ny = (int)(ncy - h()/2.0)+y();
//			cout<<"NX,NY="<<nx<<" " <<ny;
			position(nx, y());
			floor->redraw();
				
		}

		if(mx>cx)
		{
			double danger = (THREAT_MARGIN - distance) / THREAT_MARGIN;
			cout << " --> moving danger " << danger << "\n";
			double ncx = danger * (cx - dx); // new center
		//	double ncy = danger * (cy - dy);
			int nx = (int)(ncx - w()/2.0)+x();
		//	int ny = (int)(ncy - h()/2.0)+y();
//			cout<<"NX,NY="<<nx<<" " <<ny;
			position(nx, y());
			floor->redraw();
				
		}
		if(my<cy)
		{
			double danger = (THREAT_MARGIN - distance) / THREAT_MARGIN;
			cout << " --> moving danger " << danger << "\n";
		//	double ncx = danger * (cx + dx); // new center
			double ncy = danger * (cy + dy);
		//	int nx = (int)(ncx + w()/2.0)+x();
			int ny = (int)(ncy + h()/2.0)+y();
//			cout<<"NX,NY="<<nx<<" " <<ny;
			position(x(), ny);
			floor->redraw();
				
		}

		if(my>cy)
		{
			double danger = (THREAT_MARGIN - distance) / THREAT_MARGIN;
			cout << " --> moving danger " << danger << "\n";
		//	double ncx = danger * (cx - dx); // new center
			double ncy = danger * (cy - dy);
		//	int nx = (int)(ncx - w()/2.0)+x();
			int ny = (int)(ncy - h()/2.0)+y();
//			cout<<"NX,NY="<<nx<<" " <<ny;
			position(x(), ny);
			floor->redraw();
				
		}

		if(x()<=0)
		{
			int myX=x()+100;
				
			position(myX,y());
			floor->redraw();
		
		}

		if(x()>=300)
		{
			int myX=x()-100;
			position(myX,y());
			floor->redraw();
		}
		if(y()<=0)
		{
			int myY=y()+100;
				
			position(x(),myY);
			floor->redraw();
		
		}

		if(y()>=250)
		{
			int myY=y()-150;
			position(x(),myY);
			floor->redraw();
		}

		floor->redraw();

		/*
	
		*/
	}
}
