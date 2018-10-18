/** \addtogroup platform */
/** @{*/
/**
 * \defgroup platform_error Error functions
 * @{
 */
/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include "platform/mbed_retarget.h"
#include "hal/crc_api.h"
#include "mbed_crc_wrapper.h"
#include "MbedCRC.h"

void *create_mbed_crc(crc_polynomial_t polynomial) {
    mbed::MbedCRC<POLY_32BIT_REV_ANSI, 32> *crc_obj = new mbed::MbedCRC<POLY_32BIT_REV_ANSI, 32> ();
    return (void *)crc_obj;
}

int32_t compute_mbed_crc(void *crc_obj, void *data, int datalen, uint32_t *crc) {
    return (static_cast<mbed::MbedCRC<POLY_32BIT_REV_ANSI, 32> *>(crc_obj))->compute(data, datalen, crc);
}

void delete_mbed_crc(void *crc_obj) {
    delete (static_cast<mbed::MbedCRC<POLY_32BIT_REV_ANSI, 32> *>(crc_obj));
}
    
/** @}*/
/** @}*/


