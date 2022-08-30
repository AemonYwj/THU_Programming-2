#pragma once
#include <iostream>

// a base class for both teachers and students.
// DATA ATTRIBUTES:
//  char name[20]
//  char id[20]
//  int authority;
class Human
{
public:
    Human(/* args */);
    ~Human();
    char* get_name(){
        return name;
    }
    char* get_id(){
        return id;
    }
    int get_authority(){
        return authority;
    }
private:
    char name[20];
    char id[20];
    int authority;
};

class Student
{
private:
    char name[20];
    char id[20];
    int authority = 0;
public:
    Student(char nm[],char id[]);
    ~Student();
};

// The constructor of Student
// INPUT: char nm[],char id1[]
// NOTE: remember to make sure that the INPUT id1 consists of only intergar
//  and that no taken before
Student::Student(char nm[],char id1[])
{
    strcpy(name,nm);
    strcpy(id,id1);
}

class Teacher
{
private:
    char name[20];
    char id[20];
    int authority = 0;
public:
    Teacher(char nm[],char id[]);
    ~Teacher();
};

// The constructor of Teacher
// INPUT: char nm[],char id1[]
// NOTE: remember to make sure that the INPUT id1 consists of only intergar
//  and that no taken before
Teacher::Teacher(char nm[],char id1[])
{
    strcpy(name,nm);
    strcpy(id,id1);
}
