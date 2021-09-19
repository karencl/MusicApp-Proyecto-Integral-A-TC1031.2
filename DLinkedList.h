/*
 * Proyecto MusicApp
 * Karen Cebreros López
 * A01704254
 * 8/09/2021
 *
 * DLinkedList.h
 * MusicApp
 * Created by Karen CL on 8/09/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * La clase DLinkedList contiene como atributos dos canciones, que representan el
 * inicio y el final de la lista, con el objetivo de siempre saber cuál es la que
 * está primero y cuál es la que está al final.
 * Así mismo, contiene los getters para estos y algunos métodos que permiten
 * llenar la lista y recorrerla (hasta el momento).
 */

#ifndef DLinkedList_h
#define DLinkedList_h

#include <fstream>
using namespace std;

// DLinkedList class
class DLinkedList {
    private:
        // Private attributes
        Song *head;
        Song *tail;
    public:
        // Constructor
        DLinkedList(): head(NULL), tail(NULL){};
    
        // Getters
        Song* getHead();
        Song* getTail();
    
        // Public methods
        void getData(ifstream&);
        void showListForward();
        void showListBackwards();
};

/*
 * @param
 * @return Song*
 *
 * Getter of the head of the list
 *
 */
Song* DLinkedList::getHead() {
    return head;
}

/*
 * @param
 * @return Song*
 *
 * Getter of the tail of the list
 *
 */
Song* DLinkedList::getTail() {
    return tail;
}

/*
 * @param ifstream&
 * @return
 *
 * Creates the list using the data from the "songs.csv" file.
 * Each line is read and new Songs are created with the three attributes in each
 * line: name, author and duration (in seconds).
 *
 */
void DLinkedList::getData(ifstream &file) {
    while (!file.eof()) {
        Song *new_song = new Song();
        
        getline(file, new_song->name, ',');
        if (new_song->name.length() == 0)
            break;
        
        getline(file, new_song->author, ',');
        
        string duration;
        getline(file, duration, '\n');
        new_song->duration = atoi(duration.c_str());
        
        if (!head) {
            head = new_song;
            new_song->previous = NULL;
            new_song->next = NULL;
            tail = new_song;
        } else {
            tail->next = new_song;
            new_song->previous = tail;
            new_song->next = NULL;
            tail = new_song;
        }
    }
    
}

/*
 * @param
 * @return
 *
 * Shows the list from beginning to end, using a helper song: "current", that
 * keeps moving forward until it gets to NULL.
 *
 */
void DLinkedList::showListForward() {
    Song *current = new Song();
    
    current = head;
    
    if (head) {
        while (current) {
            int min = current->duration / 60;
            int sec = current->duration % 60;
            
            cout << "- - - - - - - - - - - - - -" << endl;
            cout << "Song: " << current->name << endl;
            cout << "Author: " << current->author << endl;
            cout << "Duration: " << min << ":" << sec << endl;
            cout << endl;
            current = current->next;
        }
        cout << "- - - - - - - - - - - - - -" << endl;
    } else {
        cout << "The list is empty." << endl;
    }
}

/*
 * @param
 * @return
 *
 * Shows the list from end to beginning, using a helper song: "current", that
 * keeps moving backwards until it gets to NULL.
 *
 */
void DLinkedList::showListBackwards() {
    Song *current = new Song();
    
    current = tail;
    
    if (head) {
        while (current) {
            int min = current->duration / 60;
            int sec = current->duration % 60;
            
            cout << "- - - - - - - - - - - - - -" << endl;
            cout << "Song: " << current->name << endl;
            cout << "Author: " << current->author << endl;
            cout << "Duration: " << min << ":" << sec << endl;
            cout << endl;
            current = current->previous;
        }
        cout << "- - - - - - - - - - - - - -" << endl;
    } else {
        cout << "The list is empty." << endl;
    }
}

#endif /* DLinkedList_h */
