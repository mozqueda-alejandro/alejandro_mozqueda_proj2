#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

uint32_t get_uint32(std::string s);
std::string get_hex(uint32_t i);

int main() {
    std::vector<std::string> data;
    std::vector<std::vector<std::string>> tokens;
    std::string fileName = "Programming-Project-1.txt", opcode, operand1, operand2;
    
    std::ifstream inFile(fileName);
    if (inFile.is_open())
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            std::istringstream iss(line);
            iss >> opcode >> std::hex >> operand1 >> std::hex >> operand2;
            data.push_back(opcode + " " + operand1 + " " + operand2);
            std::vector<std::string> tempVec = {opcode, operand1, operand2};
            tokens.push_back(tempVec);
        }
    } else {
        throw std::runtime_error("File does not exist.");
    }
    inFile.close();

    for (auto i : data)
    {
        std::cout << i << std::endl;
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        std::string opcode = tokens[i][0];
        uint32_t operand1 = get_uint32(tokens[i][1]);
        uint32_t operand2 = get_uint32(tokens[i][2]);
        unsigned int result = 0;
        if (opcode == "ADD") {
            result = operand1 + operand2;
        } else if (opcode == "AND") {
            result = operand1 & operand2;
        } else if (opcode == "ASR") {
            result = ((int32_t) operand1) >> ((int32_t) operand2);
        } else if (opcode == "LSR") {
            result = operand1 >> operand2;
        } else if (opcode == "LSL") {
            result = operand1 << operand2;
        } else if (opcode == "NOT") {
            result = ~operand1;
        } else if (opcode == "ORR") {
            result = operand1 | operand2;
        } else if (opcode == "SUB") {
            result = operand1 - operand2;
        } else if (opcode == "XOR") {
            result = operand1 ^ operand2;
        } else {
            throw std::runtime_error("Invalid opcode.");
        }
        std::cout << get_hex(result) << std::endl;
        
    }
    return 0;
}

uint32_t get_uint32(std::string num)
{
    uint32_t result;
    std::stringstream ss;
    ss << std::hex << num;
    ss >> result;
    return result;
}

std::string get_hex(uint32_t num)
{
    std::stringstream ss;
    ss << std::hex << num;
    return "0x" + ss.str();
}

