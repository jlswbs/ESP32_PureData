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
  numBytes += sPhasor_init(&sPhasor_KVEOvBK3, sampleRate);
  numBytes += sLine_init(&sLine_Y1BpJ4ki);
  numBytes += sPhasor_init(&sPhasor_wxNeD3Ib, sampleRate);
  numBytes += sLine_init(&sLine_TT4O0ROg);
  numBytes += sPhasor_k_init(&sPhasor_rZDiezVj, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_b0l9SnWC, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_9RoNhLH8);
  numBytes += sPhasor_init(&sPhasor_FPSv2XpK, sampleRate);
  numBytes += sPhasor_init(&sPhasor_vgRCcZ58, sampleRate);
  numBytes += sPhasor_init(&sPhasor_u3TaaAiL, sampleRate);
  numBytes += sLine_init(&sLine_aionPTXp);
  numBytes += sPhasor_k_init(&sPhasor_esoeKcyU, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_ZZbQSHmn, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_l8OOe6K7);
  numBytes += sPhasor_init(&sPhasor_jaAH7EqE, sampleRate);
  numBytes += sLine_init(&sLine_OBT1ENbl);
  numBytes += sTabhead_init(&sTabhead_8e94KVJt, &hTable_gH7P2gSB);
  numBytes += sTabread_init(&sTabread_4stW0jBp, &hTable_gH7P2gSB, false);
  numBytes += sTabread_init(&sTabread_RdmQiNtP, &hTable_gH7P2gSB, false);
  numBytes += sLine_init(&sLine_zsq0816i);
  numBytes += sLine_init(&sLine_pH3dBD1t);
  numBytes += sTabhead_init(&sTabhead_M701P5zx, &hTable_u2b7yuxf);
  numBytes += sTabread_init(&sTabread_RmAx14Rt, &hTable_u2b7yuxf, false);
  numBytes += sTabread_init(&sTabread_IKc9o2cl, &hTable_u2b7yuxf, false);
  numBytes += sLine_init(&sLine_TKDFRDBs);
  numBytes += sTabwrite_init(&sTabwrite_QkkdDpK6, &hTable_gH7P2gSB);
  numBytes += sTabwrite_init(&sTabwrite_5KLxyN5r, &hTable_u2b7yuxf);
  numBytes += sLine_init(&sLine_EXIjPF3w);
  numBytes += cVar_init_f(&cVar_heXYxN8M, 0.0f);
  numBytes += cVar_init_f(&cVar_MapbpzqU, 1.0f);
  numBytes += cVar_init_f(&cVar_G0R4RCyd, 0.0f);
  numBytes += cRandom_init(&cRandom_AL6ThBUC, 888574093);
  numBytes += cSlice_init(&cSlice_dVYW4J1E, 1, 1);
  numBytes += cRandom_init(&cRandom_1tbUJh7Z, 1527889102);
  numBytes += cSlice_init(&cSlice_l1kmoVfo, 1, 1);
  numBytes += cPack_init(&cPack_I1SnHKSl, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_FR0jXv2B, 4, 1);
  numBytes += cSlice_init(&cSlice_Zn2Ww4NH, 3, 1);
  numBytes += cSlice_init(&cSlice_w2HhWvr0, 2, 1);
  numBytes += cSlice_init(&cSlice_STh7fPrV, 1, 1);
  numBytes += cSlice_init(&cSlice_yAlIiRIl, 0, 1);
  numBytes += sVarf_init(&sVarf_vBpWzoU6, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_A9HTYzSU, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pyZZfptH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8AJMP40K, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_qHe5jBoB, -1740102572);
  numBytes += cSlice_init(&cSlice_EOhosbCo, 1, 1);
  numBytes += cPack_init(&cPack_QRhNxTSN, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_3g8H1dGZ, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_qJmq3A2A, "del-1023-inputdelay");
  numBytes += sVarf_init(&sVarf_kFbBqFl8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uEmZ2LaN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ozsTztvy, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_4MY4Kbci, "del-1023-outputdelay");
  numBytes += sVarf_init(&sVarf_rPko31Mz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_X9HwCqHk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DTLOL1Cv, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_dytksA9P, 0.0f);
  numBytes += cDelay_init(this, &cDelay_oQ3AoVyy, 0.0f);
  numBytes += hTable_init(&hTable_gH7P2gSB, 256);
  numBytes += cDelay_init(this, &cDelay_KhE39PBQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HCyGOWpg, 0.0f);
  numBytes += hTable_init(&hTable_u2b7yuxf, 256);
  numBytes += cVar_init_f(&cVar_eSXtuzBA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FUcaLSo1, 0.0f);
  numBytes += cVar_init_f(&cVar_88OJv8EM, 240.0f);
  numBytes += cBinop_init(&cBinop_WQtWchEA, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_oephqLrT, 0.0f);
  numBytes += cVar_init_f(&cVar_bdF5PqSA, 480.0f);
  numBytes += cBinop_init(&cBinop_x9Xcy9Ff, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_NICC9tTE, -1096485926);
  numBytes += cSlice_init(&cSlice_5kHx6kBn, 1, 1);
  numBytes += cPack_init(&cPack_MIBA5CVh, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_WICJFvIz, 4, 1);
  numBytes += cSlice_init(&cSlice_bJ4FlTxI, 3, 1);
  numBytes += cSlice_init(&cSlice_SGn7bGwD, 2, 1);
  numBytes += cSlice_init(&cSlice_kSS8wytf, 1, 1);
  numBytes += cSlice_init(&cSlice_VIFTYl72, 0, 1);
  numBytes += sVarf_init(&sVarf_ew5F5ivU, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_t049jOq9, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0zZS6kDo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_76qbg8Uv, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_wP8YUfGM, -920787555);
  numBytes += cSlice_init(&cSlice_BlyaWCE2, 1, 1);
  numBytes += cVar_init_f(&cVar_jcHUoXYG, 0.0f);
  numBytes += cVar_init_f(&cVar_gojWkxId, 0.0f);
  numBytes += cVar_init_f(&cVar_gzEwKqqy, 25.0f);
  numBytes += cVar_init_f(&cVar_QqlaXAMa, 32.0f);
  numBytes += cVar_init_f(&cVar_N5xWBXzM, 18.0f);
  numBytes += cVar_init_f(&cVar_iUfXwSgH, 110.0f);
  numBytes += cBinop_init(&cBinop_TpgTll92, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_YIQSgsWy, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_R7qUKWAw, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_O839pqGm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_EFKVzN8w, 4.0f);
  numBytes += cVar_init_f(&cVar_gDssJmht, 60.0f);
  numBytes += cVar_init_f(&cVar_tWx0tuKH, 150.0f);
  numBytes += cPack_init(&cPack_7xoxubrg, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_UY74B4g5, 500.0f);
  numBytes += cVar_init_f(&cVar_Hqzqifq9, 6.0f);
  numBytes += cSlice_init(&cSlice_fSN3tkW7, 2, 1);
  numBytes += cSlice_init(&cSlice_yRmg1ol5, 1, 1);
  numBytes += cSlice_init(&cSlice_C3mSF7Ja, 0, 1);
  numBytes += cSlice_init(&cSlice_Z1xg0Q6G, 1, -1);
  numBytes += cDelay_init(this, &cDelay_cJ4HYBtE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HySFq1WO, 0.0f);
  numBytes += cIf_init(&cIf_nMWtHVTV, false);
  numBytes += cSlice_init(&cSlice_lgFCxJPL, 1, -1);
  numBytes += cPack_init(&cPack_4iRW0EXG, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_BdMrbB3H, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kzHgpyMR, 0.0f);
  numBytes += cVar_init_f(&cVar_WboneOi1, 0.0f);
  numBytes += cBinop_init(&cBinop_QbgZd3nk, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_D4BhUksq, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_PFUEbTUl, 220.0f);
  numBytes += cVar_init_f(&cVar_OGDBkOh3, 6.0f);
  numBytes += cPack_init(&cPack_bNR6N8BI, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_BdgrR5OE, 30.0f);
  numBytes += cVar_init_f(&cVar_66kRJ4z3, 50.0f);
  numBytes += cVar_init_f(&cVar_eHQbCNmu, 500.0f);
  numBytes += cVar_init_f(&cVar_47vE0UTe, 110.0f);
  numBytes += cSlice_init(&cSlice_jRNXoXBR, 2, 1);
  numBytes += cSlice_init(&cSlice_uOmR58Jx, 1, 1);
  numBytes += cSlice_init(&cSlice_Ibrt4nId, 0, 1);
  numBytes += cSlice_init(&cSlice_YdWY2WHA, 1, -1);
  numBytes += cDelay_init(this, &cDelay_rBpRiJTV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_akZfJ3Rv, 0.0f);
  numBytes += cIf_init(&cIf_b1OKURPe, false);
  numBytes += cSlice_init(&cSlice_ZO2RJk55, 1, -1);
  numBytes += cPack_init(&cPack_DawPIxJp, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_cjPLXbRF, 2.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nniwqhhT, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_61isFFm3, 1.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_I1SnHKSl);
  cPack_free(&cPack_QRhNxTSN);
  cPack_free(&cPack_3g8H1dGZ);
  hTable_free(&hTable_gH7P2gSB);
  hTable_free(&hTable_u2b7yuxf);
  cPack_free(&cPack_MIBA5CVh);
  cPack_free(&cPack_7xoxubrg);
  cPack_free(&cPack_4iRW0EXG);
  cPack_free(&cPack_bNR6N8BI);
  cPack_free(&cPack_DawPIxJp);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7F849157: return &hTable_gH7P2gSB; // del-1023-inputdelay
    case 0x7CCDEFBD: return &hTable_u2b7yuxf; // del-1023-outputdelay
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8xNVoboW_sendMessage);
      break;
    }
    case 0xF7AB77BA: { // dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nZtQmmpM_sendMessage);
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


void Heavy_prog::cVar_heXYxN8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rS9cbkLw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_MapbpzqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_iEB7Zw70_sendMessage);
  cSwitchcase_j93npDg0_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_eHJfJe2U_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_iEB7Zw70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MapbpzqU, 1, m, &cVar_MapbpzqU_sendMessage);
}

