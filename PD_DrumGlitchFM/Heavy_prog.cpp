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

float hTable_nuzpzT1g_data[256] = {0.1f, 0.206667f, 0.233333f, 0.24f, 0.266667f, 0.306666f, 0.32f, 0.333333f, 0.35f, 0.353333f, 0.383333f, 0.388333f, 0.393333f, 0.423333f, 0.443333f, 0.45f, 0.473333f, 0.478333f, 0.496666f, 0.506666f, 0.51f, 0.54f, 0.556666f, 0.566666f, 0.573333f, 0.59f, 0.6f, 0.623333f, 0.63f, 0.573333f, 0.586667f, 0.592222f, 0.597778f, 0.603333f, 0.608889f, 0.614444f, 0.62f, 0.624444f, 0.628889f, 0.633333f, 0.641111f, 0.648889f, 0.656667f, 0.661667f, 0.666667f, 0.68f, 0.681667f, 0.686667f, 0.686667f, 0.68f, 0.672222f, 0.664444f, 0.656667f, 0.645555f, 0.634444f, 0.623333f, 0.611111f, 0.598889f, 0.586667f, 0.55f, 0.513333f, 0.46f, 0.45f, 0.433333f, 0.423333f, 0.403333f, 0.396667f, 0.39f, 0.383334f, 0.371667f, 0.36f, 0.35f, 0.343334f, 0.336667f, 0.333334f, 0.326667f, 0.326667f, 0.332222f, 0.337778f, 0.343334f, 0.35f, 0.356667f, 0.363334f, 0.37f, 0.385f, 0.4f, 0.412222f, 0.424445f, 0.436667f, 0.476667f, 0.526667f, 0.546667f, 0.61f, 0.583333f, 0.551667f, 0.52f, 0.493333f, 0.466667f, 0.44f, 0.418889f, 0.397778f, 0.376667f, 0.3625f, 0.348334f, 0.334167f, 0.32f, 0.301667f, 0.283334f, 0.277778f, 0.272222f, 0.266667f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.263334f, 0.266667f, 0.27f, 0.273334f, 0.276667f, 0.28f, 0.286667f, 0.293334f, 0.3f, 0.306667f, 0.313334f, 0.321111f, 0.328889f, 0.336667f, 0.344445f, 0.352222f, 0.36f, 0.375333f, 0.390667f, 0.406f, 0.421333f, 0.436667f, 0.449583f, 0.4625f, 0.475417f, 0.488333f, 0.50125f, 0.514167f, 0.527083f, 0.54f, 0.562f, 0.584f, 0.606f, 0.628f, 0.65f, 0.665833f, 0.681667f, 0.6975f, 0.713333f, 0.736667f, 0.76f, 0.78f, 0.791666f, 0.796666f, 0.775f, 0.753333f, 0.69f, 0.646667f, 0.603333f, 0.565f, 0.526667f, 0.48f, 0.466667f, 0.453333f, 0.445f, 0.436667f, 0.433333f, 0.433333f, 0.433333f, 0.433333f, 0.435333f, 0.437333f, 0.439333f, 0.441333f, 0.443334f, 0.447667f, 0.452f, 0.456334f, 0.460667f, 0.465f, 0.469333f, 0.473667f, 0.478f, 0.482333f, 0.486667f, 0.495f, 0.503333f, 0.511667f, 0.52f, 0.528333f, 0.536667f, 0.545f, 0.553333f, 0.561667f, 0.57f, 0.58f, 0.59f, 0.6f, 0.61f, 0.62f, 0.63f, 0.64f, 0.65f, 0.662083f, 0.674167f, 0.68625f, 0.698333f, 0.710417f, 0.7225f, 0.734583f, 0.746667f, 0.757619f, 0.768571f, 0.779524f, 0.790476f, 0.801428f, 0.812381f, 0.823333f, 0.834166f, 0.845f, 0.855833f, 0.866666f, 0.876666f, 0.886666f, 0.893333f, 0.78f, 0.376667f, 0.353333f, 0.333333f, 0.31f, 0.298334f, 0.286667f, 0.266667f, 0.233334f, 0.213334f, 0.183334f, 0.143334f, 0.126667f, 0.11f, 0.101667f, 0.0833337f, 4.76837e-07f, 4.76837e-07f, -0.00333285f, -0.00333285f};
float hTable_KL1HJQti_data[256] = {0.0666637f, 0.0685156f, 0.0703675f, 0.0722193f, 0.0740712f, 0.075923f, 0.333332f, 0.333332f, 0.333332f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.808333f, 0.806667f, 0.805f, 0.803333f, 0.801667f, 0.8f, 0.7975f, 0.795f, 0.7925f, 0.79f, 0.7875f, 0.785f, 0.7825f, 0.78f, 0.778667f, 0.777333f, 0.776f, 0.774667f, 0.773333f, 0.7725f, 0.771667f, 0.770833f, 0.77f, 0.769167f, 0.768333f, 0.7675f, 0.283334f, 0.280001f, 0.276667f, 0.273334f, 0.27f, 0.267334f, 0.264667f, 0.262001f, 0.259334f, 0.256667f, 0.254001f, 0.251334f, 0.248667f, 0.246001f, 0.243334f, 0.240667f, 0.238001f, 0.235334f, 0.232667f, 0.23f, 0.228422f, 0.226843f, 0.225264f, 0.223685f, 0.222106f, 0.220527f, 0.218948f, 0.217369f, 0.21579f, 0.214211f, 0.212632f, 0.211053f, 0.209474f, 0.207895f, 0.206316f, 0.204737f, 0.203158f, 0.20158f, 0.2f, 0.198667f, 0.197334f, 0.196001f, 0.194667f, 0.193334f, 0.192001f, 0.190667f, 0.189334f, 0.188001f, 0.186667f, 0.185334f, 0.184001f, 0.182667f, 0.181334f, 0.180001f, 0.179092f, 0.178182f, 0.177273f, 0.176364f, 0.175455f, 0.174546f, 0.173637f, 0.172728f, 0.171819f, 0.17091f, 0.170001f, 0.169395f, 0.168788f, 0.168182f, 0.167576f, 0.16697f, 0.166364f, 0.165758f, 0.165152f, 0.164546f, 0.16394f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.160001f, 0.153334f, 0.153334f, 0.153334f, 0.146667f, 0.146667f, 0.156667f, 0.163334f, 0.200001f, 0.236667f, 0.268334f, 0.813333f, 0.813333f, 0.813333f, 0.8125f, 0.811667f, 0.810833f, 0.81f, 0.807778f, 0.805556f, 0.803333f, 0.801111f, 0.798889f, 0.796667f, 0.795f, 0.793333f, 0.791667f, 0.79f, 0.788333f, 0.786667f, 0.785417f, 0.784167f, 0.782917f, 0.781667f, 0.780417f, 0.779167f, 0.777917f, 0.776667f, 0.775185f, 0.773704f, 0.772222f, 0.770741f, 0.769259f, 0.767778f, 0.766296f, 0.764815f, 0.763333f, 0.7625f, 0.761667f, 0.760833f, 0.76f, 0.759167f, 0.758333f, 0.7575f, 0.756667f, 0.755833f, 0.755f, 0.754167f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.756667f, 0.756667f, 0.756667f, 0.756667f, 0.753333f, 0.751111f, 0.748889f, 0.746667f, 0.745f, 0.743333f, 0.743333f, 0.743333f, 0.743333f, 0.38f, 0.383333f, 0.385f, 0.386667f, 0.39f, 0.391667f, 0.393333f, 0.396667f, 0.403333f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_Ykw3AEXD);
  numBytes += sTabhead_init(&sTabhead_HPVYHAau, &hTable_kv2bIY6A);
  numBytes += sTabread_init(&sTabread_9yMDwR6C, &hTable_kv2bIY6A, false);
  numBytes += sTabread_init(&sTabread_h5pf87Wo, &hTable_kv2bIY6A, false);
  numBytes += sPhasor_k_init(&sPhasor_erPdmW8W, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_vBK3ls2Z);
  numBytes += sSamphold_init(&sSamphold_ZQEabB5y);
  numBytes += sPhasor_k_init(&sPhasor_1AQ2DqjP, 10.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_UREw4iNW, &hTable_nuzpzT1g, false);
  numBytes += sRPole_init(&sRPole_pnhgiBCb);
  numBytes += sDel1_init(&sDel1_YEnuWjo3);
  numBytes += sSamphold_init(&sSamphold_X8IaeoOF);
  numBytes += sPhasor_init(&sPhasor_ibjXiSpq, sampleRate);
  numBytes += sPhasor_init(&sPhasor_Psdq8390, sampleRate);
  numBytes += sLine_init(&sLine_gvnkxjuR);
  numBytes += sTabread_init(&sTabread_ZfFOeuL7, &hTable_KL1HJQti, false);
  numBytes += sLine_init(&sLine_Kerjd3a8);
  numBytes += sTabwrite_init(&sTabwrite_kREcEJmM, &hTable_kv2bIY6A);
  numBytes += sPhasor_k_init(&sPhasor_ji3oE4eZ, 10.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_aWQcdghG, &hTable_nuzpzT1g, false);
  numBytes += sRPole_init(&sRPole_Z6nAkyKQ);
  numBytes += sTabread_init(&sTabread_QfLUngTy, &hTable_nuzpzT1g, false);
  numBytes += hTable_initWithData(&hTable_nuzpzT1g, 256, hTable_nuzpzT1g_data);
  numBytes += cRandom_init(&cRandom_iFRjnh3y, -2101481850);
  numBytes += cSlice_init(&cSlice_UQYq9CSm, 1, 1);
  numBytes += sVari_init(&sVari_GGBGxgOn, 0, 0, false);
  numBytes += cVar_init_s(&cVar_r9rjkJvW, "soft");
  numBytes += cSlice_init(&cSlice_glSyblAO, 1, 1);
  numBytes += sVarf_init(&sVarf_MkaCvrmR, 0.0f, 0.0f, false);
  numBytes += hTable_initWithData(&hTable_KL1HJQti, 256, hTable_KL1HJQti_data);
  numBytes += cVar_init_s(&cVar_F5VHgwzy, "hard");
  numBytes += cSlice_init(&cSlice_KYQbPd5s, 1, 1);
  numBytes += sVarf_init(&sVarf_XXlKr2j6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_DxUVrL3h, 1.0f);
  numBytes += cVar_init_f(&cVar_tQPeVjb2, 0.0f);
  numBytes += cVar_init_f(&cVar_kYvVIphP, 0.0f);
  numBytes += cVar_init_f(&cVar_wSoIJ9Pw, 0.0f);
  numBytes += cRandom_init(&cRandom_iE4gCGb3, 1850268354);
  numBytes += cSlice_init(&cSlice_O0eDrKIC, 1, 1);
  numBytes += cBinop_init(&cBinop_nCHOFz6H, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_TQhhX0KG, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_qEPNiWFd, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_sunWIGbA, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_IjUT8mP8, 0.0f);
  numBytes += cVar_init_f(&cVar_aqeAYVLq, 30.0f);
  numBytes += cBinop_init(&cBinop_Ft36E5FH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ewdNOPhP, 1.0f);
  numBytes += cVar_init_f(&cVar_AEALBF7N, 1.0f);
  numBytes += cVar_init_s(&cVar_EucvSdgo, "soft");
  numBytes += cSlice_init(&cSlice_PZFNNC16, 1, 1);
  numBytes += sVarf_init(&sVarf_z3vyuZc9, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_W9zlk5iQ, 0.0f);
  numBytes += cVar_init_f(&cVar_Qrvaqrbh, 20.0f);
  numBytes += cBinop_init(&cBinop_tJrIzhhP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Qerh8w5B, 0.0f);
  numBytes += cSlice_init(&cSlice_H8lXfC1P, 1, -1);
  numBytes += cSlice_init(&cSlice_rnnRDYXz, 1, -1);
  numBytes += cVar_init_f(&cVar_n4mFGdls, 0.0f);
  numBytes += cVar_init_f(&cVar_Vg66aA4u, 1.0f);
  numBytes += cVar_init_f(&cVar_xlt7lUsH, 0.0f);
  numBytes += cVar_init_f(&cVar_U57XbXQp, 0.0f);
  numBytes += cVar_init_f(&cVar_TtRfMNwl, 0.0f);
  numBytes += cSlice_init(&cSlice_UwMfcEPS, 1, 1);
  numBytes += cSlice_init(&cSlice_WZ0HKVIV, 0, 1);
  numBytes += cBinop_init(&cBinop_O9wBVXyD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KUiF1cQ1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_es5Z9GdG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_w33JWraP, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dV8r74M2, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_RGOS5il8, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_55L3bROO, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Y1ft90KE, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_aSIIS7n5, 0.0f);
  numBytes += cVar_init_f(&cVar_fZ8qKUiO, 0.0f);
  numBytes += cVar_init_f(&cVar_I5fArWh3, 22050.0f);
  numBytes += cBinop_init(&cBinop_RjSW4lLh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IfohYkhI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_O1RrUHNx, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_tTst2fv8, "soft");
  numBytes += cSlice_init(&cSlice_wok2JNEI, 1, 1);
  numBytes += sVarf_init(&sVarf_MBt1ngqC, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_AUaBt1Yt, 0.0f);
  numBytes += cVar_init_f(&cVar_5Iu7Rld2, 20.0f);
  numBytes += cBinop_init(&cBinop_UgYSXcsE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_htisHQ2l, 0.0f);
  numBytes += cSlice_init(&cSlice_cJf30xBf, 1, -1);
  numBytes += cSlice_init(&cSlice_4D0043pE, 1, -1);
  numBytes += cVar_init_f(&cVar_nh8VjQex, 0.0f);
  numBytes += cVar_init_f(&cVar_31j8cvUB, 1.0f);
  numBytes += cVar_init_f(&cVar_x0prnj0y, 0.0f);
  numBytes += cVar_init_f(&cVar_Nmjgukir, 0.0f);
  numBytes += cVar_init_f(&cVar_1LhKvejM, 0.0f);
  numBytes += cSlice_init(&cSlice_NIdgkcWx, 1, 1);
  numBytes += cSlice_init(&cSlice_yZw6TnTO, 0, 1);
  numBytes += cBinop_init(&cBinop_1I2KijBq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_l5ye3p5s, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MsKs6gwO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0jFsdPUH, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_w9WXXicD, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_8zanzMir, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_BKCMMbWo, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ubm92Z2d, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_jozLOCDF, 0.0f);
  numBytes += cVar_init_f(&cVar_IUVHN0L7, 0.0f);
  numBytes += cVar_init_f(&cVar_Jk4gcy8s, 22050.0f);
  numBytes += cBinop_init(&cBinop_wHEJwGR8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UXI1IKf6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qRnoYoan, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_tAxFk9E1, -2077181193);
  numBytes += cSlice_init(&cSlice_ZpXTpqZT, 1, 1);
  numBytes += cRandom_init(&cRandom_unhbdF4x, 1629847222);
  numBytes += cSlice_init(&cSlice_4dOQoVd7, 1, 1);
  numBytes += cIf_init(&cIf_vSIY55jT, false);
  numBytes += cBinop_init(&cBinop_FASl5Cjm, 12.0f); // __gte
  numBytes += cVar_init_s(&cVar_twb7qF6o, "del-del");
  numBytes += sVarf_init(&sVarf_eICdP8Hz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bPfdTy0V, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7T227YS1, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_wRViWLVH, 0.0f);
  numBytes += cVar_init_f(&cVar_XCS22Kmc, 20.0f);
  numBytes += cBinop_init(&cBinop_wSHTRjGY, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_MGwWdfvT, 0.0f);
  numBytes += cSlice_init(&cSlice_bfEKSIeF, 1, -1);
  numBytes += cSlice_init(&cSlice_1Omtxea6, 1, -1);
  numBytes += cVar_init_f(&cVar_S5XFhRDZ, 0.0f);
  numBytes += cVar_init_f(&cVar_M8TA715B, 1.0f);
  numBytes += cVar_init_f(&cVar_6k1L62L6, 0.0f);
  numBytes += cVar_init_f(&cVar_gVPwwBFM, 0.0f);
  numBytes += cVar_init_f(&cVar_2yWpv0qW, 0.0f);
  numBytes += cSlice_init(&cSlice_ZnJiNZuF, 1, 1);
  numBytes += cSlice_init(&cSlice_DwolN8la, 0, 1);
  numBytes += cBinop_init(&cBinop_Mq6rSWJ8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RqCPsZda, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_s0TEFcHP, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9xoE2D2w, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tZjIcmyC, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Jhp9be6j, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_4IB1GIDe, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_R0IaF3h5, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_ee6TneC7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pXRykEm1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_NPmljPnG, 0.0f);
  numBytes += hTable_init(&hTable_kv2bIY6A, 256);
  numBytes += sVarf_init(&sVarf_qLGlR3FT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yIdaGMrH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_T1F29IyG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gGJiX61N, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_nuzpzT1g);
  hTable_free(&hTable_KL1HJQti);
  hTable_free(&hTable_kv2bIY6A);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x69706D21: return &hTable_nuzpzT1g; // soft
    case 0x726EF81D: return &hTable_KL1HJQti; // hard
    case 0x7BAC8768: return &hTable_kv2bIY6A; // del-del
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_waa8EF2J_sendMessage);
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


