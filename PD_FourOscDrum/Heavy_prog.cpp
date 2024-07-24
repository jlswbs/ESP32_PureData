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

#include "Heavy_prog.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_prog *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_prog_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_prog_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_prog_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_prog();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_Po8EKrRM, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_CRfl9uq0, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_x1L8mMlD);
  numBytes += sPhasor_init(&sPhasor_dte76BRs, sampleRate);
  numBytes += sLine_init(&sLine_LDGEo1Qm);
  numBytes += sLine_init(&sLine_p20w6CRW);
  numBytes += sPhasor_init(&sPhasor_9w1k0syw, sampleRate);
  numBytes += sPhasor_init(&sPhasor_sYJRchkA, sampleRate);
  numBytes += sLine_init(&sLine_QjX9aLjf);
  numBytes += sLine_init(&sLine_tmDLs8rB);
  numBytes += sPhasor_init(&sPhasor_khg6ykOj, sampleRate);
  numBytes += sPhasor_init(&sPhasor_69GRd7Lv, sampleRate);
  numBytes += sLine_init(&sLine_PYEMb4u2);
  numBytes += cVar_init_f(&cVar_KXBZInVO, 0.0f);
  numBytes += cVar_init_f(&cVar_8GsjVYwW, 0.0f);
  numBytes += cVar_init_f(&cVar_OYKPX3zT, 0.0f);
  numBytes += cVar_init_f(&cVar_BSjhHLJA, 0.0f);
  numBytes += cVar_init_f(&cVar_sh8ypwBG, 1.0f);
  numBytes += cVar_init_f(&cVar_UrfU5zqH, 0.0f);
  numBytes += cRandom_init(&cRandom_J8ccdS8r, 2145067496);
  numBytes += cSlice_init(&cSlice_PUnCAI4h, 1, 1);
  numBytes += cVar_init_f(&cVar_9NeYkGDG, 0.0f);
  numBytes += cVar_init_f(&cVar_y0kIiIzD, 0.0f);
  numBytes += cRandom_init(&cRandom_2TevXsNt, 1635565988);
  numBytes += cSlice_init(&cSlice_AyVE5O3b, 1, 1);
  numBytes += cVar_init_f(&cVar_9mh3tTv9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_YJS8IBbE, 0.0f);
  numBytes += cVar_init_f(&cVar_sRnnmqzA, 360.0f);
  numBytes += cBinop_init(&cBinop_lR6Rd3Tg, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_r8sIMCde, 0.0f);
  numBytes += cVar_init_f(&cVar_HVxPrRz5, 480.0f);
  numBytes += cBinop_init(&cBinop_08ObKLtc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_AnKPQOem, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_0fLAefmZ, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_KPyJljdy, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_21X2zoeY, 4, 1);
  numBytes += cSlice_init(&cSlice_1xurxlEj, 3, 1);
  numBytes += cSlice_init(&cSlice_d02rV4ie, 2, 1);
  numBytes += cSlice_init(&cSlice_cO5stuA7, 1, 1);
  numBytes += cSlice_init(&cSlice_23X14ifn, 0, 1);
  numBytes += sVarf_init(&sVarf_GCEhj3r5, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_AiaTMJfu, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DrE5THQI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FTk19mLs, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_P0sW0HAp, 0.0f);
  numBytes += cVar_init_f(&cVar_JUJKl8Gf, 120.0f);
  numBytes += cBinop_init(&cBinop_KOnBkR2g, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_nyKOadqz, 0.0f);
  numBytes += cVar_init_f(&cVar_nkXv8IP5, 240.0f);
  numBytes += cBinop_init(&cBinop_sEyyDPcs, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_C2nH64nM, -1708526077);
  numBytes += cSlice_init(&cSlice_KRg8vTa6, 1, 1);
  numBytes += cRandom_init(&cRandom_VoarSYxR, 1148512781);
  numBytes += cSlice_init(&cSlice_rA6Hje9G, 1, 1);
  numBytes += cRandom_init(&cRandom_9XoZ7f6z, 275326532);
  numBytes += cSlice_init(&cSlice_BmsayPVU, 1, 1);
  numBytes += cBinop_init(&cBinop_O76IRKG9, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_KPyJljdy);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VjzIm66Y_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_prog::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_prog::cVar_KXBZInVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2G1a6cYc_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_8GsjVYwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O2nhwcuI_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_OYKPX3zT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DHFQ0hqV_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_BSjhHLJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vdBJ8KIa_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_sh8ypwBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_wXKmSACS_sendMessage);
  cSwitchcase_iY6WAvNb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_mNVpA3RB_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_4iy0hYgK_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Pg9PCgdW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_wXKmSACS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sh8ypwBG, 1, m, &cVar_sh8ypwBG_sendMessage);
}

