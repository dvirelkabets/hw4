#include <iostream>
#include <deque>

int main() {
  // Create a deque of integers
  std::deque<int> d;

  // Add an element to the front of the deque
  d.push_front(4);
d.push_front(3);
d.push_front(2);
d.push_front(1);
  // Insert an element at the back of the deque
  d.push_back(5);
  d.push_back(6);
  d.clear();
  d.push_front(132);

  // Iterate over the elements of the deque
  for (int i : d) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
    return 0;
}