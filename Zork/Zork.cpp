// Zork.cpp: define el punto de entrada de la aplicación de consola.
//



#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "world.h"


bool QUIT = false;
void processCommand(std::string command) 
{
	
}
int main()
{	
	world* whole = new world();
	std::string command_input;
	char key;
	std::cout << "Welcome to MyZork!\n";

	while (true) 
	{
		if (QUIT) 
		{
			break;
		}
		if (_kbhit()!= 0)
		{
			key = _getch();

			if (key == '\b') // Delete char in command window
			{
				if (command_input.length() > 0)
				{
					command_input.pop_back();
					std::cout << '\b';
					std::cout << " ";
					std::cout << '\b';
				}

				
			}else if ((key == '\r')) // Get enter Key
			{
				std::cout << key; // Jump line

				if (command_input.compare("quit") == 0) // Exit condition
				{
					while ((key != 'y') && (key != 'Y') && (key != 'n') && (key != 'N'))
					{
						std::cout << "Are you sure you want to quit? (Y/N)\n";
						std::cin >> key;
						std::cout << "Key value:" << key << "\n";
						if ((key == 'Y') || (key == 'y'))
						{
							QUIT = true;
						}
						else if ((key == 'N') || (key == 'n'))
						{
							command_input.clear();
							std::cout << '\r';
						}
						else
						{
							std::cout << "Sorry, I did not get your answer\n";
						}
					}
				}
				else 
				{
					std::cout << command_input;

					processCommand(command_input);

					command_input.clear();
				}
			}else 
			{

				command_input += key;
				std::cout << key;
			}

		}
	}
    return 0;
}

