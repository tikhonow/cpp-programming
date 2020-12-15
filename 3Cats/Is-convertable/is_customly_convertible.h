struct NoTriviallyConstructible {
  NoTriviallyConstructible() = delete;
};

struct NoCopyConstructible {
  NoCopyConstructible(const NoCopyConstructible& a) = delete;
  NoCopyConstructible& operator=(const NoCopyConstructible&) = delete;
};

template <>
struct Convert<NoCopyConstructible, NoTriviallyConstructible> {
  int operator()(const NoCopyConstructible& a) { return 1; }
};

template <typename T>
class Has_op_bracket {
 private:
  typedef char YesType[1];
  typedef char NoType[2];

  template <typename C>
  static YesType& test(decltype(&C::operator()));
  template <typename C>
  static NoType& test(...);

 public:
  enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};

template <typename A, typename B>
struct is_customly_convertible {
  static constexpr bool value = Has_op_bracket<Convert<A, B>>::value;
};