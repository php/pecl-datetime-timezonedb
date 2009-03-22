/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2005 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Derick Rethans <derick@php.net>                             |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"

#include "php_timezonedb.h"

#include "ext/date/php_date.h"

#define  timezonedb_builtin timezonedb_external
#define  timezonedb_idx_builtin timezonedb_idx_external
#define  timelib_timezone_db_data_builtin timelib_timezone_db_data_external

#include "timezonedb.h"

/* {{{ timezonedb_functions[]
 */
function_entry timezonedb_functions[] = {
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ timezonedb dependencies */
#if ZEND_MODULE_API_NO >= 20050922
static const zend_module_dep timezonedb_module_deps[] = {
	ZEND_MOD_REQUIRED("standard")
	ZEND_MOD_REQUIRED("date")
	{NULL, NULL, NULL}
};
#endif
/* }}} */
/* {{{ timezonedb_module_entry
 */
zend_module_entry timezonedb_module_entry = {
#if ZEND_MODULE_API_NO >= 20050922
	STANDARD_MODULE_HEADER_EX, NULL,
	timezonedb_module_deps,
#else
	STANDARD_MODULE_HEADER,
#endif
	"timezonedb",
	timezonedb_functions,
	PHP_MINIT(timezonedb),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(timezonedb),
	"2009.3",
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TIMEZONEDB
ZEND_GET_MODULE(timezonedb)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(timezonedb)
{
	php_date_set_tzdb(&timezonedb_external);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(timezonedb)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(timezonedb)
{
	timelib_tzdb *tzdb = &timezonedb_external;

	php_info_print_table_start();
	php_info_print_table_row(2, "Alternative Timezone Database", "enabled");
	php_info_print_table_row(2, "Timezone Database Version", tzdb->version);
	php_info_print_table_end();
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
