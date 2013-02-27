#include <check.h>
#include <stdlib.h>
#include "../src/lib_sql_cache.h"

START_TEST (lib_sql_cache_test)
{
    fail_unless (lib_sql_cache_function() == 42, "Wrong meaning of life, the universe and everything.");
}
END_TEST

Suite* lib_sql_cache_suite(void)
{
    Suite *s = suite_create("lib_sql_cache_suite");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, lib_sql_cache_test);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = lib_sql_cache_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