void Heavy_prog::cVar_G0R4RCyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pFN6TTS5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OvDfnyYX_sendMessage);
}

void Heavy_prog::cSwitchcase_If30ICVi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dVYW4J1E, 0, m, &cSlice_dVYW4J1E_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AL6ThBUC, 0, m, &cRandom_AL6ThBUC_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_IFvR6IYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_SwdW32HA_sendMessage);
}

void Heavy_prog::cUnop_SwdW32HA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_heXYxN8M, 0, m, &cVar_heXYxN8M_sendMessage);
}

void Heavy_prog::cRandom_AL6ThBUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_IFvR6IYD_sendMessage);
}

void Heavy_prog::cSlice_dVYW4J1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AL6ThBUC, 1, m, &cRandom_AL6ThBUC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_m5iDwfmb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_l1kmoVfo, 0, m, &cSlice_l1kmoVfo_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1tbUJh7Z, 0, m, &cRandom_1tbUJh7Z_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_RFgF8nPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_kB20nyEn_sendMessage);
}

void Heavy_prog::cUnop_kB20nyEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jcHUoXYG, 0, m, &cVar_jcHUoXYG_sendMessage);
}

void Heavy_prog::cRandom_1tbUJh7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_RFgF8nPq_sendMessage);
}

void Heavy_prog::cSlice_l1kmoVfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1tbUJh7Z, 1, m, &cRandom_1tbUJh7Z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_I1SnHKSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GvJbaW1S_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_FR0jXv2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_vBpWzoU6, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Zn2Ww4NH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_8AJMP40K, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_w2HhWvr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_pyZZfptH, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_STh7fPrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZZbQSHmn, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_yAlIiRIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_esoeKcyU, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_LYLLY3QI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0QeaWoAm_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_0QeaWoAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_liNyaWrE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ue6BUfLl_sendMessage);
}

