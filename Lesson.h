#pragma once
#include <iostream>

// a simple class to represent Lesson
class Lesson
{
public:
    Lesson(char nm[],char lid[]);
    ~Lesson();
    char* get_name(){
        return name;
    }
    char* get_id(){
        return lesson_id;
    }
private:
    // name of the lesson
    char name[20];
    // id of the lesson
    char lesson_id[20];
};

Lesson::Lesson(char nm[],char lid[])
{
    strcpy(name,nm);
    strcpy(lesson_id,lid);
}