void Heavy_prog::hTable_nuzpzT1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_JjdW1993_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UQYq9CSm, 0, m, &cSlice_UQYq9CSm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iFRjnh3y, 0, m, &cRandom_iFRjnh3y_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_NY2Ilppz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_iwwUXeHe_sendMessage);
}

void Heavy_prog::cUnop_iwwUXeHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_clpOv6jY_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_iFRjnh3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_NY2Ilppz_sendMessage);
}

void Heavy_prog::cSlice_UQYq9CSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iFRjnh3y, 1, m, &cRandom_iFRjnh3y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_clpOv6jY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_GGBGxgOn, m);
}

void Heavy_prog::cSwitchcase_J71D6bgZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_glSyblAO, 0, m, &cSlice_glSyblAO_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_r9rjkJvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZZIukLk1_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_avTeegms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_AnOqAKYS_sendMessage);
}

void Heavy_prog::cMsg_ZZIukLk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_avTeegms_sendMessage);
}

void Heavy_prog::cSlice_glSyblAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_QfLUngTy, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_r9rjkJvW, 0, m, &cVar_r9rjkJvW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_AnOqAKYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MkaCvrmR, m);
}

void Heavy_prog::hTable_KL1HJQti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_zTvfRSPj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KYQbPd5s, 0, m, &cSlice_KYQbPd5s_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_F5VHgwzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MtaaXvDy_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_LBR3JZ4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2IDdSeLS_sendMessage);
}

