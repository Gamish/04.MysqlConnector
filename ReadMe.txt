C++ VS2022连接Mysql数据库示例

参考教程 https://www.cnblogs.com/flipped/p/6810216.html

Mysql 连接: （动态链接）
connector/c++ 连接mysql环境配置：
1. 先将解决方案改为release x64
2. 右击项目->属性->配置属性->“C/C++”->常规，在“附加包含目录”中将 Connector C++ 8.0  的"include"及"include"文件夹下所有包含.h头文件的文件夹的路径包含进来。（当然你也可以在代码中将他们加入）
3. 链接器->附加库目录，把包含lib文件的目录添加进去。本文中为：C:\Program Files\MySQL\Connector C++ 8.0\lib64\vs14
4. 链接器->输入->附加依赖项，把mysqlcppconn.lib和mysqlcppconn8.lib加上去。（注意文件夹中剩下的名字带static的lib不用放上去，原因是静态链接和动态链接的区别）
5. 把 Connector C++ 8.0\lib64 文件夹下面的dll文件全部复制到c:windows/system32下 或者项目根目录\x64\Release下
