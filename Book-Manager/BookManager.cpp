
/*
    PROJECT: BOOK MANAGER
    FILE: BookManager.cpp

    PURPOSE:
    This program manages a collection of books using C++.

    The application allows the user to:
    1. Display all books.
    2. Search for a book.
    3. Add a new book.
    4. Update an existing book.
    5. Delete a book.
    6. View available books.
    7. Save books to a file.
    0. Exit the application.

    PROGRAMMING CONCEPTS:
    - Object-oriented programming
    - Classes and objects
    - Encapsulation
    - Constructors
    - Getters and setters
    - Vectors
    - Functions
    - Loops and conditional statements
    - Input validation
    - File handling
    - Exception handling

    This version contains the complete application,
    including the main() function, in one source file.

    Book records are stored in bookData.txt.
*/


// ============================================================
// 1. LIBRARY INCLUDES
// ============================================================

// iostream provides standard input and output.
//
// cin reads information entered by the user.
// cout displays menus, messages and results.

#include <iostream>


// fstream provides tools for reading and writing files.
//
// ifstream reads information from an existing file.
// ofstream writes information to a file.
//
// This library is used to load and save bookData.txt.

#include <fstream>


// sstream allows strings to be processed as streams.
//
// stringstream is used to separate book information
// stored in comma-separated records.

#include <sstream>


// string provides the string data type.
//
// Strings are used to store book titles, authors,
// book IDs and other text information.

#include <string>


// vector provides a dynamic collection.
//
// Unlike a fixed-size array, a vector can grow
// when books are added and shrink when books
// are removed.

#include <vector>


// limits provides information about numeric limits.
//
// numeric_limits is used with cin.ignore()
// to remove unwanted characters from input.

#include <limits>


// stdexcept provides standard exception classes.
//
// Exception handling is used when converting
// text into numbers while loading book records.

#include <stdexcept>


// This allows standard library names to be written
// without the std:: prefix.

using namespace std;


// ============================================================
// 2. BOOK CLASS
// ============================================================

/*
    CLASS: Book

    PURPOSE:
    Represents one book in the collection.

    Each Book object stores:
    - Title
    - Author
    - Number of pages
    - Unique ID
    - Availability status

    The attributes are private to demonstrate
    encapsulation.

    Public getter and setter functions provide
    controlled access to the book information.
*/

class Book
{
private:

    // Stores the title of the book.
    string title;

    // Stores the author's name.
    string author;

    // Stores the number of pages.
    int pages;

    // Stores the unique book ID.
    string id;

    // Stores the availability status.
    // true means available.
    // false means unavailable.
    bool available;


public:

    // --------------------------------------------------------
    // DEFAULT CONSTRUCTOR
    // --------------------------------------------------------

    /*
        FUNCTION: Book()

        PURPOSE:
        Creates a Book object with default values.

        A constructor runs automatically when an
        object is created.

        The initialisation list assigns values
        before the constructor body runs.
    */

    Book()
        : title(""),
          author(""),
          pages(0),
          id(""),
          available(false)
    {
    }


    // --------------------------------------------------------
    // PARAMETERISED CONSTRUCTOR
    // --------------------------------------------------------

    /*
        FUNCTION: Book(...)

        PURPOSE:
        Creates a Book object using information
        supplied through parameters.

        This allows different books to have
        different titles, authors, page counts,
        IDs and availability values.
    */

    Book(
        string bookTitle,
        string bookAuthor,
        int bookPages,
        string bookId,
        bool bookAvailable
    )
        : title(bookTitle),
          author(bookAuthor),
          pages(bookPages),
          id(bookId),
          available(bookAvailable)
    {
    }


    // ========================================================
    // GETTER FUNCTIONS
    // ========================================================

    /*
        Getter functions return private attributes.

        The const keyword means these functions
        do not modify the Book object.
    */


    // Returns the title of the book.

    string getTitle() const
    {
        return title;
    }


    // Returns the author's name.

    string getAuthor() const
    {
        return author;
    }


    // Returns the number of pages.

