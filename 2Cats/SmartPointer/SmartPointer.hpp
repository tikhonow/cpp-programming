#pragma once

#include <memory>
#include "Test.hpp"

namespace smart_pointer {
// `exception` class definition
class exception : std::exception {
  using base_class = std::exception;
  using base_class::base_class;
};
// `SmartPointer` class declaration
template <typename T, typename Allocator>
class SmartPointer {
  // don't remove this macro
  ENABLE_CLASS_TESTS;

 public:
  using value_type = T;
  explicit SmartPointer(value_type *a = nullptr)
      : core((a == nullptr ? nullptr : new Core(a))) {}
  // copy constructor
  SmartPointer(const SmartPointer &c)
      : core(c.core != nullptr ? c.core : nullptr) {
    if (core != nullptr) {
      this->core->counter++;
    }
  }
  // move constructor
  SmartPointer(SmartPointer &&c) {
    this->core = c.core;
    c.core = nullptr;
  }
  // copy assigment
  SmartPointer &operator=(const SmartPointer &c) {
    this->~SmartPointer();
    this->core = c.core;
    if (this->core != nullptr) this->core->counter++;
    return *this;
  }
  // move assigment
  SmartPointer &operator=(SmartPointer &&c) {
    this->~SmartPointer();
    this->core = c.core;
    c.core = nullptr;
    return *this;
  }
  //
  SmartPointer &operator=(value_type *a) {
    this->~SmartPointer();
    if (a == nullptr) {
      this->core = nullptr;
    } else {
      this->core = new Core(a);
    }
    return *this;
  }
  ~SmartPointer() {
    if (this->core != nullptr) {
      if (this->core->counter <= 1) {
        delete this->core;
      } else {
        this->core->counter--;
      }
    }
  }
  // return reference to the object of class/type T
  // if SmartPointer contains nullptr throw `SmartPointer::exception`
  value_type &operator*() {
    if (this->core == nullptr || this->core->a == nullptr) {
      throw smart_pointer::exception();
    } else {
      return *(this->core->a);
    }
  }
  const value_type &operator*() const {
    if (this->core == nullptr || this->core->a == nullptr) {
      throw smart_pointer::exception();
    } else {
      return *(this->core->a);
    }
  }
  // return pointer to the object of class/type T
  value_type *operator->() const { return this->get(); }

  value_type *get() const {
    if (this->core == nullptr) {
      return nullptr;
    } else {
      return this->core->a;
    }
  }
  // if pointer == nullptr => return false
  operator bool() const {
    if (this->core == nullptr || this->core->a == nullptr) {
      return false;
    } else {
      return true;
    }
  }
  // if pointers points to the same address or both null => true
  template <typename U, typename AnotherAllocator>
  bool operator==(const SmartPointer<U, AnotherAllocator> &other) const {
    return static_cast<void *>(this->get()) == static_cast<void *>(other.get());
  }
  // if pointers points to the same address or both null => false
  template <typename U, typename AnotherAllocator>
  bool operator!=(const SmartPointer<U, AnotherAllocator> &c) const {
    return !(SmartPointer::operator==(c));
  }
  // if smart pointer contains non-nullptr => return count owners
  // if smart pointer contains nullptr => return 0
  std::size_t count_owners() const {
    if (this->core == nullptr) {
      return 0;
    } else {
      return this->core->counter;
    }
  }

 private:
  class Core {
   public:
    explicit Core(value_type *a) : a(a), counter(1) {}
    ~Core() {
      if (a != nullptr) delete a;
    }
    value_type *a;
    std::size_t counter;
  };
  Core *core;
};
}  // namespace smart_pointer
