博学之, 审问之, 慎思之, 明辨之, 笃行之;
零、壹、贰、叁、肆、伍、陆、柒、捌、玖、拾;






零.第一个Cpp程序 (helloworld)
    
    命令行gcc运行:
        指定输出:
            gcc -lstdc++ main.cpp -o test
                生成 test
            ./test
                输出： Hello World！
        不指定输出:
            gcc -lstdc++ main.cpp
                生成 a.out
            ./a.out
                输出： Hello World！
    CLion集成环境：
        Tools ==> CMake ==> Unload CMake Project
        这样会在 cpp 文件中自动提示 Create CMakeLists.txt
        点击它将自动在根目录生成 CMakeLists.txt 配置文件
    
    XCode集成环境：
        Create a new Xcode Project
        macos ==> Command Line Tool
        在项目构建窗口中自行配置项目信息，注意Language 选择 C++ 即可。
    
    后续都将用XCode集成环境进行学习
    
    
    
    
    
    

壹.命名&注释&变量&常量 (001designate&variable&Constant)
    
    数据是信息的载体,C程序大多时的目的就是为了处理数据.
    数据的分类:
        数字,字符,字符串三种类型:
        字符是单引号,字符串是双引号.
    
    输出数据:
        std::cout               可以输出各种类型的数据
        <<                      操作符可以拼接多个数据项
        std::endl               也可以用于换行
        using namespace std;    指定缺省的命名空间
    
    注释:
        单行注释: //
        单行注释: /**/
        多行注释可以注释掉单行注释,单行注释也可以注释掉多行注释(牛逼,已经不认识释这个字了)
    
    变量:
        ... TODO ...
    
    
    
    








零、壹、贰、叁、肆、伍、陆、柒、捌、玖、拾;