    int getPages() const
    {
        return pages;
    }


    // Returns the unique book ID.

    string getId() const
    {
        return id;
    }


    // Returns the availability status.

    bool isAvailable() const
    {
        return available;
    }


    // ========================================================
    // SETTER FUNCTIONS
    // ========================================================

    /*
        Setter functions update private attributes.

        void means the function does not return a value.

        BookManager validates user input before
        calling these functions.
    */


    // Updates the book title.

    void setTitle(const string& bookTitle)
    {
        title = bookTitle;
    }


    // Updates the author's name.

    void setAuthor(const string& bookAuthor)
    {
        author = bookAuthor;
    }


    // Updates the number of pages.

    void setPages(int bookPages)
    {
        pages = bookPages;
    }


    // Updates the book ID.

    void setId(const string& bookId)
    {
        id = bookId;
    }


    // Updates the availability status.

    void setAvailable(bool bookAvailable)
    {
        available = bookAvailable;
    }
};


// ============================================================
// 3. BOOK MANAGER CLASS
// ============================================================

/*
    CLASS: BookManager

    PURPOSE:
    Manages the complete collection of Book objects.

    The class contains functions for:
    - Loading books
    - Searching for books
    - Displaying books
    - Adding books
    - Updating books
    - Deleting books
    - Viewing available books
    - Saving books

    The collection is stored in a vector.
*/

class BookManager
{
private:

    // --------------------------------------------------------
    // VECTOR OF BOOKS
    // --------------------------------------------------------

    /*
        vector<Book> stores multiple Book objects.

        The vector changes size automatically
        when books are added or deleted.
    */

    vector<Book> books;


    // --------------------------------------------------------
    // FILE NAME
    // --------------------------------------------------------

    /*
        Stores the name of the data file.

        const prevents the filename from being
        changed after initialisation.

        The file is read from and written to
        the program's working directory.
    */

    const string filename = "bookData.txt";


    // --------------------------------------------------------
    // FUNCTION: findBookIndex()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Searches for a book using its unique ID.

        PARAMETER:
        searchId is the ID being searched for.

        RETURN VALUE:
        Returns the position of the matching book
        inside the vector.

        Returns -1 if no matching book exists.

        This function is used by searchBook(),
        addBook(), updateBook() and deleteBook().
    */

    int findBookIndex(const string& searchId) const
    {
        // Visit each Book object in the vector.

        for (size_t i = 0; i < books.size(); i++)
        {
            // Compare the current book ID with searchId.

            if (books[i].getId() == searchId)
            {
                // Return the position of the matching book.

                return static_cast<int>(i);
            }
        }

        // Return -1 when no book is found.

        return -1;
    }


    // --------------------------------------------------------
    // FUNCTION: isValidText()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Checks whether a text value is valid.

        The function rejects:
        - Empty text
        - Text containing only spaces or tabs
        - Text containing commas

        Commas are rejected because the data file
        uses commas to separate book fields.

        RETURN VALUE:
        true if the text is valid.
        false if the text is invalid.
    */

    bool isValidText(const string& textValue) const
    {
        // Reject commas.

        if (textValue.find(',') != string::npos)
        {
            return false;
        }

        // Require at least one non-space character.

        return textValue.find_first_not_of(" \t")
               != string::npos;
    }


    // --------------------------------------------------------
    // FUNCTION: readPositiveInteger()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Reads a positive whole number from the user.

        This function is used when entering
        the number of pages.

        The while loop repeats until the user
        enters a valid integer greater than zero.

        cin.clear() resets input errors.

        cin.ignore() removes unwanted characters.

        RETURN VALUE:
        A valid positive integer.
    */

