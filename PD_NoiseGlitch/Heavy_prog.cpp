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

float hTable_hNTLLZQ9_data[256] = {-0.0133332f, 0.0566667f, 0.0600001f, 0.0633334f, 0.0700001f, 0.0716667f, 0.0733334f, 0.075f, 0.0766667f, 0.863333f, 0.86f, 0.856667f, 0.854167f, 0.851667f, 0.849167f, 0.846667f, 0.844667f, 0.842667f, 0.840667f, 0.838667f, 0.836667f, 0.835333f, 0.834f, 0.832667f, 0.831333f, 0.83f, 0.827778f, 0.825556f, 0.823333f, 0.133334f, 0.126667f, 0.100001f, 0.0966674f, 0.0933341f, 0.0933341f, 0.0933341f, 0.0933341f, 0.0916674f, 0.0900007f, 0.0883341f, 0.0866674f, 0.0866674f, 0.0866674f, 0.0866674f, 0.0858341f, 0.0850008f, 0.0841674f, 0.0833341f, 0.0816674f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696f, 0.695334f, 0.694667f, 0.694f, 0.693333f, 0.691333f, 0.689333f, 0.687333f, 0.685333f, 0.683334f, 0.681667f, 0.68f, 0.678334f, 0.676667f, 0.675556f, 0.674445f, 0.673334f, 0.67f, 0.666667f, 0.663334f, 0.206667f, 0.160001f, 0.100001f, 0.0966674f, 0.0900007f, 0.0833341f, 0.0800008f, 0.0766674f, 0.0733341f, 0.0700008f, 0.0666674f, 0.0616674f, 0.0566674f, 0.0516675f, 0.0466675f, 0.0444452f, 0.042223f, 0.0400008f, 0.0377786f, 0.0355564f, 0.0333341f, 0.0325008f, 0.0316675f, 0.0308341f, 0.0300008f, 0.0293341f, 0.0286675f, 0.0280008f, 0.0273341f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0262971f, 0.0259267f, 0.0255564f, 0.025186f, 0.0248156f, 0.0244453f, 0.0240749f, 0.0237045f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.886667f, 0.89f, 0.891667f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.203334f, 0.190001f, 0.170001f, 0.156667f, 0.150001f, 0.146667f, 0.143334f, 0.139167f, 0.135001f, 0.130834f, 0.126667f, 0.124001f, 0.121334f, 0.118667f, 0.116001f, 0.113334f, 0.110667f, 0.108001f, 0.105334f, 0.102667f, 0.100001f, 0.0980007f, 0.0960007f, 0.0940007f, 0.0920007f, 0.0900008f, 0.0888896f, 0.0877785f, 0.0866674f, 0.0850008f, 0.0833341f, 0.0833341f, 0.0833341f, 0.0833341f, 0.0800008f, 0.0766674f, 0.0750008f, 0.0733341f, 0.0733341f, 0.0733341f, 0.0700008f, 0.0666674f, 0.0633341f, 0.819999f, 0.816666f, 0.0600001f, 0.0566667f, 0.0533334f};
float hTable_PPyQYIig_data[256] = {0.326666f, 0.35f, 0.355f, 0.386666f, 0.4f, 0.416666f, 0.42f, 0.43f, 0.453333f, 0.46f, 0.47f, 0.476666f, 0.496666f, 0.503333f, 0.51f, 0.516666f, 0.53f, 0.536666f, 0.546666f, 0.553333f, 0.56f, 0.576666f, 0.58f, 0.583333f, 0.593333f, 0.599999f, 0.613333f, 0.616666f, 0.623333f, 0.633333f, 0.643333f, 0.649999f, 0.656666f, 0.666666f, 0.673333f, 0.678333f, 0.689999f, 0.699999f, 0.706666f, 0.709999f, 0.716666f, 0.723333f, 0.726666f, 0.733333f, 0.736666f, 0.739999f, 0.749999f, 0.756666f, 0.759999f, 0.763333f, 0.766666f, 0.769999f, 0.773333f, 0.774999f, 0.776666f, 0.779999f, 0.783333f, 0.786666f, 0.793333f, 0.796666f, 0.796666f, 0.799999f, 0.803333f, 0.809999f, 0.809999f, 0.809999f, 0.813333f, 0.819999f, 0.819999f, 0.823333f, 0.824999f, 0.826666f, 0.833333f, 0.836666f, 0.836666f, 0.836666f, 0.843333f, 0.846666f, 0.846666f, 0.849999f, 0.85111f, 0.852221f, 0.853333f, 0.853333f, 0.854999f, 0.856666f, 0.863333f, 0.866666f, 0.868333f, 0.869999f, 0.872221f, 0.874444f, 0.879999f, 0.881666f, 0.883333f, 0.889999f, 0.889999f, 0.889999f, 0.889999f, 0.893333f, 0.893333f, 0.893333f, 0.894999f, 0.896666f, 0.896666f, 0.898333f, 0.899999f, 0.899999f, 0.899999f, 0.899999f, 0.899999f, 0.903333f, 0.903333f, 0.903333f, 0.904999f, 0.906666f, 0.909999f, 0.909999f, 0.909999f, 0.909999f, 0.913333f, 0.914444f, 0.915555f, 0.916666f, 0.916666f, 0.916666f, 0.919999f, 0.919999f, 0.921666f, 0.923333f, 0.923333f, 0.923333f, 0.923333f, 0.926666f, 0.926666f, 0.926666f, 0.928333f, 0.929999f, 0.931666f, 0.933333f, 0.933333f, 0.939999f, 0.941666f, 0.943332f, 0.943332f, 0.943332f, 0.944999f, 0.946666f, 0.949999f, 0.949999f, 0.953332f, 0.956666f, 0.959999f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.959999f, 0.954999f, 0.949999f, 0.945555f, 0.94111f, 0.936666f, 0.933333f, 0.929999f, 0.926666f, 0.919999f, 0.913333f, 0.906666f, 0.899999f, 0.896666f, 0.893333f, 0.889999f, 0.883333f, 0.878333f, 0.873333f, 0.867777f, 0.862221f, 0.856666f, 0.846666f, 0.836666f, 0.829999f, 0.823333f, 0.816666f, 0.809999f, 0.803333f, 0.796666f, 0.779999f, 0.769999f, 0.759999f, 0.746666f, 0.736666f, 0.726666f, 0.709999f, 0.699999f, 0.686666f, 0.639999f, 0.633333f, 0.609999f, 0.596666f, 0.589999f, 0.58f, 0.57f, 0.549999f, 0.542222f, 0.534444f, 0.526666f, 0.521666f, 0.516666f, 0.503333f, 0.498333f, 0.493333f, 0.473333f, 0.463333f, 0.45f, 0.436666f, 0.425f, 0.413333f, 0.403333f, 0.393333f, 0.37f, 0.353333f, 0.346666f, 0.333333f, 0.313333f, 0.296666f, 0.286666f, 0.266666f, 0.26f, 0.243333f, 0.235f, 0.216667f, 0.19f, 0.17f, 0.16f, 0.136667f, 0.13f, 0.113333f, 0.103333f, 0.0733333f, 0.06f, 0.04f, 0.0266667f, 0.0166667f, -0.0133333f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_xkU9AfC3, 110.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_9zhJXIbS, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_Rbol7sV7);
  numBytes += sSamphold_init(&sSamphold_eX0X9rcc);
  numBytes += sPhasor_init(&sPhasor_2EujnzBM, sampleRate);
  numBytes += sTabread_init(&sTabread_yKcIZGrO, &hTable_hNTLLZQ9, false);
  numBytes += sDel1_init(&sDel1_JYJLbKEN);
  numBytes += sSamphold_init(&sSamphold_aKsTdQsH);
  numBytes += sPhasor_init(&sPhasor_JDscnkNG, sampleRate);
  numBytes += sTabread_init(&sTabread_N8TpCNps, &hTable_PPyQYIig, false);
  numBytes += sTabwrite_init(&sTabwrite_zKNe5rZs, &hTable_TsTiEUnK);
  numBytes += sPhasor_k_init(&sPhasor_lPyQcKUb, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_Bq2c0V3v, &hTable_TsTiEUnK, false);
  numBytes += sTabread_init(&sTabread_Sn7Odrkg, &hTable_TsTiEUnK, false);
  numBytes += sPhasor_k_init(&sPhasor_o55CTsvV, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_eewsHbMM, &hTable_PPyQYIig, false);
  numBytes += sRPole_init(&sRPole_VzLW55oA);
  numBytes += sPhasor_k_init(&sPhasor_HchcDHKK, 50.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_i580LAs9, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_cyBBRnke);
  numBytes += sSamphold_init(&sSamphold_Mdk7pS5X);
  numBytes += sPhasor_init(&sPhasor_wVTzuI0r, sampleRate);
  numBytes += sTabread_init(&sTabread_HbBhbiRo, &hTable_PPyQYIig, false);
  numBytes += sDel1_init(&sDel1_tr0bhcIW);
  numBytes += sSamphold_init(&sSamphold_ynX61apZ);
  numBytes += sPhasor_init(&sPhasor_15v3gyK1, sampleRate);
  numBytes += sTabread_init(&sTabread_UDmNHYCE, &hTable_hNTLLZQ9, false);
  numBytes += sPhasor_k_init(&sPhasor_UwYljcj8, 1.0f, sampleRate);
  numBytes += hTable_initWithData(&hTable_hNTLLZQ9, 256, hTable_hNTLLZQ9_data);
  numBytes += cDelay_init(this, &cDelay_c9NGP1Od, 0.0f);
  numBytes += cVar_init_f(&cVar_bIzlwcP1, 20.0f);
  numBytes += cBinop_init(&cBinop_MlTQ54mv, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_7yPT9PH8, 0.0f);
  numBytes += cSlice_init(&cSlice_JxmSEaTR, 1, -1);
  numBytes += cSlice_init(&cSlice_4hmH5JIK, 1, -1);
  numBytes += cVar_init_f(&cVar_eb0V5FPV, 0.0f);
  numBytes += cVar_init_f(&cVar_ydvJaGVT, 1.0f);
  numBytes += cVar_init_f(&cVar_ABJP8LK0, 0.0f);
  numBytes += cVar_init_f(&cVar_AU4ntFFm, 0.0f);
  numBytes += cVar_init_f(&cVar_Wn2LVcec, 0.0f);
  numBytes += cSlice_init(&cSlice_8FIVrdQ9, 1, 1);
  numBytes += cSlice_init(&cSlice_wxfot2fC, 0, 1);
  numBytes += cBinop_init(&cBinop_UwFHulMV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9MKW11jc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_jJnZu7Gi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sueXsVhp, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_J3StGAIw, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_GHsN9tOU, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_XpvjE7Aj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_VHVlyy1h, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_lH9kH58U, 0.0f);
  numBytes += cVar_init_f(&cVar_RTCxRcU9, 0.0f);
  numBytes += cVar_init_f(&cVar_2JMcyfLW, 22050.0f);
  numBytes += cBinop_init(&cBinop_ibVP9RHv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vnii919H, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Huhjz27C, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_RA4wmrik, "soft2");
  numBytes += cSlice_init(&cSlice_hEfetDlA, 1, 1);
  numBytes += sVarf_init(&sVarf_3lU6YYds, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HUNI1dWF, 1.0f);
  numBytes += cVar_init_f(&cVar_VIP7Cham, 1.0f);
  numBytes += cVar_init_f(&cVar_384qgcHB, 0.0f);
  numBytes += cVar_init_f(&cVar_X5JXEGAq, 1.0f);
  numBytes += cIf_init(&cIf_umRfhjf8, false);
  numBytes += cBinop_init(&cBinop_kt02wzks, 0.0f); // __gte
  numBytes += cVar_init_f(&cVar_sskrgh2W, 0.0f);
  numBytes += cVar_init_f(&cVar_sG2qIWAK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CbWgtpSx, 0.0f);
  numBytes += cVar_init_f(&cVar_fex1PwmF, 100.0f);
  numBytes += cBinop_init(&cBinop_dL3Cf0HD, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_PPyQYIig, 256, hTable_PPyQYIig_data);
  numBytes += cBinop_init(&cBinop_0pPy1VyN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xB9c8l6E, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_smLTstmO, 0.0f);
  numBytes += cVar_init_f(&cVar_uNZEYs2k, 20.0f);
  numBytes += cBinop_init(&cBinop_CSDJiBrg, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YxZRvHpC, 0.0f);
  numBytes += cSlice_init(&cSlice_Yo9pk5Xv, 1, -1);
  numBytes += cSlice_init(&cSlice_GcKyizcz, 1, -1);
  numBytes += cVar_init_f(&cVar_GCkLVHyq, 0.0f);
  numBytes += cVar_init_f(&cVar_zhRizkkw, 1.0f);
  numBytes += cVar_init_f(&cVar_15eX9dMR, 0.0f);
  numBytes += cVar_init_f(&cVar_OyiPk4ea, 0.0f);
  numBytes += cVar_init_f(&cVar_FELnZVwu, 0.0f);
  numBytes += cSlice_init(&cSlice_TAeBQSCg, 1, 1);
  numBytes += cSlice_init(&cSlice_xWvTcEX4, 0, 1);
  numBytes += cBinop_init(&cBinop_GaT04mWS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ZRpr1YrQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_c01zmp2z, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_IGk8fIHP, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_GhyJU73T, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_vTU3bygT, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_0rmVd1I2, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_sZRTjXH1, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_DY596Izp, 0.0f);
  numBytes += cVar_init_f(&cVar_MxKuDmT1, 0.0f);
  numBytes += sVarf_init(&sVarf_UGggVA3l, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_modEGIVZ, -1088586121);
  numBytes += cSlice_init(&cSlice_UtD1DTpG, 1, 1);
  numBytes += cRandom_init(&cRandom_22fQMR0c, -1451713038);
  numBytes += cSlice_init(&cSlice_YOQLLq78, 1, 1);
  numBytes += cRandom_init(&cRandom_LMs2r5Sp, 1386636659);
  numBytes += cSlice_init(&cSlice_Xc1ClxLC, 1, 1);
  numBytes += cDelay_init(this, &cDelay_9XGa5IEA, 0.0f);
  numBytes += cVar_init_s(&cVar_YfpUIJT3, "samplebuf");
  numBytes += cSlice_init(&cSlice_TCH7IVVL, 1, 1);
  numBytes += cSlice_init(&cSlice_CXp1OzWW, 1, 1);
  numBytes += cBinop_init(&cBinop_R5B0nBLP, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nFjrpsBm, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_aylslc2Y, "samplebuf");
  numBytes += cSlice_init(&cSlice_8NLgjLqe, 1, 1);
  numBytes += sVarf_init(&sVarf_hoaUX3OS, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_akVEod5b, 0.0f);
  numBytes += cRandom_init(&cRandom_RL3zBSyg, -774020177);
  numBytes += cSlice_init(&cSlice_6ajlSnxY, 1, 1);
  numBytes += sVari_init(&sVari_LwFe7J4k, 0, 0, false);
  numBytes += cVar_init_s(&cVar_PEdetwEy, "soft");
  numBytes += cSlice_init(&cSlice_sN2unbVD, 1, 1);
  numBytes += sVarf_init(&sVarf_ReTUxQK2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9S8Va8uh, 0.0f);
  numBytes += cVar_init_f(&cVar_lCbf1UIG, 0.0f);
  numBytes += cVar_init_s(&cVar_5VncU2TL, "soft2");
  numBytes += cSlice_init(&cSlice_SpoixHbv, 1, 1);
  numBytes += sVarf_init(&sVarf_m9YXo59P, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nA4Olnjc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VQisEZpv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ywB4EeiF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jPwumd1c, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9kcrKHsQ, 0.0f);
  numBytes += cRandom_init(&cRandom_sVgdf4PP, -1213038697);
  numBytes += cSlice_init(&cSlice_DOKOv4O8, 1, 1);
  numBytes += sVari_init(&sVari_JW3YSXny, 0, 0, false);
  numBytes += cVar_init_s(&cVar_QX6txJwj, "soft");
  numBytes += cSlice_init(&cSlice_O4CEwlhw, 1, 1);
  numBytes += sVarf_init(&sVarf_kzebaz0Q, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MQLyADQe, 0.0f);
  numBytes += cVar_init_f(&cVar_kleEQH7K, 0.0f);
  numBytes += cVar_init_s(&cVar_uUCZ4NKo, "soft2");
  numBytes += cSlice_init(&cSlice_bsxc2P8I, 1, 1);
  numBytes += sVarf_init(&sVarf_3Hw3PUID, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fe0D9V86, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MdZrqOea, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HhWWpn6s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9L6SBIsG, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_jsjBynUP, 0.0f); // __div
  numBytes += hTable_init(&hTable_TsTiEUnK, 10000);
  numBytes += sVarf_init(&sVarf_I5pcZ7Os, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_hNTLLZQ9);
  hTable_free(&hTable_PPyQYIig);
  hTable_free(&hTable_TsTiEUnK);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x130A899: return &hTable_TsTiEUnK; // samplebuf
    case 0x69706D21: return &hTable_hNTLLZQ9; // soft
    case 0x18702E06: return &hTable_PPyQYIig; // soft2
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JVq5U3z9_sendMessage);
      break;
    }
    case 0x5C8E49B6: { // freqA
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EyNEZKRE_sendMessage);
      break;
    }
    case 0x24D2FF6A: { // freqB
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WclLjLcX_sendMessage);
      break;
    }
    case 0xB3BE0950: { // freqC
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_occCkZ1c_sendMessage);
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


