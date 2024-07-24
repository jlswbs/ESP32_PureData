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
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvControlSystem.h"
#include "HvControlPack.h"
#include "HvSignalLine.h"
#include "HvControlSlice.h"
#include "HvControlUnop.h"
#include "HvControlBinop.h"
#include "HvControlRandom.h"
#include "HvControlDelay.h"
#include "HvControlVar.h"
#include "HvControlCast.h"

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
  static void cVar_KXBZInVO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8GsjVYwW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OYKPX3zT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BSjhHLJA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sh8ypwBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wXKmSACS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UrfU5zqH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MgtN0KwW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_aW1Hll7B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_HukbLDqY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_J8ccdS8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PUnCAI4h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9NeYkGDG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y0kIiIzD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yQfpj8Np_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_PNCcdHRy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_qcrVhnpo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_2TevXsNt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_AyVE5O3b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9mh3tTv9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_iY6WAvNb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_YJS8IBbE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ELHvVHQi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XEb4jNnp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_bKMbrwfv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sRnnmqzA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fz4IFdlm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZrToiT48_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lLUEgMGa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lR6Rd3Tg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mNVpA3RB_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_r8sIMCde_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZPtibpBK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DpP3UyLv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1Y7K0iuq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HVxPrRz5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hPQdMY6g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j3Z0B55g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HDAjW8Hy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_08ObKLtc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_shwpQT9V_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_r1Joh2A7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rb7lBTy2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Lu5yb0bk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IBqe23ks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XKVFAzQi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AnKPQOem_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BYtOYnO9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_emWUSlru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dklvUiHG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_S6xMKNtZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8vbzj7v7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aBrQUK9c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KqoihoXR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cudvPpJD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XjrYcPS2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wTOYeL5g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FeKGSbS4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FAxKQm68_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zoyeaXNk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YoeE9iZL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_KPyJljdy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_21X2zoeY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1xurxlEj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_d02rV4ie_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cO5stuA7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_23X14ifn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TgyzzRA0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_wDkxmKfJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GJ9LyuGO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wBPx8zuV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kTR0DdaV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7hOalnlP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_frSO4oZx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AiaTMJfu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EUXFcOjF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aE30gaKw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9MthWoUW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4sPwn52p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4iy0hYgK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_P0sW0HAp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bSA3sV0e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Fe4Gri4w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_mCAPzLg3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JUJKl8Gf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gpBsVlTz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4APk8voO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nWn6qxxH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KOnBkR2g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Pg9PCgdW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_nyKOadqz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P8YP0ali_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WyjdqVRI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3tJquvAM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nkXv8IP5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j5Kwny9I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VPfkR4Km_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1fkIeCpP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sEyyDPcs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_B4uNOb3A_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_l0L1JKsD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_8emMaW8k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_C2nH64nM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KRg8vTa6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_DAPMc7DO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Bbj2D0gX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_VVRGPjh1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_VoarSYxR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rA6Hje9G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xneGALph_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_S1JrsJDz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_qmE1r4Hc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_9XoZ7f6z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BmsayPVU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2G1a6cYc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O2nhwcuI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DHFQ0hqV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vdBJ8KIa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HRuB2Vey_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vBlutDGJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_f9bgjRRY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V2mPEneY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J9aLZVBE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BOSLkc8n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O76IRKG9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VjzIm66Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Po8EKrRM;
  SignalPhasor sPhasor_CRfl9uq0;
  SignalLine sLine_x1L8mMlD;
  SignalPhasor sPhasor_dte76BRs;
  SignalLine sLine_LDGEo1Qm;
  SignalLine sLine_p20w6CRW;
  SignalPhasor sPhasor_9w1k0syw;
  SignalPhasor sPhasor_sYJRchkA;
  SignalLine sLine_QjX9aLjf;
  SignalLine sLine_tmDLs8rB;
  SignalPhasor sPhasor_khg6ykOj;
  SignalPhasor sPhasor_69GRd7Lv;
  SignalLine sLine_PYEMb4u2;
  ControlVar cVar_KXBZInVO;
  ControlVar cVar_8GsjVYwW;
  ControlVar cVar_OYKPX3zT;
  ControlVar cVar_BSjhHLJA;
  ControlVar cVar_sh8ypwBG;
  ControlBinop cBinop_wXKmSACS;
  ControlVar cVar_UrfU5zqH;
  ControlBinop cBinop_aW1Hll7B;
  ControlRandom cRandom_J8ccdS8r;
  ControlSlice cSlice_PUnCAI4h;
  ControlVar cVar_9NeYkGDG;
  ControlVar cVar_y0kIiIzD;
  ControlBinop cBinop_PNCcdHRy;
  ControlRandom cRandom_2TevXsNt;
  ControlSlice cSlice_AyVE5O3b;
  ControlVar cVar_9mh3tTv9;
  ControlDelay cDelay_YJS8IBbE;
  ControlVar cVar_sRnnmqzA;
  ControlBinop cBinop_ZrToiT48;
  ControlBinop cBinop_lLUEgMGa;
  ControlBinop cBinop_lR6Rd3Tg;
  ControlDelay cDelay_r8sIMCde;
  ControlVar cVar_HVxPrRz5;
  ControlBinop cBinop_j3Z0B55g;
  ControlBinop cBinop_HDAjW8Hy;
  ControlBinop cBinop_08ObKLtc;
  ControlBinop cBinop_AnKPQOem;
  SignalVarf sVarf_0fLAefmZ;
  ControlPack cPack_KPyJljdy;
  ControlSlice cSlice_21X2zoeY;
  ControlSlice cSlice_1xurxlEj;
  ControlSlice cSlice_d02rV4ie;
  ControlSlice cSlice_cO5stuA7;
  ControlSlice cSlice_23X14ifn;
  SignalVarf sVarf_GCEhj3r5;
  ControlBinop cBinop_AiaTMJfu;
  ControlBinop cBinop_EUXFcOjF;
  SignalVarf sVarf_DrE5THQI;
  SignalVarf sVarf_FTk19mLs;
  ControlDelay cDelay_P0sW0HAp;
  ControlVar cVar_JUJKl8Gf;
  ControlBinop cBinop_4APk8voO;
  ControlBinop cBinop_nWn6qxxH;
  ControlBinop cBinop_KOnBkR2g;
  ControlDelay cDelay_nyKOadqz;
  ControlVar cVar_nkXv8IP5;
  ControlBinop cBinop_VPfkR4Km;
  ControlBinop cBinop_1fkIeCpP;
  ControlBinop cBinop_sEyyDPcs;
  ControlBinop cBinop_l0L1JKsD;
  ControlRandom cRandom_C2nH64nM;
  ControlSlice cSlice_KRg8vTa6;
  ControlBinop cBinop_Bbj2D0gX;
  ControlRandom cRandom_VoarSYxR;
  ControlSlice cSlice_rA6Hje9G;
  ControlBinop cBinop_S1JrsJDz;
  ControlRandom cRandom_9XoZ7f6z;
  ControlSlice cSlice_BmsayPVU;
  ControlBinop cBinop_HRuB2Vey;
  ControlBinop cBinop_vBlutDGJ;
  ControlBinop cBinop_f9bgjRRY;
  ControlBinop cBinop_V2mPEneY;
  ControlBinop cBinop_O76IRKG9;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