void Heavy_prog::cCast_liNyaWrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_ue6BUfLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pI0oN2SA_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_jSF3oUEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I1SnHKSl, 0, m, &cPack_I1SnHKSl_sendMessage);
}

void Heavy_prog::cCast_KXXiukDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A9HTYzSU, HV_BINOP_MULTIPLY, 0, m, &cBinop_A9HTYzSU_sendMessage);
}

void Heavy_prog::cMsg_pI0oN2SA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KXXiukDR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jSF3oUEe_sendMessage);
}

void Heavy_prog::cBinop_A9HTYzSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I1SnHKSl, 1, m, &cPack_I1SnHKSl_sendMessage);
}

void Heavy_prog::cBinop_OmdzDuE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A9HTYzSU, HV_BINOP_MULTIPLY, 1, m, &cBinop_A9HTYzSU_sendMessage);
}

void Heavy_prog::cMsg_t6RB5d01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_OmdzDuE5_sendMessage);
}

void Heavy_prog::cMsg_GvJbaW1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_l8OOe6K7, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_l8OOe6K7, 0, m, NULL);
}

void Heavy_prog::cMsg_jyxvP1df_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FR0jXv2B, 0, m, &cSlice_FR0jXv2B_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Zn2Ww4NH, 0, m, &cSlice_Zn2Ww4NH_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_w2HhWvr0, 0, m, &cSlice_w2HhWvr0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_STh7fPrV, 0, m, &cSlice_STh7fPrV_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yAlIiRIl, 0, m, &cSlice_yAlIiRIl_sendMessage);
}

void Heavy_prog::cSwitchcase_5mhTXtjX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EOhosbCo, 0, m, &cSlice_EOhosbCo_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qHe5jBoB, 0, m, &cRandom_qHe5jBoB_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_IHn7XtHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OHQnlC3d_sendMessage);
}

void Heavy_prog::cUnop_OHQnlC3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G0R4RCyd, 0, m, &cVar_G0R4RCyd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_cS0BcCtM_sendMessage);
}

void Heavy_prog::cRandom_qHe5jBoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_IHn7XtHj_sendMessage);
}

void Heavy_prog::cSlice_EOhosbCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qHe5jBoB, 1, m, &cRandom_qHe5jBoB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_QRhNxTSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OBT1ENbl, 0, m, NULL);
}

void Heavy_prog::cPack_3g8H1dGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pH3dBD1t, 0, m, NULL);
}

void Heavy_prog::cMsg_8jahPP5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_97aKql6b_sendMessage);
}

void Heavy_prog::cSystem_97aKql6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GNJ5kxuv_sendMessage);
}

void Heavy_prog::cVar_qJmq3A2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hfC9FOBt_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_Apd5myHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sAjFzkJ6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kFbBqFl8, m);
}

void Heavy_prog::cBinop_GNJ5kxuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uEmZ2LaN, m);
}

void Heavy_prog::cMsg_hfC9FOBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Apd5myHM_sendMessage);
}

void Heavy_prog::cBinop_sAjFzkJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ozsTztvy, m);
}

void Heavy_prog::cMsg_GQFAgvT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_82fXaxZu_sendMessage);
}

void Heavy_prog::cSystem_82fXaxZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_R98iaeDS_sendMessage);
}

void Heavy_prog::cVar_4MY4Kbci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v0g1seBh_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_2f15je2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_q4mNfRIS_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rPko31Mz, m);
}

void Heavy_prog::cBinop_R98iaeDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_X9HwCqHk, m);
}

void Heavy_prog::cMsg_v0g1seBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2f15je2v_sendMessage);
}

void Heavy_prog::cBinop_q4mNfRIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DTLOL1Cv, m);
}

void Heavy_prog::cMsg_CUzKxAfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_54BUPBUO_sendMessage);
}

void Heavy_prog::cSystem_54BUPBUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_05wAWeAl_sendMessage);
}

void Heavy_prog::cDelay_dytksA9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dytksA9P, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQ3AoVyy, 0, m, &cDelay_oQ3AoVyy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dytksA9P, 0, m, &cDelay_dytksA9P_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QkkdDpK6, 1, m, NULL);
}

void Heavy_prog::cDelay_oQ3AoVyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oQ3AoVyy, m);
  cMsg_X0PmTlfV_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_YG0dTK7C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jpx9GKo5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_Jcitmve9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RrZN3lm9_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_gH7P2gSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JD4vMGWz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dytksA9P, 2, m, &cDelay_dytksA9P_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JAxvcist_sendMessage);
}

void Heavy_prog::cMsg_RrZN3lm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gH7P2gSB, 0, m, &hTable_gH7P2gSB_sendMessage);
}

void Heavy_prog::cBinop_05wAWeAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_Jcitmve9_sendMessage);
}

void Heavy_prog::cMsg_X0PmTlfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gH7P2gSB, 0, m, &hTable_gH7P2gSB_sendMessage);
}

void Heavy_prog::cCast_JAxvcist_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dytksA9P, 0, m, &cDelay_dytksA9P_sendMessage);
}

void Heavy_prog::cMsg_JD4vMGWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQ3AoVyy, 2, m, &cDelay_oQ3AoVyy_sendMessage);
}

