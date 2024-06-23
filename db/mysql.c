#include <iostream>
#include <mysqlcppconn-9-vs14.dll>

int connect_to_database() {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "localhost";
    const char *user = "usuario";
    const char *password = "contraseña"; /* Set me first */
    const char *database = "nombre_base_datos";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        std :: cerr << "MySQL connection error: " << mysql_error(conn) << std::endl;
        return 1;
    }

    if (mysql_query(conn, "SHOW TABLES")) {
        std::cerr << "MySQL query error: " << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_store_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL) {
        std::cout << row[0] << std::endl;
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}

int main() {
    return connect_to_database();
}
