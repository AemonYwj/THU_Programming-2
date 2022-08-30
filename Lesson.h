#pragma once
#include <iostream>

// a simple class to represent Lesson
class Lesson
{
private:
    // name of the lesson
    char name[20];
    // id of the lesson
    char lesson_id[20];
public:
    Lesson(char nm[],char lid[]);
    ~Lesson();
};

Lesson::Lesson(char nm[],char lid[])
{
}

Lesson::~Lesson()
{
}
