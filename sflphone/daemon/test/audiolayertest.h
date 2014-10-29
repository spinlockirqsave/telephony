/*
 *  Copyright (C) 2004-2013 Savoir-Faire Linux Inc.
 *  Author: Emmanuel Milou <emmanuel.milou@savoirfairelinux.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 *
 *  Additional permission under GNU GPL version 3 section 7:
 *
 *  If you modify this program, or any covered work, by linking or
 *  combining it with the OpenSSL project's OpenSSL library (or a
 *  modified version of that library), containing parts covered by the
 *  terms of the OpenSSL or SSLeay licenses, Savoir-Faire Linux Inc.
 *  grants you additional permission to convey the resulting work.
 *  Corresponding Source for a non-source form of such a combination
 *  shall include the source code for the parts of OpenSSL used as well
 *  as that of the covered work.
 */

/*
 * @file audiorecorderTest.cpp
 * @brief       Regroups unitary tests related to the plugin manager.
 */

#ifndef AUDIOLAYER_TEST_
#define AUDIOLAYER_TEST_

// Cppunit import
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>

#include "noncopyable.h"

class ManagerImpl;

namespace sfl {
    class PulseLayer;
}

class AudioLayerTest: public CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(AudioLayerTest);
        CPPUNIT_TEST(testAudioLayerConfig);
        //CPPUNIT_TEST(testPulseConnect);
        //TODO: this test ends the test sequence when using on a alsa only system
        //CPPUNIT_TEST(testAudioLayerSwitch);
        CPPUNIT_TEST_SUITE_END();

    public:
        AudioLayerTest();
        void testAudioLayerConfig();
        void testPulseConnect();
        void testAudioLayerSwitch();

    private:
        NON_COPYABLE(AudioLayerTest);

        ManagerImpl* manager_;
        sfl::PulseLayer* pulselayer_;
        int layer_;
};
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(AudioLayerTest, "AudioLayerTest");
CPPUNIT_TEST_SUITE_REGISTRATION(AudioLayerTest);

#endif // AUDIOLAYER_TEST_