void Heavy_prog::cMsg_jpx9GKo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QkkdDpK6, 1, m, NULL);
}

void Heavy_prog::cMsg_cEG88g0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kBL0tN88_sendMessage);
}

void Heavy_prog::cSystem_kBL0tN88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_98TwF6kr_sendMessage);
}

void Heavy_prog::cDelay_KhE39PBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KhE39PBQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HCyGOWpg, 0, m, &cDelay_HCyGOWpg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KhE39PBQ, 0, m, &cDelay_KhE39PBQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5KLxyN5r, 1, m, NULL);
}

void Heavy_prog::cDelay_HCyGOWpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HCyGOWpg, m);
  cMsg_ghRVlRKA_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_H0muetNM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LxGU8JzW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_JOgrHrcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mVv6vkQ0_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_u2b7yuxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M4tGk102_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KhE39PBQ, 2, m, &cDelay_KhE39PBQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NXrrjXqi_sendMessage);
}

void Heavy_prog::cMsg_mVv6vkQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_u2b7yuxf, 0, m, &hTable_u2b7yuxf_sendMessage);
}

void Heavy_prog::cBinop_98TwF6kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_JOgrHrcn_sendMessage);
}

void Heavy_prog::cMsg_ghRVlRKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_u2b7yuxf, 0, m, &hTable_u2b7yuxf_sendMessage);
}

void Heavy_prog::cCast_NXrrjXqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KhE39PBQ, 0, m, &cDelay_KhE39PBQ_sendMessage);
}

void Heavy_prog::cMsg_M4tGk102_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_HCyGOWpg, 2, m, &cDelay_HCyGOWpg_sendMessage);
}

void Heavy_prog::cMsg_LxGU8JzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5KLxyN5r, 1, m, NULL);
}

void Heavy_prog::cBinop_jBHXkmBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5BqTkcNq_sendMessage);
}

void Heavy_prog::cBinop_5BqTkcNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TbowM1vp_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_vbiWorQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_H4xXhZVt_sendMessage);
}

void Heavy_prog::cBinop_H4xXhZVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QZMMXX1p_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_3kJsBIG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8I8ZJtWK_sendMessage);
}

void Heavy_prog::cBinop_8I8ZJtWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7s9rbV8Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lPeHp7yu_sendMessage);
}

void Heavy_prog::cMsg_QZMMXX1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_TKDFRDBs, 0, m, NULL);
}

void Heavy_prog::cMsg_TbowM1vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_zsq0816i, 0, m, NULL);
}

void Heavy_prog::cBinop_rRZ1v2oU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3g8H1dGZ, 0, m, &cPack_3g8H1dGZ_sendMessage);
}

void Heavy_prog::cBinop_ii1lfs1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QRhNxTSN, 0, m, &cPack_QRhNxTSN_sendMessage);
}

void Heavy_prog::cCast_7s9rbV8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3g8H1dGZ, 1, m, &cPack_3g8H1dGZ_sendMessage);
}

void Heavy_prog::cCast_lPeHp7yu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QRhNxTSN, 1, m, &cPack_QRhNxTSN_sendMessage);
}

void Heavy_prog::cMsg_5BGt46ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 50.0f, 0, m, &cBinop_ii1lfs1P_sendMessage);
}

void Heavy_prog::cMsg_6CHhtfCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 50.0f, 0, m, &cBinop_rRZ1v2oU_sendMessage);
}

void Heavy_prog::cMsg_FvmqkZon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.95f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_vbiWorQu_sendMessage);
}

void Heavy_prog::cVar_eSXtuzBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0GqbET2M_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QZJSRacX_sendMessage);
}

void Heavy_prog::cSwitchcase_j93npDg0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_bjNrth0M_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_bjNrth0M_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lOQYF0m5_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_FUcaLSo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FUcaLSo1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FUcaLSo1, 0, m, &cDelay_FUcaLSo1_sendMessage);
  cSwitchcase_m5iDwfmb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_5mhTXtjX_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_l5p6IGfz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_lOQYF0m5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bjNrth0M_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FUcaLSo1, 0, m, &cDelay_FUcaLSo1_sendMessage);
  cSwitchcase_m5iDwfmb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_5mhTXtjX_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_l5p6IGfz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_rza6pvay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0LBwFVmM_sendMessage);
}

void Heavy_prog::cSystem_0LBwFVmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A4X5OKZr_sendMessage);
}

void Heavy_prog::cVar_88OJv8EM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WQtWchEA, HV_BINOP_MULTIPLY, 0, m, &cBinop_WQtWchEA_sendMessage);
}

void Heavy_prog::cMsg_bjNrth0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FUcaLSo1, 0, m, &cDelay_FUcaLSo1_sendMessage);
}

void Heavy_prog::cBinop_FEWmxEHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FUcaLSo1, 2, m, &cDelay_FUcaLSo1_sendMessage);
}

void Heavy_prog::cBinop_A4X5OKZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WQtWchEA, HV_BINOP_MULTIPLY, 1, m, &cBinop_WQtWchEA_sendMessage);
}

void Heavy_prog::cBinop_WQtWchEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FEWmxEHY_sendMessage);
}

void Heavy_prog::cSwitchcase_eHJfJe2U_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Em5YVYaZ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Em5YVYaZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W63OBwuP_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_oephqLrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oephqLrT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oephqLrT, 0, m, &cDelay_oephqLrT_sendMessage);
  cSwitchcase_If30ICVi_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_3iI3My7H_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_W63OBwuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Em5YVYaZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oephqLrT, 0, m, &cDelay_oephqLrT_sendMessage);
  cSwitchcase_If30ICVi_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_3iI3My7H_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_j6twFruY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xf2zzCaN_sendMessage);
}

void Heavy_prog::cSystem_Xf2zzCaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BBEX1yRO_sendMessage);
}

