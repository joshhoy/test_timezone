extern "C" {

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

}

#include <string>
#include "test_timezone.h"
#include <auctions/php/PhpArrayData.h>
#include <ctime>

using namespace std;

/* If you declare any globals in php_test_timezone.h uncomment this:
 ZEND_DECLARE_MODULE_GLOBALS(test_timezone)
 */

/* True global resources - no need for thread safety here */
//static int le_test_timezone;

/**
 * test_timezone_functions[]
 *
 * Every user visible function must have an entry in test_timezone_functions[].
 */
zend_function_entry test_timezone_functions[]//{{{
= {
	PHP_FE(test_timezone, NULL)

	{	NULL, NULL, NULL} /* Must be the last line in test_timezone_functions[] */
};//}}}

//{{{ test_timezone_module_entry
zend_module_entry test_timezone_module_entry = { STANDARD_MODULE_HEADER,
		"test_timezone", test_timezone_functions, PHP_MINIT(test_timezone),
		PHP_MSHUTDOWN(test_timezone), NULL, NULL, PHP_MINFO(test_timezone),
		"0.1", /* Replace with version number for your extension */
		STANDARD_MODULE_PROPERTIES };
//}}}

extern "C" {

#ifdef COMPILE_DL_TEST_TIMEZONE
ZEND_GET_MODULE(test_timezone)
#endif

}

/**
 * PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(test_timezone)//{{{
{
	return SUCCESS;
}//}}}

/**
 * PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(test_timezone)//{{{
{
	/* uncomment this line if you have INI entries
	 UNREGISTER_INI_ENTRIES();
	 */
	return SUCCESS;
}//}}}

/**
 * PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(test_timezone)//{{{
{
	return SUCCESS;
}//}}}

/**
 * PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(test_timezone)//{{{
{
	return SUCCESS;
}//}}}

/**
 * PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(test_timezone)//{{{
{
	php_info_print_table_start();
	php_info_print_table_header(2, "test_timezone support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	 DISPLAY_INI_ENTRIES();
	 */
}//}}}

/**
 * PHP_FUNCTION(test_timezone_addPageViewCount)
 *
 * @input char mid : merchandise id
 *
 * @return string 0: success, 1: failure
 */
PHP_FUNCTION(test_timezone)//{{{
{
    int argc = ZEND_NUM_ARGS();
    int *ts = 0;

    if (zend_parse_parameters(argc TSRMLS_CC, "d", &ts)  == FAILURE) {
        return;
    }

//    putenv('TZ=Asia/Taipei');

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    cerr << "Current time: " << now << endl;

    cerr << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cerr << "The UTC date and time is:"<< dt << endl;

    cerr << "Number of sec since January 1,1970:" << now << endl;

    tm *ltm = localtime(&now);

    // print various components of tm structure.
    cerr << "Year: " << 1900 + ltm->tm_year<<endl;
    cerr << "Month: "<< 1 + ltm->tm_mon<< endl;
    cerr << "Day: "<<  ltm->tm_mday << endl;
    cerr << "Time: "<< ltm->tm_hour << ":";
    cerr << ltm->tm_min << ":";
    cerr << ltm->tm_sec << endl;

}//}}}

