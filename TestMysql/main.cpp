#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <qDebug>
void connect_mysql()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");      //�������ݿ���������������Ҫע�⣨�����Ϊ��127.0.0.1�������ֲ������ӣ����Ϊlocalhost)
	db.setPort(3306);                 //�������ݿ�˿ںţ�������һ��
	db.setDatabaseName("student");      //�������ݿ�����������һ��
	db.setUserName("root");          //���ݿ��û�����������һ��
	db.setPassword("");    //���ݿ����룬������һ��
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

	// ��
	QSqlQuery query(db);
	query.exec("select * from grad"); // grad is table
	while (query.next())
	{
		QString strTmp = query.value("score").toString();// score is column
		qDebug() << strTmp;
	}

	// ��
	QString strSqlExe = "insert into grad (ID,score) values (7,77)";
	query.exec(strSqlExe);

	// ɾ
	strSqlExe = "delete from grad where score = 66";
	query.exec(strSqlExe);

	// ��
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
