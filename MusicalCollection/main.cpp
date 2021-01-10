#include <iostream>
#include <string>
#include "ConsoleHandler.h"

//Message for helping the user with the options
void message()
{
	std::cout << "Please type one of the following commands: " << std::endl;
	std::cout << "[Sign in] - For users who already have registration." << std::endl;
	std::cout << "[Sign up] - For users who don't have accounts." << std::endl;
	std::cout << "[Exit]    - Exit the program." << std::endl;
}

//Starting the application with message and Sign up/Sign in option
void startTheApplication(std::string& choice, std::string& user, std::string& pass)
{
	std::cout << "\t\t#          Welcome to Musical Collection!          #\t" << std::endl;
	std::cout << "\t\tHere you can enjoy the music you love listening to!!\t\t\r\n" << std::endl;
	std::cout << "========== M  u  s  i  c  a  l ~~~~~~~~ C  o  l  l  e  c  t  i  o  n ===========\n" << std::endl;
	//std::cout << "[Sign in] Please enter your username and password." << std::endl;
	//std::cout << "[Sign up] You don't have an account? You can register now.";

	ConsoleHandler console;
	bool flag = false, exit = false;
	message();

	while (true)
	{
		std::getline(std::cin, choice);

		if (choice == "Sign up")
		{
			console.processCommand(choice, user, pass, flag, exit);
		}
		else if (choice == "Sign in")
		{
			std::getline(std::cin, user);
			std::getline(std::cin, pass);

			console.processCommand(choice, user, pass, flag, exit);
			if (exit)
			{
				std::cout << "Exiting the program...";
				return;
			}
		}
		else if (choice == "Exit" || choice == "")
		{
			//console.processCommand(choice, user, pass, flag);
			std::cout << "Exiting the program...";
			return;
		}
	}
}

int main()
{
	std::string choice;
	std::string user;
	std::string pass;

	startTheApplication(choice, user, pass);

	return 0;
}