void Heavy_prog::cMsg_MtaaXvDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LBR3JZ4Z_sendMessage);
}

void Heavy_prog::cSlice_KYQbPd5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_ZfFOeuL7, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_F5VHgwzy, 0, m, &cVar_F5VHgwzy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_2IDdSeLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XXlKr2j6, m);
}

void Heavy_prog::cVar_DxUVrL3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pjjvJEBS_sendMessage);
  cSwitchcase_xUWjomT0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_pjjvJEBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DxUVrL3h, 1, m, &cVar_DxUVrL3h_sendMessage);
}

void Heavy_prog::cVar_tQPeVjb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_erPdmW8W, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_rfqYNQwq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z33FkXCT_sendMessage);
}

void Heavy_prog::cVar_kYvVIphP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_EGN1bDiJ_sendMessage);
}

void Heavy_prog::cVar_wSoIJ9Pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_aqFodVH1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FASl5Cjm, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_FASl5Cjm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_ecpk7oFJ_sendMessage);
}

void Heavy_prog::cSwitchcase_IRQZ0JFR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_O0eDrKIC, 0, m, &cSlice_O0eDrKIC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iE4gCGb3, 0, m, &cRandom_iE4gCGb3_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_YjCnO623_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Hwqnm6tn_sendMessage);
}

void Heavy_prog::cUnop_Hwqnm6tn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kYvVIphP, 0, m, &cVar_kYvVIphP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8A89jj3p_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FASl5Cjm, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_FASl5Cjm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vSIY55jT, 0, m, &cIf_vSIY55jT_sendMessage);
}

void Heavy_prog::cRandom_iE4gCGb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 24.0f, 0, m, &cBinop_YjCnO623_sendMessage);
}

void Heavy_prog::cSlice_O0eDrKIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iE4gCGb3, 1, m, &cRandom_iE4gCGb3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_6wx6FOls_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LFbmHa8U_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_weSWcRVI_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cEImgR3r_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_LFbmHa8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bMEN0NX5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D01Tis7G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dLb5tIRX_sendMessage);
}

void Heavy_prog::cCast_weSWcRVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ED14oQoE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mryjuvq1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eNUP4730_sendMessage);
}

void Heavy_prog::cCast_cEImgR3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ydsy0ZqK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KAG9AmnE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pWYsUomG_sendMessage);
}

void Heavy_prog::cCast_n2BxcywD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nCHOFz6H, HV_BINOP_DIVIDE, 0, m, &cBinop_nCHOFz6H_sendMessage);
}

void Heavy_prog::cCast_RMOcL71L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_blY5JKFa_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_pvF4rW8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 33.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nCHOFz6H, HV_BINOP_DIVIDE, 1, m, &cBinop_nCHOFz6H_sendMessage);
}

void Heavy_prog::cCast_ydsy0ZqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_pWYsUomG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nFtCi2D8_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_KAG9AmnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PWSe6JCM_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_mryjuvq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pvF4rW8G_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ED14oQoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_eNUP4730_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nFtCi2D8_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_D01Tis7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yryTzRp7_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_dLb5tIRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nFtCi2D8_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_bMEN0NX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_blY5JKFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Kerjd3a8, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_Kerjd3a8, 0, m, NULL);
}

void Heavy_prog::cMsg_yryTzRp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 30.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nCHOFz6H, HV_BINOP_DIVIDE, 1, m, &cBinop_nCHOFz6H_sendMessage);
}

void Heavy_prog::cMsg_PWSe6JCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 36.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nCHOFz6H, HV_BINOP_DIVIDE, 1, m, &cBinop_nCHOFz6H_sendMessage);
}

void Heavy_prog::cBinop_nCHOFz6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TQhhX0KG, m);
}

void Heavy_prog::cMsg_nFtCi2D8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RMOcL71L_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n2BxcywD_sendMessage);
}

void Heavy_prog::cSwitchcase_s7aEDCE3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CqXV2mkF_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aguyhcWu_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G2OMEMKV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_CqXV2mkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2LZXkhLp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YIqxkjEf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yHUlncGX_sendMessage);
}

void Heavy_prog::cCast_aguyhcWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kzej7m4i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j8wJyg4O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Sf6UQ29C_sendMessage);
}

void Heavy_prog::cCast_G2OMEMKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5IXaMhBw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AlOE5PI8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_st8FDfl3_sendMessage);
}

void Heavy_prog::cCast_cQUR8NHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qEPNiWFd, HV_BINOP_DIVIDE, 0, m, &cBinop_qEPNiWFd_sendMessage);
}

void Heavy_prog::cCast_IWkUbgrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MbVgotP1_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_st8FDfl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RC1FLEAp_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_AlOE5PI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_27XSbg1O_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_5IXaMhBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_Sf6UQ29C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RC1FLEAp_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Kzej7m4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_j8wJyg4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fX9gt4nb_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_YIqxkjEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b8EJtlIP_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_yHUlncGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RC1FLEAp_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_2LZXkhLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_MbVgotP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_gvnkxjuR, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_gvnkxjuR, 0, m, NULL);
}

void Heavy_prog::cBinop_qEPNiWFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sunWIGbA, m);
}

void Heavy_prog::cMsg_27XSbg1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 30.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qEPNiWFd, HV_BINOP_DIVIDE, 1, m, &cBinop_qEPNiWFd_sendMessage);
}

void Heavy_prog::cMsg_b8EJtlIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 30.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qEPNiWFd, HV_BINOP_DIVIDE, 1, m, &cBinop_qEPNiWFd_sendMessage);
}

void Heavy_prog::cMsg_fX9gt4nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qEPNiWFd, HV_BINOP_DIVIDE, 1, m, &cBinop_qEPNiWFd_sendMessage);
}

void Heavy_prog::cMsg_RC1FLEAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 440.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IWkUbgrK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cQUR8NHk_sendMessage);
}

