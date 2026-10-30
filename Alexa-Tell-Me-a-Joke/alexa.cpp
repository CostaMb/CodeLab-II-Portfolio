
/*
    Project: Alexa - Tell Me a Joke
    Language: C++

    Description:
    This program simulates a simple Alexa-style joke assistant.
    It loads jokes from Alexa.txt and allows the user to interact
    with the application by typing commands.

    Object-Oriented Programming (OOP):
    The JokeAssistant class groups the data and functions that
    control the application into one reusable unit.

    File handling:
    Jokes are loaded from an external text file.

    Commands:
    - Alexa tell me a joke
    - Alexa how many jokes do you know
    - exit

    Command validation:
    Commands must match the expected text exactly.
    Uppercase and lowercase letters are important.
    Commands without the word "Alexa" are not accepted.
*/

// ============================================================
// 1. LIBRARIES
// ============================================================

// iostream provides input and output using cin and cout.
#include <iostream>

// fstream allows the program to read external text files.
#include <fstream>

// string provides the string data type for storing text.
#include <string>

// vector stores multiple jokes in a dynamic collection.
#include <vector>

// random generates random numbers for selecting jokes.
#include <random>

// Allows standard library names without the std:: prefix.
using namespace std;


// ============================================================
// 2. JOKE STRUCTURE
// ============================================================

/*
    STRUCTURE: Joke

    PURPOSE:
    Represents one joke using two string variables.

    question stores the question part of the joke.
    answer stores the answer or punchline.

    A structure groups related information together.
*/

struct Joke {
    string question;
    string answer;
};


// ============================================================
// 3. JOKE ASSISTANT CLASS
// ============================================================

/*
    CLASS: JokeAssistant

    PURPOSE:
    Controls the Alexa joke application.

    The class is responsible for:
    - Loading jokes from Alexa.txt
    - Storing jokes in a vector
    - Selecting random jokes
    - Preventing immediate joke repetition
    - Counting available jokes
    - Validating user commands
    - Running the application

    Private members can only be accessed directly
    from inside the class.

    Public members can be accessed from outside
    the class, including from main().
*/

class JokeAssistant {
private:

    // Stores all valid jokes loaded from Alexa.txt.
    vector<Joke> jokes;

    // Remembers the index of the previously displayed joke.
    // -1 means that no joke has been displayed yet.
    int lastJoke = -1;

    // Provides a seed for the random number generator.
    random_device randomDevice;

    // Generates random numbers using the Mersenne Twister engine.
    mt19937 generator;


    // ========================================================
    // FUNCTION: trim()
    // ========================================================

    /*
        PURPOSE:
        Removes unnecessary whitespace from both ends
        of a string.

        It handles spaces, tabs, carriage returns
        and newline characters.

        This function is used when reading joke records
        from Alexa.txt.

        The function is static because it does not need
        access to a specific JokeAssistant object's data.

        PARAMETER:
        text - The original string.

        RETURN VALUE:
        A string without leading or trailing whitespace.
    */

    static string trim(const string& text) {

        // Characters treated as whitespace.
        const string whitespace = " \t\r\n";

        // Find the first character that is not whitespace.
        size_t first = text.find_first_not_of(whitespace);

        // Return an empty string if the text contains
        // only whitespace characters.
        if (first == string::npos) {
            return "";
        }

        // Find the last character that is not whitespace.
        size_t last = text.find_last_not_of(whitespace);

        // Return the text between the first and last
        // non-whitespace characters.
        return text.substr(first, last - first + 1);
    }


    // ========================================================
    // FUNCTION: loadJokes()
    // ========================================================

    /*
        PURPOSE:
        Reads jokes from the external Alexa.txt file.

        Each valid line contains:
        - A question ending with a question mark
        - An answer after the question mark

        Example:
        Why was the computer cold? It left its Windows open.

        The function:
        1. Opens the file.
        2. Reads each line.
        3. Removes unnecessary whitespace.
        4. Finds the question mark.
        5. Separates the question and answer.
        6. Stores valid jokes in the vector.

        Invalid or incomplete lines are ignored.

        PARAMETER:
        filename - Name of the file containing jokes.

        RETURN VALUE:
        true if at least one valid joke was loaded.
        false if no valid jokes were loaded.
    */

    bool loadJokes(const string& filename) {

        // Open the file in read mode.
        ifstream file(filename);

        // Stop if the file cannot be opened.
        if (!file.is_open()) {
            cout << "Error: Could not open "
                 << filename << endl;
            return false;
        }

        // Clear previous jokes before loading new records.
        jokes.clear();

        // Reset the previously selected joke.
        lastJoke = -1;

        // Stores one line read from the file.
        string line;

        // Read each line until the end of the file.
        while (getline(file, line)) {

            // Remove whitespace around the complete line.
            line = trim(line);

            // Ignore empty lines.
            if (line.empty()) {
                continue;
            }

            // Find the first question mark.
            size_t separator = line.find('?');

            // Ignore lines without a question mark.
            if (separator == string::npos) {
                continue;
            }

            // Extract the question, including its question mark.
            string question = trim(
                line.substr(0, separator + 1)
            );

            // Extract the answer after the question mark.
            string answer = trim(
                line.substr(separator + 1)
            );

            // Accept only a non-empty question and answer.
            if (!question.empty() && !answer.empty()) {

                // Create a Joke object and add it to the vector.
                jokes.push_back({question, answer});
            }
        }

        // Close the file after reading is complete.
        file.close();

        // Return true if the collection contains jokes.
        return !jokes.empty();
    }


    // ========================================================
    // FUNCTION: tellJoke()
    // ========================================================

