#include<SDL.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#define SCREEN_WEIGHT	1024
#define SCREEN_HEIGHT	800

using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL error:" << SDL_GetError() << endl;
	}
	else
	{
		SDL_Window* window = NULL;

		window = SDL_CreateWindow(u8"Never be among", 200, 100, SCREEN_WEIGHT, SCREEN_HEIGHT, 0);
		if (window == NULL)
		{
			cout << "SDL error:" << SDL_GetError() << endl;
		}
		else
		{
			SDL_Renderer* renderers = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderers, 255, 255, 255, 0);
			SDL_RenderClear(renderers);

			double a, b, c ;
			do
			{
				cout << "Введите радиус кругов " << endl;
				cout << "Введите радиус 1 круга" << endl;
				cin >> a;
				cout << "Введите радиус 2 круга" << endl;
				cin >> b;
				cout << "Введитерудиус 3 круга" << endl;
				cin >> c;
			} while (a == 0 || b == 0);
			//Введите скорости движения окружности

			SDL_SetRenderDrawColor(renderers, 120, 80, 7, 0);


			double angle = 0;
			double x, y;
			
			//Эллипс
			for (double angle = 0; angle < 720; angle += 1)
			{
				for (int angle3 = 0; angle3 < 360; angle3 += 1)
				{
					x = 30 * a * cos(angle3) + SCREEN_WEIGHT / 2;
					y = 30* b * sin(angle3) + SCREEN_HEIGHT / 2;
					SDL_RenderDrawPoint(renderers, x, y);
				}
				for (int angle1 = 0; angle1 < 360; angle1 += 1)
				{
					x = 20 * a * cos(angle1) + SCREEN_WEIGHT / 2 + 30 * a * cos(angle - 20);
					y = 20 * a * sin(angle1) + SCREEN_HEIGHT / 2 + 30 * b * sin(angle - 20);
					SDL_RenderDrawPoint(renderers, x, y);
				}
				for (int angle2 = 0; angle2 < 360; angle2 += 1)
				{
					x = 10 * b * cos(angle2) + SCREEN_WEIGHT / 2 + 30 * a * cos(angle + 40);
					y = 10 * b * sin(angle2) + SCREEN_HEIGHT / 2 + 30 * b * sin(angle + 40);
					SDL_RenderDrawPoint(renderers, x, y);

					for (int angle3 = 0; angle3 < 360; angle3 += 1)
					{
						x = 30 * a * cos(angle3) + SCREEN_WEIGHT / 2 + 30 * a * cos(angle + 70);
						y = 30 * a * sin(angle3) + SCREEN_HEIGHT / 2 + 30 * b * sin(angle + 70);
						SDL_RenderDrawPoint(renderers, x, y);
					}
				}

				SDL_RenderPresent(renderers);
				SDL_Delay(120);
				SDL_SetRenderDrawColor(renderers, 255, 255, 255, 0);
				SDL_RenderClear(renderers);
				SDL_SetRenderDrawColor(renderers, 120, 80, 7, 0);

			}
			SDL_RenderPresent(renderers);

			SDL_Delay(5000);
			SDL_DestroyRenderer(renderers);
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	return 0;
}
