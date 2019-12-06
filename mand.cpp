#include <iostream>

extern "C"
{

#include "gfx.h"
}


int main() 
{

	gfx_open(100, 100, "apollo"); 	
	
	for (int x = 0; x < 1000; x++) 
	{

		for (int y = 0; y < 1000; y++) 

		{
			float zoom = 0.0035;

			float a = 0;		
			a = ((x - 500) * zoom);

			float b = 0;
			b = ((y - 500) * zoom);

			float A = a;
			float B = b;
			int n = 0;

			while (n < 1000) 
			{
				float ab = (a * a) - (b * b);
				float bb = (2 * a * b);
				a = ab + A; 
				b = bb + B;
				if (((a * a) +( b * b)) > 4.0)
				{	
					break;
				}
				n++;

			}
			double we = n  * n * n % 245;
			double pe = n % 245;
			double le = n % 245;

			gfx_color(we, pe, le);
			gfx_point(x,y);
		}
	}

	std::cout << "F to cancel" << std::endl;

	while (true)
	{
		if(gfx_event_waiting())
		{
			int button = gfx_wait();
			if(button == 'f')
			{
				break;
			}
		}
	}
	return 0;
}
