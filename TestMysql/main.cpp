#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <qDebug>
void connect_mysql()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
	db.setPort(3306);                 //连接数据库端口号，与设置一致
	db.setDatabaseName("student");      //连接数据库名，与设置一致
	db.setUserName("root");          //数据库用户名，与设置一致
	db.setPassword("");    //数据库密码，与设置一致
	db.open();

	if (!db.open())
	{
		qDebug() << QStringLiteral("connect to mysql failed !");
		return;
	}
	else
	{
		qDebug()<< QStringLiteral("connect to mysql OK !");
	}

	// 查
	QSqlQuery query(db);
	query.exec("select * from grad"); // grad is table
	while (query.next())
	{
		QString strTmp = query.value("score").toString();// score is column
		qDebug() << strTmp;
	}

	// 增
	QString strSqlExe = "insert into grad (ID,score) values (7,77)";
	query.exec(strSqlExe);

	// 删
	strSqlExe = "delete from grad where score = 66";
	query.exec(strSqlExe);

	// 改
	strSqlExe = "UPDATE grad SET score = 666 WHERE ID = 4 AND score = 789";
	query.exec(strSqlExe);

	db.close();

	qDebug() << "insert into is success !";
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	connect_mysql();
	return a.exec();
}
