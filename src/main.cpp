// Copyright 2026 ALGORITHMTASKS
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "train.h"

Train* buildTrain(int n, int mode) {
  Train* t = new Train();
  for (int i = 0; i < n; ++i) {
    bool light = false;
    if (mode == 1) light = true;
    else if (mode == 2) light = (rand_r(nullptr) % 2 == 0);
    t->addCar(light);
  }
  return t;
}

int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  const int STEP = 50;
  const int MAX_N = 2000;
  const int REPEATS = 10;
  std::vector<int> sizes;
  std::vector<int64_t> opsOff, opsOn, opsRand;
  for (int n = 2; n <= MAX_N; n += STEP) {
    sizes.push_back(n);
    {
      Train* t = buildTrain(n, 0);
      t->getLenght();
      opsOff.push_back(t->getOpCount());
      delete t;
    }
    {
      Train* t = buildTrain(n, 1);
      t->getLenght();
      opsOn.push_back(t->getOpCount());
      delete t;
    }
    {
      int64_t total = 0;
      for (int r = 0; r < REPEATS; ++r) {
        Train* t = buildTrain(n, 2);
        t->getLenght();
        total += t->getOpCount();
        delete t;
      }
      opsRand.push_back(total / REPEATS);
    }
  }
  {
    std::ofstream f("result/data.csv");
    f << "n,All close,All open,random\n";
    for (size_t i = 0; i < sizes.size(); ++i)
      f << sizes[i] << "," << opsOff[i] << ","
        << opsOn[i] << "," << opsRand[i] << "\n";
  }
  system("python result/plot.py");
  return 0;
}
