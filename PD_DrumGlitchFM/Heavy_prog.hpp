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
#include "HvSignalLine.h"
#include "HvSignalPhasor.h"
#include "HvControlUnop.h"
#include "HvControlSlice.h"
#include "HvSignalRPole.h"
#include "HvSignalSamphold.h"
#include "HvSignalTabread.h"
#include "HvControlIf.h"
#include "HvControlCast.h"
#include "HvControlDelay.h"
#include "HvSignalTabwrite.h"
#include "HvMath.h"
#include "HvControlRandom.h"
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvSignalDel1.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvTable.h"

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
  static void hTable_nuzpzT1g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JjdW1993_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_NY2Ilppz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_iwwUXeHe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_iFRjnh3y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UQYq9CSm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_clpOv6jY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_J71D6bgZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_r9rjkJvW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_avTeegms_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZZIukLk1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_glSyblAO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AnOqAKYS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_KL1HJQti_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zTvfRSPj_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_F5VHgwzy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LBR3JZ4Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MtaaXvDy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KYQbPd5s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2IDdSeLS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DxUVrL3h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pjjvJEBS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tQPeVjb2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kYvVIphP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wSoIJ9Pw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_IRQZ0JFR_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_YjCnO623_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Hwqnm6tn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_iE4gCGb3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_O0eDrKIC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6wx6FOls_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_LFbmHa8U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_weSWcRVI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cEImgR3r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_n2BxcywD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RMOcL71L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pvF4rW8G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ydsy0ZqK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pWYsUomG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KAG9AmnE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mryjuvq1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ED14oQoE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eNUP4730_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_D01Tis7G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dLb5tIRX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bMEN0NX5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_blY5JKFa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yryTzRp7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PWSe6JCM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nCHOFz6H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nFtCi2D8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_s7aEDCE3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_CqXV2mkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aguyhcWu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_G2OMEMKV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cQUR8NHk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IWkUbgrK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_st8FDfl3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AlOE5PI8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5IXaMhBw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Sf6UQ29C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Kzej7m4i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_j8wJyg4O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YIqxkjEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yHUlncGX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2LZXkhLp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MbVgotP1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qEPNiWFd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_27XSbg1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_b8EJtlIP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fX9gt4nb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RC1FLEAp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xUWjomT0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_IjUT8mP8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pWwWovfJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Saa7gZBg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_DMYL7vSL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aqeAYVLq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LHwexBMY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hNuEzYoi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b2R6isDk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ft36E5FH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ewdNOPhP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bw9liKYf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AEALBF7N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A0ckeMXk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_r73Mg4fN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_EucvSdgo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4c6AoLzp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0ffbmWRG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PZFNNC16_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R1oRtEgf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kruuGMiQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_UiXCxxhj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_n8sK7092_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_W9zlk5iQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5sJ0zc6p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rIKp7XP2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CTDP5Dw7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qrvaqrbh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DydsaQrF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1OucFaVx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Pe58yUaA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tJrIzhhP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qerh8w5B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_IDQQNwxd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_6tVhKinM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4Ko4arZv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_8vG4MOS4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_H8lXfC1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rnnRDYXz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_n4mFGdls_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Vg66aA4u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KprmGsVx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_xnQTiEkc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xlt7lUsH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_U57XbXQp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TtRfMNwl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UwMfcEPS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WZ0HKVIV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GJEuP0XV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O9wBVXyD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KUiF1cQ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kdt0rI6k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_es5Z9GdG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TwTr0lgP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4SE0Dl9D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z529lOFK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w33JWraP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dV8r74M2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RGOS5il8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8jc63xRy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SjFJ9cuH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2DdTK3in_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6HFWuHpg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_proVhYDX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WlwolUUG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_55L3bROO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m3APV51y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5Tc3rlUr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8TiMX5RJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Bfftz95Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3F6f63px_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y1ft90KE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uFuSfIsd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zaXsWg7x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Pw3Wmy61_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Jl6LFhag_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aSIIS7n5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fZ8qKUiO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I5fArWh3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5TeMyXEV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Zb3Uze6Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RjSW4lLh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uiagia7u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0ZBtW1hZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ha0hao3N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UkOruTnl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8scLgOU2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nLXvqpoj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hCOrGfes_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_41vNSV0h_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_tTst2fv8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_jxTNwxki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EJ1A1Z9b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wok2JNEI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mlrxKBPn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_57sZdZIa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_DXN3Fkqp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9Hz0ZtfH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_AUaBt1Yt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OG0A3rca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TwsUGtYW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RQiN9Zrz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5Iu7Rld2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8bqGRooH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kKkOU4NX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bqRfFTNj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UgYSXcsE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_htisHQ2l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wOhns737_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_CjAJrIsV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_X0J8ynrr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ajBNwIlb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_cJf30xBf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4D0043pE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nh8VjQex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_31j8cvUB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CdWdcvo0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_H71PkCaY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x0prnj0y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Nmjgukir_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1LhKvejM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NIdgkcWx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yZw6TnTO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tYcMyipj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1I2KijBq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l5ye3p5s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OIo4uvJh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MsKs6gwO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DGwwgz2b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NnxnJC4u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BI2LReAa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0jFsdPUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w9WXXicD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8zanzMir_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xyxU1is0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UbsJx1d7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TIdo6qDJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8Jo4ysTN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Dzci19mq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Gi5Ei4Gb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BKCMMbWo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CaK458lr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8ejZVYdw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sAvXbVt2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SS1hJ0xO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0S1CC99l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ubm92Z2d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W300dKQv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IK6KuYb5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tgK1R9ww_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PWhvXogz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jozLOCDF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IUVHN0L7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Jk4gcy8s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pp5zErPN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xIahGpzx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wHEJwGR8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SqWqy16c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tAZSZw6z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hxARYA78_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MmRjM415_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AoiBMly8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DYbYqwLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ztEY8oVJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_j1OiuOmm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_HXAl4Xdd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_KubztpGp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_tAxFk9E1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZpXTpqZT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SQkfSwRI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_FNCl2a63_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_h3WHG3rr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_unhbdF4x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4dOQoVd7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_vSIY55jT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FASl5Cjm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_R8rOMnvZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FjT3ShJf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_twb7qF6o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_q01Avk4o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9pk1JQxE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_87Gu8wa1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ppPGzp8v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xMmWQrv4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_9pmOWw9x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Kc7bJjaN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_wRViWLVH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NVpS0lgH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gCT6CZnp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_emVtbEt9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XCS22Kmc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KlN6je1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0c5RYVry_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cpEKY77g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wSHTRjGY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MGwWdfvT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_FQLyIiaT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_YQ1ct3CM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RyHMq1tI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3b3dkkmD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_bfEKSIeF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1Omtxea6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_S5XFhRDZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_M8TA715B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Q11GofMt_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_jUEQ9dXc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6k1L62L6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gVPwwBFM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2yWpv0qW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZnJiNZuF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DwolN8la_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xGYZ9UMW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Mq6rSWJ8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RqCPsZda_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TrfVVWvE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s0TEFcHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2xTijhzv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ReLfzNRr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aPMVGDek_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9xoE2D2w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tZjIcmyC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jhp9be6j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2VEKRMl0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JL1xHtE5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O22Qr14U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5nS06Iam_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qUfnLS8x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mJFnzDM8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4IB1GIDe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lco4znAJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ta01QEpa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HqH8IFLb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_US14cFOI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8DV8jKZh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R0IaF3h5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XYbwYLEm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_D8Iz8AX2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_m1XZX2AS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_G2J5P0zW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ee6TneC7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_G7ZYSRX7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qz2pNPsz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_pXRykEm1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_NPmljPnG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rbGlZLJ5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_zH935PqI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_kv2bIY6A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1ysdrbpe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iVkcPFdt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fgRJwrBq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Mvuz9BJa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hxe22jWt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NPZ8Sjmx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aqFodVH1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rfqYNQwq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EFmYu4i9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Pk4Fpr6y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8A89jj3p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Z33FkXCT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EGN1bDiJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e6GEp7Ta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ecpk7oFJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NhUxuBxO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QrwhD9I9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_waa8EF2J_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_Ykw3AEXD;
  SignalTabhead sTabhead_HPVYHAau;
  SignalTabread sTabread_9yMDwR6C;
  SignalTabread sTabread_h5pf87Wo;
  SignalPhasor sPhasor_erPdmW8W;
  SignalDel1 sDel1_vBK3ls2Z;
  SignalSamphold sSamphold_ZQEabB5y;
  SignalPhasor sPhasor_1AQ2DqjP;
  SignalTabread sTabread_UREw4iNW;
  SignalRPole sRPole_pnhgiBCb;
  SignalDel1 sDel1_YEnuWjo3;
  SignalSamphold sSamphold_X8IaeoOF;
  SignalPhasor sPhasor_ibjXiSpq;
  SignalPhasor sPhasor_Psdq8390;
  SignalLine sLine_gvnkxjuR;
  SignalTabread sTabread_ZfFOeuL7;
  SignalLine sLine_Kerjd3a8;
  SignalTabwrite sTabwrite_kREcEJmM;
  SignalPhasor sPhasor_ji3oE4eZ;
  SignalTabread sTabread_aWQcdghG;
  SignalRPole sRPole_Z6nAkyKQ;
  SignalTabread sTabread_QfLUngTy;
  HvTable hTable_nuzpzT1g;
  ControlBinop cBinop_NY2Ilppz;
  ControlRandom cRandom_iFRjnh3y;
  ControlSlice cSlice_UQYq9CSm;
  SignalVari sVari_GGBGxgOn;
  ControlVar cVar_r9rjkJvW;
  ControlSlice cSlice_glSyblAO;
  ControlBinop cBinop_AnOqAKYS;
  SignalVarf sVarf_MkaCvrmR;
  HvTable hTable_KL1HJQti;
  ControlVar cVar_F5VHgwzy;
  ControlSlice cSlice_KYQbPd5s;
  ControlBinop cBinop_2IDdSeLS;
  SignalVarf sVarf_XXlKr2j6;
  ControlVar cVar_DxUVrL3h;
  ControlBinop cBinop_pjjvJEBS;
  ControlVar cVar_tQPeVjb2;
  ControlVar cVar_kYvVIphP;
  ControlVar cVar_wSoIJ9Pw;
  ControlBinop cBinop_YjCnO623;
  ControlRandom cRandom_iE4gCGb3;
  ControlSlice cSlice_O0eDrKIC;
  ControlBinop cBinop_nCHOFz6H;
  SignalVarf sVarf_TQhhX0KG;
  ControlBinop cBinop_qEPNiWFd;
  SignalVarf sVarf_sunWIGbA;
  ControlDelay cDelay_IjUT8mP8;
  ControlVar cVar_aqeAYVLq;
  ControlBinop cBinop_hNuEzYoi;
  ControlBinop cBinop_b2R6isDk;
  ControlBinop cBinop_Ft36E5FH;
  ControlVar cVar_ewdNOPhP;
  ControlBinop cBinop_bw9liKYf;
  ControlVar cVar_AEALBF7N;
  ControlBinop cBinop_A0ckeMXk;
  ControlVar cVar_EucvSdgo;
  ControlSlice cSlice_PZFNNC16;
  ControlBinop cBinop_R1oRtEgf;
  SignalVarf sVarf_z3vyuZc9;
  ControlDelay cDelay_W9zlk5iQ;
  ControlVar cVar_Qrvaqrbh;
  ControlBinop cBinop_1OucFaVx;
  ControlBinop cBinop_Pe58yUaA;
  ControlBinop cBinop_tJrIzhhP;
  ControlVar cVar_Qerh8w5B;
  ControlSlice cSlice_H8lXfC1P;
  ControlSlice cSlice_rnnRDYXz;
  ControlVar cVar_n4mFGdls;
  ControlVar cVar_Vg66aA4u;
  ControlVar cVar_xlt7lUsH;
  ControlVar cVar_U57XbXQp;
  ControlVar cVar_TtRfMNwl;
  ControlSlice cSlice_UwMfcEPS;
  ControlSlice cSlice_WZ0HKVIV;
  ControlBinop cBinop_GJEuP0XV;
  ControlBinop cBinop_O9wBVXyD;
  ControlBinop cBinop_KUiF1cQ1;
  ControlBinop cBinop_kdt0rI6k;
  ControlBinop cBinop_es5Z9GdG;
  ControlBinop cBinop_Z529lOFK;
  ControlBinop cBinop_w33JWraP;
  ControlBinop cBinop_dV8r74M2;
  ControlBinop cBinop_RGOS5il8;
  ControlBinop cBinop_55L3bROO;
  ControlBinop cBinop_Y1ft90KE;
  ControlVar cVar_aSIIS7n5;
  ControlVar cVar_fZ8qKUiO;
  ControlVar cVar_I5fArWh3;
  ControlBinop cBinop_RjSW4lLh;
  ControlBinop cBinop_uiagia7u;
  SignalVarf sVarf_IfohYkhI;
  ControlBinop cBinop_ha0hao3N;
  ControlBinop cBinop_UkOruTnl;
  ControlBinop cBinop_8scLgOU2;
  SignalVarf sVarf_O1RrUHNx;
  ControlBinop cBinop_nLXvqpoj;
  ControlVar cVar_tTst2fv8;
  ControlSlice cSlice_wok2JNEI;
  ControlBinop cBinop_mlrxKBPn;
  SignalVarf sVarf_MBt1ngqC;
  ControlDelay cDelay_AUaBt1Yt;
  ControlVar cVar_5Iu7Rld2;
  ControlBinop cBinop_kKkOU4NX;
  ControlBinop cBinop_bqRfFTNj;
  ControlBinop cBinop_UgYSXcsE;
  ControlVar cVar_htisHQ2l;
  ControlSlice cSlice_cJf30xBf;
  ControlSlice cSlice_4D0043pE;
  ControlVar cVar_nh8VjQex;
  ControlVar cVar_31j8cvUB;
  ControlVar cVar_x0prnj0y;
  ControlVar cVar_Nmjgukir;
  ControlVar cVar_1LhKvejM;
  ControlSlice cSlice_NIdgkcWx;
  ControlSlice cSlice_yZw6TnTO;
  ControlBinop cBinop_tYcMyipj;
  ControlBinop cBinop_1I2KijBq;
  ControlBinop cBinop_l5ye3p5s;
  ControlBinop cBinop_OIo4uvJh;
  ControlBinop cBinop_MsKs6gwO;
  ControlBinop cBinop_BI2LReAa;
  ControlBinop cBinop_0jFsdPUH;
  ControlBinop cBinop_w9WXXicD;
  ControlBinop cBinop_8zanzMir;
  ControlBinop cBinop_BKCMMbWo;
  ControlBinop cBinop_ubm92Z2d;
  ControlVar cVar_jozLOCDF;
  ControlVar cVar_IUVHN0L7;
  ControlVar cVar_Jk4gcy8s;
  ControlBinop cBinop_wHEJwGR8;
  ControlBinop cBinop_SqWqy16c;
  SignalVarf sVarf_UXI1IKf6;
  ControlBinop cBinop_hxARYA78;
  ControlBinop cBinop_MmRjM415;
  ControlBinop cBinop_AoiBMly8;
  SignalVarf sVarf_qRnoYoan;
  ControlBinop cBinop_DYbYqwLH;
  ControlBinop cBinop_HXAl4Xdd;
  ControlRandom cRandom_tAxFk9E1;
  ControlSlice cSlice_ZpXTpqZT;
  ControlBinop cBinop_FNCl2a63;
  ControlRandom cRandom_unhbdF4x;
  ControlSlice cSlice_4dOQoVd7;
  ControlIf cIf_vSIY55jT;
  ControlBinop cBinop_FASl5Cjm;
  ControlVar cVar_twb7qF6o;
  ControlBinop cBinop_9pk1JQxE;
  ControlBinop cBinop_ppPGzp8v;
  SignalVarf sVarf_eICdP8Hz;
  SignalVarf sVarf_bPfdTy0V;
  SignalVarf sVarf_7T227YS1;
  ControlDelay cDelay_wRViWLVH;
  ControlVar cVar_XCS22Kmc;
  ControlBinop cBinop_0c5RYVry;
  ControlBinop cBinop_cpEKY77g;
  ControlBinop cBinop_wSHTRjGY;
  ControlVar cVar_MGwWdfvT;
  ControlSlice cSlice_bfEKSIeF;
  ControlSlice cSlice_1Omtxea6;
  ControlVar cVar_S5XFhRDZ;
  ControlVar cVar_M8TA715B;
  ControlVar cVar_6k1L62L6;
  ControlVar cVar_gVPwwBFM;
  ControlVar cVar_2yWpv0qW;
  ControlSlice cSlice_ZnJiNZuF;
  ControlSlice cSlice_DwolN8la;
  ControlBinop cBinop_xGYZ9UMW;
  ControlBinop cBinop_Mq6rSWJ8;
  ControlBinop cBinop_RqCPsZda;
  ControlBinop cBinop_TrfVVWvE;
  ControlBinop cBinop_s0TEFcHP;
  ControlBinop cBinop_aPMVGDek;
  ControlBinop cBinop_9xoE2D2w;
  ControlBinop cBinop_tZjIcmyC;
  ControlBinop cBinop_Jhp9be6j;
  ControlBinop cBinop_4IB1GIDe;
  ControlBinop cBinop_R0IaF3h5;
  ControlVar cVar_ee6TneC7;
  ControlDelay cDelay_pXRykEm1;
  ControlDelay cDelay_NPmljPnG;
  ControlBinop cBinop_zH935PqI;
  HvTable hTable_kv2bIY6A;
  ControlBinop cBinop_iVkcPFdt;
  ControlBinop cBinop_aqFodVH1;
  ControlBinop cBinop_rfqYNQwq;
  ControlBinop cBinop_EGN1bDiJ;
  ControlBinop cBinop_ecpk7oFJ;
  ControlBinop cBinop_QrwhD9I9;
  SignalVarf sVarf_qLGlR3FT;
  SignalVarf sVarf_yIdaGMrH;
  SignalVarf sVarf_T1F29IyG;
  SignalVarf sVarf_gGJiX61N;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