void Heavy_prog::cVar_bdF5PqSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x9Xcy9Ff, HV_BINOP_MULTIPLY, 0, m, &cBinop_x9Xcy9Ff_sendMessage);
}

void Heavy_prog::cMsg_Em5YVYaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oephqLrT, 0, m, &cDelay_oephqLrT_sendMessage);
}

void Heavy_prog::cBinop_S4DiBeFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oephqLrT, 2, m, &cDelay_oephqLrT_sendMessage);
}

void Heavy_prog::cBinop_BBEX1yRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x9Xcy9Ff, HV_BINOP_MULTIPLY, 1, m, &cBinop_x9Xcy9Ff_sendMessage);
}

void Heavy_prog::cBinop_x9Xcy9Ff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_S4DiBeFh_sendMessage);
}

void Heavy_prog::cSwitchcase_3iI3My7H_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5kHx6kBn, 0, m, &cSlice_5kHx6kBn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NICC9tTE, 0, m, &cRandom_NICC9tTE_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_tK2LQjLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_H7lksc40_sendMessage);
}

void Heavy_prog::cUnop_H7lksc40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 60.0f, 0, m, &cBinop_smOxw0hW_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_8OG3PSbp_sendMessage);
}

void Heavy_prog::cRandom_NICC9tTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_tK2LQjLH_sendMessage);
}

void Heavy_prog::cSlice_5kHx6kBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NICC9tTE, 1, m, &cRandom_NICC9tTE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_MIBA5CVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EjxGWFAo_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_WICJFvIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_ew5F5ivU, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_bJ4FlTxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_76qbg8Uv, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_SGn7bGwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_0zZS6kDo, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_kSS8wytf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_b0l9SnWC, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_VIFTYl72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_rZDiezVj, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_1gbaFLF6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Td2Hj8eo_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_Td2Hj8eo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6YuwASNj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_75GH1RVg_sendMessage);
}

void Heavy_prog::cCast_6YuwASNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_75GH1RVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qsyuswTy_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_yrWdHe5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MIBA5CVh, 0, m, &cPack_MIBA5CVh_sendMessage);
}

void Heavy_prog::cCast_MlrzL9io_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t049jOq9, HV_BINOP_MULTIPLY, 0, m, &cBinop_t049jOq9_sendMessage);
}

void Heavy_prog::cMsg_qsyuswTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MlrzL9io_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yrWdHe5k_sendMessage);
}

void Heavy_prog::cBinop_t049jOq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MIBA5CVh, 1, m, &cPack_MIBA5CVh_sendMessage);
}

void Heavy_prog::cBinop_PeJzvEUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t049jOq9, HV_BINOP_MULTIPLY, 1, m, &cBinop_t049jOq9_sendMessage);
}

void Heavy_prog::cMsg_RB7i3Jhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_PeJzvEUx_sendMessage);
}

void Heavy_prog::cMsg_EjxGWFAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9RoNhLH8, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_9RoNhLH8, 0, m, NULL);
}

void Heavy_prog::cMsg_BvB8OqHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_WICJFvIz, 0, m, &cSlice_WICJFvIz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bJ4FlTxI, 0, m, &cSlice_bJ4FlTxI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SGn7bGwD, 0, m, &cSlice_SGn7bGwD_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kSS8wytf, 0, m, &cSlice_kSS8wytf_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VIFTYl72, 0, m, &cSlice_VIFTYl72_sendMessage);
}

void Heavy_prog::cSwitchcase_l5p6IGfz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BlyaWCE2, 0, m, &cSlice_BlyaWCE2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wP8YUfGM, 0, m, &cRandom_wP8YUfGM_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_PR0rbQ8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WWYFs1z7_sendMessage);
}

void Heavy_prog::cUnop_WWYFs1z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gojWkxId, 0, m, &cVar_gojWkxId_sendMessage);
}

void Heavy_prog::cRandom_wP8YUfGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_PR0rbQ8B_sendMessage);
}

void Heavy_prog::cSlice_BlyaWCE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wP8YUfGM, 1, m, &cRandom_wP8YUfGM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_jcHUoXYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LYLLY3QI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_gojWkxId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1gbaFLF6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_rS9cbkLw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0bv8mkcL_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YPMCP3aT_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mzDU6Vjx_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_0bv8mkcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o6Vvmwf6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FSjX7Xt8_sendMessage);
}

void Heavy_prog::cCast_YPMCP3aT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o9gzun55_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BlJPGVCr_sendMessage);
}

void Heavy_prog::cCast_mzDU6Vjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dEg6ooCs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X0WfU9hl_sendMessage);
}

void Heavy_prog::cVar_gzEwKqqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TpgTll92, HV_BINOP_DIVIDE, 1, m, &cBinop_TpgTll92_sendMessage);
}

void Heavy_prog::cVar_QqlaXAMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TpgTll92, HV_BINOP_DIVIDE, 1, m, &cBinop_TpgTll92_sendMessage);
}

void Heavy_prog::cVar_N5xWBXzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TpgTll92, HV_BINOP_DIVIDE, 1, m, &cBinop_TpgTll92_sendMessage);
}

void Heavy_prog::cVar_iUfXwSgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aWgzzCBa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VweHTFLo_sendMessage);
}

void Heavy_prog::cCast_VweHTFLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TpgTll92, HV_BINOP_DIVIDE, 0, m, &cBinop_TpgTll92_sendMessage);
}

void Heavy_prog::cCast_aWgzzCBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Edv4tPqT_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_TpgTll92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YIQSgsWy, m);
}

void Heavy_prog::cCast_dEg6ooCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N5xWBXzM, 0, m, &cVar_N5xWBXzM_sendMessage);
}

void Heavy_prog::cCast_X0WfU9hl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iUfXwSgH, 0, m, &cVar_iUfXwSgH_sendMessage);
}

