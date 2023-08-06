//以下是一个违反迪米特法则的C++示例：

#include <iostream>
#include <vector>
using namespace std;

class Teacher {
public:
    // 获取学生列表
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

    // 打印学生列表
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
//在上述代码中，存在违反迪米特法则的问题。`Course` 类依赖于 `Teacher` 类，并直接调用了 `Teacher` 类的
//`getStudentList()` 方法获取学生列表。这违反了迪米特法则，因为 `Course` 类必须了解 `Teacher` 类的内部细节
//，即它知道要调用 `getStudentList()` 来获取学生列表。
//
//这种设计不够松散耦合，`Course` 类与 `Teacher` 类之间存在直接的依赖关系，导致两个类之间紧密耦合。
//如果 `Teacher` 类的实现发生变化（例如，改变了存储学生列表的方式），则需要修改 `Course` 类的代码，
//这违背了开闭原则和单一责任原则。
//
//为了遵循迪米特法则，`Course` 类应该只与其直接的邻居进行交互，而不是直接调用 `Teacher` 类的方法。
//一个解决方案是引入一个中介类，例如 `CourseManager`，它负责与 `Teacher` 类交互并提供学生列表给 `Course` 类。
//这样，`Course` 类只需要与 `CourseManager` 类交互，而不需要了解 `Teacher` 类的内部细节。
//这种设计将减少 `Course` 类对其他类的直接依赖，提高了代码的灵活性和可维护性。