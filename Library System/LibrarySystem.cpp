//
// Created by 90552 on 1.12.2020.
//

#include <iostream>
#include "LibrarySystem.h"

using namespace std;


LibrarySystem::LibrarySystem(){
    head = NULL;
}

void LibrarySystem::addMovie(int movieId, string movieTitle,int movieYear) {
    // create a new node to save the value
    Node *newNode = new Node;

    //update the value
    newNode->id = movieId;
    newNode->title = movieTitle;
    newNode->year = movieYear;


    if(head == NULL)
    {
        //if the head is null
        //assign the prev to newNode
        newNode->prev = newNode;
        //assign newNode as head node
        head = newNode;
        //assign next to head node
        newNode->next=head;

    }
    else
    {
        //if the head is not null
        // take a temp node to go to last node
        Node* temp = head->prev;
        //assign the newNode as last node
        head->prev = newNode;
        //assign the newNode to temp node
        newNode->prev = temp;
        //assign the next of newNode to head node making it as last node
        newNode->next = head;
        //assign next node of temp node to new node.
        temp->next = newNode;

    }

}
void LibrarySystem::deleteMovie(int movieId) {
    if(head == NULL)
    {
        printf("\nList is Empty.\n");
        return;
    }
    else
    {
        if(head->id == movieId)
        {
            //if the head value is equal to element to be deleted
            if(head->next == head)
            {
                //if there is only 1 element
                head=NULL;
            }
            else
            {
                Node* temp = head->prev;
                head = head->next;
                head->prev = temp;
                temp->next = head;
            }
            return;
        }
        Node* temp = head->next;
        while(temp != head && temp->id != movieId)
        {
            temp = temp->next;
        }
        if(temp == head)
        {
            printf("Value not found in list\n");
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}
void LibrarySystem::addUser(int userId, string userName) {
    Node *newNode = new Node;

    //update the value
    newNode->userid = userId;
    newNode->username = userName;

    if(head == NULL)
    {
        //if the head is null
        //assign the prev to newNode
        newNode->prev = newNode;
        //assign newNode as head node
        head = newNode;
        //assign next to head node
        newNode->next=head;

    }
    else
    {
        //if the head is not null
        // take a temp node to go to last node
        Node* temp = head->prev;
        //assign the newNode as last node
        head->prev = newNode;
        //assign the newNode to temp node
        newNode->prev = temp;
        //assign the next of newNode to head node making it as last node
        newNode->next = head;
        //assign next node of temp node to new node.
        temp->next = newNode;

    }
}
void LibrarySystem::deleteUser(int userId) {
    if(head == NULL)
    {
        printf("\nList is Empty.\n");
        return;
    }
    else
    {
        if(head->userid == userId)
        {
            //if the head value is equal to element to be deleted
            if(head->next == head)
            {
                //if there is only 1 element
                head=NULL;
            }
            else
            {
                Node* temp = head->prev;
                head = head->next;
                head->prev = temp;
                temp->next = head;
            }
            return;
        }
        Node* temp = head->next;
        while(temp != head && temp->userid != userId)
        {
            temp = temp->next;
        }
        if(temp == head)
        {
            printf("Value not found in list\n");
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}
void LibrarySystem::checkoutMovie(int movieId, int userId) {
    // create a new node to save the value
    Node *newNode = new Node;

    //update the value
    newNode->id = movieId;
    newNode->userid = userId;


    if(head == NULL)
    {
        //if the head is null
        //assign the prev to newNode
        newNode->prev = newNode;
        //assign newNode as head node
        head = newNode;
        //assign next to head node
        newNode->next=head;

    }
    else
    {
        //if the head is not null
        // take a temp node to go to last node
        Node* temp = head->prev;
        //assign the newNode as last node
        head->prev = newNode;
        //assign the newNode to temp node
        newNode->prev = temp;
        //assign the next of newNode to head node making it as last node
        newNode->next = head;
        //assign next node of temp node to new node.
        temp->next = newNode;

    }
}
void LibrarySystem::returnMovie(const int movieId) {
    if(head == NULL)
    {
        printf("\nList is Empty.\n");
        return;
    }
    else
    {
        if(head->id == movieId)
        {
            //if the head value is equal to element to be deleted
            if(head->next == head)
            {
                //if there is only 1 element
                head=NULL;
            }
            else
            {
                Node* temp = head->prev;
                head = head->next;
                head->prev = temp;
                temp->next = head;
            }
            return;
        }
        Node* temp = head->next;
        while(temp != head && temp->id != movieId)
        {
            temp = temp->next;
        }
        if(temp == head)
        {
            printf("Value not found in list\n");
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}
void LibrarySystem::showAllMovies() {
    Node *temp = head;

    do
    {

        cout<< temp->id<<" ";
        cout<< temp->title<<" ";
        cout<< temp->year;
        cout << endl;
        temp = temp->next;
    }while(temp != head);


}
void LibrarySystem::showMovie(const int movieId) {
    Node *temp = head;
    int found = 0;

    do
    {
        if(temp->id == movieId)
        {
            cout<< temp->id<<" ";
            cout<< temp->title<<" ";
            cout<< temp->year;
            //cout << endl;
            found = 1;
            break;
        }
        temp = temp->next;
    }while(temp != head);

    if(found == 0)
    {
        cout<<"Movie with the id " ;
        cout<< movieId ;
        cout<<" does not exist"<<endl;
    }
}
void LibrarySystem::showUser(const int userId) {
    Node *temp = head;
    int found = 0;

    do
    {
        if(temp->userid == userId)
        {
            cout<<"User id: ";
            cout<< temp->userid<<" ";
            cout<<"User name: ";
            cout<< temp->username;
            cout << endl;
            cout<<"User ";
            cout<< temp->userid<<" ";
            cout<<"checked out the following Movies:"<<endl;


            found = 1;
            break;
        }
        temp = temp->next;
    }while(temp != head);

    if(found == 0)
    {
        cout<<"User" ;
        cout<< userId ;
        cout<<" does not exist in the system"<<endl;
    }
}

void LibrarySystem::remove(string x) {
    if(head == NULL)
    {
        cout<<"";;
        return;
    }
    else
    {
        if(head->title == x)
        {
            //if the head value is equal to element to be deleted
            if(head->next == head)
            {
                //if there is only 1 element
                head=NULL;
            }
            else
            {
                Node* temp = head->prev;
                head = head->next;
                head->prev = temp;
                temp->next = head;
            }
            return;
        }
        Node* temp = head->next;
        while(temp != head && temp->title != x)
        {
            temp = temp->next;
        }
        if(temp == head)
        {
            cout<<"";
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}
int LibrarySystem::searchM(int x) {
    Node *temp = head;
    int found = 0;

    if(head == NULL)
    {
        cout<<"";

    }
    else {

        do {
            if (temp->id == x) {
                found++;
                //cout << "found"<<endl;


                //break;
            }
            temp = temp->next;
        } while (temp != head);
    }
    if(found == 0)
    {
        return 0;
    }
    return found;
}
int LibrarySystem::searchU(int x) {
    Node *temp = head;
    int found = 0;
    if(head == NULL)
    {
        cout<<"";

    }
    else {
        do {
            if (temp->userid == x) {
                found++;
                //cout << "found"<<endl;


                //break;
            }
            temp = temp->next;
        } while (temp != head);
    }
    if(found == 0)
    {
        return 0;
    }
    return found;
}

void LibrarySystem::display() {
    Node *temp = head;

    do
    {
        cout<< temp->id<<" ";
        cout<< temp->title<<" ";
        cout<< temp->year;
        cout << endl;
        temp = temp->next;
    }while(temp != head);


}

void LibrarySystem::userDisplay() {
    Node *temp = head;

    do
    {
        cout<< temp->id<<" ";
        cout<< temp->userid;

        cout << endl;
        temp = temp->next;
    }while(temp != head);


}