    int readPositiveInteger(const string& prompt)
    {
        int number;

        while (true)
        {
            // Display the input question.

            cout << prompt;

            // Attempt to read an integer.

            if (cin >> number)
            {
                // Remove remaining characters from the line.

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                // Accept only positive numbers.

                if (number > 0)
                {
                    return number;
                }
            }
            else
            {
                // Reset the input stream after invalid input.

                cin.clear();

                // Remove invalid characters.

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );
            }

            // Ask again if the number is invalid.

            cout << "Invalid input. Enter a positive whole number.\n";
        }
    }


    // --------------------------------------------------------
    // FUNCTION: loadBooks()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Loads saved books from bookData.txt.

        Each record uses this format:

        title,author,pages,id,true/false

        Example:

        1984,George Orwell,328,002,true

        The function:
        1. Opens the data file.
        2. Reads each line.
        3. Separates the five fields.
        4. Validates the information.
        5. Creates Book objects.
        6. Stores the objects in the vector.

        Invalid or duplicate records are skipped.
    */

    void loadBooks()
    {
        // Clear the collection before loading.

        books.clear();

        // Open the file for reading.

        ifstream inputFile(filename);

        // Check whether the file opened successfully.

        if (!inputFile.is_open())
        {
            cout << "Warning: Could not open "
                 << filename << ".\n";

            return;
        }

        // Stores one line from the file.

        string line;

        // Read the file line by line.

        while (getline(inputFile, line))
        {
            // Treat the current line as a stream.

            stringstream lineStream(line);

            // Variables for the five fields.

            string bookTitle;
            string bookAuthor;
            string pagesText;
            string bookId;
            string availabilityText;

            // Separate fields using commas.

            if (!getline(lineStream, bookTitle, ',') ||
                !getline(lineStream, bookAuthor, ',') ||
                !getline(lineStream, pagesText, ',') ||
                !getline(lineStream, bookId, ',') ||
                !getline(lineStream, availabilityText))
            {
                cout << "Skipping an incomplete book record.\n";
                continue;
            }

            // Validate required text fields.

            if (!isValidText(bookTitle) ||
                !isValidText(bookAuthor) ||
                !isValidText(bookId))
            {
                cout << "Skipping a record with invalid text fields.\n";
                continue;
            }

            // Convert availability text into a Boolean.

            bool bookAvailable;

            if (availabilityText == "true")
            {
                bookAvailable = true;
            }
            else if (availabilityText == "false")
            {
                bookAvailable = false;
            }
            else
            {
                cout << "Skipping a record with invalid availability.\n";
                continue;
            }

            // Use exception handling for number conversion.

            try
            {
                size_t charactersRead = 0;

                // Convert the page count into an integer.

                int bookPages = stoi(
                    pagesText,
                    &charactersRead
                );

                // Reject invalid page counts.

                if (charactersRead != pagesText.size() ||
                    bookPages <= 0)
                {
                    cout << "Skipping a record with an invalid page count.\n";
                    continue;
                }

                // Reject duplicate book IDs.

                if (findBookIndex(bookId) != -1)
                {
                    cout << "Skipping a record with a duplicate ID.\n";
                    continue;
                }

                // Create and store the Book object.

                books.emplace_back(
                    bookTitle,
                    bookAuthor,
                    bookPages,
                    bookId,
                    bookAvailable
                );
            }
            catch (const exception&)
            {
                // Handle invalid numeric information.

                cout << "Skipping a record with invalid numeric data.\n";
            }
        }

        // Close the file after reading.

        inputFile.close();
    }