void Heavy_prog::cSwitchcase_xUWjomT0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_LHwexBMY_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_LHwexBMY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pWwWovfJ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_IjUT8mP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IjUT8mP8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IjUT8mP8, 0, m, &cDelay_IjUT8mP8_sendMessage);
  cSwitchcase_IRQZ0JFR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_j1OiuOmm_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_SQkfSwRI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_pWwWovfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LHwexBMY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IjUT8mP8, 0, m, &cDelay_IjUT8mP8_sendMessage);
  cSwitchcase_IRQZ0JFR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_j1OiuOmm_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_SQkfSwRI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Saa7gZBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DMYL7vSL_sendMessage);
}

void Heavy_prog::cSystem_DMYL7vSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b2R6isDk_sendMessage);
}

void Heavy_prog::cVar_aqeAYVLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ft36E5FH, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ft36E5FH_sendMessage);
}

void Heavy_prog::cMsg_LHwexBMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IjUT8mP8, 0, m, &cDelay_IjUT8mP8_sendMessage);
}

void Heavy_prog::cBinop_hNuEzYoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IjUT8mP8, 2, m, &cDelay_IjUT8mP8_sendMessage);
}

void Heavy_prog::cBinop_b2R6isDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ft36E5FH, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ft36E5FH_sendMessage);
}

void Heavy_prog::cBinop_Ft36E5FH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hNuEzYoi_sendMessage);
}

void Heavy_prog::cVar_ewdNOPhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bw9liKYf_sendMessage);
  cMsg_ztEY8oVJ_sendMessage(_c, 0, m);
  cMsg_NhUxuBxO_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_bw9liKYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ewdNOPhP, 1, m, &cVar_ewdNOPhP_sendMessage);
}

void Heavy_prog::cVar_AEALBF7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_A0ckeMXk_sendMessage);
  cMsg_hCOrGfes_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_A0ckeMXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AEALBF7N, 1, m, &cVar_AEALBF7N_sendMessage);
}

void Heavy_prog::cSwitchcase_r73Mg4fN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PZFNNC16, 0, m, &cSlice_PZFNNC16_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_EucvSdgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0ffbmWRG_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_4c6AoLzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_R1oRtEgf_sendMessage);
}

void Heavy_prog::cMsg_0ffbmWRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4c6AoLzp_sendMessage);
}

void Heavy_prog::cSlice_PZFNNC16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_UREw4iNW, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_EucvSdgo, 0, m, &cVar_EucvSdgo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_R1oRtEgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z3vyuZc9, m);
}

void Heavy_prog::cMsg_kruuGMiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UiXCxxhj_sendMessage);
}

void Heavy_prog::cSystem_UiXCxxhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KUiF1cQ1, HV_BINOP_MULTIPLY, 1, m, &cBinop_KUiF1cQ1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_O9wBVXyD, HV_BINOP_MULTIPLY, 1, m, &cBinop_O9wBVXyD_sendMessage);
}

void Heavy_prog::cSwitchcase_n8sK7092_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_DydsaQrF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_DydsaQrF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5sJ0zc6p_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_W9zlk5iQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_W9zlk5iQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W9zlk5iQ, 0, m, &cDelay_W9zlk5iQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qerh8w5B, 0, m, &cVar_Qerh8w5B_sendMessage);
}

void Heavy_prog::cCast_5sJ0zc6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DydsaQrF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W9zlk5iQ, 0, m, &cDelay_W9zlk5iQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qerh8w5B, 0, m, &cVar_Qerh8w5B_sendMessage);
}

void Heavy_prog::cMsg_rIKp7XP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CTDP5Dw7_sendMessage);
}

void Heavy_prog::cSystem_CTDP5Dw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Pe58yUaA_sendMessage);
}

void Heavy_prog::cVar_Qrvaqrbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tJrIzhhP, HV_BINOP_MULTIPLY, 0, m, &cBinop_tJrIzhhP_sendMessage);
}

void Heavy_prog::cMsg_DydsaQrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_W9zlk5iQ, 0, m, &cDelay_W9zlk5iQ_sendMessage);
}

void Heavy_prog::cBinop_1OucFaVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_W9zlk5iQ, 2, m, &cDelay_W9zlk5iQ_sendMessage);
}

void Heavy_prog::cBinop_Pe58yUaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tJrIzhhP, HV_BINOP_MULTIPLY, 1, m, &cBinop_tJrIzhhP_sendMessage);
}

void Heavy_prog::cBinop_tJrIzhhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1OucFaVx_sendMessage);
}

void Heavy_prog::cVar_Qerh8w5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_es5Z9GdG, HV_BINOP_SUBTRACT, 0, m, &cBinop_es5Z9GdG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Z529lOFK_sendMessage);
}

void Heavy_prog::cSwitchcase_IDQQNwxd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6tVhKinM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4Ko4arZv_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_6tVhKinM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TtRfMNwl, 0, m, &cVar_TtRfMNwl_sendMessage);
}

void Heavy_prog::cCast_4Ko4arZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_proVhYDX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WlwolUUG_sendMessage);
}

void Heavy_prog::cSwitchcase_8vG4MOS4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_H8lXfC1P, 0, m, &cSlice_H8lXfC1P_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rnnRDYXz, 0, m, &cSlice_rnnRDYXz_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jl6LFhag_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_UwMfcEPS, 0, m, &cSlice_UwMfcEPS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_WZ0HKVIV, 0, m, &cSlice_WZ0HKVIV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pw3Wmy61_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zaXsWg7x_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_H8lXfC1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_m3APV51y_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_m3APV51y_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_rnnRDYXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bfftz95Z_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3F6f63px_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bfftz95Z_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3F6f63px_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_n4mFGdls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8jc63xRy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SjFJ9cuH_sendMessage);
}

void Heavy_prog::cVar_Vg66aA4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KprmGsVx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_KprmGsVx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xnQTiEkc_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KUiF1cQ1, HV_BINOP_MULTIPLY, 0, m, &cBinop_KUiF1cQ1_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_dV8r74M2, HV_BINOP_DIVIDE, 1, m, &cBinop_dV8r74M2_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Qrvaqrbh, 0, m, &cVar_Qrvaqrbh_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_xnQTiEkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8TiMX5RJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_xlt7lUsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y1ft90KE, HV_BINOP_SUBTRACT, 1, m, &cBinop_Y1ft90KE_sendMessage);
}

void Heavy_prog::cVar_U57XbXQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TtRfMNwl, 0, m, &cVar_TtRfMNwl_sendMessage);
}

void Heavy_prog::cVar_TtRfMNwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w33JWraP, HV_BINOP_ADD, 0, m, &cBinop_w33JWraP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_55L3bROO, HV_BINOP_ADD, 0, m, &cBinop_55L3bROO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aSIIS7n5, 0, m, &cVar_aSIIS7n5_sendMessage);
}

void Heavy_prog::cSlice_UwMfcEPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8jc63xRy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SjFJ9cuH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_WZ0HKVIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6HFWuHpg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2DdTK3in_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_GJEuP0XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qerh8w5B, 1, m, &cVar_Qerh8w5B_sendMessage);
}

void Heavy_prog::cBinop_O9wBVXyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GJEuP0XV_sendMessage);
}

void Heavy_prog::cBinop_KUiF1cQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kdt0rI6k_sendMessage);
}

void Heavy_prog::cBinop_kdt0rI6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_es5Z9GdG, HV_BINOP_SUBTRACT, 1, m, &cBinop_es5Z9GdG_sendMessage);
}

void Heavy_prog::cBinop_es5Z9GdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qerh8w5B, 1, m, &cVar_Qerh8w5B_sendMessage);
}

void Heavy_prog::cMsg_TwTr0lgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_n8sK7092_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_4SE0Dl9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_n8sK7092_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_55L3bROO, HV_BINOP_ADD, 1, m, &cBinop_55L3bROO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w33JWraP, HV_BINOP_ADD, 1, m, &cBinop_w33JWraP_sendMessage);
}

void Heavy_prog::cBinop_Z529lOFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_IDQQNwxd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_w33JWraP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TtRfMNwl, 1, m, &cVar_TtRfMNwl_sendMessage);
}

void Heavy_prog::cBinop_dV8r74M2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RGOS5il8, HV_BINOP_DIVIDE, 1, m, &cBinop_RGOS5il8_sendMessage);
}

