#include <iostream>
#include "cube.h"

Cube::Cube(const std::string& data)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mData[i][j] = data[i * 4 + j];
        }
    }
}

void Cube::toRight()
{
    toLeft();
    toLeft();
    toLeft();
}

void Cube::toLeft()
{
    for (int i = 0; i < 2; ++i) 
    {
        char tmp = mData[i][3];  
        for (int j = 3; j > 0; --j) 
        {
            mData[i][j] = mData[i][j - 1];  
        }
        mData[i][0] = tmp;  
    }
}

void Cube::toUp()
{
    char tmp[4];
    for (int j = 0; j < 4; ++j)
    {
        tmp[j] = mData[0][j];
        mData[0][j] = mData[1][j];
        mData[1][j] = tmp[j];
    }
}

void Cube::toDown()
{
    toUp();
    for (int i = 0; i < 1; ++i) 
    {
        for (int j = 0; j < 4; ++j) 
        {
            char tmp = mData[i][j];
            mData[i][j] = mData[1 - i][3 - j];
            mData[1 - i][3 - j] = tmp;
        }
    }
}

void Cube::setData(const std::string& data)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mData[i][j] = data[i * 4 + j];
        }
    }
}

std::string Cube::getData() const
{
    std::string data;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            data += mData[i][j];
        }
    }
    return data;
}