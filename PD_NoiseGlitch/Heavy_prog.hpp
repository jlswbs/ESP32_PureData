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
#include "HvControlIf.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvControlRandom.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlBinop.h"
#include "HvControlUnop.h"
#include "HvControlDelay.h"
#include "HvSignalTabwrite.h"
#include "HvSignalSamphold.h"
#include "HvSignalPhasor.h"
#include "HvSignalRPole.h"
#include "HvControlSlice.h"
#include "HvSignalDel1.h"
#include "HvSignalVar.h"
#include "HvSignalTabread.h"

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
  static void hTable_hNTLLZQ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_83Dc4gVH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_sfVHlU8R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qj7csiEk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_c9NGP1Od_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fZxkHQlI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kJLe9ygk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_I4jq2luY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bIzlwcP1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BMxj5tRU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uYnlgSPv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OHEuqIJC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MlTQ54mv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7yPT9PH8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9rYhEZeL_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_1RmVUCez_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UTJ0Nr3W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fsX4PHtZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_JxmSEaTR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4hmH5JIK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eb0V5FPV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ydvJaGVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_kkmcpDSr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_XRQAU1iM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ABJP8LK0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AU4ntFFm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Wn2LVcec_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8FIVrdQ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wxfot2fC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v0jUceVM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UwFHulMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9MKW11jc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l6lHWc5n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jJnZu7Gi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1BiQUunu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0h9cDXqu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Sy57XhqK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sueXsVhp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J3StGAIw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GHsN9tOU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iVVJgDBI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pC8LOgEr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yh0NlbKt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zDMUmnRl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rzL4YjGb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7Y2wpYKw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XpvjE7Aj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DVhz9UqB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Rk7VIRjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RmmM3sR5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9IKqZvRb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JGyDGxOQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VHVlyy1h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jo3J9nad_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xjJ7c0mZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qihYcUfM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GjXEoKHr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lH9kH58U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RTCxRcU9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2JMcyfLW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XdXdi1Gn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4PaVFaGy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ibVP9RHv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ze4CT2HP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j4ieCNOH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lf4qSpKz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nSnG6hHz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TxdL3sLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aGm9hXG6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qkzlbTNS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_RA4wmrik_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RMG0xgME_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9FMb0lsW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_hEfetDlA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eVxIIQvg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tFEIsMdw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HUNI1dWF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OiKeF8J2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VIP7Cham_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zHQHfF9B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_384qgcHB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_X5JXEGAq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oDhP9ixZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UYCETMFT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_umRfhjf8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kt02wzks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sskrgh2W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sG2qIWAK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3DtduSHE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_CbWgtpSx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7hCVeQsU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zCdpXUg6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xkDpkhdk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fex1PwmF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hg6Y5fTT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kl5XB2eB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wEvaVAbV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dL3Cf0HD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_PPyQYIig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_QXWlfLtD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_PM0edoLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nnzrAbi5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7h6iBN3g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wCeRaWE7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0pPy1VyN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qNdRxNqu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fxiBLBOS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xB9c8l6E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ePG46ajT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_B9XVnhHn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZZuzV5g0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_IFng5isa_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_mTq1rOlJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n9tE9hn5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0Fp2gN0Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_M9dfK8kO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_smLTstmO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_es8AOS40_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_olEadc7C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Vdeqy1M9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uNZEYs2k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kbTaTApq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XAKC0GSQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zD3ndEdw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CSDJiBrg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YxZRvHpC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wNSLkSQW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_nKH0w9qE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VXBfwe3W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_EpwPgG5I_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Yo9pk5Xv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_GcKyizcz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GCkLVHyq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zhRizkkw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WDaDfdrf_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Zebqp15r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_15eX9dMR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OyiPk4ea_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FELnZVwu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TAeBQSCg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_xWvTcEX4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vXOIeDFU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GaT04mWS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZRpr1YrQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WlCe3QAb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_c01zmp2z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d0xQ04iL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YiEZdgSD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_95k34mHT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IGk8fIHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GhyJU73T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vTU3bygT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gOkevSaw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J5RjRo4c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_haV2Y5W2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OXEkIcgu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2hu80XeE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gsFikIM7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0rmVd1I2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ufgjGiYY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dsgd3Otx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FdEMsD5s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_F3a69WSY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jc2BFjcG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sZRTjXH1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ql2wIT6H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qnssQ6Wy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lS6cZNrX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1Fu7fc27_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DY596Izp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MxKuDmT1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_45lq3xfa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XXM0YvZM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0OYrEg93_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4KFaY69i_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_XXhw3JOd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_jwO5LOPL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_modEGIVZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UtD1DTpG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_2ZIfrK4n_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_oEMGdKMI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Qbu4o7pY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_22fQMR0c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YOQLLq78_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ubTfXNzh_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_R2sy5rv2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_vgxKQ1xh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_LMs2r5Sp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Xc1ClxLC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ietxLhVi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_9XGa5IEA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YfpUIJT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TCH7IVVL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CXp1OzWW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1lxzZiIo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R5B0nBLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VWRfZoVB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_T2NCQOsf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FA3RwTl9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nFjrpsBm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_85s0a5bQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9bWHO5dC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d11pDNUV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ACdAwgPx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YHKwXO2Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0Nb7eubP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_W1SrGX2V_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_aylslc2Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_9SGameqH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6xtbo6vk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0dRV46sb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8NLgjLqe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_akVEod5b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PYZjJu29_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_sOIlgaqw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_xpazNiSL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_RL3zBSyg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6ajlSnxY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0h6ws5Hf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KZw7WqF2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_PEdetwEy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RrNnQwd0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3S7yXL6l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sN2unbVD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_38rCLaZg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9S8Va8uh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lCbf1UIG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_gNAGIsNv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_5VncU2TL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_H1uv0pjR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_k9Qhjfne_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SpoixHbv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SVRiWx7D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aInbJWSJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ft4hGlJq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o64VPRBX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9kcrKHsQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_k3l1O7oU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_CxQW5IMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Ze1bC2sj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_sVgdf4PP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DOKOv4O8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tsluSZlN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qx8zQ0TX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_QX6txJwj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_5pwe70Hn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5wxmbJwt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_O4CEwlhw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rbyiPUUx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MQLyADQe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kleEQH7K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_o4lHDxDo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_uUCZ4NKo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ZtjMJqqV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qWsO6FOl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bsxc2P8I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rmlyRC52_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uUR0O8ga_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SoSMHb31_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HcIJjuTU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xrJnFlfv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JUu8uMnW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_MYVpZiuD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_kd9kzGkh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Me158qNL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oT13qH0M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KIevsYo2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_koQ7oRa5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d9MdT8pc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GUXr1uXE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_F1QFnKbK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QzQ0UGao_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DqOXjsFl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2jgRGMOT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jsjBynUP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pfZ41eXm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xPYEra5M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GUcbGGtm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a3h7QGKo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Bvwq3sHQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OfkT9L8m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XWjuQURi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_TsTiEUnK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JVq5U3z9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EyNEZKRE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_WclLjLcX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_occCkZ1c_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_xkU9AfC3;
  SignalPhasor sPhasor_9zhJXIbS;
  SignalDel1 sDel1_Rbol7sV7;
  SignalSamphold sSamphold_eX0X9rcc;
  SignalPhasor sPhasor_2EujnzBM;
  SignalTabread sTabread_yKcIZGrO;
  SignalDel1 sDel1_JYJLbKEN;
  SignalSamphold sSamphold_aKsTdQsH;
  SignalPhasor sPhasor_JDscnkNG;
  SignalTabread sTabread_N8TpCNps;
  SignalTabwrite sTabwrite_zKNe5rZs;
  SignalPhasor sPhasor_lPyQcKUb;
  SignalTabread sTabread_Bq2c0V3v;
  SignalTabread sTabread_Sn7Odrkg;
  SignalPhasor sPhasor_o55CTsvV;
  SignalTabread sTabread_eewsHbMM;
  SignalRPole sRPole_VzLW55oA;
  SignalPhasor sPhasor_HchcDHKK;
  SignalPhasor sPhasor_i580LAs9;
  SignalDel1 sDel1_cyBBRnke;
  SignalSamphold sSamphold_Mdk7pS5X;
  SignalPhasor sPhasor_wVTzuI0r;
  SignalTabread sTabread_HbBhbiRo;
  SignalDel1 sDel1_tr0bhcIW;
  SignalSamphold sSamphold_ynX61apZ;
  SignalPhasor sPhasor_15v3gyK1;
  SignalTabread sTabread_UDmNHYCE;
  SignalPhasor sPhasor_UwYljcj8;
  HvTable hTable_hNTLLZQ9;
  ControlDelay cDelay_c9NGP1Od;
  ControlVar cVar_bIzlwcP1;
  ControlBinop cBinop_uYnlgSPv;
  ControlBinop cBinop_OHEuqIJC;
  ControlBinop cBinop_MlTQ54mv;
  ControlVar cVar_7yPT9PH8;
  ControlSlice cSlice_JxmSEaTR;
  ControlSlice cSlice_4hmH5JIK;
  ControlVar cVar_eb0V5FPV;
  ControlVar cVar_ydvJaGVT;
  ControlVar cVar_ABJP8LK0;
  ControlVar cVar_AU4ntFFm;
  ControlVar cVar_Wn2LVcec;
  ControlSlice cSlice_8FIVrdQ9;
  ControlSlice cSlice_wxfot2fC;
  ControlBinop cBinop_v0jUceVM;
  ControlBinop cBinop_UwFHulMV;
  ControlBinop cBinop_9MKW11jc;
  ControlBinop cBinop_l6lHWc5n;
  ControlBinop cBinop_jJnZu7Gi;
  ControlBinop cBinop_Sy57XhqK;
  ControlBinop cBinop_sueXsVhp;
  ControlBinop cBinop_J3StGAIw;
  ControlBinop cBinop_GHsN9tOU;
  ControlBinop cBinop_XpvjE7Aj;
  ControlBinop cBinop_VHVlyy1h;
  ControlVar cVar_lH9kH58U;
  ControlVar cVar_RTCxRcU9;
  ControlVar cVar_2JMcyfLW;
  ControlBinop cBinop_ibVP9RHv;
  ControlBinop cBinop_Ze4CT2HP;
  SignalVarf sVarf_vnii919H;
  ControlBinop cBinop_lf4qSpKz;
  ControlBinop cBinop_nSnG6hHz;
  ControlBinop cBinop_TxdL3sLy;
  SignalVarf sVarf_Huhjz27C;
  ControlBinop cBinop_aGm9hXG6;
  ControlVar cVar_RA4wmrik;
  ControlSlice cSlice_hEfetDlA;
  ControlBinop cBinop_eVxIIQvg;
  SignalVarf sVarf_3lU6YYds;
  ControlVar cVar_HUNI1dWF;
  ControlBinop cBinop_OiKeF8J2;
  ControlVar cVar_VIP7Cham;
  ControlBinop cBinop_zHQHfF9B;
  ControlVar cVar_384qgcHB;
  ControlVar cVar_X5JXEGAq;
  ControlBinop cBinop_oDhP9ixZ;
  ControlIf cIf_umRfhjf8;
  ControlBinop cBinop_kt02wzks;
  ControlVar cVar_sskrgh2W;
  ControlVar cVar_sG2qIWAK;
  ControlDelay cDelay_CbWgtpSx;
  ControlVar cVar_fex1PwmF;
  ControlBinop cBinop_kl5XB2eB;
  ControlBinop cBinop_wEvaVAbV;
  ControlBinop cBinop_dL3Cf0HD;
  HvTable hTable_PPyQYIig;
  ControlBinop cBinop_0pPy1VyN;
  ControlBinop cBinop_xB9c8l6E;
  ControlBinop cBinop_ZZuzV5g0;
  ControlDelay cDelay_smLTstmO;
  ControlVar cVar_uNZEYs2k;
  ControlBinop cBinop_XAKC0GSQ;
  ControlBinop cBinop_zD3ndEdw;
  ControlBinop cBinop_CSDJiBrg;
  ControlVar cVar_YxZRvHpC;
  ControlSlice cSlice_Yo9pk5Xv;
  ControlSlice cSlice_GcKyizcz;
  ControlVar cVar_GCkLVHyq;
  ControlVar cVar_zhRizkkw;
  ControlVar cVar_15eX9dMR;
  ControlVar cVar_OyiPk4ea;
  ControlVar cVar_FELnZVwu;
  ControlSlice cSlice_TAeBQSCg;
  ControlSlice cSlice_xWvTcEX4;
  ControlBinop cBinop_vXOIeDFU;
  ControlBinop cBinop_GaT04mWS;
  ControlBinop cBinop_ZRpr1YrQ;
  ControlBinop cBinop_WlCe3QAb;
  ControlBinop cBinop_c01zmp2z;
  ControlBinop cBinop_95k34mHT;
  ControlBinop cBinop_IGk8fIHP;
  ControlBinop cBinop_GhyJU73T;
  ControlBinop cBinop_vTU3bygT;
  ControlBinop cBinop_0rmVd1I2;
  ControlBinop cBinop_sZRTjXH1;
  ControlVar cVar_DY596Izp;
  ControlVar cVar_MxKuDmT1;
  ControlBinop cBinop_XXM0YvZM;
  ControlBinop cBinop_0OYrEg93;
  SignalVarf sVarf_UGggVA3l;
  ControlBinop cBinop_XXhw3JOd;
  ControlRandom cRandom_modEGIVZ;
  ControlSlice cSlice_UtD1DTpG;
  ControlBinop cBinop_oEMGdKMI;
  ControlRandom cRandom_22fQMR0c;
  ControlSlice cSlice_YOQLLq78;
  ControlBinop cBinop_R2sy5rv2;
  ControlRandom cRandom_LMs2r5Sp;
  ControlSlice cSlice_Xc1ClxLC;
  ControlDelay cDelay_9XGa5IEA;
  ControlVar cVar_YfpUIJT3;
  ControlSlice cSlice_TCH7IVVL;
  ControlSlice cSlice_CXp1OzWW;
  ControlBinop cBinop_1lxzZiIo;
  ControlBinop cBinop_R5B0nBLP;
  ControlBinop cBinop_nFjrpsBm;
  ControlBinop cBinop_85s0a5bQ;
  ControlVar cVar_aylslc2Y;
  ControlBinop cBinop_6xtbo6vk;
  ControlSlice cSlice_8NLgjLqe;
  SignalVarf sVarf_hoaUX3OS;
  ControlVar cVar_akVEod5b;
  ControlBinop cBinop_sOIlgaqw;
  ControlRandom cRandom_RL3zBSyg;
  ControlSlice cSlice_6ajlSnxY;
  SignalVari sVari_LwFe7J4k;
  ControlVar cVar_PEdetwEy;
  ControlSlice cSlice_sN2unbVD;
  ControlBinop cBinop_38rCLaZg;
  SignalVarf sVarf_ReTUxQK2;
  ControlVar cVar_9S8Va8uh;
  ControlVar cVar_lCbf1UIG;
  ControlVar cVar_5VncU2TL;
  ControlSlice cSlice_SpoixHbv;
  ControlBinop cBinop_SVRiWx7D;
  SignalVarf sVarf_m9YXo59P;
  ControlBinop cBinop_aInbJWSJ;
  ControlBinop cBinop_Ft4hGlJq;
  ControlBinop cBinop_o64VPRBX;
  SignalVarf sVarf_nA4Olnjc;
  SignalVarf sVarf_VQisEZpv;
  SignalVarf sVarf_ywB4EeiF;
  SignalVarf sVarf_jPwumd1c;
  ControlVar cVar_9kcrKHsQ;
  ControlBinop cBinop_CxQW5IMm;
  ControlRandom cRandom_sVgdf4PP;
  ControlSlice cSlice_DOKOv4O8;
  SignalVari sVari_JW3YSXny;
  ControlVar cVar_QX6txJwj;
  ControlSlice cSlice_O4CEwlhw;
  ControlBinop cBinop_rbyiPUUx;
  SignalVarf sVarf_kzebaz0Q;
  ControlVar cVar_MQLyADQe;
  ControlVar cVar_kleEQH7K;
  ControlVar cVar_uUCZ4NKo;
  ControlSlice cSlice_bsxc2P8I;
  ControlBinop cBinop_rmlyRC52;
  SignalVarf sVarf_3Hw3PUID;
  ControlBinop cBinop_uUR0O8ga;
  ControlBinop cBinop_SoSMHb31;
  ControlBinop cBinop_HcIJjuTU;
  ControlBinop cBinop_xrJnFlfv;
  ControlBinop cBinop_JUu8uMnW;
  SignalVarf sVarf_fe0D9V86;
  SignalVarf sVarf_MdZrqOea;
  SignalVarf sVarf_HhWWpn6s;
  SignalVarf sVarf_9L6SBIsG;
  ControlBinop cBinop_jsjBynUP;
  ControlBinop cBinop_Bvwq3sHQ;
  ControlBinop cBinop_XWjuQURi;
  HvTable hTable_TsTiEUnK;
  SignalVarf sVarf_I5pcZ7Os;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
