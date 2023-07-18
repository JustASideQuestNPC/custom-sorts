//
// Created by hey-t on 6/18/2023.
//

#ifndef BAD_SORTS_SORTS_H
#define BAD_SORTS_SORTS_H

#include <vector>
#include <list>
#include <iterator>

namespace sorts {
  template<typename T>
  bool verifySort(std::vector<T> data) {
    T item{data[0]};
    for (size_t i{1}; i < data.size(); ++i) {
      if (item > data[i]) return false;
      item = data[i];
    }
    return true;
  }

  template<typename T>
  std::list<T> vectorToList(std::vector<T> vec) {
    std::list<T> lst{};
    std::copy(vec.begin(), vec.end(), std::back_inserter(lst));
    return lst;
  }

  template<typename T>
  std::vector<T> listToVector(std::list<T> lst) {
    std::vector<T> vec;
    std::copy(lst.begin(), lst.end(), std::back_inserter(vec));
    return vec;
  }

  template<typename T>
  void swapItems(std::vector<T> &data, size_t index1, size_t index2) {
    T temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
  }

  template<typename T>
  std::vector<T> bubbleSort(std::vector<T> data) {
    bool sorted{false};
    while (!sorted) { // loop until the data is sorted
      sorted = true;
      // step through each item in the loop
      for (size_t i{1}; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) { // if the current item is less than the item before it, swap those two items
          swapItems(data, i, i-1);
          sorted = false; // the data is sorted once a loop makes no swaps
        }
      }
    }
    return data;
  }

  template<typename T>
  std::vector<T> insertionSort(std::vector<T> data) {
    std::list<T> unsorted{vectorToList(data)};
    std::list<T> sorted{};
    bool insertedItem;
    T item;

    // manually test the first two cases so that there are two items in the sorted list
    sorted.push_back(*unsorted.begin());
    unsorted.pop_front();
    while (!unsorted.empty()) {
      insertedItem = false;
      item = *unsorted.begin();
      for (auto sortPoint{sorted.begin()}; sortPoint != sorted.end(); ++sortPoint) {
        if (item < *sortPoint) {
          sorted.insert(sortPoint, item);
          insertedItem = true;
          break;
        }
      }
      if (!insertedItem) {
        sorted.push_back(item);
      }
      unsorted.pop_front();
    }

    return listToVector(sorted);
  }

  template<typename T>
  std::vector<T> mergeVectors(std::vector<T> vec1, std::vector<T> vec2) {
    std::vector<T> merged{};
    size_t index1{0};
    size_t index2{0};

    while (index1 < vec1.size() && index2 < vec2.size()) {
      if (vec1[index1] < vec2[index2]) {
        merged.push_back(vec1[index1]);
        ++index1;
      }else{
        merged.push_back(vec2[index2]);
        ++index2;
      }
    }

    // only one of these will be executed
    for (; index1 < vec1.size(); ++index1) merged.push_back(vec1[index1]);
    for (; index2 < vec2.size(); ++index2) merged.push_back(vec2[index2]);

    return merged;
  }

  template<typename T>
  std::vector<T> mergeSort(std::vector<T> data) {
    if (data.size() == 1) {
      return data; // if there is only one item in the set, the set is sorted
    }else{
      // otherwise, split the set in half and sort each half
      auto middle = data.begin() + floor(data.size() / 2);
      std::vector<T> vec1{data.begin(), middle};
      std::vector<T> vec2{middle, data.end()};
      return mergeVectors(mergeSort(vec1), mergeSort(vec2)); // haha recursion go brrrr
    }
  }
}

#endif //BAD_SORTS_SORTS_H