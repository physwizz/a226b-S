/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"

#define MAX_OTP_SIZE_4K 0x1000
#define MAX_EEPROM_SIZE_16K 0x4000

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
        //+bug604664 zhouyikuan, add, 2020/12/18,hi4821q_qt eeprom bring up
        {W1HI4821QREARQT_SENSOR_ID, 0xA0, Common_read_region},
        //-bug604664 zhouyikuan, add, 2020/12/18,hi4821q_qt eeprom bring up
        //+bug604664 chenbocheng.wt, add, 2020/12/23,hi4821q_sy eeprom bring up
        {W1HI4821QREARSY_SENSOR_ID, 0xA0, Common_read_region},
        //+bug604664 liudijn, add, 2020/12/25,3ts ov48b2q eeprom bring up.
        {W1OV48B2QREARXL_SENSOR_ID, 0xA0, Common_read_region},
        //+bug604664 liudijn, add, 2021/03/29, w1ov64b40reartxd eeprom bring up.
        {W1OV64B40REARTXD_SENSOR_ID, 0xA0, Common_read_region},
        //+bug710560 wangmingli, add, 2021/12/29,st_hi846 dc_gc8034 st2_hi846 and txd_c8490 eeprom bring up
        //+bug604664 zhouyikuan, add, 2020/12/14,hi846&gc8034  eeprom bring up
        {W1HI846FRONTST_SENSOR_ID, 0xA0, Common_read_region},
        {W1GC8034FRONTDC_SENSOR_ID, 0xA0, Common_read_region},
        //-bug604664 zhouyikuan, add, 2020/12/14,hi846&gc8034  eeprom bring up
        //+bug604664 wangmingli, add, 2021/11/8,hi846frontst2 eeprom bring up
        {W1HI846FRONTST2_SENSOR_ID, 0xA0, Common_read_region},
        //-bug604664 wangmingli, add, 2021/11/8,hi846frontst2 eeprom bring up
        //+bug604664 qinduilin, add, 2021/11/12,c8490 eeprom bring up
        {W1C8490FRONTTXD_SENSOR_ID, 0xA0, Common_read_region},
        //-bug604664 qinduilin, add, 2021/11/12,c8490 eeprom bring up
        //-bug710560 wangmingli, add, 2021/12/29,st_hi846 dc_gc8034 st2_hi846 and txd_c8490 eeprom bring up
        //+bug710560, zhanghao2.wt, ADD, 2021/12/31, add wide sensor hi556 gc5035c sc500cs eeprom bringup
        //+bug604664 liuxingyu.wt, add, 2020/12/17, hi556  eeprom bring up
        {W1GC5035CWIDECXT_SENSOR_ID, 0xA0, Common_read_region},
        //-bug604664 liuxingyu.wt, add, 2020/12/17, hi556  eeprom bring up
        //+bug604664,liuidijin.wt,ADD,2021/01/12,3 gong wide camera sc500cs eeprom bring up
        {W1SC500CSWIDELY_SENSOR_ID, 0xA0, Common_read_region},
        //-bug604664,liuidijin.wt,ADD,2021/01/12,3 gong wide camera sc500cs eeprom bring up
        //-bug710560, zhanghao2.wt, ADD, 2021/12/31, add wide sensor hi556 gc5035c sc500cs eeprom bringup

#if 0
	{IMX258_SENSOR_ID, 0xB0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC5035_SENSOR_ID, 0x6E, Otp_read_region_GC5035, MAX_OTP_SIZE_4K},
	/*Below is commom sensor */
	{IMX586_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K,
		BL24SA64_write_region},
	{IMX576_SENSOR_ID, 0xA2, Common_read_region},
	{IMX519_SENSOR_ID, 0xA0, Common_read_region},
	{IMX319_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3M5SX_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K,
		BL24SA64_write_region},
	{IMX686_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{HI846_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KGD1SP_SENSOR_ID, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV16A10_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3P9SP_SENSOR_ID, 0xA8, Common_read_region},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX350_SENSOR_ID, 0xA0, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	{S5KJD1_SENSOR_ID, 0xB0, Common_read_region, DEFAULT_MAX_EEPROM_SIZE_8K,
		DW9763_write_region},
	{IMX499_SENSOR_ID, 0xA0, Common_read_region},
	{S5KGM2_SENSOR_ID, 0xB0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K4HAYX_SENSOR_ID, 0x5A, Otp_read_region_S5K4HAYX,
		MAX_EEPROM_SIZE_16K},
	{S5K3L6_SENSOR_ID, 0x5A, Otp_read_region_S5K3L6,
		MAX_EEPROM_SIZE_16K},
#if 0
	{GC02M1_SENSOR_ID, 0xA4, Common_read_region, MAX_EEPROM_SIZE_16K},
	{SR846D_SENSOR_ID, 0x42, Otp_read_region_SR846,
		MAX_EEPROM_SIZE_16K},
	{GC5035_SENSOR_ID, 0x7E, Otp_read_region_GC5035,
		MAX_EEPROM_SIZE_16K},
#endif
	{IMX481_SENSOR_ID, 0xA4, Common_read_region, DEFAULT_MAX_EEPROM_SIZE_8K,
		BL24SA64_write_region},
#endif
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}


