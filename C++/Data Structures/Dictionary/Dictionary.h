#ifndef PCKONG_ALGORITHMS_DS_DICTIONARY_H
#define PCKONG_ALGORITHMS_DS_DICTIONARY_H

#include <memory>
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>
#include <cstdlib>

namespace ds{

using std::unique_ptr;
using std::vector;
using std::pair;


template<typename K, typename T>
class Dictionary{

  using KeyValue = pair<K,T>;
  
  static size_t base_size;
  static size_t w;
  int random_odd;
  
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

template<typename K, typename T>
size_t ds::Dictionary<K,T>::base_size = 16;

template<typename K, typename T>
size_t ds::Dictionary<K,T>::w = std::numeric_limits<unsigned int>::max_exponent;

template<typename K, typename T>
ds::Dictionary<K,T>::Dictionary(){
  table_size = base_size;
  object_count = 0;
  dimension = 4;
  current_table = unique_ptr<vector<KeyValue>[]>(new vector<KeyValue>[table_size]);
  shadow_table = unique_ptr<vector<KeyValue>[]>(new vector<KeyValue>[table_size * 2]);
  srand(time(nullptr));
  int random = rand() % (RAND_MAX - 1);
  random_odd = random%2 == 0 ? random + 1 : random;
}

template<typename K, typename T>
bool ds::Dictionary<K,T>::add(K key, T value){
  if(get(key) != nullptr) return false;
  auto key_value = std::make_pair(key, value);
  if(object_count + 1 == table_size) resize();
  addToTable(current_table, key_value, hash(key, dimension));
  addToTable(shadow_table, key_value, hash(key, dimension+1));
  return true;
}

template<typename K, typename T>
T* ds::Dictionary<K,T>::get(const K& key){
  int bucket = hash(key, dimension);
  for(auto& k_v_pair:current_table[bucket]){
    if(k_v_pair.first == key) return &k_v_pair.second;
  }
  return nullptr;
}

template<typename K, typename T>
bool ds::Dictionary<K,T>::erase(const K& key){
  int bucket = hash(key, dimension);
  int shadow_bucket = hash(key, dimension + 1);
  auto it =
  std::remove_if(current_table[bucket].begin(),
                  current_table[bucket].end(),
                  [&](KeyValue& k_v_pair){
                    return k_v_pair.first == key;
                  });
  if(it != current_table[bucket].end()){
    current_table[bucket].erase(it,current_table[bucket].end());
    it = std::remove_if(shadow_table[shadow_bucket].begin(),
                    shadow_table[shadow_bucket].end(),
                    [&](KeyValue& k_v_pair){
                    return k_v_pair.first == key;
                  });
    shadow_table[shadow_bucket].erase(it, shadow_table[shadow_bucket].end());
    return true;
  }
  return false;
}

template<typename K, typename T>
size_t ds::Dictionary<K,T>::hash(const K& key, int d){
  return ((unsigned)random_odd * std::hash<K>()(key)) >> (w-d);
}

template<typename K, typename T>
void ds::Dictionary<K,T>::resize(){
  table_size = table_size * 2;
  dimension++;
  current_table = std::move(shadow_table);
  shadow_table = unique_ptr<vector<KeyValue>[]>(new vector<KeyValue>[table_size * 2]);
  for(int i = 0; i<table_size; i++){
    for(auto& k_v_pair:current_table[i]){
      addToTable(shadow_table, k_v_pair, hash(k_v_pair.first, dimension + 1));
    }
  }
}

template<typename K, typename T>
void
ds::Dictionary<K,T>::
addToTable(unique_ptr<vector<KeyValue>[]>& table, KeyValue key_value, size_t hash){
  table[hash].push_back(std::move(key_value));
}

#endif // PCKONG_ALGORITHMS_DS_DICTIONARY_H