void Heavy_prog::cVar_UrfU5zqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KXBZInVO, 0, m, &cVar_KXBZInVO_sendMessage);
  cMsg_BOSLkc8n_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_MgtN0KwW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PUnCAI4h, 0, m, &cSlice_PUnCAI4h_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_J8ccdS8r, 0, m, &cRandom_J8ccdS8r_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_aW1Hll7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HukbLDqY_sendMessage);
}

void Heavy_prog::cUnop_HukbLDqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_HRuB2Vey_sendMessage);
}

void Heavy_prog::cRandom_J8ccdS8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_aW1Hll7B_sendMessage);
}

void Heavy_prog::cSlice_PUnCAI4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_J8ccdS8r, 1, m, &cRandom_J8ccdS8r_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_9NeYkGDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8GsjVYwW, 0, m, &cVar_8GsjVYwW_sendMessage);
}

void Heavy_prog::cVar_y0kIiIzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OYKPX3zT, 0, m, &cVar_OYKPX3zT_sendMessage);
}

void Heavy_prog::cSwitchcase_yQfpj8Np_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AyVE5O3b, 0, m, &cSlice_AyVE5O3b_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2TevXsNt, 0, m, &cRandom_2TevXsNt_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_PNCcdHRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qcrVhnpo_sendMessage);
}

void Heavy_prog::cUnop_qcrVhnpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_f9bgjRRY_sendMessage);
}

void Heavy_prog::cRandom_2TevXsNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_PNCcdHRy_sendMessage);
}

void Heavy_prog::cSlice_AyVE5O3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2TevXsNt, 1, m, &cRandom_2TevXsNt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_9mh3tTv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BSjhHLJA, 0, m, &cVar_BSjhHLJA_sendMessage);
}

void Heavy_prog::cSwitchcase_iY6WAvNb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_fz4IFdlm_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_fz4IFdlm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ELHvVHQi_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_YJS8IBbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YJS8IBbE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YJS8IBbE, 0, m, &cDelay_YJS8IBbE_sendMessage);
  cSwitchcase_yQfpj8Np_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_ELHvVHQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fz4IFdlm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YJS8IBbE, 0, m, &cDelay_YJS8IBbE_sendMessage);
  cSwitchcase_yQfpj8Np_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_XEb4jNnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bKMbrwfv_sendMessage);
}

void Heavy_prog::cSystem_bKMbrwfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lLUEgMGa_sendMessage);
}

void Heavy_prog::cVar_sRnnmqzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lR6Rd3Tg, HV_BINOP_MULTIPLY, 0, m, &cBinop_lR6Rd3Tg_sendMessage);
}

void Heavy_prog::cMsg_fz4IFdlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YJS8IBbE, 0, m, &cDelay_YJS8IBbE_sendMessage);
}

void Heavy_prog::cBinop_ZrToiT48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YJS8IBbE, 2, m, &cDelay_YJS8IBbE_sendMessage);
}

void Heavy_prog::cBinop_lLUEgMGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lR6Rd3Tg, HV_BINOP_MULTIPLY, 1, m, &cBinop_lR6Rd3Tg_sendMessage);
}

void Heavy_prog::cBinop_lR6Rd3Tg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ZrToiT48_sendMessage);
}

void Heavy_prog::cSwitchcase_mNVpA3RB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_hPQdMY6g_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_hPQdMY6g_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZPtibpBK_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_r8sIMCde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_r8sIMCde, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r8sIMCde, 0, m, &cDelay_r8sIMCde_sendMessage);
  cSwitchcase_DAPMc7DO_onMessage(_c, NULL, 0, m, NULL);
  cMsg_J9aLZVBE_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ZPtibpBK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hPQdMY6g_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r8sIMCde, 0, m, &cDelay_r8sIMCde_sendMessage);
  cSwitchcase_DAPMc7DO_onMessage(_c, NULL, 0, m, NULL);
  cMsg_J9aLZVBE_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_DpP3UyLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Y7K0iuq_sendMessage);
}

