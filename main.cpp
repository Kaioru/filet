#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "filet.h"

void writeToFile1() {
    Filet filet = Filet();

    filet.push_back({"iPhone_7", "10", "1088.00"});
    filet.push_back({"Galaxy_S7", "10", "999.00"});
    filet.push_back({"Xperia_Z", "10", "899.00"});
    filet.push_back({"Redmi_3S", "10", "299.00"});

    std::ofstream out("product1.csv");
    filet.write(&out);
}

void readFromFile1() {
    std::ifstream in("product1.csv");
    if (!in) std::cout << "Failed to load file" << std::endl;
    Filet filet = Filet(&in);

    std::cout << "Name" << "\t\t\t"
              << "Qty" << "\t"
              << "Price" << "\t"
              << "Amount"
              << std::endl;
    for (std::vector<std::string> &row: filet) {
        std::cout << row[0] << "\t\t"
                  << row[1] << "\t"
                  << row[2] << "\t"
                  << std::setprecision(2)
                  << std::fixed
                  << std::stod(row[1]) * std::stod(row[2])
                  << std::endl;
    }
}

void readWriteFile1() {
    std::ifstream in("product1.csv");
    if (!in) std::cout << "Failed to load file" << std::endl;
    Filet filet = Filet(&in);

    for (std::vector<std::string> &row: filet) {
        std::ostringstream strs;
        strs << std::setprecision(2)
             << std::fixed
             << std::stod(row[1]) * std::stod(row[2]);
        std::string str = strs.str();
        row.push_back(str);
    }

    std::ofstream out("transaction1.csv");
    filet.write(&out);
}

void writeToFile2() {
    Filet filet = Filet();

    filet.push_back({"iPhone_7", "10", "1088.00"});
    filet.push_back({"Galaxy_S7", "10", "999.00"});
    filet.push_back({"Xperia_Z", "10", "899.00"});
    filet.push_back({"Redmi_3S", "10", "299.00"});

    std::ofstream out("product2.csv");
    filet.write(&out, ";");
}

void readWriteFile2() {

    std::ifstream in("product2.csv");
    if (!in) std::cout << "Failed to load file" << std::endl;
    Filet filet = Filet(&in, ";");

    for (std::vector<std::string> &row: filet) {
        std::ostringstream strs;
        strs << std::setprecision(2)
             << std::fixed
             << std::stod(row[1]) * std::stod(row[2]);
        std::string str = strs.str();
        row.push_back(str);
    }

    std::ofstream out("transaction2.csv");
    filet.write(&out, ";");
}

int main() {
    writeToFile1();
    readFromFile1();
    readWriteFile1();
    writeToFile2();
    readWriteFile2();
    return 0;
}