void Heavy_prog::hTable_hNTLLZQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_83Dc4gVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sfVHlU8R_sendMessage);
}

void Heavy_prog::cSystem_sfVHlU8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9MKW11jc, HV_BINOP_MULTIPLY, 1, m, &cBinop_9MKW11jc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UwFHulMV, HV_BINOP_MULTIPLY, 1, m, &cBinop_UwFHulMV_sendMessage);
}

void Heavy_prog::cSwitchcase_qj7csiEk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_BMxj5tRU_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_BMxj5tRU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fZxkHQlI_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_c9NGP1Od_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c9NGP1Od, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9NGP1Od, 0, m, &cDelay_c9NGP1Od_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7yPT9PH8, 0, m, &cVar_7yPT9PH8_sendMessage);
}

void Heavy_prog::cCast_fZxkHQlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BMxj5tRU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9NGP1Od, 0, m, &cDelay_c9NGP1Od_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7yPT9PH8, 0, m, &cVar_7yPT9PH8_sendMessage);
}

void Heavy_prog::cMsg_kJLe9ygk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I4jq2luY_sendMessage);
}

void Heavy_prog::cSystem_I4jq2luY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OHEuqIJC_sendMessage);
}

void Heavy_prog::cVar_bIzlwcP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlTQ54mv, HV_BINOP_MULTIPLY, 0, m, &cBinop_MlTQ54mv_sendMessage);
}

