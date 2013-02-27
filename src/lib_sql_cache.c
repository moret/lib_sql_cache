#include "lib_sql_cache.h"

int db_cb(void *life, int argc, char **argv, char **azColName);
int lib_sql_cache_function();

int db_cb(void *relay, int argc, char **argv, char **azColName)
{
    int life;
    int i;

    for (i = 0; i < argc; i++)
    {
        life = atoi(argv[i]);
    }

    memcpy(relay, &life, sizeof(int));
    return 0;
}

int lib_sql_cache_function()
{
    int life;
    sqlite3 *db;

    sqlite3_open("var/check_cache.db", &db);
    sqlite3_exec(db, "create table iv(i int, v varchar);", NULL, NULL, NULL);
    sqlite3_exec(db, "insert into iv values (1, 42);", NULL, NULL, NULL);
    sqlite3_exec(db, "select v from iv where i = 1;", db_cb, &life, NULL);

    //What is the meaning of life?
    return life;
}
