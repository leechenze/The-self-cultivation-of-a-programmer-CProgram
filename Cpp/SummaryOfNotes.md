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
    
    
