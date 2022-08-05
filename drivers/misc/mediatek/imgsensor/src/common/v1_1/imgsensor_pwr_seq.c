/*
 * Copyright (C) 2017 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "kd_imgsensor.h"


#include "imgsensor_hw.h"
#include "imgsensor_cfg_table.h"

/* Legacy design */
struct IMGSENSOR_HW_POWER_SEQ sensor_power_sequence[] = {

//+bug604664 chenbocheng.wt, add, 2020/12/12, 1st supply main camera hi4821q bring up
#if defined(W1HI4821QREARQT_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1HI4821QREARQT_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_High, 1},
			{DOVDD, Vol_1800, 1},
			{DVDD_1V2_IN, Vol_High, 1},
			{DVDD_1V1, Vol_Low, 1},
			{DVDD, Vol_High, 1},
			{SensorMCLK, Vol_High, 10},
			{RST, Vol_High, 10},
		},
	},
#endif
//-bug604664 chenbocheng.wt, add, 2020/12/12, 1st supply main camera hi4821q bring up

//+bug604664 chenbocheng.wt, add, 2020/12/23, 2st supply main camera sunny hi4821q bring up
#if defined(W1HI4821QREARSY_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1HI4821QREARSY_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_High, 1},
			{DOVDD, Vol_1800, 1},
			{DVDD_1V2_IN, Vol_High, 1},
			{DVDD_1V1, Vol_Low, 1},
			{DVDD, Vol_High, 1},
			{SensorMCLK, Vol_High, 10},
			{RST, Vol_High, 10},
		},
	},
#endif
//-bug604664 chenbocheng.wt, add, 2020/12/23, 2st supply main camera sunny hi4821q bring up

//+bug584789,liudijin.wt,ADD,2020/12/12,add 3 gong xinli ov48b2q bringup code.
#if defined(W1OV48B2QREARXL_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1OV48B2QREARXL_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 1},
//			{AFVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 1},
			{DVDD_1V2, Vol_Low, 1},
			{DVDD_1V1, Vol_High, 1},
			{DVDD, Vol_High, 1},
			{RST, Vol_High, 6},
			{SensorMCLK, Vol_High, 2},
		},
	},
#endif
//-bug584789,liudijin.wt,ADD,2020/12/12,add 3 gong xinli ov48b2q bringup code.
//+bug584789, qinduilin.wt,ADD,2021/02/20,add for OV64B40 bringup
#if defined(W1OV64B40REARTXD_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1OV64B40REARTXD_MIPI_RAW,
		{
			{RST, Vol_Low, 5},
			{AVDD, Vol_2800, 5},
//			{AFVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 5},
			{DVDD_1V2, Vol_Low, 1},
			{DVDD_1V1, Vol_High, 1},
			{DVDD, Vol_High, 5},
			{SensorMCLK, Vol_High, 5},
			{RST, Vol_High, 6},
		},
	},
#endif
//-bug584789, qinduilin.wt,ADD,2021/02/20,add for OV64B40 bringup

//+bug710560, wangmingli.wt, ADD, 2021/12/28, add front camera st_hi846 dc_gc8034 st2_hi846 and txd_c8490 bringup
//+bug584789,zhouyikuan.wt,MODIFY,2020/12/10,n22_st_hi846 sensor bringup
#if defined(W1HI846FRONTST_MIPI_RAW)
        {
                SENSOR_DRVNAME_W1HI846FRONTST_MIPI_RAW,
                {
                        {DOVDD, Vol_1800, 1},
                        {DVDD_1V1, Vol_High, 1},
                        {DVDD_1V2, Vol_Low, 1},
                        {DVDD, Vol_High, 1},
                        {AVDD, Vol_High, 1},
                        {SensorMCLK, Vol_High, 10},
                        {RST, Vol_Low, 10},
                        {RST, Vol_High, 1},
                },
        },
