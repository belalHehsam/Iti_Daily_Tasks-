#include <iostream>
#include <vector>

using namespace std;

class Author{
    string name;
    string nationality;

public:
    Author(string n, string na): name(n), nationality(na){};
    string getName(){return name;};
    string getNationality(){return nationality;};
};
//composition with Author
class Book {
  Author author;
  string title;
  int year;

public:
    Book(string title, int year,  string authorName, string authorNatioanlity): title(title), year(year), author(authorName, authorNatioanlity){};
    string getTitle(){return title;};
    int getYear(){return year;};
    string getAuthorName(){return author.getName();};
    string getAuthorNationality(){return author.getNationality();};
};

//aggregation with Book so we need pointers because when destruct library the book still on live
class Library{
    vector<Book*>books;
public:
    void addBook(Book* book){books.push_back(book);};
    int getBooksNumber(){return books.size();};
    friend ostream& operator<<(ostream&, const Library&);
};

ostream& operator<<(ostream&os, const Library& library ){

   for (auto b : library.books) {
    if (b) os << b->getTitle() << '\n';
}
    return os;
}


int main()
{

    Book* b1 = new Book("book1", 2000, "author1", "egy");
    Book* b2 = new Book("book2", 2000, "author2", "egy");

    Library library;

    library.addBook(b1);
    library.addBook(b2);


    cout << library;

    return 0;
}
