#include "allInclude.h"


void playMusic(int sound)
{
	wchar_t musicOut[256];
	std::string musicIn{};
	
	switch (sound)
	{
	case Start_Music:
	{
		musicIn = "Music\\Music-Start.wav";
		break;
	}
	default:
		break;
	}

	for (int i{}; i < 256; i++)
	{
		musicOut[i] = musicIn[i];
	}

	PlaySound(musicOut, NULL, SND_LOOP | SND_ASYNC);
}