void Heavy_prog::cBinop_RGOS5il8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_55L3bROO, HV_BINOP_ADD, 1, m, &cBinop_55L3bROO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w33JWraP, HV_BINOP_ADD, 1, m, &cBinop_w33JWraP_sendMessage);
}

void Heavy_prog::cCast_8jc63xRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O9wBVXyD, HV_BINOP_MULTIPLY, 0, m, &cBinop_O9wBVXyD_sendMessage);
}

void Heavy_prog::cCast_SjFJ9cuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dV8r74M2, HV_BINOP_DIVIDE, 0, m, &cBinop_dV8r74M2_sendMessage);
}

void Heavy_prog::cCast_2DdTK3in_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y1ft90KE, HV_BINOP_SUBTRACT, 0, m, &cBinop_Y1ft90KE_sendMessage);
}

void Heavy_prog::cCast_6HFWuHpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U57XbXQp, 1, m, &cVar_U57XbXQp_sendMessage);
}

void Heavy_prog::cCast_proVhYDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4SE0Dl9D_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_WlwolUUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U57XbXQp, 0, m, &cVar_U57XbXQp_sendMessage);
}

void Heavy_prog::cBinop_55L3bROO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xlt7lUsH, 0, m, &cVar_xlt7lUsH_sendMessage);
}

void Heavy_prog::cMsg_m3APV51y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_n8sK7092_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_5Tc3rlUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_n4mFGdls, 1, m, &cVar_n4mFGdls_sendMessage);
}

void Heavy_prog::cMsg_8TiMX5RJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KUiF1cQ1, HV_BINOP_MULTIPLY, 0, m, &cBinop_KUiF1cQ1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dV8r74M2, HV_BINOP_DIVIDE, 1, m, &cBinop_dV8r74M2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qrvaqrbh, 0, m, &cVar_Qrvaqrbh_sendMessage);
}

void Heavy_prog::cCast_Bfftz95Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m3APV51y_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_3F6f63px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uFuSfIsd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_55L3bROO, HV_BINOP_ADD, 0, m, &cBinop_55L3bROO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TtRfMNwl, 1, m, &cVar_TtRfMNwl_sendMessage);
}

void Heavy_prog::cBinop_Y1ft90KE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RGOS5il8, HV_BINOP_DIVIDE, 0, m, &cBinop_RGOS5il8_sendMessage);
}

void Heavy_prog::cCast_uFuSfIsd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4SE0Dl9D_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_zaXsWg7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5Tc3rlUr_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Pw3Wmy61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TwTr0lgP_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Jl6LFhag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n4mFGdls, 0, m, &cVar_n4mFGdls_sendMessage);
}

void Heavy_prog::cVar_aSIIS7n5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_nLXvqpoj_sendMessage);
}

void Heavy_prog::cVar_fZ8qKUiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I5fArWh3, 0, m, &cVar_I5fArWh3_sendMessage);
}

void Heavy_prog::cVar_I5fArWh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RjSW4lLh, HV_BINOP_MULTIPLY, 0, m, &cBinop_RjSW4lLh_sendMessage);
}

void Heavy_prog::cMsg_5TeMyXEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Zb3Uze6Y_sendMessage);
}

void Heavy_prog::cSystem_Zb3Uze6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0ZBtW1hZ_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_RjSW4lLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ha0hao3N_sendMessage);
}

void Heavy_prog::cBinop_uiagia7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RjSW4lLh, HV_BINOP_MULTIPLY, 1, m, &cBinop_RjSW4lLh_sendMessage);
}

void Heavy_prog::cMsg_0ZBtW1hZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_uiagia7u_sendMessage);
}

void Heavy_prog::cBinop_ha0hao3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UkOruTnl_sendMessage);
}

void Heavy_prog::cBinop_UkOruTnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8scLgOU2_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_O1RrUHNx, m);
}

void Heavy_prog::cBinop_8scLgOU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IfohYkhI, m);
}

void Heavy_prog::cBinop_nLXvqpoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fZ8qKUiO, 0, m, &cVar_fZ8qKUiO_sendMessage);
}

void Heavy_prog::cMsg_hCOrGfes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_8vG4MOS4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_41vNSV0h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wok2JNEI, 0, m, &cSlice_wok2JNEI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_tTst2fv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EJ1A1Z9b_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_jxTNwxki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mlrxKBPn_sendMessage);
}

void Heavy_prog::cMsg_EJ1A1Z9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jxTNwxki_sendMessage);
}

void Heavy_prog::cSlice_wok2JNEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_aWQcdghG, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_tTst2fv8, 0, m, &cVar_tTst2fv8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_mlrxKBPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MBt1ngqC, m);
}

void Heavy_prog::cMsg_57sZdZIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DXN3Fkqp_sendMessage);
}

void Heavy_prog::cSystem_DXN3Fkqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l5ye3p5s, HV_BINOP_MULTIPLY, 1, m, &cBinop_l5ye3p5s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1I2KijBq, HV_BINOP_MULTIPLY, 1, m, &cBinop_1I2KijBq_sendMessage);
}

void Heavy_prog::cSwitchcase_9Hz0ZtfH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_8bqGRooH_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_8bqGRooH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OG0A3rca_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_AUaBt1Yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AUaBt1Yt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUaBt1Yt, 0, m, &cDelay_AUaBt1Yt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_htisHQ2l, 0, m, &cVar_htisHQ2l_sendMessage);
}

void Heavy_prog::cCast_OG0A3rca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8bqGRooH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUaBt1Yt, 0, m, &cDelay_AUaBt1Yt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_htisHQ2l, 0, m, &cVar_htisHQ2l_sendMessage);
}

void Heavy_prog::cMsg_TwsUGtYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RQiN9Zrz_sendMessage);
}

void Heavy_prog::cSystem_RQiN9Zrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bqRfFTNj_sendMessage);
}

void Heavy_prog::cVar_5Iu7Rld2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UgYSXcsE, HV_BINOP_MULTIPLY, 0, m, &cBinop_UgYSXcsE_sendMessage);
}

void Heavy_prog::cMsg_8bqGRooH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUaBt1Yt, 0, m, &cDelay_AUaBt1Yt_sendMessage);
}

void Heavy_prog::cBinop_kKkOU4NX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUaBt1Yt, 2, m, &cDelay_AUaBt1Yt_sendMessage);
}

void Heavy_prog::cBinop_bqRfFTNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UgYSXcsE, HV_BINOP_MULTIPLY, 1, m, &cBinop_UgYSXcsE_sendMessage);
}

void Heavy_prog::cBinop_UgYSXcsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kKkOU4NX_sendMessage);
}

void Heavy_prog::cVar_htisHQ2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MsKs6gwO, HV_BINOP_SUBTRACT, 0, m, &cBinop_MsKs6gwO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_BI2LReAa_sendMessage);
}

void Heavy_prog::cSwitchcase_wOhns737_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CjAJrIsV_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X0J8ynrr_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_CjAJrIsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1LhKvejM, 0, m, &cVar_1LhKvejM_sendMessage);
}

void Heavy_prog::cCast_X0J8ynrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gi5Ei4Gb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dzci19mq_sendMessage);
}

void Heavy_prog::cSwitchcase_ajBNwIlb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cJf30xBf, 0, m, &cSlice_cJf30xBf_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4D0043pE, 0, m, &cSlice_4D0043pE_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tgK1R9ww_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NIdgkcWx, 0, m, &cSlice_NIdgkcWx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_yZw6TnTO, 0, m, &cSlice_yZw6TnTO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PWhvXogz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IK6KuYb5_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_cJf30xBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_CaK458lr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_CaK458lr_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_4D0043pE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SS1hJ0xO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0S1CC99l_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SS1hJ0xO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0S1CC99l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_nh8VjQex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xyxU1is0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UbsJx1d7_sendMessage);
}

void Heavy_prog::cVar_31j8cvUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CdWdcvo0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_CdWdcvo0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H71PkCaY_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_l5ye3p5s, HV_BINOP_MULTIPLY, 0, m, &cBinop_l5ye3p5s_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_w9WXXicD, HV_BINOP_DIVIDE, 1, m, &cBinop_w9WXXicD_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_5Iu7Rld2, 0, m, &cVar_5Iu7Rld2_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_H71PkCaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sAvXbVt2_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_x0prnj0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ubm92Z2d, HV_BINOP_SUBTRACT, 1, m, &cBinop_ubm92Z2d_sendMessage);
}

