#include <iostream>
#include "PNG_reader.h"
#include "Window.h"

double sigmoid(double x)
{
	return (1 / (1 + pow(2.71828, -x)));
}

int main()
{
	PNG_reader image("examples/1.png");

	PNG_reader image_copy = image;
	image_copy.make_larger(33);

	int weight[26 * 26];
	
	int x[26 * 26];
	for (int i = 0; i < 26 * 26; i++)
	{
		x[i] = image.image_data[i];
	}

	for (int y = 0; y < 26; y++)
	{
		for (int x1 = 0; x1 < 26; x1++)
		{
			if (x[y * 26 + x1] > 0)
			{
				std::cout << "1";
				continue;
			}
			std::cout << "0";
		}
		std::cout << '\n';
	}

	Window win(image_copy);
	while (win.isRunning());

	return 0;
}