///////////////////////////////////////////////////////////////////////
// Main.C For the MusicPlayer program.
//
// Advanced Linux Sound Architecture (ALSA) is a software framework and 
// part of the Linux kernel that provides an application programming 
// interface (API) for sound card device drivers. 
//
// Vorbis is the Ogg Vorbis audio coding format 
//
// To build this file:
// 
// gcc -Wall Main.c -o MusicPlayer -lasound -lvorbisfile 
//
// This file will use the alsa lib to set up the pulse-code modulation interface 
// (PCM) to play output and use the vorbis lib to read in a .ogg file and pass
// it to the PCM
///////////////////////////////////////////////////////////////////////
#include <alsa/asoundlib.h>
#include <vorbis/vorbisfile.h>
#include <linux/limits.h>
#include <dirent.h>
#include "MusicPlayer.h"

const int SAMPLE_RATE = 44100;          // frequency in Hz

int main()
{
    DIR*            dir;
    struct dirent*  ent;
    char trackArray[30][NAME_MAX];
    memset(trackArray, 0, 30 * NAME_MAX);
    
    if (dir = opendir ("/home/mark/Music/Rival Consoles/Persona"))
    {
        int rowIndex = 0;
        while (ent = readdir(dir)) 
        {
            if (strstr(ent->d_name, ".ogg"))   
                strcpy(&trackArray[rowIndex++][0],ent->d_name);
        }
        closedir(dir);
    } 

    chdir("/home/mark/Music/Rival Consoles/Persona");


    int i = 0;

    while (trackArray[i][0])
    {
        printf("%d\t-\t%s\n", i, &trackArray[i][0]);
    
        snd_pcm_t* pcmHandle = NULL;        // PCM handle

        OpenPCM(&pcmHandle);
        unsigned long pcmPeriodSize = SetupPCM(pcmHandle);
        
        // Allocate buffer to hold a single PCM period
        // bufferSize = PCM period * 2 channels * 2 byte format
        int bufferSize = pcmPeriodSize * 2 * 2;
        char* buffer = (char*) malloc(bufferSize);

        OggVorbis_File vf;

        if (ov_fopen(&trackArray[i++][0], &vf) < 0)
            printf("ov_fopen error\n");

        int current_section = 0;
        long bytesRead = 0;

        do  // pass a buffer of data from the file to the PCM 
        {
            bytesRead = ov_read(&vf, buffer, bufferSize, 0, 2, 1, &current_section);

            // bytesRead will four times as large as snd_pcm_writei is expecting 
            // (2 channels, 2 byte data format)  
            if (snd_pcm_writei(pcmHandle, buffer, bytesRead / 4) < 0) 
                break;
        }
        while(bytesRead);

        ov_clear(&vf);              // clear the decoder's buffers
        free(buffer);               // free the buffer memory
        snd_pcm_drain(pcmHandle);   // stop a PCM preserving pending frames
        snd_pcm_close(pcmHandle);   // close PCM handle 
    }

    return 1;
}

void OpenPCM(snd_pcm_t** ppcmHandle)
{
    // Playback device
    static char *device = "default";
    
    // Opens a PCM
    if (snd_pcm_open(ppcmHandle, device, SND_PCM_STREAM_PLAYBACK, 0) < 0)
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