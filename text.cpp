#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "text.h"

void Text::addCube(const std::string& data)
{
    Cube* tmp = new Cube(data);
    mCubes.push_back(tmp);
}

void Text::readFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }
    std::string line;
    bool firstFlag = true;  
    while (std::getline(file, line))
    {
        if (firstFlag)
        {
            mKey = line;
            firstFlag = false;
        }
        else
        {
            std::replace(line.begin(), line.end(), ' ', '*');
            const int maxSize = 8;
            const char fillSym = '#';
            while (line.length() % maxSize != 0)
            {
                line += fillSym;
            }
            for (size_t i = 0; i < line.length(); i += maxSize)
            {
                std::string tmp = line.substr(i, maxSize);
                std::replace(tmp.begin(), tmp.end(), ' ', '*');
                this->addCube(tmp);
            }
        }  
    }

    file.close();
}

void Text::print() const
{
    for (const Cube* cube : mCubes)
    {
        std::cout << "Cube data: " << cube->getData() << std::endl;
    }
}

std::vector<std::string> Text::splitString(const std::string& str, char del)
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, del))
    {
        token.erase(std::remove(token.begin(), token.end(), ' '), token.end());
        tokens.push_back(token);
    }
    return tokens;
}


void Text::decode(const std::string& fileName)
{
    this->readFile(fileName);
    print();
    std::vector<std::string> key = splitString(mKey, ':'); 
    for (int i = 0; i < key.size(); ++i)
    {
        std::vector<std::string> result = splitString(key[i], ','); 
        int cubeIndex = i % mCubes.size();
        for (int j = 0; j < result.size(); ++j)
        {
            char direction = result[j][0];
            std::string numberStr = result[j].substr(1);
            int count = std::stoi(numberStr);
            for (int k = 0; k < count; ++k)
            {
                switch (direction)
                {
                    case 'L':
                        mCubes[cubeIndex]->toLeft();
                        break;
                    case 'R':
                        mCubes[cubeIndex]->toRight();
                        break;
                    case 'D':
                        mCubes[cubeIndex]->toDown();
                        break;
                    case 'U':
                        mCubes[cubeIndex]->toUp();
                        break;
                    default:
                        std::cerr << "Invalid direction: " << direction << std::endl;
                        break;
                }
            }
        }
    }
}