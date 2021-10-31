/*
 * Proyecto MusicApp
 * Karen Cebreros López
 * A01704254
 * 8/09/2021
 *
 * song.h
 * MusicApp
 * Created by Karen CL on 8/09/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * La estructura Song, tiene simplemente los datos (nombre, autor y duración) de
 * cada canción y punteros que se utilizan para conectarlas en una lista
 * doblemente enlazada, ya que es la manera en la que normalmente fucniona una
 * aplicación de música para recorrer las canciones.
 */

#ifndef Song_h
#define Song_h

using namespace std;

// Structura "Song"
struct Song {
    // Apuntadores y datos
    Song *previous;
    string name;
    string author;
    int duration;
    Song *next;
};

#endif /* Song_h */
