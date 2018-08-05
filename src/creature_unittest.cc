// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <random>
#include <chrono>

#include "creature.h"

#include "gtest/gtest.h"

namespace {

    using edu::sbcc::cs140::Creature;
    using edu::sbcc::cs140::Human;
    using edu::sbcc::cs140::CyberDemon;
    using edu::sbcc::cs140::Balrog;
    using edu::sbcc::cs140::Elf;

// Tests edu::sbcc:cs140::String.

    using std::string;

    using namespace ::testing_internal;

    class CreatureTest : public ::testing::Test {
    protected:
        static const uint MAX_TESTED_SCORE = 20;
        static const uint MAX_OVERALL_SCORE = 25;
        static uint _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint CreatureTest::_testScore = 0;

    TEST_F(CreatureTest, Human) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        Human h(20, 20);
        ASSERT_EQ("Human", h.getSpecies());
        for(size_t i = 0; i < 100; i++) {
            int damage = h.getDamage();
            ASSERT_GE(20, damage);
        }
        _testScore += 5;
    }

    TEST_F(CreatureTest, CyberDemon) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        bool atLeast1LE20 = false;
        bool atLeast1GT50 = false;

        CyberDemon c(20, 20);
        ASSERT_EQ("Cyber Demon", c.getSpecies());
        for (size_t i = 0; i < 100; i++) {
            int damage = c.getDamage();
            if (damage <= 20) atLeast1LE20 = true;
            if (damage > 50)  atLeast1GT50 = true;
        }
        ASSERT_TRUE(atLeast1LE20 && atLeast1GT50);
        _testScore += 5;
    }

    TEST_F(CreatureTest, Balrog) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        bool atLeast1GE20LT50 = false;
        bool atLeast1GT50 = false;

        Balrog b(20, 20);
        ASSERT_EQ("Balrog", b.getSpecies());
        for (size_t i = 0; i < 100; i++) {
            int damage = b.getDamage();
            if (damage >= 20 && damage < 50) atLeast1GE20LT50 = true;
            if (damage >= 50) atLeast1GT50 = true;
        }
        ASSERT_TRUE(atLeast1GE20LT50 && atLeast1GT50);

        _testScore += 5;
    }

    TEST_F(CreatureTest, Elf) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        bool atLeast1GT20 = false;
        Elf e(20, 20);
        ASSERT_EQ("Elf", e.getSpecies());
        for (size_t i = 0; i < 100; i++) {
            int damage = e.getDamage();
            if (damage > 20) atLeast1GT20 = true;
        }
        ASSERT_TRUE(atLeast1GT20);

        _testScore += 5;
    }

}