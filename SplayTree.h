/*
 * Proyecto MusicApp
 * Karen Cebreros López
 * A01704254
 * 8/09/2021
 *
 * SplayTree.h
 * MusicApp
 * Created by Karen CL on 8/09/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * La clase SplayTree contiene como atributos la duración de cada canción y tres
 * apuntadores (padre, hijo derecho e hijo izquierdo).
 * Esta clase fue hecha con el objetivo de poder tener otro tipo de estructura, en
 * donde también se ve como se agregan y eliminan canciones. Sin embargo, en el
 * programa, más que nada se usa para hacer recorridos y obtener la cantidad de
 * canciones total, así como también la duración total de la playlist en minutos
 * y segundos.
 *
 * La clase contiene los métodos que permiten al árbol hacer las rotaciones
 * necesarias, para acomodar las duraciones como se debe.
 *
 */

#ifndef SplayTree_h
#define SplayTree_h

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class SplayTree;

// Template class Node
class TreeNode {
    private:
    // Atributos (privados)
    int value;
    TreeNode *left, *right, *parent;

    // Métodos (privados)
    TreeNode* succesor();
    TreeNode* rotRight(TreeNode*);
    TreeNode* rotLeft(TreeNode*);

    public:
        // Constructor
        TreeNode(int val): value(val), left(NULL), right(NULL), parent(NULL){};
        
        // Métodos
        TreeNode* splay(TreeNode*, TreeNode*);
        TreeNode* add(int);
        TreeNode* remove(int);
        void clearTree();
        int playlistDuration(TreeNode*);

        // Clase "SplayTree" puesta como friend de "TreeNode"
        friend class SplayTree;
};

/*
 * @param
 * @return TreeNode*
 *
 * Obtiene el sucesor de un nodo.
 *
 */
TreeNode* TreeNode::succesor() {
    TreeNode *ri = right;
    TreeNode *le = left;
    
    if (!right->left) {
        right = right->left;
        ri->right = NULL;
        return ri;
    }
    if (!left->right) {
        left = left->right;
        le->left = NULL;
        return le;
    }
    
    TreeNode *parent = right;
    TreeNode *child = right->left;
    
    while (child->left) {
        parent = child;
        child = child->left;
    }
    
    parent->left = child->right;
    child->right = NULL;
    return child;
}

/*
 * @param TreeNode*
 * @return TreeNode*
 *
 * Se hace una rotación hacia la derecha.
 *
 */
TreeNode* TreeNode::rotRight(TreeNode *nodo) {
    TreeNode *aux = nodo->left;
    nodo->left = aux->right;
    
    if (aux->right)
        aux->right->parent = nodo;
    aux->right = nodo;
    
    aux->parent = nodo->parent;
    nodo->parent = aux;
    
    if (aux->parent) {
        if (aux->parent->left && aux->parent->left->value == nodo->value)
            aux->parent->left = aux;
        else
            aux->parent->right = aux;
    }
    
    return aux;
}

/*
 * @param TreeNode*
 * @return TreeNode*
 *
 * Se hace una rotación hacia la izquierda.
 *
 */
TreeNode* TreeNode::rotLeft(TreeNode *nodo) {
    TreeNode *aux = nodo->right;
    nodo->right = aux->left;
    
    if (aux->left)
        aux->left->parent = nodo;
    aux->left = nodo;
    
    aux->parent = nodo->parent;
    nodo->parent = aux;
    
    if (aux->parent) {
        if (aux->parent->left && aux->parent->left->value == nodo->value)
            aux->parent->left = aux;
        else
            aux->parent->right = aux;
    }
    
    return aux;
}

/*
 * @param TreeNode*, TreeNode*
 * @return TreeNode*
 *
 * Aplica el "splay" para realizar las rotaciones pertinentes.
 *
 */
TreeNode* TreeNode::splay(TreeNode *root, TreeNode *nodo) {
    while (nodo->parent) {
        if (nodo->parent->value == root->value) {
            if (nodo->parent->left && nodo->parent->left->value == nodo->value)
                rotRight(nodo->parent);
            else
                rotLeft(nodo->parent);
        } else {
            TreeNode *padre = nodo->parent;
            TreeNode *abuelo = padre->parent;
            
            if (padre->left && abuelo->left && nodo->value == padre->left->value
                && padre->value == abuelo->left->value) {
                rotRight(abuelo);
                rotRight(padre);
            } else if (padre->right && abuelo->right
                       && nodo->value == padre->right->value
                       && padre->value == abuelo->right->value) {
                rotLeft(abuelo);
                rotLeft(padre);
            } else if (padre->right && abuelo->left
                       && nodo->value == padre->right->value
                       && padre->value == abuelo->left->value) {
                rotLeft(padre);
                rotRight(abuelo);
            } else {
                rotRight(padre);
                rotLeft(abuelo);
            }
        }
    }
    return nodo;
}

/*
 * @param int
 * @return TreeNode*
 *
 * Después de que se comprueba que el árbol no está vacío, se agrega un nuevo
 * nodo al árbol.
 *
 */
TreeNode* TreeNode::add(int val) {
    if (val > value) {
        if (right)
            return (right->add(val));
        else {
            right = new TreeNode(val);
            right->parent = this;
            return right;
        }
    } else {
        if (left)
            return (left->add(val));
        else {
            left = new TreeNode(val);
            left->parent = this;
            return left;
        }
    }
}

/*
 * @param int
 * @return TreeNode*
 *
 * Elimina un nodo del árbol, evaluando si tiene dos, uno o cero hijos y haciendo
 * rotaciones para acomodar todo de nuevo.
 *
 */