    /*
        PURPOSE:
        Selects and displays a random joke.

        The function uses uniform_int_distribution
        to generate a random index within the vector.

        If more than one joke exists, the previous joke
        is excluded from the next selection.

        This prevents the same joke from appearing
        twice in a row.

        RETURN VALUE:
        void - The function displays information
        but does not return a value.
    */

    void tellJoke() {

        // Check that jokes are available.
        if (jokes.empty()) {
            cout << "Alexa: No jokes are available." << endl;
            return;
        }

        // Create a distribution covering valid vector indexes.
        uniform_int_distribution<size_t> distribution(
            0, jokes.size() - 1
        );

        // Select a random joke index.
        size_t index = distribution(generator);

        // Avoid repeating the previous joke when possible.
        if (jokes.size() > 1) {

            while (static_cast<int>(index) == lastJoke) {
                index = distribution(generator);
            }
        }

        // Remember the selected joke.
        lastJoke = static_cast<int>(index);

        // Display the question and answer together.
        cout << "Alexa: "
             << jokes[index].question << " "
             << jokes[index].answer
             << endl;
    }


    // ========================================================
    // FUNCTION: showJokeCount()
    // ========================================================

    /*
        PURPOSE:
        Displays how many valid jokes were loaded.

        The vector's size() function returns
        the total number of Joke objects.

        The const keyword means this function
        does not modify the JokeAssistant object.

        RETURN VALUE:
        void - Displays the result without returning it.
    */

    void showJokeCount() const {

        cout << "Alexa: I know "
             << jokes.size()
             << " jokes!"
             << endl;
    }


    // ========================================================
    // FUNCTION: processCommand()
    // ========================================================

    /*
        PURPOSE:
        Checks the user's command and calls
        the appropriate function.

        IMPORTANT:
        Commands are compared exactly.

        The program does not convert commands
        to lowercase or remove characters.

        This means:
        "Alexa tell me a joke" is accepted.

        "tell me a joke" is rejected.
        "alexa tell me a joke" is rejected.
        "ALEXA tell me a joke" is rejected.

        The same rule applies to the joke count command.

        The exit command remains available
        to close the application.

        PARAMETER:
        command - The exact text entered by the user.

        RETURN VALUE:
        false when the user enters "exit".
        true for all other inputs.
    */

    bool processCommand(const string& command) {

        // Exit the application when requested.
        if (command == "exit") {

            cout << "Alexa: Goodbye!" << endl;
            return false;
        }

        // Accept only the complete, correctly written command.
        else if (command == "Alexa tell me a joke") {

            // Display a random joke.
            tellJoke();
        }

        // Accept only the complete joke-count command.
        else if (
            command == "Alexa how many jokes do you know"
        ) {

            // Display the number of available jokes.
            showJokeCount();
        }

        // Reject every other command.
        else {

            cout << "Alexa: Invalid command." << endl;

            cout << "Please type one of the following:"
                 << endl;

            cout << "Alexa tell me a joke" << endl;

            cout << "Alexa how many jokes do you know"
                 << endl;

            cout << "exit" << endl;
        }

        // Continue running after processing the command.
        return true;
    }


public:

    // ========================================================
    // CONSTRUCTOR: JokeAssistant()
    // ========================================================

    /*
        PURPOSE:
        Runs automatically when a JokeAssistant
        object is created.

        The constructor initialises the random
        number generator using randomDevice.

        This allows jokes to be selected randomly
        during application execution.
    */

    JokeAssistant() : generator(randomDevice()) {
    }


    // ========================================================
    // FUNCTION: run()
    // ========================================================

    /*
        PURPOSE:
        Starts and controls the application.

        The function:
        1. Loads jokes from Alexa.txt.
        2. Checks whether valid jokes exist.
        3. Displays the available commands.
        4. Reads commands from the user.
        5. Processes each command.
        6. Continues until the user enters "exit".

        getline() reads the complete input line,
        including spaces.

        The while loop keeps the application running.

        Unlike the previous version, the command
        is not converted to lowercase.

        This ensures exact command matching.
    */

    void run() {

        // Load jokes before accepting user commands.
        if (!loadJokes("alexa.txt")) {

            cout << "No valid jokes found. Check alexa.txt."
                 << endl;

            return;
        }

        // Display application instructions.
        cout << "Alexa Joke Assistant is ready!" << endl;

        cout << "Type: Alexa tell me a joke" << endl;

        cout << "Type: Alexa how many jokes do you know"
             << endl;

        cout << "Type: exit to close the program."
             << endl;

        // Stores the command entered by the user.
        string command;

        // Continue accepting commands until exit.
        while (true) {

            cout << "\nYou: ";

            // Read the complete command.
            if (!getline(cin, command)) {

                // Exit if the input stream is closed.
                cout << "\nAlexa: Goodbye!" << endl;
                break;
            }

            // Process the original command without
            // changing uppercase or lowercase letters.
            if (!processCommand(command)) {

                // Stop the loop when exit is requested.
                break;
            }
        }
    }
};


// ============================================================
// 4. MAIN FUNCTION
// ============================================================

/*
    FUNCTION: main()

    PURPOSE:
    This is the starting point of the C++ application.

    The function:
    1. Creates a JokeAssistant object.
    2. Calls the run() function.
    3. Returns zero when execution finishes successfully.

    Because main() is included in this file,
    a separate main.cpp is not required.
*/

int main() {

    // Create an instance of the JokeAssistant class.
    JokeAssistant assistant;

    // Start the application's command loop.
    assistant.run();

    // Return zero to indicate successful termination.
    return 0;
}
