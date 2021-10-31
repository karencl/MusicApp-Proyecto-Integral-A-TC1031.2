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
#include <sstream>
using namespace std;

// DLinkedList class
class DLinkedList {
    private:
        // Atributos privados
        Song *head;
        Song *tail;
    public:
        // Constructor
        DLinkedList(): head(NULL), tail(NULL){};
    
        // Getters
        Song* getHead();
        Song* getTail();
    
        // Métodos públicos
        void getData(ifstream&);
        void showListForward();
        void showListBackwards();
        void addSong(string, string, int, int);
        bool deleteSong(int, int&);
        void clearList();
        void writeData(fstream&);
};

/*
 * @param
 * @return Song*
 *
 * Getter de "head" (el principio de la lista)
 *
 */
Song* DLinkedList::getHead() {
    return head;
}

/*
 * @param
 * @return Song*
 *
 * Getter de "tail" (el final de la lista)
 *
 */
Song* DLinkedList::getTail() {
    return tail;
}

/*
 * @param ifstream&
 * @return
 *
 * Crea la lista usando los datos del archivo "songs.csv".
 * Se lee cada línea, creando en cada vuelta una canción, con sus respectivos
 * atributos (nombre, autor y la duración en segundos).
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
 * Imprime la lista de principio a fin, usando un auxiliar "current", que se va
 * moviendo a través de la lista, hasta que sea NULL.
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
 * Imprime la lista de fin a principio, usando un auxiliar "current", que se va
 * moviendo a través de la lista, hasta que sea NULL.
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
 * Se agrega una canción al final de la lista, usando "tail".
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
 * Se remueve y elimina una canción de la lista, a través del index que es pasado.
 *
 */
bool DLinkedList::deleteSong(int pos, int &removed_song_duration) {
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
            removed_song_duration = song_to_be_removed->duration;
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
                    
                    removed_song_duration = song_to_be_removed->duration;
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
 * Se vacía la lista.
 * (Todas las canciones son removidad y eliminadas).
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

/*
 * @param ifstream&
 * @return
 *
 * Se llena un nuevo archivo de canciones, con los datos de la lista doblemente
 * enlazada, con el fin de tener nuestro archivo "songs.csv" actualizado al
 * término del programa.
 *
 */
void DLinkedList::writeData(fstream &new_file) {
    Song *aux = head;

    new_file << "name,author,duration\n";
    
    while (aux) {
        stringstream aux_string;
        
        aux_string << aux->name << "," << aux->author << ",";
        aux_string << to_string(aux->duration) + "\n";
        
        new_file << aux_string.str();
       
        aux = aux->next;
    }
}

#endif /* DLinkedList_h */