#endif
//-bug584789,zhouyikuan.wt,MODIFY,2020/12/10,n22_st_hi846 sensor bringup
//+bug584789,zhanghengyuan.wt,MODIFY,2020/12/10,n22_front_dc_gc8034 sensor bringup
#if defined(W1GC8034FRONTDC_MIPI_RAW)
        {
                SENSOR_DRVNAME_W1GC8034FRONTDC_MIPI_RAW,
                {
                        {RST, Vol_Low, 1},
                        {DOVDD, Vol_1800, 1},
                        {DVDD_1V1, Vol_High, 1},
                        {DVDD_1V2, Vol_Low, 1},
                        {DVDD, Vol_1200, 1},
                        {AVDD, Vol_2800, 1},
                        {SensorMCLK, Vol_High, 1},
                        {RST, Vol_High, 1},
                },
        },
#endif
//-bug584789,zhouyikuan.wt,MODIFY,2020/12/10,n22_front_dc_gc8034 sensor bringup
//+bug604664,wangmingli.wt,add,2021/11/08,front n22_st2_hi846 sensor bringup
#if defined(W1HI846FRONTST2_MIPI_RAW)
        {
                SENSOR_DRVNAME_W1HI846FRONTST2_MIPI_RAW,
                {
                        {DOVDD, Vol_1800, 1},
                        {DVDD_1V1, Vol_High, 1},
                        {DVDD_1V2, Vol_Low, 1},
                        {DVDD, Vol_High, 1},
                        {AVDD, Vol_High, 1},
                        {SensorMCLK, Vol_High, 10},
                        {RST, Vol_Low, 10},
                        {RST, Vol_High, 1},
                },
        },
#endif
//-bug604664,wangmingli.wt,add,2021/11/08,front n22_st2_hi846 sensor bringup
//+bug584789, qinduilin.wt, ADD, 2021/11/10, add front camera c8490 bringup
#if defined(W1C8490FRONTTXD_MIPI_RAW)
        {
                SENSOR_DRVNAME_W1C8490FRONTTXD_MIPI_RAW,
                {
                        {DOVDD, Vol_1800, 1},
                        {DVDD_1V1, Vol_High, 1},
                        {DVDD_1V2, Vol_Low, 1},
                        {AVDD, Vol_2800, 1},
                        {DVDD, Vol_1200, 1},
                        {RST, Vol_Low, 1},
                        {RST, Vol_High, 10},
                        {SensorMCLK, Vol_High, 10},
                },
        },
#endif
//-bug584789, qinduilin.wt, ADD, 2021/11/10, add front camera c8490 bringup
//-bug710560, wangmingli.wt, ADD, 2021/12/28, add front camera st_hi846 dc_gc8034 st2_hi846 and txd_c8490 bringup

//+bug584789,zhanghengyuan.wt,MODIFY,2020/12/17,depth c2515 bf2253 gc02m1b bringup
#if defined(W1C2515DEPSJ_MIPI_MONO)
	{
		SENSOR_DRVNAME_W1C2515DEPSJ_MIPI_MONO,
		{
			{RST, Vol_High, 1,Vol_High},
			{DOVDD, Vol_1800, 20,Vol_Low},
			{AVDD, Vol_2800, 10,Vol_Low},
			{RST, Vol_Low, 10,Vol_High},
			{SensorMCLK, Vol_High, 10,Vol_Low},
		},
	},
#endif
#if defined(W1BF2253DEPLH_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1BF2253DEPLH_MIPI_RAW,
		{
			{RST, Vol_Low, 1,Vol_Low},
			{DOVDD, Vol_1800, 1,Vol_Low},
			{AVDD, Vol_Low, 1,Vol_Low},
			{SensorMCLK, Vol_High, 1,Vol_Low},
			{AVDD, Vol_2800, 1,Vol_2800},
			{RST, Vol_High, 1,Vol_Low},
			{RST, Vol_Low, 1,Vol_Low},
		},
	},