void Heavy_prog::cVar_Nmjgukir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1LhKvejM, 0, m, &cVar_1LhKvejM_sendMessage);
}

void Heavy_prog::cVar_1LhKvejM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jFsdPUH, HV_BINOP_ADD, 0, m, &cBinop_0jFsdPUH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKCMMbWo, HV_BINOP_ADD, 0, m, &cBinop_BKCMMbWo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jozLOCDF, 0, m, &cVar_jozLOCDF_sendMessage);
}

void Heavy_prog::cSlice_NIdgkcWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xyxU1is0_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UbsJx1d7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_yZw6TnTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TIdo6qDJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8Jo4ysTN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_tYcMyipj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_htisHQ2l, 1, m, &cVar_htisHQ2l_sendMessage);
}

void Heavy_prog::cBinop_1I2KijBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tYcMyipj_sendMessage);
}

void Heavy_prog::cBinop_l5ye3p5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OIo4uvJh_sendMessage);
}

void Heavy_prog::cBinop_OIo4uvJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MsKs6gwO, HV_BINOP_SUBTRACT, 1, m, &cBinop_MsKs6gwO_sendMessage);
}

void Heavy_prog::cBinop_MsKs6gwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_htisHQ2l, 1, m, &cVar_htisHQ2l_sendMessage);
}

void Heavy_prog::cMsg_DGwwgz2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_9Hz0ZtfH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_NnxnJC4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_9Hz0ZtfH_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKCMMbWo, HV_BINOP_ADD, 1, m, &cBinop_BKCMMbWo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jFsdPUH, HV_BINOP_ADD, 1, m, &cBinop_0jFsdPUH_sendMessage);
}

void Heavy_prog::cBinop_BI2LReAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wOhns737_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_0jFsdPUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1LhKvejM, 1, m, &cVar_1LhKvejM_sendMessage);
}

void Heavy_prog::cBinop_w9WXXicD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8zanzMir, HV_BINOP_DIVIDE, 1, m, &cBinop_8zanzMir_sendMessage);
}

void Heavy_prog::cBinop_8zanzMir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKCMMbWo, HV_BINOP_ADD, 1, m, &cBinop_BKCMMbWo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jFsdPUH, HV_BINOP_ADD, 1, m, &cBinop_0jFsdPUH_sendMessage);
}

void Heavy_prog::cCast_xyxU1is0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1I2KijBq, HV_BINOP_MULTIPLY, 0, m, &cBinop_1I2KijBq_sendMessage);
}

void Heavy_prog::cCast_UbsJx1d7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w9WXXicD, HV_BINOP_DIVIDE, 0, m, &cBinop_w9WXXicD_sendMessage);
}

void Heavy_prog::cCast_TIdo6qDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nmjgukir, 1, m, &cVar_Nmjgukir_sendMessage);
}

void Heavy_prog::cCast_8Jo4ysTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ubm92Z2d, HV_BINOP_SUBTRACT, 0, m, &cBinop_ubm92Z2d_sendMessage);
}

void Heavy_prog::cCast_Dzci19mq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nmjgukir, 0, m, &cVar_Nmjgukir_sendMessage);
}

void Heavy_prog::cCast_Gi5Ei4Gb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NnxnJC4u_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_BKCMMbWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x0prnj0y, 0, m, &cVar_x0prnj0y_sendMessage);
}

void Heavy_prog::cMsg_CaK458lr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_9Hz0ZtfH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_8ejZVYdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nh8VjQex, 1, m, &cVar_nh8VjQex_sendMessage);
}

void Heavy_prog::cMsg_sAvXbVt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l5ye3p5s, HV_BINOP_MULTIPLY, 0, m, &cBinop_l5ye3p5s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w9WXXicD, HV_BINOP_DIVIDE, 1, m, &cBinop_w9WXXicD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5Iu7Rld2, 0, m, &cVar_5Iu7Rld2_sendMessage);
}

void Heavy_prog::cCast_SS1hJ0xO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CaK458lr_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_0S1CC99l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W300dKQv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKCMMbWo, HV_BINOP_ADD, 0, m, &cBinop_BKCMMbWo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1LhKvejM, 1, m, &cVar_1LhKvejM_sendMessage);
}

void Heavy_prog::cBinop_ubm92Z2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8zanzMir, HV_BINOP_DIVIDE, 0, m, &cBinop_8zanzMir_sendMessage);
}

void Heavy_prog::cCast_W300dKQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NnxnJC4u_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_IK6KuYb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8ejZVYdw_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_tgK1R9ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nh8VjQex, 0, m, &cVar_nh8VjQex_sendMessage);
}

void Heavy_prog::cCast_PWhvXogz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DGwwgz2b_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_jozLOCDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_DYbYqwLH_sendMessage);
}

void Heavy_prog::cVar_IUVHN0L7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jk4gcy8s, 0, m, &cVar_Jk4gcy8s_sendMessage);
}

void Heavy_prog::cVar_Jk4gcy8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wHEJwGR8, HV_BINOP_MULTIPLY, 0, m, &cBinop_wHEJwGR8_sendMessage);
}

void Heavy_prog::cMsg_pp5zErPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xIahGpzx_sendMessage);
}

void Heavy_prog::cSystem_xIahGpzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tAZSZw6z_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_wHEJwGR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hxARYA78_sendMessage);
}

void Heavy_prog::cBinop_SqWqy16c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wHEJwGR8, HV_BINOP_MULTIPLY, 1, m, &cBinop_wHEJwGR8_sendMessage);
}

void Heavy_prog::cMsg_tAZSZw6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SqWqy16c_sendMessage);
}

void Heavy_prog::cBinop_hxARYA78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MmRjM415_sendMessage);
}

void Heavy_prog::cBinop_MmRjM415_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_AoiBMly8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qRnoYoan, m);
}

void Heavy_prog::cBinop_AoiBMly8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UXI1IKf6, m);
}

void Heavy_prog::cBinop_DYbYqwLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IUVHN0L7, 0, m, &cVar_IUVHN0L7_sendMessage);
}

void Heavy_prog::cMsg_ztEY8oVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_ajBNwIlb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_j1OiuOmm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZpXTpqZT, 0, m, &cSlice_ZpXTpqZT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tAxFk9E1, 0, m, &cRandom_tAxFk9E1_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_HXAl4Xdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KubztpGp_sendMessage);
}

void Heavy_prog::cUnop_KubztpGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tQPeVjb2, 0, m, &cVar_tQPeVjb2_sendMessage);
}

void Heavy_prog::cRandom_tAxFk9E1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_HXAl4Xdd_sendMessage);
}

void Heavy_prog::cSlice_ZpXTpqZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tAxFk9E1, 1, m, &cRandom_tAxFk9E1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_SQkfSwRI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4dOQoVd7, 0, m, &cSlice_4dOQoVd7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_unhbdF4x, 0, m, &cRandom_unhbdF4x_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_FNCl2a63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_h3WHG3rr_sendMessage);
}

void Heavy_prog::cUnop_h3WHG3rr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wSoIJ9Pw, 0, m, &cVar_wSoIJ9Pw_sendMessage);
}

void Heavy_prog::cRandom_unhbdF4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 32.0f, 0, m, &cBinop_FNCl2a63_sendMessage);
}

void Heavy_prog::cSlice_4dOQoVd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_unhbdF4x, 1, m, &cRandom_unhbdF4x_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cIf_vSIY55jT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Pk4Fpr6y_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_EFmYu4i9_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_FASl5Cjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vSIY55jT, 1, m, &cIf_vSIY55jT_sendMessage);
}

void Heavy_prog::cMsg_R8rOMnvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FjT3ShJf_sendMessage);
}

void Heavy_prog::cSystem_FjT3ShJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9pk1JQxE_sendMessage);
}

void Heavy_prog::cVar_twb7qF6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_87Gu8wa1_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_q01Avk4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ppPGzp8v_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eICdP8Hz, m);
}

void Heavy_prog::cBinop_9pk1JQxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bPfdTy0V, m);
}

void Heavy_prog::cMsg_87Gu8wa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_q01Avk4o_sendMessage);
}

void Heavy_prog::cBinop_ppPGzp8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7T227YS1, m);
}

void Heavy_prog::cMsg_xMmWQrv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9pmOWw9x_sendMessage);
}