void Heavy_prog::cMsg_BMxj5tRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9NGP1Od, 0, m, &cDelay_c9NGP1Od_sendMessage);
}

void Heavy_prog::cBinop_uYnlgSPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9NGP1Od, 2, m, &cDelay_c9NGP1Od_sendMessage);
}

void Heavy_prog::cBinop_OHEuqIJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlTQ54mv, HV_BINOP_MULTIPLY, 1, m, &cBinop_MlTQ54mv_sendMessage);
}

void Heavy_prog::cBinop_MlTQ54mv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uYnlgSPv_sendMessage);
}

void Heavy_prog::cVar_7yPT9PH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jJnZu7Gi, HV_BINOP_SUBTRACT, 0, m, &cBinop_jJnZu7Gi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Sy57XhqK_sendMessage);
}

void Heavy_prog::cSwitchcase_9rYhEZeL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1RmVUCez_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UTJ0Nr3W_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_1RmVUCez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Wn2LVcec, 0, m, &cVar_Wn2LVcec_sendMessage);
}

void Heavy_prog::cCast_UTJ0Nr3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7Y2wpYKw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rzL4YjGb_sendMessage);
}

void Heavy_prog::cSwitchcase_fsX4PHtZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JxmSEaTR, 0, m, &cSlice_JxmSEaTR_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4hmH5JIK, 0, m, &cSlice_4hmH5JIK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xjJ7c0mZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8FIVrdQ9, 0, m, &cSlice_8FIVrdQ9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wxfot2fC, 0, m, &cSlice_wxfot2fC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GjXEoKHr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qihYcUfM_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_JxmSEaTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DVhz9UqB_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_DVhz9UqB_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_4hmH5JIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JGyDGxOQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9IKqZvRb_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JGyDGxOQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9IKqZvRb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_eb0V5FPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iVVJgDBI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pC8LOgEr_sendMessage);
}

void Heavy_prog::cVar_ydvJaGVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kkmcpDSr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_kkmcpDSr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XRQAU1iM_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9MKW11jc, HV_BINOP_MULTIPLY, 0, m, &cBinop_9MKW11jc_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_J3StGAIw, HV_BINOP_DIVIDE, 1, m, &cBinop_J3StGAIw_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_bIzlwcP1, 0, m, &cVar_bIzlwcP1_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_XRQAU1iM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RmmM3sR5_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_ABJP8LK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHVlyy1h, HV_BINOP_SUBTRACT, 1, m, &cBinop_VHVlyy1h_sendMessage);
}

void Heavy_prog::cVar_AU4ntFFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Wn2LVcec, 0, m, &cVar_Wn2LVcec_sendMessage);
}

void Heavy_prog::cVar_Wn2LVcec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sueXsVhp, HV_BINOP_ADD, 0, m, &cBinop_sueXsVhp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XpvjE7Aj, HV_BINOP_ADD, 0, m, &cBinop_XpvjE7Aj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lH9kH58U, 0, m, &cVar_lH9kH58U_sendMessage);
}

