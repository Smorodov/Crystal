//
//  Crystal Text-to-Speech Engine
//
//  Copyright (c) 2007 THU-CUHK Joint Research Center for
//  Media Sciences, Technologies and Systems. All rights reserved.
//
//  http://mjrc.sz.tsinghua.edu.cn
//
//  Redistribution and use in source and binary forms, with or without
//  modification, is not allowed, unless a valid written license is
//  granted by THU-CUHK Joint Research Center.
//
//  THU-CUHK Joint Research Center has the rights to create, modify,
//  copy, compile, remove, rename, explain and deliver the source codes.
//

///
/// @file
///
/// @brief    Head file for voice data management interface
///
/// <b>History:</b>
/// - Version:  0.1.0
///   Author:   John (john.zywu@gmail.com)
///   Date:     2007/06/03
///   Changed:  Created
///

#ifndef _CST_TTS_BASE_DATA_VOICEDATA_H_
#define _CST_TTS_BASE_DATA_VOICEDATA_H_

#include "../datamanage/data_datamanager.h"
#include "wav_synthesizer.h"

namespace cst
{
    namespace tts
    {
        namespace base
        {
            ///
            /// @brief  The class for managing the voice data (i.e. wave synthesizer, speech library, etc)
            ///
            class CVoiceData : public CDataManager
            {
            public:
                ///
                /// @brief  Default constructor
                ///
                CVoiceData() : m_pWavSynthesizer(NULL) {}

                ///
                /// @brief  Default destructor
                ///
                virtual ~CVoiceData() {terminate();}

                ///
                /// @brief  Initialize the data manager from the configuration information
                ///
                /// @param  [in] dataConfig     The configuration information
                ///
                /// @return Whether operation is successful
                ///
                virtual bool initialize(const DataConfig &dataConfig);

                ///
                /// @brief  Terminate (free) the initialized data
                ///
                virtual bool terminate();

                ///
                /// @brief  Get the wave synthesizer module
                ///
                virtual const CWavSynthesizer &getWavSynthesizer() const;

            private:
                ///
                /// @brief  Declared to prevent calling, will not be implemented
                ///
                CVoiceData &operator = (const CVoiceData &);
                ///
                /// @brief  Declared to prevent calling, will not be implemented
                ///
                CVoiceData(const CVoiceData &);

            protected:
                CWavSynthesizer *m_pWavSynthesizer; ///< Wave synthesizer
            };

        }//namespace base
    }
}

#endif//_CST_TTS_BASE_DATA_VOICEDATA_H_
