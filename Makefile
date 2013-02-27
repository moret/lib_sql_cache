all: test

test:
	@echo 'Target $@'
	rm -rf bin/ var/
	mkdir bin/ var/
	gcc -Wall -Werror -O -fast tests/check_lib_sql_cache.c src/lib_sql_cache.c -lcheck -lsqlite3 -o bin/check_test_suite
	bin/check_test_suite
