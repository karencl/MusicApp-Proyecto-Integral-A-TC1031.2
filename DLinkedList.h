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
#include <iostream>
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
        void addSong(string, string, int, int);
        bool deleteSong(int);
        void clearList();
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
        int i = 1;
        while (current) {
            int min = current->duration / 60;
            int sec = current->duration % 60;
            
            cout << i << " - - - - - - - - - - - - - -" << endl;
            cout << "Song: " << current->name << endl;
            cout << "Author: " << current->author << endl;
            cout << "Duration: " << min << ":" << sec << endl;
            cout << endl;
            current = current->next;
            
            i++;
        }
        cout << "- - - - - - - - - - - - - -" << endl;
    } else {
        cout << "La lista está vacía." << endl;
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
        int i = 1;
        while (current) {
            int min = current->duration / 60;
            int sec = current->duration % 60;
            
            cout << i << " - - - - - - - - - - - - - -" << endl;
            cout << "Song: " << current->name << endl;
            cout << "Author: " << current->author << endl;
            cout << "Duration: " << min << ":" << sec << endl;
            cout << endl;
            current = current->previous;
            
            i++;
        }
        cout << "- - - - - - - - - - - - - -" << endl;
    } else {
        cout << "La lista está vacía." << endl;
    }
}

/*
 * @param string, string, int, int
 * @return
 *
 * A new song gets added to the end of the list using tail.
 *
 */
void DLinkedList::addSong(string _name, string _author, int dur_min, int dur_sec){
    Song *new_song = new Song();
    new_song->name = _name;
    new_song->author = _author;
    new_song->duration = (dur_min*60) + dur_sec;
    
    if (!head) {
        head = new_song;
        tail = new_song;
    } else {
        tail->next = new_song;
        new_song->previous = tail;
        tail = new_song;
    }
}

/*
 * @param int
 * @return bool
 *
 * A new song gets removed from the list and deleted, using it's index in it.
 *
 */
bool DLinkedList::deleteSong(int pos) {
    Song *aux = head;
    bool removed = false;
    
    if (!aux) {
        cout << "\nLa lista está vacía." << endl;
        return removed;
    } else {
        Song *song_to_be_removed = head;
        if (pos == 0) {
            head = head->next;
            head->previous = NULL;
            delete song_to_be_removed;
            
            removed = true;
            return removed;
        } else {
            Song *aux1 = head;
            Song *aux2 = aux1->next;
            int pos_check = 1;
            
            while (aux2) {
                if (pos_check == pos) {
                    song_to_be_removed = aux2;
                    
                    if (aux2 == tail) {
                        aux1->next = NULL;
                        tail = aux1;
                    } else {
                        aux1->next = aux2->next;
                        aux2->next->previous = aux1;
                    }
                    
                    delete song_to_be_removed;
                    removed = true;
                    return removed;
                }
                pos_check++;
                aux1 = aux1->next;
                aux2 = aux2->next;
            }
        }
    }
    
    cout << "\nCanción no encontrada." << endl;
    return removed;
}

/*
 * @param
 * @return
 *
 * Clears the playlist.
 * (All songs are removed and deleted from it).
 *
 */
void DLinkedList::clearList() {
    Song *aux1 = new Song();
    Song *aux2 = new Song();
    
    while (aux1) {
        aux2 = aux1->next;
        delete aux1;
        aux1 = aux2;
    }
    
    head = NULL;
    tail = NULL;
}

#endif /* DLinkedList_h */
