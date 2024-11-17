#include <iostream>

#include "bstp.h"
void tree::Put(node *T) {
  if (T == nullptr)
    std::cout << "";
  else {
    std::cout << T->Key << "(";
    Put(T->Less);
    std::cout << ",";
    Put(T->More);
    std::cout << ")";
  }
}
void tree::Put(void) { Put(Root); }
void tree::PutSort(node *T) {
  if (T == nullptr)
    std::cout << "* ";
  else {
    PutSort(T->Less);
    std::cout << T->Key << " ";
    Put(T->More);
  }
}
void tree::PutSort(void) { PutSort(Root); }
void tree::Draw(void) { Draw(Root, 0); }
void tree::Draw(node *T, int Level) {
  if (T != NULL) {
    Draw(T->More, Level + 1);
    std::cout.width(Level * 3);
    std::cout << " " << T->Key << "\n";
    Draw(T->Less, Level + 1);
  }
}
tree::node **tree::Search(node **T, int Key) {
  if (*T == nullptr) return T;
  if ((*T)->Key == Key) return T;
  if ((*T)->Key > Key) return Search(&(*T)->Less, Key);
  return Search(&(*T)->More, Key);
}
bool tree::Delete(int Key) {
  node **T = Search(&Root, Key);
  if (*T == nullptr) return 0;
  node *Right = (*T)->Less;
  node *Less = (*T)->Less;
  node *More = (*T)->More;
  (*T)->Less = (*T)->More = nullptr;
  delete *T;
  if (Less == nullptr)
    *T = More;
  else {
    while (Right->More != nullptr) Right = Right->More;
    Right->More = More;
    *T = Less;
  }
  return 1;
}

int tree::Linearize(void) {
  int counter = 0;
  node **T = &Root;
  while ((*T)->More != nullptr || (*T)->Less != nullptr) {
    while ((*T)->Less != nullptr) {
      node *RightMost = (*T)->Less;
      while (RightMost->More != nullptr) RightMost = RightMost->More;
      RightMost->More = (*T)->More;
      *T = (*T)->Less;
    }
    T = &(*T)->More;
    counter++;
  }
  return counter;
}
void tree::BalanceTree(node **T, int N) {
  if (*T == nullptr) return;
  node **P = T;

  for (int i = 0; i < N / 2; i++) P = &(*P)->More;
  (*P)->More = *T;
  *T = *P;
  *P = nullptr;

  BalanceTree(&(*T)->Less, N / 2);
  BalanceTree(&(*T)->More, N - N / 2 - 1);
}
void tree::Balance(void) { BalanceTree(&Root, Linearize()); }
void tree::Access(int Key) {
  node **T = Search(&Root, Key);
  if (*T == NULL) {
    *T = new node(Key);
    std::cout << "Add a new key\n";
  } else
    std::cout << "Node exists\n";
}