void Heavy_prog::cSlice_8FIVrdQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iVVJgDBI_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pC8LOgEr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_wxfot2fC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zDMUmnRl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yh0NlbKt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_v0jUceVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7yPT9PH8, 1, m, &cVar_7yPT9PH8_sendMessage);
}

void Heavy_prog::cBinop_UwFHulMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_v0jUceVM_sendMessage);
}

void Heavy_prog::cBinop_9MKW11jc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l6lHWc5n_sendMessage);
}

void Heavy_prog::cBinop_l6lHWc5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jJnZu7Gi, HV_BINOP_SUBTRACT, 1, m, &cBinop_jJnZu7Gi_sendMessage);
}

void Heavy_prog::cBinop_jJnZu7Gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7yPT9PH8, 1, m, &cVar_7yPT9PH8_sendMessage);
}

void Heavy_prog::cMsg_1BiQUunu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_qj7csiEk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_0h9cDXqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_qj7csiEk_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XpvjE7Aj, HV_BINOP_ADD, 1, m, &cBinop_XpvjE7Aj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sueXsVhp, HV_BINOP_ADD, 1, m, &cBinop_sueXsVhp_sendMessage);
}

void Heavy_prog::cBinop_Sy57XhqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9rYhEZeL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_sueXsVhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Wn2LVcec, 1, m, &cVar_Wn2LVcec_sendMessage);
}

void Heavy_prog::cBinop_J3StGAIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GHsN9tOU, HV_BINOP_DIVIDE, 1, m, &cBinop_GHsN9tOU_sendMessage);
}

void Heavy_prog::cBinop_GHsN9tOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XpvjE7Aj, HV_BINOP_ADD, 1, m, &cBinop_XpvjE7Aj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sueXsVhp, HV_BINOP_ADD, 1, m, &cBinop_sueXsVhp_sendMessage);
}

void Heavy_prog::cCast_iVVJgDBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UwFHulMV, HV_BINOP_MULTIPLY, 0, m, &cBinop_UwFHulMV_sendMessage);
}

void Heavy_prog::cCast_pC8LOgEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J3StGAIw, HV_BINOP_DIVIDE, 0, m, &cBinop_J3StGAIw_sendMessage);
}

void Heavy_prog::cCast_yh0NlbKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHVlyy1h, HV_BINOP_SUBTRACT, 0, m, &cBinop_VHVlyy1h_sendMessage);
}

void Heavy_prog::cCast_zDMUmnRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AU4ntFFm, 1, m, &cVar_AU4ntFFm_sendMessage);
}

void Heavy_prog::cCast_rzL4YjGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AU4ntFFm, 0, m, &cVar_AU4ntFFm_sendMessage);
}

void Heavy_prog::cCast_7Y2wpYKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0h9cDXqu_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_XpvjE7Aj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ABJP8LK0, 0, m, &cVar_ABJP8LK0_sendMessage);
}

void Heavy_prog::cMsg_DVhz9UqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_qj7csiEk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Rk7VIRjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_eb0V5FPV, 1, m, &cVar_eb0V5FPV_sendMessage);
}

void Heavy_prog::cMsg_RmmM3sR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9MKW11jc, HV_BINOP_MULTIPLY, 0, m, &cBinop_9MKW11jc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_J3StGAIw, HV_BINOP_DIVIDE, 1, m, &cBinop_J3StGAIw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bIzlwcP1, 0, m, &cVar_bIzlwcP1_sendMessage);
}

void Heavy_prog::cCast_9IKqZvRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jo3J9nad_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XpvjE7Aj, HV_BINOP_ADD, 0, m, &cBinop_XpvjE7Aj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Wn2LVcec, 1, m, &cVar_Wn2LVcec_sendMessage);
}

void Heavy_prog::cCast_JGyDGxOQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DVhz9UqB_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_VHVlyy1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GHsN9tOU, HV_BINOP_DIVIDE, 0, m, &cBinop_GHsN9tOU_sendMessage);
}

void Heavy_prog::cCast_jo3J9nad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0h9cDXqu_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_xjJ7c0mZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eb0V5FPV, 0, m, &cVar_eb0V5FPV_sendMessage);
}

void Heavy_prog::cCast_qihYcUfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rk7VIRjZ_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_GjXEoKHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1BiQUunu_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_lH9kH58U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_aGm9hXG6_sendMessage);
}

void Heavy_prog::cVar_RTCxRcU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2JMcyfLW, 0, m, &cVar_2JMcyfLW_sendMessage);
}

void Heavy_prog::cVar_2JMcyfLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ibVP9RHv, HV_BINOP_MULTIPLY, 0, m, &cBinop_ibVP9RHv_sendMessage);
}

void Heavy_prog::cMsg_XdXdi1Gn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4PaVFaGy_sendMessage);
}

void Heavy_prog::cSystem_4PaVFaGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j4ieCNOH_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_ibVP9RHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lf4qSpKz_sendMessage);
}

void Heavy_prog::cBinop_Ze4CT2HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ibVP9RHv, HV_BINOP_MULTIPLY, 1, m, &cBinop_ibVP9RHv_sendMessage);
}

void Heavy_prog::cMsg_j4ieCNOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Ze4CT2HP_sendMessage);
}

void Heavy_prog::cBinop_lf4qSpKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nSnG6hHz_sendMessage);
}

void Heavy_prog::cBinop_nSnG6hHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TxdL3sLy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Huhjz27C, m);
}

void Heavy_prog::cBinop_TxdL3sLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vnii919H, m);
}

void Heavy_prog::cBinop_aGm9hXG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RTCxRcU9, 0, m, &cVar_RTCxRcU9_sendMessage);
}

void Heavy_prog::cSwitchcase_qkzlbTNS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hEfetDlA, 0, m, &cSlice_hEfetDlA_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_RA4wmrik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9FMb0lsW_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_RMG0xgME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_eVxIIQvg_sendMessage);
}

void Heavy_prog::cMsg_9FMb0lsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RMG0xgME_sendMessage);
}

void Heavy_prog::cSlice_hEfetDlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_eewsHbMM, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_RA4wmrik, 0, m, &cVar_RA4wmrik_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_eVxIIQvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3lU6YYds, m);
}

void Heavy_prog::cMsg_tFEIsMdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_fsX4PHtZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_HUNI1dWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OiKeF8J2_sendMessage);
  cMsg_tFEIsMdw_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_OiKeF8J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HUNI1dWF, 1, m, &cVar_HUNI1dWF_sendMessage);
}

void Heavy_prog::cVar_VIP7Cham_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zHQHfF9B_sendMessage);
  cMsg_45lq3xfa_sendMessage(_c, 0, m);
  cSwitchcase_QXWlfLtD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_zHQHfF9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VIP7Cham, 1, m, &cVar_VIP7Cham_sendMessage);
}

void Heavy_prog::cVar_384qgcHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cVar_X5JXEGAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_oDhP9ixZ_sendMessage);
  cSwitchcase_3DtduSHE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_oDhP9ixZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X5JXEGAq, 1, m, &cVar_X5JXEGAq_sendMessage);
}

void Heavy_prog::cCast_UYCETMFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cIf_umRfhjf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oT13qH0M_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_kt02wzks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_umRfhjf8, 1, m, &cIf_umRfhjf8_sendMessage);
}

void Heavy_prog::cVar_sskrgh2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kt02wzks, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_kt02wzks_sendMessage);
}

