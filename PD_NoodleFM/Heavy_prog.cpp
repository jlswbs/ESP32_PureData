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
 * Table Data
 */

float hTable_jCCDVWQI_data[256] = {0.643333f, 0.693333f, 0.703333f, 0.72f, 0.734444f, 0.738889f, 0.743333f, 0.75f, 0.756667f, 0.762222f, 0.767778f, 0.773333f, 0.78f, 0.786667f, 0.793333f, 0.8f, 0.808333f, 0.816667f, 0.825f, 0.833333f, 0.843333f, 0.853333f, 0.858333f, 0.863333f, 0.873333f, 0.883333f, 0.885f, 0.886667f, 0.896667f, 0.896667f, 0.898333f, 0.9f, 0.903333f, 0.906667f, 0.906667f, 0.906667f, 0.908333f, 0.91f, 0.91f, 0.91f, 0.913333f, 0.916667f, 0.918333f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.916667f, 0.913333f, 0.91f, 0.907333f, 0.904666f, 0.902f, 0.899333f, 0.896667f, 0.895f, 0.893333f, 0.891667f, 0.89f, 0.889167f, 0.888333f, 0.8875f, 0.886666f, 0.885555f, 0.884444f, 0.883333f, 0.882222f, 0.881111f, 0.88f, 0.878333f, 0.876667f, 0.876667f, 0.873333f, 0.87f, 0.866667f, 0.863333f, 0.86f, 0.858333f, 0.856667f, 0.855f, 0.853333f, 0.85f, 0.846667f, 0.843333f, 0.84f, 0.836667f, 0.833333f, 0.831667f, 0.83f, 0.828333f, 0.826667f, 0.825f, 0.823333f, 0.820555f, 0.817778f, 0.815f, 0.812222f, 0.809444f, 0.806667f, 0.802667f, 0.798667f, 0.794667f, 0.790667f, 0.786667f, 0.783889f, 0.781111f, 0.778333f, 0.775555f, 0.772778f, 0.77f, 0.766667f, 0.763333f, 0.76f, 0.756667f, 0.753333f, 0.75f, 0.746667f, 0.743333f, 0.74f, 0.736667f, 0.733333f, 0.73f, 0.726667f, 0.723333f, 0.72f, 0.716667f, 0.711111f, 0.705556f, 0.7f, 0.693333f, 0.686667f, 0.68f, 0.674445f, 0.668889f, 0.663333f, 0.655f, 0.646667f, 0.636667f, 0.626667f, 0.621111f, 0.615556f, 0.61f, 0.6f, 0.59f, 0.58f, 0.571667f, 0.563333f, 0.558f, 0.552667f, 0.547333f, 0.542f, 0.536667f, 0.533334f, 0.53f, 0.526667f, 0.523334f, 0.52f, 0.516667f, 0.511667f, 0.506667f, 0.501667f, 0.496667f, 0.492667f, 0.488667f, 0.484667f, 0.480667f, 0.476667f, 0.471667f, 0.466667f, 0.461667f, 0.456667f, 0.451334f, 0.446f, 0.440667f, 0.435334f, 0.43f, 0.424445f, 0.418889f, 0.413334f, 0.408889f, 0.404445f, 0.396667f, 0.383334f, 0.38f, 0.373334f, 0.366667f, 0.36f, 0.346667f, 0.341667f, 0.336667f, 0.331667f, 0.326667f, 0.322223f, 0.317778f, 0.313334f, 0.307778f, 0.302223f, 0.296667f, 0.291667f, 0.286667f, 0.28f, 0.278334f, 0.276667f, 0.256667f, 0.246667f, 0.238334f, 0.23f, 0.220001f, 0.216667f, 0.200001f, 0.196667f, 0.186667f, 0.176667f, 0.175001f, 0.170001f, 0.160001f, 0.156667f, 0.151667f, 0.146667f, 0.130001f, 0.123334f, 0.106667f, 0.103333f, 0.103333f, 0.1f, 0.0966667f, 0.095f, 0.0933334f, 0.0911111f, 0.0888889f, 0.0866667f, 0.085f, 0.0833334f, 0.08f, 0.0766667f, 0.0666667f, 0.0666667f, 0.0666667f, 0.0666667f, 0.065f, 0.06f, 0.0566667f, 0.0533333f, 0.0533333f, 0.0333334f};
float hTable_iCtzOTOf_data[256] = {0.0666637f, 0.0685156f, 0.0703675f, 0.0722193f, 0.0740712f, 0.075923f, 0.333332f, 0.333332f, 0.333332f, 0.333332f, 0.333332f, 0.333332f, 0.466667f, 0.466667f, 0.466667f, 0.466667f, 0.466667f, 0.386667f, 0.395556f, 0.404444f, 0.413333f, 0.433333f, 0.453333f, 0.476667f, 0.5f, 0.528333f, 0.556666f, 0.626666f, 0.676666f, 0.695f, 0.713333f, 0.725f, 0.74f, 0.75f, 0.75f, 0.746666f, 0.743333f, 0.706666f, 0.693333f, 0.68f, 0.663333f, 0.646666f, 0.63f, 0.613333f, 0.585f, 0.556667f, 0.541111f, 0.525555f, 0.51f, 0.500833f, 0.491667f, 0.4825f, 0.473333f, 0.465555f, 0.457778f, 0.45f, 0.436667f, 0.433333f, 0.426667f, 0.42f, 0.42f, 0.42f, 0.424f, 0.428f, 0.432f, 0.436f, 0.44f, 0.445f, 0.45f, 0.455f, 0.46f, 0.465f, 0.47f, 0.477143f, 0.484286f, 0.491428f, 0.498571f, 0.505714f, 0.512857f, 0.52f, 0.53f, 0.54f, 0.55f, 0.56f, 0.57f, 0.58f, 0.59f, 0.606666f, 0.623333f, 0.64f, 0.657778f, 0.675555f, 0.466667f, 0.456667f, 0.446667f, 0.445556f, 0.444444f, 0.443333f, 0.441667f, 0.44f, 0.44f, 0.44f, 0.44f, 0.44f, 0.44f, 0.44f, 0.440833f, 0.441667f, 0.4425f, 0.443333f, 0.446667f, 0.45f, 0.453333f, 0.456667f, 0.46f, 0.466f, 0.472f, 0.478f, 0.484f, 0.49f, 0.499167f, 0.508333f, 0.5175f, 0.526666f, 0.538889f, 0.551111f, 0.563333f, 0.456667f, 0.44f, 0.423333f, 0.411667f, 0.4f, 0.394444f, 0.388889f, 0.383333f, 0.376667f, 0.37f, 0.368333f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.371667f, 0.376667f, 0.381667f, 0.386667f, 0.3925f, 0.398333f, 0.404167f, 0.41f, 0.419333f, 0.428667f, 0.438f, 0.447333f, 0.456667f, 0.470833f, 0.485f, 0.499167f, 0.513333f, 0.533333f, 0.553333f, 0.573333f, 0.593333f, 0.636666f, 0.68f, 0.718333f, 0.756666f, 0.793333f, 0.82f, 0.776666f, 0.493333f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.479444f, 0.482222f, 0.485f, 0.487778f, 0.490555f, 0.493333f, 0.496111f, 0.498889f, 0.501667f, 0.504444f, 0.507222f, 0.51f, 0.515f, 0.52f, 0.525f, 0.53f, 0.535f, 0.54f, 0.551111f, 0.562222f, 0.573333f, 0.591666f, 0.46f, 0.45f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.448333f, 0.45f, 0.456667f, 0.456667f, 0.448333f, 0.44f, 0.42f, 0.408333f, 0.396667f, 0.386667f, 0.376667f, 0.373333f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.373333f, 0.38f, 0.38f, 0.38f, 0.383333f, 0.385f, 0.386667f, 0.39f, 0.391667f, 0.393333f, 0.396667f, 0.403333f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_1hPHYRCe, 220.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_R5MIhdk9, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_gCavYMUi, &hTable_jCCDVWQI, false);
  numBytes += sRPole_init(&sRPole_BzrGQPBH);
  numBytes += sPhasor_k_init(&sPhasor_ZMhDY3Gp, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_wwaYJPIN);
  numBytes += sSamphold_init(&sSamphold_CHzzCTd1);
  numBytes += sPhasor_k_init(&sPhasor_gnb4NNin, 110.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_mX0IMNqq, sampleRate);
  numBytes += sTabread_init(&sTabread_3rH5YBA9, &hTable_jCCDVWQI, false);
  numBytes += sDel1_init(&sDel1_D5yeXuPo);
  numBytes += sSamphold_init(&sSamphold_KqL8alVT);
  numBytes += sPhasor_init(&sPhasor_Lc8M1ZOl, sampleRate);
  numBytes += sPhasor_init(&sPhasor_MnSCPKGK, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_pMCXnglZ, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_zBR7tNNi, &hTable_jCCDVWQI, false);
  numBytes += sRPole_init(&sRPole_GleC6YyZ);
  numBytes += sTabread_init(&sTabread_jZxQYrKW, &hTable_iCtzOTOf, false);
  numBytes += sPhasor_init(&sPhasor_VP39BkkG, sampleRate);
  numBytes += hTable_initWithData(&hTable_jCCDVWQI, 256, hTable_jCCDVWQI_data);
  numBytes += cRandom_init(&cRandom_Sh4Fncxx, 1200872672);
  numBytes += cSlice_init(&cSlice_mT8lEY5R, 1, 1);
  numBytes += sVari_init(&sVari_3GECHzGw, 0, 0, false);
  numBytes += cVar_init_s(&cVar_VaQy0tNm, "soft");
  numBytes += cSlice_init(&cSlice_WRhIDnPD, 1, 1);
  numBytes += sVarf_init(&sVarf_RxGJSywu, 0.0f, 0.0f, false);
  numBytes += hTable_initWithData(&hTable_iCtzOTOf, 256, hTable_iCtzOTOf_data);
  numBytes += cVar_init_s(&cVar_i78GeMpw, "hard");
  numBytes += cSlice_init(&cSlice_c8z323Bj, 1, 1);
  numBytes += sVarf_init(&sVarf_AGV1Z0H0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VNUlLlgI, 1.0f);
  numBytes += cVar_init_f(&cVar_mD9pdlgW, 0.0f);
  numBytes += cVar_init_f(&cVar_z4NSS9rp, 0.0f);
  numBytes += cVar_init_f(&cVar_oQmdBjSK, 0.0f);
  numBytes += cVar_init_s(&cVar_6KhSksuV, "soft");
  numBytes += cSlice_init(&cSlice_c6mfptmw, 1, 1);
  numBytes += sVarf_init(&sVarf_oEa2iozi, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_HvWpsfiw, 0.0f);
  numBytes += cVar_init_f(&cVar_sV9Co62c, 20.0f);
  numBytes += cBinop_init(&cBinop_fG8g1Ig1, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_351a7eub, 0.0f);
  numBytes += cSlice_init(&cSlice_9KrHcYAs, 1, -1);
  numBytes += cSlice_init(&cSlice_YPSNUbpJ, 1, -1);
  numBytes += cVar_init_f(&cVar_Ul5MLxT8, 0.0f);
  numBytes += cVar_init_f(&cVar_28q3Gucu, 1.0f);
  numBytes += cVar_init_f(&cVar_OjFjFYEg, 0.0f);
  numBytes += cVar_init_f(&cVar_Ep2VcbB4, 0.0f);
  numBytes += cVar_init_f(&cVar_WuOy1exi, 0.0f);
  numBytes += cSlice_init(&cSlice_sAKwJVdg, 1, 1);
  numBytes += cSlice_init(&cSlice_YpVNc6ZO, 0, 1);
  numBytes += cBinop_init(&cBinop_ExATSVZq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sOZwtyCe, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0tVtvBif, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rKiwoRCC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_8HGz5QCr, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_mcsLm02D, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xiNU2vrg, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zH0B4cQ4, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_Tfk04EG1, 0.0f);
  numBytes += cVar_init_f(&cVar_bLxrB8TK, 0.0f);
  numBytes += cVar_init_f(&cVar_q7EZ2IXQ, 22050.0f);
  numBytes += cBinop_init(&cBinop_YHMX96v8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kmiEHq0F, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DgyRxLke, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_NLCcHSen, "soft");
  numBytes += cSlice_init(&cSlice_5ZapETkv, 1, 1);
  numBytes += sVarf_init(&sVarf_RIL1ZuxN, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_NvNGczAT, 0.0f);
  numBytes += cVar_init_f(&cVar_8HIZP3Wx, 20.0f);
  numBytes += cBinop_init(&cBinop_PhtzFj9H, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lRcGpdft, 0.0f);
  numBytes += cSlice_init(&cSlice_WCspljmO, 1, -1);
  numBytes += cSlice_init(&cSlice_4JvOM7Lu, 1, -1);
  numBytes += cVar_init_f(&cVar_T1cj9KUs, 0.0f);
  numBytes += cVar_init_f(&cVar_x0dYeFiy, 1.0f);
  numBytes += cVar_init_f(&cVar_1cKuofcp, 0.0f);
  numBytes += cVar_init_f(&cVar_J17DPHr2, 0.0f);
  numBytes += cVar_init_f(&cVar_rWob9zZw, 0.0f);
  numBytes += cSlice_init(&cSlice_hSlPUeF2, 1, 1);
  numBytes += cSlice_init(&cSlice_4VYkSVbh, 0, 1);
  numBytes += cBinop_init(&cBinop_h71d0rwt, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3Uc2Yd0l, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zwe0S00z, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jDVmQqVc, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lbSuZ1GZ, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_k1kMJZMc, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_UDQYYpCE, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XojsP7l7, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_b1jLgKW8, 0.0f);
  numBytes += cVar_init_f(&cVar_fJlCB5Q3, 0.0f);
  numBytes += cVar_init_f(&cVar_ZDXrelO6, 22050.0f);
  numBytes += cBinop_init(&cBinop_H7hZlj8r, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_B9h1LePy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_u6NGvTFr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hKpIuWB2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aa1RAOoK, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_rLyKpXYj, 0.0f);
  numBytes += cVar_init_f(&cVar_x8TXmBWB, 30.0f);
  numBytes += cBinop_init(&cBinop_YSURqAde, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_BPyGLp9a, 173304223);
  numBytes += cSlice_init(&cSlice_H9SEGXap, 1, 1);
  numBytes += cRandom_init(&cRandom_NLtOyXIw, -169681036);
  numBytes += cSlice_init(&cSlice_9BjPBoFR, 1, 1);
  numBytes += cRandom_init(&cRandom_1fl30dN0, 1448243413);
  numBytes += cSlice_init(&cSlice_OpRx6UWG, 1, 1);
  numBytes += sVarf_init(&sVarf_0PgfG2og, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hBfTf7cP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xJBVVo8G, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ubGYPnNy, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_jCCDVWQI);
  hTable_free(&hTable_iCtzOTOf);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x69706D21: return &hTable_jCCDVWQI; // soft
    case 0x726EF81D: return &hTable_iCtzOTOf; // hard
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lNAsSoTv_sendMessage);
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