void Heavy_prog::cCast_BlJPGVCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iUfXwSgH, 0, m, &cVar_iUfXwSgH_sendMessage);
}

void Heavy_prog::cCast_o9gzun55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QqlaXAMa, 0, m, &cVar_QqlaXAMa_sendMessage);
}

void Heavy_prog::cCast_o6Vvmwf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gzEwKqqy, 0, m, &cVar_gzEwKqqy_sendMessage);
}

void Heavy_prog::cCast_FSjX7Xt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iUfXwSgH, 0, m, &cVar_iUfXwSgH_sendMessage);
}

void Heavy_prog::cMsg_Edv4tPqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EXIjPF3w, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_EXIjPF3w, 0, m, NULL);
}

void Heavy_prog::cBinop_af9Gd7Q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O839pqGm, m);
}

void Heavy_prog::cBinop_b1mBt8zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Mrw1y38V_sendMessage);
}

void Heavy_prog::cBinop_Mrw1y38V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R7qUKWAw, HV_BINOP_POW, 1, m, &cBinop_R7qUKWAw_sendMessage);
  cMsg_JSWkBKyX_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_R7qUKWAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_af9Gd7Q7_sendMessage);
}

void Heavy_prog::cMsg_JSWkBKyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R7qUKWAw, HV_BINOP_POW, 0, m, &cBinop_R7qUKWAw_sendMessage);
}

void Heavy_prog::cBinop_zO6CU3Kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_BT1h409M_sendMessage);
}

void Heavy_prog::cBinop_BT1h409M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BdMrbB3H, m);
}

void Heavy_prog::cBinop_X0kHkpMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_KosRBI1E_sendMessage);
}

void Heavy_prog::cBinop_KosRBI1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wZEYVwiX_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_EFKVzN8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_zO6CU3Kf_sendMessage);
}

void Heavy_prog::cVar_gDssJmht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_X0kHkpMw_sendMessage);
}

void Heavy_prog::cVar_tWx0tuKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7xoxubrg, 0, m, &cPack_7xoxubrg_sendMessage);
}

void Heavy_prog::cPack_7xoxubrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aMpQwYaa_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_UY74B4g5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7xoxubrg, 2, m, &cPack_7xoxubrg_sendMessage);
}

void Heavy_prog::cVar_Hqzqifq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7xoxubrg, 1, m, &cPack_7xoxubrg_sendMessage);
}

void Heavy_prog::cSlice_fSN3tkW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_cJ4HYBtE, 1, m, &cDelay_cJ4HYBtE_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HySFq1WO, 1, m, &cDelay_HySFq1WO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_yRmg1ol5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MhMke394_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_frWLYf4p_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_C3mSF7Ja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_6EVdmcU5_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_tWhaXWpb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Z1xg0Q6G, 0, m, &cSlice_Z1xg0Q6G_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZrxsLhcf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fSN3tkW7, 0, m, &cSlice_fSN3tkW7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_yRmg1ol5, 0, m, &cSlice_yRmg1ol5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_C3mSF7Ja, 0, m, &cSlice_C3mSF7Ja_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_Z1xg0Q6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uwTg0iTE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VUYxX0zl_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uwTg0iTE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VUYxX0zl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_cJ4HYBtE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cJ4HYBtE, m);
  cPack_onMessage(_c, &Context(_c)->cPack_4iRW0EXG, 0, m, &cPack_4iRW0EXG_sendMessage);
  cMsg_E1BMLqLO_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_HySFq1WO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HySFq1WO, m);
  cPack_onMessage(_c, &Context(_c)->cPack_4iRW0EXG, 1, m, &cPack_4iRW0EXG_sendMessage);
}

void Heavy_prog::cIf_nMWtHVTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_HySFq1WO, 0, m, &cDelay_HySFq1WO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_6EVdmcU5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lgFCxJPL, 0, m, &cSlice_lgFCxJPL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5VCYwFXe_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9NM8HU6M_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_lgFCxJPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pAc0FkJL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_pAc0FkJL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_E1BMLqLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_nMWtHVTV, 1, m, &cIf_nMWtHVTV_sendMessage);
}

void Heavy_prog::cMsg_S05IOT4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_nMWtHVTV, 1, m, &cIf_nMWtHVTV_sendMessage);
}

void Heavy_prog::cCast_5VCYwFXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nMWtHVTV, 0, m, &cIf_nMWtHVTV_sendMessage);
}

void Heavy_prog::cCast_9NM8HU6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cJ4HYBtE, 0, m, &cDelay_cJ4HYBtE_sendMessage);
}

void Heavy_prog::cCast_frWLYf4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S05IOT4l_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_MhMke394_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HySFq1WO, 0, m, &cDelay_HySFq1WO_sendMessage);
}

void Heavy_prog::cMsg_pAc0FkJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HySFq1WO, 0, m, &cDelay_HySFq1WO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cJ4HYBtE, 0, m, &cDelay_cJ4HYBtE_sendMessage);
}

void Heavy_prog::cPack_4iRW0EXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TT4O0ROg, 0, m, NULL);
}

void Heavy_prog::cCast_ZrxsLhcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UHIKflIN_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_UHIKflIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cJ4HYBtE, 1, m, &cDelay_cJ4HYBtE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HySFq1WO, 1, m, &cDelay_HySFq1WO_sendMessage);
}

void Heavy_prog::cMsg_WBzsOJX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_TT4O0ROg, 0, m, NULL);
}

void Heavy_prog::cCast_uwTg0iTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4CzAjRIS_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_VUYxX0zl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WBzsOJX4_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_4CzAjRIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_6EVdmcU5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_wZEYVwiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 50.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Y1BpJ4ki, 0, m, NULL);
}

void Heavy_prog::cCast_OvDfnyYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_b1mBt8zt_sendMessage);
}

