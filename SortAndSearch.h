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

#include "DLinkedList.h"
#include "Song.h"
using namespace std;

// SortOrSearch class
class SortOrSearch {
    private:
        // Private method
        void swapSong(Song*, Song*);
    public:
        // Constructor
        SortOrSearch(){};
    
        // Public methods
        void quickSort(Song*, Song*, int);
        Song* quickPartition(Song*, Song*, int);
        Song* sequentialSearch(Song*, Song*, string, int);
};

/*
 * @param Song*, Song*
 * @return
 *
 * Swaps the values (name, author and duration) of two songs.
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
 * Recursive function that calls itself to make the partitions of the list in
 * order to sort it using a pivot in each call.
 *
 */
void SortOrSearch::quickSort(Song *head, Song *tail, int attribute) {
    if (head && head != tail && head != tail->next) {
        Song *partition = quickPartition(head, tail, attribute);
        
        quickSort(head, partition->previous, attribute);
        quickSort(partition->next, tail, attribute);
    }
}

/*
 * @param Song*, Song*, int
 * @return Song*
 *
 * Compares the values (names or authors) of the songs in the partition using
 * the start and the end passed into the funcion, in order to sort it (swap the
 * values).
 *
 */
Song* SortOrSearch::quickPartition(Song *start, Song *end, int attribute) {
    string pivot;
    attribute == 1 ? pivot = end->name : pivot = end->author; // pivot
    
    Song *i = start->previous; // counter: low-1
    string j_atributte;
    for (Song *j = start; j != end; j = j->next) {
        attribute == 1 ? j_atributte = j->name : j_atributte = j->author;
        if (j_atributte <= pivot) {
            // increment i
            if (i)
                i = i->next;
            else
                i = start;
            
            swapSong(i, j);
        }
    }
    // increment i before the swap and return to avoid putting i+1 in both of them
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
 * Searchs for an especific song in the list using sequential search and
 * returns the song if found.
 *
 */
Song* SortOrSearch::sequentialSearch(Song* head, Song* tail, string x,
                                     int attribute) {
    string aux;
    Song *s = new Song();
    for (Song *i = head; i != tail->next; i = i->next) {
        attribute == 1 ? aux = i->name : aux = i->author;
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
