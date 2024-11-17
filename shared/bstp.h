struct tree {
  struct node {
    int Key;
    node *Less, *More;
    node(int NewKey, node *L = nullptr, node *M = nullptr)
        : Key(NewKey), Less(L), More(M) {}
    ~node(void) {
      delete Less;
      delete More;
    }
  } *Root;
  tree(void) : Root(nullptr) {}
  ~tree(void) { delete Root; }
  void Clear(void) {
    delete Root;
    Root = nullptr;
  }
  node **Search(node **T, int Key);
  void Access(int Key);
  void Put(node *T);
  void Put(void);
  void PutSort(node *T);
  void PutSort(void);
  void Draw(void);
  void Draw(node *T, int Level);
  bool Delete(int Key);
  int Linearize(void);
  void BalanceTree(node **T, int N);
  void Balance(void);
};