void Heavy_prog::hTable_jCCDVWQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_54BRwOFy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mT8lEY5R, 0, m, &cSlice_mT8lEY5R_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Sh4Fncxx, 0, m, &cRandom_Sh4Fncxx_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_MDdF8jov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tFOWnE2l_sendMessage);
}

void Heavy_prog::cUnop_tFOWnE2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hW0ORePN_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_Sh4Fncxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_MDdF8jov_sendMessage);
}

void Heavy_prog::cSlice_mT8lEY5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Sh4Fncxx, 1, m, &cRandom_Sh4Fncxx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_hW0ORePN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_3GECHzGw, m);
}

void Heavy_prog::cSwitchcase_qLhvxmzd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WRhIDnPD, 0, m, &cSlice_WRhIDnPD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_VaQy0tNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9OeJCsHq_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_566Lo9Db_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_c7Tle2Ix_sendMessage);
}

void Heavy_prog::cMsg_9OeJCsHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_566Lo9Db_sendMessage);
}

void Heavy_prog::cSlice_WRhIDnPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_3rH5YBA9, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_VaQy0tNm, 0, m, &cVar_VaQy0tNm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_c7Tle2Ix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RxGJSywu, m);
}

void Heavy_prog::hTable_iCtzOTOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_ToHpvWyD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_c8z323Bj, 0, m, &cSlice_c8z323Bj_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_i78GeMpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VVt5I32A_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_RtxuyZnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Q0WVtELO_sendMessage);
}

