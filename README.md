# filet
yet another csv file parser written for a school assignment.

*(not to be mistaken for a boneless piece of meat)*

## how 2 use
```cpp
std::ifstream in("example.csv");
Filet filet = Filet(&in);

std::cout << filet[0][0] << std::endl; // prints the value of the first row and first column!
filet[0][0] = "fish!" // sets the value of the first row and first column.
filet.push_back({"woo", "a", "new", "row!"});

// do a loop de loop de loop
for (std::vector<std::string> &row: filet) {
    std::cout << row[0] << std::endl;
}

std::ofstream out("new.csv");
filet.write(&out);
```
```cpp
std::ifstream in("example.csv");
Filet filet = Filet(&in, ","); // custom delimiters!!

std::ofstream out("newDeliminatorer.csv");
filet.write(&out, ";"); // revolutionary innovation!1
```
