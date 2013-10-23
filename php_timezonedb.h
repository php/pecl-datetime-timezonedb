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

#ifndef PHP_TIMEZONEDB_H
#define PHP_TIMEZONEDB_H

#include "php.h"

extern zend_module_entry timezonedb_module_entry;
#define phpext_timezonedb_ptr &timezonedb_module_entry

#define PHP_TIMEZONEDB_VERSION "2013.7"

PHP_MINIT_FUNCTION(timezonedb);
PHP_MINFO_FUNCTION(timezonedb);

#endif	/* TIMEZONEDB_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