#endif
//+bug604664 chenbocheng.wt, add, 2021/01/13, distinguish depth camera params for dualcam
#if defined(W1BF2253DEPLH3_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1BF2253DEPLH3_MIPI_RAW,
		{
			{RST, Vol_Low, 1,Vol_Low},
			{DOVDD, Vol_1800, 1,Vol_Low},
			{AVDD, Vol_Low, 1,Vol_Low},
			{SensorMCLK, Vol_High, 1,Vol_Low},
			{AVDD, Vol_2800, 1,Vol_2800},
			{RST, Vol_High, 1,Vol_Low},
			{RST, Vol_Low, 1,Vol_Low},
		},
	},
#endif
#if defined(W1GC02M1BDEPCXT_MIPI_MONO)
	{
		SENSOR_DRVNAME_W1GC02M1BDEPCXT_MIPI_MONO,
		{
			{RST, Vol_Low, 15},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 1},
			{RST, Vol_High, 1},
			{SensorMCLK, Vol_High, 1},
		},
	},
#endif
#if defined(W1GC02M1BDEPCXT5_MIPI_MONO)
	{
		SENSOR_DRVNAME_W1GC02M1BDEPCXT5_MIPI_MONO,
		{
			{RST, Vol_Low, 15},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 1},
			{RST, Vol_High, 1},
			{SensorMCLK, Vol_High, 1},
		},
	},
#endif
//+bug710560 , zhanghao2.wt, ADD, 2021/12/28, add wide sensor hi556 gc5035c sc500cs bringup
//+bug584789, liuxingyu.wt, ADD, 2020/12/13, add hi556 gc5035c bringup
#if defined(W1HI556WIDEXL_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1HI556WIDEXL_MIPI_RAW,
		{
			{RST, Vol_Low, 0},
			{DVDD_1V2, Vol_Low, 0},
			{DVDD_1V1, Vol_High, 5},
			{DVDD2, Vol_High, 1},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 1},
			{DVDD, Vol_1100, 5},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 5},
		},
	},
#endif
#if defined(W1GC5035CWIDECXT_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1GC5035CWIDECXT_MIPI_RAW,
		{
			//{PDN, Vol_Low, 0},
			{DOVDD, Vol_1800, 2},
			{DVDD_1V2, Vol_Low, 1},
			{DVDD_1V1, Vol_High, 1},
			{DVDD2, Vol_High, 2},
			{DVDD, Vol_1200, 2},
			{AVDD, Vol_2800, 2},
			{RST, Vol_Low, 10},
			{RST, Vol_High, 10},
			//{PDN, Vol_High, 0},
			{SensorMCLK, Vol_High, 10},
		},
	},
#endif
//-bug584789, liuxingyu.wt, ADD, 2020/12/13, add hi556 gc5035c bringup
//+bug584789, liudijin.wt, ADD, 2021/01/11, add 3 gong wide camera sc500cs bringup
#if defined(W1SC500CSWIDELY_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1SC500CSWIDELY_MIPI_RAW,
		{
			//{PDN, Vol_Low, 0},
			{DOVDD, Vol_1800, 1},
			{DVDD_1V2, Vol_Low, 1},
			{DVDD_1V1, Vol_High, 1},
			{DVDD2, Vol_High, 1},
			{DVDD, Vol_1200, 1},
			{AVDD, Vol_2800, 1},
			{RST, Vol_Low, 10},
			{RST, Vol_High, 1},
			//{PDN, Vol_High, 0},
			{SensorMCLK, Vol_High, 1},
		},
	},
#endif
//-bug584789, liudijin.wt, ADD, 2021/01/11, add 3 gong wide camera sc500cs bringup
//-bug710560 , zhanghao2.wt, ADD, 2021/12/28, add wide sensor hi556 gc5035c sc500cs bringup

