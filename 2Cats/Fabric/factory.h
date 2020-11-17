#include <string>
#include <vector>
#include <map>

class Object {
 public:
  virtual std::string ToString() const = 0;
  virtual ~Object() {}
};

class Object_ : public Object {
 public:
  explicit Object_(std::string object_id) : object_id(object_id) {}
  std::string ToString() const { return object_id; }

 private:
  std::string object_id;
};

Object *my_new_apple() { return new Object_("apple!"); }
Object *my_new_list() { return new Object_("list"); }
Object *my_new_yet() { return new Object_("yet another identifier"); }

class Factory {
 public:
  Factory() {
    data.insert(std::make_pair("apple!", &my_new_apple));
    data.insert(std::make_pair("list", &my_new_list));
    data.insert(
        std::make_pair("yet another identifier", &my_new_yet));
  }
  Object *Create(const std::string &class_id) {
    auto if_exist = data.find(class_id);
    return (if_exist)->second();
  }
  void Register(const std::string &class_id, Object *(*instance_creator)()) {
    data.insert(std::make_pair(class_id, instance_creator));
  }

 private:
  std::map<std::string, Object *(*)()> data;
};