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
#include "ad_rss/state/LongitudinalRssState.hpp"

class LongitudinalRssStateTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad_rss::state::LongitudinalRssState value;
    bool valueIsSafe{true};
    value.isSafe = valueIsSafe;
    ::ad_rss::state::LongitudinalResponse valueResponse(::ad_rss::state::LongitudinalResponse::None);
    value.response = valueResponse;
    ::ad_rss::state::ResponseInformation valueResponseInformation;
    ::ad_rss::physics::Distance valueResponseInformationSafeDistance(0.);
    valueResponseInformation.safeDistance = valueResponseInformationSafeDistance;
    ::ad_rss::physics::Distance valueResponseInformationCurrentDistance(0.);
    valueResponseInformation.currentDistance = valueResponseInformationCurrentDistance;
    ::ad_rss::state::ResponseEvaluator valueResponseInformationResponseEvaluator(
      ::ad_rss::state::ResponseEvaluator::None);
    valueResponseInformation.responseEvaluator = valueResponseInformationResponseEvaluator;
    value.responseInformation = valueResponseInformation;
    mValue = value;
  }

  ::ad_rss::state::LongitudinalRssState mValue;
};

TEST_F(LongitudinalRssStateTests, copyConstruction)
{
  ::ad_rss::state::LongitudinalRssState value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LongitudinalRssStateTests, moveConstruction)
{
  ::ad_rss::state::LongitudinalRssState value(std::move(::ad_rss::state::LongitudinalRssState(mValue)));
  EXPECT_EQ(mValue, value);
}

TEST_F(LongitudinalRssStateTests, copyAssignment)
{
  ::ad_rss::state::LongitudinalRssState value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LongitudinalRssStateTests, moveAssignment)
{
  ::ad_rss::state::LongitudinalRssState value;
  value = std::move(::ad_rss::state::LongitudinalRssState(mValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LongitudinalRssStateTests, comparisonOperatorEqual)
{
  ::ad_rss::state::LongitudinalRssState valueA = mValue;
  ::ad_rss::state::LongitudinalRssState valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LongitudinalRssStateTests, comparisonOperatorIsSafeDiffers)
{
  ::ad_rss::state::LongitudinalRssState valueA = mValue;
  bool isSafe{false};
  valueA.isSafe = isSafe;
  ::ad_rss::state::LongitudinalRssState valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LongitudinalRssStateTests, comparisonOperatorResponseDiffers)
{
  ::ad_rss::state::LongitudinalRssState valueA = mValue;
  ::ad_rss::state::LongitudinalResponse response(::ad_rss::state::LongitudinalResponse::BrakeMin);
  valueA.response = response;
  ::ad_rss::state::LongitudinalRssState valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LongitudinalRssStateTests, comparisonOperatorResponseInformationDiffers)
{
  ::ad_rss::state::LongitudinalRssState valueA = mValue;
  ::ad_rss::state::ResponseInformation responseInformation;
  ::ad_rss::physics::Distance responseInformationSafeDistance(1e6);
  responseInformation.safeDistance = responseInformationSafeDistance;
  ::ad_rss::physics::Distance responseInformationCurrentDistance(1e6);
  responseInformation.currentDistance = responseInformationCurrentDistance;
  ::ad_rss::state::ResponseEvaluator responseInformationResponseEvaluator(
    ::ad_rss::state::ResponseEvaluator::IntersectionOverlap);
  responseInformation.responseEvaluator = responseInformationResponseEvaluator;
  valueA.responseInformation = responseInformation;
  ::ad_rss::state::LongitudinalRssState valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}
