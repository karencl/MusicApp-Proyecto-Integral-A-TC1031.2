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
    
    ifstream
    file("songs.csv");
    
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
    while (option != 8) {
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
        
        // Add song
        else if (option == 4) {
            cout << "Ingresa los datos de la nueva canción..." << endl;
            string name, author;
            int duration_mins, duration_secs;
            
            cout << "Nombre de la canción: ";
            cin.ignore();
            getline(cin, name);
            cout << "Autor de la canción: ";
            getline(cin, author);
            cout << "Duración (solo los minutos): ";
            cin >> duration_mins;
            cout << "Duración (solo los segundos): ";
            cin >> duration_secs;
            
            list.addSong(name, author, duration_mins, duration_secs);
            cout << "\n¡Se agregó una nueva canción a la lista!" << endl;
            
            h = list.getHead();
            t = list.getTail();
        }
        
        // Delete song
        else if (option == 5) {
            list.showListForward();
            
            int song_pos;
            cout << "Ingresa el número de la canción a eliminar..." << endl;
            cin >> song_pos;
            
            bool result = list.deleteSong(song_pos-1);
            if (result)
                cout << "\nCanción eliminada exitosamente." << endl;
            else
                cout << "Error al eliminar la canción." << endl;
            
            h = list.getHead();
            t = list.getTail();
        }
        
        // Sort playlist
        else if (option == 6) {
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
        
        // Clear playlist
        else if (option == 7) {
            list.clearList();
            
            cout << "\nSe ha vaciado por completo la lista." << endl;
        }
        
        // Exit the cycle and end program
        else if (option == 8) {
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
    cout << "4) Agrega canción" << endl;
    cout << "5) Elimina canción" << endl;
    cout << "6) Ordena playlist" << endl;
    cout << "7) Vaciar playlist" << endl;
    cout << "8) Salir" << endl;
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
