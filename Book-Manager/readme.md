# CO2 Emission Calculator

## About the Project

This is a C++ project that estimates CO2 emissions from travelling by car, bus or train. I created it to practise my programming skills and learn how to use C++ to solve a practical problem.

## Features

- Enter a travel distance in kilometres or miles.
- Convert miles into kilometres automatically.
- Choose between a car, bus or train.
- If a car is selected, choose petrol, diesel or electric.
- Calculate and display the estimated CO2 emissions in kilograms.
- Check user input and ask again when an invalid value is entered.

## How It Works

The program first asks for the travel distance and its unit. It then asks the user to select a transport type. For cars, the user also selects the fuel type. The program multiplies the distance in kilometres by an emission factor and displays the estimated result.

The code is organised into separate functions for entering the distance, selecting transport, getting the emission factor, calculating emissions and displaying the result.

## Requirements

- A C++ compiler that supports C++11 or later.
- A terminal or code editor, such as Visual Studio Code.

## How to Compile and Run

Open a terminal in the folder containing the source file.

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic CalculatorCO2.cpp -o CalculatorCO2
```

Run the application:

```bash
./CalculatorCO2
```

## Project Files

- `CalculatorCO2.cpp` – Contains the source code and functions used by the calculator.
- `readme.md` – Contains the project documentation and instructions.

## Notes

The emission factors currently used in this educational project are illustrative values. They should be checked against reliable sources before the calculator is used to make accurate real-world estimates.

## What I Learned

While working on this project, I practised using C++ functions, variables, loops, conditional statements, mathematical calculations and input validation. I also learned how to organise code into smaller parts and test the program with different inputs.