void Heavy_prog::cSystem_1Y7K0iuq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HDAjW8Hy_sendMessage);
}

void Heavy_prog::cVar_HVxPrRz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_08ObKLtc, HV_BINOP_MULTIPLY, 0, m, &cBinop_08ObKLtc_sendMessage);
}

void Heavy_prog::cMsg_hPQdMY6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_r8sIMCde, 0, m, &cDelay_r8sIMCde_sendMessage);
}

void Heavy_prog::cBinop_j3Z0B55g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_r8sIMCde, 2, m, &cDelay_r8sIMCde_sendMessage);
}

void Heavy_prog::cBinop_HDAjW8Hy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_08ObKLtc, HV_BINOP_MULTIPLY, 1, m, &cBinop_08ObKLtc_sendMessage);
}

void Heavy_prog::cBinop_08ObKLtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_j3Z0B55g_sendMessage);
}

void Heavy_prog::cSwitchcase_shwpQT9V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r1Joh2A7_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rb7lBTy2_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lu5yb0bk_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_r1Joh2A7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wTOYeL5g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cudvPpJD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XjrYcPS2_sendMessage);
}

void Heavy_prog::cCast_rb7lBTy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KqoihoXR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aBrQUK9c_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8vbzj7v7_sendMessage);
}

void Heavy_prog::cCast_Lu5yb0bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S6xMKNtZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_emWUSlru_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dklvUiHG_sendMessage);
}

void Heavy_prog::cCast_IBqe23ks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FeKGSbS4_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_XKVFAzQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AnKPQOem, HV_BINOP_DIVIDE, 0, m, &cBinop_AnKPQOem_sendMessage);
}

void Heavy_prog::cBinop_AnKPQOem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0fLAefmZ, m);
}

void Heavy_prog::cMsg_BYtOYnO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 36.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AnKPQOem, HV_BINOP_DIVIDE, 1, m, &cBinop_AnKPQOem_sendMessage);
}

void Heavy_prog::cCast_emWUSlru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYtOYnO9_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_dklvUiHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FAxKQm68_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_S6xMKNtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_8vbzj7v7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FAxKQm68_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_aBrQUK9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YoeE9iZL_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_KqoihoXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_cudvPpJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zoyeaXNk_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_XjrYcPS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FAxKQm68_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_wTOYeL5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_FeKGSbS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PYEMb4u2, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_PYEMb4u2, 0, m, NULL);
}

void Heavy_prog::cMsg_FAxKQm68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IBqe23ks_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XKVFAzQi_sendMessage);
}

void Heavy_prog::cMsg_zoyeaXNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AnKPQOem, HV_BINOP_DIVIDE, 1, m, &cBinop_AnKPQOem_sendMessage);
}

void Heavy_prog::cMsg_YoeE9iZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AnKPQOem, HV_BINOP_DIVIDE, 1, m, &cBinop_AnKPQOem_sendMessage);
}

void Heavy_prog::cPack_KPyJljdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9MthWoUW_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_21X2zoeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_GCEhj3r5, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_1xurxlEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_FTk19mLs, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_d02rV4ie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_DrE5THQI, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_cO5stuA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_CRfl9uq0, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_23X14ifn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Po8EKrRM, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_TgyzzRA0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wDkxmKfJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_wDkxmKfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GJ9LyuGO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wBPx8zuV_sendMessage);
}

void Heavy_prog::cCast_GJ9LyuGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_wBPx8zuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_frSO4oZx_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_kTR0DdaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KPyJljdy, 0, m, &cPack_KPyJljdy_sendMessage);
}

void Heavy_prog::cCast_7hOalnlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AiaTMJfu, HV_BINOP_MULTIPLY, 0, m, &cBinop_AiaTMJfu_sendMessage);
}

void Heavy_prog::cMsg_frSO4oZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7hOalnlP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kTR0DdaV_sendMessage);
}

void Heavy_prog::cBinop_AiaTMJfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KPyJljdy, 1, m, &cPack_KPyJljdy_sendMessage);
}

