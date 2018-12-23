#include <sstream>
#include <iostream>
#include "filet.h"

Filet::Filet(std::istream *istream) {
    Filet::istream = istream;

    read();
}

void Filet::read() {
    std::string line;

    while (!istream->eof() && !istream->fail()) {
        std::getline(*istream, line, '\n');

        std::vector<std::string> row;
        size_t pos = 0;

        while ((pos = line.find(',')) != std::string::npos) {
            row.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }

        row.push_back(line);

        push_back(row);
    }
}

void Filet::write(std::ofstream *ostream) {
    std::string output = "";

    for (vector <std::string> &row: *this) {
        for (std::string &value: row) {
            output += value + ",";
        }

        output = output.substr(0, output.size() - 1);
        output += "\n";
    }

    *ostream << output;
}
