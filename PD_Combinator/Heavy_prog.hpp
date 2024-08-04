/**
 * Copyright (c) 2024 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_PROG_HPP_
#define _HEAVY_CONTEXT_PROG_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlSystem.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvControlPack.h"
#include "HvControlIf.h"
#include "HvControlUnop.h"
#include "HvSignalTabread.h"
#include "HvSignalTabwrite.h"
#include "HvControlRandom.h"
#include "HvControlDelay.h"
#include "HvSignalLine.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvTable.h"
#include "HvControlSlice.h"
#include "HvControlCast.h"
#include "HvSignalVar.h"

class Heavy_prog : public HeavyContext {

 public:
  Heavy_prog(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_prog();

  const char *getName() override { return "prog"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_heXYxN8M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MapbpzqU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iEB7Zw70_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_G0R4RCyd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_If30ICVi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_IFvR6IYD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_SwdW32HA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_AL6ThBUC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dVYW4J1E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_m5iDwfmb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_RFgF8nPq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_kB20nyEn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_1tbUJh7Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_l1kmoVfo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_I1SnHKSl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FR0jXv2B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Zn2Ww4NH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_w2HhWvr0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_STh7fPrV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yAlIiRIl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_LYLLY3QI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_0QeaWoAm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_liNyaWrE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ue6BUfLl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jSF3oUEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KXXiukDR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pI0oN2SA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A9HTYzSU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OmdzDuE5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_t6RB5d01_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GvJbaW1S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jyxvP1df_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5mhTXtjX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_IHn7XtHj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_OHQnlC3d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_qHe5jBoB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EOhosbCo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_QRhNxTSN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_3g8H1dGZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8jahPP5k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_97aKql6b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qJmq3A2A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Apd5myHM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GNJ5kxuv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hfC9FOBt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sAjFzkJ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GQFAgvT2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_82fXaxZu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4MY4Kbci_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2f15je2v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R98iaeDS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v0g1seBh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q4mNfRIS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CUzKxAfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_54BUPBUO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_dytksA9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_oQ3AoVyy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YG0dTK7C_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Jcitmve9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_gH7P2gSB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RrZN3lm9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_05wAWeAl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_X0PmTlfV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JAxvcist_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JD4vMGWz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jpx9GKo5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cEG88g0p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_kBL0tN88_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_KhE39PBQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_HCyGOWpg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_H0muetNM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_JOgrHrcn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_u2b7yuxf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mVv6vkQ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_98TwF6kr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ghRVlRKA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NXrrjXqi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_M4tGk102_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LxGU8JzW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jBHXkmBI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5BqTkcNq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vbiWorQu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H4xXhZVt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3kJsBIG9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8I8ZJtWK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QZMMXX1p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TbowM1vp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rRZ1v2oU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ii1lfs1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7s9rbV8Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lPeHp7yu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5BGt46ig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6CHhtfCc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FvmqkZon_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eSXtuzBA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_j93npDg0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_FUcaLSo1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lOQYF0m5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rza6pvay_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0LBwFVmM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_88OJv8EM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bjNrth0M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FEWmxEHY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A4X5OKZr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WQtWchEA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eHJfJe2U_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_oephqLrT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W63OBwuP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j6twFruY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Xf2zzCaN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bdF5PqSA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Em5YVYaZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S4DiBeFh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BBEX1yRO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x9Xcy9Ff_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3iI3My7H_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_tK2LQjLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_H7lksc40_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_NICC9tTE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5kHx6kBn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_MIBA5CVh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WICJFvIz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bJ4FlTxI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SGn7bGwD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_kSS8wytf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_VIFTYl72_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1gbaFLF6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Td2Hj8eo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6YuwASNj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_75GH1RVg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yrWdHe5k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MlrzL9io_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qsyuswTy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t049jOq9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PeJzvEUx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RB7i3Jhi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EjxGWFAo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BvB8OqHO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_l5p6IGfz_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_PR0rbQ8B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_WWYFs1z7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_wP8YUfGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BlyaWCE2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jcHUoXYG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gojWkxId_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rS9cbkLw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_0bv8mkcL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YPMCP3aT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mzDU6Vjx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gzEwKqqy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QqlaXAMa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_N5xWBXzM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iUfXwSgH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VweHTFLo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aWgzzCBa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TpgTll92_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dEg6ooCs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_X0WfU9hl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BlJPGVCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o9gzun55_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o6Vvmwf6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FSjX7Xt8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Edv4tPqT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_af9Gd7Q7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b1mBt8zt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Mrw1y38V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R7qUKWAw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JSWkBKyX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zO6CU3Kf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BT1h409M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X0kHkpMw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KosRBI1E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EFKVzN8w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gDssJmht_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tWx0tuKH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_7xoxubrg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UY74B4g5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Hqzqifq9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fSN3tkW7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yRmg1ol5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_C3mSF7Ja_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tWhaXWpb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Z1xg0Q6G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_cJ4HYBtE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_HySFq1WO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_nMWtHVTV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6EVdmcU5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_lgFCxJPL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_E1BMLqLO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_S05IOT4l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5VCYwFXe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9NM8HU6M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_frWLYf4p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MhMke394_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pAc0FkJL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_4iRW0EXG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZrxsLhcf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UHIKflIN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WBzsOJX4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uwTg0iTE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VUYxX0zl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4CzAjRIS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wZEYVwiX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OvDfnyYX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pFN6TTS5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xiCBonYx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oeFXVddX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_501NwKHf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aMpQwYaa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kzHgpyMR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WboneOi1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OhV6eJJe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wy8hzqdF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q5fp44WE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QbgZd3nk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Jc89JRlG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kDRaA5Zd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PFbKJ8b0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_isHSz0FO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_elwZhyM8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PFUEbTUl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OGDBkOh3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_bNR6N8BI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BdgrR5OE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_66kRJ4z3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eHQbCNmu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_47vE0UTe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H1nNaYMh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fM5n5D8X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jRNXoXBR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uOmR58Jx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Ibrt4nId_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MiYna9et_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_YdWY2WHA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_rBpRiJTV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_akZfJ3Rv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_b1OKURPe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Kdo9QnnB_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_ZO2RJk55_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UmgYpJ0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TeIC2Log_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2R0ZGgM6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7GokFokQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jsj9qtF2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DrKOd84k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gjhyfbs5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_DawPIxJp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bx2Wg4C6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XPnotKhZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5JvvvsnF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HsNxiDHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mg7M1I0d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WLliidlz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QZJSRacX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0GqbET2M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yLuPbb3d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hHqN88GG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RIkc2DWs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1BKP6GWs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_smOxw0hW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cS0BcCtM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8OG3PSbp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8xNVoboW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_nZtQmmpM_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_KVEOvBK3;
  SignalLine sLine_Y1BpJ4ki;
  SignalPhasor sPhasor_wxNeD3Ib;
  SignalLine sLine_TT4O0ROg;
  SignalPhasor sPhasor_rZDiezVj;
  SignalPhasor sPhasor_b0l9SnWC;
  SignalLine sLine_9RoNhLH8;
  SignalPhasor sPhasor_FPSv2XpK;
  SignalPhasor sPhasor_vgRCcZ58;
  SignalPhasor sPhasor_u3TaaAiL;
  SignalLine sLine_aionPTXp;
  SignalPhasor sPhasor_esoeKcyU;
  SignalPhasor sPhasor_ZZbQSHmn;
  SignalLine sLine_l8OOe6K7;
  SignalPhasor sPhasor_jaAH7EqE;
  SignalLine sLine_OBT1ENbl;
  SignalTabhead sTabhead_8e94KVJt;
  SignalTabread sTabread_4stW0jBp;
  SignalTabread sTabread_RdmQiNtP;
  SignalLine sLine_zsq0816i;
  SignalLine sLine_pH3dBD1t;
  SignalTabhead sTabhead_M701P5zx;
  SignalTabread sTabread_RmAx14Rt;
  SignalTabread sTabread_IKc9o2cl;
  SignalLine sLine_TKDFRDBs;
  SignalTabwrite sTabwrite_QkkdDpK6;
  SignalTabwrite sTabwrite_5KLxyN5r;
  SignalLine sLine_EXIjPF3w;
  ControlVar cVar_heXYxN8M;
  ControlVar cVar_MapbpzqU;
  ControlBinop cBinop_iEB7Zw70;
  ControlVar cVar_G0R4RCyd;
  ControlBinop cBinop_IFvR6IYD;
  ControlRandom cRandom_AL6ThBUC;
  ControlSlice cSlice_dVYW4J1E;
  ControlBinop cBinop_RFgF8nPq;
  ControlRandom cRandom_1tbUJh7Z;
  ControlSlice cSlice_l1kmoVfo;
  ControlPack cPack_I1SnHKSl;
  ControlSlice cSlice_FR0jXv2B;
  ControlSlice cSlice_Zn2Ww4NH;
  ControlSlice cSlice_w2HhWvr0;
  ControlSlice cSlice_STh7fPrV;
  ControlSlice cSlice_yAlIiRIl;
  SignalVarf sVarf_vBpWzoU6;
  ControlBinop cBinop_A9HTYzSU;
  ControlBinop cBinop_OmdzDuE5;
  SignalVarf sVarf_pyZZfptH;
  SignalVarf sVarf_8AJMP40K;
  ControlBinop cBinop_IHn7XtHj;
  ControlRandom cRandom_qHe5jBoB;
  ControlSlice cSlice_EOhosbCo;
  ControlPack cPack_QRhNxTSN;
  ControlPack cPack_3g8H1dGZ;
  ControlVar cVar_qJmq3A2A;
  ControlBinop cBinop_GNJ5kxuv;
  ControlBinop cBinop_sAjFzkJ6;
  SignalVarf sVarf_kFbBqFl8;
  SignalVarf sVarf_uEmZ2LaN;
  SignalVarf sVarf_ozsTztvy;
  ControlVar cVar_4MY4Kbci;
  ControlBinop cBinop_R98iaeDS;
  ControlBinop cBinop_q4mNfRIS;
  SignalVarf sVarf_rPko31Mz;
  SignalVarf sVarf_X9HwCqHk;
  SignalVarf sVarf_DTLOL1Cv;
  ControlDelay cDelay_dytksA9P;
  ControlDelay cDelay_oQ3AoVyy;
  ControlBinop cBinop_Jcitmve9;
  HvTable hTable_gH7P2gSB;
  ControlBinop cBinop_05wAWeAl;
  ControlDelay cDelay_KhE39PBQ;
  ControlDelay cDelay_HCyGOWpg;
  ControlBinop cBinop_JOgrHrcn;
  HvTable hTable_u2b7yuxf;
  ControlBinop cBinop_98TwF6kr;
  ControlBinop cBinop_jBHXkmBI;
  ControlBinop cBinop_5BqTkcNq;
  ControlBinop cBinop_vbiWorQu;
  ControlBinop cBinop_H4xXhZVt;
  ControlBinop cBinop_3kJsBIG9;
  ControlBinop cBinop_8I8ZJtWK;
  ControlBinop cBinop_rRZ1v2oU;
  ControlBinop cBinop_ii1lfs1P;
  ControlVar cVar_eSXtuzBA;
  ControlDelay cDelay_FUcaLSo1;
  ControlVar cVar_88OJv8EM;
  ControlBinop cBinop_FEWmxEHY;
  ControlBinop cBinop_A4X5OKZr;
  ControlBinop cBinop_WQtWchEA;
  ControlDelay cDelay_oephqLrT;
  ControlVar cVar_bdF5PqSA;
  ControlBinop cBinop_S4DiBeFh;
  ControlBinop cBinop_BBEX1yRO;
  ControlBinop cBinop_x9Xcy9Ff;
  ControlBinop cBinop_tK2LQjLH;
  ControlRandom cRandom_NICC9tTE;
  ControlSlice cSlice_5kHx6kBn;
  ControlPack cPack_MIBA5CVh;
  ControlSlice cSlice_WICJFvIz;
  ControlSlice cSlice_bJ4FlTxI;
  ControlSlice cSlice_SGn7bGwD;
  ControlSlice cSlice_kSS8wytf;
  ControlSlice cSlice_VIFTYl72;
  SignalVarf sVarf_ew5F5ivU;
  ControlBinop cBinop_t049jOq9;
  ControlBinop cBinop_PeJzvEUx;
  SignalVarf sVarf_0zZS6kDo;
  SignalVarf sVarf_76qbg8Uv;
  ControlBinop cBinop_PR0rbQ8B;
  ControlRandom cRandom_wP8YUfGM;
  ControlSlice cSlice_BlyaWCE2;
  ControlVar cVar_jcHUoXYG;
  ControlVar cVar_gojWkxId;
  ControlVar cVar_gzEwKqqy;
  ControlVar cVar_QqlaXAMa;
  ControlVar cVar_N5xWBXzM;
  ControlVar cVar_iUfXwSgH;
  ControlBinop cBinop_TpgTll92;
  SignalVarf sVarf_YIQSgsWy;
  ControlBinop cBinop_af9Gd7Q7;
  ControlBinop cBinop_b1mBt8zt;
  ControlBinop cBinop_Mrw1y38V;
  ControlBinop cBinop_R7qUKWAw;
  SignalVarf sVarf_O839pqGm;
  ControlBinop cBinop_zO6CU3Kf;
  ControlBinop cBinop_BT1h409M;
  ControlBinop cBinop_X0kHkpMw;
  ControlBinop cBinop_KosRBI1E;
  ControlVar cVar_EFKVzN8w;
  ControlVar cVar_gDssJmht;
  ControlVar cVar_tWx0tuKH;
  ControlPack cPack_7xoxubrg;
  ControlVar cVar_UY74B4g5;
  ControlVar cVar_Hqzqifq9;
  ControlSlice cSlice_fSN3tkW7;
  ControlSlice cSlice_yRmg1ol5;
  ControlSlice cSlice_C3mSF7Ja;
  ControlSlice cSlice_Z1xg0Q6G;
  ControlDelay cDelay_cJ4HYBtE;
  ControlDelay cDelay_HySFq1WO;
  ControlIf cIf_nMWtHVTV;
  ControlSlice cSlice_lgFCxJPL;
  ControlPack cPack_4iRW0EXG;
  SignalVarf sVarf_BdMrbB3H;
  ControlVar cVar_kzHgpyMR;
  ControlVar cVar_WboneOi1;
  ControlBinop cBinop_OhV6eJJe;
  ControlBinop cBinop_Wy8hzqdF;
  ControlBinop cBinop_q5fp44WE;
  ControlBinop cBinop_QbgZd3nk;
  SignalVarf sVarf_D4BhUksq;
  ControlBinop cBinop_kDRaA5Zd;
  ControlBinop cBinop_PFbKJ8b0;
  ControlBinop cBinop_isHSz0FO;
  ControlBinop cBinop_elwZhyM8;
  ControlVar cVar_PFUEbTUl;
  ControlVar cVar_OGDBkOh3;
  ControlPack cPack_bNR6N8BI;
  ControlVar cVar_BdgrR5OE;
  ControlVar cVar_66kRJ4z3;
  ControlVar cVar_eHQbCNmu;
  ControlVar cVar_47vE0UTe;
  ControlBinop cBinop_H1nNaYMh;
  ControlBinop cBinop_fM5n5D8X;
  ControlSlice cSlice_jRNXoXBR;
  ControlSlice cSlice_uOmR58Jx;
  ControlSlice cSlice_Ibrt4nId;
  ControlSlice cSlice_YdWY2WHA;
  ControlDelay cDelay_rBpRiJTV;
  ControlDelay cDelay_akZfJ3Rv;
  ControlIf cIf_b1OKURPe;
  ControlSlice cSlice_ZO2RJk55;
  ControlPack cPack_DawPIxJp;
  SignalVarf sVarf_cjPLXbRF;
  SignalVarf sVarf_nniwqhhT;
  SignalVarf sVarf_61isFFm3;
  ControlBinop cBinop_smOxw0hW;
  ControlBinop cBinop_cS0BcCtM;
  ControlBinop cBinop_8OG3PSbp;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
