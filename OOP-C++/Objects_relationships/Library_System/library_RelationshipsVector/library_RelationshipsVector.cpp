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

//comment below
//dah compostion because Book who create the author and when destruct the book the Author auto destruct with IT
class Book {
  Author* author;
  string title;
  int year;

public:
    Book(string title, int year,  string authorName, string authorNationality): title(title), year(year){
        author = new Author(authorName, authorNationality);
    };
    string getTitle()const {return title;}
    int getYear() const {return year;};
    string getAuthorName() const {return author->getName();};
    string getAuthorNationality() const {return author->getNationality();};
    Book(const Book& book){
        this->author = new Author(book.getAuthorName(), book.getAuthorNationality());
        this->title = book.getTitle();
        this->year = book.getYear();
    };

    Book& operator=(const Book& book){
        if(this == &book) return *this;
        delete this->author;
        this->author = new Author(book.getAuthorName(), book.getAuthorNationality());
        this->title = book.getTitle();
        this->year = book.getYear();
        return *this;
    };
    ~Book(){delete author;};

};


class Library{
    vector<Book>books;
public:
    void addBook(Book book){books.push_back(book);};
    int getBooksNumber(){return books.size();};
    friend ostream& operator<<(ostream&, const Library&);
};

ostream& operator<<(ostream&os, const Library& library ){

    for(int i=0; i<library.books.size(); i++){
        os << library.books[i].getTitle() << '\n';
    }
    return os;
}

int main()
{

    Book b1("book1", 2000, "author1", "egy");
    Book b2("book2", 2000, "author2", "egy");
    Book b3("book3", 2000, "author3", "egy");

    Book b4 = b3;

    b2 = b1;


    Library library;

    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);
    library.addBook(b4);


    cout << library;

    return 0;
}

/*

ليه رغم إنه Pointer؟
مش لازم الـ Composition يبقى object جوة object بشكل مباشر.

المعيار الحقيقي:

المركّب (Book) هو اللي بيخلق المكوّن (Author) وهو اللي بيقتله.

وده اللي حاصل هنا:

Book هو اللي عمل new Author

Book هو اللي هيعمل delete Author

يعني:

عمر الـ Author = عمر الـ Book

وده هو تعريف الـ Composition.

يبقى Pointer أو Object مباشر مش فارق…

الفارق الحقيقي هو:

✔ مين بيعمل new
✔ مين بيعمل delete
✔ هل المكوّن يعيش لو المركّب مات؟

هنا لأ → يبقى Composition.
*/
