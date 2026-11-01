# Book Manager

## About the Project

Book Manager is a C++ console application designed to manage a collection of books.

I developed this project to practise object-oriented programming, file handling, data management and input validation.

The application allows users to organise book records through an interactive menu.

## Features

- Display all books in the collection.
- Search for a book using its unique ID.
- Add new books.
- Update existing book information.
- Delete books from the collection.
- Display only available books.
- Save book records to an external text file.
- Load previously saved book records.
- Validate user input and prevent duplicate book IDs.

## How It Works

The application uses two main classes.

### Book Class

The `Book` class represents an individual book and stores the following information:

- Title
- Author
- Number of pages
- Unique ID
- Availability status

The class uses private attributes and public methods to control access to book information.

### BookManager Class

The `BookManager` class manages the collection of books.

It uses a C++ vector to store book objects and provides methods for adding, updating, deleting, searching and displaying records.

Users interact with the application through a console menu.

When adding a book, the program checks the information entered and verifies that the ID is unique.

When updating a book, users can modify the title, author, page count and availability status. The unique ID remains unchanged.

When deleting a book, the program removes the selected record from the collection.

The available-books feature displays only records marked as available.

### File Handling

The program uses `bookData.txt` to store book information.

Each record contains the book's title, author, page count, ID and availability status.

The application loads existing records when it starts.

When book information changes, the program saves the updated collection to the text file.

This allows the records to remain available between program sessions.

## Requirements

- A C++ compiler supporting C++17.
- A terminal or development environment such as Visual Studio Code.
- The `bookData.txt` file containing the book records.

## How to Compile and Run

Open a terminal in the `Book-Manager` folder.

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic BookManager.cpp -o BookManager
```

Run the application:

```bash
./BookManager
```

Keep `bookData.txt` in the same folder when running the application.

## Project Files

- `BookManager.cpp`: Contains the `Book` and `BookManager` classes, functions and main application.
- `bookData.txt`: Stores book records.
- `readme.md`: Contains project documentation and instructions.

## Input Validation

The application includes checks to reduce incorrect data entry.

These include validating numerical input, checking book IDs, preventing duplicate records and handling invalid availability values.

The program also allows users to retain existing title or author information during an update by leaving the corresponding input empty.

## Testing

I compiled and ran the application in the terminal.

I checked that the main menu appeared correctly and that existing book records could be loaded and displayed.

The project also includes functions for modifying records and saving changes.

## What I Learned

This project helped me improve my understanding of C++ classes, encapsulation, constructors, vectors, functions and file handling.

I also practised input validation, organising a larger application and storing information between program sessions.

Working on this project helped me understand how different C++ components can work together to manage structured data.