public:

    // --------------------------------------------------------
    // BOOKMANAGER CONSTRUCTOR
    // --------------------------------------------------------

    /*
        FUNCTION: BookManager()

        PURPOSE:
        Runs automatically when a BookManager
        object is created.

        It calls loadBooks() to load previously
        saved book records into the vector.
    */

    BookManager()
    {
        loadBooks();
    }


    // --------------------------------------------------------
    // FUNCTION: displayBooks()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Displays every book in the collection.

        The function shows:
        - ID
        - Title
        - Author
        - Number of pages
        - Availability

        If the vector is empty, an appropriate
        message is displayed.
    */

    void displayBooks() const
    {
        // Check whether the collection is empty.

        if (books.empty())
        {
            cout << "No books are currently stored.\n";
            return;
        }

        cout << "\n========== ALL BOOKS ==========\n";

        // Visit each book without modifying it.

        for (const Book& book : books)
        {
            cout << "ID: " << book.getId() << '\n';
            cout << "Title: " << book.getTitle() << '\n';
            cout << "Author: " << book.getAuthor() << '\n';
            cout << "Pages: " << book.getPages() << '\n';

            // Display the availability status.

            cout << "Availability: "
                 << (book.isAvailable()
                     ? "Available"
                     : "Unavailable")
                 << "\n-------------------------------\n";
        }
    }


    // --------------------------------------------------------
    // FUNCTION: searchBook()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Searches for a book using its unique ID.

        The function:
        1. Asks the user for an ID.
        2. Searches the collection.
        3. Displays the matching book.
        4. Shows a message if the book is not found.
    */

    void searchBook() const
    {
        string searchId;

        // Ask for the book ID.

        cout << "Enter the ID of the book to search for: ";
        getline(cin, searchId);

        // Find the matching book.

        int index = findBookIndex(searchId);

        // Handle a missing book.

        if (index == -1)
        {
            cout << "No book found with ID: "
                 << searchId << '\n';

            return;
        }

        // Access the matching Book object.

        const Book& book = books[index];

        // Display the book details.

        cout << "\nBook found:\n";
        cout << "ID: " << book.getId() << '\n';
        cout << "Title: " << book.getTitle() << '\n';
        cout << "Author: " << book.getAuthor() << '\n';
        cout << "Pages: " << book.getPages() << '\n';

        cout << "Availability: "
             << (book.isAvailable()
                 ? "Available"
                 : "Unavailable")
             << '\n';
    }


    // --------------------------------------------------------
    // FUNCTION: addBook()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Adds a new book to the collection.

        The function requests:
        - Title
        - Author
        - Number of pages
        - Unique ID
        - Availability

        Each value is validated before the
        Book object is created.

        The new book is added to the vector
        using emplace_back().

        saveBooks() stores the updated collection.
    */

    void addBook()
    {
        string bookTitle;
        string bookAuthor;
        string bookId;
        string availabilityInput;

        // Ask for the title.

        cout << "Enter book title: ";
        getline(cin, bookTitle);

        // Validate the title.

        if (!isValidText(bookTitle))
        {
            cout << "Invalid title. Do not leave it blank or use commas.\n";
            return;
        }

        // Ask for the author.

        cout << "Enter author: ";
        getline(cin, bookAuthor);

        // Validate the author.

        if (!isValidText(bookAuthor))
        {
            cout << "Invalid author. Do not leave it blank or use commas.\n";
            return;
        }

        // Read a positive page count.

        int bookPages = readPositiveInteger(
            "Enter number of pages: "
        );

        // Ask for a unique ID.

        cout << "Enter a unique book ID: ";
        getline(cin, bookId);

        // Validate the ID.

        if (!isValidText(bookId))
        {
            cout << "Invalid ID. Do not leave it blank or use commas.\n";
            return;
        }

        // Check for duplicate IDs.

        if (findBookIndex(bookId) != -1)
        {
            cout << "A book with this ID already exists.\n";
            return;
        }

        // Ask for availability.

        cout << "Is the book available? Enter true or false: ";
        getline(cin, availabilityInput);

        bool bookAvailable;

        // Convert the text into a Boolean.

        if (availabilityInput == "true")
        {
            bookAvailable = true;
        }
        else if (availabilityInput == "false")
        {
            bookAvailable = false;
        }
        else
        {
            cout << "Invalid availability. Enter true or false.\n";
            return;
        }

        // Create the new Book object.

        books.emplace_back(
            bookTitle,
            bookAuthor,
            bookPages,
            bookId,
            bookAvailable
        );

        cout << "Book added successfully.\n";

        // Save the new collection.

        saveBooks();
    }


    // --------------------------------------------------------
    // FUNCTION: updateBook()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Updates an existing book.

        The user enters the book ID.

        They can change:
        - Title
        - Author
        - Number of pages
        - Availability

        Pressing Enter for the title, author
        or availability keeps the old value.

        The book ID remains unchanged.

        All information is validated before
        changes are applied.
    */

    void updateBook()
    {
        string searchId;

        // Ask for the ID of the book.

        cout << "Enter the ID of the book to update: ";
        getline(cin, searchId);

        // Find the book.

        int index = findBookIndex(searchId);

        if (index == -1)
        {
            cout << "No book found with ID: "
                 << searchId << '\n';

            return;
        }

        // Access the existing information.

        const Book& existingBook = books[index];

        string newTitle;
        string newAuthor;
        string availabilityInput;

        // Display the current title.

        cout << "Current title: "
             << existingBook.getTitle() << '\n';

        // Ask for a new title.

        cout << "Enter new title, or press Enter to keep it: ";
        getline(cin, newTitle);

        // Validate the new title if entered.

        if (!newTitle.empty() && !isValidText(newTitle))
        {
            cout << "Invalid title. No changes were made.\n";
            return;
        }

        // Display the current author.

        cout << "Current author: "
             << existingBook.getAuthor() << '\n';

        // Ask for a new author.

        cout << "Enter new author, or press Enter to keep it: ";
        getline(cin, newAuthor);

        // Validate the new author if entered.

        if (!newAuthor.empty() && !isValidText(newAuthor))
        {
            cout << "Invalid author. No changes were made.\n";
            return;
        }

        // Ask for a new page count.

        int newPages = readPositiveInteger(
            "Enter the new page count: "
        );

        // Display the current availability.

        cout << "Current availability: "
             << (existingBook.isAvailable()
                 ? "true"
                 : "false")
             << '\n';

        // Ask for a new availability value.

        cout << "Enter true or false, or press Enter to keep it: ";
        getline(cin, availabilityInput);

        // Keep the existing value by default.

        bool newAvailability = existingBook.isAvailable();

        // Validate the new availability.

        if (availabilityInput == "true")
        {
            newAvailability = true;
        }
        else if (availabilityInput == "false")
        {
            newAvailability = false;
        }
        else if (!availabilityInput.empty())
        {
            cout << "Invalid availability. No changes were made.\n";
            return;
        }

        // Access the original Book object.

        Book& book = books[index];

        // Update the title if a new value was entered.

        if (!newTitle.empty())
        {
            book.setTitle(newTitle);
        }

        // Update the author if a new value was entered.

        if (!newAuthor.empty())
        {
            book.setAuthor(newAuthor);
        }

        // Update pages and availability.

        book.setPages(newPages);
        book.setAvailable(newAvailability);

        cout << "Book updated successfully.\n";

        // Save the updated collection.

        saveBooks();
    }


    // --------------------------------------------------------
    // FUNCTION: deleteBook()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Deletes a book using its unique ID.

        The function:
        1. Asks for the ID.
        2. Searches for the matching book.
        3. Removes it from the vector.
        4. Saves the remaining books.

        erase() removes the selected vector element.
    */

    void deleteBook()
    {
        string searchId;

        // Ask for the book ID.

        cout << "Enter the ID of the book to delete: ";
        getline(cin, searchId);

        // Find the matching book.

        int index = findBookIndex(searchId);

        if (index == -1)
        {
            cout << "No book found with ID: "
                 << searchId << '\n';

            return;
        }

        // Remove the book from the vector.

        books.erase(books.begin() + index);

        cout << "Book deleted successfully.\n";

        // Save the updated collection.

        saveBooks();
    }


    // --------------------------------------------------------
    // FUNCTION: viewAvailableBooks()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Displays only books marked as available.

        The function checks each Book object.

        If isAvailable() returns true,
        the book details are displayed.

        If no available books exist,
        an appropriate message is shown.
    */

    void viewAvailableBooks() const
    {
        // Track whether an available book was found.

        bool foundAvailable = false;

        cout << "\n========== AVAILABLE BOOKS ==========\n";

        // Visit every book in the vector.

        for (const Book& book : books)
        {
            // Display only available books.

            if (book.isAvailable())
            {
                foundAvailable = true;

                cout << "ID: " << book.getId() << '\n';
                cout << "Title: " << book.getTitle() << '\n';
                cout << "Author: " << book.getAuthor() << '\n';
                cout << "Pages: " << book.getPages() << '\n';
                cout << "Availability: Available\n";
                cout << "-------------------------------\n";
            }
        }

        // Display a message if no available books exist.

        if (!foundAvailable)
        {
            cout << "There are no available books.\n";
        }
    }


    // --------------------------------------------------------
    // FUNCTION: saveBooks()
    // --------------------------------------------------------

    /*
        PURPOSE:
        Saves the collection to bookData.txt.

        ofstream opens the file for writing.

        Existing file contents are replaced
        with the current book collection.

        Each record uses this format:

        title,author,pages,id,true/false

        Saving allows records to be loaded
        when the program starts again.
    */

    void saveBooks() const
    {
        // Open the file for writing.

        ofstream outputFile(filename);

        // Check whether the file opened successfully.

        if (!outputFile.is_open())
        {
            cout << "Error: Could not save data to "
                 << filename << ".\n";

            return;
        }

        // Write every book to the file.

        for (const Book& book : books)
        {
            outputFile << book.getTitle() << ','
                       << book.getAuthor() << ','
                       << book.getPages() << ','
                       << book.getId() << ','
                       << (book.isAvailable()
                           ? "true"
                           : "false")
                       << '\n';
        }

        // Close the file after writing.

        outputFile.close();

        cout << "Books saved successfully.\n";
    }
};