void Heavy_prog::cBinop_EUXFcOjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AiaTMJfu, HV_BINOP_MULTIPLY, 1, m, &cBinop_AiaTMJfu_sendMessage);
}

void Heavy_prog::cMsg_aE30gaKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_EUXFcOjF_sendMessage);
}

void Heavy_prog::cMsg_9MthWoUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_x1L8mMlD, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_x1L8mMlD, 0, m, NULL);
}

void Heavy_prog::cMsg_4sPwn52p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_21X2zoeY, 0, m, &cSlice_21X2zoeY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1xurxlEj, 0, m, &cSlice_1xurxlEj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_d02rV4ie, 0, m, &cSlice_d02rV4ie_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_cO5stuA7, 0, m, &cSlice_cO5stuA7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_23X14ifn, 0, m, &cSlice_23X14ifn_sendMessage);
}

void Heavy_prog::cSwitchcase_4iy0hYgK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_gpBsVlTz_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_gpBsVlTz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bSA3sV0e_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_P0sW0HAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P0sW0HAp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0sW0HAp, 0, m, &cDelay_P0sW0HAp_sendMessage);
  cSwitchcase_MgtN0KwW_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_xneGALph_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_bSA3sV0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gpBsVlTz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0sW0HAp, 0, m, &cDelay_P0sW0HAp_sendMessage);
  cSwitchcase_MgtN0KwW_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_xneGALph_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Fe4Gri4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mCAPzLg3_sendMessage);
}

void Heavy_prog::cSystem_mCAPzLg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nWn6qxxH_sendMessage);
}

void Heavy_prog::cVar_JUJKl8Gf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KOnBkR2g, HV_BINOP_MULTIPLY, 0, m, &cBinop_KOnBkR2g_sendMessage);
}

void Heavy_prog::cMsg_gpBsVlTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0sW0HAp, 0, m, &cDelay_P0sW0HAp_sendMessage);
}

void Heavy_prog::cBinop_4APk8voO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0sW0HAp, 2, m, &cDelay_P0sW0HAp_sendMessage);
}

void Heavy_prog::cBinop_nWn6qxxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KOnBkR2g, HV_BINOP_MULTIPLY, 1, m, &cBinop_KOnBkR2g_sendMessage);
}

void Heavy_prog::cBinop_KOnBkR2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4APk8voO_sendMessage);
}

void Heavy_prog::cSwitchcase_Pg9PCgdW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_j5Kwny9I_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_j5Kwny9I_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P8YP0ali_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_nyKOadqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nyKOadqz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nyKOadqz, 0, m, &cDelay_nyKOadqz_sendMessage);
  cSwitchcase_B4uNOb3A_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_P8YP0ali_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j5Kwny9I_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nyKOadqz, 0, m, &cDelay_nyKOadqz_sendMessage);
  cSwitchcase_B4uNOb3A_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_WyjdqVRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3tJquvAM_sendMessage);
}

void Heavy_prog::cSystem_3tJquvAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1fkIeCpP_sendMessage);
}

void Heavy_prog::cVar_nkXv8IP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sEyyDPcs, HV_BINOP_MULTIPLY, 0, m, &cBinop_sEyyDPcs_sendMessage);
}

void Heavy_prog::cMsg_j5Kwny9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nyKOadqz, 0, m, &cDelay_nyKOadqz_sendMessage);
}

void Heavy_prog::cBinop_VPfkR4Km_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nyKOadqz, 2, m, &cDelay_nyKOadqz_sendMessage);
}

void Heavy_prog::cBinop_1fkIeCpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sEyyDPcs, HV_BINOP_MULTIPLY, 1, m, &cBinop_sEyyDPcs_sendMessage);
}

void Heavy_prog::cBinop_sEyyDPcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VPfkR4Km_sendMessage);
}

void Heavy_prog::cSwitchcase_B4uNOb3A_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KRg8vTa6, 0, m, &cSlice_KRg8vTa6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C2nH64nM, 0, m, &cRandom_C2nH64nM_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_l0L1JKsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8emMaW8k_sendMessage);
}

void Heavy_prog::cUnop_8emMaW8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_vBlutDGJ_sendMessage);
}

void Heavy_prog::cRandom_C2nH64nM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_l0L1JKsD_sendMessage);
}

