/* Copyright (c) 2019, Arm Limited and Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 the "License";
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "perspective_camera.h"

namespace vkb
{
namespace sg
{
PerspectiveCamera::PerspectiveCamera(const std::string &name) :
    Camera{name}
{}

void PerspectiveCamera::set_field_of_view(float new_fov)
{
	fov = new_fov;
}

void PerspectiveCamera::set_far_plane(float zfar)
{
	far_plane = zfar;
}

void PerspectiveCamera::set_near_plane(float znear)
{
	near_plane = znear;
}

void PerspectiveCamera::set_aspect_ratio(float new_aspect_ratio)
{
	aspect_ratio = new_aspect_ratio;
}

float PerspectiveCamera::get_field_of_view()
{
	/* Calculate vertical fov */
	auto vfov = static_cast<float>(2 * atan(tan(fov / 2) * (1.0 / aspect_ratio)));

	return aspect_ratio > 1.0f ? fov : vfov;
}

float PerspectiveCamera::get_aspect_ratio()
{
	return aspect_ratio;
}

glm::mat4 PerspectiveCamera::get_projection()
{
	return glm::perspective(get_field_of_view(), aspect_ratio, near_plane, far_plane);
}
}        // namespace sg
}        // namespace vkb
