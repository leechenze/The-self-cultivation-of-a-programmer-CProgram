博学之, 审问之, 慎思之, 明辨之, 笃行之;
零、壹、贰、叁、肆、伍、陆、柒、捌、玖、拾;




本机的CentOS系统账号密码: localhost-VMWareFusion-[CentOS-64-Arm.vmwarevm]

    IP:         172.16.168.136
        在VMWareFusion中通过ifconfig查看 ens000 查看IP
    username:   anglee
    password:   930316
    Ubuntu安装教程:     BV1JN4y1d7Q3

本机的Ubuntu系统账号密码: localhost-VMWareFusion-[Ubuntu-64-bit-Arm-Server-24.04.2.vmwarevm]

    IP:         172.16.168.134
        在VMWareFusion中通过ifconfig查看 ens000 查看IP
    username:       anglee
    password:       930316
    Ubuntu安装教程:     BV1V4421D7Gt

通过 VSCode 或 Termius 连接该地址进行操作(VMWareFusion的图形界面既丑又难用)

VNWare快照功能使用(snapshot)











零.初识Linux(000IntroductionToLinux)

    Linux目录结构
        常见的根目录说明:
            /bin:         **Binary**, 存放系统启动和运行过程中必需的用户命令, 比如 `ls`、`cp`、`rm`、`cat` 等. 所有用户都能使用. 
            /sbin:        **System Binary**, 存放系统管理员使用的系统管理命令, 比如 `reboot`、`ifconfig`、`iptables` 等, 普通用户一般不能直接使用
            /boot:        系统启动相关文件, 比如内核（`vmlinuz`）、引导程序（如 `grub`）都在这里. 系统能否启动与此密切相关. 
            /dev:         **Device**, 设备文件目录. Linux 把所有设备都当作文件, 比如 `/dev/sda`（硬盘）, `/dev/null`（空设备）. 
            /etc:         系统配置文件所在目录, 比如网络、用户、服务配置都在这里. 如 `/etc/passwd`、`/etc/fstab`、`/etc/hosts`. 
            /home:        用户的主目录. 例如用户 `tom` 的主目录是 `/home/tom`. 用户的桌面、下载等都放在这里. 
            /lib:         系统运行所需的共享库（.so 文件）, 为 `/bin` 和 `/sbin` 目录下的程序提供依赖支持. 
            /lib64:       专门为 64 位库文件预留的目录（64 位系统才有）. 
            /media:       可移动介质（如 U 盘、CD-ROM）自动挂载点, 插入时一般挂载到这里. 
            /mnt:         手动临时挂载文件系统的挂载点, 用户或管理员可以将设备挂载在此以访问内容. 
            /opt:         额外安装的**第三方应用程序**放在这里, 常见于大型商业软件（如 Chrome、VMware、jdk 等）. 
            /proc:        内核和进程信息的虚拟文件系统（不占磁盘空间）, 如 `/proc/cpuinfo` 查看 CPU 信息、`/proc/[pid]` 查看进程状态. 
            /root:        超级用户（root）的主目录, 对应普通用户的 `/home/username`. 
            /run:         系统启动时临时存储运行时数据, 如 PID 文件、Socket 文件等（取代旧的 `/var/run`）. 
            /srv:         服务数据目录, 例如 Web 或 FTP 服务的根目录可能放这里.
            /sys:         类似 `/proc`, 用于与内核交互的虚拟文件系统, 展现硬件设备结构. 
            /tmp:         临时文件目录, 系统或应用运行时会在这里生成临时文件, 系统重启后可自动清空. 
            /usr:         存放系统中安装的共享只读数据, 包括用户命令、库文件、文档等, 结构类似 `/`例如:
                `/usr/bin`:             普通命令
                `/usr/lib`:             库文件
                `/usr/share`:           共享数据
                `/usr/local`:           用户本地安装软件
            /var:         可变数据目录, 用于存放日志、缓存、邮件、打印等数据, 比如:
                `/var/log`:             日志文件
                `/var/spool`:           打印队列
                `/var/cache`:           缓存
    
    Linux常见的命令格式:
        command [-options] [parameter]
        命令本体 [-命令选项] [命令参数]
        例如: ls -l /usr/local
            以列表的形式显示/usr/local目录下的内容
        注意:
            cp -rv ./test01/* ./test02
            这种命令中的./可以省略, 为:
            cp -rv test01/* test02

    Linux常见发行版及安装工具:
        | 发行版                          | 包管理器命令        | 使用的包格式        | 说明                                    |
        | ------------------------       | ----------------- | --------------    | ----------------------------           |
        | ** Ubuntu / Debian **          | `apt` / `dpkg`    | `.deb`            | `apt` 是高级前端, 常用；`dpkg` 是底层工具。 |
        | ** Debian **                   | `apt` / `apt-get` | `.deb`            | `apt-get` 更老, `apt` 更简洁、推荐使用。   |
        | ** CentOS / RHEL 7- **         | `yum`             | `.rpm`            | 适用于旧版 RHEL/CentOS 系列。             |
        | ** CentOS / RHEL 8+ **         | `dnf`             | `.rpm`            | `yum` 的现代替代版, 更快、更安全。          |
        | ** Linux Mint **               | `apt`             | `.deb`            | 基于 Ubuntu, 工具相同。                   |
        | ** Kali Linux **               | `apt`             | `.deb`            | 基于 Debian。                           |
        | ** Fedora **                   | `dnf` / `rpm`     | `.rpm`            | `rpm` 是底层工具, `dnf` 推荐使用。         |
        | ** openSUSE **                 | `zypper`          | `.rpm`            | zypper 是 YaST 的命令行前端。             |
        | ** Arch Linux / Manjaro **     | `pacman`          | `.pkg.tar.zst`    | 简洁快速的包管理器, 支持二进制和源码安装。     |
        | ** Alpine Linux **             | `apk`             | `.apk`            | 极小型发行版, 适用于 Docker 等轻量环境。     |
        | ** Gentoo **                   | `emerge`          | 源码包             | 源码级包管理, 功能强大但安装慢。             |
        | ** Slackware **                | `slackpkg`        | `.tgz`            | 较传统, 较手工化的包管理。                  |














壹.Linux基础命令(001BasicLinuxCommands)

    Linux常用命令:
        history
            说明:
                历史管理命令
            选项:
                -c          清空历史
                -d          N 删除第N条
                !N          执行第N条命令
                !!          上一条命令
                !string	    执行最近一次以 string 开头的命令
                !?string?	执行最近包含 string 的命令
            示例:
                history | grep ssh          ==>         搜索含"ssh"的历史命令
                !4                          ==>         执行历史记录中第4条命令
                !!                          ==>         执行上一次的命令(!! 等同于 !-1)
                !-2                         ==>         执行上两次的命令
        ls
            说明:
                列举文件内容
            选项:
                -l  详细列表
                -a  显示隐藏文件
                -d  显示目录
                -f  显示文件
                -h  人性化大小,即显示文件大小的单位
                -t  按时间排序
                -R  递归列出
            示例:
                ls -l /usr/local            ==>         显示/usr/local目录下的内容,以列表的形式
                ls test*                    ==>         显示名称为前缀为test的 文件和目录
                ls test??                   ==>         显示名称为前缀为test, 并且之后只有两个通配符的 目录(不含文件, 文件需要加后缀)
                ls test??.txt               ==>         显示名称为前缀为test, 并且之后只有两个通配符的 txt文件
                ls test??.*                 ==>         显示名称为前缀为test, 并且之后只有两个通配符的 任意文件
        mkdir
            说明:
                创建目录
            选项:
                -p  创建多级目录
                -m  设置权限
                -v  显示过程
            示例:
                mkdir -m 755 -p project/{src,doc,bin}           ==>         递归创建project及其子目录, 设置权限为755
                mkdir -p project/{src,doc,bin}                  ==>         递归创建project及子目录 src, doc, bin
                mkdir test01 test02                             ==>         创建test01和test02目录
        rmdir
            说明:
                删除空目录
            选项:
                -p  删除空父目录
            示例:
                rmdir -p tmp/a/b            ==>         删除 b/ 后若 a/ 和 tmp/ 为空, 则一并删除
        cp
            说明:
                复制文件/目录
            选项:
                -   r递归目录
                -   p保留属性
                -   a归档模式（= -dpr）
                -   i覆盖前提示
                -   v显示过程
            示例:
                cp -rv ./test01 ./test02              ==>         复制 test01 目录到 test02, 并显示详细过程, 注意结果将是: test02/test01.
                cp -rv ./test01/* ./test02            ==>         复制 test01 目录下的所有目录和文件到 test02, 并显示详细过程.
        mv
            说明:
                移动/重命名文件
            选项:
                -i  覆盖提示
                -v  显示过程
                -f  强制覆盖
                -u  只移动更新的文件
            示例:
                mv -rv ./test01 ./test02              ==>         移动 test01 目录到 test02, 并显示详细过程, 注意结果将是: test02/test01.
                mv -rv ./test01/* ./test02            ==>         移动 test01 目录下的所有目录和文件到 test02, 并显示详细过程.
                mv -u *.log /archive/                 ==>         仅移动比目标目录更新的 .log 文件到 /archive, 注意不是跟 目标目录 /archive/ 本身 比较时间, 而是跟 目标目录中是否已存在相同文件名的文件 进行比较!
        rm	
            说明:
                删除文件/目录
            选项:
                -r  递归删除
                -f  强制删除
                -i  删除前确认
                -v  显示过程		
            示例:
                rm -rf ~/cache/*            ==>         强制删除~目录下的cache内所有文件
        stat
            说明:
                显示文件元数据
            选项:
                -c  自定义格式
                -f  显示文件系统状态		
            示例:
                stat -c "%A %U %s" test01.txt           ==>         输出test01.txt的权限, 所有者和字节大小
                stat -c %n:%s test01.txt	            ==>         输出test01.txt的文件名和大小
                stat -c %y test01.txt                   ==>         输出test01.txt的最后修改时间
                stat test01.txt                         ==>         输出test01.txt的所有详细信息
            补充:
                stat -c "%A %U %s" test01.txt
                还可以写为
                stat -c %A-%U-%s" test01.txt
                stat -c %A:%U:%s" test01.txt
        file	
            说明:
                检测文件类型
            选项:
                -b  简化输出
                -i  输出MIME类型
            示例:
                file -bi image.jpg          ==>         简化输出image.jpg的MIME类型（如image/jpeg）
        find
            说明:
                搜索文件
            选项:
                -name   按名称
                -type   按类型
                -exec   执行命令
                -mtime  按修改时间
            示例:
                find / -type f -name "*.conf" -mtime -7         ==>         搜索系统中7天内修改过的.conf配置文件
                find . -name "file.txt"                         ==>         在当前目录及子目录中查找名为 file.txt 的文件(大小写敏感)
                find . -iname "file.txt"                        ==>         在当前目录及子目录中查找名为 file.txt 的文件(忽略大小写)
                find . -type d                                  ==>         查找当前目录下的所有目录
                find . -type f                                  ==>         查找当前路径下所有普通文件
                find . -type f -empty                           ==>         查找大小为 0 字节的空文件
                find . -type d -empty                           ==>         查找无内容的空目录
                find . -mtime -3	                            ==>         查找最近 3 天内修改过的文件
                find . -amin -10	                            ==>         查找 10 分钟内访问过的文件
                find . -size +10M	                            ==>         查找大于 10MB 的文件
                find . -user root	                            ==>         查找属于 root 用户的文件
                find . -type f -perm 0777	                    ==>         查找权限为 777 的文件
                find . -name "*.tmp" -delete	                ==>         删除所有 .tmp 文件
                find . -name "*.conf" -exec cp {} /backup/ \;	==>         找到每个 .conf 文件并复制到 /backup/
                find . -newer ref.txt	                        ==>         查找比 ref.txt 更新的文件
                find . ! -newer ref.txt	                        ==>         查找比 ref.txt 更老的文件
        tar	
            说明:
                归档压缩工具
            选项:
                -c  创建归档
                -C  解压时指定解压的目的地
                -x  解包归档
                -v  显示过程
                -t	显示归档列表
                -f  指定文件
                -z  gzip压缩/解压（.tar.gz）
                -J	xz压缩/解压（.tar.xz）
            示例:
                tar -czvf backup.tar.gz /data           ==>         将 /data 目录压缩为backup.tar.gz（gzip格式）
                tar -cvf archive.tar dir/	            ==>         打包 dir/ 成 archive.tar, 只打包
                tar -czvf archive.tar.gz dir/	        ==>         打包并使用 gzip 压缩
                tar -xvf archive.tar	                ==>         解包 .tar 文件
                tar -xzvf archive.tar.gz	            ==>         解压 .tar.gz 文件
                tar -tvf archive.tar.gz	                ==>         显示归档中的文件列表
                tar -xzvf archive.tar.gz -C /tmp	    ==>         解压到 /tmp 目录
            注意:
                1.tar是一个打包工具, 并不是一个压缩工具, 是否压缩要带有 -z 或 -J参数
                2.命令选项顺序在保证f为最后时可以随便, 如: -czvf ==> -zcvf, -vzcf, -cvzf, 但 -cfvz 就不行, 因为 -f 之后要紧跟输出的文件名, 否则就错乱了, 确保 -f 紧跟归档文件名.
        zip
            说明:
                压缩工具
            选项:
                -r	递归压缩目录（压缩整个文件夹）
                -q	安静模式, 不显示过程信息
                -v	显示详细信息（verbose）
                -9	最大压缩率（等级 0～9, 9 表示最小体积）
                -e	给压缩包加密码
                -x	排除指定文件或目录
                -m	压缩后删除源文件（即“移动”成压缩包）
            示例:
                zip archive.zip file1.txt                       ==>         将 file1.txt 压缩为 archive.zip. 
                zip archive.zip file1.txt file2.txt file3.txt   ==>         将 file1,2,3.txt多个文件 压缩为 archive.zip. 
                zip -r project.zip my_project/                  ==>         将 my_project 目录及其目录下所有内容递归压缩为 project.zip. 
                zip -e secret.zip file.txt                      ==>         将为 secret.zip 设密压缩, 压缩文件时要求输入密码保护.
                zip -r code.zip src/ -x "*.log" "*.tmp"         ==>         递归压缩 src/, 但排除所有 .log 和 .tmp 文件. 
        unzip
            说明:
                解压工具
            选项:
                -l	列出 zip 文件的内容, 不解压
                -v	显示详细信息（类似 -l, 但更详细）
                -d  将内容解压到指定目录
                -o	解压时自动覆盖已有文件（默认会询问）
                -n	解压时不覆盖已有文件
                -q	安静模式, 不输出过程信息
                -x  解压时排除指定的文件
            示例:
                unzip file.zip                                  ==>         将 file.zip 的内容解压到当前目录
                unzip file.zip -d /tmp/myfiles/                 ==>         将 zip 文件解压到 /tmp/myfiles/ 目录下
                unzip -l file.zip                               ==>         列出 zip 中包含的所有文件和路径, 不解压
                unzip file.zip myfolder/file1.txt               ==>         只解压 zip 中的 myfolder/file1.txt 文件
                unzip file.zip -x "*.txt"                       ==>         ==>         只解压 zip 中的 myfolder/file1.txt 文件
        cd
            说明:
                changes diretory
            示例:
                cd /                                    ==>         到根目录
                cd .                                    ==>         到当前目录(没用)
                cd ..                                   ==>         返回上一级目录
                cd ../..                                ==>         返回上两级目录(以此类推)
                cd /usr/local/xxx                       ==>         到/usr/local/xxx目录
        pwd
            说明:
                print work directory
            示例:
                pwd                                     ==>         打印当前工作工作目录
        which/whereis/type
            说明:
                输出可执行文件的绝对路径
            选项:
                -a  显示所有匹配的路径(而不仅是第一个)
            示例:
                which ls	                            ==>         查找 ls 命令的可执行文件路径, 通常输出 /bin/ls
                which python3	                        ==>         显示当前系统中 python3 命令的位置
                which -a python3	                    ==>         显示所有匹配的 python3 路径（如果 PATH 中有多个）
                which gcc	                            ==>         查看当前使用的 gcc 编译器的位置
        touch
            说明:
                创建文件
            示例:
                touch file.txt                          ==>         创建空文件 file.txt
                touch file1 file2                       ==>         同时创建 file1 和 file2 文件
        cat
            说明:
                查看文件内容
            选项:
                -n  显示所有行号（包括空行）
                -b	显示所有行号（不包括空行）
                -s	压缩连续空行为一行空行
                -A	显示所有不可见字符
            内部操作:
                Ctrl+D      保存并退出
            示例:
                cat file.txt	                        ==>         输出file文件内容
                cat file1.txt file2.txt                 ==>         按顺序合并显示两个文件内容
                cat > file.txt                          ==>         从标准输入覆盖写入内容到 file.txt（Ctrl+D 保存）
                cat file1 file2 > all.txt	            ==>         合并两个文件内容写入到 all.txt 中
                cat >> file.txt                         ==>         从标准输入追加写入内容到 file.txt（Ctrl+D 保存）
                cat -b file.txt                         ==>         输出file文件内容, 并显示行号（不包括空行）
            注意:
                cat 不适合查看大文件, 推荐使用 less、more. 
        nl
            说明:
                等同于 cat -b
            示例:
                nl file.txt                             ==>         输出file文件内容, 并显示行号（不包括空行）
        more
            说明:
                查看文件内容
            选项:
                -n	每页显示 n 行
                +n	从第 n 行开始显示
                -d	显示提示, 如 "Press space to continue"
                -s	合并多空行为一行空行
            内部操作
                空格	     显示下一页
                Enter	    向下滚动一行
                b	        返回上一页
                q	        退出查看
                s	        跳过一行
            示例:
                more -10 longfile.txt                   ==>         每页显示10行
                more +20 config.txt                     ==>         从第20行开始查看
                more -1 +3 test04.txt                   ==>         从第三行开始显示, 每页显示一行
        less
            说明:
                查看文件内容
            选项:
                -N	    显示行号
                -S	    不自动换行, 超长行水平滚动
                +n	    从第 n 行开始显示
                +/word	打开时直接搜索某个关键词
            内部操作
                空格 / f	         下一页
                b	                上一页
                ↑ / ↓	            上下滚动一行
                /word	            向下搜索
                ?word	            向上搜索
                n / N	            下一个/上一个搜索结果
                q	                退出
            示例:
                less -N file.txt                        ==>         带行号查看
                less +45 file.txt                       ==>         从第45行开始
                less +/error log.txt                    ==>         打开直接跳转到第一个 error 处
        head
            说明:
                查看文件头几行
            选项:
                -n N	显示前 N 行
                -c N	显示前 N 字节
            示例:
                head -n 5 file.txt                      ==>         显示前5行
                head -c 20 file.txt                     ==>         显示前20个字节
        tail
            说明:
                查看末尾几行
            选项:
                选项	     含义
                -n N	    显示最后 N 行
                -c N	    显示最后 N 字节
                -f	        实时输出追加内容（常用于日志监控）
                -F	        类似 -f, 但文件被替换后也能继续监听
            示例:
                tail -n 20 access.log                   ==>         查看最后20行
                tail -f server.log                      ==>         实时查看日志追加
                tail -fn 5 test04.txt                   ==>         实时查看test04.txt并只显示最后5行
        ps
            说明:
                查看当前系统运行的进程信息(快照, 非实时状态)
            选项:
                -e 或 -A	显示所有进程（相当于全系统）
                -f	        全格式输出（包含 PPID、UID、CMD 等）
                -u          用户名	显示某个用户的进程
                -x	        显示无终端控制的进程（如守护进程）
                -o	        指定输出字段, 例如 ps -eo pid,cmd
                -l	        长格式输出（显示 F, PRI, NI 等更多字段）
                -p PID	    显示指定 PID 的进程信息
                -C 名称	     按命令名查找进程（如 -C nginx）
                aux（无 -）	 传统 BSD 格式显示所有进程
                ef（无 -）	 显示完整格式及树形结构（SysV 风格）
            输出说明:
                PID	        进程 ID
                PPID	    父进程 ID
                USER	    进程所属用户
                %CPU	    占用 CPU 百分比
                %MEM	    占用内存百分比
                VSZ	        占用虚拟内存大小（KB）
                RSS	        实际使用的物理内存（KB）
                STAT	    进程状态（如 S 睡眠, R 运行, Z 僵尸）
                TTY	        关联的终端
                TIME	    占用的 CPU 时间
                CMD	        启动命令及参数
            示例:
                ps -ef                                  ==>         显示所有列
                ps -eo pid,ppid,cmd,%mem,%cpu           ==>         输出自定义列, 只显示 进程ID,内存,CPU占用等
                ps -C nginx                             ==>         查找 cmd 列名为 nginx 的进程
                ps -ef | grep nginx                     ==>         查找 cmd 列名包含 nginx 的进程
        df
            说明:
                用于显示文件系统磁盘空间的总容量、已用空间和可用空间
            选项:
                -h	        以人类可读的格式显示（自动换算成 KB/MB/GB）
                -H	        类似 -h, 但使用1000进制（千进制）单位
                -k	        以 KB 为单位显示（默认单位）
                -m	        以 MB 为单位显示
                -T	        显示文件系统类型（ext4、tmpfs 等）
                -i	        显示 inode 使用情况（文件节点数量）
                --total	    显示所有文件系统的汇总
                -t <类型>	 只显示指定类型的文件系统
                -x <类型>	 排除指定类型的文件系统
            示例:
                df -h                   ==>         查看系统的空间
                df -h /home             ==>         查看 home 目录所在文件系统的空间
            输出字段解读:
                Filesystem	    文件系统的设备名或挂载点（分区名称）
                Size	        文件系统的总容量    
                Used	        已用空间
                Avail	        剩余可用空间
                Use%	        已用空间百分比
                Mounted on	    文件系统挂载点（挂载目录）
        top
            说明:
                实时显示系统运行状态
            选项:
                -i          只显示运行的进程, 不限时闲置或无用的进程
                -b	        批处理模式(非内部交互操作), 适合输出到文件或脚本使用
                -n <次数>	 指定刷新次数后退出（配合 -b 使用）
                -u <用户>	 仅显示指定用户的进程
                -c          显示产生进程的完整命令,补全COMMAND列.
                -p <PID>	仅显示指定 PID 的进程
                -d <秒>	    指定刷新间隔时间（秒）
                -H	        显示线程（Thread）
            内部操作:
                q	退出 top
                h	显示帮助信息
                1	显示每个 CPU 的使用率
                M	按内存使用排序
                P	按 CPU 使用排序
                T	按累计运行时间排序
                k	杀进程（输入 PID 后按提示操作）
                r	renice（修改进程优先级）
                u	输入用户名, 仅显示该用户的进程
                f	自定义显示字段
            示例:
                top	                                ==>         直接启动实时监控
                top -u root	                        ==>         仅显示 root 用户的进程
                top -p 1234	                        ==>         仅查看 PID 为 1234 的进程
                top -b -n 1 > top.txt	            ==>         批处理方式刷新一次, 并输出到文件
                top -b -d 5 -n 3	                ==>         每 5 秒刷新一次, 共刷新 3 次（适合写脚本分析）
                top -H	                            ==>         显示所有线程的资源使用情况
        su
            说明:
                切换账户
            选项:
                -l  使用目标用户的登录 shell 环境（等同完整登录）, 会加载 .bash_profile 等
            示例:
                su                                  ==>         切换到 root 用户（不加载 root 的环境）, 需输入 root 密码
                su -                                ==>         切换到 root 并加载完整登录环境（推荐）, 相当于完整登录 root
                su - anglee                         ==>         切换到 anglee 并加载完整登录环境
                su -l                               ==>         切换到 root 并加载完整登录环境（推荐）, 相当于完整登录 root
                su -c "ls /root"                    ==>         以 root 用户身份执行 "ls /root" 命令, 然后立即返回原用户
                exit                                ==>         退出 su 用户, 返回原来的普通用户
                ctrl+d                              ==>         退出 su 用户, 返回原来的普通用户
            注意:
                以下四种写法等价
                    su - 
                    su -l 
                    su - root 
                    su -l root
        sudo
            说明:
                授权普通用户,临时以root身份执行某命令
            注意:
                需为普通用户配置sudo认证,详见第二章节(用户和权限)
        systemctl
            说明:
                服务管理
            选项:
                start               启动服务
                stop                停止服务
                restart             重启服务
                reload              重新加载服务配置
                status              查看服务状态
                enable              开机自动启动服务
                disable             取消开机自动启动
                list-units          列出当前加载的服务单元
                is-active           判断服务是否运行
            示例:
                systemctl start nginx               ==>         启动 nginx 服务
                systemctl enable nginx              ==>         设置 nginx 服务开机自动启动
                systemctl restart nginx             ==>         重启 nginx 服务
                systemctl reload nginx              ==>         重新加载 nginx 配置（不停止服务）
                systemctl status nginx              ==>         查看 nginx 服务的当前状态, 包括是否运行、日志等
                systemctl is-active nginx	        ==>         检查 nginx 服务是否处于 "active (running)" 状态
        lsof
            说明:
                列出当前系统打开的文件信息, 包括打开的文件、网络连接、管道等.
            选项:
                -i                      显示网络相关的打开文件
                -p <PID>                显示指定进程打开的文件
                -u <user>               显示指定用户打开的文件
                +D <directory>          显示指定目录下所有打开的文件
                -n                      不转换网络地址为主机名, 提升速度
                -c <cmd>                显示指定命令打开的文件
                -t                      只输出进程ID, 方便脚本使用
            示例:
                lsof -i :80	                        ==>         显示所有占用 80 端口的打开文件（即占用80端口的进程）
                lsof -p 1234	                    ==>         查看进程号为 1234 的进程打开了哪些文件
                lsof -u root	                    ==>         列出 root 用户打开的所有文件
                lsof +D /var/log	                ==>         列出 /var/log 目录及子目录中被打开的所有文件
                lsof -n -i TCP	                    ==>         不解析主机名, 显示所有 TCP 网络连接
                lsof -t -i :22	                    ==>         只输出使用 22 端口的进程ID, 便于脚本杀进程
                lsof -i TCP:443	                    ==>         列出监听 HTTPS 端口的进程
                lsof -i @192.168.1.10	            ==>         列出与 IP 地址通信的所有连接
        ip
            说明:
                网络配置和查看的重要工具, 它是 ifconfig, route, netstat 等老旧命令的替代品, 由 iproute2 工具集提供. 
            示例:
                ip -brief addr                      ==>         IP地址简易信息输出
                ip addr                             ==>         IP地址信息输出
            注意:
                ip addr 替代过去的 ifconfig 命令
        kill
            说明:
                进程发送信号的命令
            选项/信号名:
                -1	SIGHUP	    终端断开, 常用于重启守护进程
                -2	SIGINT	    中断（Ctrl+C）
                -9	SIGKILL	    强制终止, 不能被捕获或阻止
                -15	SIGTERM	    请求终止（默认）, 可被捕获、忽略
                -l	            显示所有信号名
                -s  SIGNAL	    指定信号名发送, 如 -s SIGKILL
            示例:
                kill 1234	                        ==>         向进程 1234 发送 SIGTERM 请求进程优雅终止
                kill -9 1234	                    ==>         强制终止进程 1234	立即终止进程, 无法拦截
                kill -15 1234	                    ==>         等价于 kill 1234	默认信号是 15, 即 SIGTERM
                kill -l	                            ==>         显示所有支持的信号列表	用于参考信号名称与编号
        ping
            说明:
                测试网络连通性, 走的是系统的名字解析服务（nsswitch.conf 配置）, 所以根据默认配置, ping会优先读 /etc/hosts, 没有时才会读公共DNS的配置.
            选项:
                -c  发送次数
                -i  间隔秒数
                -W  超时时间
            示例:
                ping -c 4 -W 2 google.com           ==>         测试google网络是否联通
        host
            说明:
                查询 DNS（域名系统）记录的工具, 直接向 DNS 服务器请求查询, 不理会 /etc/hosts 本地静态映射文件中的配置.
            选项:
                -t TYPE	        查询指定类型的 DNS 记录, 如 A, MX, NS, TXT 等
                -a	            查询所有类型的记录（等同于 -t any）
                -v	            显示详细输出（verbose）
                -l	            列出域名的所有主机（zone transfer, 需要授权）
                -C	            检查 DNS 配置情况
                -W SECS	        等待响应时间, 默认 5 秒
            示例:
                host example.com            ==>         查询域名对应的 IP 地址（正向解析）
                host 8.8.8.8                ==>         查询 IP 地址对应的域名（反向解析）
                host example.com 8.8.8.8    ==>         查询域名对应的 IP 地址（使用指定的DNS服务器8.8.8.8查询）
        ss
            说明:
                网络连接统计工具(替代netstat的现代工具)
            选项:
                -t	显示 TCP 套接字	
                -u	显示 UDP 套接字	
                -l	仅显示监听状态的套接字	
                -n	不解析域名或服务名	
                -a	显示所有套接字（监听和非监听）	
                -p	显示使用套接字的进程	
                -s	显示套接字统计信息	
                -4	显示 IPv4 连接	
                -6	显示 IPv6 连接	
                -r	显示路由信息（不常用）	
                -o	显示计时器信息（如超时）	
            示例:
                ss -t	                            ==>         显示所有 TCP 连接
                ss -u	                            ==>         显示所有 UDP 套接字
                ss -tuln	                        ==>         显示所有监听状态的 TCP/UDP 套接字
                ss -tn	                            ==>         提高速度, 显示 IP 和端口号而非主机名和服务名
                ss -ta	                            ==>         显示所有 TCP 连接, 包括 ESTAB、LISTEN 等
                ss -tulpn	                        ==>         查看监听端口对应的进程 PID 和程序名
                ss -s	                            ==>         查看 TCP、UDP、RAW 等连接的汇总统计
                ss -tuln4	                        ==>         显示 IPv4 的监听 TCP/UDP 连接
                ss -tuln6	                        ==>         显示 IPv6 的监听 TCP/UDP 连接
                ss -r	                            ==>         查看路由表相关的 socket
                ss -o state established	            ==>         显示 TCP 已建立连接及其定时器
        curl
            说明:
                网络数据传输工具
            选项:
                -X	指定请求方法（如 GET, POST）
                -d	指定请求数据（POST/PUT 提交数据）
                -H	添加 HTTP 请求头
                -i	显示响应头和响应体
                -I	仅显示响应头（HEAD 请求）
                -o	保存输出到文件
                -O	以远程文件名保存文件
                -L	跟踪重定向
                -s	静默模式, 不显示进度
                -S	与 -s 配合, 显示错误
                -u	提供用户名密码（基本认证）
                --compressed	请求压缩内容
                -k	忽略 SSL 证书检查
                -v	显示详细请求过程（verbose）
                -x	设置代理服务器
            示例:
                curl -X POST https://api.example.com	            ==>         用 POST 方法访问接口
                curl -d "name=Tom" -X POST https://api.example.com	==>         提交表单数据
                curl -H "Content-Type: application/json"	        ==>         设置请求头为 JSON
                curl -i https://example.com	                        ==>         同时查看响应头和内容
                curl -I https://example.com	                        ==>         检查网页是否存在或跳转情况
                curl -o index.html https://example.com	            ==>         下载页面保存为 index.html
                curl -O https://example.com/file.zip	            ==>         保留远程文件名下载
                curl -L https://example.com	                        ==>         自动跳转最终地址
                curl -s https://example.com	                        ==>         静默请求, 不显示进度条
                curl -sS https://wrong.url	                        ==>         只在出错时显示信息
                curl -u user:pass https://example.com	            ==>         用 Basic Auth 认证
                curl --compressed https://example.com	            ==>         请求 gzip/deflate 内容
                curl -k https://selfsigned.example.com	            ==>         忽略无效 SSL 证书
                curl -v https://example.com	                        ==>         输出请求/响应详细信息
                curl -x http://127.0.0.1:8080 https://example.com	==>         通过代理请求
        wget
            说明:
                命令行下载工具
            选项:
                -O	指定输出文件名
                -P	指定保存目录
                -c	断点续传
                -b	后台下载
                -q	安静模式（不输出）
                --show-progress	显示进度条
                --limit-rate=	限速下载
                --wait=	每次下载等待秒数
                --no-check-certificate	忽略 SSL 证书错误
                --user / --password	指定用户名密码
                -r	递归下载（整站）
                --level=N	设置递归层级
                -np	不追溯父目录
                -nd	不创建目录结构
            示例:
                wget -O index.html https://example.com	                        ==>         将页面保存为 index.html
                wget -P ./downloads https://example.com/a.pdf	                ==>         下载文件保存到 ./downloads
                wget -c https://example.com/bigfile.zip	                        ==>         如果上次中断则继续下载
                wget -b https://example.com/file.zip	                        ==>         在后台下载文件（日志写入 wget-log）
                wget -q https://example.com	                                    ==>         静默下载, 无输出
                wget --show-progress https://example.com	                    ==>         下载时显示百分比进度
                wget --limit-rate=500k https://example.com	                    ==>         限制速度为每秒 500KB
                wget --wait=2 -r https://example.com	                        ==>         每个请求之间等待 2 秒
                wget --no-check-certificate https://selfsigned.example.com	    ==>         忽略不安全证书
                wget --user=admin --password=1234 https://example.com	        ==>         认证方式访问资源
                wget -r https://example.com	                                    ==>         下载整个网站结构
                wget -r --level=2 https://example.com	                        ==>         最多递归 2 层子目录
                wget -r -np https://example.com/docs/	                        ==>         只下载该路径及以下
                wget -nd -r https://example.com/files/	                        ==>         所有文件下载到当前目录
                wget https://example.com/file.txt                               ==>         下载单个文件
        echo
            说明:
                输出命令到终端
            选项:
                -n	不自动换行输出
                -e	启用转义字符（如 \n, \t, \\, 等）
                -E	默认值, 禁用转义（大多数系统默认启用）
            示例:
                echo Hello World	                                            ==>         Hello World	输出一行文本
                echo "User is $USER"                                            ==>         输出变量内容
                echo "Next line" > file.txt                                     ==>         输出内容覆盖写入到file.txt文本中
                echo "Next line" >> file.txt                                    ==>         输出内容追加写入到file.txt文本中
                echo -e "Line1\nLine2"		                                    ==>         输出两行内容, \n 表示换行
        grep
            说明:
                文本搜索
            选项:
                -i  忽略大小写
                -v  反选匹配
                -r  递归目录
                -E  扩展正则
                -n  显示行号
                -l  匹配的文件名
                -C  显示上下文行数
                -c  统计行数
                -w  匹配完整单词
                --color         高亮匹配的结果
                --exclude-dir   忽略目录
            示例:
                grep "error" logfile.txt                            ==>         在文件 logfile.txt 中搜索包含字符串 "error" 的所有行
                grep -i "warning" system.log                        ==>         忽略大小写字符匹配 "warning"、"Warning"、"WARNING" 等字符
                grep -r "main()" /home/user/project/                ==>         递归搜索 /home/user/project/ 目录及其子目录中所有文件, 查找 "main()"
                grep -n "TODO" source_code.py                       ==>         显示匹配行在文件中的行号（如 42:TODO: fix this）
                grep -v "success" results.csv                       ==>         输出不包含 "success" 的所有行(用于排除结果)
                grep -c "404" access.log                            ==>         统计包含 "404" 的行数(输出数字, 而非具体行)
                grep -l "deprecated" *.js                           ==>         输出包含匹配项的文件名
                grep -E "[0-9]{3}-[0-9]{4}" contacts.txt            ==>         启用扩展正则表达式, 在 contacts.txt 中搜索如 123-4567 的电话号码格式。
                grep -w "port" config.cfg                           ==>         确保只匹配完整单词（如 port 不会匹配 export）
                grep -e "error" -e "fatal" app.log                  ==>         使用多个 -e 选项搜索包含 "error" 或 "fatal" 的行
                grep -r --exclude-dir="node_modules" "function" .   ==>         递归搜索时忽略 node_modules 目录, .表示当前目录
        wc
            说明:
                字符统计
            选项:
                -l	仅统计行数（lines）
                -w	仅统计单词数（words）
                -c	仅统计字节数（bytes）
                -m	仅统计字符数（chars, 支持多字节字符）
                -L	输出最长行的长度（字符数）
            示例/输出/说明:
                wc helloworld.txt       ==>     1  2 12 helloworld.txt      ==>         1行,2单词,28字节(包含转义字符)
        sort
            说明:
                排序文件命令
            选项:
                -n	按数字大小排序（默认是字典序）
                -r	反向排序（降序）
                -k	指定以第几列作为排序关键字（字段以空格或制表符分隔）
                -t	设置字段分隔符
                -u	去重（前提是排序后的重复行）
                -o  文件名	指定输出文件, 而不是默认输出到屏幕
                -M	按月份名称排序（如 Jan, Feb）
                -b	忽略每行前导空格进行比较
                --help	查看帮助文档
            示例:
                sort file.txt                   ==>         基本排序
                sort -n scores.txt              ==>         按数字大小排序
                sort -r names.txt               ==>         将文本内容按降序排列
                sort -k 3 data.txt              ==>         按每行的第 3 列排序
                sort -u names.txt               ==>         排序并去重
                sort bigfile.txt -o sorted.txt  ==>         排序 bigfile.txt 并将结果输出到 sorted.txt 文件中, 覆盖 sorted.txt, 不会提示, sorted.txt 文本不需要提前创建好, sort会自动创建
                sort bigfile.txt >> sorted.txt  ==>         排序 bigfile.txt 并将结果输出到 sorted.txt 文件中, 追加 sorted.txt.
        uniq
            说明:
                检测和过滤相邻重复行, 一般与 sort 搭配使用
            选项:
                -c	统计每行出现的次数
                -d	只显示重复的行
                -u	只显示不重复的行
                -i	忽略大小写比较
                -f N	忽略每行前 N 个字段比较
                -s N	忽略每行前 N 个字符比较
            示例:
                sort names.txt | uniq           ==>         基本排序
                sort names.txt | uniq -c        ==>         统计出现次数
                sort names.txt | uniq -d        ==>         只保留重复行
        diff
            说明:
                比较两个文件的差异, 常用于配置 或 代码变更比对. 
            选项:
                -y	并排显示文件差异（side-by-side）
                -c	上下文格式（context diff, 显示改动前后几行）
                -u	联合格式（unified diff, 常用于补丁/版本控制）
                --color=auto	彩色输出差异
                -q	只报告是否不同, 不输出具体差异
            示例:
                diff old.txt new.txt                                    ==>         比较两个文件的内容
                diff -y old.txt new.txt                                 ==>         以并排方式展示差异
                diff -y --color=auto old.txt new.txt                    ==>         以并排方式展示差异并且高亮差异
                diff -u config_v1.conf config_v2.conf > config.patch    ==>         输出适合 patch 命令使用的差异格式
                diff -q a.txt b.txt && echo "Same" || echo "Diff"       ==>         只判断是否不同
        bc
            说明:
                (Basic Calculator)Linux下的高精度计算工具, 支持整数, 小数和表达式
            选项:
                -l	启用标准数学库（支持小数、三角函数等）
                -q	静默模式, 不显示欢迎信息
            示例:
                echo "3+5" | bc                             ==>         计算 3+5
                echo "scale=3; 10/3" | bc                   ==>         scale 用于设置小数精度, 结果为 3.333
                bc                                          ==>         进入交互式 bc 模式, 可连续输入表达式
        watch
            说明:
                周期性执行某个命令
            选项:
                -n 秒数	 指定间隔时间（默认 2 秒）
                -d	    高亮显示发生变化的部分
                -t	    不显示顶部标题和时间戳
                -g	    只在输出变化时才更新
            示例:
                watch -n 1 date                             ==>         每秒更新一次当前时间
                watch -d df -h                              ==>         实时查看磁盘使用变化, 并高亮有变化的部分
                watch -n 5 "ps aux | grep nginx"            ==>         每 5 秒刷新一次 nginx 相关进程
                watch -t uptime                             ==>         去掉时间戳, 只显示 uptime 信息
        ssh
            说明:
                远程登录工具
            选项:
                -p	指定远程主机 SSH 端口, 默认是 22
                -i	指定私钥文件, 用于密钥认证
                -v	显示详细调试信息
                -C	启用压缩, 提高慢速连接性能
                -X	启用 X11 转发, 用于图形界面应用远程显示
                -o	传递额外配置选项, 如禁用主机密钥检查
                -L	本地端口转发（隧道）
            示例:
                ssh user@192.168.1.10                       ==>         用用户名 user 登录 IP 地址为 192.168.1.10 的服务器
                ssh -p 2222 user@host                       ==>         远程连接服务器 SSH 服务监听在 2222 端口
                ssh -i ~/.ssh/id_rsa user@host              ==>         使用指定私钥文件登录
                ssh -v user@host                            ==>         显示连接过程的详细调试信息.
                ssh -C user@host                            ==>         对数据进行压缩, 适合带宽较低的连接
                ssh -X user@host                            ==>         远程运行图形界面程序, 本地显示窗口
                ssh -o StrictHostKeyChecking=no user@host   ==>         连接时不检查主机密钥, 避免首次连接提示
                ssh -L 8080:localhost:80 user@host          ==>         把本地 8080 端口映射到远程服务器的 80 端口
                scp file.txt user@host.com:/home/user/      ==>         SSH 命令执行远程传输, 将 file.txt 传输到 user@host.com:/home/user/ 目录下
            提示:
                可以在 ~/.ssh/config 里配置别名, 简化命令: 
                    Host myserver
                    HostName 192.168.1.10
                    User user
                    Port 2222
                    IdentityFile ~/.ssh/my_key.pem
                配置后, 可以直接ssh链接 Host 名称即可登陆:
                    ssh myserver
        chmod
            说明:
                修改文件访问权限
            选项:
                -R  递归修改目录及其下所有文件和子目录的权限。
                -v  显示修改过程的详细信息。
                -c  仅在权限发生变化时显示信息。
            权限模式:
                符号模式:
                    符号格式:
                        [ugoa][+-=][rwx]
                    格式解释:
                        r(4), w(2), x(1)
                        u(user, 所有者/用户) / g(group, 组) / o(others, 其他用户) / a(all, 所有)
                        +(添加权限) / -(移除权限) / =(设置权限)
                    示例:
                        chmod u+rwx file.txt                ==>         给文件所有者添加读写执行权限
                        chmod go-rwx file.txt               ==>         给组和其他用户移除读写执行权限
                        chmod a=r file.txt                  ==>         所有用户设为只读
                        chmod -R u=rwx,g=w,o=4 ~/LearnDir/  ==>         为~/LearnDir/目录设置权限为 所有者读写执行,组用户写,其他用户读权限.
                数字模式:
                    数字格式:
                        三位八进制数(如 755,644)
                    常用数字组合:
                        组合	符号表示	        含义	                                        典型使用场景
                        644	    rw-r--r--	    所有者可读写, 组和其他用户只读	                     普通文件 (如文本文件、配置文件), 允许所有人查看, 但只有所有者可修改
                        755	    rwxr-xr-x	    所有者可读写执行, 组和其他用户可读执行	              可执行文件 (如脚本、程序)或目录, 允许所有人运行或进入, 但只有所有者可修改
                        600	    rw-------	    所有者可读写, 组和其他用户无权限	                 私有文件 (如敏感配置文件), 只有所有者可访问
                        700	    rwx------	    所有者可读写执行, 组和其他用户无权限	              私有可执行文件或目录, 只有所有者可访问和运行
                        664	    rw-rw-r--	    所有者和组可读写, 其他用户只读	                     组共享文件, 允许组内用户编辑, 外部用户只读
                        775	    rwxrwxr-x	    所有者和组可读写执行, 其他用户可读执行	               组共享目录或程序, 组内用户可完全操作, 外部用户可访问
                        777	    rwxrwxrwx	    所有人可读写执行	                               完全开放 (不推荐, 安全性低), 如临时共享目录
                        400	    r--------	    所有者只读, 组和其他用户无权限	                     敏感只读文件 (如证书文件), 仅所有者可查看
                    数字单独权限及含义:
                        0   ==> 无权限        ==>         ---        ==>         无读, 无写, 无执行权限
                        1   ==> 执行         ==>         --x        ==>         只有执行权限 (对文件表示可运行, 对目录表示可进入)
                        2   ==> 写           ==>         -w-        ==>         只有写权限 (可修改文件或目录内容)
                        3   ==> 写+执行       ==>         -wx        ==>        有写和执行权限 (可修改并运行/进入)
                        4   ==> 读           ==>         r--        ==>         只有读权限 (可查看文件内容或列出目录)
                        5   ==> 读+执行       ==>         r-x        ==>        有读和执行权限 (可查看并运行/进入)
                        6   ==> 读+写        ==>         rw-        ==>         有读和写权限 (可查看和修改)
                        7   ==> 读+写+执行    ==>         rwx        ==>         拥有全部权限 (可查看、修改、运行/进入)
                    解释:
                        数字表示: 用八进制数表示权限, 例如 755 表示:
                            所有者: 7 (rwx = 4+2+1)
                            所属组: 5 (r-x = 4+0+1)
                            其他用户: 5 (r-x = 4+0+1)
                    示例:
                        chmod 644 file.txt                  ==>         所有者读写（6=4+2）, 组和其他用户只读（4）
                        chmod 755 script.sh                 ==>         所有者读写执行（7=4+2+1）, 组和其他用户读执行（5=4+1）
        chown
            说明:
                修改文件所有者
            选项:
                -R  递归更改目录及其下所有文件和子目录的所有者/组。
                -v  显示更改过程的详细信息。
                -c  仅在所有者/组发生变化时显示信息。
            示例:
                chown anglee ~/file.txt                     ==>         将文件所有者设为anglee
                chown user1:group1 file.txt                 ==>         更改文件的所有者和所属组为 user1:group1
                chown :group1 file.txt                      ==>         只更改文件的所属组为 group1
                chown -R anglee mydir/                      ==>         递归更改目录及其内容的拥有者为 anglee
        realpath
            说明:
                输出文件绝对路径
            示例:
                realpath vim.txt                            ==>         输出vim.txt的绝对路径
        hostnamectl
            说明:
                查看当前系统的详细信息,如:查看当前发行版的版本等等..
            示例:
                hostnamectl                                 ==>            查看当前系统的详细信息
                hostnamectl set-hostname centos             ==>            设置主机名


    Linux命令符号:
        |
            说明:
                管道符, 把前一个命令的输出, 作为后一个命令的输入
            示例:
                ps -ef | grep nginx                         ==>         查找 cmd 列名包含 nginx 的进程
                ll -R | grep test01                         ==>         递归输出当前目录并查找test01的文件和目录
        >
            说明:
                把命令输出写入到文件, 覆盖文件原内容
            示例:
                echo "hello" > file.txt	                    ==>         将 "hello" 写入 file.txt, 覆盖原内容
        >>
            说明:
                把命令输出追加到文件末尾	
            示例:
                echo "world" >> file.txt	                ==>         将 "world" 追加写入 file.txt, 不覆盖
        <
            说明:
                从文件中读取内容作为命令输入
            示例:
                sort < names.txt                            ==>         将 names.txt 内容作为输入, 排序后输出, 会输出排序后的名字, 假设names.txt是记录名字的文本.
        &&
            说明:
                只有前一个命令成功, 才执行后一个命令
            示例:
                mkdir test && cd test                       ==>         创建目录成功后, 才进入该目录
        ||
            说明:
                只有前一个命令失败, 才执行后一个命令
            示例:
                cd not_exist_dir || echo "目录不存在"           ==>         如果 cd 失败(因为目录不存在), 就输出"目录不存在". 
        ;	
            说明:
                顺序执行多个命令, 无论前一个是否成功
            示例:
                cd /tmp; ls; pwd                            ==>         依次执行: 进入 /tmp, 列出文件, 显示当前路径
        ~
            说明:
                HOME目录快捷符
            示例:
                cd ~	                                    ==>         进入当前用户HOME目录, 比如 /home/username
        .
            说明:
                当前目录	
            示例:
                ls .	                                    ==>         列出当前目录内容
        ..	
            说明:
                上一级目录	
            示例:
                cd ..	                                    ==>         进入当前目录的上一级目录
        *	
            说明:
                通配符, 匹配任意数量字符
            示例:
                ls *.txt                                    ==>         列出所有以 .txt 结尾的文件
                ls *test*                                   ==>         列出所有包含 test 的文件或目录
                ls *test                                    ==>         列出所有以 test 结尾的文件或目录
                ls test*                                    ==>         列出所有以 test 开头的文件或目录
        ?	
            说明:
                通配符, 匹配任意一个字符
            示例:
                ls file?.txt	                            ==>         匹配 file1.txt、fileA.txt 等单字符变体
        $()
            说明:
                命令替换, 将命令输出替换到当前位置
            示例:
                echo "Today is $(date)"                     ==>         输出: Today is 2025-06-10 ...
        `` 
            说明:
                旧式命令替换, 功能同 $()
            示例:
                echo `whoami`	                            ==>         输出当前用户名
                echo `pwd`	                                ==>         输出当前工作目录


    Vim/Vi
        vim编辑器的三种工作模式
            命令模式(command mode 或 normal mode):
                默认vi编辑器都会进入命令模式,通过命令模式选择进入 编辑模式 或 底线命令模式
                常用操作:
                    i                   ==>         进入编辑模式(输入模式)
                    a                   ==>         在当前光标位置之后进入编辑模式(输入模式)
                    I                   ==>         在当前行的开头进入编辑模式(输入模式)
                    A                   ==>         在当前行的结尾进入编辑模式(输入模式)
                    o                   ==>         在当前光标下一行进入编辑模式(输入模式)
                    O                   ==>         在当前光标上一行进入编辑模式(输入模式)
                    esc                 ==>         返回命令模式
                    h                   ==>         光标左移
                    l                   ==>         光标右移
                    j                   ==>         光标下移
                    k                   ==>         光标上移
                    $                   ==>         移动到行尾
                    0                   ==>         移动到行首
                    ^                   ==>         移动到行首的第一个非空字符
                    gg                  ==>         移动到文件开头
                    G                   ==>         移动到文件末尾
                    nG                  ==>         移动到第 n 行
                    w                   ==>         跳到下一个词首
                    b                   ==>         跳到上一个词首
                    e                   ==>         跳到词尾
                    Ctrl + f            ==>         向下翻页
                    Ctrl + b            ==>         向上翻页
                    Ctrl + d            ==>         向下半页
                    Ctrl + u            ==>         向上半页
                    /                   ==>         搜索模式
                        n                   ==>         向下继续搜索
                        N                   ==>         向上继续搜索
                    dd                  ==>         删除光标所在行
                    ndd                 ==>         删除光标所在行之后的n行(3dd 就是删除包含当前行之后的三行)
                    yy                  ==>         复制当前行
                    nyy                 ==>         复制光标所在行之后的n行(3yy 就是复制包含当前行之后的三行)
                    p                   ==>         粘贴
                    u                   ==>         撤销修改
                    ctrl+r              ==>         反向撤销修改
                    dG                  ==>         从当前行开始向下全部删除
                    dgg                 ==>         从当前行开始向上全部删除
                    d$                  ==>         从当前光标开始,删除至本行结尾
                    d^                  ==>         从当前光标开始,删除至本行开头
                    d0                  ==>         从当前光标开始,删除至本行开头
            输入模式(insert mode):
                即所谓的编辑模式,插入模式.
            底线命令模式(last line mode):
                通常用于文件的保存,退出等查操作.
                常用操作
                    :w                  ==>         保存文件
                    :wq or :x           ==>         保存并退出
                    :q!                 ==>         强制退出不保存
                    :set nu             ==>         显示行号
                    :set paste          ==>         设置粘贴模式,设为粘贴模式后会使在输入模式时 外部粘贴进来的内容格式不错乱
                    :e filename         ==>         打开新文件(filename是要打开的文件名)
                    :saveas newfile     ==>         另存为(newfile是要另存的文件名)














贰.用户和权限(002UsersAndPermissions)

    初识root用户
        无论是windows,macOS,Linux均采用多用户的管理模式进行权限管理.
        在Liunx中拥有最大权限的用户是 :root 用户(超级管理员)
        普通用户在很多地方的权限是受限制的
            比如普通用户在根目录下无法创建任何文件或目录(Permission denied)
        普通用户一般在HOME(~)目录内的权限是不受限的
        在HOME目录外,大多数地方,普通用户只有只读和执行权限, 无修改权限.
        
        为普通用户配置sudo认证
            切换到root用户,执行 visudo 命令, 或者 vi /etc/sudoers, 会通过vi编辑器打开:/etc/sudoers
            在文件最后追加:
                anglee ALL=(ALL)        NOPASSWD: ALL
            最后通过:wq保存

    用户和用户组管理
        Linux系统中可以:
            配置多个用户
            配置多个用户组
            用户可以加入多个用户组中
        Linux关于权限的管控有两个级别:
            针对用户的权限控制
            针对用户组的权限控制
            比如: 一个文件, 可以允许某个用户组的用户都可以访问,也可以指定某一个用户可访问.
        用户组管理(需要用root用户执行,因为用户和用户组权限管理需要顶级权限):
            创建用户组:
                groupadd 用户组名
            删除用户组:
                groupdel 用户组名
        用户管理(同样需要root用户执行)
            创建用户
                useradd [-g -d] 用户名
                    -g 指定用户的组,不指定-g, 会自动创建同名组并自动加入, 指定-g需要组已存在.
                    -d 指定用户的HOME路径, 如果不指定, home目录默认在: /home/用户名
            删除用户
                userdel [-r] 用户名
                    -r 删除用户的home目录, 不使用-r时删除用户时, home目录将被保留
            查看用户所属组
                id
                或
                id 用户名
                输出解释:
                    uid=0(root) gid=0(root) groups=0(root) context=unconfined_u:unconfined_r:unconfined_t:s0-s0:c0.c1023
                        uid表示用户id为0(即root)
                        gid表示组id为0(即root)
                        groups表示所属组为0(即root组)
                    uid=1001(anglee) gid=1001(anglee) groups=1001(anglee),27(sudo)
                        当前用户是 anglee（UID 1001）
                        主组也是 anglee（GID 1001）
                        该用户还属于 sudo 组（GID 27）, 意味着他可以使用 sudo 提权
                    uid=1001(test) gid=1001(itcast) groups=1001(itcast)
                        当前用户是 test 1001）
                        主组是 itcast（GID 1001）
            修改用户所属组:
                usermod -aG 用户组 用户名,将指定用户加入指定用户组
                示例:
                    usermod -aG itcast anglee
                    将 anglee 用户添加到 itcast 用户组中
            查看所有用户	
                cat /etc/passwd
                getent passwd
            查看所有组	
                cat /etc/group
                getent group
        初识权限控制
            drwxr-xr-x.  20 root root 3440 Jun  6 13:12 dev
            根据顺序解读
            | 字段                  | 示例            | 含义                                  |
            | -------------        | -------------   | --------------------------           |
            | **1. 权限位**         | `drwxr-xr-x.`   | 文件类型 + 权限位 + SELinux 标志        |
            | **2. 硬链接数**        | `20`           | 指向该目录的“引用数”（通常是目录项数量）    |
            | **3. 所有者**         | `root`          | 拥有这个文件/目录的用户名                |
            | **4. 所属组**         | `root`          | 拥有这个文件/目录的用户组名              |
            | **5. 文件大小**       | `3440`          | 文件大小（字节）；目录时是占用的字节数      |
            | **6. 最后修改时间**    | `Jun 6 13:12`   | 最后一次修改的时间                      |
            | **7. 文件名**         | `dev`           | 目录名（或文件名）                      |

            文件类型:
                -	普通文件（regular file）	文本、二进制、可执行等
                d	目录（directory）	文件夹
                l	软链接/符号链接（symbolic link）	类似 Windows 的快捷方式
                b	块设备文件（block device）	硬盘、U 盘、光驱等设备
                c	字符设备文件（character device）	键盘、串口等字符方式通信设备
                p	管道（pipe / FIFO）	进程间通信的一种方式
                s	套接字（socket）	进程间通信（网络/本地）
                D	门（door, 仅 Solaris 使用）	现代 Linux 很少见
                n	网络设备（rare）	罕见, 部分嵌入式系统或特定 FS 中可能出现
            
            这段输出解读:
                rwx权限是对于root用户名的
                r-x权限是对于root用户组的
                r-x权限是对于除root用户组和用户名以外的其他用户的
            所以当我们看到ll的结果时,就能看到该目录或文件在当前用户是否有权限操作了.
        修改权限控制
            | 命令      | 全称               | 含义                                               | 用途         |
            | ------- | ---------------- | ------------------------------------                 | ---------- |
            | `chown` | **change owner** | 改变文件或目录的**所有者**（user）和**用户组**（group）     | 修改文件的用户和用户组     |
            | `chmod` | **change mode**  | 改变文件或目录的**权限模式（mode）**                      | 修改读/写/执行权限 |
            符号模式:
                符号格式:
                    [ugoa][+-=][rwx]
                格式解释:
                    r(4), w(2), x(1)
                    u(user, 所有者/用户) / g(group, 组) / o(others, 其他用户) / a(all, 所有)
                    +(添加权限) / -(移除权限) / =(设置权限)
            数字模式:
                0   ==> 无权限        ==>         ---        ==>         无读, 无写, 无执行权限
                1   ==> 执行         ==>         --x        ==>         只有执行权限 (对文件表示可运行, 对目录表示可进入)
                2   ==> 写           ==>         -w-        ==>         只有写权限 (可修改文件或目录内容)
                3   ==> 写+执行       ==>         -wx        ==>        有写和执行权限 (可修改并运行/进入)
                4   ==> 读           ==>         r--        ==>         只有读权限 (可查看文件内容或列出目录)
                5   ==> 读+执行       ==>         r-x        ==>        有读和执行权限 (可查看并运行/进入)
                6   ==> 读+写        ==>         rw-        ==>         有读和写权限 (可查看和修改)
                7   ==> 读+写+执行    ==>         rwx        ==>         拥有全部权限 (可查看、修改、运行/进入)














叁.Liunx实用操作(003UsingLinuxEffectively)

    实用技巧
        ctrl+c                  退出常见的程序,如 tail -f
        ctrl+d                  退出常见的程序,如linux自带的python环境 和 root 用户登出(exit)等操作
        ctrl+r                  历史命令搜索
        ctrl+a                  跳到命令开头
        ctrl+e                  跳到命令结尾
        opt+left arrow          向左跳一个单词
        opt+right arrow         向右跳一个单词
        ctrl+l                  清空屏幕命令(同clear)


    软件安装
        | 命令                         | 作用            | 示例                                          |
        | -------------------------- | ------------- | ------------------------------------------- |
        | `dnf install <pkg>`        | 安装软件包         | `sudo dnf install vim`                      |
        | `dnf remove <pkg>`         | 卸载软件包         | `sudo dnf remove nano`                      |
        | `dnf update`               | 更新所有可更新的软件包   | `sudo dnf update`                           |
        | `dnf upgrade`              | 更新（等同 update） | `sudo dnf upgrade`                          |
        | `dnf search <pkg>`         | 搜索软件包         | `dnf search python`                         |
        | `dnf info <pkg>`           | 显示软件包详细信息     | `dnf info httpd`                            |
        | `dnf list installed`       | 列出所有已安装的软件包   | `dnf list installed`                        |
        | `dnf clean all`            | 清理缓存          | `sudo dnf clean all`                        |
        | `dnf groupinstall <group>` | 安装软件包组（环境）    | `sudo dnf groupinstall "Development Tools"` |


    控制软件启动关闭
        命令:
            systemctl
        选项:
            start               启动服务
            stop                停止服务
            restart             重启服务
            reload              重新加载服务配置
            status              查看服务状态
            enable              开机自动启动服务
            disable             取消开机自动启动
            list-units          列出当前加载的服务单元
            is-active           判断服务是否运行
        示例:
            systemctl start nginx               ==>         启动 nginx 服务
            systemctl enable nginx              ==>         设置 nginx 服务开机自动启动
            systemctl restart nginx             ==>         重启 nginx 服务
            systemctl reload nginx              ==>         重新加载 nginx 配置（不停止服务）
            systemctl status nginx              ==>         查看 nginx 服务的当前状态, 包括是否运行、日志等
            systemctl is-active nginx	        ==>         检查 nginx 服务是否处于 "active (running)" 状态
        内置服务:
            NetworkManager          主网络服务
            network                 副网络服务
            firewalld               防火墙服务
            sshd/ssh                远程安全登录和命令执行服务
        第三方服务:
            ntp(ntpd)               自动同步系统时间服务
            httpd                   Web 网站的访问功能服务(网页服务器)
        注意:
            有些第三方服务安装后可以通过 systemctl 控制是因为服务本身会自动集成到systemctl中.
            但是有些软件安装后没有自动集成到systemctl中, 也可以手动添加.


    软链接
        在系统中创建软链接,可以将文件,文件夹链接到其他位置, 类似于windows系统中的快捷方式
        命令:
            ln
        选项:
            -s	创建符号（软）链接
            -f	强制覆盖目标文件
            -v	显示创建过程（verbose）
            -n	处理软链接时, 不跟随它指向的文件
            -T	把目标强制当成普通文件（防止目标是目录）
        示例:
            ln -s /etc/nginx/nginx.conf ~/nginx.conf            ==>         创建软链接, 原文件是 /etc/nginx/nginx.conf, 软链接是 ~/nginx.conf.

    
    日期和时区
        命令:
            date [选项] [+格式]
        选项:
            -d STRING	            使用指定的日期时间字符串（不改变系统时间）
                STRING可以为绝对时间:
                    date -d "2025-06-20 14:30:00"
                STRING可以为相对时间表达式:
                    | 关键字             | 示例              | 含义说明         |
                    | --------------- | --------------- | ------------ |
                    | `yesterday`     | `"yesterday"`   | 昨天           |
                    | `tomorrow`      | `"tomorrow"`    | 明天           |
                    | `now`           | `"now"`         | 当前时间         |
                    | `ago`           | `"3 days ago"`  | 几天前          |
                    | `next` / `last` | `"next Friday"` | 下/上 星期几、月、年等 |
                    | `+N unit`       | `"+3 days"`     | 未来 N 单位时间    |
                    | `-N unit`       | `"-2 hours"`    | 过去 N 单位时间    |
                    支持的时间单位:
                        seconds, minutes, hours
                        days, weeks, months, years
                        Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
                    比如:
                        date -d "yesterday"
                        date -d "2 days ago"
                        date -d "next Friday"
                        date -d "last month"
                        date -d "3 hours ago"
                        date -d "+2 weeks"
                STRING可以为时间戳:
                    date -d @1700000000
            -s STRING	            设置系统时间（需要 root 权限）
                STRING的场景和-d相同, 除了时间戳外, 即-s的STRING不可以为时间戳,其余和-d的STRING一样.
            -u	                    以 UTC（协调世界时）显示时间
            -R	                    输出符合 RFC 5322 格式的日期（用于邮件头）
            --rfc-3339=TYPE	        输出符合 RFC 3339 标准的时间格式（常用于日志）
            --date=STRING	        与 -d 相同, 用于指定解析时间字符串
            --set=STRING	        与 -s 相同, 用于设置系统时间
            --utc 或 --universal	与 -u 相同, 显示 UTC 时间
            -I	                    使用 ISO 8601 标准输出时间, 如 2025-06-20（默认只输出日期）
            -I[=type]	            精确控制输出格式: date, hours, minutes, seconds, ns 等
            --help	                显示帮助信息
            --version	            显示版本信息
        自定义格式控制符:
            | 控制符  | 含义               | 示例值        |
            | ---- | ---------------- | ---------- |
            | `%Y` | 年（4位）            | 2025       |
            | `%y` | 年（后两位）           | 25         |
            | `%m` | 月（01-12）         | 06         |
            | `%d` | 日（01-31）         | 20         |
            | `%H` | 时（00-23）         | 14         |
            | `%M` | 分（00-59）         | 30         |
            | `%S` | 秒（00-59）         | 45         |
            | `%a` | 星期（缩写）           | Thu        |
            | `%A` | 星期（全称）           | Thursday   |
            | `%u` | 一周中的第几天（1-7）     | 4          |
            | `%j` | 一年中的第几天（001-366） | 171        |
            | `%Z` | 时区               | CST        |
            | `%s` | 自 Unix 纪元起(1970-01-01 00:00:00)的秒数    | 1750000000 |
        示例:
            date                                ==>         查看当前日期
            date "+%Y-%m-%d %H:%M:%S"           ==>         获取指定格式的时间
            date -d "yesterday" "+%Y-%m-%d"     ==>         获取指定日期的时间
            date +%s                            ==>         获取当前时间戳
            date -d @1750000000                 ==>         转换时间戳为可读的时间
        修改系统时区:
            通过符号链接修改 /etc/localtime:
                rm -f /etc/localtime
                sudo ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
            通过命令修改
                命令格式:
                    timedatectl [子命令] [选项]
                常用功能:
                    | 功能                    | 命令                                            | 说明                   |
                    | --------------------- | --------------------------------------------- | -------------------- |
                    | 查看当前时间和状态             | `timedatectl`                                 | 显示本地时间、UTC、时区、NTP状态等 |
                    | 设置系统时区                | `sudo timedatectl set-timezone Asia/Shanghai` | 设置为北京时间（东八区）         |
                    | 列出所有支持的时区             | `timedatectl list-timezones`                  | 显示可选的时区列表            |
                    | 启用 NTP 同步             | `sudo timedatectl set-ntp true`               | 启用自动时间同步             |
                    | 禁用 NTP 同步             | `sudo timedatectl set-ntp false`              | 关闭自动时间同步             |
                    | 设置本地时间（需配合 `date -s`） | `sudo date -s "2025-06-21 15:00:00"`          | 手动设定系统时间             |
        使用ntp/ntpd/chrony/chronyc同步系统时间:
            注意:
                ntpd 是老旧的守护进程, 现在在新版 RHEL/CentOS 中不再维护。
                chronyd 是更快、更适合虚拟机和不连续联网系统的 NTP 客户端, 推荐使用。
            安装chrony
                sudo dnf install -y chrony
            启动 chrony 服务并设置开机启动
                sudo systemctl enable --now chronyd
            查看同步状态
                chronyc tracking
                    输出中的 Leap status, Stratum, Last offset 等字段表示是否同步成功。
            检查当前同步的时间服务器
                chronyc sources


    IP地址和主机名
        每一台电脑都会有一个IP地址, 用于和其他计算机进行通讯.
        IP地址分为两个版本分别是IPv4,IPv6, 一般索说的IP都指的是IPv4.
        IPv4地址的格式为: a.b.c.d, 其中abcd都表示0~255的数字.
        可以通过ifconfig查看本机IP地址, 使用ifconfig首先需安装net-tools工具.
            ifconfig输出字段解读:
                lo	        回环接口	loopback, 本地回环设备, IP 一般是 127.0.0.1, 用于本机通信（系统内部）
                ensX	    有线网卡	“Ethernet Naming Standard”, 新版 Linux 的命名规范, 例如 ens33 表示网口
                ethX	    旧式有线网卡	旧版 Linux 中常见, 如 eth0, 新版已逐步改用 ensX 命名
                wlanX	    无线网卡	无线网络设备, 如 wlan0（Wi-Fi 接口）
                enpXsY	    PCI路径网卡	更详细的 predictable 命名方式, 如 enp0s3, 表示 PCI 总线位置的接口
                virbrX	    虚拟桥接设备	一般由 libvirt 或虚拟机（如 KVM/QEMU）创建的虚拟网络桥接
                brX	        网络桥设备	桥接网络接口, 如 Docker 或虚拟机使用桥接模式会创建
                vnetX	    虚拟网卡设备	虚拟机使用的虚拟网络接口（QEMU/KVM 下常见）
                dockerX	    Docker 虚拟接口	Docker 创建的容器网络虚拟网桥接口, 如 docker0
                tunX	    TUN 设备	VPN 使用的虚拟点对点接口, 例如 OpenVPN、WireGuard
                tapX	    TAP 设备	虚拟网桥使用的 TAP 接口
                bondX	    聚合网卡	多个物理网卡聚合为一, 如服务器双网卡聚合成 bond0
                teamX	    类似 bond	用于网卡聚合的另一种机制, 常用于冗余或负载均衡
        特殊IP地址:
            127.0.0.1           表示本机地址
            0.0.0.0             1.指代本机, 2.在端口绑定中用来确定绑定关系, 3.在一些IP地址限制中用来表示好所有IP,相当于*通配符.
        域名解析:
            域名解析流程如下:
                访问www.baidu.com, linux检查 /etc/hosts 本地静态映射文件 是否有 baidu.com 的ip地址匹配记录
                如果有, 这直接打开记录对应的IP地址.
                如果没有就会联网访问公开的DNS服务器中是否有记录, 市面上有很多免费公开使用的DNS服务器,比如说 114.114.114.114 或 8.8.8.8 等...
                这些DNS服务器所提供的服务就是: 把域名给到DNS服务器, DNS会返回域名对应IP供访问.
            可玩性:
                既然域名解析的第一步是要访问本地静态映射文件. 那么就可以在linux中的 /etc/hosts 配置ipv4为自定义名(主机名),
                然后通过 [用户名@主机名] 代替 [用户名@ipv4地址] 进行电脑的远程连接和访问通讯了.
        配置Linux的固定IP地址
            CentOS7
                编辑网卡配置文件
                    sudo vim /etc/sysconfig/network-scripts/ifcfg-ens33
                内容示例即解释
                    TYPE=Ethernet
                    BOOTPROTO=dhcp                  改为 BOOTPROTO=static
                    NAME=ens33
                    DEVICE=ens33
                    ONBOOT=yes
                    IPADDR=192.168.1.100            IP地址
                    NETMASK=255.255.255.0           子网掩码固定
                    GATEWAY=192.168.1.1             网关
                    DNS1=8.8.8.8                    DNS1设置为网关即可
                然后重启网络服务
                    sudo systemctl restart network
            CentOS9
                默认的网络配置方式是通过 NetworkManager 管理网络接口, 推荐使用 nmcli 命令行工具 或 编辑 keyfile 配置文件 来配置固定 IP.

    
    网络请求和下载
        可以通过ping命令,检查指定网络服务器是否可联通状态
        wget是非交互式的文件下载器,用于下载网络文件和资源
        curl用于发送http网络请求,可用于下载文件,获取信息等...


    端口
        端口是设备与外界通讯交流的出入口, 可以分为 物理端口 和 虚拟端口
        物理端口又称之为接口, 是可见端口, 如USB接口, RJ45网口, HDMI端口等等.
        虚拟端口是计算机内部的端口, 是虚拟的不可见的, 是操作系统和外部进行交互使用的.
        计算机之间的通讯, 是通过IP锁定某个具体的计算机, 但无法锁定具体的程序.
        计算机程序之间的通讯, 就是通过端口实现的, 具体来说是IP + 端口
        最大端口号到 65535, 端口可以分为三类进行使用:
            公认端口: 0 ~ 1023, 通常用于一些系统内置或知名程序的预留使用, 如ssh的22端口, https的443端口, 非特殊需要, 不要占用这个范围的端口.
                常见的知名程序的端口号:
                    | 端口号   | 协议      | 服务/程序名称       | 说明                    |
                    | ----- | ------- | ------------- | --------------------- |
                    | 22    | TCP     | SSH           | 远程登录、文件传输（scp/sftp）   |
                    | 80    | TCP     | HTTP          | 超文本传输协议, 网页访问          |
                    | 443   | TCP     | HTTPS         | HTTP 的安全版本, SSL/TLS 加密 |
                    | 21    | TCP     | FTP           | 文件传输协议                |
                    | 25    | TCP     | SMTP          | 邮件发送协议                |
                    | 110   | TCP     | POP3          | 邮件接收协议                |
                    | 143   | TCP     | IMAP          | 邮件接收协议（支持服务器同步）       |
                    | 53    | UDP/TCP | DNS           | 域名解析                  |
                    | 3306  | TCP     | MySQL         | MySQL 数据库服务端口         |
                    | 5432  | TCP     | PostgreSQL    | PostgreSQL 数据库服务端口    |
                    | 6379  | TCP     | Redis         | Redis 内存数据库           |
                    | 27017 | TCP     | MongoDB       | MongoDB 数据库           |
                    | 8080  | TCP     | HTTP 代理端口  | 常用于开发环境、代理服务器         |
                    | 3389  | TCP     | RDP           | Windows 远程桌面          |
                    | 5900  | TCP     | VNC           | 远程桌面协议                |
                    | 123   | UDP     | NTP           | 网络时间协议                |
                    | 139   | TCP     | SMB/CIFS      | Windows 文件共享（NetBIOS） |
                    | 445   | TCP     | SMB           | Windows 文件共享          |
                    | 69    | UDP     | TFTP          | 简单文件传输协议              |
                    | 11211 | TCP/UDP | Memcached     | 分布式缓存                 |
                    | 9200  | TCP     | Elasticsearch | Elasticsearch HTTP 接口 |
            注册端口: 1024 ~ 49151, 通常可以随意使用, 用于松散的绑定一些程序和服务
            动态端口: 49152 ~ 65535, 通常不会固定绑定程序, 而是当程序对于进行网络通讯时临时使用
        查看当前系统端口占用情况:
            安装
                sudo dnf install -y nmap
            使用
                nmap 127.0.0.1
        查看指定端口的占用情况
            使用netstat
                安装
                    sudo dnf install -y net-tools
                使用
                    netstat -anp | grep 端口号
            使用ss(推荐)
                安装: 现在默认大多数linux系统都支持 iproute2 套件, ss 就是 iproute2 套件中的一个工具.
                使用
                    ss -anp | grep 端口号


    进程管理
        计算机中的每个程序的运行都会被系统注册为一个进程, 并为每个进程非配一个进程ID, 即进程号
        根据程序名关闭程序
            得到程序进程运行信息,主要是PID
                ps -ef | grep 程序名称
            关闭程序
                kill 程序PID
            或者强制关闭
                kill -9 程序PID
        根据端口号关闭程序
            得到程序进程运行信息,主要是PID
                lsof -i :端口号
            关闭程序
                kill 程序PID
            或者强制关闭
                kill -9 程序PID


    主机状态监控
        系统资源监控
            通过top命令查看CPU, 内存使用情况, 类似于mac的 activity monitor 和 windows的任务管理器
            top命令详解
                选项:
                    -i          只显示运行的进程, 不限时闲置或无用的进程
                    -b	        批处理模式(非内部交互操作), 适合输出到文件或脚本使用
                    -n <次数>	 指定刷新次数后退出（配合 -b 使用）
                    -u <用户>	 仅显示指定用户的进程
                    -c          显示产生进程的完整命令,补全COMMAND列.
                    -p <PID>	仅显示指定 PID 的进程
                    -d <秒>	    指定刷新间隔时间（秒）
                    -H	        显示线程（Thread）
                示例:
                    top	                                ==>         直接启动实时监控
                    top -u root	                        ==>         仅显示 root 用户的进程
                    top -p 1234	                        ==>         仅查看 PID 为 1234 的进程
                    top -b -n 1 > top.txt	            ==>         批处理方式刷新一次, 并输出到文件
                    top -b -d 5 -n 3	                ==>         每 5 秒刷新一次, 共刷新 3 次（适合写脚本分析）
                    top -H	                            ==>         显示所有线程的资源使用情况
            输出解读:
                系统整体信息:
                    top - 14:33:50 up 10 days,  2:01,  3 users,  load average: 0.12, 0.25, 0.32
                        | 字段           | 含义                                              |
                        | ------------ | ----------------------------------------------- |
                        | 时间           | 当前系统时间                                          |
                        | up           | 系统已运行时间                                         |
                        | users        | 当前登录的用户数                                        |
                        | load average | 系统负载（1分钟、5分钟、15分钟平均）<br>**0.00–1.00 表示轻松, 越高越忙** |
                    Tasks: 224 total,   1 running, 223 sleeping,   0 stopped,   0 zombie
                        | 字段       | 含义         |
                        | -------- | ---------- |
                        | total    | 总进程数       |
                        | running  | 正在运行的进程数   |
                        | sleeping | 休眠（等待）的进程数 |
                        | stopped  | 停止的进程数     |
                        | zombie   | 僵尸进程数      |
                    %Cpu(s):  3.3 us,  1.0 sy,  0.0 ni, 95.3 id,  0.3 wa,  0.0 hi,  0.0 si,  0.0 st
                        | 字段 | 含义                     |
                        | -- | ---------------------- |
                        | us | 用户态 CPU 使用率            |
                        | sy | 内核态（系统）CPU 使用率         |
                        | ni | 用户进程空间内改变过优先级的进程占用 CPU |
                        | id | 空闲 CPU 时间              |
                        | wa | 等待 I/O（磁盘/网络等）         |
                        | hi | 硬中断占用 CPU              |
                        | si | 软中断占用 CPU              |
                        | st | 被虚拟机窃取的时间（steal）       |
                    MiB Mem :   7896.3 total,   1523.2 free,   4021.7 used,   2351.4 buff/cache
                        | 字段         | 含义                   |
                        | ---------- | -------------------- |
                        | total      | 总物理内存                |
                        | free       | 空闲物理内存               |
                        | used       | 已使用（不包括缓存和 buffer）   |
                        | buff/cache | 缓存和缓冲区（Linux 内存管理特性） |
                    MiB Swap:   2048.0 total,   2048.0 free,      0.0 used.   3610.2 avail Mem
                        | 字段        | 含义             |
                        | --------- | -------------- |
                        | total     | 总交换空间(虚拟内存)  |
                        | free      | 空闲交换空间         |
                        | used      | 已使用的交换空间       |
                        | avail Mem | 真实可用内存（包含缓存部分） |
                进程列表
                    | 字段      | 含义                             |
                    | ------- | ------------------------------ |
                    | PID     | 进程 ID                          |
                    | USER    | 所属用户                           |
                    | PR      | 进程优先级（priority,越小优先级越高）      |
                    | NI      | nice 值（影响优先级, 越小优先级越高）          | 
                    | VIRT    | 虚拟内存使用总量（包括 swap、共享库等）         |
                    | RES     | 实际物理内存占用（常驻内存）                 |
                    | SHR     | 共享内存（和其他进程共享的部分）               |
                    | S       | 进程状态（R=运行, S=睡眠, Z=僵尸, T=停止, I=空闲） |
                    | %CPU    | 占用 CPU 百分比                     |
                    | %MEM    | 占用物理内存百分比                      |
                    | TIME+   | 累计使用的 CPU 时间                   |
                    | COMMAND | 启动该进程的命令名称                     |
                操作
                    q	退出 top
                    h	显示帮助信息
                    1	显示每个 CPU 的使用率
                    M	按内存使用排序
                    P	按 CPU 使用排序
                    T	按累计运行时间排序
                    k	杀进程（输入 PID 后按提示操作）
                    r	renice（修改进程优先级）
                    u	输入用户名, 仅显示该用户的进程
                    f	自定义显示字段
                        space       选中列/取消选中列
                        up          上移
                        down        下移
                        q/esc       退出
                    e   切换进程内存显示单位
                    i   显示/隐藏闲置和无用进程,等同于 -i 参数
                    l   显示/隐藏平均负载和启动时间信息.
                    t   显示/隐藏cpu状态信息
                    m   显示隐藏内存信息
        磁盘监控
            使用df命令,查看硬盘的使用情况
                选项:
                    -h	        以人类可读的格式显示（自动换算成 KB/MB/GB）
                    -H	        类似 -h, 但使用1000进制（千进制）单位
                    -k	        以 KB 为单位显示（默认单位）
                    -m	        以 MB 为单位显示
                    -T	        显示文件系统类型（ext4、tmpfs 等）
                    -i	        显示 inode 使用情况（文件节点数量）
                    --total	    显示所有文件系统的汇总
                    -t <类型>	 只显示指定类型的文件系统
                    -x <类型>	 排除指定类型的文件系统
                示例:
                    df -h                   ==>         查看系统的空间
                    df -h /home             ==>         查看 home 目录所在文件系统的空间
                输出字段解读:
                    Filesystem	    文件系统的设备名或挂载点（分区名称）
                    Size	        文件系统的总容量    
                    Used	        已用空间
                    Avail	        剩余可用空间
                    Use%	        已用空间百分比
                    Mounted on	    文件系统挂载点（挂载目录）
            使用iostat查看cpu,磁盘的具体使用指标
                iostat -x n1 n2
                    -x 表示显示更多信息
                    n1 表示刷新间隔
                    n1 表示刷新几次
        网络监控
            使用sar命令查看网络的统计信息, sar是非常强大的工具, 这里只解释 -n 选项用途
                sar -n DEV n1 n2
                    -n 表示查看网络 DEV 表示查看网络接口
                    n1 表示刷新间隔(缺省时查看一次就结束)
                    n2 表示查看次数(缺省时表示无限次数)
                输出字段解读:
                    | 字段         | 含义                                                    |
                    | ---------- | ----------------------------------------------------- |
                    | `IFACE`    | 接口名称（如 `eth0`, `lo`, `ens33` 等）                       |
                    | `rxpck/s`  | 每秒接收的 **网络包（packet）数**（Receive packets per second）    |
                    | `txpck/s`  | 每秒发送的 **网络包数**（Transmit packets per second）           |
                    | `rxkB/s`   | 每秒接收的 **数据量（KB）**（Receive kilobytes per second）       |
                    | `txkB/s`   | 每秒发送的 **数据量（KB）**（Transmit kilobytes per second）      |
                    | `rxcmp/s`  | 每秒接收的 **压缩数据包数**（Rare, Receive Compressed packets）     |
                    | `txcmp/s`  | 每秒发送的 **压缩数据包数**（Transmit Compressed packets）         |
                    | `rxmcst/s` | 每秒接收的 **多播数据包数**（Multicast packets per second）        |
                    | `%ifutil`  | 接口利用率（Interface utilization）<br>≈(rxkB/s + txkB/s)/带宽 |


    环境变量
        执行env命令可查看当前系统中记录的环境变量, 其是一种 key=value 型结构
        无论在任何时候都能正确执行 cd 等系统命令, 就是环境变量中 PATH 这个项目的值的作用.
        查看详细PATH的记录值:
            env | grep PATH
        输出:
            PATH=/home/anglee/.local/bin:/home/anglee/bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin
        解释:
            PATH是由多个:进行将多个值分割的, 当执行 cd 系统命令时, 会在 : 分割的前后多个目录中搜索是否有 cd 可执行程序
            直到搜索到 cd 这个可执行程序, 如果都没有结果将会输出 bash: xxx: command not found...
        ${}
            在Linux中 ${} 符号被用于取变量的值.
            比如 ${PATH} 就可以得到 /home/anglee/.local/bin:/home/anglee/bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin
            然后配合 echo 正确输出 $PATH 的值 echo ${PATH} 也可以直接 echo $PATH
        环境变量设置
            临时设置:
                export 变量名=变量值
                示例:
                    export MYNAME=anglee
                    即可在全局的当前会话下的当前用户通过 echo $MYNAME 得到 anglee
            永久设置:
                针对当前用户生效
                    配置在 ~/.bashrc 或 ~/.bash_profile 系统文件中
                    配置内容:
                        export MYNAME=anglee
                    重载配置:
                        source ~/.bashrc
                    保存后即可在全局的当前用户通过 echo $MYNAME 得到 anglee
                针对所有用户生效
                    配置在 /etc/profile 或 /etc/environment 系统文件中
                    配置内容:
                        export MYNAME=anglee
                    重载配置:
                        ssource /etc/profile
                    保存后即可在全局的所有用户通过 echo $MYNAME 得到 anglee
                注意最后需要通过 source /etc/profile 或 source ~/.bashrc, 即重载配置文件立即生效, 
        自定义一个环境变量
            切换root用户, 在当前HOME目录内创建文件夹, myenv, 在文件夹内创建文件mkhaha
            通过vim编辑器, 在mkhaha文件内填入: echo "Hahahahaha".
            当执行 sudo ./mkhaha 会得到 sudo: ./mkhaha: command not found
            是因为 mkhaha 是不可执行的文件, 没有执行权限, 需要设定为执行权限的文件 chmod 755 mkhaha
            再次 ./mkhaha 即可得到正确输出 Hahahahaha.
            修改PATH的值
                临时修改PATH:
                    export PATH=$PATH:/home/itheima/myenv, 再次执行mkhaha, 无论在哪里都能执行了
                永久修改PATH:
                    export PATH=$PATH:/home/itheima/myenv, 填入用户环境变量文件或系统环境变量文件中.
            此时在任意工作目录都可以正确执行 mkhaha 这个自定义命令.
    

    上传和下载
        使用lrzsz工具包
            安装上传和下载文件工具 lrzsz
            sudo dnf install lrzsz
            rz(文件上传/文件接收)和sz(文件下载/文件发送)属于 lrzsz 工具包的一部分, 是基于 ZModem 协议 的命令行文件传输工具
            注意mac下需要使用finalshell工具才支持 ZModem 协议. 除此之外的大多数都不支持 zModem协议.
            rz命令选项:
                -y	自动覆盖本地已有文件（不提示）
                -e	启动 rz 后自动退出
                -b	使用二进制传输（binary），效率更高
                -a	ASCII 模式传输，适用于文本文件
                -E	传输出错时自动退出
                -q	安静模式（不显示详细过程）
                -t	安全模式（telnet/ssh 使用时自动打开）
                -v	显示详细信息（verbose）
            sz命令选项:
                -y	自动覆盖本地已有文件
                -e	传输完成后自动退出
                -b	使用二进制方式发送
                -a	ASCII 文本发送
                -E	发生错误时退出
                -q	静默模式
                -v	显示详细过程
                --escape	启用转义传输模式（防止传输中断）
        使用scp命令
            scp（Secure Copy Protocol）是基于 SSH 的远程文件拷贝命令, 用于在本地和远程之间, 或两个远程主机之间安全地复制文件或目录
            命令格式:
                scp [选项] 源路径 目标路径
            命令选项:
                -r	递归复制整个目录
                -P	指定远程主机 SSH 端口（注意是大写 P）
                -C	启用压缩传输，提高速度
                -p	保留文件的原始修改时间、访问时间和权限
                -v	显示详细信息（调试用）
                -q	安静模式，禁止进度条显示
                -i	指定私钥文件，用于密钥认证
            命令示例:
                scp ./photo.jpg anglee@192.168.1.10:/home/anglee/images/            ==>         将 photo.jpg 发送到远程服务器的指定目录中。
                scp anglee@192.168.1.10:/home/anglee/report.txt ./                  ==>         从远程服务器下载 report.txt 到当前目录。
                scp -r ./project anglee@192.168.1.10:/home/anglee/                  ==>         使用 -r 递归复制整个目录。
                scp -r anglee@192.168.1.10:/home/anglee/logs ./backup/              ==>         下载整个目录
                scp -P 2222 file.txt anglee@192.168.1.10:/home/anglee/              ==>         使用指定端口 2222 进行文件传输
                scp file1 file2 file3 user@host:/path/                              ==>         复制文件到远程主机/path/目录
        

    压缩和解压
        详见第一章节Linux常用命令的 tar, zip/unzip 命令详解.

    
    挂载和卸载挂载
        安装nfs工具包
            sudo apt install nfs-common -y
        命令格式:
            sudo mount [选项] 设备/远程目录 本地挂载点
        命令示例:
            sudo mount -t nfs 192.168.1.100:/home/wheeltec/wheeltec_robot /mnt      ==>         把远程主机（IP：192.168.1.100）的共享目录挂到本地 /mnt,实现文件共享(修改远程时,会同步修改本地,反之同理)
            sudo umount /mnt                                                        ==>         卸载挂载
        




零、壹、贰、叁、肆、伍、陆、柒、捌、玖、拾;