void Heavy_prog::cVar_sG2qIWAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_3DtduSHE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_hg6Y5fTT_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_hg6Y5fTT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7hCVeQsU_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_CbWgtpSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CbWgtpSx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CbWgtpSx, 0, m, &cDelay_CbWgtpSx_sendMessage);
  cSwitchcase_4KFaY69i_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_7hCVeQsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hg6Y5fTT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CbWgtpSx, 0, m, &cDelay_CbWgtpSx_sendMessage);
  cSwitchcase_4KFaY69i_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_zCdpXUg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xkDpkhdk_sendMessage);
}

void Heavy_prog::cSystem_xkDpkhdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wEvaVAbV_sendMessage);
}

void Heavy_prog::cVar_fex1PwmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dL3Cf0HD, HV_BINOP_MULTIPLY, 0, m, &cBinop_dL3Cf0HD_sendMessage);
}

void Heavy_prog::cMsg_hg6Y5fTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CbWgtpSx, 0, m, &cDelay_CbWgtpSx_sendMessage);
}

void Heavy_prog::cBinop_kl5XB2eB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CbWgtpSx, 2, m, &cDelay_CbWgtpSx_sendMessage);
}

void Heavy_prog::cBinop_wEvaVAbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dL3Cf0HD, HV_BINOP_MULTIPLY, 1, m, &cBinop_dL3Cf0HD_sendMessage);
}

void Heavy_prog::cBinop_dL3Cf0HD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kl5XB2eB_sendMessage);
}

void Heavy_prog::hTable_PPyQYIig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_QXWlfLtD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PM0edoLt_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nnzrAbi5_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_PM0edoLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d9MdT8pc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GUXr1uXE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_koQ7oRa5_sendMessage);
}

void Heavy_prog::cCast_nnzrAbi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F1QFnKbK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QzQ0UGao_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DqOXjsFl_sendMessage);
}

void Heavy_prog::cSystem_7h6iBN3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0pPy1VyN, HV_BINOP_SUBTRACT, 1, m, &cBinop_0pPy1VyN_sendMessage);
}

void Heavy_prog::cMsg_wCeRaWE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7h6iBN3g_sendMessage);
}

void Heavy_prog::cBinop_0pPy1VyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xB9c8l6E, HV_BINOP_DIVIDE, 0, m, &cBinop_xB9c8l6E_sendMessage);
}

void Heavy_prog::cSystem_qNdRxNqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0pPy1VyN, HV_BINOP_SUBTRACT, 0, m, &cBinop_0pPy1VyN_sendMessage);
}

void Heavy_prog::cMsg_fxiBLBOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qNdRxNqu_sendMessage);
}

void Heavy_prog::cBinop_xB9c8l6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_IFng5isa_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a3h7QGKo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GUcbGGtm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pfZ41eXm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xPYEra5M_sendMessage);
}

void Heavy_prog::cSystem_ePG46ajT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZZuzV5g0_sendMessage);
}

void Heavy_prog::cMsg_B9XVnhHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ePG46ajT_sendMessage);
}

void Heavy_prog::cBinop_ZZuzV5g0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xB9c8l6E, HV_BINOP_DIVIDE, 1, m, &cBinop_xB9c8l6E_sendMessage);
}

void Heavy_prog::cSwitchcase_IFng5isa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x453B6000: { // "2998.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mTq1rOlJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_mTq1rOlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2jgRGMOT_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_n9tE9hn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0Fp2gN0Z_sendMessage);
}

void Heavy_prog::cSystem_0Fp2gN0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZRpr1YrQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZRpr1YrQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GaT04mWS, HV_BINOP_MULTIPLY, 1, m, &cBinop_GaT04mWS_sendMessage);
}

void Heavy_prog::cSwitchcase_M9dfK8kO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_kbTaTApq_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_kbTaTApq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_es8AOS40_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_smLTstmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_smLTstmO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_smLTstmO, 0, m, &cDelay_smLTstmO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YxZRvHpC, 0, m, &cVar_YxZRvHpC_sendMessage);
}

void Heavy_prog::cCast_es8AOS40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kbTaTApq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_smLTstmO, 0, m, &cDelay_smLTstmO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YxZRvHpC, 0, m, &cVar_YxZRvHpC_sendMessage);
}

void Heavy_prog::cMsg_olEadc7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Vdeqy1M9_sendMessage);
}

void Heavy_prog::cSystem_Vdeqy1M9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zD3ndEdw_sendMessage);
}

void Heavy_prog::cVar_uNZEYs2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CSDJiBrg, HV_BINOP_MULTIPLY, 0, m, &cBinop_CSDJiBrg_sendMessage);
}

void Heavy_prog::cMsg_kbTaTApq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_smLTstmO, 0, m, &cDelay_smLTstmO_sendMessage);
}

void Heavy_prog::cBinop_XAKC0GSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_smLTstmO, 2, m, &cDelay_smLTstmO_sendMessage);
}

void Heavy_prog::cBinop_zD3ndEdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CSDJiBrg, HV_BINOP_MULTIPLY, 1, m, &cBinop_CSDJiBrg_sendMessage);
}

void Heavy_prog::cBinop_CSDJiBrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XAKC0GSQ_sendMessage);
}

void Heavy_prog::cVar_YxZRvHpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c01zmp2z, HV_BINOP_SUBTRACT, 0, m, &cBinop_c01zmp2z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_95k34mHT_sendMessage);
}

void Heavy_prog::cSwitchcase_wNSLkSQW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nKH0w9qE_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VXBfwe3W_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_nKH0w9qE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FELnZVwu, 0, m, &cVar_FELnZVwu_sendMessage);
}

void Heavy_prog::cCast_VXBfwe3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gsFikIM7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2hu80XeE_sendMessage);
}

void Heavy_prog::cSwitchcase_EpwPgG5I_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Yo9pk5Xv, 0, m, &cSlice_Yo9pk5Xv_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GcKyizcz, 0, m, &cSlice_GcKyizcz_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Fu7fc27_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_TAeBQSCg, 0, m, &cSlice_TAeBQSCg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_xWvTcEX4, 0, m, &cSlice_xWvTcEX4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qnssQ6Wy_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lS6cZNrX_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_Yo9pk5Xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ufgjGiYY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ufgjGiYY_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_GcKyizcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F3a69WSY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jc2BFjcG_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F3a69WSY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jc2BFjcG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_GCkLVHyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J5RjRo4c_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gOkevSaw_sendMessage);
}

void Heavy_prog::cVar_zhRizkkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WDaDfdrf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_WDaDfdrf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zebqp15r_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZRpr1YrQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZRpr1YrQ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_GhyJU73T, HV_BINOP_DIVIDE, 1, m, &cBinop_GhyJU73T_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_uNZEYs2k, 0, m, &cVar_uNZEYs2k_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_Zebqp15r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FdEMsD5s_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_15eX9dMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sZRTjXH1, HV_BINOP_SUBTRACT, 1, m, &cBinop_sZRTjXH1_sendMessage);
}

void Heavy_prog::cVar_OyiPk4ea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FELnZVwu, 0, m, &cVar_FELnZVwu_sendMessage);
}

void Heavy_prog::cVar_FELnZVwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IGk8fIHP, HV_BINOP_ADD, 0, m, &cBinop_IGk8fIHP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rmVd1I2, HV_BINOP_ADD, 0, m, &cBinop_0rmVd1I2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DY596Izp, 0, m, &cVar_DY596Izp_sendMessage);
}

