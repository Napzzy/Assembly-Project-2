#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <sstream>
using VectorChar = std::vector<char>;

void read_files(VectorChar &Variable, VectorChar &CharCommand, VectorChar &Value);
void write_files(VectorChar &Variable, VectorChar &CharCommand, VectorChar &Value);

int main()
{
    VectorChar InputCommand;  // Commands are not fixed size
    VectorChar InPutVariable; // F
    VectorChar Value;

    read_files(InputCommand, InPutVariable, Value);
    write_files(InputCommand, InPutVariable, Value);

    return 0;
}

void read_files(VectorChar &CharCommand, VectorChar &CharVariable, VectorChar &Value)
{
    std::ifstream inputFile("spasp.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Error opening the file! \n";
        exit(2);
    }

    std::string store;

    while (std::getline(inputFile, store))
    {
        std::istringstream values(store);
        char Command;
        char Variable;
        char number;

        if (values >> Command >> Variable) // Come back
        {
            CharCommand.push_back(Command);
            CharVariable.push_back(Variable);

            if (Command == 'D')
            {
                if (values >> number)
                    Value.push_back(number);
            }
        }
    }

    inputFile.close();
}

void write_files(VectorChar &Variable, VectorChar &CharCommand, VectorChar &Value)
{
    std::ofstream dataFile("data.txt");
    std::ofstream codeFile("code.txt");

    if (!dataFile.is_open() || !codeFile.is_open()) 
    {
        std::cout << "error opening file! ";
        exit(3);
    }

    for (int i = 0; i < Value.size(); i++)
    {
        dataFile << i << " " << Value[i] << std::endl;
    }

    std::cout << "closed";

    dataFile.close();
    codeFile.close();
}