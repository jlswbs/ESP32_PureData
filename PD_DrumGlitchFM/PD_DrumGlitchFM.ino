// FM drum glitch noodle - puredata //

#define SAMPLE_RATE 44100

#include "AudioTools.h"
#include "AudioLibs/I2SCodecStream.h"
#include "Heavy_prog.hpp"
#include "AudioLibs/PureDataStream.h"

AudioInfo info(SAMPLE_RATE, 2, 16);
Heavy_prog pd_prog(SAMPLE_RATE);
PureDataStream pd(pd_prog);
I2SCodecStream out(AudioKitAC101);
StreamCopy copier(out, pd);

void setup() {

  srand(time(NULL));

  pd.begin();

  auto cfg = out.defaultConfig();
  cfg.sd_active = false;
  cfg.copyFrom(info);
  out.begin(cfg);

}

void loop() {
  
  copier.copy();
  
}