void Heavy_prog::cSystem_9pmOWw9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqCPsZda, HV_BINOP_MULTIPLY, 1, m, &cBinop_RqCPsZda_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mq6rSWJ8, HV_BINOP_MULTIPLY, 1, m, &cBinop_Mq6rSWJ8_sendMessage);
}

void Heavy_prog::cSwitchcase_Kc7bJjaN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_KlN6je1O_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_KlN6je1O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NVpS0lgH_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_wRViWLVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wRViWLVH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wRViWLVH, 0, m, &cDelay_wRViWLVH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MGwWdfvT, 0, m, &cVar_MGwWdfvT_sendMessage);
}

void Heavy_prog::cCast_NVpS0lgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KlN6je1O_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wRViWLVH, 0, m, &cDelay_wRViWLVH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MGwWdfvT, 0, m, &cVar_MGwWdfvT_sendMessage);
}

void Heavy_prog::cMsg_gCT6CZnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_emVtbEt9_sendMessage);
}

void Heavy_prog::cSystem_emVtbEt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cpEKY77g_sendMessage);
}

void Heavy_prog::cVar_XCS22Kmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wSHTRjGY, HV_BINOP_MULTIPLY, 0, m, &cBinop_wSHTRjGY_sendMessage);
}

void Heavy_prog::cMsg_KlN6je1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wRViWLVH, 0, m, &cDelay_wRViWLVH_sendMessage);
}

void Heavy_prog::cBinop_0c5RYVry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wRViWLVH, 2, m, &cDelay_wRViWLVH_sendMessage);
}

void Heavy_prog::cBinop_cpEKY77g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wSHTRjGY, HV_BINOP_MULTIPLY, 1, m, &cBinop_wSHTRjGY_sendMessage);
}

void Heavy_prog::cBinop_wSHTRjGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0c5RYVry_sendMessage);
}

void Heavy_prog::cVar_MGwWdfvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s0TEFcHP, HV_BINOP_SUBTRACT, 0, m, &cBinop_s0TEFcHP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_aPMVGDek_sendMessage);
}

void Heavy_prog::cSwitchcase_FQLyIiaT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YQ1ct3CM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RyHMq1tI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_YQ1ct3CM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2yWpv0qW, 0, m, &cVar_2yWpv0qW_sendMessage);
}

void Heavy_prog::cCast_RyHMq1tI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mJFnzDM8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qUfnLS8x_sendMessage);
}

void Heavy_prog::cSwitchcase_3b3dkkmD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bfEKSIeF, 0, m, &cSlice_bfEKSIeF_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1Omtxea6, 0, m, &cSlice_1Omtxea6_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m1XZX2AS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZnJiNZuF, 0, m, &cSlice_ZnJiNZuF_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DwolN8la, 0, m, &cSlice_DwolN8la_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G2J5P0zW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D8Iz8AX2_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_bfEKSIeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_lco4znAJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_lco4znAJ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_1Omtxea6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_US14cFOI_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8DV8jKZh_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_US14cFOI_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8DV8jKZh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_S5XFhRDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JL1xHtE5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2VEKRMl0_sendMessage);
}

void Heavy_prog::cVar_M8TA715B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Q11GofMt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_Q11GofMt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jUEQ9dXc_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RqCPsZda, HV_BINOP_MULTIPLY, 0, m, &cBinop_RqCPsZda_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_tZjIcmyC, HV_BINOP_DIVIDE, 1, m, &cBinop_tZjIcmyC_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_XCS22Kmc, 0, m, &cVar_XCS22Kmc_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_jUEQ9dXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HqH8IFLb_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_6k1L62L6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0IaF3h5, HV_BINOP_SUBTRACT, 1, m, &cBinop_R0IaF3h5_sendMessage);
}

void Heavy_prog::cVar_gVPwwBFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2yWpv0qW, 0, m, &cVar_2yWpv0qW_sendMessage);
}

void Heavy_prog::cVar_2yWpv0qW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9xoE2D2w, HV_BINOP_ADD, 0, m, &cBinop_9xoE2D2w_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IB1GIDe, HV_BINOP_ADD, 0, m, &cBinop_4IB1GIDe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ee6TneC7, 0, m, &cVar_ee6TneC7_sendMessage);
}

void Heavy_prog::cSlice_ZnJiNZuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JL1xHtE5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2VEKRMl0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_DwolN8la_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5nS06Iam_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O22Qr14U_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_xGYZ9UMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MGwWdfvT, 1, m, &cVar_MGwWdfvT_sendMessage);
}

void Heavy_prog::cBinop_Mq6rSWJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xGYZ9UMW_sendMessage);
}

void Heavy_prog::cBinop_RqCPsZda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TrfVVWvE_sendMessage);
}

void Heavy_prog::cBinop_TrfVVWvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s0TEFcHP, HV_BINOP_SUBTRACT, 1, m, &cBinop_s0TEFcHP_sendMessage);
}

void Heavy_prog::cBinop_s0TEFcHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MGwWdfvT, 1, m, &cVar_MGwWdfvT_sendMessage);
}

void Heavy_prog::cMsg_2xTijhzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Kc7bJjaN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_ReLfzNRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Kc7bJjaN_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IB1GIDe, HV_BINOP_ADD, 1, m, &cBinop_4IB1GIDe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9xoE2D2w, HV_BINOP_ADD, 1, m, &cBinop_9xoE2D2w_sendMessage);
}

void Heavy_prog::cBinop_aPMVGDek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FQLyIiaT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_9xoE2D2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2yWpv0qW, 1, m, &cVar_2yWpv0qW_sendMessage);
}

void Heavy_prog::cBinop_tZjIcmyC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jhp9be6j, HV_BINOP_DIVIDE, 1, m, &cBinop_Jhp9be6j_sendMessage);
}

void Heavy_prog::cBinop_Jhp9be6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IB1GIDe, HV_BINOP_ADD, 1, m, &cBinop_4IB1GIDe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9xoE2D2w, HV_BINOP_ADD, 1, m, &cBinop_9xoE2D2w_sendMessage);
}

void Heavy_prog::cCast_2VEKRMl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tZjIcmyC, HV_BINOP_DIVIDE, 0, m, &cBinop_tZjIcmyC_sendMessage);
}

void Heavy_prog::cCast_JL1xHtE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mq6rSWJ8, HV_BINOP_MULTIPLY, 0, m, &cBinop_Mq6rSWJ8_sendMessage);
}

void Heavy_prog::cCast_O22Qr14U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0IaF3h5, HV_BINOP_SUBTRACT, 0, m, &cBinop_R0IaF3h5_sendMessage);
}

void Heavy_prog::cCast_5nS06Iam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gVPwwBFM, 1, m, &cVar_gVPwwBFM_sendMessage);
}

void Heavy_prog::cCast_qUfnLS8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gVPwwBFM, 0, m, &cVar_gVPwwBFM_sendMessage);
}

void Heavy_prog::cCast_mJFnzDM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ReLfzNRr_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_4IB1GIDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6k1L62L6, 0, m, &cVar_6k1L62L6_sendMessage);
}

void Heavy_prog::cMsg_lco4znAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Kc7bJjaN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Ta01QEpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_S5XFhRDZ, 1, m, &cVar_S5XFhRDZ_sendMessage);
}

void Heavy_prog::cMsg_HqH8IFLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqCPsZda, HV_BINOP_MULTIPLY, 0, m, &cBinop_RqCPsZda_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tZjIcmyC, HV_BINOP_DIVIDE, 1, m, &cBinop_tZjIcmyC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XCS22Kmc, 0, m, &cVar_XCS22Kmc_sendMessage);
}

void Heavy_prog::cCast_US14cFOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lco4znAJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_8DV8jKZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XYbwYLEm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IB1GIDe, HV_BINOP_ADD, 0, m, &cBinop_4IB1GIDe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2yWpv0qW, 1, m, &cVar_2yWpv0qW_sendMessage);
}

void Heavy_prog::cBinop_R0IaF3h5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jhp9be6j, HV_BINOP_DIVIDE, 0, m, &cBinop_Jhp9be6j_sendMessage);
}

void Heavy_prog::cCast_XYbwYLEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ReLfzNRr_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_D8Iz8AX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ta01QEpa_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_m1XZX2AS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S5XFhRDZ, 0, m, &cVar_S5XFhRDZ_sendMessage);
}

