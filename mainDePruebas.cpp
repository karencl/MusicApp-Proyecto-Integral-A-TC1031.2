/*
 * Proyecto MusicApp
 * Karen Cebreros López
 * A01704254
 * 8/09/2021
 *
 * mainDePruebas.cpp
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
    
    cout<<"Antes de iniciar con las pruebas, se puede observar el archivo\n";
    cout<<"'songs.csv', para apreciar el antes y después de que este sea ";
    cout<<"modificado."<<endl;
    
    cout<<"\nEl archivo original de las canciones se encuentra en otro archivo\n";
    cout<<"de texto aparte, en caso de que se quieran correr las pruebas desde\n";
    cout<<"un inicio. (Si no, simplemente se van a agregar las mismas canciones";
    cout<<"\nuna y otra vez a éste)."<<endl;
    
    cout << "\n\nº º º º º º º º º º º º º º º º º º º º º º º º º º º\n" << endl;
    
    // Print the list back and forward
    cout << "PRUEBA DE IMPRESIÓN... \n \tDe adelante hacia atrás: \n" << endl;
    list.showListForward();
    cout << "PRUEBA DE IMPRESIÓN 2... \n \tDe atrás hacia adelante: \n" << endl;
    list.showListBackwards();
    
    cout << "\n\nº º º º º º º º º º º º º º º º º º º º º º º º º º º\n" << endl;
    
    cout << "\nPRUEBA DE MODIFICACIÓN..." << endl;
    cout << "\n\tAgregando canción *Hear Me Now - Alok - 3:14*" << endl;
    int dur_to_remove_in_tree = 0, pl_duration;
    list.addSong("Hear Me Now", "Alok", 3, 14);
    splayt.add(194);
    h = list.getHead();
    t = list.getTail();
    cout << "\tDuración total de la playlist: ";
    pl_duration = splayt.playlistDuration();
    cout << pl_duration / 60 << " minutos con ";
    cout << pl_duration % 60 << " segundos" << endl;
    cout<<"\tEl tamaño de la playlist es: "<<splayt.size()<<" canciones"<<endl;
    
    cout << "\n\tEliminando canción *Ill Be Back - Sam Feldt - 2:37*" << endl;
    list.deleteSong(4, dur_to_remove_in_tree);
    if (dur_to_remove_in_tree)
        splayt.remove(dur_to_remove_in_tree);
    h = list.getHead();
    t = list.getTail();
    cout << "\tDuración total de la playlist: ";
    pl_duration = splayt.playlistDuration();
    cout << pl_duration / 60 << " minutos con ";
    cout << pl_duration % 60 << " segundos" << endl;
    cout<<"\tEl tamaño de la playlist es: "<<splayt.size()<<" canciones"<<endl;
    
    cout << "\n\tAgregando canción *Wasted Love - Ofenbach - 2:19*" << endl;
    list.addSong("Wasted Love", "Ofenbach", 2, 19);
    splayt.add(139);
    h = list.getHead();
    t = list.getTail();
    cout << "\tDuración total de la playlist: ";
    pl_duration = splayt.playlistDuration();
    cout << pl_duration / 60 << " minutos con ";
    cout << pl_duration % 60 << " segundos" << endl;
    cout<<"\tEl tamaño de la playlist es: "<<splayt.size()<<" canciones"<<endl;
    
    cout << "\n\tAgregando canción *Broken - Bjonr - 2:56*" << endl;
    list.addSong("Broken", "Bjonr", 2, 56);
    splayt.add(176);
    h = list.getHead();
    t = list.getTail();
    cout << "\tDuración total de la playlist: ";
    pl_duration = splayt.playlistDuration();
    cout << pl_duration / 60 << " minutos con ";
    cout << pl_duration % 60 << " segundos" << endl;
    cout<<"\tEl tamaño de la playlist es: "<<splayt.size()<<" canciones"<<endl;
    
    cout << "\n\tEliminando canción *Go Solo - Zwette - 3:12*" << endl;
    list.deleteSong(5, dur_to_remove_in_tree);
    if (dur_to_remove_in_tree)
        splayt.remove(dur_to_remove_in_tree);
    h = list.getHead();
    t = list.getTail();
    cout << "\tDuración total de la playlist: ";
    pl_duration = splayt.playlistDuration();
    cout << pl_duration / 60 << " minutos con ";
    cout << pl_duration % 60 << " segundos" << endl;
    cout<<"\tEl tamaño de la playlist es: "<<splayt.size()<<" canciones"<<endl;
    
    cout << "\n\nMostrando lista de adelante hacia atrás..." << endl;
    list.showListForward();
    
    cout << "\n\nº º º º º º º º º º º º º º º º º º º º º º º º º º º\n" << endl;
    
    cout << "\nPRUEBA DE ORDENAMIENTO... \n \tPor nombre:\n" << endl;
    s.quickSort(h, t, 1);
    list.showListForward();
    cout << "\nPRUEBA DE ORDENAMIENTO... \n \tPor autor:\n" << endl;
    s.quickSort(h, t, 2);
    list.showListForward();
    
    cout << "\n\nº º º º º º º º º º º º º º º º º º º º º º º º º º º\n" << endl;
    
    cout << "PRUEBA DE BÚSQUEDAS... \n\tPor nombre:\n" << endl;
    cout << "\tBuscando canción *Garden - Jervis Campbell - 3:16* " << endl;
    Song *aux = s.sequentialSearch(h, t, "Garden",  1);
    printSong(aux);
    cout << "\n\tBuscando canción *Paris - The Chainsmokers - 3:41* " << endl;
    aux = s.sequentialSearch(h, t, "Paris",  1);
    printSong(aux);
    
    cout << "\nPRUEBA DE BÚSQUEDAS 2... \n\tPor autor:\n" << endl;
    cout << "\tBuscando canción *Does It Matter - Janieck - 3:28* " << endl;
    aux = s.sequentialSearch(h, t, "Janieck",  2);
    printSong(aux);
    cout << "\n\tBuscando canción *Wasting Love - HAYES - 2:53* " << endl;
    aux = s.sequentialSearch(h, t, "HAYES",  2);
    printSong(aux);
    
    cout << "\n\nº º º º º º º º º º º º º º º º º º º º º º º º º º º\n" << endl;
    
    cout << "\nPRUEBA DE VACIADO... \n" << endl;
    cout<<"Esta parte del código se encuentra comentada, ya que si se hace, el ";
    cout<<"usuario no va a poder apreciar\nbien la modificación del archivo ";
    cout<<"'songs.csv', porque la lista se vacía y por ende, el archivo también.";
    cout<<"\nSe puede descomentar en caso de que se quiera ver esto."<<endl;
    //list.clearList();
    //splayt.clearTree();
    //list.showListForward();
    
    cout << "\n\nº º º º º º º º º º º º º º º º º º º º º º º º º º º\n" << endl;
    
    cout << "\nPRUEBA DE MANIPULACIÓN DE ARCHIVO .CSV..." << endl;
    fstream new_file;
    new_file.open("new_songs.csv", ios::out);
    
    list.writeData(new_file);
    
    file.close();
    new_file.close();
    
    remove("songs.csv");
    rename("new_songs.csv", "songs.csv");
    cout<<"Archivo modificado. Los datos se pueden ver directamente en el."<<endl;

    return 0;
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
