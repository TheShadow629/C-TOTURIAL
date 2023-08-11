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
//Model-View-Controller (MVC) 模式是软件开发中广泛使用的架构模式。它将应用程序分为三个相互连接的组件：
//模型（Model）、视图（View）和控制器（Controller）。
//
//1. 模型（Model）：
//模型代表应用程序的数据和业务逻辑。它封装数据并提供操作和访问数据的方法。模型会通知视图和控制器数据的任何变化。
//在 MVC 模式中，模型独立于视图和控制器。
//
//2. 视图（View）：
//视图负责将模型的数据呈现给用户界面并进行显示。它接收来自模型的更新，并反映对数据的任何更改。视图是被动的，
//不包含任何业务逻辑。它将用户的操作委托给控制器。
//
//3. 控制器（Controller）：
//控制器处理用户输入，充当视图和模型之间的中介。它通过视图接收用户输入，并相应地更新模型。它还接收来自模型的通知，
//并更新视图以反映数据的变化。控制器包含应用程序的逻辑，协调模型和视图之间的数据流动。
//
//下面我们使用 C++ 实现一个简单的 MVC 模式示例：
//
//```cpp
//#include <iostream>
//
//// 模型（Model）
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
//// 视图（View）
//class UserView {
//public:
//    void displayUser(const std::string& name) {
//        std::cout << "用户: " << name << std::endl;
//    }
//};
//
//// 控制器（Controller）
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
//// 主程序
//int main() {
//    UserController userController;
//
//    // 通过控制器更新用户名
//    userController.updateUserName("张三");
//
//    // 通过控制器显示用户信息
//    userController.displayUserInfo();
//
//    return 0;
//}
//```
//
//在上述代码中：
//- `UserModel` 类表示模型（Model），它封装用户的数据（姓名）并提供操作数据的方法。
//- `UserView` 类表示视图（View），负责将用户的数据显示到用户界面。在本例中，它简单地打印用户的姓名。
//- `UserController` 类表示控制器（Controller），处理用户输入并相应地更新模型。它还更新视图以反映数据的变化。
//控制器包含模型和视图的实例。
//
//在 `main` 函数中：
//- 创建了 `UserController` 的实例。
//- 通过控制器使用 `updateUserName` 子程序更新用户的姓名。
//- 通过控制器使用 `displayUserInfo` 子程序显示用户信息。
//
//代码中使用注释突出显示了 MVC 模式的部分，指出哪些部分对应于模型（UserModel）、视图（UserView）和控制器（UserController）。