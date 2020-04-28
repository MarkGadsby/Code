#include "MusicPlayer.h"

const int SAMPLE_RATE = 44100;          // frequency in Hz

void OpenPCM(snd_pcm_t** ppcmHandle)
{
    // Playback device
//    static char *device = "default";
    
    // Opens a PCM
    if (snd_pcm_open(ppcmHandle, "default", SND_PCM_STREAM_PLAYBACK, 0) < 0)
        printf("snd_pcm_open error\n");
}

unsigned long SetupPCM(snd_pcm_t* pcmHandle)
{
    snd_pcm_hw_params_t* hwParams;

    // Allocate an invalid snd_pcm_hw_params_t using standard malloc 
    if (snd_pcm_hw_params_malloc(&hwParams) < 0)
        printf("snd_pcm_hw_params_malloc error\n");

    // The configuration space will be filled with all possible ranges for the PCM device
    if (snd_pcm_hw_params_any(pcmHandle, hwParams) < 0)
        printf("snd_pcm_hw_params_any error\n");

    // Restrict a configuration space to contain only the interleaved access type 
	if (snd_pcm_hw_params_set_access(pcmHandle, hwParams, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) 
        printf("snd_pcm_hw_params_set_access error\n");

    // Restrict a configuration space to contain only signed 16 bit little endian format 
	if (snd_pcm_hw_params_set_format(pcmHandle, hwParams, SND_PCM_FORMAT_S16_LE) < 0)
        printf("snd_pcm_hw_params_set_format error\n");

    // Restrict a configuration space to contain two channels, stereo 
	if (snd_pcm_hw_params_set_channels(pcmHandle, hwParams, 2) < 0)
        printf("snd_pcm_hw_params_set_channels error\n");

    // Restrict a configuration space to have a sample rate nearest to a 44100hZ 
    unsigned int rate = SAMPLE_RATE;
	if (snd_pcm_hw_params_set_rate_near(pcmHandle, hwParams, &rate, 0) < 0) 
        printf("snd_pcm_hw_params_set_rate_near error\n");

    // Install one PCM hardware configuration chosen from a configuration space
	if (snd_pcm_hw_params(pcmHandle, hwParams) < 0)
        printf("snd_pcm_hw_params error\n");

    // Extract period size from a configuration space
    unsigned long periodSize;
    if (snd_pcm_hw_params_get_period_size(hwParams, &periodSize, 0) < 0)
        printf("snd_pcm_hw_params_get_period_size error\n");

    // Prepare PCM for use 
    if (snd_pcm_prepare(pcmHandle) < 0)
        printf("snd_pcm_prepar error\n");

	printf("PCM state:\t%s\n", snd_pcm_state_name(snd_pcm_state(pcmHandle)));
    return periodSize;
} 
