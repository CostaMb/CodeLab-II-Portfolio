# Alexa Tell Me a Joke

## About My Project

For this project, I created a simple joke assistant using C++. I wanted to make a program that could respond to a few commands and tell jokes stored in a text file.

I used this project to practise working with classes, functions, user input and file handling.

## What My Program Can Do

- Read jokes from `alexa.txt`.
- Tell a random joke when the user enters the correct command.
- Avoid repeating the same joke twice in a row.
- Show how many jokes are available.
- Respond when the user enters an unknown command.
- Close the program when the user types `exit`.

## How I Made It Work

I created a class called `JokeAssistant` to organise the main parts of my program. I also used a structure called `Joke` to store joke information.

Instead of putting all the jokes directly into the C++ code, I decided to keep them in a separate text file called `alexa.txt`.

The program reads this file and uses the jokes when the user asks for one.

I added three commands:

| Command | What It Does |
|---|---|
| `Alexa tell me a joke` | Tells a random joke |
| `Alexa how many jokes do you know` | Shows the number of jokes |
| `exit` | Closes the program |

The commands must be typed exactly as shown, including capital letters.

I also added a check to stop the program from telling the same joke twice in a row.

## How to Run My Program

I used Visual Studio Code and the terminal to compile and test my code.

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic alexa.cpp -o Alexa
```

Run:

```bash
./Alexa
```

The `alexa.txt` file needs to be in the same folder.

## Project Files

- `alexa.cpp`: My C++ program.
- `alexa.txt`: The jokes used by the program.
- `readme.md`: Information about my project.

## Testing

I tested the program by entering the different commands and checking the responses.

I also checked that the jokes loaded from the text file and that the program could close correctly.

## What I Learned

This project helped me understand how classes and functions work together.

I also learned more about reading information from files, using loops and conditions, and selecting random values.

One useful part of this project was learning how to keep the jokes separate from the main code, making the program easier to update.