//-bug604664 chenbocheng.wt, add, 2021/01/13, distinguish depth camera params for dualcam
//-bug584789,zhanghengyuan.wt,MODIFY,2020/12/17,depth c2515 bf2253 gc02m1b bringup

//+bug604664 liudijin.wt, add, 2021/04/16, distinguish depth camera params for ov64b40 dualcam
#if defined(W1BF2253DEPLH64_MIPI_RAW)
	{
		SENSOR_DRVNAME_W1BF2253DEPLH64_MIPI_RAW,
		{
			{RST, Vol_Low, 1,Vol_Low},
			{DOVDD, Vol_1800, 1,Vol_Low},
			{AVDD, Vol_Low, 1,Vol_Low},
			{SensorMCLK, Vol_High, 1,Vol_Low},
			{AVDD, Vol_2800, 1,Vol_2800},
			{RST, Vol_High, 1,Vol_Low},
			{RST, Vol_Low, 1,Vol_Low},
		},
	},
#endif
#if defined(W1C2515DEPSJ64_MIPI_MONO)
	{
		SENSOR_DRVNAME_W1C2515DEPSJ64_MIPI_MONO,
		{
			{RST, Vol_High, 1,Vol_High},
			{DOVDD, Vol_1800, 20,Vol_Low},
			{AVDD, Vol_2800, 10,Vol_Low},
			{RST, Vol_Low, 10,Vol_High},
			{SensorMCLK, Vol_High, 10,Vol_Low},
		},
	},
#endif
//-bug604664 liudijin.wt, add, 2021/04/16, distinguish depth camera params for ov64b40 dualcam

#if 0
#if defined(IMX766_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX766_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 3},
#ifdef CONFIG_REGULATOR_RT5133
			{AVDD1, Vol_1800, 0},
#endif
			{AFVDD, Vol_2800, 3},
			{DVDD, Vol_1100, 4},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 6},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(S5KJD1_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5KJD1_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DVDD, Vol_1100, 0},
			{AVDD, Vol_2800, 0},
			{AFVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{PDN, Vol_High, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(S5KJN1_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5KJN1_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DVDD, Vol_1100, 0},
			{AVDD, Vol_2800, 0},
			{AFVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{PDN, Vol_High, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(IMX586_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX586_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 0},
#ifdef CONFIG_REGULATOR_RT5133
			{AVDD1, Vol_1800, 0},
#endif
		//	{AFVDD, Vol_2800, 0},
			{DVDD, Vol_1100, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 3}
		},
	},
#endif
#if defined(OV48B_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV48B_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 5},
			//{AFVDD, Vol_2800, 2},
			{RST, Vol_High, 5},
		},
	},
#endif
#if defined(S5K3P9SP_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3P9SP_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DVDD, Vol_1100, 1},
			{AVDD, Vol_2800, 1},
			{DOVDD, Vol_1800, 0},
			{SensorMCLK, Vol_High, 0},
			//{AFVDD, Vol_2800, 5},
			{RST, Vol_High, 2},
		},
	},
#endif
#if defined(IMX319_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX319_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 0},
			{AFVDD, Vol_2800, 0},
			{DVDD, Vol_1100, 0},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(S5K3M5SX_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3M5SX_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DVDD, Vol_1100, 1},
			{AVDD, Vol_2800, 1},
			//{AFVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 1},
			{RST, Vol_High, 2},
			{SensorMCLK, Vol_High, 1}
		},
	},
#endif
#if defined(GC02M0_MIPI_RAW)
	{
		SENSOR_DRVNAME_GC02M0_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(IMX519_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX519_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{AFVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 1}
		},
	},
#endif
#if defined(IMX519DUAL_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX519DUAL_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{AFVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 1}
		},
	},
#endif
#if defined(IMX499_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX499_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1100, 0},
			{AFVDD, Vol_2800, 1},
			{SensorMCLK, Vol_High, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 10}
		},
	},
