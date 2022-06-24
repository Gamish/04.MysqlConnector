// king.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// Mysql 连接: （动态链接）
// connector/c++ 连接mysql环境配置：
// 1. 先将解决方案改为release x64
// 2. 右击项目->属性->配置属性->“C/C++”->常规，在“附加包含目录”中将 Connector C++ 8.0  的"include"及"include"文件夹下所有包含.h头文件的文件夹的路径包含进来。（当然你也可以在代码中将他们加入）
// 3. 链接器->附加库目录，把包含lib文件的目录添加进去。本文中为：C:\Program Files\MySQL\Connector C++ 8.0\lib64\vs14
// 4. 链接器->输入->附加依赖项，把mysqlcppconn.lib和mysqlcppconn8.lib加上去。（注意文件夹中剩下的名字带static的lib不用放上去，原因是静态链接和动态链接的区别）
// 5. 把 Connector C++ 8.0\lib64 文件夹下面的dll文件全部复制到c:windows/system32下 或者项目根目录\x64\Release下

#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
using namespace sql;
using namespace std;
int main()
{
	cout << endl;
	cout << "正在执行 'SELECT 'Hello World!' AS _message'..." << endl;

	try {
		sql::Driver* driver;
		sql::Connection* con;
		sql::Statement* stmt;
		sql::ResultSet* res;

		/* 创建连接 */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
		/* 连接 MySQL 数据库 king  */
		con->setSchema("king");

		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT * from cq_user_family_highlights");
		while (res->next()) {
			cout << "\t... MySQL replies: ";
			/* 获取某列属性值通过列名 */
			cout << "id : " << res->getString("id") << "  idUser : " << res->getString("user_id") << "   pos:" << res->getString("pos") << endl;
			/* 通过数字偏移量, 1 代表第一列 */
			cout << res->getString(1) << endl;
		}
		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException& e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	cout << endl;

	getchar();

	return 0;
}

// 下载安装boost库
// 后续编译过程中报错说fatal error C1083 : Cannot open include file : boost / shared_ptr.hpp
// 原来是项目没有添加boost库的额外Include目录，而mysql_connection.h中又引用了该库。因此这一步也是需要的。
// 下载地址：https://sourceforge.net/projects/boost/
// 下载安装好后， 项目属性 = > C / C++ = > 输入 = > 附加包含目录 中添加C : \local\boost_1_64_0