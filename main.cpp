#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <chrono>
#include <map>

#include "sorts.h"
#include "color-codes.h"

using namespace colorcodes;
using namespace std::chrono;
typedef std::vector<int>(*sortFunction)(std::vector<int> vec);

const std::map<std::string, sortFunction> sortAlgs{
    {"bubble", sorts::bubbleSort},
    {"insertion", sorts::insertionSort},
    {"merge", sorts::mergeSort}
};

// shamelessly taken from StackOverflow
int randInt(const int min, const int max) {
  std::random_device rd;     // Only used once to initialise (seed) engine
  std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
  std::uniform_int_distribution<int> uni(min,max); // Guaranteed unbiased
  return uni(rng);
}

double testAndVerify(sortFunction fn, std::vector<int> &dataset, const std::string &name="") {
  auto startTime = high_resolution_clock::now();
  std::cout << "Running " << name << " sort...\n";
  std::vector<int> sorted = fn(dataset);
  auto endTime = high_resolution_clock::now();
  double elapsedTime = duration<double, std::milli>{endTime - startTime}.count();
  std::cout << "Completed " << name << " sort in " << elapsedTime << "ms\n";
  std::cout << "Verifiying " << name << " sort...";
  if (sorts::verifySort(sorted)) {
    std::cout << textColors::green << "VERIFIED" << textColors::default_ << '\n';
  }
  else {
    std::cout << textColors::red << "FAILED" << textColors::default_ << '\n';
  }

  return elapsedTime;
}

void runTest(int dataSize, int numTests, int dataRange, std::ofstream &logFile) {
  std::cout << "Building dataset of size " << textColors::yellow << dataSize << textColors::default_ << '\n';
  for (int i{0}; i < numTests; ++i) {
    logFile << dataSize << ',';
    std::vector<int> dataset{};
    std::vector<int> sortedData{};
    for (int d{0}; d < dataSize; ++d) {
      dataset.push_back(randInt(0, dataRange));
    }
    for (const auto &[name, alg] : sortAlgs) {
      logFile << testAndVerify(alg, dataset, name) << ',';
    }
    logFile << '\n';
    std::cout << '\n';
  }

}

int setSize{200};
int numSets{50};
int numTests{10};
int sizeIncrement{200};
int range{1000000};

int main() {
  std::ofstream logFile("./outputs/executionTimes.csv");
  logFile << "Dataset Size,Bubble,Insertion,Merge\n";

  for (int i{0}; i < numSets; ++i) {
    runTest(setSize, numTests, range, logFile);
    setSize += sizeIncrement;
  }
}