#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <functional>

using std::vector;
using std::string;

bool operator>(const GameObject &a, const GameObject &b) {
  return a.id > b.id;
}

template<class Tp, template<class> class Compare>
class DereferenceCompare {
  Compare<Tp> comp;

 public:
  bool operator()(const Tp *const a, const Tp *const b) const {
    return comp(*a, *b);
  }
};

class GameDatabase {
 public:
  GameDatabase() = default;
  /// вставляет в базу объект с именем [name] и позицией [x, y]
  /// если объект с таким id в базе уже есть, заменяет его новым
  void Insert(ObjectId id, string name, size_t x, size_t y) {
    GameObject tmp{id, name, x, y};
    if (id_acces.find(id) != id_acces.end()) Remove(id);
    id_acces.insert({id, tmp});
    auto tmp1 = &id_acces.at(id);
    possition_acces[{x, y}].insert(tmp1);
    name_acces[name].insert(tmp1);

  }
  /// удаляет элемент по id
  /// если такого элемента нет, ничего не делает
  void Remove(ObjectId id) {
    if (id_acces.find(id) != id_acces.end()) {
      GameObject *tmp = &id_acces.find(id)->second;
      (possition_acces.find({tmp->x, tmp->y}))->second.erase(tmp);
      (name_acces.find({tmp->name}))->second.erase(tmp);
      id_acces.erase(id_acces.find(id));

    }
  }

  /// возвращает вектор объектов c именем [name]
  /// сортировка по убыванию id
  vector<GameObject> DataByName(string name) const {
    vector<GameObject> result;
    auto iterator = name_acces.find(name);
    if (iterator == name_acces.end()) return result;
    for (auto i: iterator->second) {
      result.push_back(*i);
    }
    return result;
  }

  /// возвращает вектор объектов, находящихся в позиции [x, y]
  /// сортировка по убыванию id
  vector<GameObject> DataByPosition(size_t x, size_t y) const {
    vector<GameObject> result;
    auto iterator = possition_acces.find({x, y});
    if (iterator == possition_acces.end()) return result;
    for (auto i: iterator->second) {
      result.push_back(*i);
    }
    return result;
  }

  /// возвращает вектор всех объектов из базы
  /// сортировка по убыванию id
  vector<GameObject> Data() const {
    vector<GameObject> result;
    for (auto i : id_acces) {
      result.push_back(i.second);
    }
    return result;
  }

 private:
  /// быстрый доступ по id
  std::map<ObjectId, GameObject, std::greater<ObjectId>> id_acces;
  /// быстрый доступ по позиции
  std::map<std::pair<size_t, size_t>, std::set<GameObject *, DereferenceCompare<GameObject, std::greater>>>
      possition_acces;
  /// быстрый доступ по имени
  std::unordered_map<string, std::set<GameObject *, DereferenceCompare<GameObject, std::greater>>> name_acces;
};