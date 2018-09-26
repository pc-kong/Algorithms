#ifndef DICTIONARY_H
#define DICTIONARY_H

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
  size_t table_size;
  size_t object_count;
  unique_ptr<vector<KeyValue>> current_table;
  unique_ptr<vector<KeyValue>> shadow_table;

  size_t hash(const K& key);
  void resize();

public:
  Dictionary();
  bool add(K key, T value);
  bool erase(const K& key);
  T* get(const K& key);
};

};

#endif // DICTIONARY_H