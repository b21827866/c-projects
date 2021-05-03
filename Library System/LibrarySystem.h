
#ifndef ASS2_LIBRARYSYSTEM_H
#define ASS2_LIBRARYSYSTEM_H
using namespace std;
class LibrarySystem{
private:
    struct Node
    {
        int id;
        string title;
        int year;
        int userid;
        string username;

        Node *prev;
        Node *next;
    };

    Node *head;
public:
    LibrarySystem();
    void addMovie(const int movieId,const string movieTitle,const int movieYear);
    void deleteMovie(const int movieId);

    void addUser(const int userId,const string userName);
    void deleteUser(const int userId);

    void checkoutMovie(const int movieId,const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);

    void remove(string x);
    int searchM(int x);
    int searchU(int x);
    void display();
    void userDisplay();

};


#endif //ASS2_LIBRARYSYSTEM_H