void Heavy_prog::cMsg_VVt5I32A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RtxuyZnM_sendMessage);
}

void Heavy_prog::cSlice_c8z323Bj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_jZxQYrKW, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_i78GeMpw, 0, m, &cVar_i78GeMpw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_Q0WVtELO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AGV1Z0H0, m);
}

void Heavy_prog::cVar_VNUlLlgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_d2Ae0kMV_sendMessage);
  cSwitchcase_hIv0KkEM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_d2Ae0kMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VNUlLlgI, 1, m, &cVar_VNUlLlgI_sendMessage);
}

void Heavy_prog::cVar_mD9pdlgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZMhDY3Gp, 0, m);
  cMsg_g1vEBkea_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_lbZTUNpG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aa1RAOoK, m);
}

void Heavy_prog::cVar_z4NSS9rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_rx9ix8xz_sendMessage);
  cMsg_k6Hm1Rs8_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_oQmdBjSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_fMrGHicB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 120.0f, 0, m, &cBinop_LYjrWvJg_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hKpIuWB2, m);
}

void Heavy_prog::cSwitchcase_uILFc7W4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_c6mfptmw, 0, m, &cSlice_c6mfptmw_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_6KhSksuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aNTNx1gA_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_oxuvIae6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_e4uj5vh6_sendMessage);
}

