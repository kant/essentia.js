/*
 * EssentiaMin.js 
 */

#ifndef ESSENTIAMIN_H
#define ESSENTIAMIN_H

#include <vector>

extern bool esInitStatus;

// EssentiaMin class which includes methods of some selected essentia c++ algos
class EssentiaMin {

    public:
        // to store the current essentia libray version
        std::string essentiaVersion;

        // register essentia algos
        void initState(bool debugger);
        // shutdown essentia instance
        void shutDown();

        // add your essentia example methods here and also define the methods in the essentiamin.cpp file 
        float loudnessVickers(std::vector<float>& signalFrame);
        float zeroCrossingRate(std::vector<float>& signal);
        float danceability(std::vector<float>& signal);
        // std::vector<std::vector<double> > stftExtractor(std::vector<float>& signal, int frameSize, int hopSize);
        std::string keyExtractor(std::vector<float>& signal);

        std::vector<float> windowing(std::vector<float>& signalFrame, std::string windowType);
        std::vector<float> spectrum(std::vector<float>& signalFrame);
        std::vector<float> spectrumExtractor(std::vector<float>& signal, int frameSize, int hopSize, std::string windowType);
        std::vector<float> logMelBands(std::vector<float>& spectrumFrame, int numBands);
        std::vector<float> logMelBandsExtractor(std::vector<float>& signal, int numBands, int frameSize, int hopSize, std::string windowType);
        std::vector<float> hpcp(std::vector<float>& signalFrame, bool nonLinear);
        std::vector<float> onsetRate(std::vector<float>& signal);
        std::vector<float> autoCorrelation(std::vector<float>& signal);
        std::vector<float> envelope(std::vector<float>& signal);
        std::vector<float> onsetDetectionGlobal(std::vector<float>& signal);
        std::vector<float> noveltyCurve(std::vector<float>& spectrumFrame);
        std::vector<float> superfluxNoveltyCurve(std::vector<float>& spectrumFrame);
        std::vector<float> superFluxExtractor(std::vector<float>& signal, int sampleRate, int frameSize, int hopSize);
        std::vector<std::vector<float> > frameGenerator(std::vector<float>& signal, int frameSize, int hopeSize);
        // if you want multiple returns, add void functions and pass the output vectors as input
        void chordDetection(std::vector<float>& chroma, int hopSize, std::vector<std::string>& chords, std::vector<float>& strength);
        void mfcc(std::vector<float>& signal, std::vector<float>& mfccBands, std::vector<float>& mfccCoeffs);
        void pitchYin(std::vector<float>& signalFrame, float pitch, float pitchConfidence);
        void pitchProbabilisticYinExtractor(std::vector<float>& signal, std::vector<float>& pitch, std::vector<float>& voicedProbabilities);
        void pitchMelodiaExtractor(std::vector<float>& signal, std::vector<float>& pitch, std::vector<float>& pitchConfidence);
        void predominantPitchMelodiaExtractor(std::vector<float>& signal, std::vector<float>& pitch, std::vector<float>& pitchConfidence);
        void bpmHistogram(std::vector<float>& signal, std::vector<float>& bpmEstimates, std::vector<float>& histogram);
        void key(std::vector<float>& chroma, std::string profileType, std::vector<std::string> keyFeatures, float strength);
        void beatTrackerMultiFeature(std::vector<float>& signal, std::vector<float>& ticks, float confidence);
        void loudnessEBUR128(std::vector<float>& signal, std::vector<float>& momLoudness, std::vector<float>& shortLoudness, float integrateLoudness, float loudRange);

        // add your essentia example methods here and also  define the methods in the essentiamin.cpp file
};

#endif  // ESSENTIAMIN_H
