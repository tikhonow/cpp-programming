//
// Created by tihon on 10.11.2020.
//

#ifndef FX_FIXED_ALLOCATOR_H
#define FX_FIXED_ALLOCATOR_H

#include <vector>
#include <iostream>

template<typename Tp>
class FixedAllocator {
  PageAllocator page_allocator_;
  std::vector<Tp *> memory;
  std::uint64_t memory_size;

 public:
  explicit FixedAllocator(std::uint64_t page_size) :
      page_allocator_(page_size), memory_size(page_size) {}

  Tp *Allocate() {
    Tp *a;
    if (memory.empty()) {
      a = static_cast<Tp *>(page_allocator_.Allocate());
      for (size_t i = 0; i < memory_size; i++) {
        a = 0;
        memory.push_back(a);
      }
    }
    a = *(memory.end() - 1);
    memory.pop_back();
    return a;
  }

  void Deallocate(Tp *p) {
    memory.push_back(p);
  }

  const PageAllocator &InnerAllocator() const noexcept {
    return page_allocator_;
  }
};

#endif  // FX_FIXED_ALLOCATOR_H
