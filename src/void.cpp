#include <iostream>
#include <iomanip>
#include <string>
#include "command.h"

void print_usage_format()
{
    std::cout << "\nUsage:" << std::endl;
    std::cout << "\tvoid [command]\n"
              << std::endl;

    std::cout << "Available Commands:" << std::endl;
    std::cout << std::left;

    std::cout << std::setw(1) << "\t" << std::setw(10) << "help";
    std::cout << std::setw(30) << "Print usage format along with a list of available commands" << std::endl;

    std::cout << std::setw(1) << "\t" << std::setw(10) << "build";
    std::cout << std::setw(30) << "Builds project files into a dynamic library for execution" << std::endl;

    std::cout << std::setw(1) << "\t" << std::setw(10) << "serve";
    std::cout << std::setw(30) << "Interfaces with the project library and runs a server instance\n"
              << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        print_usage_format();
        return 1;
    }

    // convert command to string
    std::string command = argv[1];

    // help command
    if (command == "help")
    {
        print_usage_format();
        return 0;
    }

    // other commands - [build, serve]
    if (command == "build")
        return Command::build();
    if (command == "serve")
        return Command::serve();

    print_usage_format();
    return 1;
}