void Heavy_prog::cMsg_aNTNx1gA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oxuvIae6_sendMessage);
}

void Heavy_prog::cSlice_c6mfptmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_zBR7tNNi, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_6KhSksuV, 0, m, &cVar_6KhSksuV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_e4uj5vh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_oEa2iozi, m);
}

void Heavy_prog::cMsg_j3CiHu9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4ZmJN7oh_sendMessage);
}

void Heavy_prog::cSystem_4ZmJN7oh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sOZwtyCe, HV_BINOP_MULTIPLY, 1, m, &cBinop_sOZwtyCe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ExATSVZq, HV_BINOP_MULTIPLY, 1, m, &cBinop_ExATSVZq_sendMessage);
}

void Heavy_prog::cSwitchcase_lDOXitVM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_iM5ANqby_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_iM5ANqby_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ynoijBi3_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_HvWpsfiw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HvWpsfiw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvWpsfiw, 0, m, &cDelay_HvWpsfiw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_351a7eub, 0, m, &cVar_351a7eub_sendMessage);
}

void Heavy_prog::cCast_ynoijBi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iM5ANqby_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvWpsfiw, 0, m, &cDelay_HvWpsfiw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_351a7eub, 0, m, &cVar_351a7eub_sendMessage);
}

void Heavy_prog::cMsg_gj0O7jQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KaRcE1rM_sendMessage);
}

void Heavy_prog::cSystem_KaRcE1rM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Bcm58bOw_sendMessage);
}

void Heavy_prog::cVar_sV9Co62c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fG8g1Ig1, HV_BINOP_MULTIPLY, 0, m, &cBinop_fG8g1Ig1_sendMessage);
}

void Heavy_prog::cMsg_iM5ANqby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvWpsfiw, 0, m, &cDelay_HvWpsfiw_sendMessage);
}

void Heavy_prog::cBinop_9QT22ZK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvWpsfiw, 2, m, &cDelay_HvWpsfiw_sendMessage);
}

void Heavy_prog::cBinop_Bcm58bOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fG8g1Ig1, HV_BINOP_MULTIPLY, 1, m, &cBinop_fG8g1Ig1_sendMessage);
}

void Heavy_prog::cBinop_fG8g1Ig1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9QT22ZK6_sendMessage);
}

void Heavy_prog::cVar_351a7eub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0tVtvBif, HV_BINOP_SUBTRACT, 0, m, &cBinop_0tVtvBif_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_eCbQtQ6K_sendMessage);
}

void Heavy_prog::cSwitchcase_K5qWyyeY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uCML7Ex1_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sIof6cBE_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_uCML7Ex1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WuOy1exi, 0, m, &cVar_WuOy1exi_sendMessage);
}

void Heavy_prog::cCast_sIof6cBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IKCVfWsa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FV5AmZeZ_sendMessage);
}

void Heavy_prog::cSwitchcase_rUBCACYO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9KrHcYAs, 0, m, &cSlice_9KrHcYAs_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YPSNUbpJ, 0, m, &cSlice_YPSNUbpJ_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qu2PB0ov_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sAKwJVdg, 0, m, &cSlice_sAKwJVdg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YpVNc6ZO, 0, m, &cSlice_YpVNc6ZO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SW4AF7Bl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ikuOHhvC_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_9KrHcYAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fihBT9KS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_fihBT9KS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_YPSNUbpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KErKVSma_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uasloja7_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KErKVSma_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uasloja7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_Ul5MLxT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rGFAS8jW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M4DzltPu_sendMessage);
}

void Heavy_prog::cVar_28q3Gucu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3VSqF9U3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_3VSqF9U3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6ALLcfLr_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_sOZwtyCe, HV_BINOP_MULTIPLY, 0, m, &cBinop_sOZwtyCe_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_8HGz5QCr, HV_BINOP_DIVIDE, 1, m, &cBinop_8HGz5QCr_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_sV9Co62c, 0, m, &cVar_sV9Co62c_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_6ALLcfLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0O9IVAlP_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_OjFjFYEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zH0B4cQ4, HV_BINOP_SUBTRACT, 1, m, &cBinop_zH0B4cQ4_sendMessage);
}

void Heavy_prog::cVar_Ep2VcbB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WuOy1exi, 0, m, &cVar_WuOy1exi_sendMessage);
}

void Heavy_prog::cVar_WuOy1exi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rKiwoRCC, HV_BINOP_ADD, 0, m, &cBinop_rKiwoRCC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xiNU2vrg, HV_BINOP_ADD, 0, m, &cBinop_xiNU2vrg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Tfk04EG1, 0, m, &cVar_Tfk04EG1_sendMessage);
}

void Heavy_prog::cSlice_sAKwJVdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rGFAS8jW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M4DzltPu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_YpVNc6ZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_auTUUCOH_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NzfqVS8T_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_1D0Wmylh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_351a7eub, 1, m, &cVar_351a7eub_sendMessage);
}

void Heavy_prog::cBinop_ExATSVZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1D0Wmylh_sendMessage);
}

void Heavy_prog::cBinop_sOZwtyCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hvGNv623_sendMessage);
}

void Heavy_prog::cBinop_hvGNv623_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0tVtvBif, HV_BINOP_SUBTRACT, 1, m, &cBinop_0tVtvBif_sendMessage);
}

