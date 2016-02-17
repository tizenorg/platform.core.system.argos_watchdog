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

#ifndef __ARGOS_H__
#define __ARGOS_H__

#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumeration for controlling watchdog operation.
 * @since_tizen 2.4
 *
*/
typedef enum {
	AW_OP_DISABLE,			/**< watchdog disable **/
	AW_OP_ENABLE,			/**< watchdog enable **/
	AW_OP_CHANGE_TIMEOUT,	/**< change watchdog timeout **/
} aw_op_e;

/**
 * @brief Register watchdog.
 *
 * @since_tizen 2.4
 *
 * @remarks
 *
 * @return 0 on success, otherwise a errno-style error value.
 *
 */
int aw_register(unsigned int timeout);

/**
 * @brief Control watchdog operation.
 *
 * @since_tizen 2.4
 *
 * @remarks In op AW_OP_ENABLE and AW_OP_DISABLE, the API ignores data field.
 *          In op AW_OP_CHANGE_TIMEOUT, data field requires timeout value.
 *
 * @return 0 on success, otherwise a errno-style error value.
 *
 */
int aw_control(aw_op_e op, void *data);

/**
 * @brief Notify watchdog.
 *
 * @since_tizen 2.4
 *
 * @remarks
 *
 * @return 0 on success, otherwise a errno-style error value.
 *
 */
int aw_notify(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARGOS_H__ */