void Heavy_prog::cSlice_TAeBQSCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J5RjRo4c_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gOkevSaw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_xWvTcEX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_haV2Y5W2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OXEkIcgu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_vXOIeDFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YxZRvHpC, 1, m, &cVar_YxZRvHpC_sendMessage);
}

void Heavy_prog::cBinop_GaT04mWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vXOIeDFU_sendMessage);
}

void Heavy_prog::cBinop_ZRpr1YrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WlCe3QAb_sendMessage);
}

void Heavy_prog::cBinop_WlCe3QAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c01zmp2z, HV_BINOP_SUBTRACT, 1, m, &cBinop_c01zmp2z_sendMessage);
}

void Heavy_prog::cBinop_c01zmp2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YxZRvHpC, 1, m, &cVar_YxZRvHpC_sendMessage);
}

void Heavy_prog::cMsg_d0xQ04iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_M9dfK8kO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_YiEZdgSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_M9dfK8kO_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rmVd1I2, HV_BINOP_ADD, 1, m, &cBinop_0rmVd1I2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IGk8fIHP, HV_BINOP_ADD, 1, m, &cBinop_IGk8fIHP_sendMessage);
}

void Heavy_prog::cBinop_95k34mHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wNSLkSQW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_IGk8fIHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FELnZVwu, 1, m, &cVar_FELnZVwu_sendMessage);
}

void Heavy_prog::cBinop_GhyJU73T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vTU3bygT, HV_BINOP_DIVIDE, 1, m, &cBinop_vTU3bygT_sendMessage);
}

void Heavy_prog::cBinop_vTU3bygT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rmVd1I2, HV_BINOP_ADD, 1, m, &cBinop_0rmVd1I2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IGk8fIHP, HV_BINOP_ADD, 1, m, &cBinop_IGk8fIHP_sendMessage);
}

void Heavy_prog::cCast_gOkevSaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GhyJU73T, HV_BINOP_DIVIDE, 0, m, &cBinop_GhyJU73T_sendMessage);
}

void Heavy_prog::cCast_J5RjRo4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GaT04mWS, HV_BINOP_MULTIPLY, 0, m, &cBinop_GaT04mWS_sendMessage);
}

void Heavy_prog::cCast_haV2Y5W2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OyiPk4ea, 1, m, &cVar_OyiPk4ea_sendMessage);
}

void Heavy_prog::cCast_OXEkIcgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sZRTjXH1, HV_BINOP_SUBTRACT, 0, m, &cBinop_sZRTjXH1_sendMessage);
}

void Heavy_prog::cCast_2hu80XeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OyiPk4ea, 0, m, &cVar_OyiPk4ea_sendMessage);
}

void Heavy_prog::cCast_gsFikIM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YiEZdgSD_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_0rmVd1I2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_15eX9dMR, 0, m, &cVar_15eX9dMR_sendMessage);
}

void Heavy_prog::cMsg_ufgjGiYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_M9dfK8kO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Dsgd3Otx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_GCkLVHyq, 1, m, &cVar_GCkLVHyq_sendMessage);
}

void Heavy_prog::cMsg_FdEMsD5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZRpr1YrQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZRpr1YrQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GhyJU73T, HV_BINOP_DIVIDE, 1, m, &cBinop_GhyJU73T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uNZEYs2k, 0, m, &cVar_uNZEYs2k_sendMessage);
}

void Heavy_prog::cCast_F3a69WSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ufgjGiYY_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_jc2BFjcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ql2wIT6H_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rmVd1I2, HV_BINOP_ADD, 0, m, &cBinop_0rmVd1I2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FELnZVwu, 1, m, &cVar_FELnZVwu_sendMessage);
}

void Heavy_prog::cBinop_sZRTjXH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vTU3bygT, HV_BINOP_DIVIDE, 0, m, &cBinop_vTU3bygT_sendMessage);
}

void Heavy_prog::cCast_ql2wIT6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YiEZdgSD_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_qnssQ6Wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d0xQ04iL_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_lS6cZNrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dsgd3Otx_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_1Fu7fc27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GCkLVHyq, 0, m, &cVar_GCkLVHyq_sendMessage);
}

void Heavy_prog::cVar_DY596Izp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UGggVA3l, m);
}

void Heavy_prog::cVar_MxKuDmT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_UwYljcj8, 0, m);
}

void Heavy_prog::cMsg_45lq3xfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_EpwPgG5I_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_XXM0YvZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_0OYrEg93_sendMessage);
}

void Heavy_prog::cBinop_0OYrEg93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MxKuDmT1, 0, m, &cVar_MxKuDmT1_sendMessage);
}

void Heavy_prog::cSwitchcase_4KFaY69i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UtD1DTpG, 0, m, &cSlice_UtD1DTpG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_modEGIVZ, 0, m, &cRandom_modEGIVZ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_XXhw3JOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jwO5LOPL_sendMessage);
}

void Heavy_prog::cUnop_jwO5LOPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_384qgcHB, 0, m, &cVar_384qgcHB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kt02wzks, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_kt02wzks_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_umRfhjf8, 0, m, &cIf_umRfhjf8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KIevsYo2_sendMessage);
}

void Heavy_prog::cRandom_modEGIVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_XXhw3JOd_sendMessage);
}

void Heavy_prog::cSlice_UtD1DTpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_modEGIVZ, 1, m, &cRandom_modEGIVZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_2ZIfrK4n_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YOQLLq78, 0, m, &cSlice_YOQLLq78_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_22fQMR0c, 0, m, &cRandom_22fQMR0c_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_oEMGdKMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Qbu4o7pY_sendMessage);
}

void Heavy_prog::cUnop_Qbu4o7pY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sG2qIWAK, 0, m, &cVar_sG2qIWAK_sendMessage);
  cSend_MYVpZiuD_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_22fQMR0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.0f, 0, m, &cBinop_oEMGdKMI_sendMessage);
}

void Heavy_prog::cSlice_YOQLLq78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_22fQMR0c, 1, m, &cRandom_22fQMR0c_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_ubTfXNzh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Xc1ClxLC, 0, m, &cSlice_Xc1ClxLC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LMs2r5Sp, 0, m, &cRandom_LMs2r5Sp_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_R2sy5rv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vgxKQ1xh_sendMessage);
}

void Heavy_prog::cUnop_vgxKQ1xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sskrgh2W, 0, m, &cVar_sskrgh2W_sendMessage);
  cSend_kd9kzGkh_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_XWjuQURi_sendMessage);
}

void Heavy_prog::cRandom_LMs2r5Sp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 54.0f, 0, m, &cBinop_R2sy5rv2_sendMessage);
}

void Heavy_prog::cSlice_Xc1ClxLC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LMs2r5Sp, 1, m, &cRandom_LMs2r5Sp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_ietxLhVi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x6FF57CB4: { // "start"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CXp1OzWW, 0, m, &cSlice_CXp1OzWW_sendMessage);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_d11pDNUV_sendMessage(_c, 0, m);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TCH7IVVL, 0, m, &cSlice_TCH7IVVL_sendMessage);
      break;
    }
    default: {
      cMsg_VWRfZoVB_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_prog::cDelay_9XGa5IEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9XGa5IEA, m);
  cMsg_d11pDNUV_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_YfpUIJT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FA3RwTl9_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_TCH7IVVL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zKNe5rZs, 2, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_YfpUIJT3, 0, m, &cVar_YfpUIJT3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_CXp1OzWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zKNe5rZs, 1, m, NULL);
      cBinop_onMessage(_c, &Context(_c)->cBinop_nFjrpsBm, HV_BINOP_SUBTRACT, 0, m, &cBinop_nFjrpsBm_sendMessage);
      break;
    }
    case 1: {
      cMsg_0Nb7eubP_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_1lxzZiIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R5B0nBLP, HV_BINOP_DIVIDE, 1, m, &cBinop_R5B0nBLP_sendMessage);
}