void Heavy_prog::cBinop_0tVtvBif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_351a7eub, 1, m, &cVar_351a7eub_sendMessage);
}

void Heavy_prog::cMsg_MBZ3gnBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_lDOXitVM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_IGudnTHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_lDOXitVM_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xiNU2vrg, HV_BINOP_ADD, 1, m, &cBinop_xiNU2vrg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rKiwoRCC, HV_BINOP_ADD, 1, m, &cBinop_rKiwoRCC_sendMessage);
}

void Heavy_prog::cBinop_eCbQtQ6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_K5qWyyeY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_rKiwoRCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WuOy1exi, 1, m, &cVar_WuOy1exi_sendMessage);
}

void Heavy_prog::cBinop_8HGz5QCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mcsLm02D, HV_BINOP_DIVIDE, 1, m, &cBinop_mcsLm02D_sendMessage);
}

void Heavy_prog::cBinop_mcsLm02D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xiNU2vrg, HV_BINOP_ADD, 1, m, &cBinop_xiNU2vrg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rKiwoRCC, HV_BINOP_ADD, 1, m, &cBinop_rKiwoRCC_sendMessage);
}

void Heavy_prog::cCast_rGFAS8jW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ExATSVZq, HV_BINOP_MULTIPLY, 0, m, &cBinop_ExATSVZq_sendMessage);
}

void Heavy_prog::cCast_M4DzltPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8HGz5QCr, HV_BINOP_DIVIDE, 0, m, &cBinop_8HGz5QCr_sendMessage);
}

void Heavy_prog::cCast_auTUUCOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ep2VcbB4, 1, m, &cVar_Ep2VcbB4_sendMessage);
}

void Heavy_prog::cCast_NzfqVS8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zH0B4cQ4, HV_BINOP_SUBTRACT, 0, m, &cBinop_zH0B4cQ4_sendMessage);
}

void Heavy_prog::cCast_IKCVfWsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IGudnTHG_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_FV5AmZeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ep2VcbB4, 0, m, &cVar_Ep2VcbB4_sendMessage);
}

void Heavy_prog::cBinop_xiNU2vrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OjFjFYEg, 0, m, &cVar_OjFjFYEg_sendMessage);
}

void Heavy_prog::cMsg_fihBT9KS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_lDOXitVM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_4xIsYw6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Ul5MLxT8, 1, m, &cVar_Ul5MLxT8_sendMessage);
}

void Heavy_prog::cMsg_0O9IVAlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sOZwtyCe, HV_BINOP_MULTIPLY, 0, m, &cBinop_sOZwtyCe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8HGz5QCr, HV_BINOP_DIVIDE, 1, m, &cBinop_8HGz5QCr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sV9Co62c, 0, m, &cVar_sV9Co62c_sendMessage);
}

void Heavy_prog::cCast_KErKVSma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fihBT9KS_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_uasloja7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AFgUpDIy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xiNU2vrg, HV_BINOP_ADD, 0, m, &cBinop_xiNU2vrg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WuOy1exi, 1, m, &cVar_WuOy1exi_sendMessage);
}

void Heavy_prog::cBinop_zH0B4cQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mcsLm02D, HV_BINOP_DIVIDE, 0, m, &cBinop_mcsLm02D_sendMessage);
}

void Heavy_prog::cCast_AFgUpDIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IGudnTHG_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_SW4AF7Bl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MBZ3gnBI_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ikuOHhvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4xIsYw6Q_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Qu2PB0ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ul5MLxT8, 0, m, &cVar_Ul5MLxT8_sendMessage);
}

void Heavy_prog::cVar_Tfk04EG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_ANvL7JnK_sendMessage);
}

void Heavy_prog::cVar_bLxrB8TK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q7EZ2IXQ, 0, m, &cVar_q7EZ2IXQ_sendMessage);
}

void Heavy_prog::cVar_q7EZ2IXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YHMX96v8, HV_BINOP_MULTIPLY, 0, m, &cBinop_YHMX96v8_sendMessage);
}

void Heavy_prog::cMsg_VzsYfzYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y0NhsbKO_sendMessage);
}

void Heavy_prog::cSystem_y0NhsbKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oX6fqTVT_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_YHMX96v8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qjqRTm6V_sendMessage);
}

void Heavy_prog::cBinop_XqwWbkON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YHMX96v8, HV_BINOP_MULTIPLY, 1, m, &cBinop_YHMX96v8_sendMessage);
}

void Heavy_prog::cMsg_oX6fqTVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XqwWbkON_sendMessage);
}

void Heavy_prog::cBinop_qjqRTm6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EtYA7t6q_sendMessage);
}

void Heavy_prog::cBinop_EtYA7t6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6RftiFMe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DgyRxLke, m);
}

void Heavy_prog::cBinop_6RftiFMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kmiEHq0F, m);
}

void Heavy_prog::cBinop_ANvL7JnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bLxrB8TK, 0, m, &cVar_bLxrB8TK_sendMessage);
}

void Heavy_prog::cMsg_g1vEBkea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_rUBCACYO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_BQx7NL2Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5ZapETkv, 0, m, &cSlice_5ZapETkv_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_NLCcHSen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8L6OrAut_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_GXlA86s3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_V9UtAnjW_sendMessage);
}

void Heavy_prog::cMsg_8L6OrAut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GXlA86s3_sendMessage);
}

void Heavy_prog::cSlice_5ZapETkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_gCavYMUi, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_NLCcHSen, 0, m, &cVar_NLCcHSen_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_V9UtAnjW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RIL1ZuxN, m);
}

void Heavy_prog::cMsg_RoxlRdrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ae8JrsZx_sendMessage);
}

void Heavy_prog::cSystem_Ae8JrsZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Uc2Yd0l, HV_BINOP_MULTIPLY, 1, m, &cBinop_3Uc2Yd0l_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_h71d0rwt, HV_BINOP_MULTIPLY, 1, m, &cBinop_h71d0rwt_sendMessage);
}