#endif
#if defined(IMX481_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX481_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
#ifdef CONFIG_REGULATOR_RT5133
			//To trigger ex-LDO output 2.8V
			{AVDD, Vol_1800, 0},
#else
			// PMIC output 2.8V
			{AVDD, Vol_2800, 0},
#endif
			{DOVDD, Vol_1800, 0},
#ifdef CONFIG_REGULATOR_RT5133
			//To trigger ex-LDO output 1.1V
			{DVDD, Vol_1800, 0},
#else
			//PMIC output 1.1V
			{DVDD, Vol_1100, 0},
#endif
//			{AFVDD, Vol_2800, 1},
			{SensorMCLK, Vol_High, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 10}
		},
	},
#endif
#if defined(IMX576_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX576_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1100, 1}, /*data sheet 1050*/
			{SensorMCLK, Vol_High, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 8}
		},
	},
#endif
#if defined(IMX350_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX350_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1200, 5},
			{SensorMCLK, Vol_High, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(IMX398_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX398_MIPI_RAW,
		{
			{SensorMCLK, Vol_Low, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1100, 0},
			{AFVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 1},
		},
	},
#endif
#if defined(OV23850_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV23850_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 2},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 5},
		},
	},
#endif
#if defined(OV16885_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV16885_MIPI_RAW,
		{
			{PDN, Vol_Low, 1},
			{RST, Vol_Low, 1},
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 1},
			{DVDD, Vol_1200, 5},
			{PDN, Vol_High, 2},
			{RST, Vol_High, 2},
		},
	},
#endif
#if defined(OV05A20_MIPI_RAW)
		{
			SENSOR_DRVNAME_OV05A20_MIPI_RAW,
			{
				{SensorMCLK, Vol_High, 1},
				{RST, Vol_Low, 1},
				{AVDD, Vol_2800, 10},
				{DOVDD, Vol_1800, 5},
				{DVDD, Vol_1200, 5},
				{RST, Vol_High, 15}
			},
		},
#endif

#if defined(IMX386_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX386_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1100, 0},
			{DOVDD, Vol_1800, 1},
			{AFVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 2},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 10},
		},
	},
#endif
#if defined(IMX386_MIPI_MONO)
	{
		SENSOR_DRVNAME_IMX386_MIPI_MONO,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1100, 0},
			{DOVDD, Vol_1800, 1},
			{AFVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 2},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 10},
		},
	},
#endif
#if defined(IMX376_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX376_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 1},
			{DOVDD, Vol_1800, 1},
			{DVDD, Vol_1200, 5},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(IMX338_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX338_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 1},
			{AVDD, Vol_2500, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1100, 0},
			{AFVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(S5K2LQSX_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K2LQSX_MIPI_RAW,
		{
			{PDN, Vol_Low, 1},
			{RST, Vol_Low, 1},
			{SensorMCLK, Vol_High, 4},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1000, 1},
			{DOVDD, Vol_1800, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 0},
		},
	},
#endif
#if defined(S5K4H7_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K4H7_MIPI_RAW,
		{
			{PDN, Vol_Low, 1},
			{RST, Vol_Low, 1},
			{SensorMCLK, Vol_High, 4},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1000, 1},
			{DOVDD, Vol_1800, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 0},
		},
	},
#endif
#if defined(S5K4E6_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K4E6_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2900, 0},
			{DVDD, Vol_1200, 2},
			{AFVDD, Vol_2800, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K2T7SP_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K2T7SP_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1000, 0},
			{SensorMCLK, Vol_High, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 2},
		},
	},
#endif
#if defined(S5K3P8SP_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3P8SP_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1000, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 4},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0},
		},
	},
#endif
#if defined(S5K3P8SX_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3P8SX_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{SensorMCLK, Vol_High, 1},
			{DVDD, Vol_1000, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 2},
		},
	},
