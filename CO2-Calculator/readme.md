# CO2 Emission Calculator

## About My Project

For this project, I created a CO2 Emission Calculator using C++. I wanted to make a simple program that could estimate how much CO2 is produced when travelling by different types of transport.

I chose this idea because it allowed me to practise calculations, functions and user input while working on a practical example.

## What My Program Can Do

- Ask the user to enter a travel distance.
- Accept distances in kilometres or miles.
- Convert miles into kilometres.
- Let the user choose between car, bus and train.
- Allow petrol, diesel or electric options for cars.
- Calculate estimated CO2 emissions.
- Display the result in kilograms.
- Check incorrect input and ask the user to try again.

## How I Made It Work

I divided the program into separate functions to make the code easier to understand.

The program first asks for the distance and the measurement unit.

If the user selects miles, the program converts the distance into kilometres.

After that, the user chooses the transport type. If they select a car, the program also asks for the fuel type.

Each transport option has an emission factor that the program uses for the calculation.

The formula is:

CO2 emissions = Distance in kilometres × Emission factor

For example, if the user enters 100 kilometres and selects a petrol car, the program calculates:

100 × 0.192 = 19.20 kg CO2

## Emission Factors Used

| Transport | kg CO2/km |
|---|---|
| Petrol car | 0.192 |
| Diesel car | 0.171 |
| Electric car | 0.053 |
| Bus | 0.105 |
| Train | 0.035 |

These are example values used for my programming project. They are not intended to provide exact real-world emission measurements.

## How to Run My Program

I used Visual Studio Code and the terminal to compile and test my application.

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic CalculatorCO2.cpp -o CalculatorCO2
```

Run:

```bash
./CalculatorCO2
```

## Project Files

- `CalculatorCO2.cpp`: My C++ calculator.
- `readme.md`: Information about my project.

## Testing

I compiled and ran the calculator in the terminal.

I checked that I could enter a distance, select a transport method and receive a calculated result.

I also checked how the program responded to invalid input.

## What I Learned

This project helped me practise using functions, variables, loops and conditional statements.

I also improved my understanding of mathematical calculations in C++ and how to check user input.

I learned that dividing a program into smaller functions makes the code easier to read, test and change.

Working on this calculator helped me understand how C++ can be used to solve a practical problem.
