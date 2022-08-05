/*
 *  sound/soc/codecs/mt6660-regmap.c
 *  Mediatek Regmap Source for Richtek MT6660 SPKAMP IC
 *
 *  Copyright (C) 2018 Mediatek Inc.
 *  cy_huang <cy_huang@richtek.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/err.h>

#include "mt6660.h"

#ifdef CONFIG_RT_REGMAP
#define MT6660_REG_DECL(_addr, _reg_type, _mask_...)	\
static unsigned char rt_writable_mask_##_addr[MT6660_GET_SIZE(_addr)] = _mask_;\
static struct rt_register rt_register_##_addr = {\
	.addr = MT6660_GET_ADDR(_addr),\
	.size = MT6660_GET_SIZE(_addr),\
	.reg_type = _reg_type,\
	.wbit_mask = rt_writable_mask_##_addr,\
}

MT6660_REG_DECL(MT6660_REG_DEVID, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_SERIAL_DATA_STATUS, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_BLOCK_CLK_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SYSTEM_CTRL, RT_WBITS_WR_ONCE, {0x8f});
MT6660_REG_DECL(MT6660_REG_IRQ_EN, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_IRQ_STATUS1, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_CRC_CHECK, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_ADDA_CLOCK, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_I2C_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_IRQ_STATUS2, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_SERIAL_CFG1, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SERIAL_CFG2, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_DATAO_SEL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TDM_CFG1, RT_WBITS_WR_ONCE, {0xdf});
MT6660_REG_DECL(MT6660_REG_TDM_CFG2, RT_WBITS_WR_ONCE, {0x1f, 0x9f});
MT6660_REG_DECL(MT6660_REG_TDM_CFG3, RT_WBITS_WR_ONCE, {0x1f, 0xff});
MT6660_REG_DECL(MT6660_REG_HPF_CTRL, RT_WBITS_WR_ONCE, {0x07});
MT6660_REG_DECL(MT6660_REG_HPF0_COEF, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_HPF1_COEF, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_HPF2_COEF, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_GISENS, RT_WBITS_WR_ONCE, {0x01, 0xff});
MT6660_REG_DECL(MT6660_REG_GVSENS, RT_WBITS_WR_ONCE, {0x1f});
MT6660_REG_DECL(MT6660_REG_PATH_BYPASS, RT_WBITS_WR_ONCE, {0xff});
MT6660_REG_DECL(MT6660_REG_WDT_CTRL, RT_WBITS_WR_ONCE, {0xb3});
MT6660_REG_DECL(MT6660_REG_HCLIP_CTRL, RT_WBITS_WR_ONCE, {0x01, 0xff});
MT6660_REG_DECL(MT6660_REG_RAMP_CTRL, RT_WBITS_WR_ONCE, {0x07});
MT6660_REG_DECL(MT6660_REG_VOL_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SPS_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SG_CFG, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SG_VOMIN, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SIGMAX, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SPSTH, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_M60, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_M28, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_P4, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_P36, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_P68, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_P100, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_TC_GAIN_P132, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_CALI_T0, RT_WBITS_WR_ONCE, {0x07});
MT6660_REG_DECL(MT6660_REG_BST_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_BST_L1, RT_WBITS_WR_ONCE, {0x0f, 0xff});
MT6660_REG_DECL(MT6660_REG_BST_L2, RT_WBITS_WR_ONCE, {0x0f, 0xff});
MT6660_REG_DECL(MT6660_REG_BST_L3, RT_WBITS_WR_ONCE, {0x0f, 0xff});
MT6660_REG_DECL(MT6660_REG_PSM_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_CCMAX, RT_WBITS_WR_ONCE, {0x7f});
MT6660_REG_DECL(MT6660_REG_PROTECTION_CFG, RT_WBITS_WR_ONCE, {0x7f});
MT6660_REG_DECL(MT6660_REG_VPTAT, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_VBAT, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_BST_CFG1, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_BST_CFG2, RT_WBITS_WR_ONCE, {0x07, 0xff});
MT6660_REG_DECL(MT6660_REG_BST_CFG3, RT_WBITS_WR_ONCE, {0x7f});
MT6660_REG_DECL(MT6660_REG_DA_GAIN, RT_WBITS_WR_ONCE, {0x07, 0xff});
MT6660_REG_DECL(MT6660_REG_FF_GAIN, RT_WBITS_WR_ONCE, {0x03, 0xff});
MT6660_REG_DECL(MT6660_REG_RLD_COEF1, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_RLD_COEF2, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_AUDIO_IN2_SEL, RT_WBITS_WR_ONCE, {0x1f});
MT6660_REG_DECL(MT6660_REG_SIG_GAIN, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_IDAC1_TM, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_IDAC2_TM, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_IDAC3_TM, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_GVPTAT, RT_WBITS_WR_ONCE, {0x1, 0xff});
MT6660_REG_DECL(MT6660_REG_IPEAK_LOW, RT_WBITS_WR_ONCE, {0x3f});
MT6660_REG_DECL(MT6660_REG_GPWM_LV, RT_WBITS_WR_ONCE, {0x3f});
MT6660_REG_DECL(MT6660_REG_VBT_SENSE, RT_WBITS_WR_ONCE, {0x3f});
MT6660_REG_DECL(MT6660_REG_VPTAT_ADC_CODE, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_VBAT_ADC_CODE, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_SUB_ADC_OFFSET, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_IDAC_TM_CTRL, RT_WBITS_WR_ONCE, {0xf3});
MT6660_REG_DECL(MT6660_REG_IDAC_TEST_CODE, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_IDAC_MONOTONIC, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_PLL_CFG1, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_PLL_CFG2, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_PLL_CFG3, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_PLL_CFG4, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_PLL_RATIO, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_DRE_CTRL, RT_WBITS_WR_ONCE, {0x1f});
MT6660_REG_DECL(MT6660_REG_DRE_THDMODE, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_DRE_TIMING, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_DRE_CORASE, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_PWM_CTRL, RT_WBITS_WR_ONCE, {0x3f});
MT6660_REG_DECL(MT6660_REG_DC_PROTECT_CTRL, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_DITHER_CTRL, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_ADC_USB_MODE, RT_WBITS_WR_ONCE, {0x03});
MT6660_REG_DECL(MT6660_REG_EFUSE_EN, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_EFUSE_CTRL, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_EFUSE_MAP, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_INTERNAL_CFG, RT_WBITS_WR_ONCE, {0xfe});
MT6660_REG_DECL(MT6660_REG_DC_ADJ, RT_NORMAL_WR_ONCE, {});
MT6660_REG_DECL(MT6660_REG_ZC_CFG, RT_WBITS_WR_ONCE, {0x7f});
MT6660_REG_DECL(MT6660_REG_BG_CFG, RT_WBITS_WR_ONCE, {0xdf});
MT6660_REG_DECL(MT6660_REG_TM_EN, RT_WBITS_WR_ONCE, {0x01});
MT6660_REG_DECL(MT6660_REG_RAM_BIST_TST, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_SCAN_MODE, RT_WBITS_WR_ONCE, {0x01});
MT6660_REG_DECL(MT6660_REG_DBG_OUT_SEL1, RT_WBITS_WR_ONCE, {0x3f});
MT6660_REG_DECL(MT6660_REG_DBG_OUT_SEL2, RT_WBITS_WR_ONCE, {0x1f, 0x1f});
MT6660_REG_DECL(MT6660_REG_RESV0, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV1, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV2, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV3, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV4, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV5, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV6, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV7, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV8, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV9, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV10, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV11, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV12, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV13, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV14, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV15, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV16, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV17, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV18, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV19, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV20, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV21, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV22, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV23, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV24, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV25, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV26, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV27, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV28, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV29, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV30, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV31, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV32, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV33, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV34, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV35, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV36, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV37, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV38, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV39, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV40, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV41, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV42, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV43, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV44, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV45, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV46, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV47, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV48, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV49, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV50, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV51, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV52, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV53, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV54, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV55, RT_VOLATILE, {});
MT6660_REG_DECL(MT6660_REG_RESV56, RT_VOLATILE, {});

static const rt_register_map_t mt6660_regmap[] = {
	RT_REG(MT6660_REG_DEVID),
	RT_REG(MT6660_REG_SERIAL_DATA_STATUS),
	RT_REG(MT6660_REG_BLOCK_CLK_CTRL),
	RT_REG(MT6660_REG_SYSTEM_CTRL),
	RT_REG(MT6660_REG_IRQ_EN),
	RT_REG(MT6660_REG_IRQ_STATUS1),
	RT_REG(MT6660_REG_CRC_CHECK),
	RT_REG(MT6660_REG_ADDA_CLOCK),
	RT_REG(MT6660_REG_I2C_CTRL),
	RT_REG(MT6660_REG_IRQ_STATUS2),
	RT_REG(MT6660_REG_SERIAL_CFG1),
	RT_REG(MT6660_REG_SERIAL_CFG2),
	RT_REG(MT6660_REG_DATAO_SEL),
	RT_REG(MT6660_REG_TDM_CFG1),
	RT_REG(MT6660_REG_TDM_CFG2),
	RT_REG(MT6660_REG_TDM_CFG3),
	RT_REG(MT6660_REG_HPF_CTRL),
	RT_REG(MT6660_REG_HPF0_COEF),
	RT_REG(MT6660_REG_HPF1_COEF),
	RT_REG(MT6660_REG_HPF2_COEF),
	RT_REG(MT6660_REG_GISENS),
	RT_REG(MT6660_REG_GVSENS),
	RT_REG(MT6660_REG_PATH_BYPASS),
	RT_REG(MT6660_REG_WDT_CTRL),
	RT_REG(MT6660_REG_HCLIP_CTRL),
	RT_REG(MT6660_REG_RAMP_CTRL),
	RT_REG(MT6660_REG_VOL_CTRL),
	RT_REG(MT6660_REG_SPS_CTRL),
	RT_REG(MT6660_REG_SG_CFG),
	RT_REG(MT6660_REG_SG_VOMIN),
	RT_REG(MT6660_REG_SIGMAX),
	RT_REG(MT6660_REG_SPSTH),
	RT_REG(MT6660_REG_TC_GAIN_M60),
	RT_REG(MT6660_REG_TC_GAIN_M28),
	RT_REG(MT6660_REG_TC_GAIN_P4),
	RT_REG(MT6660_REG_TC_GAIN_P36),
	RT_REG(MT6660_REG_TC_GAIN_P68),
	RT_REG(MT6660_REG_TC_GAIN_P100),
	RT_REG(MT6660_REG_TC_GAIN_P132),
	RT_REG(MT6660_REG_CALI_T0),
	RT_REG(MT6660_REG_BST_CTRL),
	RT_REG(MT6660_REG_BST_L1),
	RT_REG(MT6660_REG_BST_L2),
	RT_REG(MT6660_REG_BST_L3),
	RT_REG(MT6660_REG_PSM_CTRL),
	RT_REG(MT6660_REG_CCMAX),
	RT_REG(MT6660_REG_PROTECTION_CFG),
	RT_REG(MT6660_REG_VPTAT),
	RT_REG(MT6660_REG_VBAT),
	RT_REG(MT6660_REG_BST_CFG1),
	RT_REG(MT6660_REG_BST_CFG2),
	RT_REG(MT6660_REG_BST_CFG3),
	RT_REG(MT6660_REG_DA_GAIN),
	RT_REG(MT6660_REG_FF_GAIN),
	RT_REG(MT6660_REG_RLD_COEF1),
	RT_REG(MT6660_REG_RLD_COEF2),
	RT_REG(MT6660_REG_AUDIO_IN2_SEL),
	RT_REG(MT6660_REG_SIG_GAIN),
	RT_REG(MT6660_REG_IDAC1_TM),
	RT_REG(MT6660_REG_IDAC2_TM),
	RT_REG(MT6660_REG_IDAC3_TM),
	RT_REG(MT6660_REG_GVPTAT),
	RT_REG(MT6660_REG_IPEAK_LOW),
	RT_REG(MT6660_REG_GPWM_LV),
	RT_REG(MT6660_REG_VBT_SENSE),
	RT_REG(MT6660_REG_VPTAT_ADC_CODE),
	RT_REG(MT6660_REG_VBAT_ADC_CODE),
	RT_REG(MT6660_REG_SUB_ADC_OFFSET),
	RT_REG(MT6660_REG_IDAC_TM_CTRL),
	RT_REG(MT6660_REG_IDAC_TEST_CODE),
	RT_REG(MT6660_REG_IDAC_MONOTONIC),
	RT_REG(MT6660_REG_PLL_CFG1),
	RT_REG(MT6660_REG_PLL_CFG2),
	RT_REG(MT6660_REG_PLL_CFG3),
	RT_REG(MT6660_REG_PLL_CFG4),
	RT_REG(MT6660_REG_PLL_RATIO),
	RT_REG(MT6660_REG_DRE_CTRL),
	RT_REG(MT6660_REG_DRE_THDMODE),
	RT_REG(MT6660_REG_DRE_TIMING),
	RT_REG(MT6660_REG_DRE_CORASE),
	RT_REG(MT6660_REG_PWM_CTRL),
	RT_REG(MT6660_REG_DC_PROTECT_CTRL),
	RT_REG(MT6660_REG_DITHER_CTRL),
	RT_REG(MT6660_REG_ADC_USB_MODE),
	RT_REG(MT6660_REG_EFUSE_EN),
	RT_REG(MT6660_REG_EFUSE_CTRL),
	RT_REG(MT6660_REG_EFUSE_MAP),
	RT_REG(MT6660_REG_INTERNAL_CFG),
	RT_REG(MT6660_REG_DC_ADJ),
	RT_REG(MT6660_REG_ZC_CFG),
	RT_REG(MT6660_REG_BG_CFG),
	RT_REG(MT6660_REG_TM_EN),
	RT_REG(MT6660_REG_RAM_BIST_TST),
	RT_REG(MT6660_REG_SCAN_MODE),
	RT_REG(MT6660_REG_DBG_OUT_SEL1),
	RT_REG(MT6660_REG_DBG_OUT_SEL2),
	RT_REG(MT6660_REG_RESV0),
	RT_REG(MT6660_REG_RESV1),
	RT_REG(MT6660_REG_RESV2),
	RT_REG(MT6660_REG_RESV3),
	RT_REG(MT6660_REG_RESV4),
	RT_REG(MT6660_REG_RESV5),
	RT_REG(MT6660_REG_RESV6),
	RT_REG(MT6660_REG_RESV7),
	RT_REG(MT6660_REG_RESV8),
	RT_REG(MT6660_REG_RESV9),
	RT_REG(MT6660_REG_RESV10),
	RT_REG(MT6660_REG_RESV11),
	RT_REG(MT6660_REG_RESV12),
	RT_REG(MT6660_REG_RESV13),
	RT_REG(MT6660_REG_RESV14),
	RT_REG(MT6660_REG_RESV15),
	RT_REG(MT6660_REG_RESV16),
	RT_REG(MT6660_REG_RESV17),
	RT_REG(MT6660_REG_RESV18),
	RT_REG(MT6660_REG_RESV19),
	RT_REG(MT6660_REG_RESV20),
	RT_REG(MT6660_REG_RESV21),
	RT_REG(MT6660_REG_RESV22),
	RT_REG(MT6660_REG_RESV23),
	RT_REG(MT6660_REG_RESV24),
	RT_REG(MT6660_REG_RESV25),
	RT_REG(MT6660_REG_RESV26),
	RT_REG(MT6660_REG_RESV27),
	RT_REG(MT6660_REG_RESV28),
	RT_REG(MT6660_REG_RESV29),
	RT_REG(MT6660_REG_RESV30),
	RT_REG(MT6660_REG_RESV31),
	RT_REG(MT6660_REG_RESV32),
	RT_REG(MT6660_REG_RESV33),
	RT_REG(MT6660_REG_RESV34),
	RT_REG(MT6660_REG_RESV35),
	RT_REG(MT6660_REG_RESV36),
	RT_REG(MT6660_REG_RESV37),
	RT_REG(MT6660_REG_RESV38),
	RT_REG(MT6660_REG_RESV39),
	RT_REG(MT6660_REG_RESV40),
	RT_REG(MT6660_REG_RESV41),
	RT_REG(MT6660_REG_RESV42),
	RT_REG(MT6660_REG_RESV43),
	RT_REG(MT6660_REG_RESV44),
	RT_REG(MT6660_REG_RESV45),
	RT_REG(MT6660_REG_RESV46),
	RT_REG(MT6660_REG_RESV47),
	RT_REG(MT6660_REG_RESV48),
	RT_REG(MT6660_REG_RESV49),
	RT_REG(MT6660_REG_RESV50),
	RT_REG(MT6660_REG_RESV51),
	RT_REG(MT6660_REG_RESV52),
	RT_REG(MT6660_REG_RESV53),
	RT_REG(MT6660_REG_RESV54),
	RT_REG(MT6660_REG_RESV55),
	RT_REG(MT6660_REG_RESV56),
};

static struct rt_regmap_properties mt6660_regmap_props = {
	.register_num = ARRAY_SIZE(mt6660_regmap),
	.rm = mt6660_regmap,
	.rt_regmap_mode = RT_MULTI_BYTE | RT_DBG_SPECIAL,
	.aliases = "mt6660",
	.rt_format = RT_BIG_ENDIAN,
};

static int mt6660_regmap_read_device(void *client,
				     u32 addr, int len, void *dst)
{
	return i2c_smbus_read_i2c_block_data(client, addr, len, dst);
}

static int mt6660_regmap_write_device(void *client, u32 addr,
				       int len, const void *src)
{
	return i2c_smbus_write_i2c_block_data(client, addr, len, src);
}

static struct rt_regmap_fops mt6660_regmap_fops = {
	.read_device = mt6660_regmap_read_device,
	.write_device = mt6660_regmap_write_device,
};

int mt6660_regmap_register(struct mt6660_chip *chip)
{
	mt6660_regmap_props.name = kasprintf(GFP_KERNEL,
					     "mt6660.%s", dev_name(chip->dev));
	chip->regmap = rt_regmap_device_register(&mt6660_regmap_props,
						 &mt6660_regmap_fops,
						 chip->dev, chip->i2c, chip);
	return chip->regmap ? 0 : -EINVAL;
}
EXPORT_SYMBOL_GPL(mt6660_regmap_register);

void mt6660_regmap_unregister(struct mt6660_chip *chip)
{
	rt_regmap_device_unregister(chip->regmap);
}
EXPORT_SYMBOL_GPL(mt6660_regmap_unregister);
#else
int mt6660_regmap_register(struct mt6660_chip *chip)
{
	return 0;
}
EXPORT_SYMBOL_GPL(mt6660_regmap_register);

void mt6660_regmap_unregister(struct mt6660_chip *chip)
{
}
EXPORT_SYMBOL_GPL(mt6660_regmap_unregister);
#endif /* CONFIG_RT_REGMAP */