#endif
#if defined(S5K3M2_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3M2_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 4},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K3P3SX_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3P3SX_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 4},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K5E2YA_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K5E2YA_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 4},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K4ECGX_MIPI_YUV)
	{
		SENSOR_DRVNAME_S5K4ECGX_MIPI_YUV,
		{
			{DVDD, Vol_1200, 1},
			{AVDD, Vol_2800, 1},
			{DOVDD, Vol_1800, 1},
			{AFVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(OV16880_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV16880_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 1},
			{DVDD, Vol_1200, 5},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(S5K2P7_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K2P7_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 1},
			{DVDD, Vol_1000, 1},
			{DOVDD, Vol_1800, 1},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_Low, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0},
		},
	},
#endif
#if defined(S5K2P8_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K2P8_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 4},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 1},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(IMX258_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX258_MIPI_RAW,
		{
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AFVDD, Vol_2800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 1},
			{SensorMCLK, Vol_High, 0},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(IMX258_MIPI_MONO)
	{
		SENSOR_DRVNAME_IMX258_MIPI_MONO,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(IMX377_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX377_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(OV8858_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV8858_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 1},
			{DVDD, Vol_1200, 5},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(OV8856_MIPI_RAW)
	{SENSOR_DRVNAME_OV8856_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 2},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 5},
		},
	},
#endif
#if defined(S5K2X8_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K2X8_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(IMX214_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX214_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1000, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 1}
		},
	},
#endif
#if defined(IMX214_MIPI_MONO)
	{
		SENSOR_DRVNAME_IMX214_MIPI_MONO,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1000, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 1}
		},
	},
#endif
#if defined(IMX230_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX230_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 10},
			{DOVDD, Vol_1800, 10},
			{DVDD, Vol_1200, 10},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5KGM2_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5KGM2_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AFVDD, Vol_2800, 5},
			{DOVDD, Vol_High, 1},
			{AVDD, Vol_High, 1},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K3L6_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3L6_MIPI_RAW,
		{
			{RST, Vol_Low, 0},
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_High, 0},
			{AVDD, Vol_High, 0},
			{AFVDD, Vol_2800, 5},
			{RST, Vol_High, 1},
		},
	},
#endif
#if defined(S5K3L8_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3L8_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K4HAYX_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K4HAYX_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_High, 1},
			{DOVDD, Vol_High, 1},
			{AFVDD, Vol_2800, 5},
			{SensorMCLK, Vol_High, 0},
			{RST, Vol_High, 1}
		},
	},
#endif
#if defined(IMX362_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX362_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 10},
			{DOVDD, Vol_1800, 10},
			{DVDD, Vol_1200, 10},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K2L7_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K2L7_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1000, 0},
			{AFVDD, Vol_2800, 3},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(IMX318_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX318_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{AVDD, Vol_2800, 0},
			{DOVDD, Vol_1800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 5},
			{SensorMCLK, Vol_High, 5},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(OV8865_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV8865_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 5},
			{RST, Vol_Low, 5},
			{DOVDD, Vol_1800, 5},
			{AVDD, Vol_2800, 5},
			{DVDD, Vol_1200, 5},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_High, 5},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(IMX219_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX219_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 10},
			{DOVDD, Vol_1800, 10},
			{DVDD, Vol_1000, 10},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_Low, 0},
			{PDN, Vol_High, 0},
			{RST, Vol_Low, 0},
			{RST, Vol_High, 0}
		},
	},
