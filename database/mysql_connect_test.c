//前提是有MSI的mysql数据库，还有STUDENT的库表, 库表中包含学号姓名并且是字符型
#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"

int main(void) {
	MYSQL 	  *mysql = malloc(sizeof(MYSQL));
	MYSQL_RES *result = NULL;
	MYSQL_ROW  row;

	if (mysql_init(mysql) == NULL)
		fprintf(stderr, "mysql init error");

	mysql = mysql_real_connect(mysql, "localhost", "root", "qiangxi2100", "MSI", 0, NULL, 0);
	if (mysql == NULL) {
		printf("connect error%s\n", mysql_error(mysql));
		return -1;
	}

	//查询数据
	mysql_query(mysql, "select * from STUDENT");
	result = mysql_store_result(mysql);
	printf("学号\t\t姓名\n");
	while ((row = mysql_fetch_row(result)) != 0)
		printf("%s\t%s\n", row[0], row[1]);
	
	free(mysql); mysql = NULL;
	mysql_free_result(result);
	mysql_close(mysql);
	return 0;
}