void Heavy_prog::cCast_pFN6TTS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oeFXVddX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xiCBonYx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_501NwKHf_sendMessage);
}

void Heavy_prog::cCast_xiCBonYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hqzqifq9, 0, m, &cVar_Hqzqifq9_sendMessage);
}

void Heavy_prog::cCast_oeFXVddX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UY74B4g5, 0, m, &cVar_UY74B4g5_sendMessage);
}

void Heavy_prog::cCast_501NwKHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tWx0tuKH, 0, m, &cVar_tWx0tuKH_sendMessage);
}

void Heavy_prog::cMsg_aMpQwYaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_tWhaXWpb_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_tWhaXWpb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_kzHgpyMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_3kJsBIG9_sendMessage);
}

void Heavy_prog::cVar_WboneOi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_jBHXkmBI_sendMessage);
}

void Heavy_prog::cBinop_OhV6eJJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D4BhUksq, m);
}

void Heavy_prog::cBinop_Wy8hzqdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_q5fp44WE_sendMessage);
}

void Heavy_prog::cBinop_q5fp44WE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbgZd3nk, HV_BINOP_POW, 1, m, &cBinop_QbgZd3nk_sendMessage);
  cMsg_Jc89JRlG_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_QbgZd3nk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_OhV6eJJe_sendMessage);
}

void Heavy_prog::cMsg_Jc89JRlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbgZd3nk, HV_BINOP_POW, 0, m, &cBinop_QbgZd3nk_sendMessage);
}

void Heavy_prog::cBinop_kDRaA5Zd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_PFbKJ8b0_sendMessage);
}

void Heavy_prog::cBinop_PFbKJ8b0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_61isFFm3, m);
}

void Heavy_prog::cBinop_isHSz0FO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_elwZhyM8_sendMessage);
}

void Heavy_prog::cBinop_elwZhyM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cjPLXbRF, m);
}

void Heavy_prog::cVar_PFUEbTUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_kDRaA5Zd_sendMessage);
}

void Heavy_prog::cVar_OGDBkOh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_isHSz0FO_sendMessage);
}

void Heavy_prog::cPack_bNR6N8BI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1BKP6GWs_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_BdgrR5OE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bNR6N8BI, 2, m, &cPack_bNR6N8BI_sendMessage);
}

void Heavy_prog::cVar_66kRJ4z3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bNR6N8BI, 1, m, &cPack_bNR6N8BI_sendMessage);
}

void Heavy_prog::cVar_eHQbCNmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bNR6N8BI, 0, m, &cPack_bNR6N8BI_sendMessage);
}

void Heavy_prog::cVar_47vE0UTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_H1nNaYMh_sendMessage);
}

void Heavy_prog::cBinop_H1nNaYMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fM5n5D8X_sendMessage);
}

void Heavy_prog::cBinop_fM5n5D8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nniwqhhT, m);
}

void Heavy_prog::cSlice_jRNXoXBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_rBpRiJTV, 1, m, &cDelay_rBpRiJTV_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_akZfJ3Rv, 1, m, &cDelay_akZfJ3Rv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_uOmR58Jx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DrKOd84k_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jsj9qtF2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Ibrt4nId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_Kdo9QnnB_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_MiYna9et_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YdWY2WHA, 0, m, &cSlice_YdWY2WHA_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bx2Wg4C6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_jRNXoXBR, 0, m, &cSlice_jRNXoXBR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uOmR58Jx, 0, m, &cSlice_uOmR58Jx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ibrt4nId, 0, m, &cSlice_Ibrt4nId_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_YdWY2WHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mg7M1I0d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HsNxiDHh_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mg7M1I0d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HsNxiDHh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_rBpRiJTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rBpRiJTV, m);
  cPack_onMessage(_c, &Context(_c)->cPack_DawPIxJp, 0, m, &cPack_DawPIxJp_sendMessage);
  cMsg_UmgYpJ0X_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_akZfJ3Rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_akZfJ3Rv, m);
  cPack_onMessage(_c, &Context(_c)->cPack_DawPIxJp, 1, m, &cPack_DawPIxJp_sendMessage);
}

void Heavy_prog::cIf_b1OKURPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_akZfJ3Rv, 0, m, &cDelay_akZfJ3Rv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_Kdo9QnnB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZO2RJk55, 0, m, &cSlice_ZO2RJk55_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7GokFokQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2R0ZGgM6_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_ZO2RJk55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Gjhyfbs5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Gjhyfbs5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_UmgYpJ0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_b1OKURPe, 1, m, &cIf_b1OKURPe_sendMessage);
}

void Heavy_prog::cMsg_TeIC2Log_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_b1OKURPe, 1, m, &cIf_b1OKURPe_sendMessage);
}

void Heavy_prog::cCast_2R0ZGgM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rBpRiJTV, 0, m, &cDelay_rBpRiJTV_sendMessage);
}

void Heavy_prog::cCast_7GokFokQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b1OKURPe, 0, m, &cIf_b1OKURPe_sendMessage);
}

void Heavy_prog::cCast_jsj9qtF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TeIC2Log_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_DrKOd84k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_akZfJ3Rv, 0, m, &cDelay_akZfJ3Rv_sendMessage);
}

void Heavy_prog::cMsg_Gjhyfbs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_akZfJ3Rv, 0, m, &cDelay_akZfJ3Rv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rBpRiJTV, 0, m, &cDelay_rBpRiJTV_sendMessage);
}

void Heavy_prog::cPack_DawPIxJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_aionPTXp, 0, m, NULL);
}

void Heavy_prog::cCast_bx2Wg4C6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XPnotKhZ_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_XPnotKhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rBpRiJTV, 1, m, &cDelay_rBpRiJTV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_akZfJ3Rv, 1, m, &cDelay_akZfJ3Rv_sendMessage);
}

