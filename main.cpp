#include <iostream>
#include <fstream>
#include "filet.h"

int main() {
    std::ifstream in("test.csv");

    if (!in) std::cout << "Failed to load file." << std::endl;

    Filet filet = Filet(&in);

    in.close();

    std::ofstream out("test2.csv");

    filet.write(&out);
    out.close();
    return 0;
}