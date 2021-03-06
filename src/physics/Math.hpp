// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (c) 2018-2019 Intel Corporation
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
//    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
//    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
//    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//    POSSIBILITY OF SUCH DAMAGE.
//
// ----------------- END LICENSE BLOCK -----------------------------------

/**
 * @file
 */

#pragma once

#include "ad_rss/physics/Acceleration.hpp"
#include "ad_rss/physics/CoordinateSystemAxis.hpp"
#include "ad_rss/physics/Distance.hpp"
#include "ad_rss/physics/Duration.hpp"
#include "ad_rss/physics/Speed.hpp"

/*!
 * @brief namespace ad_rss
 */
namespace ad_rss {
/*!
 * @brief namespace physics
 */
namespace physics {

/**
 * @brief Calculate the stopping distance for a given speed and deceleration on a constant accelerated movement
 *
 * @param[in]  currentSpeed           is the current speed of the vehicle
 * @param[in]  deceleration           is the applied (positive) deceleration
 * @param[out] stoppingDistance       is the resulting stopping distance
 *                                    The sign of the stoppingDistance equals the sign of the currentSpeed.
 *
 * @return true on success, false otherwise
 */
bool calculateStoppingDistance(Speed const &currentSpeed, Acceleration const &deceleration, Distance &stoppingDistance);

/**
 * @brief Calculate the vehicle speed after a given period of time on a constant accelerated movement
 *
 * @param[in]  axis            is the coordinate axis this calculation is for
 * @param[in]  currentSpeed    is the current speed of the vehicle
 *                             (in longitudinal direction this has to be always positive)
 * @param[in]  acceleration    is the acceleration of the vehicle
 * @param[in]  responseTime    is the (positive) period of time the vehicle keeps accelerating
 * @param[out] resultingSpeed  is the resulting speed after \a responseTime
 *                             In longitudinal direction, the resulting speed >= 0. Especially, the vehicle is not
 *                             starting to drive in reverse direction after standing still. In lateral direction,
 *                             the resulting speed might have a different sign than the currentSpeed.
 *
 * @return true on success, false otherwise
 */
bool calculateSpeedAfterResponseTime(CoordinateSystemAxis const &axis,
                                     Speed const &currentSpeed,
                                     Acceleration const &acceleration,
                                     Duration const &responseTime,
                                     Speed &resultingSpeed);

/**
 * @brief Calculate the distance offset of a vehicle after a given period of time on a constant accelerated movement
 *
 * @param[in]  axis             is the coordinate axis this calculation is for
 * @param[in]  currentSpeed     is the current speed of the vehicle
 *                              (in longitudinal direction this has to be always positive)
 * @param[in]  acceleration     is the acceleration of the vehicle
 * @param[in]  responseTime     is the (positive) period of time the vehicle keeps accelerating
 * @param[out] distanceOffset   is the distance offset from the current position
 *                              In decelerated longitudinal situation, the distance offset is restricted to the point
 *                              in time the vehicle stops; if the vehicle is able to stop within the response time,
 *                              it's equal to the stopping distance. Therefore, the distance offset in longitudinal
 *                              case is always positive. In lateral situation, the sign of the distance offset can be
 *                              positive or negative; the following is always true:
 *                              'lateral_position_after_response_time' = distanceOffset + 'current_lateral_position'
 *
 * @return true on success, false otherwise
 */
bool calculateDistanceOffsetAfterResponseTime(CoordinateSystemAxis const &axis,
                                              Speed const &currentSpeed,
                                              Acceleration const &acceleration,
                                              Duration const &responseTime,
                                              Distance &distanceOffset);

/**
 * @brief Calculate the time needed to cover a given distance
 *
 * The function will respect acceleration during response time and then braking till zero velocity
 * If the distance is not covered when then velocity reaches zero, infinite time will be returned
 *
 * @param[in] currentSpeed starting velocity
 * @param[in] responseTime
 * @param[in] acceleration during response time
 * @param[in] deceleration after response time
 * @param[in] distanceToCover distance that should be covered
 * @param[out] requiredTime time needed to cover the distance
 *
 * @return true on, success, false otherwise
 *
 */
bool calculateTimeToCoverDistance(Speed const &currentSpeed,
                                  Duration const &responseTime,
                                  Acceleration const &acceleration,
                                  Acceleration const &deceleration,
                                  Distance const &distanceToCover,
                                  Duration &requiredTime);

} // namespace physics
} // namespace ad_rss
