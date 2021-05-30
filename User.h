#pragma once
#define LEN 50
#include "LectureHandler.h"

class user {
protected:
    int ID;
    char* name;
    char* password;
    char* mail;
    char* ph_num;
    char* major;
public:
    user(int id, const char* n_name, const char* n_password, const char* n_mail, const char* n_ph_num, const char* n_major);
    void change_ID(int id);
    void change_password(char* n_password);
    void change_name(char* n_name);
    void change_mail(char* n_mail);
    void change_ph_num(char* n_ph_num);
    void change_major(char* n_major);
    int get_ID(void);
    char* get_password(void);
    char* get_name(void);
    char* get_mail(void);
    char* get_ph_num(void);
    char* get_major(void);
    virtual int getUser() const = 0;
    ~user();
};
class student :public user {
private:
    int grade;
    char* lecture;
public:
    student(int n_student_number, const char* n_name, const char* n_password, const char* n_mail, const char* n_ph_num, const char* n_major);
    void info_grade() const;
    void AddLecture(const char* n_lecture);
    void Addgrade(int n_grade);
    void apply_lecture(LectureHandler&);
    int getUser() const;
    ~student();
};

class professor :public user {
public:
    professor(int n_pro_number, const char* n_name, const char* n_password, const char* n_mail, const char* n_ph_num, const char* n_major);
    int getUser() const;
};
