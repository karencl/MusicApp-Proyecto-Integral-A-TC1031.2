/*
 * Proyecto MusicApp
 * Karen Cebreros López
 * A01704254
 * 8/09/2021
 *
 * main.cpp
 * MusicApp
 * Created by Karen CL on 8/09/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * Descripción:
 * Este es un proyecto para la clase de "Programación de estructuras de datos y
 * algoritmos fundamentales".
 * Es un programa que simula el funcionamiento de una aplicación de música,
 * a través del manejo de una playlist y sus canciones.
 * Tiene como objetivo aprender sobre las estructuras de datos lineares, árboles,
 * algoritmos de búsqueda y ordenamientos.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

#include "Song.h"
#include "DLinkedList.h"
#include "SortAndSearch.h"
using namespace std;

void showMenu();
void printSong(Song*);

int main() {
    
    /*
     * Opens the csv file. *Careful with the path, in case you move the document
     * from folder or so.*
     */
    ifstream
    file("/Users/karencbrs/Documents/Xcode_projects/MusicApp/MusicApp/songs.csv");
    
    if (!file.is_open()) {
        cout << "There was an error opening the file." << endl;
        return 1;
    } else {
        string skip;
        getline(file, skip, '\n');
    }
    
    // Sort y DLinkedList objects
    DLinkedList list;
    SortOrSearch s;
    
    // Get data from the file and store it in the list
    list.getData(file);
    
    // Get the "Head" and "Tail" of the list
    Song *h = list.getHead();
    Song *t = list.getTail();
    
    // Menu
    int option = 1;
    while (option != 5) {
        showMenu();
        cout << "Ingresa opción: ";
        cin >> option;
        cout << endl;
        
        // Show playlist from beginning to end
        if (option == 1) {
            list.showListForward();
        }
        
        // Show playlist from end to beginning
        else if (option == 2) {
            list.showListBackwards();
        }
        
        // Search a song
        else if (option == 3) {
            cout << "NOTA: Si hay más de una canción con el mismo autor o nombre";
            cout << ", saldrá la primera que se encuentre en la lista.\n" << endl;
            
            int attribute;
            cout << "Elige el atributo por como quieres buscar..." << endl;
            cout << "Por nombre (1) o autor (2): ";
            cin >> attribute;
            cout << endl;
            
            if (attribute == 1 || attribute == 2) {
                string busca;
                cout << "Ingresa lo que quieres buscar..." << endl;
                cout << "* Toma en cuenta mayúsculas y minúsculas y espacios *: ";
                cin.ignore();
                getline(cin, busca);
                cout << endl;
                
                Song *aux = s.sequentialSearch(h, t, busca, attribute);
                printSong(aux);
            } else {
                cout << "¡Error! Atributo no encontrado." << endl;
            }
        }
        
        // Sort playlist
        else if (option == 4) {
            int attribute;
            cout << "Elige el atributo por como quieres ordenar..." << endl;
            cout << "Por nombre (1) o autor (2): ";
            cin >> attribute;
            cout << endl;
            
            if (attribute == 1 || attribute == 2) {
                s.quickSort(h, t, attribute);
                cout << "¡Listo! La lista ha quedado ordenada." << endl;
            } else {
                cout << "¡Error! Atributo no encontrado.\n" << endl;
            }
        }
        
        // Exit the cycle and end program
        else if (option == 5) {
            cout << "Hasta pronto!" << endl;
        }
        
        // Error message for option not found
        else {
            cout << "¡Error! Opción no disponible." << endl;
        }
    }
    
    file.close();
    return 0;
}

/*
 * @param
 * @return
 *
 * Shows the menu
 *
 */
void showMenu() {
    cout << endl;
    cout << "· · · · · · · · MENÚ · · · · · · · ·" << endl;
    cout << "1) Muestra playlist de principio a fin" << endl;
    cout << "2) Muestra playlist de fin a principio" << endl;
    cout << "3) Busca canción" << endl;
    cout << "4) Ordena playlist" << endl;
    cout << "5) Salir" << endl;
    cout << endl;
}

/*
 * @param
 * @return Song*
 *
 * Prints the data of one song
 *
 */
void printSong(Song* s) {
    int min = s->duration / 60;
    int sec = s->duration % 60;
    
    cout << "- - - - - - - - - - - - - -" << endl;
    cout << "Song: " << s->name << endl;
    cout << "Author: " << s->author << endl;
    cout << "Duration: " << min << ":" << sec << endl;
    cout << "- - - - - - - - - - - - - -" << endl;
}
