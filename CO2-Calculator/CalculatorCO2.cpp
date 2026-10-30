/*
    PROJECT: CO2 EMISSION CALCULATOR

    PURPOSE:
    This program estimates CO2 emissions from travelling by car, bus,
    or train. The user enters a distance in kilometres or miles.
    If the user chooses a car, they also select petrol, diesel, or electric.

    HOW THE PROGRAM WORKS:
    1. Read and validate the travel distance.
    2. Convert miles into kilometres when necessary.
    3. Ask the user to select a transport type.
    4. Ask for the car fuel type if a car is selected.
    5. Calculate the estimated CO2 emissions.
    6. Display the result.

    IMPORTANT:
    The emission factors in this educational example are illustrative.
    They should be verified against reliable sources before the project
    is submitted.
*/

// Include the iostream library.
// This library provides standard input and output tools.
// cin reads information entered by the user.
// cout displays messages and results on the screen.
#include <iostream>

// Include the iomanip library.
// This library provides tools for formatting displayed values.
// We use fixed and setprecision(2) to display two decimal places.
#include <iomanip>

// Include the limits library.
// This library provides information about numerical limits.
// We use numeric_limits and cin.ignore() to remove invalid input.
#include <limits>

// Allow standard library names, such as cout and cin, to be used
// without writing std:: before each name.
using namespace std;


