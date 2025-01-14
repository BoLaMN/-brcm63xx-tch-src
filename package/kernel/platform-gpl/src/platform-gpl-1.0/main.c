/********** COPYRIGHT AND CONFIDENTIALITY INFORMATION NOTICE *************
** Copyright (c) 2014 - Technicolor Delivery Technologies, SAS          **
** All Rights Reserved                                                  **
**                                                                      **
** This program is free software; you can redistribute it and/or modify **
** it under the terms of the GNU General Public License version 2 as    **
** published by the Free Software Foundation.                           **
*************************************************************************/

#include <linux/version.h>
#include <linux/module.h>
#include <linux/types.h>

#include "bootloader.h"

MODULE_LICENSE("GPL");


int platform_gpl_mod_init( void )
{
        int err;

        err = bootloader_init();

        if (err != 0) {
                return err;
        }

        return 0;
}

void platform_gpl_mod_cleanup( void )
{
        bootloader_cleanup();
}


module_init( platform_gpl_mod_init );
module_exit( platform_gpl_mod_cleanup );

