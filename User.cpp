//�赵�� �л��� ���� �η��� ���Ͽ� ���� �ø��� �Ǿ����ϴ�.
//�赵�� �л��� user class��, ���� �̸� ����� student class�� professor class�� �ۼ��Ͽ����ϴ�.

#pragma once

#include <iostream>
#include <cstring>
#include <Windows.h>
//#include "Lecture.h"
#include "User.h"

#define _CRT_SECURE_NO_WARNINGS
#define LEN 50

using namespace std;

user::user(int id, const char* n_name, const char* n_password, const char* n_mail, const char* n_ph_num, const char* n_major) {
    ID = id;
    this->name = new char[strlen(n_name) + 1];
    this->password = new char[strlen(n_password) + 1];
    this->mail = new char[strlen(n_mail) + 1];
    this->ph_num = new char[strlen(n_ph_num) + 1];
    this->major = new char[strlen(n_major) + 1];
    strcpy(name, n_name);
    strcpy(password, n_password);
    strcpy(mail, n_mail);
    strcpy(ph_num, n_ph_num);
    strcpy(major, n_major);
}


void user::change_ID(int id) {
    ID = id;
}

void user::change_password(char* n_password) {
    this->password = new char[strlen(n_password) + 1];
    strcpy(password, n_password);
}

void user::change_name(char* n_name) {
    this->name = new char[strlen(n_name) + 1];
    strcpy(name, n_name);
}

void user::change_mail(char* n_mail) {
    this->mail = new char[strlen(n_mail) + 1];
    strcpy(mail, n_mail);
}

void user::change_ph_num(char* n_ph_num) {
    this->ph_num = new char[strlen(n_ph_num) + 1];
    strcpy(ph_num, n_ph_num);
}

void user::change_major(char* n_major) {
    this->major = new char[strlen(n_major) + 1];
    strcpy(major, n_major);
}


int user::get_ID(void) {
    return ID;
}

char* user::get_password(void) {
    return password;
}

char* user::get_name(void) {
    return name;
}

char* user::get_mail(void) {
    return mail;
}

char* user::get_ph_num(void) {
    return ph_num;
}

char* user::get_major(void) {
    return major;
}

user::~user() {
    delete[] name;
    delete[] password;
    delete[] mail;
    delete[] ph_num;
    delete[] major;
}




student::student(int n_student_number, const char* n_name, const char* n_password, const char* n_mail, const char* n_ph_num, const char* n_major)
    : user(n_student_number, n_name, n_password, n_mail, n_ph_num, n_major), grade(0), lecture(NULL) {}
/* void info_time() const{
     cout << this->name << "���� ���ǽð��� " <<Lecture::GetLectureTime() << "�Դϴ�!" << endl;
 }double Lecture::GetLectureTime() const{
     return lectureTime;
     }*/ //�ð�ǥ�� �ʿ��ϰ� �Ǹ� �ؿ����� lecture class�� �־���ҵ�
void student::info_grade() const {
    cout << this->name << "���� ������ " << this->grade << "�Դϴ�!" << endl;
}

void student::AddLecture(const char* n_lecture)
{
    this->lecture = new char[strlen(n_lecture) + 1];
    strcpy(lecture, n_lecture);
}

void student::Addgrade(int n_grade) {
    grade = n_grade;
}

//������û
void student::apply_lecture(LectureHandler& lectHdl) {
    //cout << "���� ���:" << endl;
    if (this->lecture != NULL)
    {
        cout << "�̹� ������û�� ���ǰ� �ֽ��ϴ�." << endl;
    }
    else
    {
        lectHdl.showAllLecture();
        int apply;
        while (true) {
            cout << "\n" << "��û�� �����ڵ��� �Է����ּ��� (-1 �Է����� ���) : ";
            cin >> apply;
            if (apply == -1)
            {
                break;
            }
            Lecture* lec = lectHdl.findLecture(apply);
            if (lec == NULL)
            {
                cout << "�ش� ���ǰ� �����ϴ�. �ٽ� �Է����ּ���." << endl;
            }
            else if (lec->AddStudent(this->ID)) {
                AddLecture(lectHdl.findLecture(apply)->GetLectureName());
                system("cls");
                cout << this->lecture << " ������û�� �����߽��ϴ�." << endl;
                break;
            }
        }
    }
}

student::~student() {
    delete[]lecture;
}

int student::getUser() const
{
    return 1;
}


professor::professor(int n_pro_number, const char* n_name, const char* n_password, const char* n_mail, const char* n_ph_num, const char* n_major)
    :user(n_pro_number, n_name, n_password, n_mail, n_ph_num, n_major) {}

int professor::getUser() const
{
    return 2;
}
