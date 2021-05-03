#include <iostream>
#include <fstream>
#include <sstream>
#include "LibrarySystem.h"
using namespace std;

int main(int argc, char *argv[]) {

    freopen(argv[2],"w",stdout);

    LibrarySystem ls;
    LibrarySystem userList;
    LibrarySystem checkList;

    string line;
    string test = "";
    cout<<"===Movie Library System==="<<endl;
    ifstream Commands(argv[1]);

    while (getline(Commands, line)) {



        std::string delimiter = "\t";
        string split[4];
        size_t pos = 0;
        string token;
        int a = 0;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            split[a] = token;
            line.erase(0, pos + delimiter.length());
            a++;
        }
        split[a] = line;

        if(split[0] != test){
            cout<<endl;
            cout<<"==="+split[0]+"() method test==="<<endl;
            test = split[0];
        }

        if (split[0] == "addMovie"){
            stringstream y(split[1]);
            int x = 0;
            y >> x;

            stringstream a(split[3]);
            int b = 0;
            a >> b;

            ls.addMovie(x, split[2], b);
            if (ls.searchM(x) >1){
                ls.remove(split[2]);
                cout<<"Movie ";
                cout<< x;
                cout<<" already exists"<<endl;
            }
            else{
                cout<<"Movie ";
                cout<< x;
                cout<<" has been added"<<endl;
            }
        }
        if (split[0] == "deleteMovie") {
            stringstream y(split[1]);
            int x = 0;
            y >> x;
            if (ls.searchM(x) ==0){
                cout<<"Movie "+ split[1]+ " does not exist"<<endl;
            }
            else if (checkList.searchM(x)!=1 && ls.searchM(x)==1){
                cout<<"Movie "+ split[1]+ " has not been checked out"<<endl;
                cout<<"Movie "+ split[1]+ " has been deleted"<<endl;

                ls.deleteMovie(x);
            }
            else if (checkList.searchM(x)==1){
                cout<<"Movie "+ split[1]+ " has been checked out"<<endl;
                cout<<"Movie "+ split[1]+ " has been deleted"<<endl;

                checkList.deleteMovie(x);
                ls.deleteMovie(x);
            }



        }
        if (split[0] == "addUser") {
            stringstream y(split[1]);
            int x = 0;
            y >> x;

            userList.addUser(x, split[2]);
            if (userList.searchU(x) >1){
                userList.deleteUser(x);
                cout<<"User ";
                cout<< x;
                cout<<" already exists"<<endl;
            }
            else{
                cout<<"User ";
                cout<< x;
                cout<<" has been added"<<endl;
            }
            //userList.userDisplay();
        }
        if (split[0] == "deleteUser") {
            stringstream y(split[1]);
            int x = 0;
            y >> x;
            //userList.userDisplay();
            if (userList.searchU(x)==0) {
                cout<<"User "+split[1]+ " does not exist"<<endl;


            }
            if(userList.searchU(x)>=1){
                userList.deleteUser(x);
                cout<<"User "+split[1]+ " has been deleted"<<endl;
            }
        }
        if (split[0] == "checkoutMovie") {
            stringstream y(split[1]);
            int x = 0;
            y >> x;
            stringstream a(split[2]);
            int b = 0;
            a >> b;
            if (ls.searchM(x) !=1 || checkList.searchM(x)==1){
                cout << "Movie " + split[1] + " does not exist for checkout" <<endl;

            }
            else if (userList.searchU(b) != 1){
                cout << "User " + split[2] + " does not exist for checkout" <<endl;
            }else {
                checkList.checkoutMovie(x,b);
                cout << "Movie " + split[1] + " has been checked out by User "+ split[2] <<endl;
            }

        }
        if (split[0] == "returnMovie"){
            stringstream y(split[1]);
            int x = 0;
            y >> x;

            if (ls.searchM(x) ==1 ){
                if (checkList.searchM(x) ==1){
                    checkList.returnMovie(x);
                    cout << "Movie " + split[1] + " has been returned" <<endl;
                }
                else{
                    cout << "Movie "+ split[1] + " has not been checked out" <<endl;
                }

            }
            else{
                cout << "Movie " + split[1] + " not exist in the library" <<endl;
            }
        }
        if (split[0] == "showAllMovie"){
            cout << "Movie id - Movie name - Year - Status" <<endl;
            ls.showAllMovies();

        }
        if (split[0] == "showMovie"){
            stringstream y(split[1]);
            int x = 0;
            y >> x;
            ls.showMovie(x);
            if (checkList.searchM(x)==1){
                cout<<" Checked out by User "<<endl;
            }
            if (checkList.searchM(x)!=1 && ls.searchM(x)==1){
                cout<<" Not checked out "<<endl;
            }
        }
        if (split[0] == "showUser"){
            stringstream y(split[1]);
            int x = 0;
            y >> x;
            userList.showUser(x);
            if (checkList.searchU(x) ==1){
                cout<<"Movie id - Movie name - Year"<<endl;
            }
        }




    }



}