#endif
#if defined(S5K3M3_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K3M3_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1000, 0},
			{AFVDD, Vol_2800, 1},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(OV5670_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV5670_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 5},
			{RST, Vol_Low, 5},
			{DOVDD, Vol_1800, 5},
			{AVDD, Vol_2800, 5},
			{DVDD, Vol_1200, 5},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_High, 5},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(OV5670_MIPI_RAW_2)
	{
		SENSOR_DRVNAME_OV5670_MIPI_RAW_2,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 5},
			{RST, Vol_Low, 5},
			{DOVDD, Vol_1800, 5},
			{AVDD, Vol_2800, 5},
			{DVDD, Vol_1200, 5},
			{AFVDD, Vol_2800, 5},
			{PDN, Vol_High, 5},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(OV2281_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV2281_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 0},
			{RST, Vol_Low, 10},
			{RST, Vol_High, 5},
			{PDN, Vol_Low, 5},
			{PDN, Vol_High, 5},
		},
	},
#endif
#if defined(OV20880_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV20880_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 1},
			{DOVDD, Vol_1800, 1},
			{DVDD, Vol_1100, 1},
			{RST, Vol_High, 5}
		},
	},
#endif
#if defined(OV5645_MIPI_YUV)
	{
		SENSOR_DRVNAME_OV5645_MIPI_YUV,
		{
			{SensorMCLK, Vol_High, 0},
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 0},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 5},
			{PDN, Vol_High, 1},
			{RST, Vol_High, 10}
		},
	},
#endif
#if defined(S5K5E9_MIPI_RAW)
	{
		SENSOR_DRVNAME_S5K5E9_MIPI_RAW,
		{
			{PDN, Vol_Low, 0},
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{AFVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 2},
			{PDN, Vol_High, 0},
			{RST, Vol_High, 10}
		},
	},
#endif
#if defined(S5KGD1SP_MIPI_RAW)
		{
			SENSOR_DRVNAME_S5KGD1SP_MIPI_RAW,
			{
				{RST, Vol_Low, 1},
				{AVDD, Vol_2800, 0},
				{DVDD, Vol_1100, 0},
				{DOVDD, Vol_1800, 1},
				{SensorMCLK, Vol_High, 1},
				{RST, Vol_High, 2}
			},
		},
#endif
#if defined(HI846_MIPI_RAW)
		{
			SENSOR_DRVNAME_HI846_MIPI_RAW,
			{
				{RST, Vol_Low, 1},
				{AVDD, Vol_2800, 0},
				{DVDD, Vol_1200, 0},
				{DOVDD, Vol_1800, 1},
				{SensorMCLK, Vol_High, 1},
				{RST, Vol_High, 2}
			},
		},
#endif
#if defined(GC02M0_MIPI_RAW)
		{
			SENSOR_DRVNAME_GC02M0_MIPI_RAW,
			{
				{RST, Vol_Low, 1},
				{AVDD, Vol_2800, 0},
				{DVDD, Vol_1200, 0},
				{DOVDD, Vol_1800, 1},
				{SensorMCLK, Vol_High, 1},
				{RST, Vol_High, 2}
			},
		},
#endif
#if defined(GC02M1_MIPI_RAW)
	{
		SENSOR_DRVNAME_GC02M1_MIPI_RAW,
		{
			{AVDD, Vol_Low, 0},
			{RST, Vol_Low, 1},
			{DOVDD, Vol_High, 0},
			{AVDD, Vol_High, 1},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(OV02A10_MIPI_MONO)
		{
			SENSOR_DRVNAME_OV02A10_MIPI_MONO,
			{
				{RST, Vol_High, 1},
				{AVDD, Vol_2800, 0},
			/*main3 has no dvdd, compatible with sub2*/
				{DVDD, Vol_1200, 0},
				{DOVDD, Vol_1800, 0},
				{SensorMCLK, Vol_High, 5},
				{RST, Vol_Low, 9}
			},
		},
#endif
#if defined(IMX686_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX686_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_2900, 0},
		/*in alph.dts file, pin avdd controls two gpio pins*/
			/*{AVDD_1, Vol_1800, 0},*/
			{DVDD, Vol_1100, 0},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 1}
		},
	},
