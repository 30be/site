#include "bstp.h"
int main() {
  tree T;
  T.Access(1);
  T.Access(2);
  T.Access(4);
  T.Access(7);
  T.Access(4);
  T.Access(3);
  T.Access(0);
  T.Access(8);
  T.Draw();
  T.Linearize();
  T.Draw();
  T.Balance();
  T.Draw();
}
