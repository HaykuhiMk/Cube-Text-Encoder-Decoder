#ifndef CUBE_H
#define CUBE_H
#include <vector>
#include <string>

class Cube
{
public:
    Cube() = default;
    Cube(const std::string&);
    void toLeft();
    void toRight();
    void toDown();
    void toUp();
    void setData(const std::string&);
    std::string getData() const;

private:
    char mData[2][4];
};

#endif  //CUBE_H