#include "AudioManager.h"
#include "../Logger.h"
#include <iostream>

using namespace std ;

AudioManager* AudioManager::Singleton = 0 ;
sem_t AudioManager::Access ;


AudioManager::AudioManager() {
    assert(sem_init(&Access, 0, 1) == 0) ;
    assert(al_install_audio()) ;
    assert(al_init_acodec_addon()) ;
    m_bgm = 0 ;

    // Set up the audio device and mixers
    m_audioDevice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2) ;
    m_audioMixers["sfx"] = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2) ;
    m_audioMixers["bgm"] = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2) ;
    m_audioMixers["master"] = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2) ;

    al_attach_mixer_to_mixer(m_audioMixers["sfx"], m_audioMixers["master"]) ;
    al_attach_mixer_to_mixer(m_audioMixers["bgm"], m_audioMixers["master"]) ;
    al_attach_mixer_to_voice(m_audioMixers["master"], m_audioDevice) ;
}


AudioManager::~AudioManager() throw() {
    sem_destroy(&Access) ;

    stopBGM() ;
	for (SampleIterator it = m_sounds.begin() ; it != m_sounds.end() ; it++)
        al_destroy_sample(it -> second) ;
}


AudioManager* AudioManager::getInstance() {
    if (Singleton == 0)
        Singleton = new AudioManager() ;

    return Singleton ;
}


void AudioManager::load(const string& name) {
    // Load the sound if needed
    if (m_sounds.count(name) == 0) {
        string path = "media/sfx/" + name + ".wav" ;
        #ifdef DEBUG
        Logger::print("Load sound: " + path) ;
        #endif
        al_reserve_samples(m_sounds.size() + 1) ;
        m_sounds[name] = al_load_sample(path.c_str()) ;
    }
}


void AudioManager::playSound(const string& name, bool loop) {
    ALLEGRO_PLAYMODE mode ;
    mode = (loop) ? ALLEGRO_PLAYMODE_LOOP : ALLEGRO_PLAYMODE_ONCE ;

    sem_wait(&Access) ;
    load(name) ;
//    // Load the sound if needed
//    if (m_sounds.count(name) == 0) {
//        string path = "media/sfx/" + name + ".wav" ;
//        #ifdef DEBUG
//        Logger::print("Load sound: " + path) ;
//        #endif
//        al_reserve_samples(m_sounds.size() + 1) ;
//        m_sounds[name] = al_load_sample(path.c_str()) ;
//    }

    // Play the sound
    ALLEGRO_SAMPLE_INSTANCE* sndInstance = al_create_sample_instance(m_sounds[name]) ;
    al_attach_sample_instance_to_mixer(sndInstance, m_audioMixers["sfx"]) ;
    al_set_sample_instance_playmode(sndInstance, mode) ;
    al_play_sample_instance(sndInstance) ;
    sem_post(&Access) ;
}


void AudioManager::playBGM(const std::string& name) {
    stopBGM() ;

    string path = "media/bgm/" + name + ".ogg" ;

    sem_wait(&Access) ;
    m_bgm = al_load_audio_stream(path.c_str(), 4, 2048) ;
    assert(m_bgm) ;

    assert(al_set_audio_stream_playmode(m_bgm, ALLEGRO_PLAYMODE_LOOP)) ;
    assert(al_attach_audio_stream_to_mixer(m_bgm, m_audioMixers["bgm"])) ;
    sem_post(&Access) ;
}


void AudioManager::stopBGM() {
    sem_wait(&Access) ;
    if (m_bgm != 0) {
        // Stop the previous BGM
        al_drain_audio_stream(m_bgm) ;
        al_destroy_audio_stream(m_bgm) ;
        m_bgm = 0 ;
    }
    sem_post(&Access) ;
}
