# Alexa Tell Me a Joke

## About the Project

Alexa Tell Me a Joke is a C++ command-line application that responds to specific user commands and displays jokes stored in an external text file.

I developed this project to practise object-oriented programming, file handling, user input processing and random number generation.

## Features

- Read jokes from an external file called `alexa.txt`.
- Display a randomly selected joke.
- Prevent the same joke from appearing twice consecutively.
- Display the total number of available jokes.
- Recognise specific user commands.
- Handle unrecognised commands.
- Allow users to exit the application.

## How It Works

The application uses a class called `JokeAssistant` to organise its main functionality.

A structure called `Joke` represents joke information.

When the application starts, it reads jokes from `alexa.txt` and stores them in memory.

The user can enter one of the following commands:

| Command | Action |
|---|---|
| `Alexa tell me a joke` | Displays a randomly selected joke |
| `Alexa how many jokes do you know` | Displays the number of available jokes |
| `exit` | Closes the application |

Commands are case-sensitive and must match the expected text.

The application uses conditional statements to identify commands and a loop to continue accepting input until the user exits.

Random selection allows different jokes to appear. The program also prevents immediate repetition of the previously selected joke.

## Requirements

- A C++ compiler supporting C++17.
- A terminal or development environment such as Visual Studio Code.
- The `alexa.txt` file containing the jokes.

## How to Compile and Run

Open a terminal in the `Alexa-Tell-Me-a-Joke` folder.

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic alexa.cpp -o Alexa
```

Run the application:

```bash
./Alexa
```

Make sure `alexa.txt` is in the same folder when running the program.

## Project Files

- `alexa.cpp`: Contains the C++ source code.
- `alexa.txt`: Contains the jokes used by the application.
- `readme.md`: Contains project documentation and instructions.

## Testing

I compiled and ran the program in the terminal.

I tested the supported commands, checked that jokes were loaded from the text file and verified that the application responded to user input.

I also checked the random joke selection and exit functionality.

## What I Learned

This project helped me improve my understanding of C++ classes, structures, file handling, functions, loops and conditional statements.

I also practised random number generation, organising program functionality and testing an interactive command-line application.
