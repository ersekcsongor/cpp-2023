#include <iostream>
#include "SimpleTextGenerator.h"
int main() {
    std::cout << "Hello, Lab_13" << std::endl;
    string text = "Now is not the time for sleep, now is the time for party!";
    SimpleTextGenerator generator;
    generator.trainFromText(text);
    generator.printData();
    for (int i = 0; i < 3; ++i) {
        cout << "Generated text: " << generator.generate("now is", 10) << endl;
    }
    return 0;
}