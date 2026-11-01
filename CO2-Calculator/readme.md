# CO2 Emission Calculator

## About the Project

This is a C++ console application that estimates carbon dioxide (CO2) emissions from travelling by car, bus or train. I developed this project to practise my programming skills and apply C++ concepts to a practical environmental calculation.

## Features

- Enter a travel distance in kilometres or miles.
- Automatically convert miles into kilometres.
- Choose between three transport methods: car, bus or train.
- Select petrol, diesel or electric when choosing a car.
- Calculate estimated CO2 emissions in kilograms.
- Validate user input and request valid values when necessary.
- Display the calculated result with two decimal places.

## How It Works

The program asks the user to enter a travel distance and select the measurement unit.

If the distance is entered in miles, the program converts it into kilometres using a conversion factor of 1.60934.

The user then selects a transport method. When choosing a car, the program also asks for the fuel type.

The calculator uses the following illustrative emission factors:

| Transport | Emission Factor (kg CO2/km) |
|---|---|
| Petrol car | 0.192 |
| Diesel car | 0.171 |
| Electric car | 0.053 |
| Bus | 0.105 |
| Train | 0.035 |

The calculation uses the formula:

Estimated CO2 emissions (kg) = Distance (km) × Emission factor (kg/km)

For example, travelling 100 km in a petrol car produces an estimated 19.20 kg of CO2 using the project's illustrative factor.

The application uses separate functions to manage user input, transport selection, calculations and result display.

## Requirements

- A C++ compiler supporting C++17.
- A terminal or development environment such as Visual Studio Code.

## How to Compile and Run

Open a terminal in the `CO2-Calculator` folder.

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic CalculatorCO2.cpp -o CalculatorCO2
```

Run the application:

```bash
./CalculatorCO2
```

## Project Files

- `CalculatorCO2.cpp`: Contains the complete C++ source code.
- `readme.md`: Contains the project description and instructions.

## Notes

The emission factors used in this project are illustrative values intended for educational purposes. They are not presented as official UK Government conversion factors.

Actual emissions depend on vehicle type, energy source, operating conditions and calculation methodology.

## What I Learned

Through this project, I improved my understanding of C++ functions, variables, conditional statements, loops, mathematical calculations and input validation.

I also practised organising a program into separate functions, compiling source code and testing calculations through a command-line interface.