// ============================================================
// 4. MAIN FUNCTION
// ============================================================

/*
    FUNCTION: main()

    PURPOSE:
    This is the starting point of the application.

    The function:
    1. Creates a BookManager object.
    2. Displays the main menu.
    3. Reads the user's selection.
    4. Validates the input.
    5. Calls the selected operation.
    6. Repeats until the user selects Exit.

    The do-while loop displays the menu
    at least once.

    The switch statement selects the
    correct operation based on the user's choice.

    Because main() is included here,
    a separate main.cpp is not required.
*/

int main()
{
    // Create a BookManager object.
    // Its constructor loads saved books automatically.

    BookManager manager;

    // Store the user's menu selection.

    int choice = -1;

    // Repeat until the user selects option 0.

    do
    {
        // Display the main menu.

        cout << "\n====================================\n";
        cout << "           BOOK MANAGER             \n";
        cout << "====================================\n";
        cout << "1. Display all books\n";
        cout << "2. Search for a book\n";
        cout << "3. Add a new book\n";
        cout << "4. Update a book\n";
        cout << "5. Delete a book\n";
        cout << "6. View available books\n";
        cout << "7. Save books to file\n";
        cout << "0. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        // Attempt to read an integer.

        if (!(cin >> choice))
        {
            // Reset the input stream.

            cin.clear();

            // Remove invalid input characters.

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";

            // Use -1 to repeat the menu.

            choice = -1;
            continue;
        }

        // Remove remaining characters from the input line.
        // This prevents problems when using getline().

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        // Execute the selected menu operation.

        switch (choice)
        {
            case 1:

                // Display every book.

                manager.displayBooks();
                break;


            case 2:

                // Search for a book by ID.

                manager.searchBook();
                break;


            case 3:

                // Add a new book.

                manager.addBook();
                break;


            case 4:

                // Update an existing book.

                manager.updateBook();
                break;


            case 5:

                // Delete a book.

                manager.deleteBook();
                break;


            case 6:

                // Display available books.

                manager.viewAvailableBooks();
                break;


            case 7:

                // Save the collection to the data file.

                manager.saveBooks();
                break;


            case 0:

                // Save the collection before exiting.

                manager.saveBooks();

                cout << "Thank you for using Book Manager.\n";
                break;


            default:

                // Handle menu numbers outside the valid range.

                cout << "Invalid choice. Select an option from 0 to 7.\n";
                break;
        }

    } while (choice != 0);

    // Return 0 to indicate successful termination.

    return 0;
}