// FUNCTION 1: GET DISTANCE IN KILOMETRES
//
// The double keyword means that this function returns a decimal number.
// The function has empty parentheses because it does not receive arguments.
// Its purpose is to read the user's distance, validate it, and convert
// the value into kilometres if the user enters miles.
double getDistanceInKilometres() {

    // Declare a double variable to store the travel distance.
    // We use double because distances can contain decimal values,
    // for example, 12.5 kilometres.
    double distance;

    // Declare an integer variable to store the selected distance unit.
    // The user will enter 1 for kilometres or 2 for miles.
    int unit;

    // Ask the user to enter a travel distance.
    // cout displays the message.
    // \n creates a new line before the message.
    cout << "\nEnter distance: ";

    // Validate the distance entered by the user.
    // cin >> distance attempts to read a number.
    // !(cin >> distance) becomes true if the input cannot be read
    // as a number, for example, if the user enters "hello".
    // distance < 0 checks whether the distance is negative.
    // The || operator means OR, so either problem makes the condition true.
    // The while loop repeats until a valid, non-negative number is entered.
    while (!(cin >> distance) || distance < 0) {

        // Tell the user that the distance is invalid and ask again.
        cout << "Invalid distance. Enter a number >= 0: ";

        // Reset the input stream's error state.
        // This allows cin to attempt another input operation.
        cin.clear();

        // Remove the remaining invalid characters from the input line.
        // numeric_limits<streamsize>::max() gives a large upper limit.
        // '\n' tells cin.ignore() to stop when it reaches the end of the line.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Display the available units of measurement.
    cout << "\nChoose the distance unit:\n";
    cout << "1. Kilometres\n";
    cout << "2. Miles\n";
    cout << "Your choice: ";

    // Validate the selected unit.
    // Only options 1 and 2 are accepted.
    // The loop repeats if the input is not an integer or is outside this range.
    while (!(cin >> unit) || unit < 1 || unit > 2) {

        // Explain which options are valid.
        cout << "Invalid choice. Enter 1 or 2: ";

        // Clear the input error so another value can be read.
        cin.clear();

        // Discard the invalid characters from the input line.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check whether the user selected miles.
    // The == operator compares two values.
    // It is different from =, which assigns a value to a variable.
    if (unit == 2) {

        // Convert miles into kilometres.
        // One mile is approximately 1.60934 kilometres.
        // Multiplying the distance by this number converts the unit.
        distance = distance * 1.60934;
    }

    // Return the distance in kilometres to the function that called this one.
    // Returning a value allows main() to store and use the converted distance.
    return distance;
}


// FUNCTION 2: GET CAR EMISSION FACTOR
//
// This function asks the user to select a car fuel type.
// It returns a double value representing an estimated emission factor.
// An emission factor is the estimated amount of CO2 produced per kilometre.
double getCarEmissionFactor() {

    // Declare an integer variable to store the fuel selection.
    // Option 1 means petrol, option 2 means diesel, and option 3 means electric.
    int fuel;

    // Display the available car fuel types.
    cout << "\nChoose the car fuel type:\n";
    cout << "1. Petrol\n";
    cout << "2. Diesel\n";
    cout << "3. Electric\n";
    cout << "Your choice: ";

    // Validate the fuel selection.
    // The user must enter an integer between 1 and 3.
    while (!(cin >> fuel) || fuel < 1 || fuel > 3) {

        // Display an error message if the selection is invalid.
        cout << "Invalid choice. Enter 1, 2 or 3: ";

        // Reset the input stream after an invalid input.
        cin.clear();

        // Remove the invalid characters so the user can try again.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Use switch to execute code based on the value of fuel.
    // Each case represents one possible fuel selection.
    // return sends the selected factor back to the calling function
    // and immediately ends this function.

    switch (fuel) {

        // Execute this case when the user selects petrol.
        case 1:
            cout << "Fuel type: Petrol\n";

            // Return an illustrative petrol emission factor.
            // The example factor is 0.192 kg CO2 per kilometre.
            // Verify this value against a reliable source before submission.
            return 0.192;

        // Execute this case when the user selects diesel.
        case 2:
            cout << "Fuel type: Diesel\n";

            // Return an illustrative diesel emission factor.
            // The example factor is 0.171 kg CO2 per kilometre.
            // Verify this value against a reliable source before submission.
            return 0.171;

        // Execute this case when the user selects electric.
        case 3:
            cout << "Fuel type: Electric\n";

            // Return an illustrative electric-car emission factor.
            // The estimate depends on how electricity-related emissions
            // are measured, so it needs a suitable source.
            return 0.053;

        // The default case is a fallback if no case matches.
        // The validation loop should prevent this case from being reached.
        default:
            return 0.0;
    }
}


// FUNCTION 3: GET TRANSPORT EMISSION FACTOR
//
// This function asks the user to choose a transport type.
// It returns the emission factor associated with the selected transport.
// If the user chooses a car, it calls getCarEmissionFactor() to ask
// for the fuel type as well.
double getEmissionFactor() {

    // Declare an integer variable for the transport selection.
    // Option 1 means car, option 2 means bus, and option 3 means train.
    int transport;

    // Display the available transport options.
    cout << "\nChoose your transport:\n";
    cout << "1. Car\n";
    cout << "2. Bus\n";
    cout << "3. Train\n";
    cout << "Your choice: ";

    // Check that the transport option is valid.
    // The loop continues if the user enters text or a number outside 1-3.
    while (!(cin >> transport) || transport < 1 || transport > 3) {

        // Tell the user which options are accepted.
        cout << "Invalid choice. Enter 1, 2 or 3: ";

        // Clear the input stream's error state.
        cin.clear();

        // Remove the invalid input characters.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check whether the user selected a car.
    if (transport == 1) {

        // Call the fuel-selection function and return its result.
        // This separates car fuel selection from the transport menu.
        return getCarEmissionFactor();
    }

    // Check whether the user selected a bus.
    if (transport == 2) {

        // Display the selected transport type.
        cout << "Transport type: Bus\n";

        // Return the example bus emission factor.
        // This value is illustrative and needs a reliable source.
        return 0.105;
    }

    // If execution reaches this point, the transport must be a train.
    // This is because the validation loop accepts only options 1, 2, or 3.
    cout << "Transport type: Train\n";

    // Return the example train emission factor.
    // This value is illustrative and needs a reliable source.
    return 0.035;
}


// FUNCTION 4: CALCULATE CO2 EMISSIONS
//
// This function performs the main mathematical calculation.
// It receives the distance in kilometres and the emission factor.
// double means that the function returns a number that can contain decimals.
// Keeping the calculation in a separate function makes the program easier
// to understand, test, and maintain.
double calculateCO2(double distance, double emissionFactor) {

    // Multiply the distance by the emission factor.
    // Example: 100 km * 0.192 kg CO2/km = 19.20 kg CO2.
    // The result is returned to the calling function.
    return distance * emissionFactor;
}


// FUNCTION 5: DISPLAY THE RESULT
//
// void means that this function does not return a value.
// It receives the distance and calculated emissions as parameters.
// Its responsibility is to display the result clearly to the user.
void displayResult(double distance, double emissions) {

    // Use fixed decimal notation for floating-point output.
    // This works with setprecision(2) to show two decimal places.
    cout << fixed;

    // Set the output precision to two digits after the decimal point.
    // For example, 19.2 will be displayed as 19.20.
    cout << setprecision(2);

    // Display a heading to separate the result from the input questions.
    cout << "\n========== CALCULATION RESULT ==========\n";

    // Display the distance.
    // The distance is shown in kilometres because the program converts miles.
    cout << "Distance: " << distance << " km\n";

    // Display the estimated CO2 emissions in kilograms.
    cout << "Estimated CO2 emissions: "
         << emissions << " kg CO2\n";

    // Display a closing line for the results section.
    cout << "========================================\n";
}


// MAIN FUNCTION: PROGRAM ENTRY POINT
//
// In a standard C++ application, execution starts in main().
// This function coordinates the other functions in the correct order.
// int means that main() returns an integer status code to the operating system.
int main() {

    // Display the application title when the program starts.
    cout << "========================================\n";
    cout << "        CO2 EMISSION CALCULATOR\n";
    cout << "========================================\n";

    // STEP 1:
    // Call getDistanceInKilometres() to read and validate the distance.
    // Store the returned value in a double variable called distance.
    double distance = getDistanceInKilometres();

    // STEP 2:
    // Call getEmissionFactor() to select the transport type.
    // If a car is selected, this function also asks for the fuel type.
    // Store the returned factor in emissionFactor.
    double emissionFactor = getEmissionFactor();

    // STEP 3:
    // Pass the distance and emission factor to calculateCO2().
    // Store the calculated result in emissions.
    double emissions = calculateCO2(distance, emissionFactor);

    // STEP 4:
    // Pass the distance and emissions to displayResult().
    // The function prints the final calculation on the screen.
    displayResult(distance, emissions);

    // Return 0 to indicate that the program finished successfully.
    // This is a conventional success status for a C++ program.
    return 0;
}
