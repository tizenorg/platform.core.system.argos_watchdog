/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "common.h"
#include <systemd/sd-daemon.h>

/* In case of watchdog based on systemd sd_notify,
 * runtime registration does not support.
 * It will be supported by resrouced watchdog in the future */

int _aw_register(unsigned int timeout)
{
	return -ENOTSUP;
}

/* Under development - Ask to Mr.Hwang for the progress */
int _aw_control(aw_op_e op, void *data)
{
	return -ENOTSUP;
}

int _aw_notify(void)
{
	int err;
	err = sd_notify(0, "WATCHDOG=1");

	if(err == 0)
		return -ECOMM;
	else if(err > 0)
		err = 0;

	return err;
}

