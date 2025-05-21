// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include<vector>
#include<algorithm>

template<typename T>
class TPQueue {

public:

  T pop() {
    T result = queue.front();
    queue.erase(queue.begin());
    return result;
  }

  void push(const T& element) {
    queue.push_back(element);
    std::sort(queue.begin(), queue.end(), [](const T& a, const T& b) {
      return a.prior > b.prior;
    });
  }

private:

  std::vector<T> queue;

};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