void Heavy_prog::cBinop_R5B0nBLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9bWHO5dC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9XGa5IEA, 1, m, &cDelay_9XGa5IEA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9XGa5IEA, 0, m, &cDelay_9XGa5IEA_sendMessage);
}

void Heavy_prog::cMsg_VWRfZoVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zKNe5rZs, 1, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nFjrpsBm, HV_BINOP_SUBTRACT, 0, m, &cBinop_nFjrpsBm_sendMessage);
}

void Heavy_prog::cSystem_T2NCQOsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nFjrpsBm, HV_BINOP_SUBTRACT, 1, m, &cBinop_nFjrpsBm_sendMessage);
}

void Heavy_prog::cMsg_FA3RwTl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T2NCQOsf_sendMessage);
}

void Heavy_prog::cBinop_nFjrpsBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_85s0a5bQ_sendMessage);
}

void Heavy_prog::cBinop_85s0a5bQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R5B0nBLP, HV_BINOP_DIVIDE, 0, m, &cBinop_R5B0nBLP_sendMessage);
}

void Heavy_prog::cMsg_9bWHO5dC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9XGa5IEA, 0, m, &cDelay_9XGa5IEA_sendMessage);
}

void Heavy_prog::cMsg_d11pDNUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zKNe5rZs, 1, m, NULL);
}

void Heavy_prog::cMsg_ACdAwgPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YHKwXO2Y_sendMessage);
}

void Heavy_prog::cSystem_YHKwXO2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1lxzZiIo_sendMessage);
}

void Heavy_prog::cMsg_0Nb7eubP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zKNe5rZs, 1, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nFjrpsBm, HV_BINOP_SUBTRACT, 0, m, &cBinop_nFjrpsBm_sendMessage);
}

void Heavy_prog::cSwitchcase_W1SrGX2V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8NLgjLqe, 0, m, &cSlice_8NLgjLqe_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_aylslc2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0dRV46sb_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_9SGameqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_6xtbo6vk_sendMessage);
}

void Heavy_prog::cBinop_6xtbo6vk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hoaUX3OS, m);
}

void Heavy_prog::cMsg_0dRV46sb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9SGameqH_sendMessage);
}

void Heavy_prog::cSlice_8NLgjLqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_Bq2c0V3v, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_Sn7Odrkg, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_aylslc2Y, 0, m, &cVar_aylslc2Y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_akVEod5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_9zhJXIbS, 0, m);
}

void Heavy_prog::cSwitchcase_PYZjJu29_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6ajlSnxY, 0, m, &cSlice_6ajlSnxY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RL3zBSyg, 0, m, &cRandom_RL3zBSyg_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_sOIlgaqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xpazNiSL_sendMessage);
}

void Heavy_prog::cUnop_xpazNiSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0h6ws5Hf_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_RL3zBSyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_sOIlgaqw_sendMessage);
}

void Heavy_prog::cSlice_6ajlSnxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RL3zBSyg, 1, m, &cRandom_RL3zBSyg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_0h6ws5Hf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_LwFe7J4k, m);
}

void Heavy_prog::cSwitchcase_KZw7WqF2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sN2unbVD, 0, m, &cSlice_sN2unbVD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_PEdetwEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3S7yXL6l_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_RrNnQwd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_38rCLaZg_sendMessage);
}

void Heavy_prog::cMsg_3S7yXL6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RrNnQwd0_sendMessage);
}

void Heavy_prog::cSlice_sN2unbVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_yKcIZGrO, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_PEdetwEy, 0, m, &cVar_PEdetwEy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_38rCLaZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ReTUxQK2, m);
}

void Heavy_prog::cVar_9S8Va8uh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cVar_lCbf1UIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_gNAGIsNv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SpoixHbv, 0, m, &cSlice_SpoixHbv_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_5VncU2TL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k9Qhjfne_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_H1uv0pjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SVRiWx7D_sendMessage);
}

void Heavy_prog::cMsg_k9Qhjfne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H1uv0pjR_sendMessage);
}

void Heavy_prog::cSlice_SpoixHbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_N8TpCNps, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_5VncU2TL, 0, m, &cVar_5VncU2TL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_SVRiWx7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_m9YXo59P, m);
}

void Heavy_prog::cBinop_aInbJWSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9S8Va8uh, 0, m, &cVar_9S8Va8uh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nA4Olnjc, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ywB4EeiF, m);
}

void Heavy_prog::cBinop_Ft4hGlJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_akVEod5b, 0, m, &cVar_akVEod5b_sendMessage);
}

void Heavy_prog::cBinop_o64VPRBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lCbf1UIG, 0, m, &cVar_lCbf1UIG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VQisEZpv, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jPwumd1c, m);
}

void Heavy_prog::cVar_9kcrKHsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_i580LAs9, 0, m);
}

void Heavy_prog::cSwitchcase_k3l1O7oU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DOKOv4O8, 0, m, &cSlice_DOKOv4O8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sVgdf4PP, 0, m, &cRandom_sVgdf4PP_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_CxQW5IMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Ze1bC2sj_sendMessage);
}

void Heavy_prog::cUnop_Ze1bC2sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tsluSZlN_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_sVgdf4PP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_CxQW5IMm_sendMessage);
}

void Heavy_prog::cSlice_DOKOv4O8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sVgdf4PP, 1, m, &cRandom_sVgdf4PP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_tsluSZlN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_JW3YSXny, m);
}

void Heavy_prog::cSwitchcase_qx8zQ0TX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_O4CEwlhw, 0, m, &cSlice_O4CEwlhw_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_QX6txJwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5wxmbJwt_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_5pwe70Hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rbyiPUUx_sendMessage);
}

void Heavy_prog::cMsg_5wxmbJwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5pwe70Hn_sendMessage);
}

void Heavy_prog::cSlice_O4CEwlhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_UDmNHYCE, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_QX6txJwj, 0, m, &cVar_QX6txJwj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_rbyiPUUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kzebaz0Q, m);
}

void Heavy_prog::cVar_MQLyADQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cVar_kleEQH7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_o4lHDxDo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bsxc2P8I, 0, m, &cSlice_bsxc2P8I_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_uUCZ4NKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qWsO6FOl_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_ZtjMJqqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rmlyRC52_sendMessage);
}

void Heavy_prog::cMsg_qWsO6FOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZtjMJqqV_sendMessage);
}

void Heavy_prog::cSlice_bsxc2P8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_HbBhbiRo, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_uUCZ4NKo, 0, m, &cVar_uUCZ4NKo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_rmlyRC52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3Hw3PUID, m);
}

void Heavy_prog::cBinop_uUR0O8ga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MQLyADQe, 0, m, &cVar_MQLyADQe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MdZrqOea, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9L6SBIsG, m);
}

void Heavy_prog::cBinop_SoSMHb31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_HcIJjuTU_sendMessage);
}

void Heavy_prog::cBinop_HcIJjuTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kleEQH7K, 0, m, &cVar_kleEQH7K_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fe0D9V86, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HhWWpn6s, m);
}