void Heavy_prog::cSlice_KRg8vTa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C2nH64nM, 1, m, &cRandom_C2nH64nM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_DAPMc7DO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rA6Hje9G, 0, m, &cSlice_rA6Hje9G_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VoarSYxR, 0, m, &cRandom_VoarSYxR_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_Bbj2D0gX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_VVRGPjh1_sendMessage);
}

void Heavy_prog::cUnop_VVRGPjh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_V2mPEneY_sendMessage);
}

void Heavy_prog::cRandom_VoarSYxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Bbj2D0gX_sendMessage);
}

void Heavy_prog::cSlice_rA6Hje9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VoarSYxR, 1, m, &cRandom_VoarSYxR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_xneGALph_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BmsayPVU, 0, m, &cSlice_BmsayPVU_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9XoZ7f6z, 0, m, &cRandom_9XoZ7f6z_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_S1JrsJDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qmE1r4Hc_sendMessage);
}

void Heavy_prog::cUnop_qmE1r4Hc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O76IRKG9, HV_BINOP_ADD, 1, m, &cBinop_O76IRKG9_sendMessage);
}

void Heavy_prog::cRandom_9XoZ7f6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_S1JrsJDz_sendMessage);
}

void Heavy_prog::cSlice_BmsayPVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9XoZ7f6z, 1, m, &cRandom_9XoZ7f6z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_2G1a6cYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QjX9aLjf, 0, m, NULL);
}

void Heavy_prog::cMsg_O2nhwcuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tmDLs8rB, 0, m, NULL);
}

void Heavy_prog::cMsg_DHFQ0hqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LDGEo1Qm, 0, m, NULL);
}

void Heavy_prog::cMsg_vdBJ8KIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_p20w6CRW, 0, m, NULL);
}

void Heavy_prog::cBinop_HRuB2Vey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UrfU5zqH, 0, m, &cVar_UrfU5zqH_sendMessage);
}

void Heavy_prog::cBinop_vBlutDGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9NeYkGDG, 0, m, &cVar_9NeYkGDG_sendMessage);
}

void Heavy_prog::cBinop_f9bgjRRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y0kIiIzD, 0, m, &cVar_y0kIiIzD_sendMessage);
}

void Heavy_prog::cBinop_V2mPEneY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9mh3tTv9, 0, m, &cVar_9mh3tTv9_sendMessage);
}

void Heavy_prog::cMsg_J9aLZVBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_shwpQT9V_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_BOSLkc8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_O76IRKG9, HV_BINOP_ADD, 0, m, &cBinop_O76IRKG9_sendMessage);
}

void Heavy_prog::cBinop_O76IRKG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TgyzzRA0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cReceive_VjzIm66Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XEb4jNnp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sRnnmqzA, 0, m, &cVar_sRnnmqzA_sendMessage);
  cMsg_DpP3UyLv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HVxPrRz5, 0, m, &cVar_HVxPrRz5_sendMessage);
  cMsg_aE30gaKw_sendMessage(_c, 0, m);
  cMsg_4sPwn52p_sendMessage(_c, 0, m);
  cMsg_Fe4Gri4w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JUJKl8Gf, 0, m, &cVar_JUJKl8Gf_sendMessage);
  cMsg_WyjdqVRI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nkXv8IP5, 0, m, &cVar_nkXv8IP5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sh8ypwBG, 0, m, &cVar_sh8ypwBG_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_prog::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_Po8EKrRM, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_CRfl9uq0, VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_x1L8mMlD, VOf(Bf1));
    __hv_varread_f(&sVarf_DrE5THQI, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_FTk19mLs, VOf(Bf3));
    __hv_varread_f(&sVarf_GCEhj3r5, VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_dte76BRs, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_line_f(&sLine_LDGEo1Qm, VOf(Bf0));
    __hv_line_f(&sLine_p20w6CRW, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_9w1k0syw, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_phasor_f(&sPhasor_sYJRchkA, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_QjX9aLjf, VOf(Bf7));
    __hv_line_f(&sLine_tmDLs8rB, VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_f(&sPhasor_khg6ykOj, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_phasor_f(&sPhasor_69GRd7Lv, VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_line_f(&sLine_PYEMb4u2, VOf(Bf9));
    __hv_varread_f(&sVarf_0fLAefmZ, VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf4));
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf9), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_var_k_f(VOf(Bf3), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_prog::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_prog::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
