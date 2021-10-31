/*
 * Proyecto MusicApp
 * Karen Cebreros López
 * A01704254
 * 8/09/2021
 *
 * SortAndSearch.h
 * MusicApp
 * Created by Karen CL on 8/09/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * La clase SortOrSearch no contiene atributos como tal. Esta solo tiene métodos
 * que ayudan al ordenamiento y búsqueda de las canciones en la lista.
 * Tiene un método privado que ayuda a intercambiar los valores de dos canciones,
 * un método público que se utiliza para buscar una canción por autor o nombre en
 * la lista y finalmente otros métodos públicos que trabajan en conjunto para
 * ordenar ésta.
 */

#ifndef SortAndSearch_h
#define SortAndSearch_h

#include <algorithm>

#include "DLinkedList.h"
#include "Song.h"
using namespace std;

// SortOrSearch class
class SortOrSearch {
    private:
        // Método privado
        void swapSong(Song*, Song*);
    public:
        // Constructor
        SortOrSearch(){};
    
        // Métodos públicos
        void quickSort(Song*, Song*, int);
        Song* quickPartition(Song*, Song*, int);
        Song* sequentialSearch(Song*, Song*, string, int);
};

/*
 * @param Song*, Song*
 * @return
 *
 * Swap de los valores (name, author and duration) de dos canciones.
 *
 */
void SortOrSearch::swapSong(Song *A, Song *B) {
    string aux_name = A->name;
    string aux_author = A->author;
    int aux_duration = A->duration;
    
    A->name = B->name;
    A->author = B->author;
    A->duration = B->duration;
    
    B->name = aux_name;
    B->author = aux_author;
    B->duration = aux_duration;
}

/*
 * @param Song*, Song*, int
 * @return
 *
 * Función recursiva que hace el partido de la lista para ordenarla, usando un
 * "pivote".
 *
 */
void SortOrSearch::quickSort(Song *start, Song *end, int attribute) {
    if (end && end != start && start != end->next) {
        Song *partition = quickPartition(start, end, attribute);
        
        quickSort(start, partition->previous, attribute);
        quickSort(partition->next, end, attribute);
    }
}

/*
 * @param Song*, Song*, int
 * @return Song*
 *
 * Compara los valores (nombre o autor) de dos canciones de la partición, usando
 * el "start" y "end" que se le pasa a la función, para poder hacer el
 * ordenamiento, a través de swaps.
 *
 */
Song* SortOrSearch::quickPartition(Song *start, Song *end, int attribute) {
    string pivot;
    attribute == 1 ? pivot = end->name : pivot = end->author; // pivote
    transform(pivot.begin(), pivot.end(), pivot.begin(), ::tolower);
    
    Song *i = start->previous; // contador: end-1
    string j_atributte;
    for (Song *j = start; j != end; j = j->next) {
        attribute == 1 ? j_atributte = j->name : j_atributte = j->author;
        transform(j_atributte.begin(), j_atributte.end(),
                  j_atributte.begin(), ::tolower);
        if (j_atributte <= pivot) {
            // incremento i
            if (i)
                i = i->next;
            else
                i = start;
            
            swapSong(i, j);
        }
    }
    // incremento i antes del swap y del return (así evito ponerlo 2 veces)
    if (i)
        i = i->next;
    else
        i = start;
    
    swapSong(i, end);
    
    return i;
}

/*
 * @param Song*, Song*, string, int
 * @return Song*
 *
 * Busca una canción en específico de la lista, usando búsqueda secuencial.
 * Se regresa la canción si ésta es encontrada.
 *
 */
Song* SortOrSearch::sequentialSearch(Song* head, Song* tail, string x,
                                     int attribute) {
    string aux;
    Song *s = new Song();
    for (Song *i = head; i != tail->next; i = i->next) {
        attribute == 1 ? aux = i->name : aux = i->author;
        transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
        if (x == aux) {
            s = i;
            cout << "¡Canción encontrada!" << endl;
            return s;
        }
    }
    
    cout << "Canción no encontrada :'(" << endl;
    return s;
}

#endif /* SortAndSearch_h */
