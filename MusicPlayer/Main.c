#include <vorbis/vorbisfile.h>
#include <alsa/asoundlib.h>

int main()
{
    // PCM handle
    snd_pcm_t* pcmHandle;
    
    // Unsigned frames quantity 
    snd_pcm_uframes_t framesQuantity;

    // Playback device
    static char *device = "default";

    int err = snd_pcm_open(&pcmHandle, device, SND_PCM_STREAM_PLAYBACK, 0);

    if (err < 0) 
    {
        printf("Playback open error: \n");
        return 2;
    }
    else
        printf("snd_pcm_open:\t\t\tSeems OK\n");
    
    // Allocate parameters object and fill it with default values	
    snd_pcm_hw_params_t* hwParams;
    if (snd_pcm_hw_params_malloc(&hwParams) == 0)
        printf("snd_pcm_hw_params_malloc:\tSeems OK\n");

    if (snd_pcm_hw_params_any(pcmHandle, hwParams) >= 0)
        printf("snd_pcm_hw_params_any:\t\tSeems OK\n");

	if (snd_pcm_hw_params_set_access(pcmHandle, hwParams, SND_PCM_ACCESS_RW_INTERLEAVED) >= 0) 
        printf("snd_pcm_hw_params_set_access:\tSeems OK\n");

	if (snd_pcm_hw_params_set_format(pcmHandle, hwParams, SND_PCM_FORMAT_S16_LE) >= 0)
        printf("snd_pcm_hw_params_set_format:\tSeems OK\n");

	if (snd_pcm_hw_params_set_channels(pcmHandle, hwParams, 2) >= 0)
        printf("snd_pcm_hw_params_set_channels:\tSeems OK\n");

    int rate = 44100;

	if (snd_pcm_hw_params_set_rate_near(pcmHandle, hwParams, &rate, 0) >= 0) 
        printf("snd_pcm_hw_params_set_rate_near:Seems OK\n");

	if (snd_pcm_hw_params(pcmHandle, hwParams) >= 0)
        printf("snd_pcm_hw_params:\t\tSeems OK\n");

	printf("PCM name:\t\t\t'%s'\n", snd_pcm_name(pcmHandle));

	printf("PCM state:\t\t\t%s\n", snd_pcm_state_name(snd_pcm_state(pcmHandle)));

    int tmp = 0;

	snd_pcm_hw_params_get_channels(hwParams, &tmp);
	printf("channels:\t\t\t%i ", tmp);

	if (tmp == 1)
		printf("(mono)\n");
	else if (tmp == 2)
		printf("(stereo)\n");

	snd_pcm_hw_params_get_rate(hwParams, &tmp, 0);
	printf("rate:\t\t\t\t%d bps\n", tmp);

	printf("seconds:\t\t\t%d\n", 5);	

    // Allocate buffer to hold single period
    snd_pcm_hw_params_get_period_size(hwParams, &framesQuantity, 0);

	printf("frames:\t\t\t\t%lu\n", framesQuantity);	

    int bufferSize = framesQuantity * 2 * 2;
    char* buffer = (char*) malloc(bufferSize);

    OggVorbis_File vf;
    int eof = 0;
    int current_section;

    if (ov_fopen("TrashShort.ogg", &vf) == 0)
        printf("ov_fopen:\t\t\tSeems OK\n");

    vorbis_info *vi = ov_info(&vf, -1);
    printf("\nBitstream\n");
    printf("channels:\t\t\t%i\n", vi->channels);
	printf("rate:\t\t\t\t%ld Hz\n", vi->rate);

    printf("Encoded by:\t\t\t%s\n\n", ov_comment(&vf, -1)->vendor);
    //    snd_pcm_set_params(pcmHandle,SND_PCM_ACCESS_RW_INTERLEAVED, SND_PCM_FORMAT_S16_LE, 2, 44100,  

    while(!eof)
    {
        long ret = ov_read(&vf, buffer, bufferSize, 0, 2, 1, &current_section);

        if(ret == 0)
        {
            printf("end of file\n");
            eof = 1;
        }
        else if(ret < 0)
        {
            printf("error in the stream%ld\n", ret );
        }
        else
        {
            snd_pcm_sframes_t frames = snd_pcm_writei(pcmHandle, buffer, ret / 4/*framesQuantity*/);
    
            if (frames < 0)
            {
                printf("snd_pcm_writen failed: %s\n", snd_strerror(frames));
            
                if (frames == -EPIPE)
                {
                    snd_pcm_prepare(pcmHandle);
                }
                else
                {       
                    break;
                }
            }
        }
    }
    ov_clear(&vf);
    free(buffer);
    snd_pcm_drain(pcmHandle);
    snd_pcm_close(pcmHandle);
    return 1;
}

