#include <CLI/CLI.hpp>
#include <iostream>
#include <iomanip>

int main(const int argc, char **argv) {
    CLI::App app{"Console calculator"};


    double a = 0.0;
    double b = 0.0;
    std::string operation;

    app.add_option("-a,--first", a, "First number")->required();
    app.add_option("-b,--second", b, "Second number")->required();
    app.add_option("-o,--operation", operation, "Operation (+, -, *, /)")
            ->required()
            ->check(CLI::IsMember({"+", "-", "*", "/"}));

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    double result = 0.0;
    bool valid = true;

    if (operation == "+") {
        result = a + b;
    } else if (operation == "-") {
        result = a - b;
    } else if (operation == "*") {
        result = a * b;
    } else if (operation == "/") {
        if (b != 0) {
            result = a / b;
        } else {
            std::cout << "Error: Division by zero!" << std::endl;
            valid = false;
        }
    }

    if (valid) {
        std::cout << std::fixed << std::setprecision(2)
                << a << " " << operation << " " << b
                << " = " << result << std::endl;
    }

    return 0;
}