void Heavy_prog::cSwitchcase_Bl1Ne1OD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_HziQSVqi_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HziQSVqi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s0Djen1f_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_NvNGczAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NvNGczAT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NvNGczAT, 0, m, &cDelay_NvNGczAT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lRcGpdft, 0, m, &cVar_lRcGpdft_sendMessage);
}

void Heavy_prog::cCast_s0Djen1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HziQSVqi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NvNGczAT, 0, m, &cDelay_NvNGczAT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lRcGpdft, 0, m, &cVar_lRcGpdft_sendMessage);
}

void Heavy_prog::cMsg_KOtP7Ypx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2lb2fqIe_sendMessage);
}

void Heavy_prog::cSystem_2lb2fqIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DMdGJtgz_sendMessage);
}

void Heavy_prog::cVar_8HIZP3Wx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PhtzFj9H, HV_BINOP_MULTIPLY, 0, m, &cBinop_PhtzFj9H_sendMessage);
}

void Heavy_prog::cMsg_HziQSVqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NvNGczAT, 0, m, &cDelay_NvNGczAT_sendMessage);
}

void Heavy_prog::cBinop_siJuQUIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NvNGczAT, 2, m, &cDelay_NvNGczAT_sendMessage);
}

void Heavy_prog::cBinop_DMdGJtgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PhtzFj9H, HV_BINOP_MULTIPLY, 1, m, &cBinop_PhtzFj9H_sendMessage);
}

void Heavy_prog::cBinop_PhtzFj9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_siJuQUIh_sendMessage);
}

void Heavy_prog::cVar_lRcGpdft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zwe0S00z, HV_BINOP_SUBTRACT, 0, m, &cBinop_zwe0S00z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Z1qlnmlF_sendMessage);
}

void Heavy_prog::cSwitchcase_DajjMmwN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5QL7eIUd_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HwoWG4dx_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_5QL7eIUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rWob9zZw, 0, m, &cVar_rWob9zZw_sendMessage);
}

void Heavy_prog::cCast_HwoWG4dx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TjCuLJ0N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KpGsdw5p_sendMessage);
}

void Heavy_prog::cSwitchcase_afw8wfDu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WCspljmO, 0, m, &cSlice_WCspljmO_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4JvOM7Lu, 0, m, &cSlice_4JvOM7Lu_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9Hj8bO6e_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hSlPUeF2, 0, m, &cSlice_hSlPUeF2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4VYkSVbh, 0, m, &cSlice_4VYkSVbh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_74tnbFII_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J3JRqYd2_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_WCspljmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_GWv9DN5K_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_GWv9DN5K_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_4JvOM7Lu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XlfnCVhd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a6KL4ZNR_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XlfnCVhd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a6KL4ZNR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_T1cj9KUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jC1Xksxj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7HzcvZ9W_sendMessage);
}

void Heavy_prog::cVar_x0dYeFiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_H5001sOh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_H5001sOh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FcHJ4Yu3_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3Uc2Yd0l, HV_BINOP_MULTIPLY, 0, m, &cBinop_3Uc2Yd0l_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_lbSuZ1GZ, HV_BINOP_DIVIDE, 1, m, &cBinop_lbSuZ1GZ_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_8HIZP3Wx, 0, m, &cVar_8HIZP3Wx_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_FcHJ4Yu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hKK49EGO_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_1cKuofcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XojsP7l7, HV_BINOP_SUBTRACT, 1, m, &cBinop_XojsP7l7_sendMessage);
}

void Heavy_prog::cVar_J17DPHr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rWob9zZw, 0, m, &cVar_rWob9zZw_sendMessage);
}

void Heavy_prog::cVar_rWob9zZw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jDVmQqVc, HV_BINOP_ADD, 0, m, &cBinop_jDVmQqVc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UDQYYpCE, HV_BINOP_ADD, 0, m, &cBinop_UDQYYpCE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b1jLgKW8, 0, m, &cVar_b1jLgKW8_sendMessage);
}

void Heavy_prog::cSlice_hSlPUeF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jC1Xksxj_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7HzcvZ9W_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_4VYkSVbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lk4qOTSq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_giXjmZ9q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_coURPGFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lRcGpdft, 1, m, &cVar_lRcGpdft_sendMessage);
}

void Heavy_prog::cBinop_h71d0rwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_coURPGFL_sendMessage);
}

void Heavy_prog::cBinop_3Uc2Yd0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wQ6OZggl_sendMessage);
}

void Heavy_prog::cBinop_wQ6OZggl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zwe0S00z, HV_BINOP_SUBTRACT, 1, m, &cBinop_zwe0S00z_sendMessage);
}

void Heavy_prog::cBinop_zwe0S00z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lRcGpdft, 1, m, &cVar_lRcGpdft_sendMessage);
}

void Heavy_prog::cMsg_HuGhT9z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Bl1Ne1OD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_an8RbMH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Bl1Ne1OD_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UDQYYpCE, HV_BINOP_ADD, 1, m, &cBinop_UDQYYpCE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jDVmQqVc, HV_BINOP_ADD, 1, m, &cBinop_jDVmQqVc_sendMessage);
}

void Heavy_prog::cBinop_Z1qlnmlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DajjMmwN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_jDVmQqVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rWob9zZw, 1, m, &cVar_rWob9zZw_sendMessage);
}

void Heavy_prog::cBinop_lbSuZ1GZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k1kMJZMc, HV_BINOP_DIVIDE, 1, m, &cBinop_k1kMJZMc_sendMessage);
}

void Heavy_prog::cBinop_k1kMJZMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UDQYYpCE, HV_BINOP_ADD, 1, m, &cBinop_UDQYYpCE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jDVmQqVc, HV_BINOP_ADD, 1, m, &cBinop_jDVmQqVc_sendMessage);
}

