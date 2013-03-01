all: test

test: dirs
	@echo 'Target $@'
	gcc tests/check_lib_sql_cache.c src/lib_sql_cache.c -lcheck -lsqlite3 -o bin/check_test_suite
	bin/check_test_suite

lib: dirs
	@echo 'Target $@'
	gcc src/lib_sql_cache.c -shared -c -o bin/libsqlcache.so

run: lib dirs
	@echo 'Target $@'
	gcc example/run.c -Lbin/ -Isrc/ -lsqlcache -lsqlite3 -o bin/run
	bin/run

dirs:
	mkdir -p bin/

clean:
	rm -rf bin/
