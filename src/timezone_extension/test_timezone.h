#ifndef PHP_TEST_TIMEZONE_H
#define PHP_TEST_TIMEZONE_H
#endif

extern zend_module_entry test_timezone_module_entry;
#define phpext_test_timezone_ptr &test_timezone_module_entry

#ifdef PHP_WIN32
#define PHP_TEST_TIMEZONE_API __declspec(dllexport)
#else
#define PHP_TEST_TIMEZONE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(     test_timezone );
PHP_MSHUTDOWN_FUNCTION( test_timezone );
PHP_RINIT_FUNCTION(     test_timezone );
PHP_RSHUTDOWN_FUNCTION( test_timezone );
PHP_MINFO_FUNCTION(     test_timezone );

/**
 * PHP_FUNCTION(test_timezone_addPageViewCount)
 *
 * @input char mid : merchandise id
 *
 * @return string 0: success, 1: failure
 */
PHP_FUNCTION(test_timezone);
