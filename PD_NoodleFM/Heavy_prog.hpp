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
#include "HvControlBinop.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"
#include "HvTable.h"
#include "HvControlSlice.h"
#include "HvControlSystem.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvSignalRPole.h"
#include "HvControlDelay.h"
#include "HvSignalSamphold.h"
#include "HvSignalVar.h"
#include "HvControlUnop.h"
#include "HvSignalPhasor.h"
#include "HvSignalTabread.h"
#include "HvControlRandom.h"

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
  static void hTable_jCCDVWQI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_54BRwOFy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_MDdF8jov_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_tFOWnE2l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Sh4Fncxx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mT8lEY5R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hW0ORePN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qLhvxmzd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_VaQy0tNm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_566Lo9Db_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9OeJCsHq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WRhIDnPD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_c7Tle2Ix_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_iCtzOTOf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ToHpvWyD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_i78GeMpw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RtxuyZnM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VVt5I32A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_c8z323Bj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q0WVtELO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VNUlLlgI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d2Ae0kMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mD9pdlgW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_z4NSS9rp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oQmdBjSK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uILFc7W4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_6KhSksuV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_oxuvIae6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aNTNx1gA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_c6mfptmw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e4uj5vh6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j3CiHu9d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4ZmJN7oh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_lDOXitVM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_HvWpsfiw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ynoijBi3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gj0O7jQm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_KaRcE1rM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sV9Co62c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iM5ANqby_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9QT22ZK6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Bcm58bOw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fG8g1Ig1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_351a7eub_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_K5qWyyeY_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_uCML7Ex1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sIof6cBE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rUBCACYO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_9KrHcYAs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YPSNUbpJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ul5MLxT8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_28q3Gucu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3VSqF9U3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_6ALLcfLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OjFjFYEg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ep2VcbB4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WuOy1exi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sAKwJVdg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YpVNc6ZO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1D0Wmylh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ExATSVZq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sOZwtyCe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hvGNv623_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0tVtvBif_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MBZ3gnBI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IGudnTHG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eCbQtQ6K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rKiwoRCC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8HGz5QCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mcsLm02D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rGFAS8jW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_M4DzltPu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_auTUUCOH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NzfqVS8T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IKCVfWsa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FV5AmZeZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xiNU2vrg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fihBT9KS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4xIsYw6Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0O9IVAlP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KErKVSma_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uasloja7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zH0B4cQ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AFgUpDIy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SW4AF7Bl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ikuOHhvC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Qu2PB0ov_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Tfk04EG1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bLxrB8TK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_q7EZ2IXQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VzsYfzYU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_y0NhsbKO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YHMX96v8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XqwWbkON_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oX6fqTVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qjqRTm6V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EtYA7t6q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6RftiFMe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ANvL7JnK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_g1vEBkea_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BQx7NL2Z_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_NLCcHSen_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GXlA86s3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8L6OrAut_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5ZapETkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V9UtAnjW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RoxlRdrR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Ae8JrsZx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Bl1Ne1OD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_NvNGczAT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_s0Djen1f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KOtP7Ypx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2lb2fqIe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8HIZP3Wx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HziQSVqi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_siJuQUIh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DMdGJtgz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PhtzFj9H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lRcGpdft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_DajjMmwN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_5QL7eIUd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HwoWG4dx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_afw8wfDu_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_WCspljmO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4JvOM7Lu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_T1cj9KUs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x0dYeFiy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_H5001sOh_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_FcHJ4Yu3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1cKuofcp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_J17DPHr2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rWob9zZw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_hSlPUeF2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4VYkSVbh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_coURPGFL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h71d0rwt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3Uc2Yd0l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wQ6OZggl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zwe0S00z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HuGhT9z8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_an8RbMH0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z1qlnmlF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jDVmQqVc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lbSuZ1GZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k1kMJZMc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jC1Xksxj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7HzcvZ9W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_giXjmZ9q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lk4qOTSq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KpGsdw5p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TjCuLJ0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UDQYYpCE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GWv9DN5K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_peU1cWce_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hKK49EGO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a6KL4ZNR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XlfnCVhd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XojsP7l7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EVU8b9iw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J3JRqYd2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_74tnbFII_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9Hj8bO6e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_b1jLgKW8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fJlCB5Q3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZDXrelO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_odDLhuPu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0pEGgKpV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H7hZlj8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SA9i1i9X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gy5mdjVC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vNURfSP5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ypdvIAAC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fwDaHLfz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ypodWxNy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_k6Hm1Rs8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_hIv0KkEM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_rLyKpXYj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OC40gq6E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4JuLlEwy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_bBRzbwMh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x8TXmBWB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xhFBQB59_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vPE33F9r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3S5kvFTH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YSURqAde_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vR4YXHyS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_eDaXTy5N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_7AOXQ70e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_BPyGLp9a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_H9SEGXap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Eppw4nyN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_hpOnCzhu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_SyoE8HJy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_NLtOyXIw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9BjPBoFR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_DFOwN7ul_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_cMLblFmp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_wPZKuUrJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_1fl30dN0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_OpRx6UWG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rx9ix8xz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fMrGHicB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lbZTUNpG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LYjrWvJg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_lNAsSoTv_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_1hPHYRCe;
  SignalPhasor sPhasor_R5MIhdk9;
  SignalTabread sTabread_gCavYMUi;
  SignalRPole sRPole_BzrGQPBH;
  SignalPhasor sPhasor_ZMhDY3Gp;
  SignalDel1 sDel1_wwaYJPIN;
  SignalSamphold sSamphold_CHzzCTd1;
  SignalPhasor sPhasor_gnb4NNin;
  SignalPhasor sPhasor_mX0IMNqq;
  SignalTabread sTabread_3rH5YBA9;
  SignalDel1 sDel1_D5yeXuPo;
  SignalSamphold sSamphold_KqL8alVT;
  SignalPhasor sPhasor_Lc8M1ZOl;
  SignalPhasor sPhasor_MnSCPKGK;
  SignalPhasor sPhasor_pMCXnglZ;
  SignalTabread sTabread_zBR7tNNi;
  SignalRPole sRPole_GleC6YyZ;
  SignalTabread sTabread_jZxQYrKW;
  SignalPhasor sPhasor_VP39BkkG;
  HvTable hTable_jCCDVWQI;
  ControlBinop cBinop_MDdF8jov;
  ControlRandom cRandom_Sh4Fncxx;
  ControlSlice cSlice_mT8lEY5R;
  SignalVari sVari_3GECHzGw;
  ControlVar cVar_VaQy0tNm;
  ControlSlice cSlice_WRhIDnPD;
  ControlBinop cBinop_c7Tle2Ix;
  SignalVarf sVarf_RxGJSywu;
  HvTable hTable_iCtzOTOf;
  ControlVar cVar_i78GeMpw;
  ControlSlice cSlice_c8z323Bj;
  ControlBinop cBinop_Q0WVtELO;
  SignalVarf sVarf_AGV1Z0H0;
  ControlVar cVar_VNUlLlgI;
  ControlBinop cBinop_d2Ae0kMV;
  ControlVar cVar_mD9pdlgW;
  ControlVar cVar_z4NSS9rp;
  ControlVar cVar_oQmdBjSK;
  ControlVar cVar_6KhSksuV;
  ControlSlice cSlice_c6mfptmw;
  ControlBinop cBinop_e4uj5vh6;
  SignalVarf sVarf_oEa2iozi;
  ControlDelay cDelay_HvWpsfiw;
  ControlVar cVar_sV9Co62c;
  ControlBinop cBinop_9QT22ZK6;
  ControlBinop cBinop_Bcm58bOw;
  ControlBinop cBinop_fG8g1Ig1;
  ControlVar cVar_351a7eub;
  ControlSlice cSlice_9KrHcYAs;
  ControlSlice cSlice_YPSNUbpJ;
  ControlVar cVar_Ul5MLxT8;
  ControlVar cVar_28q3Gucu;
  ControlVar cVar_OjFjFYEg;
  ControlVar cVar_Ep2VcbB4;
  ControlVar cVar_WuOy1exi;
  ControlSlice cSlice_sAKwJVdg;
  ControlSlice cSlice_YpVNc6ZO;
  ControlBinop cBinop_1D0Wmylh;
  ControlBinop cBinop_ExATSVZq;
  ControlBinop cBinop_sOZwtyCe;
  ControlBinop cBinop_hvGNv623;
  ControlBinop cBinop_0tVtvBif;
  ControlBinop cBinop_eCbQtQ6K;
  ControlBinop cBinop_rKiwoRCC;
  ControlBinop cBinop_8HGz5QCr;
  ControlBinop cBinop_mcsLm02D;
  ControlBinop cBinop_xiNU2vrg;
  ControlBinop cBinop_zH0B4cQ4;
  ControlVar cVar_Tfk04EG1;
  ControlVar cVar_bLxrB8TK;
  ControlVar cVar_q7EZ2IXQ;
  ControlBinop cBinop_YHMX96v8;
  ControlBinop cBinop_XqwWbkON;
  SignalVarf sVarf_kmiEHq0F;
  ControlBinop cBinop_qjqRTm6V;
  ControlBinop cBinop_EtYA7t6q;
  ControlBinop cBinop_6RftiFMe;
  SignalVarf sVarf_DgyRxLke;
  ControlBinop cBinop_ANvL7JnK;
  ControlVar cVar_NLCcHSen;
  ControlSlice cSlice_5ZapETkv;
  ControlBinop cBinop_V9UtAnjW;
  SignalVarf sVarf_RIL1ZuxN;
  ControlDelay cDelay_NvNGczAT;
  ControlVar cVar_8HIZP3Wx;
  ControlBinop cBinop_siJuQUIh;
  ControlBinop cBinop_DMdGJtgz;
  ControlBinop cBinop_PhtzFj9H;
  ControlVar cVar_lRcGpdft;
  ControlSlice cSlice_WCspljmO;
  ControlSlice cSlice_4JvOM7Lu;
  ControlVar cVar_T1cj9KUs;
  ControlVar cVar_x0dYeFiy;
  ControlVar cVar_1cKuofcp;
  ControlVar cVar_J17DPHr2;
  ControlVar cVar_rWob9zZw;
  ControlSlice cSlice_hSlPUeF2;
  ControlSlice cSlice_4VYkSVbh;
  ControlBinop cBinop_coURPGFL;
  ControlBinop cBinop_h71d0rwt;
  ControlBinop cBinop_3Uc2Yd0l;
  ControlBinop cBinop_wQ6OZggl;
  ControlBinop cBinop_zwe0S00z;
  ControlBinop cBinop_Z1qlnmlF;
  ControlBinop cBinop_jDVmQqVc;
  ControlBinop cBinop_lbSuZ1GZ;
  ControlBinop cBinop_k1kMJZMc;
  ControlBinop cBinop_UDQYYpCE;
  ControlBinop cBinop_XojsP7l7;
  ControlVar cVar_b1jLgKW8;
  ControlVar cVar_fJlCB5Q3;
  ControlVar cVar_ZDXrelO6;
  ControlBinop cBinop_H7hZlj8r;
  ControlBinop cBinop_SA9i1i9X;
  SignalVarf sVarf_B9h1LePy;
  ControlBinop cBinop_vNURfSP5;
  ControlBinop cBinop_ypdvIAAC;
  ControlBinop cBinop_fwDaHLfz;
  SignalVarf sVarf_u6NGvTFr;
  ControlBinop cBinop_ypodWxNy;
  SignalVarf sVarf_hKpIuWB2;
  SignalVarf sVarf_aa1RAOoK;
  ControlDelay cDelay_rLyKpXYj;
  ControlVar cVar_x8TXmBWB;
  ControlBinop cBinop_vPE33F9r;
  ControlBinop cBinop_3S5kvFTH;
  ControlBinop cBinop_YSURqAde;
  ControlBinop cBinop_eDaXTy5N;
  ControlRandom cRandom_BPyGLp9a;
  ControlSlice cSlice_H9SEGXap;
  ControlBinop cBinop_hpOnCzhu;
  ControlRandom cRandom_NLtOyXIw;
  ControlSlice cSlice_9BjPBoFR;
  ControlBinop cBinop_cMLblFmp;
  ControlRandom cRandom_1fl30dN0;
  ControlSlice cSlice_OpRx6UWG;
  ControlBinop cBinop_rx9ix8xz;
  ControlBinop cBinop_fMrGHicB;
  ControlBinop cBinop_lbZTUNpG;
  ControlBinop cBinop_LYjrWvJg;
  SignalVarf sVarf_0PgfG2og;
  SignalVarf sVarf_hBfTf7cP;
  SignalVarf sVarf_xJBVVo8G;
  SignalVarf sVarf_ubGYPnNy;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
