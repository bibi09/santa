#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__

#include "../patterns/NoCopy.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cassert>
#include <semaphore.h>
#include <map>
#include <string>

/**
 * @brief   Manager of musics and sound effects.
 * @author  Denis CARLUS
 */
class AudioManager : private NoCopy {
    private:
        /** @brief Singleton of the AudioManager handler. */
        static AudioManager* Singleton ;

        /**
         * @brief Regulate the access to the singleton to avoid concurrency
         *        problems.
         */
        static sem_t Access ;

        /** @brief  Audio device to which sounds are output. */
        ALLEGRO_VOICE* m_audioDevice ;
        /** @brief  Audio mixers to which are attached the different sounds. */
        std::map<std::string, ALLEGRO_MIXER*> m_audioMixers ;
        /** @brief  Loaded sound effects. */
        std::map<std::string, ALLEGRO_SAMPLE*> m_sounds ;
        /** @brief  Background music. */
        ALLEGRO_AUDIO_STREAM* m_bgm ;


                                            /** CONSTRUCTION AND DESTRUCTION **/
        /** @brief Construction of a SpriteManager handler. */
        AudioManager() ;

        /** @brief Destruction of the SpriteManager handler. */
        ~AudioManager() throw() ;


    public:
        /**
         * @brief Get the unique instance of ConfettiManager.
         * @return  The unique instance of ConfettiManager.
         */
        static AudioManager* getInstance() ;

        /** @brief  Load a sound. */
        void load(const std::string& name) ;

        /** @brief  Play a sound. Load it if not yet in memory. */
        void playSound(const std::string& name, bool loop = false) ;


        /** @brief  Play the given BGM. */
        void playBGM(const std::string& name) ;

        /** @brief  Stop the current BGM. */
        void stopBGM() ;
} ;

#endif
