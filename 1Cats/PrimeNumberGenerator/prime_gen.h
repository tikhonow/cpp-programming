class PrimeNumberGenerator {
 public:
  int start;
  int right_prime_number;
  explicit PrimeNumberGenerator(int start) {
    this->start = start;
    if (this->start == 1) {
      this->start++;
    }
  }
  int GetNextPrime() {
    bool check = 0;
    while (!check) {
      check = 1;
      for (int i = 2; i <= sqrt(start) && check; i++) {
        if (start % i == 0) {
          check = 0;
        }
      }
      if (check) {
        start++;
        return start - 1;
      }
      start++;
    }
    return 0;
  }
};
