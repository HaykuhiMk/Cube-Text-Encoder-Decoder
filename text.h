#ifndef TEXT_H
#define TEXT_H
#include "cube.h"

class Text
{
public:
    void addCube(const std::string&);
    void readFile(const std::string&);
    void print() const;
    void decode(const std::string&);
    std::vector<std::string> splitString(const std::string&, char);

private:
    std::string mKey;
    std::vector<Cube*> mCubes;
};

#endif  //TEXT_H