#endif
#if defined(IMX616_MIPI_RAW)
		{
			SENSOR_DRVNAME_IMX616_MIPI_RAW,
			{
				{RST, Vol_Low, 1},
				{AVDD, Vol_2900, 0},
				{DVDD, Vol_1100, 0},
				{DOVDD, Vol_1800, 1},
				{SensorMCLK, Vol_High, 1},
				{RST, Vol_High, 2}
			},
		},
#endif
#if defined(GC5035_MIPI_RAW)
	{
		SENSOR_DRVNAME_GC5035_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_High, 1},
			{AVDD, Vol_High, 1},
			{DVDD, Vol_High, 1},
			{SensorMCLK, Vol_High, 0},
			{RST, Vol_High, 0},
		},
	},
#endif
#if defined(IMX355_MIPI_RAW)
	{
		SENSOR_DRVNAME_IMX355_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 1},
			{DVDD, Vol_1200, 1},
			{AVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(OV13B10_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV13B10_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{RST, Vol_High, 5},
			{SensorMCLK, Vol_High, 1},
		},
	},
#endif
#if defined(OV48C_MIPI_RAW)
		{
			SENSOR_DRVNAME_OV48C_MIPI_RAW,
			{
				{RST, Vol_Low, 1},
				{SensorMCLK, Vol_High, 0},
				{DOVDD, Vol_1800, 0},
				{AVDD, Vol_2800, 0},
				{DVDD, Vol_1200, 5},
				{RST, Vol_High, 5},
			},
		},
#endif
#if defined(SR846D_MIPI_RAW)
	{
		SENSOR_DRVNAME_SR846D_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_High, 1},
			{AVDD, Vol_High, 1},
			{SensorMCLK, Vol_High, 0},
			{RST, Vol_High, 0},
		},
	},
#endif
#if defined(OV16A10_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV16A10_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{AVDD, Vol_2800, 0},
			{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2},
		},
	},
#endif
#if defined(GC8054_MIPI_RAW)
	{
		SENSOR_DRVNAME_GC8054_MIPI_RAW,
		{
			{SensorMCLK, Vol_High, 0},
			{RST, Vol_Low,  1},
			{DOVDD, Vol_1800, 1},
			{DVDD, Vol_1200, 1},
			{AVDD, Vol_2800, 1},
			{RST, Vol_High, 1},
			//{AFVDD, Vol_Low, 5}
		},
	},
#endif
#if defined(GC02M0B_MIPI_MONO)
	{
		SENSOR_DRVNAME_GC02M0B_MIPI_MONO,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(GC02M1B_MIPI_MONO)
	{
		SENSOR_DRVNAME_GC02M1B_MIPI_MONO,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 0},
			{AVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(GC02M0B_MIPI_MONO1)
	{
		SENSOR_DRVNAME_GC02M0B_MIPI_MONO1,
		{
			{RST, Vol_Low, 1},
			//{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(GC02M0B_MIPI_MONO2)
	{
		SENSOR_DRVNAME_GC02M0B_MIPI_MONO2,
		{
			{RST, Vol_Low, 1},
			//{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(GC02K0B_MIPI_MONO)
	{
		SENSOR_DRVNAME_GC02K0B_MIPI_MONO,
		{
			{RST, Vol_Low, 1},
			//{DVDD, Vol_1200, 0},
			{DOVDD, Vol_1800, 1},
			{AVDD, Vol_2800, 0},
			{SensorMCLK, Vol_High, 1},
			{RST, Vol_High, 2}
		},
	},
#endif
#if defined(OV02B10_MIPI_RAW)
	{
		SENSOR_DRVNAME_OV02B10_MIPI_RAW,
		{
			{RST, Vol_Low, 1},
			{DOVDD, Vol_1800, 1},
			{SensorMCLK, Vol_High, 0},
			{AVDD, Vol_2800, 9},
			{RST, Vol_High, 1}
		},
	},
#endif
#endif
	/* add new sensor before this line */
	{NULL,},
};

