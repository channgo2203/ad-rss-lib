/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2018-2019 Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 *    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *    POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#include <gtest/gtest.h>
#include <limits>
#include "ad_rss/world/LateralRssAccelerationValues.hpp"

class LateralRssAccelerationValuesTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad_rss::world::LateralRssAccelerationValues value;
    ::ad_rss::physics::Acceleration valueAccelMax(-1e2);
    valueAccelMax = ::ad_rss::physics::Acceleration(0.); // set to valid value within struct
    value.accelMax = valueAccelMax;
    ::ad_rss::physics::Acceleration valueBrakeMin(-1e2);
    valueBrakeMin = ::ad_rss::physics::Acceleration(
      0. + ::ad_rss::physics::Acceleration::cPrecisionValue); // set to valid value within struct
    value.brakeMin = valueBrakeMin;
    mValue = value;
  }

  ::ad_rss::world::LateralRssAccelerationValues mValue;
};

TEST_F(LateralRssAccelerationValuesTests, copyConstruction)
{
  ::ad_rss::world::LateralRssAccelerationValues value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LateralRssAccelerationValuesTests, moveConstruction)
{
  ::ad_rss::world::LateralRssAccelerationValues value(std::move(::ad_rss::world::LateralRssAccelerationValues(mValue)));
  EXPECT_EQ(mValue, value);
}

TEST_F(LateralRssAccelerationValuesTests, copyAssignment)
{
  ::ad_rss::world::LateralRssAccelerationValues value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LateralRssAccelerationValuesTests, moveAssignment)
{
  ::ad_rss::world::LateralRssAccelerationValues value;
  value = std::move(::ad_rss::world::LateralRssAccelerationValues(mValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LateralRssAccelerationValuesTests, comparisonOperatorEqual)
{
  ::ad_rss::world::LateralRssAccelerationValues valueA = mValue;
  ::ad_rss::world::LateralRssAccelerationValues valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LateralRssAccelerationValuesTests, comparisonOperatorAccelMaxDiffers)
{
  ::ad_rss::world::LateralRssAccelerationValues valueA = mValue;
  ::ad_rss::physics::Acceleration accelMax(1e2);
  valueA.accelMax = accelMax;
  ::ad_rss::world::LateralRssAccelerationValues valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LateralRssAccelerationValuesTests, comparisonOperatorBrakeMinDiffers)
{
  ::ad_rss::world::LateralRssAccelerationValues valueA = mValue;
  ::ad_rss::physics::Acceleration brakeMin(1e2);
  valueA.brakeMin = brakeMin;
  ::ad_rss::world::LateralRssAccelerationValues valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}
