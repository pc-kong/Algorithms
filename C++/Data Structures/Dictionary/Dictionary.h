#ifndef PCKONG_ALGORITHMS_DS_DICTIONARY_H
#define PCKONG_ALGORITHMS_DS_DICTIONARY_H

#include <memory>
#include <vector>
#include <utility>

namespace ds{

using std::unique_ptr;
using std::vector;
using std::pair;


template<typename K, typename T>
class Dictionary{

  using KeyValue = pair<K,T>;
  
  static size_t base_size;
  static size_t w;
  
  size_t table_size;
  size_t object_count;
  size_t dimension;
  unique_ptr<vector<KeyValue>[]> current_table;
  unique_ptr<vector<KeyValue>[]> shadow_table;

  size_t hash(const K&, int);
  void addToTable(unique_ptr<vector<KeyValue>[]>&, KeyValue, size_t hash);
  void resize();

public:
  Dictionary();
  bool add(K, T);
  bool erase(const K&);
  T* get(const K&);
};

};

#endif // PCKONG_ALGORITHMS_DS_DICTIONARY_H