void Heavy_prog::cMsg_5JvvvsnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_aionPTXp, 0, m, NULL);
}

void Heavy_prog::cCast_HsNxiDHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5JvvvsnF_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_mg7M1I0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WLliidlz_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_WLliidlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_Kdo9QnnB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_QZJSRacX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Wy8hzqdF_sendMessage);
}

void Heavy_prog::cCast_0GqbET2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RIkc2DWs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yLuPbb3d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hHqN88GG_sendMessage);
}

void Heavy_prog::cCast_yLuPbb3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_66kRJ4z3, 0, m, &cVar_66kRJ4z3_sendMessage);
}

void Heavy_prog::cCast_hHqN88GG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eHQbCNmu, 0, m, &cVar_eHQbCNmu_sendMessage);
}

void Heavy_prog::cCast_RIkc2DWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BdgrR5OE, 0, m, &cVar_BdgrR5OE_sendMessage);
}

void Heavy_prog::cMsg_1BKP6GWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_MiYna9et_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_MiYna9et_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_smOxw0hW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eSXtuzBA, 0, m, &cVar_eSXtuzBA_sendMessage);
}

void Heavy_prog::cBinop_cS0BcCtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kzHgpyMR, 0, m, &cVar_kzHgpyMR_sendMessage);
}

void Heavy_prog::cBinop_8OG3PSbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WboneOi1, 0, m, &cVar_WboneOi1_sendMessage);
}

void Heavy_prog::cReceive_8xNVoboW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CUzKxAfP_sendMessage(_c, 0, m);
  cMsg_cEG88g0p_sendMessage(_c, 0, m);
  cMsg_t6RB5d01_sendMessage(_c, 0, m);
  cMsg_jyxvP1df_sendMessage(_c, 0, m);
  cMsg_5BGt46ig_sendMessage(_c, 0, m);
  cMsg_6CHhtfCc_sendMessage(_c, 0, m);
  cMsg_FvmqkZon_sendMessage(_c, 0, m);
  cMsg_rza6pvay_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_88OJv8EM, 0, m, &cVar_88OJv8EM_sendMessage);
  cMsg_j6twFruY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bdF5PqSA, 0, m, &cVar_bdF5PqSA_sendMessage);
  cMsg_RB7i3Jhi_sendMessage(_c, 0, m);
  cMsg_BvB8OqHO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EFKVzN8w, 0, m, &cVar_EFKVzN8w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gDssJmht, 0, m, &cVar_gDssJmht_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PFUEbTUl, 0, m, &cVar_PFUEbTUl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OGDBkOh3, 0, m, &cVar_OGDBkOh3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_47vE0UTe, 0, m, &cVar_47vE0UTe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MapbpzqU, 0, m, &cVar_MapbpzqU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qJmq3A2A, 0, m, &cVar_qJmq3A2A_sendMessage);
  cMsg_8jahPP5k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4MY4Kbci, 0, m, &cVar_4MY4Kbci_sendMessage);
  cMsg_GQFAgvT2_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_nZtQmmpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BdgrR5OE, 1, m, &cVar_BdgrR5OE_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10;
  hv_bufferi_t Bi0, Bi1;

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
    __hv_varread_f(&sVarf_O839pqGm, VOf(Bf0));
    __hv_varread_f(&sVarf_BdMrbB3H, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_KVEOvBK3, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_Y1BpJ4ki, VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_wxNeD3Ib, VIf(Bf0), VOf(Bf0));
    __hv_neg_f(VIf(Bf0), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_min_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf3), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_TT4O0ROg, VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_pow_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_var_k_f(VOf(Bf0), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_phasor_k_f(&sPhasor_rZDiezVj, VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_b0l9SnWC, VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_9RoNhLH8, VOf(Bf4));
    __hv_varread_f(&sVarf_0zZS6kDo, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_76qbg8Uv, VOf(Bf6));
    __hv_varread_f(&sVarf_ew5F5ivU, VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_f(&sPhasor_FPSv2XpK, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_D4BhUksq, VOf(Bf6));
    __hv_varread_f(&sVarf_61isFFm3, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_vgRCcZ58, VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cjPLXbRF, VOf(Bf5));
    __hv_varread_f(&sVarf_nniwqhhT, VOf(Bf7));
    __hv_fms_f(VIf(Bf1), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_u3TaaAiL, VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_min_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf5), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_aionPTXp, VOf(Bf7));
    __hv_zero_f(VOf(Bf5));
    __hv_pow_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_esoeKcyU, VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_ZZbQSHmn, VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_l8OOe6K7, VOf(Bf5));
    __hv_varread_f(&sVarf_pyZZfptH, VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_8AJMP40K, VOf(Bf1));
    __hv_varread_f(&sVarf_vBpWzoU6, VOf(Bf7));
    __hv_fma_f(VIf(Bf9), VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_jaAH7EqE, VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_OBT1ENbl, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_8e94KVJt, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_uEmZ2LaN, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ozsTztvy, VOf(Bf0));
    __hv_min_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_varread_f(&sVarf_kFbBqFl8, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_4stW0jBp, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_RdmQiNtP, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_zsq0816i, VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf6), VOf(Bf4));
    __hv_line_f(&sLine_pH3dBD1t, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_M701P5zx, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_X9HwCqHk, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_DTLOL1Cv, VOf(Bf0));
    __hv_min_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf5));
    __hv_varread_f(&sVarf_rPko31Mz, VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_RmAx14Rt, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_IKc9o2cl, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_TKDFRDBs, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_QkkdDpK6, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_5KLxyN5r, VIf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_line_f(&sLine_EXIjPF3w, VOf(Bf4));
    __hv_varread_f(&sVarf_YIQSgsWy, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf4), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_var_k_f(VOf(Bf6), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));

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
