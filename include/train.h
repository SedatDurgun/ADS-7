// Copyright 2026 ALGORITHMTASKS
#pragma once

class Train {
 private:
  struct Car {
    bool light;
    Car* next;
    Car* prev;
  };
  int countOp;
  Car* head;
  int countCar;

 public:
  Train();
  ~Train();
  void addCar(bool light);
  int getLenght();
  int getOpCount() const;
};