void Heavy_prog::cBinop_xrJnFlfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_uUR0O8ga_sendMessage);
}

void Heavy_prog::cBinop_JUu8uMnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9kcrKHsQ, 0, m, &cVar_9kcrKHsQ_sendMessage);
}

void Heavy_prog::cSend_MYVpZiuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EyNEZKRE_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_kd9kzGkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WclLjLcX_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_Me158qNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_occCkZ1c_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_oT13qH0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UYCETMFT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VIP7Cham, 0, m, &cVar_VIP7Cham_sendMessage);
  cSwitchcase_2ZIfrK4n_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_KIevsYo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ubTfXNzh_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_HUNI1dWF, 0, m, &cVar_HUNI1dWF_sendMessage);
}

void Heavy_prog::cCast_koQ7oRa5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wCeRaWE7_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_d9MdT8pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_GUXr1uXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ietxLhVi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_F1QFnKbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2jgRGMOT_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_QzQ0UGao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B9XVnhHn_sendMessage(_c, 0, m);
  cMsg_fxiBLBOS_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_DqOXjsFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_2jgRGMOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_ietxLhVi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_jsjBynUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_lPyQcKUb, 0, m);
}

void Heavy_prog::cCast_pfZ41eXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jsjBynUP, HV_BINOP_DIVIDE, 1, m, &cBinop_jsjBynUP_sendMessage);
}

void Heavy_prog::cCast_xPYEra5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OfkT9L8m_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_GUcbGGtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 48.0f, 0, m, &cBinop_Bvwq3sHQ_sendMessage);
}

void Heavy_prog::cCast_a3h7QGKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cBinop_Bvwq3sHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_I5pcZ7Os, m);
}

void Heavy_prog::cMsg_OfkT9L8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jsjBynUP, HV_BINOP_DIVIDE, 0, m, &cBinop_jsjBynUP_sendMessage);
}

void Heavy_prog::cBinop_XWjuQURi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fex1PwmF, 0, m, &cVar_fex1PwmF_sendMessage);
  cSend_Me158qNL_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_TsTiEUnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cReceive_JVq5U3z9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kJLe9ygk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bIzlwcP1, 0, m, &cVar_bIzlwcP1_sendMessage);
  cMsg_XdXdi1Gn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2JMcyfLW, 0, m, &cVar_2JMcyfLW_sendMessage);
  cMsg_olEadc7C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uNZEYs2k, 0, m, &cVar_uNZEYs2k_sendMessage);
  cMsg_83Dc4gVH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ABJP8LK0, 0, m, &cVar_ABJP8LK0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ydvJaGVT, 0, m, &cVar_ydvJaGVT_sendMessage);
  cMsg_n9tE9hn5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_15eX9dMR, 0, m, &cVar_15eX9dMR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zhRizkkw, 0, m, &cVar_zhRizkkw_sendMessage);
  cSwitchcase_PYZjJu29_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_k3l1O7oU_onMessage(_c, NULL, 0, m, NULL);
  cMsg_zCdpXUg6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fex1PwmF, 0, m, &cVar_fex1PwmF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YfpUIJT3, 0, m, &cVar_YfpUIJT3_sendMessage);
  cMsg_ACdAwgPx_sendMessage(_c, 0, m);
  cMsg_d11pDNUV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_X5JXEGAq, 0, m, &cVar_X5JXEGAq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RA4wmrik, 0, m, &cVar_RA4wmrik_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aylslc2Y, 0, m, &cVar_aylslc2Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PEdetwEy, 0, m, &cVar_PEdetwEy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5VncU2TL, 0, m, &cVar_5VncU2TL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QX6txJwj, 0, m, &cVar_QX6txJwj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uUCZ4NKo, 0, m, &cVar_uUCZ4NKo_sendMessage);
}

void Heavy_prog::cReceive_EyNEZKRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 400.0f, 0, m, &cBinop_XXM0YvZM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_Ft4hGlJq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_JUu8uMnW_sendMessage);
}

void Heavy_prog::cReceive_WclLjLcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_aInbJWSJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_SoSMHb31_sendMessage);
}

void Heavy_prog::cReceive_occCkZ1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_o64VPRBX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_xrJnFlfv_sendMessage);
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
    __hv_varread_i(&sVari_LwFe7J4k, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_LwFe7J4k, VIi(Bi1));
    __hv_var_k_f(VOf(Bf0), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_phasor_k_f(&sPhasor_xkU9AfC3, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_9zhJXIbS, VOf(Bf0));
    __hv_del1_f(&sDel1_Rbol7sV7, VIf(Bf0), VOf(Bf1));
    __hv_lt_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_samphold_f(&sSamphold_eX0X9rcc, VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_nA4Olnjc, VOf(Bf5));
    __hv_varread_f(&sVarf_VQisEZpv, VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_2EujnzBM, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_ReTUxQK2, VOf(Bf2));
    __hv_min_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_tabread_if(&sTabread_yKcIZGrO, VIi(Bi1), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_del1_f(&sDel1_JYJLbKEN, VIf(Bf0), VOf(Bf3));
    __hv_lt_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_aKsTdQsH, VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ywB4EeiF, VOf(Bf2));
    __hv_varread_f(&sVarf_jPwumd1c, VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_JDscnkNG, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_m9YXo59P, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_tabread_if(&sTabread_N8TpCNps, VIi(Bi1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_stoppable_f(&sTabwrite_zKNe5rZs, VIf(Bf1));
    __hv_phasor_k_f(&sPhasor_lPyQcKUb, VOf(Bf1));
    __hv_varread_f(&sVarf_I5pcZ7Os, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_hoaUX3OS, VOf(Bf1));
    __hv_min_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_Bq2c0V3v, VIi(Bi0), VOf(Bf2));
    __hv_tabread_if(&sTabread_Sn7Odrkg, VIi(Bi1), VOf(Bf0));
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_o55CTsvV, VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_3lU6YYds, VOf(Bf1));
    __hv_min_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi1));
    __hv_tabread_if(&sTabread_eewsHbMM, VIi(Bi1), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Huhjz27C, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_vnii919H, VOf(Bf5));
    __hv_rpole_f(&sRPole_VzLW55oA, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_varread_i(&sVari_JW3YSXny, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_JW3YSXny, VIi(Bi0));
    __hv_var_k_f(VOf(Bf7), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_phasor_k_f(&sPhasor_HchcDHKK, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_i580LAs9, VOf(Bf7));
    __hv_del1_f(&sDel1_cyBBRnke, VIf(Bf7), VOf(Bf1));
    __hv_lt_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_samphold_f(&sSamphold_Mdk7pS5X, VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fe0D9V86, VOf(Bf8));
    __hv_varread_f(&sVarf_MdZrqOea, VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_wVTzuI0r, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf2), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_3Hw3PUID, VOf(Bf2));
    __hv_min_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_tabread_if(&sTabread_HbBhbiRo, VIi(Bi0), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_add_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_del1_f(&sDel1_tr0bhcIW, VIf(Bf7), VOf(Bf2));
    __hv_lt_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_samphold_f(&sSamphold_ynX61apZ, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_HhWWpn6s, VOf(Bf3));
    __hv_varread_f(&sVarf_9L6SBIsG, VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_15v3gyK1, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_kzebaz0Q, VOf(Bf7));
    __hv_min_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_tabread_if(&sTabread_UDmNHYCE, VIi(Bi0), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_UwYljcj8, VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf1));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_UGggVA3l, VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

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
