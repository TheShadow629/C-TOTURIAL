//������һ��Υ�������ط����C++ʾ����

#include <iostream>
#include <vector>
using namespace std;

class Teacher {
public:
    // ��ȡѧ���б�
    vector<string> getStudentList() {
        vector<string> studentList = { "John", "Alice", "Bob" };
        return studentList;
    }
};

class Course {
private:
    Teacher* teacher;
public:
    Course() : teacher(new Teacher()) {}

    // ��ӡѧ���б�
    void printStudentList() {
        vector<string> students = teacher->getStudentList();
        for (const auto& student : students) {
            cout << student << endl;
        }
    }
};

int main() {
    Course course;
    course.printStudentList();
    return 0;
}
//
//�����������У�����Υ�������ط�������⡣`Course` �������� `Teacher` �࣬��ֱ�ӵ����� `Teacher` ���
//`getStudentList()` ������ȡѧ���б���Υ���˵����ط�����Ϊ `Course` ������˽� `Teacher` ����ڲ�ϸ��
//������֪��Ҫ���� `getStudentList()` ����ȡѧ���б�
//
//������Ʋ�����ɢ��ϣ�`Course` ���� `Teacher` ��֮�����ֱ�ӵ�������ϵ������������֮�������ϡ�
//��� `Teacher` ���ʵ�ַ����仯�����磬�ı��˴洢ѧ���б�ķ�ʽ��������Ҫ�޸� `Course` ��Ĵ��룬
//��Υ���˿���ԭ��͵�һ����ԭ��
//
//Ϊ����ѭ�����ط���`Course` ��Ӧ��ֻ����ֱ�ӵ��ھӽ��н�����������ֱ�ӵ��� `Teacher` ��ķ�����
//һ���������������һ���н��࣬���� `CourseManager`���������� `Teacher` �ཻ�����ṩѧ���б�� `Course` �ࡣ
//������`Course` ��ֻ��Ҫ�� `CourseManager` �ཻ����������Ҫ�˽� `Teacher` ����ڲ�ϸ�ڡ�
//������ƽ����� `Course` ����������ֱ������������˴��������ԺͿ�ά���ԡ