void Heavy_prog::cCast_G2J5P0zW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2xTijhzv_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_ee6TneC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_QrwhD9I9_sendMessage);
}

void Heavy_prog::cMsg_G7ZYSRX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qz2pNPsz_sendMessage);
}

void Heavy_prog::cSystem_qz2pNPsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iVkcPFdt_sendMessage);
}

void Heavy_prog::cDelay_pXRykEm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pXRykEm1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NPmljPnG, 0, m, &cDelay_NPmljPnG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pXRykEm1, 0, m, &cDelay_pXRykEm1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kREcEJmM, 1, m, NULL);
}

void Heavy_prog::cDelay_NPmljPnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NPmljPnG, m);
  cMsg_fgRJwrBq_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_rbGlZLJ5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NPZ8Sjmx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_zH935PqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1ysdrbpe_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_kv2bIY6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hxe22jWt_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pXRykEm1, 2, m, &cDelay_pXRykEm1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mvuz9BJa_sendMessage);
}

void Heavy_prog::cMsg_1ysdrbpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_kv2bIY6A, 0, m, &hTable_kv2bIY6A_sendMessage);
}

void Heavy_prog::cBinop_iVkcPFdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_zH935PqI_sendMessage);
}

void Heavy_prog::cMsg_fgRJwrBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_kv2bIY6A, 0, m, &hTable_kv2bIY6A_sendMessage);
}

void Heavy_prog::cCast_Mvuz9BJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pXRykEm1, 0, m, &cDelay_pXRykEm1_sendMessage);
}

void Heavy_prog::cMsg_hxe22jWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_NPmljPnG, 2, m, &cDelay_NPmljPnG_sendMessage);
}

void Heavy_prog::cMsg_NPZ8Sjmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kREcEJmM, 1, m, NULL);
}

void Heavy_prog::cBinop_aqFodVH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ji3oE4eZ, 0, m);
}

void Heavy_prog::cBinop_rfqYNQwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1AQ2DqjP, 0, m);
}

void Heavy_prog::cMsg_EFmYu4i9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_s7aEDCE3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Pk4Fpr6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_6wx6FOls_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_8A89jj3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ewdNOPhP, 0, m, &cVar_ewdNOPhP_sendMessage);
}

void Heavy_prog::cCast_Z33FkXCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AEALBF7N, 0, m, &cVar_AEALBF7N_sendMessage);
}

void Heavy_prog::cBinop_EGN1bDiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qLGlR3FT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_T1F29IyG, m);
}

void Heavy_prog::cMsg_e6GEp7Ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ykw3AEXD, 0, m, NULL);
}

void Heavy_prog::cBinop_ecpk7oFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aqeAYVLq, 0, m, &cVar_aqeAYVLq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yIdaGMrH, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gGJiX61N, m);
}

void Heavy_prog::cMsg_NhUxuBxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1800.0f);
  cSwitchcase_3b3dkkmD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_QrwhD9I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e6GEp7Ta_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_waa8EF2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rIKp7XP2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Qrvaqrbh, 0, m, &cVar_Qrvaqrbh_sendMessage);
  cMsg_5TeMyXEV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I5fArWh3, 0, m, &cVar_I5fArWh3_sendMessage);
  cMsg_TwsUGtYW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5Iu7Rld2, 0, m, &cVar_5Iu7Rld2_sendMessage);
  cMsg_pp5zErPN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Jk4gcy8s, 0, m, &cVar_Jk4gcy8s_sendMessage);
  cMsg_kruuGMiQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xlt7lUsH, 0, m, &cVar_xlt7lUsH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Vg66aA4u, 0, m, &cVar_Vg66aA4u_sendMessage);
  cMsg_57sZdZIa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x0prnj0y, 0, m, &cVar_x0prnj0y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_31j8cvUB, 0, m, &cVar_31j8cvUB_sendMessage);
  cMsg_gCT6CZnp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XCS22Kmc, 0, m, &cVar_XCS22Kmc_sendMessage);
  cSwitchcase_JjdW1993_onMessage(_c, NULL, 0, m, NULL);
  cMsg_Saa7gZBg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aqeAYVLq, 0, m, &cVar_aqeAYVLq_sendMessage);
  cMsg_xMmWQrv4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6k1L62L6, 0, m, &cVar_6k1L62L6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M8TA715B, 0, m, &cVar_M8TA715B_sendMessage);
  cMsg_G7ZYSRX7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DxUVrL3h, 0, m, &cVar_DxUVrL3h_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_r9rjkJvW, 0, m, &cVar_r9rjkJvW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_F5VHgwzy, 0, m, &cVar_F5VHgwzy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EucvSdgo, 0, m, &cVar_EucvSdgo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tTst2fv8, 0, m, &cVar_tTst2fv8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_twb7qF6o, 0, m, &cVar_twb7qF6o_sendMessage);
  cMsg_R8rOMnvZ_sendMessage(_c, 0, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16;
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
    __hv_line_f(&sLine_Ykw3AEXD, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_HPVYHAau, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_bPfdTy0V, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_7T227YS1, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_varread_f(&sVarf_eICdP8Hz, VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_9yMDwR6C, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_h5pf87Wo, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_varread_i(&sVari_GGBGxgOn, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_GGBGxgOn, VIi(Bi1));
    __hv_abs_f(VIf(Bf1), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_erPdmW8W, VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_del1_f(&sDel1_vBK3ls2Z, VIf(Bf6), VOf(Bf5));
    __hv_lt_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_samphold_f(&sSamphold_ZQEabB5y, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_1AQ2DqjP, VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_z3vyuZc9, VOf(Bf7));
    __hv_min_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_tabread_if(&sTabread_UREw4iNW, VIi(Bi1), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_O1RrUHNx, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_IfohYkhI, VOf(Bf7));
    __hv_rpole_f(&sRPole_pnhgiBCb, VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_del1_f(&sDel1_YEnuWjo3, VIf(Bf4), VOf(Bf10));
    __hv_lt_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_samphold_f(&sSamphold_X8IaeoOF, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_qLGlR3FT, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_T1F29IyG, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_gGJiX61N, VOf(Bf9));
    __hv_fma_f(VIf(Bf11), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_phasor_f(&sPhasor_ibjXiSpq, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf12), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf13), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf11), VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf9), VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_yIdaGMrH, VOf(Bf12));
    __hv_fma_f(VIf(Bf3), VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_phasor_f(&sPhasor_Psdq8390, VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf13), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_gvnkxjuR, VOf(Bf13));
    __hv_varread_f(&sVarf_sunWIGbA, VOf(Bf12));
    __hv_mul_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf11));
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_abs_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf11));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf14), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf11), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf15), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf3), VIf(Bf15), VOf(Bf13));
    __hv_var_k_f(VOf(Bf14), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_XXlKr2j6, VOf(Bf4));
    __hv_min_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_cast_fi(VIf(Bf14), VOi(Bi1));
    __hv_tabread_if(&sTabread_ZfFOeuL7, VIi(Bi1), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_Kerjd3a8, VOf(Bf13));
    __hv_varread_f(&sVarf_TQhhX0KG, VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf11));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf14), 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f);
    __hv_mul_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf13));
    __hv_add_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf13), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_kREcEJmM, VIf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf0), VOf(Bf13));
    __hv_var_k_f(VOf(Bf2), 0.002f, 0.002f, 0.002f, 0.002f, 0.002f, 0.002f, 0.002f, 0.002f);
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_ji3oE4eZ, VOf(Bf2));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_abs_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf13), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf13), VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf1), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_MBt1ngqC, VOf(Bf13));
    __hv_min_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_tabread_if(&sTabread_aWQcdghG, VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf13), 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_qRnoYoan, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_UXI1IKf6, VOf(Bf13));
    __hv_rpole_f(&sRPole_Z6nAkyKQ, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf8), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_MkaCvrmR, VOf(Bf6));
    __hv_min_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi1));
    __hv_tabread_if(&sTabread_QfLUngTy, VIi(Bi1), VOf(Bf8));
    __hv_mul_f(VIf(Bf15), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf13), VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf10), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf14), 0.002f, 0.002f, 0.002f, 0.002f, 0.002f, 0.002f, 0.002f, 0.002f);
    __hv_mul_f(VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf14), VIf(O1), VOf(O1));

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
