// Zork.cpp: define el punto de entrada de la aplicación de consola.
//



#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "world.h"

world* whole;

std::list<entity*>::iterator it;
bool QUIT = false;
void processCommand(std::string command) 
{
	if (command.compare("test") == 0)
	{
		it = whole->contains.begin();
		std::cout << "\n";
		std::cout << (*it)->description << "\n";
		++it;
		std::cout << (*it)->description << "\n";
		++it;
		std::cout << (*it)->description << "\n";
	}
	if (command.compare("look") == 0) {
		whole->playerLook();
		//character->containedIn->look();
		//character->containedIn->
	}
}
int main()
{	
	whole = new world();
	std::string command_input;
	char key;
	std::cout << "Welcome to Zork!\n";
	std::cout << "You are a poor farmer working all day long just to be able to put some food on the table. \n";
	std::cout << "One day, as you are returning from the fields you work in someone aproaches you from behind.\n";
	std::cout << "Before you can react you feel a strong hit in the back of your head.\n";
	std::cout << "Just as you fall unconscious you can barely see a big man that grabs you and starts carring you... somewhere. \n";
	std::cout << "After some time you start regaining consciousness... \n";
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

