#include "Dictionary.h"
#include <limits>
#include <cstdlib>

template<typename K, typename T>
size_t ds::Dictionary<K,T>::base_size = 16;

template<typename K, typename T>
size_t ds::Dictionary<K,T>::w = std::numeric_limits<unsigned int>::max_exponent;

template<typename K, typename T>
ds::Dictionary<K,T>::Dictionary(){
  table_size = base_size;
  object_count = 0;
  dimension = 4;
  current_table = new vector<KeyValue>[table_size];
  shadow_table = new vector<KeyValue>[table_size * 2];
  srand(time(nullptr));
}

template<typename K, typename T>
size_t ds::Dictionary<K,T>::hash(const K& key, int d){
  int random = rand() % (RAND_MAX - 1);
  int random_odd = random%2 == 0 ? random + 1 : random;
  return ((unsigned)random_odd * std::hash<K>(key)) >> (w-d);
}

template<typename K, typename T>
void ds::Dictionary<K,T>::resize(){
  table_size = table_size * 2;
  dimension++;
  current_table = shadow_table;
  shadow_table = new vector<KeyValue>[table_size * 2];
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