void Heavy_prog::cCast_jC1Xksxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h71d0rwt, HV_BINOP_MULTIPLY, 0, m, &cBinop_h71d0rwt_sendMessage);
}

void Heavy_prog::cCast_7HzcvZ9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lbSuZ1GZ, HV_BINOP_DIVIDE, 0, m, &cBinop_lbSuZ1GZ_sendMessage);
}

void Heavy_prog::cCast_giXjmZ9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XojsP7l7, HV_BINOP_SUBTRACT, 0, m, &cBinop_XojsP7l7_sendMessage);
}

void Heavy_prog::cCast_lk4qOTSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J17DPHr2, 1, m, &cVar_J17DPHr2_sendMessage);
}

void Heavy_prog::cCast_KpGsdw5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J17DPHr2, 0, m, &cVar_J17DPHr2_sendMessage);
}

void Heavy_prog::cCast_TjCuLJ0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_an8RbMH0_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_UDQYYpCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1cKuofcp, 0, m, &cVar_1cKuofcp_sendMessage);
}

void Heavy_prog::cMsg_GWv9DN5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Bl1Ne1OD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_peU1cWce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_T1cj9KUs, 1, m, &cVar_T1cj9KUs_sendMessage);
}

void Heavy_prog::cMsg_hKK49EGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Uc2Yd0l, HV_BINOP_MULTIPLY, 0, m, &cBinop_3Uc2Yd0l_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lbSuZ1GZ, HV_BINOP_DIVIDE, 1, m, &cBinop_lbSuZ1GZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8HIZP3Wx, 0, m, &cVar_8HIZP3Wx_sendMessage);
}

void Heavy_prog::cCast_a6KL4ZNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EVU8b9iw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UDQYYpCE, HV_BINOP_ADD, 0, m, &cBinop_UDQYYpCE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rWob9zZw, 1, m, &cVar_rWob9zZw_sendMessage);
}

void Heavy_prog::cCast_XlfnCVhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GWv9DN5K_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_XojsP7l7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k1kMJZMc, HV_BINOP_DIVIDE, 0, m, &cBinop_k1kMJZMc_sendMessage);
}

void Heavy_prog::cCast_EVU8b9iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_an8RbMH0_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_J3JRqYd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_peU1cWce_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_74tnbFII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HuGhT9z8_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_9Hj8bO6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T1cj9KUs, 0, m, &cVar_T1cj9KUs_sendMessage);
}

void Heavy_prog::cVar_b1jLgKW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_ypodWxNy_sendMessage);
}

void Heavy_prog::cVar_fJlCB5Q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZDXrelO6, 0, m, &cVar_ZDXrelO6_sendMessage);
}

void Heavy_prog::cVar_ZDXrelO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H7hZlj8r, HV_BINOP_MULTIPLY, 0, m, &cBinop_H7hZlj8r_sendMessage);
}

void Heavy_prog::cMsg_odDLhuPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0pEGgKpV_sendMessage);
}

void Heavy_prog::cSystem_0pEGgKpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gy5mdjVC_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_H7hZlj8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vNURfSP5_sendMessage);
}

void Heavy_prog::cBinop_SA9i1i9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H7hZlj8r, HV_BINOP_MULTIPLY, 1, m, &cBinop_H7hZlj8r_sendMessage);
}

void Heavy_prog::cMsg_Gy5mdjVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SA9i1i9X_sendMessage);
}

void Heavy_prog::cBinop_vNURfSP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ypdvIAAC_sendMessage);
}

void Heavy_prog::cBinop_ypdvIAAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fwDaHLfz_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_u6NGvTFr, m);
}

void Heavy_prog::cBinop_fwDaHLfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_B9h1LePy, m);
}

void Heavy_prog::cBinop_ypodWxNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fJlCB5Q3, 0, m, &cVar_fJlCB5Q3_sendMessage);
}

void Heavy_prog::cMsg_k6Hm1Rs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_afw8wfDu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_hIv0KkEM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_xhFBQB59_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_xhFBQB59_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OC40gq6E_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_rLyKpXYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rLyKpXYj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rLyKpXYj, 0, m, &cDelay_rLyKpXYj_sendMessage);
  cSwitchcase_vR4YXHyS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Eppw4nyN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_DFOwN7ul_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_OC40gq6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xhFBQB59_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rLyKpXYj, 0, m, &cDelay_rLyKpXYj_sendMessage);
  cSwitchcase_vR4YXHyS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Eppw4nyN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_DFOwN7ul_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_4JuLlEwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bBRzbwMh_sendMessage);
}

void Heavy_prog::cSystem_bBRzbwMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3S5kvFTH_sendMessage);
}

void Heavy_prog::cVar_x8TXmBWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YSURqAde, HV_BINOP_MULTIPLY, 0, m, &cBinop_YSURqAde_sendMessage);
}

void Heavy_prog::cMsg_xhFBQB59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rLyKpXYj, 0, m, &cDelay_rLyKpXYj_sendMessage);
}

void Heavy_prog::cBinop_vPE33F9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rLyKpXYj, 2, m, &cDelay_rLyKpXYj_sendMessage);
}

void Heavy_prog::cBinop_3S5kvFTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YSURqAde, HV_BINOP_MULTIPLY, 1, m, &cBinop_YSURqAde_sendMessage);
}

void Heavy_prog::cBinop_YSURqAde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vPE33F9r_sendMessage);
}

void Heavy_prog::cSwitchcase_vR4YXHyS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_H9SEGXap, 0, m, &cSlice_H9SEGXap_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BPyGLp9a, 0, m, &cRandom_BPyGLp9a_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_eDaXTy5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7AOXQ70e_sendMessage);
}

void Heavy_prog::cUnop_7AOXQ70e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mD9pdlgW, 0, m, &cVar_mD9pdlgW_sendMessage);
}

void Heavy_prog::cRandom_BPyGLp9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_eDaXTy5N_sendMessage);
}

