# Alexa – Tell Me a Joke

## Project Description

This is a simple C++ console application that simulates a basic Alexa-style joke assistant. Users can type commands to receive a random joke, check how many jokes are available, or exit the application.

The project uses object-oriented programming, file handling, vectors, string manipulation and random number generation.

## Features

- Loads jokes from an external text file.
- Displays a random joke when requested.
- Shows the total number of valid jokes available.
- Avoids repeating the same joke twice in a row when more than one joke is available.
- Requires commands to match the expected text exactly, including uppercase and lowercase letters.
- Rejects incomplete or incorrectly written commands.
- Handles unrecognised commands with an error message.
- Allows users to exit by typing `exit`.

## Project Files

- `alexa.cpp` – Contains the main program, the `Joke` structure and the `JokeAssistant` class.
- `alexa.txt` – Stores the jokes used by the application.
- `readme.md` – Provides project documentation and instructions.

## Requirements

- A C++17-compatible compiler, such as `g++`.
- Visual Studio Code or another code editor.

## How to Compile and Run

Make sure the terminal is open in the project folder and that the source code and joke text file are in the same directory.

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic alexa.cpp -o AlexaJokes
```

Run the application:

```bash
./AlexaJokes
```

## Available Commands

| Command | Description |
|---|---|
| `Alexa tell me a joke` | Displays a random joke. |
| `Alexa how many jokes do you know` | Shows the number of valid jokes loaded. |
| `exit` | Closes the application. |

Commands are case-sensitive and must be entered exactly as shown.

For example, `tell me a joke` and `alexa tell me a joke` are not accepted.

## Example

```text
Alexa Joke Assistant is ready!
Type: Alexa tell me a joke
Type: Alexa how many jokes do you know
Type: exit to close the program.

You: tell me a joke
Alexa: Invalid command.

You: Alexa tell me a joke
Alexa: Why did the computer go to the doctor? It had a virus!

You: exit
Alexa: Goodbye!
```

*The example above is illustrative; the actual joke depends on the contents of `alexa.txt`.*

## Learning Outcomes

Through this project, I practised working with C++ structures and classes, reading data from text files, storing information in vectors, processing user input and generating random numbers. I also practised testing the application and handling invalid commands.

## Author

Created as part of my C++ programming practice and university programming portfolio.