////The Model - View - Controller(MVC) pattern is a widely used architectural pattern in software development.It separates the application into three interconnected components : the Model, the View, and the Controller.
////
////1. Model :
////    The Model represents the application's data and the business logic. It encapsulates the data and provides methods to manipulate and access it. The Model notifies the View and the Controller of any changes in the data. In the MVC pattern, the Model is independent of the View and the Controller.
////
////    2. View :
////    The View is responsible for rendering the Model's data to the user interface and displaying it. It receives updates from the Model and reflects any changes made to the data. The View is passive and does not contain any business logic. It delegates user actions to the Controller.
////
////    3. Controller :
////    The Controller handles user input and acts as an intermediary between the View and the Model.It receives input from the user through the View and updates the Model accordingly.It also receives notifications from the Model and updates the View to reflect changes in the data.The Controller contains the application's logic and orchestrates the flow of data between the Model and the View.
////
////    Now let's implement a simple example of the MVC pattern in C++:
////
////#include <iostream>
////
////    // Model
////    class UserModel {
////    private:
////        std::string name;
////
////    public:
////        void setName(const std::string& name) {
////            this->name = name;
////        }
////
////        std::string getName() const {
////            return name;
////        }
////};
////
////// View
////class UserView {
////public:
////    void displayUser(const std::string& name) {
////        std::cout << "User: " << name << std::endl;
////    }
////};
////
////// Controller
////class UserController {
////private:
////    UserModel userModel;
////    UserView userView;
////
////public:
////    void updateUserName(const std::string& name) {
////        userModel.setName(name);
////    }
////
////    void displayUserInfo() {
////        std::string name = userModel.getName();
////        userView.displayUser(name);
////    }
////};
////
////// Main program
////int main() {
////    UserController userController;
////
////    // Updating the name through the Controller
////    userController.updateUserName("John Doe");
////
////    // Displaying the user info through the Controller
////    userController.displayUserInfo();
////
////    return 0;
////}
////```
////
////In the above code, we have :
////-The `UserModel` class represents the Model, which encapsulates the user's data (name) and provides methods to manipulate it.
////- The `UserView` class represents the View, responsible for displaying the user's data to the user interface. In this example, it simply prints the user's name.
////- The `UserController` class represents the Controller, which handles user input and updates the Model accordingly.It also updates the View to reflect changes in the data.It contains instances of both the Model and the View.
////
////In the `main` function :
////    -We create an instance of the `UserController`.
////    - We update the user's name through the Controller using the `updateUserName` subroutine.
////    - We display the user's info through the Controller using the `displayUserInfo` subroutine.
////
////    The use of the MVC pattern is highlighted in the code with comments indicating which parts correspond to the Model(UserModel), the View(UserView), and the Controller(UserController).
//
//Model-View-Controller (MVC) ģʽ����������й㷺ʹ�õļܹ�ģʽ������Ӧ�ó����Ϊ�����໥���ӵ������
//ģ�ͣ�Model������ͼ��View���Ϳ�������Controller����
//
//1. ģ�ͣ�Model����
//ģ�ʹ���Ӧ�ó�������ݺ�ҵ���߼�������װ���ݲ��ṩ�����ͷ������ݵķ�����ģ�ͻ�֪ͨ��ͼ�Ϳ��������ݵ��κα仯��
//�� MVC ģʽ�У�ģ�Ͷ�������ͼ�Ϳ�������
//
//2. ��ͼ��View����
//��ͼ����ģ�͵����ݳ��ָ��û����沢������ʾ������������ģ�͵ĸ��£�����ӳ�����ݵ��κθ��ġ���ͼ�Ǳ����ģ�
//�������κ�ҵ���߼��������û��Ĳ���ί�и���������
//
//3. ��������Controller����
//�����������û����룬�䵱��ͼ��ģ��֮����н顣��ͨ����ͼ�����û����룬����Ӧ�ظ���ģ�͡�������������ģ�͵�֪ͨ��
//��������ͼ�Է�ӳ���ݵı仯������������Ӧ�ó�����߼���Э��ģ�ͺ���ͼ֮�������������
//
//��������ʹ�� C++ ʵ��һ���򵥵� MVC ģʽʾ����
//
//```cpp
//#include <iostream>
//
//// ģ�ͣ�Model��
//class UserModel {
//private:
//    std::string name;
//
//public:
//    void setName(const std::string& name) {
//        this->name = name;
//    }
//
//    std::string getName() const {
//        return name;
//    }
//};
//
//// ��ͼ��View��
//class UserView {
//public:
//    void displayUser(const std::string& name) {
//        std::cout << "�û�: " << name << std::endl;
//    }
//};
//
//// ��������Controller��
//class UserController {
//private:
//    UserModel userModel;
//    UserView userView;
//
//public:
//    void updateUserName(const std::string& name) {
//        userModel.setName(name);
//    }
//
//    void displayUserInfo() {
//        std::string name = userModel.getName();
//        userView.displayUser(name);
//    }
//};
//
//// ������
//int main() {
//    UserController userController;
//
//    // ͨ�������������û���
//    userController.updateUserName("����");
//
//    // ͨ����������ʾ�û���Ϣ
//    userController.displayUserInfo();
//
//    return 0;
//}
//```
//
//�����������У�
//- `UserModel` ���ʾģ�ͣ�Model��������װ�û������ݣ����������ṩ�������ݵķ�����
//- `UserView` ���ʾ��ͼ��View���������û���������ʾ���û����档�ڱ����У����򵥵ش�ӡ�û���������
//- `UserController` ���ʾ��������Controller���������û����벢��Ӧ�ظ���ģ�͡�����������ͼ�Է�ӳ���ݵı仯��
//����������ģ�ͺ���ͼ��ʵ����
//
//�� `main` �����У�
//- ������ `UserController` ��ʵ����
//- ͨ��������ʹ�� `updateUserName` �ӳ�������û���������
//- ͨ��������ʹ�� `displayUserInfo` �ӳ�����ʾ�û���Ϣ��
//
//������ʹ��ע��ͻ����ʾ�� MVC ģʽ�Ĳ��֣�ָ����Щ���ֶ�Ӧ��ģ�ͣ�UserModel������ͼ��UserView���Ϳ�������UserController����