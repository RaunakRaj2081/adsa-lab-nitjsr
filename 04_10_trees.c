#include <stdio.h>
#include <stdlib.h>

//
// ---------------- AVL TREE ----------------
//
typedef struct AVL {
    int key, h;
    struct AVL *l, *r;
} AVL;

// Utility functions
int H(AVL* n) { return n ? n->h : 0; }
int max(int a, int b) { return a > b ? a : b; }

AVL* newAVL(int k) {
    AVL* n = malloc(sizeof(AVL));
    n->key = k; n->l = n->r = NULL; n->h = 1;
    return n;
}

// Rotations
AVL* rotR(AVL* y) {
    AVL* x = y->l; AVL* t = x->r;
    x->r = y; y->l = t;
    y->h = 1 + max(H(y->l), H(y->r));
    x->h = 1 + max(H(x->l), H(x->r));
    return x;
}
AVL* rotL(AVL* x) {
    AVL* y = x->r; AVL* t = y->l;
    y->l = x; x->r = t;
    x->h = 1 + max(H(x->l), H(x->r));
    y->h = 1 + max(H(y->l), H(y->r));
    return y;
}
int bal(AVL* n) { return n ? H(n->l) - H(n->r) : 0; }

// Insert
AVL* insertAVL(AVL* r, int k) {
    if (!r) return newAVL(k);

    if (k < r->key) r->l = insertAVL(r->l, k);
    else if (k > r->key) r->r = insertAVL(r->r, k);
    else return r;

    r->h = 1 + max(H(r->l), H(r->r));
    int b = bal(r);

    if (b > 1 && k < r->l->key) return rotR(r);
    if (b < -1 && k > r->r->key) return rotL(r);
    if (b > 1 && k > r->l->key) { r->l = rotL(r->l); return rotR(r); }
    if (b < -1 && k < r->r->key) { r->r = rotR(r->r); return rotL(r); }

    return r;
}

// Search
AVL* searchAVL(AVL* r, int k) {
    if (!r || r->key == k) return r;
    return k < r->key ? searchAVL(r->l, k) : searchAVL(r->r, k);
}

// Delete Tree
void freeAVL(AVL* r) {
    if (!r) return;
    freeAVL(r->l);
    freeAVL(r->r);
    free(r);
}

//
// ---------------- RED-BLACK TREE (Skeleton) ----------------
//
typedef enum { R, B } Color;
typedef struct RB {
    int key; Color c;
    struct RB *l, *r, *p;
} RB;

RB* NIL = 0;

RB* newRB(int k) {
    RB* n = malloc(sizeof(RB));
    n->key = k; n->c = R;
    n->l = n->r = n->p = NIL;
    return n;
}

// Simplified Insert (not full balancing)
RB* insertRB(RB* root, int k) {
    RB* n = newRB(k);
    n->c = B;   // keep root black
    return n;
}

RB* searchRB(RB* r, int k) {
    if (!r || r == NIL || r->key == k) return r;
    return k < r->key ? searchRB(r->l, k) : searchRB(r->r, k);
}

void freeRB(RB* r) {
    if (!r || r == NIL) return;
    freeRB(r->l);
    freeRB(r->r);
    free(r);
}

//
// ---------------- B-TREE (Skeleton) ----------------
//
#define T 3
typedef struct BTree {
    int n, leaf;
    int keys[2*T-1];
    struct BTree* c[2*T];
} BTree;

BTree* newBT(int leaf) {
    BTree* t = malloc(sizeof(BTree));
    t->n = 0; t->leaf = leaf;
    return t;
}

void traverseBT(BTree* r) {
    int i;
    for (i = 0; i < r->n; i++) {
        if (!r->leaf) traverseBT(r->c[i]);
        printf("%d ", r->keys[i]);
    }
    if (!r->leaf) traverseBT(r->c[i]);
}

//
// ---------------- B+ TREE (Skeleton) ----------------
//
typedef struct BPlus {
    int n, leaf;
    int keys[2*T-1];
    struct BPlus* c[2*T];
    struct BPlus* next;
} BPlus;

BPlus* newBPlus(int leaf) {
    BPlus* t = malloc(sizeof(BPlus));
    t->n = 0; t->leaf = leaf; t->next = NULL;
    return t;
}

//
// ---------------- MAIN ----------------
//
int main() {
    // AVL Demo
    AVL* avl = NULL;
    avl = insertAVL(avl, 10);
    avl = insertAVL(avl, 20);
    avl = insertAVL(avl, 30);

    printf("AVL search 20: %s\n", searchAVL(avl, 20) ? "Found" : "Not Found");

    // Red-Black Tree Demo
    RB* rb = insertRB(NULL, 15);
    printf("RB root = %d\n", rb->key);

    // B-Tree Demo
    BTree* bt = newBT(1);
    bt->keys[0] = 5; bt->n = 1;
    printf("BTree key = %d\n", bt->keys[0]);

    // B+ Tree Demo
    BPlus* bp = newBPlus(1);
    bp->keys[0] = 7; bp->n = 1;
    printf("B+Tree key = %d\n", bp->keys[0]);

    return 0;
}
