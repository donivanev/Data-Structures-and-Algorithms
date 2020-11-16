#include <iostream>
#include <string>
#include "ConsoleHandler.h"

//Message for helping the user with the options
void message()
{
	std::cout << "Please type one of the following commands: " << std::endl;
	std::cout << "[Sign in] - For users who already have registration." << std::endl;
	std::cout << "[Sign up] - For users who don't have accounts." << std::endl;
}

//Starting the application with message and Sign up/Sign in option
void startTheApplication(std::string& choice, std::string& user, std::string& pass)
{
	std::cout << "\t\t#\tWelcome to Musical Collection!\t\t#\t" << std::endl;
	std::cout << "\t\tHere you can enjoy the music you love listen to!!\t\t\r\n" << std::endl;
	//std::cout << "[Sign in] Please enter your username and password." << std::endl;
	//std::cout << "[Sign up] You don't have an account? You can register now.";

	message();
	std::getline(std::cin, choice);

	while (choice != "Sign in" && choice != "Sign up")
	{
		std::cout << "Wrong command!" << std::endl;
		message();
		std::getline(std::cin, choice);
	}

	if (choice == "Sign in")
	{
		std::getline(std::cin, user);
		std::getline(std::cin, pass);
	}
}

int main()
{
	ConsoleHandler console;
	std::string choice;
	std::string user;
	std::string pass;

	startTheApplication(choice, user, pass);

	console.processCommand(choice, user, pass);

	return 0;
}