#include <iostream>
#include <memory>
#include <fstream>
#include <map>

int main()
{
    char data_buffer[256];
    std::ifstream infile_handler;
    infile_handler.open("./want_change_text.txt");
    if (!infile_handler.is_open()) std::cout << "Error opening file!" << std::endl;
    
    infile_handler.close();
    return 0;
}