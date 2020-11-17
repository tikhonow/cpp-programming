#include <iostream>
#include <vector>
#include <set>

class Set {
 public:
  std::vector<int64_t> set;

  explicit Set(const std::vector<int64_t> &vec = std::vector<int64_t>()) {
    for (size_t i : vec) {
      auto tmp = std::find(set.begin(), set.end(), i);
      if (tmp == set.end()) {
        set.push_back(i);
      }
    }
  }

  bool Contains(int64_t value) const {
    auto tmp = std::find(set.begin(), set.end(), value);
    return !(tmp == set.end());
  }

  void Add(int64_t value) {
    if (!Contains(value)) {
      set.push_back(value);
    }
  }

  void Remove(int64_t value) {
    size_t pos = 0;
    for (size_t i = 0; i < set.size(); i++) {
      if (set[i] == value) {
        pos = i;
        set.erase(set.begin() + pos);
      }
    }
  }

  Set Union(const Set &s) const {
    Set union_;
    for (size_t i : set) {
      union_.Add(i);
    }
    for (size_t i : s.set) {
      if (!union_.Contains(i)) {
        union_.Add(i);
      }
    }
    return union_;
  }

  Set Intersection(const Set &s) const {
    Set inter_;
    for (size_t i : s.set) {
      if (Contains(i)) {
        inter_.set.push_back(i);
      }
    }
    return inter_;
  }

  Set Difference(const Set &s) const {
    Set diff_;
    for (size_t i : set) {
      if (!s.Contains(i)) {
        diff_.Add(i);
      }
    }
    return diff_;
  }
  Set SymmetricDifference(const Set &s) const {
    Set set_sym_dif;
    for (size_t i : s.set) {
      if (!Contains(i)) {
        set_sym_dif.Add(i);
      }
    }
    for (size_t i : set) {
      if (!s.Contains(i)) {
        set_sym_dif.Add(i);
      }
    }
    return set_sym_dif;
  }
  std::vector<int64_t> Data() const { return set; }
};
