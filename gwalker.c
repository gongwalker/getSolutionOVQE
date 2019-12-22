/* gwalker extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_gwalker.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void gwalker_test1()
 */
PHP_FUNCTION(gwalker_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "gwalker");
}
/* }}} */

/* {{{ string gwalker_test2( [ string $var ] )
 */
PHP_FUNCTION(gwalker_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/



PHP_FUNCTION(getSolutionOVQE)
{
    double a = 0;
    double b = 0;
    double c = 0;

    
    double x1 = 0;
    double x2 = 0;

    double detal = 0;

    
    ZEND_PARSE_PARAMETERS_START(2, 3) 
        Z_PARAM_DOUBLE(a)                 
        Z_PARAM_DOUBLE(b)                 
        Z_PARAM_OPTIONAL                  
        Z_PARAM_DOUBLE(c)             
        ZEND_PARSE_PARAMETERS_END();
        
    if (a == 0 && b == 0)
    {
	RETURN_FALSE;
    } 	

    array_init(return_value);

    if (a == 0)
    {
        x1 = -1 * (c/b);
        add_index_double(return_value, 0, x1);
        return;
    }
    detal = pow(b, 2) - 4 * a * c;

    if (detal == 0)
    {
        x1 = (-b + sqrt(detal)) / (2 * a);
        add_index_double(return_value, 0, x1);
        return;
    }
    else if (detal > 0)
    {
        x1 = (-b + sqrt(detal)) / (2 * a);
        x2 = (-b - sqrt(detal)) / (2 * a);
        add_index_double(return_value, 0, x1);
        add_index_double(return_value, 1, x2);
        return;
    }
   
    RETURN_FALSE;
}

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(gwalker)
{
#if defined(ZTS) && defined(COMPILE_DL_GWALKER)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(gwalker)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gwalker support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_gwalker_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gwalker_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ gwalker_functions[]
 */
static const zend_function_entry gwalker_functions[] = {
	PHP_FE(gwalker_test1,		arginfo_gwalker_test1)
	PHP_FE(gwalker_test2,		arginfo_gwalker_test2)
	PHP_FE(getSolutionOVQE,		NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ gwalker_module_entry
 */
zend_module_entry gwalker_module_entry = {
	STANDARD_MODULE_HEADER,
	"gwalker",					/* Extension name */
	gwalker_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(gwalker),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(gwalker),			/* PHP_MINFO - Module info */
	PHP_GWALKER_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GWALKER
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(gwalker)
#endif
