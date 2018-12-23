#ifndef FILET_FILET_H
#define FILET_FILET_H

#include <fstream>
#include <vector>

class Filet : public std::vector<std::vector<std::string>> {
    std::istream *istream;
public:
    Filet(std::istream *istream);

    void read();

    void write(std::ofstream *ostream);
};

#endif //FILET_FILET_H