TreeNode* TreeNode::remove(int val) {
    TreeNode *succesor, *old;
    if (val > value) {
        if (right) {
            if (right->value == val) {
                old = right;
                if (old->right && old->left) {
                    succesor = right->succesor();
                    if (succesor) {
                        succesor->right = old->right;
                        succesor->left = old->left;
                        succesor->parent = old->parent;
                        
                        if (succesor->right)
                            succesor->right->parent = succesor;
                        if (succesor->left)
                            succesor->left->parent = succesor;
                    }
                    right = succesor;
                } else if (old->right) {
                    old->right->parent = right->parent;
                    right = old->right;
                } else if (old->left) {
                    old->left->parent = right->parent;
                    right = old->left;
                } else {
                    right = NULL;
                }
                
                delete old;
                return this;
            } else {
                return right->remove(val);
            }
        }
    } else if (val < value) {
        if (left) {
            if (left->value == val) {
                old = left;
                if (old->right && old->left) {
                    succesor = left->succesor();
                    if (succesor) {
                        succesor->right = old->right;
                        succesor->left = old->left;
                        succesor->parent = old->parent;
                        
                        if (succesor->right)
                            succesor->right->parent = succesor;
                        if (succesor->left)
                            succesor->left->parent = succesor;
                    }
                    left = succesor;
                } else if (old->right) {
                    old->right->parent = left->parent;
                    left = old->right;
                } else if (old->left) {
                    old->left->parent = left->parent;
                    left = old->left;
                } else {
                    left = NULL;
                }
                
                delete old;
                return this;
            } else {
                return left->remove(val);
            }
        }
    }
    return this;
}

/*
 * @param
 * @return
 *
 * Vacía el árbol, eliminando cada nodo de éste.
 *
 */
void TreeNode::clearTree() {
    if (left) {
        left->clearTree();
        delete left;
        left = NULL;
    }
    if (right) {
        right->clearTree();
        delete right;
        right = NULL;
    }
}

/*
 * @param
 * @return int&
 *
 * Suma las duraciones (todos los nodos del árbol), haciendo un recorrido de
 * éste de forma "in-order".
 *
 */
int TreeNode::playlistDuration(TreeNode *node) {
    if (!node) {
        return 0;
    } else {
        return (value + node->playlistDuration(node->left) +
                node->playlistDuration(node->right));
    }
}


// Template class SplayTree
class SplayTree {
    private:
        // Atributos (privados)
        TreeNode *root;
        int sze;
    public:
        // Constructor
        SplayTree(): root(NULL), sze(0){};
        
        // Métodos
        void fillTree(ifstream&);
        void add(int);
        void remove(int);
        int size();
        void clearTree();
        int playlistDuration();
};

/*
 * @param ifstream&
 * @return
 *
 * Crea el árbol usando las duraciones de las canciones del archivo "songs.csv".
 * Se lee cada línea de este y se van agregando al árbol en el orden correcto
 * utilizando la función "add()" con cada una.
 *
 */
void SplayTree::fillTree(ifstream &file) {
    while (!file.eof()) {
        string name, author, duration;
        getline(file, name, ',');
        getline(file, author, ',');
        getline(file, duration, '\n');
        
        int dur = atoi(duration.c_str());
        
        if (dur != 0)
            add(dur);
    }
}

/*
 * @param int
 * @return
 *
 * Evalua si la raíz está vacía o no. (En caso de que sí, el valor se agrega a
 * ésta y en caso contrario, primero se llama al método "add()" de la clase
 * TreeNode y luego al "splay" para organizar el árbol con el elemento más nuevo
 * hasta arriba.
 *
 */
void SplayTree::add(int val) {
    if (root) {
        TreeNode *new_node = root->add(val);
        root = root->splay(root, new_node);
    } else {
        root = new TreeNode(val);
    }
    sze++;
}

/*
 * @param int
 * @return
 *
 * Busca si el elemento que se quiere eliminar se encuentra en la estructura o no
 * y lurgo prosigue a eliminarlo, para finalmente ordenar el árbol.
 *
 */
void SplayTree::remove(int val) {
    if (root) {
        if (root->value == val) {
            TreeNode *succesor = root->succesor();
            if (succesor) {
                succesor->right = root->right;
                succesor->left = root->left;
                succesor->parent = NULL;
                
                if (succesor->right)
                    succesor->right->parent = succesor;
                if (succesor->left)
                    succesor->left->parent = succesor;
            }
            
            delete root;
            root = succesor;
        } else {
            TreeNode *to_remove = root->remove(val);
            root = root->splay(root, to_remove);
        }
        sze--;
    }
}

/*
 * @param
 * @return int
 *
 * Regresa el atributo "size", que es el que va guardando el tamaño del árbol.
 *
 */
int SplayTree::size() {
    return sze;
}

/*
 * @param
 * @return
 *
 * Vacía el árbol (si éste no se encuentra vacío ya), recorriéndolo y eliminando
 * cada nodo.
 *
 */
void SplayTree::clearTree() {
    if (root) {
        root->clearTree();
    }
    delete root;
    root = NULL;
    sze = 0;
}

/*
 * @param
 * @return int
 *
 * Regresa la suma de todos los valores de los nodos (las duraciones); haciendo
 * un recorrido del árbol en caso de que no esté vacío.
 *
 */
int SplayTree::playlistDuration() {
    TreeNode *aux = root;
    if (aux)
        return root->playlistDuration(root);
    return 0;
}

#endif /* SplayTree_h */
