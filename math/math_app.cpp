/*
    math_app.hpp
    created on :29/8/2023
    author     :shrief mahmoud

*/
#include "math_app.hpp"  // Include the header file for your Math Library.

MathLib::MathLib()  // Constructor for the MathLib class.
{
    // Constructor body (empty in this case).
}

double MathLib::add(double num1, double num2)  // Definition of the 'add' method.
{
    return num1 + num2;  // Add 'num1' and 'num2' and return the result.
}

double MathLib::sub(double num1, double num2)  // Definition of the 'sub' method.
{
    return num1 - num2;  // Subtract 'num2' from 'num1' and return the result.
}

double MathLib::multiply(double num1, double num2)  // Definition of the 'multiply' method.
{
    return num1 * num2;  // Multiply 'num1' and 'num2' and return the result.
}

double MathLib::divide(double num1, double num2)  // Definition of the 'divide' method.
{
    return num1 / num2;  // Divide 'num1' by 'num2' and return the result.
}

int main(int argc, char *argv[])  // Entry point of the program.
{
    MathLib mathLib;  // Create an instance of the MathLib class.
    Sender sender;    // Create an instance of the Sender class.
    sender.MsgQueConnect("/math_app");  // Connect to a message queue.

    if (argc == 2 && std::strcmp(argv[1], "--help") == 0)
    {
        // Display usage information when the "--help" argument is provided.
        std::cout << "Usage: " << argv[0] << " <num1> <operator> <num2>\n"
                  << "Perform basic math operations based on the entered arguments.\n"
                  << "Supported operators: +, -, *, /\n";
        return 0;  // Exit the program successfully.
    }

    if (argc != 4)
    {
        // Display an error message if the number of arguments is not equal to 4.
        std::cout << "Usage: " << argv[0] << " <num1> <operator> <num2>\n";
        return 1;  // Exit the program with an error code.
    }

    double num1 = atof(argv[1]);  // Convert the first command-line argument to a double.
    char op = argv[2][0];         // Get the operator character from the second argument.
    double num2 = atof(argv[3]);  // Convert the third command-line argument to a double.
    double result;

    switch (op)
    {
    case '+':
        result = mathLib.add(num1, num2);  // Call the 'add' method and store the result.
        sender.MsgQueSend("[MATH_APP] ADD operation √√√");  // Send a message to the message queue.
        break;
    case '-':
        result = mathLib.sub(num1, num2);  // Call the 'sub' method and store the result.
        sender.MsgQueSend("[MATH_APP] SUB operation √√√");  // Send a message to the message queue.
        break;
    case 'x':
        result = mathLib.multiply(num1, num2);  // Call the 'multiply' method and store the result.
        sender.MsgQueSend("[MATH_APP] MUL operation √√√");  // Send a message to the message queue.
        break;
    case '/':
        if (num2 == 0)
        {
            std::cout << "Error: Division by zero is not allowed.\n";  // Display an error message for division by zero.
            return 1;  // Exit the program with an error code.
        }
        result = mathLib.divide(num1, num2);  // Call the 'divide' method and store the result.
        sender.MsgQueSend("[MATH_APP] add operation √√√");  // Send a message to the message queue.
        break;
    default:
        std::cout << "Error: Invalid operator.\n";  // Display an error message for an invalid operator.
        return 1;  // Exit the program with an error code.
    }

    std::cout << "Result = " << result << "\n";  // Display the calculated result.
    return 0;  // Exit the program successfully.
}

