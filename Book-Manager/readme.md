# Book Manager

## About My Project

For this project, I created a Book Manager application using C++. I wanted to build a program where I could store book information and manage it using a simple menu in the terminal.

This project was more detailed than my previous exercises because I had to work with different functions, classes and a text file.

## What My Program Can Do

- Display all books.
- Search for a book using its ID.
- Add a new book.
- Update book information.
- Delete a book.
- Show only available books.
- Save book information in a text file.
- Load saved books when the program starts.

## How I Made It Work

I used two classes called `Book` and `BookManager`.

The `Book` class stores information about each book, including its title, author, number of pages, ID and availability.

The `BookManager` class handles the main operations, such as adding, searching, updating and deleting books.

I used a vector to keep the books together while the program is running.

I also created a menu so the user can choose what they want to do.

For example, when adding a new book, the program asks for the book information and checks that the ID is not already being used.

When updating a book, the user can change its title, author, number of pages and availability. The book ID stays the same.

## Working With Files

I used `bookData.txt` to save the book information.

When the program starts, it reads the saved records from this file.

When a book is added, updated or deleted, the program saves the changes.

This was an important part of the project because I wanted the book information to remain available after closing the application.

## How to Run My Program

I used Visual Studio Code and the terminal to compile and run the project.

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic BookManager.cpp -o BookManager
```

Run:

```bash
./BookManager
```

The `bookData.txt` file needs to be in the same folder.

## Project Files

- `BookManager.cpp`: My main C++ source file.
- `bookData.txt`: Stores the book information.
- `readme.md`: Information about the project.

## Testing

I compiled the program and checked that the menu appeared correctly.

I also tested loading and displaying the books from the text file.

While working on the project, I made changes to improve the organisation of the code and how the program handles user input.

## What I Learned

This project helped me understand object-oriented programming in more detail.

I practised using classes, constructors, vectors, functions and file handling.

I also learned why checking user input is important, especially when adding or updating information.

The most useful part for me was understanding how to connect different functions and classes to create one working application.
