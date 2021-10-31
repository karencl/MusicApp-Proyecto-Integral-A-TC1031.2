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
#include <algorithm>

#include "Song.h"
#include "DLinkedList.h"
#include "SortAndSearch.h"
#include "SplayTree.h"
using namespace std;

void showMenu();
void printSong(Song*);

int main() {
    
    ifstream file("songs.csv");
    
    string skip;
    if (!file.is_open()) {
        cout << "Hubo un error al abrir el archivo." << endl;
        return 1;
    } else {
        getline(file, skip, '\n');
    }
    
    // Objetos de Sort, DLinkedList y SplayTree.
    DLinkedList list;
    SortOrSearch s;
    SplayTree splayt;
    
    // Obtiene los datos del archivo y se guardan en la lista y en el árbol.
    list.getData(file);
    file.clear();
    file.seekg(0, ios::beg);
    getline(file, skip, '\n');
    splayt.fillTree(file);
    
    // Getters de "Head" y "Tail" de la lista doblemente enlazada
    Song *h = list.getHead();
    Song *t = list.getTail();
    
    cout<<"Antes de iniciar, se puede observar el archivo 'songs.csv',\n";
    cout<<"para apreciar el antes y después de que este sea modificado." << endl;
    
    cout<<"\nEl archivo original de las canciones se encuentra en otro archivo\n";
    cout<<"de texto aparte, en caso de que se quieran correr las pruebas desde\n";
    cout<<"un inicio. (Si no, simplemente se van a agregar las mismas canciones";
    cout<<"\nuna y otra vez a éste)."<<endl;
    
    // Menú
    int option = 1;
    while (option != 10) {
        showMenu();
        cout << "Ingresa opción: ";
        cin >> option;
        cout << endl;
        
        // Muestra playlist de principio a fin (usando la lista)
        if (option == 1) {
            list.showListForward();
        }
        
        // Muestra playlist de fin a principio (usando la lista)
        else if (option == 2) {
            list.showListBackwards();
        }
        
        // Busca una canción (por nombre o autor)
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
                cout << "* Toma en cuenta los espacios *: ";
                cin.ignore();
                getline(cin, busca);
                cout << endl;
                
                transform(busca.begin(), busca.end(), busca.begin(), ::tolower);
                
                Song *aux = s.sequentialSearch(h, t, busca, attribute);
                printSong(aux);
            } else {
                cout << "¡Error! Atributo no encontrado." << endl;
            }
        }
        
        // Agrega una canción (tanto a la lista, como al árbol)
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
            
            int total_dur = (duration_mins*60) + duration_secs;
            
            list.addSong(name, author, duration_mins, duration_secs);
            splayt.add(total_dur);
            cout << "\n¡Se agregó una nueva canción a la lista!" << endl;
            
            h = list.getHead();
            t = list.getTail();
        }
        
        // Elimina una canción (tanto de la lista, como del árbol)
        else if (option == 5) {
            list.showListForward();
            
            int song_pos, dur_to_remove_in_tree = 0;
            cout << "Ingresa el número de la canción a eliminar..." << endl;
            cin >> song_pos;
            
            bool result = list.deleteSong(song_pos-1, dur_to_remove_in_tree);
            if (result) {
                cout << "\nCanción eliminada exitosamente." << endl;
                if (dur_to_remove_in_tree != 0)
                    splayt.remove(dur_to_remove_in_tree);
            } else
                cout << "Error al eliminar la canción." << endl;
            
            h = list.getHead();
            t = list.getTail();
        }
        
        // Ordena la playlist (por nombre o autor)
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
        
        // Obtiene la duración total en minutos y segundos (usando el árbol)
        else if (option == 7) {
            int pl_duration = 0;
            cout << "La duración total de la playlist es:" << endl;
            
            pl_duration = splayt.playlistDuration();
            cout << pl_duration / 60 << " minutos con ";
            cout << pl_duration % 60 << " segundos" << endl;
        }
        
        // Obtiene el tamaño o número de canciones (usando el árbol)
        else if (option == 8) {
            cout << "El tamaño de la playlist es:" << endl;
            cout << splayt.size() << " canciones" << endl;
        }
        
        // Vacía tanto la lista como el árbol
        else if (option == 9) {
            list.clearList();
            splayt.clearTree();
            cout << "\nSe ha vaciado por completo la lista." << endl;
        }
        
        // Sale del "while", actualiza el archivo .csv y termina el programa
        else if (option == 10) {
            fstream new_file;
            new_file.open("new_songs.csv", ios::out);
            
            list.writeData(new_file);
            
            file.close();
            new_file.close();
            
            remove("songs.csv");
            rename("new_songs.csv", "songs.csv");
            
            cout << "Hasta pronto!" << endl;
        }
        
        // Error -> opción no válida
        else {
            cout << "¡Error! Opción no disponible." << endl;
        }
    }

    return 0;
}

/*
 * @param
 * @return
 *
 * Muestra el menú
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
    cout << "7) Obtén la duración total de la playlist" << endl;
    cout << "8) Obtén el tamaño de la playlist" << endl;
    cout << "9) Vaciar playlist" << endl;
    cout << "10) Salir" << endl;
    cout << endl;
}

/*
 * @param
 * @return Song*
 *
 * Imprime los datos de una canción en específico
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