void Heavy_prog::cSlice_H9SEGXap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BPyGLp9a, 1, m, &cRandom_BPyGLp9a_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_Eppw4nyN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9BjPBoFR, 0, m, &cSlice_9BjPBoFR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NLtOyXIw, 0, m, &cRandom_NLtOyXIw_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_hpOnCzhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_SyoE8HJy_sendMessage);
}

void Heavy_prog::cUnop_SyoE8HJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oQmdBjSK, 0, m, &cVar_oQmdBjSK_sendMessage);
}

void Heavy_prog::cRandom_NLtOyXIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_hpOnCzhu_sendMessage);
}

void Heavy_prog::cSlice_9BjPBoFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NLtOyXIw, 1, m, &cRandom_NLtOyXIw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_DFOwN7ul_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OpRx6UWG, 0, m, &cSlice_OpRx6UWG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1fl30dN0, 0, m, &cRandom_1fl30dN0_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_cMLblFmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wPZKuUrJ_sendMessage);
}

void Heavy_prog::cUnop_wPZKuUrJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z4NSS9rp, 0, m, &cVar_z4NSS9rp_sendMessage);
}

void Heavy_prog::cRandom_1fl30dN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 24.0f, 0, m, &cBinop_cMLblFmp_sendMessage);
}

void Heavy_prog::cSlice_OpRx6UWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1fl30dN0, 1, m, &cRandom_1fl30dN0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_rx9ix8xz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0PgfG2og, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xJBVVo8G, m);
}

void Heavy_prog::cBinop_fMrGHicB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1hPHYRCe, 0, m);
}

void Heavy_prog::cBinop_lbZTUNpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_gnb4NNin, 0, m);
}

void Heavy_prog::cBinop_LYjrWvJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x8TXmBWB, 0, m, &cVar_x8TXmBWB_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hBfTf7cP, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ubGYPnNy, m);
}

void Heavy_prog::cReceive_lNAsSoTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gj0O7jQm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sV9Co62c, 0, m, &cVar_sV9Co62c_sendMessage);
  cMsg_VzsYfzYU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_q7EZ2IXQ, 0, m, &cVar_q7EZ2IXQ_sendMessage);
  cMsg_KOtP7Ypx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8HIZP3Wx, 0, m, &cVar_8HIZP3Wx_sendMessage);
  cMsg_odDLhuPu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZDXrelO6, 0, m, &cVar_ZDXrelO6_sendMessage);
  cMsg_j3CiHu9d_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OjFjFYEg, 0, m, &cVar_OjFjFYEg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_28q3Gucu, 0, m, &cVar_28q3Gucu_sendMessage);
  cMsg_RoxlRdrR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1cKuofcp, 0, m, &cVar_1cKuofcp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_x0dYeFiy, 0, m, &cVar_x0dYeFiy_sendMessage);
  cSwitchcase_54BRwOFy_onMessage(_c, NULL, 0, m, NULL);
  cMsg_4JuLlEwy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x8TXmBWB, 0, m, &cVar_x8TXmBWB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VNUlLlgI, 0, m, &cVar_VNUlLlgI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VaQy0tNm, 0, m, &cVar_VaQy0tNm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_i78GeMpw, 0, m, &cVar_i78GeMpw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6KhSksuV, 0, m, &cVar_6KhSksuV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NLCcHSen, 0, m, &cVar_NLCcHSen_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13;
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
    __hv_phasor_k_f(&sPhasor_1hPHYRCe, VOf(Bf0));
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
    __hv_phasor_k_f(&sPhasor_R5MIhdk9, VOf(Bf3));
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
    __hv_var_k_f(VOf(Bf2), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_RIL1ZuxN, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_tabread_if(&sTabread_gCavYMUi, VIi(Bi0), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_u6NGvTFr, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_B9h1LePy, VOf(Bf0));
    __hv_rpole_f(&sRPole_BzrGQPBH, VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_i(&sVari_3GECHzGw, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_3GECHzGw, VIi(Bi1));
    __hv_abs_f(VIf(Bf1), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_ZMhDY3Gp, VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_del1_f(&sDel1_wwaYJPIN, VIf(Bf4), VOf(Bf5));
    __hv_lt_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_samphold_f(&sSamphold_CHzzCTd1, VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_xJBVVo8G, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_gnb4NNin, VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_ubGYPnNy, VOf(Bf9));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_phasor_f(&sPhasor_mX0IMNqq, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_RxGJSywu, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_tabread_if(&sTabread_3rH5YBA9, VIi(Bi1), VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_del1_f(&sDel1_D5yeXuPo, VIf(Bf3), VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_KqL8alVT, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_0PgfG2og, VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_hBfTf7cP, VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_Lc8M1ZOl, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_hKpIuWB2, VOf(Bf5));
    __hv_min_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_aa1RAOoK, VOf(Bf2));
    __hv_max_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf5));
    __hv_phasor_f(&sPhasor_MnSCPKGK, VIf(Bf5), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf12), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf13), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf4), VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf11), VIf(Bf10), VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f);
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_phasor_k_f(&sPhasor_pMCXnglZ, VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf1));
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf12), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_oEa2iozi, VOf(Bf7));
    __hv_min_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_cast_fi(VIf(Bf12), VOi(Bi1));
    __hv_tabread_if(&sTabread_zBR7tNNi, VIi(Bi1), VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_DgyRxLke, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_kmiEHq0F, VOf(Bf11));
    __hv_rpole_f(&sRPole_GleC6YyZ, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_AGV1Z0H0, VOf(Bf3));
    __hv_min_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_cast_fi(VIf(Bf12), VOi(Bi1));
    __hv_tabread_if(&sTabread_jZxQYrKW, VIi(Bi1), VOf(Bf12));
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_phasor_f(&sPhasor_VP39BkkG, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf1), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf11), VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf2), 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f, 0.005f);
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));

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
